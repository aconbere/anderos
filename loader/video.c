#include "video.h"
#include "common.h"

void framebuffer_write_string( framebuffer_t *fb, const char *string, int color ) {
  if (fb->offset >= FRAMEBUFFER_MAX_OFFSET) {
    return;
  }
  int n = sizeof(unsigned char);
  while( *string != 0 ) {
    fb->ram[fb->offset * n] = *string++;
    fb->offset++;
    fb->ram[fb->offset * n] = color;
    fb->offset++;
  }
}

void framebuffer_clear( framebuffer_t *fb) {
  int i = 0;
  int max_string = 80*25;
  char string[max_string];

  while (i <= max_string) {
    string[i] = ' ';
    i++;
  }

  framebuffer_write_string(fb, string, 0x00);
  framebuffer_reset(fb);
}

void framebuffer_reset( framebuffer_t *fb ) {
  fb->offset = 0;
  fb->ram = (unsigned char *)0xB8000; 
}

void framebuffer_move_cursor( framebuffer_t *fb, int x, int y) {
  fb->offset = (y * 80) + x;
}

