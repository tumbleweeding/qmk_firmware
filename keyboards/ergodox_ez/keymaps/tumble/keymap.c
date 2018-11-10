#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define WM 0 // default layer
#define QW 1 // temp qwerty layer
#define GM 2 // locked qwerty layer
#define LW 3 // lower
#define RS 4 // raise
#define MS 5 // mouse

//#define CTLQ LM(QW, 0x01)
//#define GUIQ LM(QW, 0x08)
//#define ALTQ LM(QW, 0x04)
#define LOCK LGUI(KC_L)
#define SPSH MT(MOD_LSFT, KC_SPC)

enum my_keycodes {
  CTLQ = 0,
  GUIQ,
  ALTQ,
  PRSNP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[WM] = KEYMAP_80(
        // left hand
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,
        KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,   KC_B,   KC_J,
        KC_BSPC, KC_A,    KC_S,    KC_H,    KC_T,   KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,   KC_V,   KC_K,
        M(CTLQ), M(GUIQ), M(ALTQ), KC_LSFT, MO(LW),
                                                        PRSNP,   KC_PGUP,
	                                       LOCK,    DF(GM),  KC_DEL,
	                                       M(CTLQ), M(ALTQ), KC_ENT,
        // right hand
             KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
             KC_B,    KC_J,   KC_F,    KC_U,    KC_P,    KC_SCLN,  KC_DEL,
                      KC_Y,   KC_N,    KC_E,    KC_O,    KC_I,     KC_QUOT,
             KC_V,    KC_K,   KC_L,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                              MO(RS),  MO(MS),  KC_RALT, KC_APP,   KC_RCTRL,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
             KC_ESC,  KC_BSPC, SPSH
    ),

[QW] = KEYMAP_80(  
        // left hand
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,
        KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,
        M(CTLQ),  M(GUIQ), M(ALTQ), KC_LSFT, KC_TRNS,
                                                        PRSNP,   KC_PGUP,
	                                       LOCK,    DF(WM),  KC_ENT,
	                                       KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
             KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                              KC_TRNS, KC_TRNS, KC_RALT, KC_APP,  KC_RCTRL,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
	     KC_TRNS, KC_TRNS, KC_TRNS
    ),

[GM] = KEYMAP_80(  
        // left hand
        KC_ESC,       KC_F1,  KC_F2,  KC_F3,    KC_F4,   KC_F5,   KC_F6,
        KC_TAB,       KC_Q,   KC_W,   KC_E,     KC_R,    KC_T,    KC_Y,
        KC_BSPC,      KC_A,   KC_S,   KC_D,     KC_F,    KC_G,	 
        KC_LSFT,      KC_Z,   KC_X,   KC_C,     KC_V,    KC_B,    KC_N,
        KC_LCTRL,     KC_X,   KC_LALT,KC_LALT,  KC_SPC,
                                                         PRSNP,   KC_PGUP,
	                                        LOCK,    DF(WM),  KC_ENT,
	                                        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
             KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
             KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                              KC_LALT, KC_TRNS, KC_RALT, KC_APP,   KC_RCTRL,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
	     KC_TRNS, KC_TRNS, KC_TRNS
    ),
[LW] = KEYMAP_80(
       // left hand
       KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_TRNS, XXXXXXX, KC_BSLS, KC_MINS, KC_EQL,  XXXXXXX,
       KC_TRNS, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                        PRSNP,   KC_PGUP,
	                                       LOCK,    DF(WM),  KC_ENT,
	                                       KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
                XXXXXXX, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
       XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                         KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
	     KC_TRNS, KC_TRNS, KC_TRNS
),

[RS] = KEYMAP_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
       KC_CAPS, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,
       KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
                                                        PRSNP,   KC_PGUP,
	                                       LOCK,    DF(WM),  KC_ENT,
	                                       KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       XXXXXXX,  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
                 XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
       XXXXXXX,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
	     KC_TRNS, KC_TRNS, KC_TRNS
),

[MS] = KEYMAP_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_CAPS, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,
       KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
                                                        PRSNP,   KC_PGUP,
	                                       LOCK,    DF(WM),  KC_ENT,
	                                       KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
                 XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  XXXXXXX, KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, KC_TRNS,
                          KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_PGDN, KC_UP,
             KC_LEFT, KC_DOWN, KC_RIGHT,
	     KC_TRNS, KC_TRNS, KC_TRNS
)
};
/*
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};
*/
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      case CTLQ:
	if (record->event.pressed) {
        register_code(KC_LCTRL);
        layer_on(1); // your qwerty layer number
      } else {
        layer_off(1); // your qwerty layer number
        unregister_code(KC_LCTRL);
      }
      return false;
      break;
      case GUIQ:
	if (record->event.pressed) {
        register_code(KC_LGUI);
        layer_on(1); // your qwerty layer number
      } else {
        layer_off(1); // your qwerty layer number
        unregister_code(KC_LGUI);
      }
      return false;
      break;
      
      case ALTQ:
	if (record->event.pressed) {
        register_code(KC_LALT);
        layer_on(1); // your qwerty layer number
      } else {
        layer_off(1); // your qwerty layer number
        unregister_code(KC_LALT);
      }
      return false;
      break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};
/*
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	 switch (keycode) {
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
