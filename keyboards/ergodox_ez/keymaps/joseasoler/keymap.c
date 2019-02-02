#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_extras/keymap_spanish.h"

// Definition of keyboard layers.
enum keyboard_layers {
	BASE = 0, // Base layer
	SYMB,     // Symbols layer
	NAV,      // Navigation layer
	UNICODE,  // Unicode layer
};

// Custom keycodes used by this keymap.
enum custom_keycodes {
	UNUSED = SAFE_RANGE,
	/* Unicode keycodes. */
	U_POUND, // £
	U_SHRUG, // ¯\_(ツ)_/¯
	U_LENNY, // ( ͡° ͜ʖ ͡°)
	U_ANGRY, // ಠ_ಠ
};

// Macros and abbreviations.
#define J_HYPER ALL_T(KC_NO)
#define J_MEH MEH_T(KC_NO)
#define J_TILD ALGR(KC_4)

// Flag for the caps lock state.
bool is_caps_lock_enabled = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | ¡/¿  |           |Unicod|   6  |   7  |   8  |   9  |   0  |  '/?   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |Symbol|           |Symbol|   Y  |   U  |   I  |   O  |   P  |   ç    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ñ  |   ´    |
 * |--------+------+------+------+------+------| Nav  |           | Nav  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Cmd |  Alt | Hyper|  Meh |                                       |AltGr | App  | Left | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | #### | #### |       | #### | #### |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Delete	|Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,  KC_5,  ES_IEXL,
  KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,  KC_T,  MO(SYMB),
  KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,  KC_G,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,  KC_B,  MO(NAV),
  KC_LCTL,  KC_LGUI,  KC_LALT,  J_HYPER, J_MEH,

                                                                           KC_NO,    KC_NO,
                                                                                     KC_HOME,
                                                                  KC_SPC,  KC_BSPC,  KC_END,
  // right hand
                              MO(UNICODE),  KC_6,  KC_7,     KC_8,     KC_9,     KC_0,    ES_APOS,
                              MO(SYMB),     KC_Y,  KC_U,     KC_I,     KC_O,     KC_P,    ES_CCED,
                                            KC_H,  KC_J,     KC_K,     KC_L,     ES_NTIL, ES_ACUT,
                              MO(NAV),      KC_N,  KC_M,     KC_COMM,  KC_DOT,   KC_UP,   KC_RSFT,
                                                   KC_ALGR,  KC_APP,   KC_LEFT,  KC_DOWN, KC_RGHT,

  KC_NO,    KC_NO,
  KC_PGUP,
  KC_PGDN,  KC_DELT,  KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc    | #### | #### | #### | #### | #### | #### |           |DISBL | #### | #### | #### | #### | #### |  ####  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab    |   &  |   |  |   {  |   }  |   $  |DISBL |           |DISBL |   º  |   +  |   -  |   *  |   /  |    ¬   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps   |   !  |   =  |   (  |   )  |   _  |------|           |------|   @  |   /  |   \  |   %  |   ^  |    `   |
 * |---------+------+------+------+------+------|DISBL |           |DISBL |------+------+------+------+------+--------|
 * | LShift  |   ~  |   #  |   [  |   ]  | #### |      |           |      |   €  |   <  |   >  |   £  |  Up  | RShift |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl  |  Cmd |  Alt | Hyper|  Meh |                                       |AltGr | App  | Left | Down | Right|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | #### | #### |       | #### | #### |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Delete	|Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
  KC_TRNS,  ES_AMPR,  ES_PIPE,  ES_LCBR,   ES_RCBR,  KC_DLR,   KC_TRNS,
  KC_TRNS,  KC_EXLM,  ES_EQL,   ES_LPRN,   ES_RPRN,  ES_UNDS,
  KC_TRNS,  J_TILD,   ES_HASH,  ES_LBRC,   ES_RBRC,  KC_NO,    KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,

                                                                                    KC_TRNS,  KC_TRNS,
                                                                                              KC_TRNS,
                                                                          KC_TRNS,  KC_TRNS,  KC_TRNS,
  // right hand
                              KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                              KC_TRNS,  ES_OVRR,  ES_PLUS,  ES_MINS,  ES_ASTR,  ES_SLSH,  ES_NOT,
                                        ES_AT,    ES_SLSH,  ES_BSLS,  KC_PERC,  ES_CIRC,  ES_ACUT,
                              KC_TRNS,  ES_EURO,  ES_LESS,  ES_GRTR,  U_POUND,  KC_TRNS,  KC_TRNS,
                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 2: Navigation layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |DISBL |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |      |      |      |      |      |DISBL |           |DISBL |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  | PgUp |PgDown| Home |  End |      |------|           |------|      | Play | Prev | Next |      |        |
 * |--------+------+------+------+------+------|DISBL |           |DISBL |------+------+------+------+------+--------|
 * | LShift |      |      |      |Insert|      |      |           |      |      |VolUp |VolDn | Mute |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Cmd |  Alt | Hyper|  Meh |                                       |AltGr | App  | Left | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | #### | #### |       | #### | #### |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Delete	|Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [NAV] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,  KC_NO,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_TRNS,
  KC_TRNS,  KC_PGUP,  KC_PGDN,  KC_HOME,  KC_END,  KC_NO,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_INS,  KC_NO,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                                                    KC_TRNS,  KC_TRNS,
                                                                                              KC_TRNS,
                                                                          KC_TRNS,  KC_TRNS,  KC_TRNS,
  // right hand
                              KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
                              KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F12,
                                        KC_NO,    KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_NO,    KC_NO,
                              KC_TRNS,  KC_TRNS,  KC_VOLU,  KC_VOLD,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 3: Unicode layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |      |ANGRY |LENNY |SHRUG |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      |      |      |      |      |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Cmd |  Alt | Hyper|  Meh |                                       |AltGr | App  | Left | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | #### | #### |       | #### | #### |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Delete	|Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [UNICODE] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,
  KC_TRNS,  KC_NO,    U_ANGRY,  U_LENNY,  U_SHRUG,  KC_NO,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                                                    KC_TRNS,  KC_TRNS,
                                                                                              KC_TRNS,
                                                                          KC_TRNS,  KC_TRNS,  KC_TRNS,
  // right hand
                              KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                              KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                              KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,
                                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

// Enabling caps lock will turn on the first led.
void process_caps_lock(bool pressed) {
  if (pressed) {
    if (is_caps_lock_enabled) {
      ergodox_right_led_1_off();
    }
    else {
      ergodox_right_led_1_on();
    }
    is_caps_lock_enabled = !is_caps_lock_enabled;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
		/* Modification of existing keycodes. */
		case KC_CAPS:
      process_caps_lock(record->event.pressed);
			break;
		/* Unicode keycodes. */
		case U_POUND:
      send_unicode_hex_string("00A3");
			return false;
		case U_SHRUG:
			send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
			return false;
		case U_LENNY:
			send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
			return false;
		case U_ANGRY:
			send_unicode_hex_string("0CA0 005F 0CA0");
			return false;
		}
	}
	// Allow QMK to process the event normally.
	return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	// ToDo: Multiplatform support.
	set_unicode_input_mode(UC_LNX);
};

// Runs after a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
	ergodox_board_led_off();

	uint8_t layer = biton32(state);
	switch (layer) {
		case SYMB:
			ergodox_right_led_2_on();
			ergodox_right_led_3_off();
			break;
		case NAV:
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
