#ifndef DANICE_COLOR_PACK
#define DANICE_COLOR_PACK

void yellow(uint8_t i) { rgb_matrix_set_color(i, 0xAA, 0x9B, 0x00); }

void orange(uint8_t i) { rgb_matrix_set_color(i, 0xAA, 0x4D, 0x00); }

void red(uint8_t i) { rgb_matrix_set_color(i, 0xAA, 0x00, 0x00); }

void pink(uint8_t i) { rgb_matrix_set_color(i, 0x8B, 0x00, 0x49); }

void purple(uint8_t i) { rgb_matrix_set_color(i, 0x45, 0x07, 0x72); }

void royal_blue(uint8_t i) { rgb_matrix_set_color(i, 0x2F, 0x0B, 0x74); }

void blue(uint8_t i) { rgb_matrix_set_color(i, 0x0D, 0x28, 0x72); }

void sea_blue(uint8_t i) { rgb_matrix_set_color(i, 0x00, 0x66, 0x66); }

void blue_green(uint8_t i) { rgb_matrix_set_color(i, 0x00, 0x75, 0x40); }

void green(uint8_t i) { rgb_matrix_set_color(i, 0x00, 0x88, 0x00); }

void light_green(uint8_t i) { rgb_matrix_set_color(i, 0x58, 0x9B, 0x00); }

void grey(uint8_t i) { rgb_matrix_set_color(i, 0x18, 0x18, 0x12); }

void white(uint8_t i) { rgb_matrix_set_color(i, 0x88, 0x88, 0x80); }

void (*getColor(int c)) (uint8_t i) {
  void (*p[11]) (uint8_t i);
  p[0] = yellow;
  p[1] = orange;
  p[2] = red;
  p[3] = pink;
  p[4] = purple;
  p[5] = royal_blue;
  p[6] = blue;
  p[7] = sea_blue;
  p[8] = blue_green;
  p[9] = green;
  p[10] = light_green;

  if (c < 0) {
    c = 11 + c;
  }
  if (c > 10) {
    c = c - 11;
  }
  return (*p[c]);
}

#endif