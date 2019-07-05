#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_extras/keymap_spanish.h"

// Definition of keyboard layers.
enum keyboard_layers
{
  KL_BASE = 0,    // Base layer.
  KL_NAVIGATION,  // Navigation layer.
  KL_SYMBOL,      // Symbol layer.
};

// Custom keycodes used by this keymap.
enum custom_keycodes
{
  UNUSED = SAFE_RANGE,
  /* Macro keycodes. */
  CK_ARROW,  // ->
  /* Unicode keycodes. */
  CK_SHRUG,  // ¯\_(ツ)_/¯
};

// Keycode macros.
#define KJ_TILD ALGR(KC_4)

// Layers.
#define MO_SYMBL MO(KL_SYMBOL)
#define MO_NAVIG MO(KL_NAVIGATION)

// Unicode single keycode macros.
#define KU_POUND UC(0xA3)  // £
#define KU_DEGRE UC(0xB0)  // °

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
[KL_BASE] = LAYOUT_ergodox(

  // Left hand.
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_NO,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     MO_SYMBL,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     MO_NAVIG,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_HYPR,  KC_MEH,

                                                              KC_NO,    KC_NO,
                                                                        KC_HOME,
                                                    KC_SPC,   KC_BSPC,  KC_END,
  // Right hand.
            KC_INS,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     ES_APOS,
            MO_SYMBL, KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     ES_IEXL,
                      KC_H,     KC_J,     KC_K,     KC_L,     ES_NTIL,  ES_ACUT,
            MO_NAVIG, KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT,
                                KC_ALGR,  KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT,

  KC_NO,    KC_INS,
  KC_PGUP,
  KC_PGDN,  KC_DELT,  KC_ENT
),
[KL_SYMBOL] = LAYOUT_ergodox(
  // Left hand.
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,    KC_TRNS,
  KC_TRNS,  KC_NO,    CK_ARROW, ES_LESS,   ES_GRTR, ES_HASH,  KC_TRNS,
  KC_TRNS,  ES_SLSH,  ES_BSLS,  ES_LPRN,   ES_RPRN, ES_UNDS,
  KC_TRNS,  ES_LBRC,  ES_RBRC,  ES_LCBR,   ES_RCBR, ES_AT,    KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,

                                                              KC_TRNS,  KC_TRNS,
                                                                        KC_TRNS,
                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,
  // Right hand.
            KC_TRNS,  ES_OVRR,  ES_NOT,   KJ_TILD,  KU_DEGRE, KC_NO,    KC_TRNS,
            KC_TRNS,  ES_CIRC,  ES_EQL,   ES_AMPR,  ES_PIPE,  KC_EXLM,  KC_TRNS,
                      KC_PERC,  ES_PLUS,  ES_MINS,  ES_ASTR,  ES_SLSH,  KC_TRNS,
            KC_TRNS,  ES_CCED,  KC_DLR,   ES_EURO,  KU_POUND, KC_NO,    KC_TRNS,
                                KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,

  KC_TRNS,  CK_SHRUG,
  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS
),
[KL_NAVIGATION] = LAYOUT_ergodox(
  // Left hand.
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
  KC_TRNS,  KC_NO,    KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_NO,
  KC_TRNS,  KC_NO,    KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_NO,    KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                              KC_TRNS,  KC_TRNS,
                                                                        KC_TRNS,
                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,
  // Right hand.
            KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
            KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F12,
                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
            KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,
                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

// The first LED of the Ergodox EZ shows the current state of Caps Lock.
void change_caps_lock_led(void)
{
  // Flag for the caps lock state.
  static bool is_caps_lock_enabled = false;

  if (is_caps_lock_enabled)
  {
    ergodox_right_led_1_off();
  }
  else
  {
    ergodox_right_led_1_on();
  }
  is_caps_lock_enabled = !is_caps_lock_enabled;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!record->event.pressed)
  {
    return true;
  }

  switch (keycode)
  {
    /* Modification of standard keycodes. */
    case KC_CAPS:
      change_caps_lock_led();
      break;
    /* Custom macro keycodes. */
    case CK_ARROW:
      tap_code(ES_MINS);
      tap_code16(ES_GRTR);
      break;
    /* Custom unicode keycodes. */
    case CK_SHRUG:
      send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
      break;
  }

  return true;
}

// Runs once the keyboard matrix is initialized, but before other features have been set up.
void matrix_init_user(void)
{
  // ToDo: Multiplatform support.
  set_unicode_input_mode(UC_LNX);
};

// This runs every time that the layers get changed.
uint32_t layer_state_set_user(uint32_t state)
{
  ergodox_board_led_off();

  switch (biton32(state))
  {
    case KL_SYMBOL:
      ergodox_right_led_2_on();
      ergodox_right_led_3_off();
      break;
    case KL_NAVIGATION:
      ergodox_right_led_2_off();
      ergodox_right_led_3_on();
      break;
    default:
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
      break;
  }

  return state;
};
