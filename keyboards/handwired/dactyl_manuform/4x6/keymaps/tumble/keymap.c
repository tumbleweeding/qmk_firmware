#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _WM 0
#define _QW 1
#define _LW 2
#define _RS 3
#define _MS 4

// Fillers to make layering more clear

#define ____ KC_TRNS
#define xxxxxxx KC_NO

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define LW MO(_LW)
#define RS MO(_RS)
#define MS MO(_MS)

#define SPSH MT(MOD_LSFT, KC_SPC)

#define CQ M(CTLQ)
#define GQ M(GUIQ)
#define AQ M(ALTQ)

enum custom_keycodes {
    CTLQ = 0,
    GUIQ,
    ALTQ,
    // DYNAMIC_MACRO_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |      |      |                             |      |      |
 *                             |------+------|                             |------+------|
 *                             |      |      |                             |      |      |
 *                             +-------------+                             +-------------+
 *                                           +-------------+ +-------------+
 *                                           |      |      | |      |      |
 *                                           |------+------| |------+------|
 *                                           |      |      | |      |      |
 *                                           +-------------+ +-------------+
 */
[_WM] = LAYOUT( \
    KC_TAB,  KC_Q,  KC_D,   KC_R,   KC_W,   KC_B,               KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,KC_DEL,    \
    KC_BSPC, KC_A,  KC_S,   KC_H,   KC_T,   KC_G,               KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,   KC_QUOT,   \
    KC_LSFT, KC_Z,  KC_X,   KC_M,   KC_C,   KC_V,               KC_K,   KC_L,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,    \
                    KC_UP, KC_DOWN,                                             KC_LEFT,KC_RIGHT,                  \
                                    LW,     CQ,                 SPSH,   RS,                                        \
                                    AQ,     GQ,                 KC_ESC, MS,                                        \
                                    KC_ENT, KC_ESC,             KC_ENT, KC_BSPC                                    \
),

[_QW] = LAYOUT( \
    KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   _______,   \
    KC_BSPC, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

[_LW] = LAYOUT(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,            xxxxxxx,KC_7,   KC_8,   KC_9,   KC_0,   _______,   \
    _______,xxxxxxx,KC_BSLS,KC_MINS,KC_EQL, xxxxxxx,            xxxxxxx,KC_4,   KC_5,   KC_6,   xxxxxxx,xxxxxxx,   \
    _______,xxxxxxx,xxxxxxx,KC_LBRC,KC_RBRC,xxxxxxx,            KC_0,   KC_1,   KC_2,   KC_3,   xxxxxxx,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                    _______,KC_LCTRL,           _______,KC_END,                                    \
                                    KC_LALT,KC_LGUI,            KC_APP, _______,                                   \
                                    _______,_______,            _______,_______                                    \
),

[_RS] = LAYOUT(
    KC_GRV, xxxxxxx,xxxxxxx,KC_UP,  xxxxxxx,xxxxxxx,            xxxxxxx,KC_F9,  KC_F10, KC_F11, KC_F12, _______,   \
    KC_CAPS,xxxxxxx,KC_LEFT,KC_DOWN,KC_RGHT,xxxxxxx,            xxxxxxx,KC_F5,  KC_F6,  KC_F7,  KC_F8,  xxxxxxx,   \
    _______,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,            xxxxxxx,KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,   \
                    _______,_______,                                            _______,_______,                   \
                                    KC_HOME,_______,            _______,RS,                                        \
                                    _______,_______,            KC_ESC, _______,                                   \
                                    _______,_______,            _______,_______                                    \
),

[_MS] = LAYOUT(
    xxxxxxx,xxxxxxx,xxxxxxx,KC_MS_U,xxxxxxx,xxxxxxx,            xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,_______,   \
    KC_BSPC,xxxxxxx,KC_MS_L,KC_MS_D,KC_MS_R,xxxxxxx,            xxxxxxx,KC_BTN1,KC_BTN2,xxxxxxx,xxxxxxx,xxxxxxx,   \
    _______,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,            xxxxxxx,KC_WH_U,KC_WH_D,xxxxxxx,xxxxxxx,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                    _______,KC_LCTL,            _______,_______,                                   \
                                    KC_LALT,KC_LGUI,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
   // MACRODOWN only works in this function
   switch (id)
   {
   case CTLQ:
      if (record->event.pressed)
      {
         register_code(KC_LCTRL);
         layer_on(1);
      }
      else
      {
         layer_off(1);
         unregister_code(KC_LCTRL);
      }
      return false;
      break;
   case GUIQ:
      if (record->event.pressed)
      {
         register_code(KC_LGUI);
         layer_on(1);
      }
      else
      {
         layer_off(1);
         unregister_code(KC_LGUI);
      }
      return false;
      break;

   case ALTQ:
      if (record->event.pressed)
      {
         register_code(KC_LALT);
         layer_on(1);
      }
      else
      {
         layer_off(1);
         unregister_code(KC_LALT);
      }
      return false;
      break;
   }
   return MACRO_NONE;
};