RGB_MATRIX_EFFECT(JUST_TYPE)
RGB_MATRIX_EFFECT(SEIGE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "color.h"

bool JUST_TYPE(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  int main = rgb_matrix_config.hue;
  int border = rgb_matrix_config.sat;
  int bottom = rgb_matrix_config.val;

  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();

    if (i < 16)  getColor(bottom) (i);
    else if (i < 33)  getColor(border) (i);
    else if (i > 86)  getColor(bottom) (i);
    else if (i > 75)  getColor(border) (i);
    else {
      switch(i) {
        case 33:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 62:
        case 63:
        case 74:
        case 75:
          getColor(border) (i);
          break;
        default:
          getColor(main) (i);
          //green(i);
          break;
      }
    }
  }

  return led_max < DRIVER_LED_TOTAL; 
}

bool SEIGE(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  int bottom = rgb_matrix_config.val;

  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (i > 86) getColor(bottom) (i);
    else switch(i) {
      // WASD
      case 35:
      case 51:
      case 52:
      case 53:
        red(i);
        break;
      // Movement
      case 34:
      case 36:
      case 63:
      case 66:
      case 76:
      case 78:
      case 79:
        orange(i);
        break;
      // Weapon keys
      case 37:
      case 54:
      case 67:
      case 68:
        light_green(i);
        break;
      // Switch keys
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
        green(i);
        break;
      // Commands
      case 0:
      case 33:
      case 38:
      case 39:
        blue(i);
        break;
      default:
        grey(i);
        break;
    }
  }

  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
