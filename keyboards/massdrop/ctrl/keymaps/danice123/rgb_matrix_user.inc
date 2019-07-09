RGB_MATRIX_EFFECT(SEIGE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool SEIGE(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  // HSV hsv = { rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val };
  // RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();

    switch(i) {
      // WASD
      case 35:
      case 51:
      case 52:
      case 53:
        rgb_matrix_set_color(i, 0xA7, 0x00, 0x32);
        break;
      // Movement
      case 34:
      case 36:
      case 63:
      case 66:
      case 76:
      case 78:
      case 79:
        rgb_matrix_set_color(i, 0xA9, 0x73, 0x00);
        break;
      // Weapon keys
      case 37:
      case 54:
      case 67:
      case 68:
        rgb_matrix_set_color(i, 0x40, 0x9B, 0x00);
        break;
      // Switch keys
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
        rgb_matrix_set_color(i, 0x35, 0x7E, 0x15);
        break;
      case 0:
      case 33:
        rgb_matrix_set_color(i, 0x00, 0x88, 0x81);
        break;
      default:
        rgb_matrix_set_color(i, 0x12, 0x18, 0x18);
        break;
    }
  }

  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
