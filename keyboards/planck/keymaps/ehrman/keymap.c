#include QMK_KEYBOARD_H

#define RE_LSFT LSFT_T(KC_CAPS)
#define RE_RSFT RSFT_T(KC_CAPS)
#define RE_SPC LT(2, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_grid(
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,			KC_O,	KC_P,		KC_MINS,
		KC_ESC,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J	,	KC_K,		KC_L	,	KC_SCLN,		KC_QUOT,
		RE_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,		RE_RSFT,
		KC_LCTL,	KC_LALT,	KC_LGUI,	KC_BSPC,	MO(1),	KC_SPC,	KC_SPC,	MO(2),	KC_ENT,		KC_RGUI,	KC_RALT,		KC_RCTL
		),

	[1] = LAYOUT_planck_grid(
		XXXXXXX,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,		KC_F10,	KC_EQL,
		XXXXXXX,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,		KC_0,	KC_GRV,
		_______,	KC_F11,	KC_F12,	_______,	_______,	_______,	_______,	_______,	KC_LBRC,	KC_RBRC,	KC_BSLS,	_______,
		_______,	_______,	_______,	KC_DEL,	_______,	_______,	_______,	_______,	KC_INS,	_______,		_______,	_______
		),

	[2] = LAYOUT_planck_grid(
		XXXXXXX,	KC_HOME,	KC_UP,		KC_END,		XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_HOME,	KC_UP,		KC_PGUP,	XXXXXXX,	XXXXXXX,
		XXXXXXX,	KC_LEFT,	KC_DOWN,	KC_RGHT,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_LEFT,	XXXXXXX,	KC_RGHT,	XXXXXXX,	XXXXXXX,
		_______,	KC_PGUP,	XXXXXXX,	KC_PGDN,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_END,		KC_DOWN,	KC_PGDN,	XXXXXXX,	_______,
		_______,	_______,	_______,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,	XXXXXXX,	_______,	_______,	_______
		),
};
