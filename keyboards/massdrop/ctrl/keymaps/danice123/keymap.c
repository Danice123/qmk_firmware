#include QMK_KEYBOARD_H

enum ctrl_layers {
	_KEY,
	_CLR,
	_FUN
};

enum ctrl_keycodes {
    LED_BRI = SAFE_RANGE, //LED Brightness Increase
    LED_BRD,              //LED Brightness Decrease
    MD_BOOT,
    CLR_TYP,
    CLR_SEG,
    CLR_M_1, CLR_M_2, CLR_M_3, CLR_M_4, CLR_M_5, CLR_M_6, CLR_M_7, CLR_M_8, CLR_M_9, CLR_M10, CLR_M11,
    CLR_B_1, CLR_B_2, CLR_B_3, CLR_B_4, CLR_B_5, CLR_B_6, CLR_B_7, CLR_B_8, CLR_B_9, CLR_B10, CLR_B11,
    CLR_O_1, CLR_O_2, CLR_O_3, CLR_O_4, CLR_O_5, CLR_O_6, CLR_O_7, CLR_O_8, CLR_O_9, CLR_O10, CLR_O11,
};

enum ctrl_tapdance {
    TD_SPAC
};

int COLOR_MODE;
bool isParkorOn = false;                                                                                                                                                                                                  

void parkor_finish(qk_tap_dance_state_t *state, void *user_data) {
    if (!state->interrupted && state->pressed && COLOR_MODE == RGB_MATRIX_CUSTOM_SEIGE) {
        isParkorOn = true;
    } else {
        register_code(KC_SPC);
    }
}

void parkor_reset(qk_tap_dance_state_t *state, void *user_data) {
    isParkorOn = false;
    unregister_code(KC_SPC);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPAC]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, parkor_finish, parkor_reset, 10)
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KEY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        MO(_FUN),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   TD(TD_SPAC),                        KC_RALT, MO(_CLR),KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_CLR] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, CLR_M_1, CLR_M_2, CLR_M_3, CLR_M_4, CLR_M_5, CLR_M_6, CLR_M_7, CLR_M_8, CLR_M_9, CLR_M10, CLR_M11, _______, _______,   _______, _______, _______, \
        _______, CLR_B_1, CLR_B_2, CLR_B_3, CLR_B_4, CLR_B_5, CLR_B_6, CLR_B_7, CLR_B_8, CLR_B_9, CLR_B10, CLR_B11, _______, _______,   _______, _______, _______, \
        _______, CLR_O_1, CLR_O_2, CLR_O_3, CLR_O_4, CLR_O_5, CLR_O_6, CLR_O_7, CLR_O_8, CLR_O_9, CLR_O10, CLR_O11, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              LED_BRI, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, LED_BRD, _______ \
    ),
    [_FUN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, MD_BOOT, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   CLR_TYP, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   CLR_SEG, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
	    0,       1,       2,       3,       4,       5,       6,       7,       8,       9,       10,      11,      12,                 13,      14,      15,      \
	    16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,        30,      31,      32,      \
	    33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      44,      45,      46,        47,      48,      49,      \
	    50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      60,      61,      62,      \
	    63,      64,      65,      66,      67,      68,      69,      70,      71,      72,      73,      74,                                   75,      \
	    76,      77,      78,                        79,                                 80,      81,      82,      83,                 84,      85,      86      \
	),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_JUST_TYPE);
    COLOR_MODE = RGB_MATRIX_CUSTOM_JUST_TYPE;
    rgb_matrix_sethsv(9, 7, 5);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if (isParkorOn) {
        tap_code(KC_SPC);
    }
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
            }
            return false;
        case LED_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
            }
            return false;
        case MD_BOOT:
            reset_keyboard();
            return false;
        case CLR_TYP:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_JUST_TYPE);
                COLOR_MODE = RGB_MATRIX_CUSTOM_JUST_TYPE;
            }
            return false;
        case CLR_SEG:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_SEIGE);
                COLOR_MODE = RGB_MATRIX_CUSTOM_SEIGE;
            }
            return false;
        case CLR_M_1:
        case CLR_M_2:
        case CLR_M_3:
        case CLR_M_4:
        case CLR_M_5:
        case CLR_M_6:
        case CLR_M_7:
        case CLR_M_8:
        case CLR_M_9:
        case CLR_M10:
        case CLR_M11:
            if (record->event.pressed) {
                rgb_matrix_sethsv(keycode - CLR_M_1, rgb_matrix_config.sat, rgb_matrix_config.val);
            }
            return false;
        case CLR_B_1:
        case CLR_B_2:
        case CLR_B_3:
        case CLR_B_4:
        case CLR_B_5:
        case CLR_B_6:
        case CLR_B_7:
        case CLR_B_8:
        case CLR_B_9:
        case CLR_B10:
        case CLR_B11:
            if (record->event.pressed) {
                rgb_matrix_sethsv(rgb_matrix_config.hue, keycode - CLR_B_1, rgb_matrix_config.val);
            }
            return false;
        case CLR_O_1:
        case CLR_O_2:
        case CLR_O_3:
        case CLR_O_4:
        case CLR_O_5:
        case CLR_O_6:
        case CLR_O_7:
        case CLR_O_8:
        case CLR_O_9:
        case CLR_O10:
        case CLR_O11:
            if (record->event.pressed) {
                rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, keycode - CLR_O_1);
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void (*getColor(int c)) (uint8_t i);
void yellow(uint8_t i);
void orange(uint8_t i);
void red(uint8_t i);
void pink(uint8_t i);
void purple(uint8_t i);
void royal_blue(uint8_t i);
void blue(uint8_t i);
void sea_blue(uint8_t i);
void blue_green(uint8_t i);
void green(uint8_t i);
void light_green(uint8_t i);
void grey(uint8_t i);
void white(uint8_t i);

void handle_led_clr(int i);
void handle_led_fun(int i);

void rgb_matrix_indicators_user(void) {
	if (!g_suspend_state && rgb_matrix_config.enable) {
		switch (biton32(layer_state)) {
		case _CLR:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                handle_led_clr(i);
            }
			break;
		case _FUN:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                handle_led_fun(i);
            }
		    break;
		}
	}
}

void handle_led_fun(int i) {
    switch(i) {
    case 30: // CLR_TYP
        if (COLOR_MODE == RGB_MATRIX_CUSTOM_JUST_TYPE) {
            red(i);
        } else {
            green(i);
        }
        break;
    case 47: // CLR_SEG
        if (COLOR_MODE == RGB_MATRIX_CUSTOM_SEIGE) {
            red(i);
        } else {
            blue(i);
        }
        break;
    case 15: // MD_BOOT
        red(i);
        break;
    case 69: // TG_NKRO
        blue(i);
        break;
    case 50: // _FUN
        red(i);
        break;
    default:
        grey(i);
        break;
    }
}

void handle_led_clr(int i) {
    if (COLOR_MODE == RGB_MATRIX_CUSTOM_JUST_TYPE) {
        if (i > 16 && i < 28) {
            getColor(i - 17) (i);
        } else if (i > 33 && i < 45) {
            getColor(i - 34) (i);
        } else if (i > 50 && i < 62) {
            getColor(i - 51) (i);
        }
        else {
            switch(i) {
            case 75:
                yellow(i);
                break;
            case 85:
                green(i);
                break;
            case 81: // _CLR
                red(i);
                break;
            default:
                grey(i);
                break;
            }
        }
    } else {
        switch(i) {
        case 75:
            yellow(i);
            break;
        case 85:
            green(i);
            break;
        case 81: // _CLR
            red(i);
            break;
        default:
            grey(i);
            break;
        }
    }
}