/* Copyright 2017 Benjamin Kesselring
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
#include "xd75.h"
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif //RGBLIGHT_ENABLE

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _QW 0
#define _LW 1
#define _RS 2

#define LWHM LT(_LW, KC_HOME)
#define RSED LT(_RS, KC_END)
#define SPSH MT(MOD_LSFT, KC_SPC)
#define ENSH MT(MOD_RSFT, KC_ENT)
#define LOCK LGUI(KC_L)

enum my_keycodes {
	ESCTAB = SAFE_RANGE,
	PRSNP
};

bool lShift = false;
bool rShift = false;
bool lAlt = false;
bool rAlt = false;
bool lCtrl = false;
bool rCtrl = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY - MIT ENHANCED / GRID COMPATIBLE
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | DEL    | F11    | F12    | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | DEL    |        | LOCK   | PRSCR  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
   * | BACKSP | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |        | ENTER  | ENTER  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
   * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENSH   | RSHFT  | UP     |        |
   * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
   * | LCTRL  | LGUI   | LALT   | PGUP   | LOWER  | SPACE  | SPACE  | RAISE  | PGDN   | RALT   | MENU   | RCTRL  | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */

   [_QW] = { /* QWERTY */
    { KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,   KC_F11,   KC_F12,   KC_DEL   },
    { KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_DEL,   XXXXXXX,  LOCK,     PRSNP    },
    { KC_BSPC,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  XXXXXXX,  KC_ENT,   KC_ENT   },
    { KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  ENSH,     KC_RSFT,  KC_UP,    XXXXXXX  },
    { KC_LCTL,    KC_LGUI,  KC_LALT,  KC_PGUP,  LWHM,     KC_SPC,   SPSH,     RSED,     KC_PGDN,  KC_RALT,  KC_APP,   KC_RCTRL, KC_LEFT,  KC_DOWN,  KC_RGHT  },
   },

   /* LOWERED
    * .--------------------------------------------------------------------------------------------------------------------------------------.
    * | `      | F11    | F12    | F13    | F4     | F5     | F6     | F7     | F8     | F9     | F10    | DEL    | F11    | F12    | DEL    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
    * | `      |        |        |        |        |        |        | 7      | 8      | 9      | 0      |        |        |        | PSCR   |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
    * | BACKSP |        | \      | -      | =      |        |        | 4      | 5      | 6      |        |        |        | ENTER  | ENTER  |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
    * | LSHIFT |        |        | [      | ]      |        | 0      | 1      | 2      | 3      |        | ENTER  |        | UP     |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | LCTRL  | LGUI   | LALT   | PGUP   | LOWER  | SPACE  | SPACE  | END    | PGDN   |  RALT   | MENU  | RCTRL  | LEFT   | DOWN   | RIGHT  |
    * '--------------------------------------------------------------------------------------------------------------------------------------'
    */

     [_LW] = { /* LOWERED */
      { KC_GRV,   KC_F11,   KC_F12,   KC_F13,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
	  { KC_GRV,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,     _______,  XXXXXXX,  XXXXXXX,  _______  },
	  { _______,  XXXXXXX,  KC_BSLS,  KC_MINS,  KC_EQL,   XXXXXXX,  XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,  _______,  XXXXXXX,  _______,  _______  },
      { _______,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,  XXXXXXX,  KC_0,     KC_1,     KC_2,     KC_3,     KC_ENT,   _______,  _______,  _______,  XXXXXXX  },
      { _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______  },
     },

    /* RAISED
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | `      | F11    | F12    | F13    | F4     | F5     | F6     | F7     | F8     | F9     | F10    | DEL    | F11    | F12    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | `      |        |        | UP     |        |        |        |        |        |        |        |        |        |        | PSCR   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAPS   |        | LEFT   | DOWN   | RIGHT  |        |        |        |        |        |        |        |        | ENTER  | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT |        |        |        |        |        |        |        |        |        |        | ENTER  |        | UP     |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | PGUP   | HOME   | SPACE  | SPACE  | RAISE  | PGDN   | RALT   | MENU   | RCTRL  | LEFT   | DOWN   | RIGHT  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

     [_RS] = { /* RAISED */
      { KC_GRV,   KC_F11,   KC_F12,   KC_F13,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
      { KC_TAB,   XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  _______  },
      { KC_CAPS,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  _______,  _______  },
      { _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ENT,   _______,  XXXXXXX,  _______,  XXXXXXX  },
      { _______,  _______,  _______,  _______,  KC_HOME,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
     },
};
 
 void matrix_scan_user(void){
	#ifdef RGBLIGHT_ENABLE

	 lShift = keyboard_report->mods & MOD_BIT(KC_LSFT);
	 rShift = keyboard_report->mods & MOD_BIT(KC_RSFT);

		//if CAPS LOCK is on, set right 2 LEDs blue, else if shift is pressed, set the LEDs on its side blue, else set them red
		if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
			if (lShift) {
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 0);
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 1);
			} else {
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 0);
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 1);
			}
			if (rShift) {
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 4);
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 5);
			}
			else {
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 4);
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 5);
			}
		}
		else {
			if (lShift) {
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 0);
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 1);
			}
			else {
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 0);
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 1);
			}
			if (rShift) {
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 4);
				rgblight_setrgb_at(0x00, 0x00, 0xFF, 5);
			}
			else {
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 4);
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 5);
			}
		}
		
		static uint8_t old_layer = 255;
		uint8_t new_layer = biton32(layer_state);

		if (old_layer != new_layer) {
			switch (new_layer) {
			case _QW:
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 2);
				rgblight_setrgb_at(0xFF, 0x00, 0x00, 3);
				
				break;
			case _RS:
				rgblight_setrgb_at(0xFF, 0xFF, 0x00, 2);
				rgblight_setrgb_at(0xFF, 0xFF, 0x00, 3);
				
				break;
			case _LW:
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 2);
				rgblight_setrgb_at(0x00, 0xFF, 0x00, 3);
				
				break;
			}

			old_layer = new_layer;
		}

	#endif //RGBLIGHT_ENABLE
 }

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	 switch (keycode) {
	 //if alt is pressed or ctrl without shift is pressed, key returns tab. else return esc
	 //this key is used for esc and tab. tab for alt+tab or ctrl+tab while acting as esc for other times and for ctrl+shift+esc (task manager)
	 case ESCTAB:
		 if (record->event.pressed) {

		   lAlt = keyboard_report->mods & MOD_BIT(KC_LALT);
		   rAlt = keyboard_report->mods & MOD_BIT(KC_RALT);
		   lCtrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
		   rCtrl = keyboard_report->mods & MOD_BIT(KC_RCTL);

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
	 case PRSNP:
		 if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_PSCREEN));
			SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_F12))));
		 } else {
			SEND_STRING(SS_UP(X_PSCREEN));
		 }
		 return false;
		 break;
	 default:
		 return true;
	 }
 }

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
