#include QMK_KEYBOARD_H

const key_override_t nine_bkt_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_LCBR);
const key_override_t zero_bkt_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_RCBR);
const key_override_t lprn_bkt_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LBRC);
const key_override_t rprn_bkt_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RBRC);
const key_override_t coln_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);

const key_override_t **key_overrides = (const key_override_t *[]){
	&nine_bkt_override,
	&zero_bkt_override,
	&lprn_bkt_override,
	&rprn_bkt_override,
	&coln_scln_override,
	NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_grid(
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,			KC_O,	KC_P,	KC_BSPC,
		KC_DEL,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,		KC_K,		KC_L,	KC_COLN,	KC_ENT,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,
		KC_LCTL,	KC_LALT,	KC_LGUI,	KC_MINS,	TT(1),	KC_SPC,	KC_SPC,	TT(2),	KC_QUOT,		KC_RGUI,	KC_RALT,	KC_RCTL
		),

	[1] = LAYOUT_planck_grid(
		KC_ESC,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_7,	KC_8,	KC_9,	KC_LPRN,	KC_GRV,
		KC_INS,	XXXXXXX,	XXXXXXX,	XXXXXXX,	TT(3),	XXXXXXX,	XXXXXXX,	KC_4,	KC_5,	KC_6,	KC_RPRN,	KC_EQL,
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_1,	KC_2,	KC_3,	KC_BSLS,	_______,
		_______,	_______,	_______,	XXXXXXX,	_______,	_______,	_______,	KC_0,	KC_DOT,	_______,	_______,	_______
		),

	[2] = LAYOUT_planck_grid(
		KC_ESC,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_HOME,	KC_UP,	KC_PGUP,	KC_PSCR,	XXXXXXX,
		KC_INS,	KC_APP,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_LEFT,		XXXXXXX,	KC_RGHT,	XXXXXXX,	XXXXXXX,
		_______,	XXXXXXX,	XXXXXXX,	KC_CAPS,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_END,		KC_DOWN,	KC_PGDN,	XXXXXXX,	_______,
		_______,	_______,	_______,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,		XXXXXXX,	_______,	_______,	_______
		),

	[3] = LAYOUT_planck_grid(
		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	XXXXXXX,
		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,	XXXXXXX,	XXXXXXX,	KC_F4,	KC_F5,	KC_F6,	KC_F11,	XXXXXXX,
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_F1,	KC_F2,	KC_F3,	KC_F12,	_______,
		_______,	_______,	_______,	XXXXXXX,	_______,	_______,	_______,	XXXXXXX,	XXXXXXX,	_______,	_______,	_______
		),
};
