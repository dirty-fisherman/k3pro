/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include QMK_KEYBOARD_H

// clang-format off
enum layers{
    LAY_0,
    LAY_1,
    LAY_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAY_0] = LAYOUT_iso_85(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_PSCR,  KC_DEL,   TO(LAY_1),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_ENT,             KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_BSLS,            KC_HOME,
        KC_LSFT,  KC_GRV,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,  KC_UP,    KC_END,
        KC_LGUI,  KC_LALT,  KC_LCTL,                                KC_SPC,                                 KC_RALT,  XXXXXXX,    KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAY_1] = LAYOUT_iso_85(
        KC_ESC,    KC_F13,      KC_F14,      KC_F15,      KC_F16,      KC_F17,      KC_F18,      KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_MUTE,     KC_VOLD,  KC_VOLU,   XXXXXXX,  XXXXXXX,   TO(LAY_2),
        XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,
        XXXXXXX,   KC_P7,       KC_P8,       KC_P9,       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,
        XXXXXXX,   KC_P4,       KC_P5,       KC_P6,       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,             XXXXXXX,             XXXXXXX,
        XXXXXXX,   XXXXXXX,     KC_P1,       KC_P2,       KC_P3,       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,             XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,     KC_P0,                                              XXXXXXX,                                            XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX),

    [LAY_2] = LAYOUT_iso_85(
        XXXXXXX,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   XXXXXXX,  XXXXXXX,   TO(LAY_0),
        XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,
        XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,
        XXXXXXX,   XXXXXXX,     MI_Cs1,      MI_Ds1,      XXXXXXX,     MI_Fs1,      MI_Gs1,      MI_As1,      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,             XXXXXXX,             XXXXXXX,
        XXXXXXX,   MI_C1,       MI_D1,       MI_E1,       MI_F1,       MI_G1,       MI_A1,       MI_B1,       MI_C2,       XXXXXXX,     XXXXXXX,     XXXXXXX,             XXXXXXX,  MI_VELU,   XXXXXXX,
        XXXXXXX,   XXXXXXX,     XXXXXXX,                                            MI_SUST,                                            XXXXXXX,     XXXXXXX,  XXXXXXX,   MI_OCTD,  MI_VELD,   MI_OCTU),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 2:
        rgb_matrix_set_color_all(RGB_TEAL);
        break;
    case 1:
        rgb_matrix_set_color_all(RGB_MAGENTA);
        break;
    case 0:
        rgb_matrix_set_color_all(RGB_PURPLE);
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_set_color_all(RGB_PURPLE);
        break;
    }
  return state;
}
