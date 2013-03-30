#include "video.h"

volatile unsigned char *videoram = (unsigned char *)0xB8000;

void video_write_char(const char c, int color) {
  *videoram++ = c;
  *videoram++ = color;
}

// note this example will always write to the top
// line of the screen
void video_write_string(const char *string, int color ) {
  while( *string != 0 ) {
    *videoram++ = *string++;
    *videoram++ = color;
  }
}

void video_clear() {
    int i = 0;
    int max_string = 80*25;
    char string[max_string];

    while (i <= max_string) {
      string[i] = ' ';
      i++;
    }

    video_write_string(string, 0x00);
}

void video_write_decimal(int i) {
    video_write_string("", i);
}

