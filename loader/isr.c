#include "common.h"
#include "isr.h"
#include "video.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs) {
    video_write_string("recieved interrupt: ", 0x2a);
    video_write_decimal(regs.int_no);
    video_write_char('\n', 0x2a);
}
