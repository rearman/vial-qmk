#include QMK_KEYBOARD_H

enum re_keycode {
	RE_COLN = QK_KB_0,
	RE_LPRN,
	RE_RPRN,
	RE_9,
	RE_0,
	RE_TILDE,
};

#define RE_ESC	LGUI_T(KC_ESC)
#define RE_LSFT	LSFT_T(KC_CAPS)
#define RE_RSFT	RSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_hhkb(
			     RE_ESC,	RE_TILDE,	KC_7,		KC_5,		KC_3,	KC_1,	RE_9,	RE_0,	KC_2,	KC_4,	KC_6,	KC_8,	RE_LPRN,	RE_LPRN,	KC_BSLS,	
			     KC_TAB,	KC_QUOT,	KC_COMM,	KC_DOT,	KC_P,	KC_Y,	KC_F,	KC_G,	KC_C,	KC_R,	KC_L,	KC_SLSH,	KC_EQL,		KC_BSPC,
			     KC_DEL,	KC_A,		KC_O,		KC_E,	KC_U,	KC_I,	KC_D,	KC_H,	KC_T,	KC_N,	KC_S,	KC_MINS,	KC_ENT,
			     RE_LSFT,	RE_COLN,	KC_Q,		KC_J,	KC_K,	KC_X,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,	RE_RSFT,	TT(1),
			     KC_LALT,	KC_LCTL,	KC_SPC,	KC_RCTL,	KC_RALT
			     ),

	[1] = LAYOUT_60_hhkb(
			     KC_TRNS,	KC_F11,		KC_F7,	KC_F5,	KC_F3,		KC_F1,		KC_F9,	KC_F10,	KC_F2,	KC_F4,	KC_F6,		KC_F8,		KC_F12,	KC_NO,	MO(2),
			     KC_TRNS,	KC_NO,		KC_NO,	KC_NO,	KC_PSCR,	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_UP,		KC_NO,	KC_NO,
			     KC_INS,	KC_HOME,	KC_NO,	KC_END,	KC_PGUP,	KC_NO,	KC_PGDN,	KC_NO,	KC_NO,	KC_NO,	KC_LEFT,	KC_RGHT,	KC_TRNS,
			     KC_TRNS,	KC_NO,		KC_NO,	KC_NO,	KC_NO,		KC_NO,		KC_NO,	KC_APP,	KC_NO,	KC_NO,	KC_DOWN,	KC_TRNS,	KC_TRNS,
			     KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
			     ),

	[2] = LAYOUT_60_hhkb(
			     QK_BOOT,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_TRNS,
			     KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			     KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			     KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_TRNS,
			     KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO
			     ),
};

/* PER LAYER LED BACKLIGHT COLORS */
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_RED});
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_CYAN});
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_PURPLE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_layer0_layer, my_capslock_layer, my_layer1_layer, my_layer2_layer);

void keyboard_post_init_user(void)
{
	rgblight_layers = my_rgb_layers;
}
/* Caps-lock color */
bool led_update_user(led_t led_state)
{
	rgblight_set_layer_state(1, led_state.caps_lock);
	return true;
}

/* Default State */
layer_state_t default_layer_state_set_user(layer_state_t state)
{
	rgblight_set_layer_state(0, layer_state_cmp(state, 0));
	return state;
}

/* Other layer colors */
layer_state_t layer_state_set_user(layer_state_t state)
{
	rgblight_set_layer_state(2, layer_state_cmp(state, 1));
	rgblight_set_layer_state(3, layer_state_cmp(state, 2));
	return state;
}

uint8_t mod_state;
bool press_custom_key(uint16_t shifted, uint16_t unshifted)
{
	mod_state = get_mods();
	if (mod_state &MOD_MASK_SHIFT) {
		del_mods(MOD_MASK_SHIFT);
		tap_code16(shifted);
		set_mods(mod_state);
		return false;
	} else {
		tap_code16(unshifted);
	return false;
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
	case RE_COLN:
		if (record->event.pressed)
			press_custom_key(KC_SCLN, KC_COLN);
		return false;
	case RE_LPRN:
		if (record->event.pressed)
			press_custom_key(KC_LBRC, KC_LPRN);
		return false;
	case RE_RPRN:
		if (record->event.pressed)
			press_custom_key(KC_RBRC, KC_RPRN);
		return false;
	case RE_9:
		if (record->event.pressed)
			press_custom_key(KC_LCBR, KC_9);
		return false;
	case RE_0:
		if (record->event.pressed)
			press_custom_key(KC_RCBR, KC_0);
		return false;
	case RE_TILDE:
		if (record->event.pressed)
			press_custom_key(KC_GRV, KC_TILDE);
		return false;
	default:
		return true;
	}
}
