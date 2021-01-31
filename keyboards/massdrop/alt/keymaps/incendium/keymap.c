/**
 * QMK Firmware - Massdrop ALT - Incendium Keymap
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KL] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        LT_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FL] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS, \
        _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _LAYER_, _______, _______, _______  \
    ),
    [_NL] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_PMNS, KC_PPLS, _______, KC_MUTE, \
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PSLS, _______, _______, KC_EQL,  _______, \
        _LAYER_, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PPLS,          KC_PENT, KC_VOLU, \
        _______, _______, _______, _______, JB_PSTE, _______, KC_P0,   KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, _______,          _______, KC_VOLU, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
};

#ifdef _______
#    undef _______
#    define _______ {0,0,0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_FL] = {
        _______, SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  SPRING,  _______, GREEN, \
        _______, GOLD,    CORAL,   _______, _______, _______, _______, _______, _______, _______, GOLD,    GOLD,    GOLD,    _______, RED, \
        _______, GOLD,    CORAL,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RED,     _______, _______, _______,     RED,    PINK, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    },
    [_NL] = {
        _______, _______, _______, _______, _______, _______, _______, GOLD,    GOLD,    GOLD,    GREEN,   GREEN,   GREEN,   _______, RED, \
        _______, CYAN,    AZURE,   CYAN,    TEAL,    _______, _______, GOLD,    RED,     GOLD,    GREEN,   _______, _______, GREEN,   _______, \
        WHITE,   AZURE,   AZURE,   AZURE,   TEAL,    _______, _______, GOLD,    GOLD,    GOLD,    GREEN,   GREEN,            GREEN,   AZURE, \
        _______, _______, _______, _______, GREEN,   _______, RED,     RED,     RED,     GREEN,   GREEN,   _______,          _______, AZURE, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    },
};
#    undef _______
#    define _______ KC_TRNS
#endif
// clang-format on

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv(128, 0, 255);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void set_layer_color(int layer) {
    if (layer == 0) {
        return;
    }
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };

        if (hsv.h || hsv.s || hsv.v) {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float) rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        } else if (layer == _FL) {
            HSV hsv2 = {rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};

            HSV hue_inc = hsv2;
            HSV hue_dec = hsv2;
            HSV sat_inc = hsv2;
            HSV sat_dec = hsv2;
            HSV val_inc = hsv2;
            HSV val_dec = hsv2;

            hue_inc.h = hsv2.h + 8;
            hue_dec.h = hsv2.h - 8;
            sat_inc.s = hsv2.s + 16 > 255 ? 255 : hsv2.s + 16;
            sat_dec.s = hsv2.s - 16 < 0 ? 0 : hsv2.s - 16;
            val_inc.v = hsv2.v + 16 > 255 ? 255 : hsv2.v + 16;
            val_dec.v = hsv2.v - 16 < 0 ? 0 : hsv2.v - 16;

            RGB rgb_hue_inc = hsv_to_rgb(hue_inc);
            RGB rgb_hue_dec = hsv_to_rgb(hue_dec);
            RGB rgb_sat_inc = hsv_to_rgb(sat_inc);
            RGB rgb_sat_dec = hsv_to_rgb(sat_dec);
            RGB rgb_val_inc = hsv_to_rgb(val_inc);
            RGB rgb_val_dec = hsv_to_rgb(val_dec);

            switch (i) {
                case 18:
                    rgb_matrix_set_color(i, rgb_hue_inc.r, rgb_hue_inc.g, rgb_hue_inc.b);
                    break;
                case 33:
                    rgb_matrix_set_color(i, rgb_hue_dec.r, rgb_hue_dec.g, rgb_hue_dec.b);
                    break;
                case 19:
                    rgb_matrix_set_color(i, rgb_sat_inc.r, rgb_sat_inc.g, rgb_sat_inc.b);
                    break;
                case 34:
                    rgb_matrix_set_color(i, rgb_sat_dec.r, rgb_sat_dec.g, rgb_sat_dec.b);
                    break;
                case 20:
                    rgb_matrix_set_color(i, rgb_val_inc.r, rgb_val_inc.g, rgb_val_inc.b);
                    break;
                case 35:
                    rgb_matrix_set_color(i, rgb_val_dec.r, rgb_val_dec.g, rgb_val_dec.b);
                    break;
            }
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || disable_layer_color || rgb_matrix_get_flags() == LED_FLAG_NONE || rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) {
        return;
    }

    set_layer_color(get_highest_layer(layer_state));
}
