#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _WM 0
#define _QW 1
#define _LW 2
#define _RS 3
#define _MS 4

enum custom_keycodes {
    CTLQ = 0,
    GUIQ,
    ALTQ,
    // DYNAMIC_MACRO_RANGE,
};

// #define DYNAMIC_MACRO_SIZE 128
// #include "dynamic_macro.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

#define SPSH MT(MOD_LSFT, KC_SPC)

// #define MR1 DYN_REC_START1
// #define MR2 DYN_REC_START2
// #define MP1 DYN_MACRO_PLAY1
// #define MP2 DYN_MACRO_PLAY2
// #define MST DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WM] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                               KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                               KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    M(ALTQ),          KC_ESC,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    M(GUIQ), MO(_LW), M(CTLQ),                   SPSH,    MO(_RS), MO(_MS)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_QW] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_LW] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                            xxxxxxx, KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, xxxxxxx, KC_BSLS, KC_MINS, KC_EQL,  xxxxxxx,                            xxxxxxx, KC_4,    KC_5,    KC_6,    xxxxxxx, xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, xxxxxxx, xxxxxxx, KC_LBRC, KC_RBRC, xxxxxxx, _______,          KC_APP,  KC_0,    KC_1,    KC_2,    KC_3,    xxxxxxx, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, MO(_LW), _______,                   _______, KC_END,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_RS] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  xxxxxxx, xxxxxxx, KC_UP,   xxxxxxx, xxxxxxx,                            xxxxxxx, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, xxxxxxx, KC_LEFT, KC_DOWN, KC_RGHT, xxxxxxx,                            xxxxxxx, KC_F5,   KC_F6,   KC_F7,   KC_F8,   xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______, xxxxxxx, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_HOME, _______,                   _______, MO(_RS), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_MS] = KEYMAP(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  xxxxxxx, xxxxxxx, KC_MS_U, xxxxxxx, xxxxxxx,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, xxxxxxx, KC_MS_L, KC_MS_D, KC_MS_R, xxxxxxx,                            xxxxxxx, KC_BTN1, KC_BTN2, xxxxxxx, xxxxxxx, xxxxxxx,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, MO(_LW), KC_RCTL,                   _______, MO(_RS), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }*/
  switch (keycode) {
  }
  return true;
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
