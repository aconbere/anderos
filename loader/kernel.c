#include "stdint.h"

// note this example will always write to the top
// line of the screen
void video_write_string( volatile unsigned char *video, const char *string, int color ) {
  while( *string != 0 ) {
    *video++ = *string++;
    *video++ = color;
  }
}

void video_clear( volatile unsigned char *video ) {
    int i = 0;
    int max_string = 80*25;
    char string[max_string];

    while (i <= max_string) {
      string[i] = ' ';
      i++;
    }

    video_write_string(video, string, 0x00);
}

void interupt_handler(void) {
  volatile unsigned char *videoram = (unsigned char *)0xB8000;
  video_write_string(videoram, "wtf", 0x2a);
  asm("cli");
  asm("hlt");
}
 
void kmain(void) {
  extern uint32_t magic;

  /* Uncomment the following if you want to be able to access the multiboot header */
  /* extern void *mbd; */

  if ( magic != 0x2BADB002 ) {
     /* Something went not according to specs. Print an error */
     /* message and halt, but do *not* rely on the multiboot */
     /* data structure. */
  }

  /* You could either use multiboot.h */
  /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
  /* or do your offsets yourself. The following is merely an example. */
  //char * boot_loader_name =(char*) ((long*)mbd)[16];

  /* Print a letter to screen to see everything is working: */
  volatile unsigned char *videoram = (unsigned char *)0xB8000;
  video_clear(videoram);
  video_write_string(videoram, "Hi, this is AnderOS", 0x2a);
}
