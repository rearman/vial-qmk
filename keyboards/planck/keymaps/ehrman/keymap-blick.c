#include QMK_KEYBOARD_H
/* 1		2	3	4	5	6	7	8	9	0	11	12
 * tab	esc	z	x	k	g	b	v	q	j	ret	bsp
 * fig		.	p	w	f	u	l	c	m	y	,	fig
 * cap	d	h	i	a	t	e	n	s	o	r	cap
 * ctl		alt	gui	X	X	spc	spc	X	X	gui	alt	ctl
 */

#define RE_LSFT LSFT_T(KC_CAPS)
#define RE_RSFT RSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_grid(
		KC_TAB,	KC_ESC,	KC_Z,	KC_X,	KC_K,	KC_G,	KC_B,	KC_V,	KC_Q,	KC_J,		KC_ENT,		KC_BSPC,
		TT(1),	KC_DOT,	KC_P,	KC_W,	KC_F,	KC_U,	KC_L,	KC_C,	KC_M,	KC_Y,	KC_COMM,	TT(1),
		RE_LSFT,	KC_D,	KC_H,	KC_I,		KC_A,	KC_T,	KC_E,	KC_N,	KC_S,	KC_O,	KC_R,		RE_RSFT,
		KC_LCTL,	KC_LALT,	KC_LGUI,	XXXXXXX,	XXXXXXX,	KC_SPC,	KC_SPC,	XXXXXXX,	XXXXXXX,	KC_RGUI,	KC_RALT,		KC_RCTL
		),

	[1] = LAYOUT_planck_grid(
		_______,	KC_LBRC,	KC_MINS,	KC_CIRC,	KC_UNDS,	KC_LPRN,	KC_RPRN,	KC_AT,	KC_HASH,	KC_COLN,	KC_RBRC,		_______,
		_______,	KC_BSLS,	KC_SLSH,	KC_QUOT,	KC_DQT,	KC_EXLM,	KC_SCLN,		KC_QUES,	KC_PERC,	KC_DLR,		KC_AMPR,	_______,
		_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,		KC_7,	KC_8,	KC_9,		KC_0,		_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,		_______,		_______
		),
};
