#include "common.h"
#include "isr.h"
#include "video.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs) {
  framebuffer_t fb;
  framebuffer_reset(&fb);
  framebuffer_clear(&fb);
  framebuffer_move_cursor(&fb, 0, 1);
  framebuffer_write_string(&fb, "recieved interupt", 0x2a);
}
