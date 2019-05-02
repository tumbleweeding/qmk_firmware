#include "cospad.h"
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _M 0

#define _______ KC_TRNS

enum my_keycodes {
  PRSNP = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-------------------.
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * |----|----|----|----|
   * |    |    |    |    |
   * `-------------------'
   */

[_M] = KEYMAP(
  KC_LCTL,  KC_LSFT,  KC_TAB,     KC_ESC,     \
  KC_LALT,  KC_WBAK,  LCTL(KC_W), KC_F5,      \
  KC_SPC,   KC_WFWD,  LCTL(KC_T), LGUI(KC_E), \
  KC_LEFT,  KC_PGDN,  KC_PGUP,    KC_NO,      \
  KC_DOWN,  KC_UP,    LGUI(KC_L), PRSNP,      \
  KC_RIGHT, KC_ENTER, KC_ESC,     KC_DEL),
};

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
