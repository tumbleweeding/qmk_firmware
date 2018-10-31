/* Copyright 2015-2017 Jack Humbert
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

#include "niu_mini.h"
#include "action_layer.h"
#ifdef RGBLIGHT_ENABLE
  #include "rgblight.h"
#endif //RGBLIGHT_ENABLE

extern keymap_config_t keymap_config;

int r, g, b;

//layers
//#define _QW 0
#define _WM 0
#define _QW 1
#define _LW 2
#define _RS 3

//tap layer keys
#define LWHM LT(_LW, KC_HOME)
#define RSED LT(_RS, KC_END)
#define SPSH MT(MOD_LSFT, KC_SPC)
#define ENSH MT(MOD_RSFT, KC_ENT)
//#define CTRQ LM(_QW, KC_LCTRL)
//#define GUIQ LM(_QW, KC_GUI)
#define CTRQ M(0)
#define GUIQ M(1)
#define ALTQ M(2)
/*
enum keycodes {
  ESCTAB = SAFE_RANGE,
};
*/
bool lShift = false;
bool rShift = false;
bool lAlt = false;
bool rAlt = false;
bool lCtrl = false;
bool rCtrl = false;
int hues[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
* ,-----------------------------------------------------------------------------------.
* | TAB  | Q    | D    | R    | W    | B    | J    | F    | U    | P    | ;    | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Bsps | A    | S    | H    | T    | G    | Y    | N    | E    | O    | I    | '    |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |Shift | Z    | X    | M    | C    | V    | K    | L    | ,    | .    | /    | ENSH |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | CTLQW| GUI  | Alt  | PGUP | LWHM |    SPSH     | RSED | PGDN | Alt  | Menu | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[_WM] = {
{ KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL  },
{ KC_BSPC, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT },
{ KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, ENSH    },
{ CTRQ,    GUIQ,    ALTQ,    KC_PGUP, MO(_LW), SPSH,    SPSH,    MO(_RS),  KC_PGDN, KC_RALT, KC_APP,  KC_RCTL }
},

/* Qwerty
* ,-----------------------------------------------------------------------------------.
* | TAB  | Q    | W    | E    | R    | T    | Y    | U    | I    | O    | P    | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Bsps | A    | S    | D    | F    | G    | H    | J    | K    | L    | ;    | '    |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |Shift | Z    | X    | C    | V    | B    | N    | M    | ,    | .    | /    | ENSH |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  | Alt  | PGUP | Home |    SPSH     | End  | PGDN | Alt  | Menu | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[_QW] = {
{ KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_DEL, },
{ KC_BSPC, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, },
{ KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  ENSH, },
{ _______, _______,  _______,  _______,  MO(_LW),  SPSH,     SPSH,     MO(_RS),  _______,  KC_RALT,  KC_APP,   KC_RCTRL, },
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | ~    |RGBtog|      |      |      |      |      | 7    | 8    | 9    | 0    | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bspc |      | \    | -    | =    |      |      | 4    | 5    | 6    |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |      |      | [    | ]    |      | 0    | 1    | 2    | 3    |      | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | PGUP |      |    SPSH     |      | PGDN | Alt  | Menu | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_LW] = {
  { KC_GRV,  RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    _______  },
  { _______, XXXXXXX, KC_BSLS, KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX  },
  { _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, KC_ENT   },
  { _______, _______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______  },
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      | Up   |      |      |      | F9   | F10  | F11  | F12  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      | Left | Down |Right |      |      | F5   | F6   | F7   | F8   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |      | F1   | F2   | F3   | F4   | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | PGUP |      |    SPSH     |      | PGDN | Alt  | Menu | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_RS] = {
  { KC_ESC,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______  },
  { KC_CAPS, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX  },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_ENT   },
  { _______, _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______  },
},
};

void matrix_scan_user(void) {
  r = 255;
  g = 0;
  b = 0;
  lAlt = keyboard_report->mods & MOD_BIT(KC_LALT);
  rAlt = keyboard_report->mods & MOD_BIT(KC_RALT);
  lCtrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
  rCtrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
  lShift = keyboard_report->mods & MOD_BIT(KC_LSFT);
  rShift = keyboard_report->mods & MOD_BIT(KC_RSFT);
#ifdef RGBLIGHT_ENABLE
  //RGB LEDs on sides turn blue if caps lock is on or red if caps lock is off
  if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
	  hues[0] = hues[1] = hues[6] = hues[7] = hues[8] = hues[13] = 240;
  }
  else {
	  hues[0] = hues[1] = hues[6] = hues[7] = hues[8] = hues[13] = 0;
  }

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
    case _WM:
	case _QW:
		hues[2] = hues[3] = hues[4] = hues[5] = hues[9] = hues[10] = hues[11] = hues[12] = 0;
		
		break;
    case _RS:
		hues[2] = hues[3] = hues[4] = hues[5] = hues[9] = hues[10] = hues[11] = hues[12] = 33;
		
		break;
    case _LW:
		hues[2] = hues[3] = hues[4] = hues[5] = hues[9] = hues[10] = hues[11] = hues[12] = 120;
		
		break;
    }

	for (int i = 0; i < RGBLED_NUM; i++) rgblight_sethsv_at(hues[i], 255, 255, i);

    old_layer = new_layer;
  }
#endif //RGBLIGHT_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    /*
    case ESCTAB:
		if (record->event.pressed) {

		  if (lAlt || rAlt || ((lCtrl || rCtrl) && !(lShift || rShift))) {
			SEND_STRING(SS_DOWN(X_TAB));
		  } else {
			SEND_STRING(SS_DOWN(X_ESCAPE));
		  }
		} else {
		  SEND_STRING(SS_UP(X_TAB));
		  SEND_STRING(SS_UP(X_ESCAPE));
		}
		return false;
		break;
    */
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
	case 0:
		if (record->event.pressed) {
			layer_on(_QW);
			register_code(KC_LCTL);
		}
		else
		{
			unregister_code(KC_LCTL);
			layer_off(_QW);
		}
		break;
	case 1:
		if (record->event.pressed) {
			layer_on(_QW);
			register_code(KC_LGUI);
		}
		else
		{
			unregister_code(KC_LGUI);
			layer_off(_QW);
		}
		break;
	case 2:
		if (record->event.pressed) {
			layer_on(_QW);
			register_code(KC_LALT);
		}
		else
		{
			unregister_code(KC_LALT);
			layer_off(_QW);
		}
	}
	return MACRO_NONE;
};
