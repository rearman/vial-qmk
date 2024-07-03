#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

const key_override_t coln_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);

const key_override_t **key_overrides = (const key_override_t *[]){
	&coln_scln_override,
	NULL
};

/* LAYERS */
#define RE_LWR	LT(1, KC_BSPC)
#define RE_RSE	LT(2, KC_ENT)
/* MODS */
#define RE_TAB	LALT_T(KC_TAB)
#define RE_MINS	RALT_T(KC_MINS)
#define RE_EQL	LCTL_T(KC_EQL)
#define RE_QUOT	RCTL_T(KC_QUOT)
#define RE_LCAP	LSFT_T(KC_CAPS)
#define RE_RCAP	RSFT_T(KC_CAPS)
#define RE_GRV	RALT_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_grid(
		RE_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	RE_MINS,
		RE_EQL,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_COLN,	RE_QUOT,
		RE_LCAP,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	RE_RCAP,
		KC_LGUI,	TO(4),	TO(5),	KC_ESC,	RE_LWR,	KC_SPC,	KC_SPC,	TT(2),	KC_ENT,	XXXXXXX,	KC_APP,	KC_RGUI
		),

	[1] = LAYOUT_planck_grid(
		_______,	XXXXXXX,	XXXXXXX,	KC_LBRC,	KC_RBRC,	XXXXXXX,	XXXXXXX,	KC_7,	KC_8,	KC_9,	XXXXXXX,	_______,
		_______,	XXXXXXX,	XXXXXXX,	KC_LPRN,	KC_RPRN,	XXXXXXX,	XXXXXXX,	KC_4,	KC_5,	KC_6,	XXXXXXX,	RE_GRV,
		_______,	XXXXXXX,	XXXXXXX,	KC_LCBR,	KC_RCBR,	XXXXXXX,	XXXXXXX,	KC_1,	KC_2,	KC_3,	KC_BSLS,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_0,	KC_DOT,	_______,	_______,	_______
		),

	[2] = LAYOUT_planck_grid(
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PSCR,	XXXXXXX,	KC_HOME,	KC_UP,	KC_PGUP,	XXXXXXX,	_______,
		_______,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_INS,	XXXXXXX,	KC_LEFT,	KC_APP,	KC_RGHT,	XXXXXXX,	_______,
		_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	XXXXXXX,	XXXXXXX,	KC_END,	KC_DOWN,	KC_PGDN,	XXXXXXX,	_______,
		_______,	_______,	_______,	_______,	KC_DEL,	_______,	_______,	_______,	_______,	_______,	_______,	_______
		),

	[3] = LAYOUT_planck_grid(
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,
		_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,	XXXXXXX,	XXXXXXX,	_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______
		),

	[4] = LAYOUT_planck_grid(
		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	TO(0),
		XXXXXXX,	XXXXXXX,	TO(5),	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
		KC_P,	KC_H,	KC_D,	KC_B,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
		XXXXXXX,	XXXXXXX,	TO(5),	XXXXXXX,	KC_A,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX
		),

	[5] = LAYOUT_planck_grid(
		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	TO(0),
		XXXXXXX,	TO(4),	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
		KC_0,	KC_LPRN,	KC_DLR,	KC_DQT, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
		XXXXXXX,	TO(4),	XXXXXXX,	XXXXXXX,	KC_EXLM,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX
		)
};

// Required for raise/lower/adjust
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, 1, 2, 3);
}

/*
 * Local Variables:
 * mode: C
 * tab-width: 9
 * c-basic-offset: 9
 * indent-tabs-mode: t
 * End:
 * ex: shiftwidth=9 tabstop=9
 * Acme: Tab 9
 */
