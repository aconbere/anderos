typedef struct {
  volatile unsigned char *ram;
  int offset;
} framebuffer_t;

#define FRAMEBUFFER_MAX_OFFSET 80 * 25

void framebuffer_write_string( framebuffer_t *framebuffer, const char *string, int color );
void framebuffer_clear( framebuffer_t *framebuffer );
void framebuffer_reset( framebuffer_t *framebuffer );
void framebuffer_move_cursor( framebuffer_t *framebuffer, int x, int y );
framebuffer_t * framebuffer_init();
