#include QMK_KEYBOARD_H

#define _BASE 0

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _WM 0
#define _QW 1
#define _GM 2
#define _LW 3
#define _RS 4

#define LWHM LT(_LW, KC_HOME)
#define RSED LT(_RS, KC_END)
#define SPSH MT(MOD_LSFT, KC_SPC)
#define ENSH MT(MOD_RSFT, KC_ENT)
#define LOCK LGUI(KC_L)
#define CTLQ LM(_QW, 0x01)
#define GUIQ LM(_QW, 0x08)

enum my_keycodes {
	ESCTAB = SAFE_RANGE,
	PRSNP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WM] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_DEL,        KC_ESC,  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS, KC_MINS, KC_EQL,        PRSNP,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_LBRC, KC_RBRC,       LOCK,    XXXXXXX, XXXXXXX, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL, \
    KC_BSPC, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    XXXXXXX, XXXXXXX,       TG(_GM), XXXXXXX, XXXXXXX, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    XXXXXXX, XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, ENSH, \
    CTLQ,    GUIQ,    KC_LALT, KC_PGUP, LWHM,    KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, SPSH,    RSED,    KC_PGDN, KC_RALT, KC_APP,  KC_RCTL \
),
[_QW] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_DEL,        KC_ESC,  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS, KC_MINS, KC_EQL,        XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_LBRC, KC_RBRC,       XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    XXXXXXX, XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENSH, \
    CTLQ,    GUIQ,    KC_LALT, KC_PGUP, LWHM,    KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, SPSH,    RSED,    KC_PGDN, KC_RALT, KC_APP,  KC_RCTL \
),
[_GM] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_DEL,        KC_ESC,  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS, KC_MINS, KC_EQL,        PRSNP,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_LBRC, KC_RBRC,       LOCK,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    XXXXXXX, XXXXXXX,       TG(_GM), XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_COMM, XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENSH, \
    KC_LCTL, KC_X,    KC_LALT, KC_PGUP, LWHM,    KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, SPSH,    RSED,    KC_PGDN, KC_RALT, KC_APP,  KC_RCTL \
),
[_LW] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_DEL,        KC_ESC,  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS, KC_MINS, KC_EQL,        XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_BSPC, XXXXXXX, KC_BSLS, KC_MINS, KC_EQL,  KC_G,    KC_H,    XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_QUOT, \
    KC_LSFT, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT, \
    CTLQ,    GUIQ,    KC_LALT, KC_PGUP, LWHM,    KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, SPSH,    RSED,    KC_PGDN, KC_RALT, KC_APP,  KC_RCTL \
),
[_RS] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_DEL,        KC_ESC,  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_DEL, \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSLS, KC_MINS, KC_EQL,        XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,\
    KC_TAB,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
    KC_CAPS, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_QUOT, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   ENSH, \
    CTLQ,    GUIQ,    KC_LALT, KC_PGUP, LWHM,    KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, SPSH,    RSED,    KC_PGDN, KC_RALT, KC_APP,  KC_RCTL \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	 switch (keycode) {
	 case ESCTAB:
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