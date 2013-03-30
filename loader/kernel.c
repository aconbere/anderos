#include "stdint.h"
#include "video.h"

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

  framebuffer_t fb;
  framebuffer_reset(&fb);
  framebuffer_clear(&fb);

  framebuffer_move_cursor(&fb, 10,10);

  framebuffer_write_string(&fb, "Hi, this is AnderOS", 0x2a);
}
