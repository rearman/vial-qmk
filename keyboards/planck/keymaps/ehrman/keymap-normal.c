#include QMK_KEYBOARD_H

typedef enum {
  TD_NONE,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_UNKNOWN
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

enum {
  LYR,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void lr_finished(qk_tap_dance_state_t *state, void *user_data);
void lr_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ,-----------------------------------------------------------------------.
 * | ESC |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  =  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  [  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     | TAB | BSP |    SPC    | RSE | ENT |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_grid(
LALT_T(KC_ESC),  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    RALT_T(KC_MINS),
LCTL_T(KC_EQL),  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
LSFT_T(KC_LBRC), KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_RBRC),
XXXXXXX,         XXXXXXX, KC_TAB, TD(LYR), KC_BSPC, XXXXXXX, XXXXXXX, KC_SPC, TD(LYR), KC_ENT,  XXXXXXX, XXXXXXX
			 ),

[1] = LAYOUT_planck_grid(
_______, XXXXXXX, OSM(MOD_LGUI), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7, KC_P8,   KC_P9,   KC_PSCR, _______,
_______, KC_APP,  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4, KC_P5,   KC_P6,   XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX,       KC_CAPS, XXXXXXX, XXXXXXX, KC_NUM,  KC_P1, KC_P2,   KC_P3,   XXXXXXX, _______,
XXXXXXX, XXXXXXX, _______,       _______, _______, _______, _______, KC_P0, KC_PDOT, _______, XXXXXXX, XXXXXXX
),

[2] = LAYOUT_planck_grid(
KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,	   _______,
KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
XXXXXXX, XXXXXXX, _______, _______, KC_DEL,  _______, _______, KC_DEL,  _______, _______, XXXXXXX, XXXXXXX
),
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  }
  else return TD_UNKNOWN;
}

static td_tap_t lr_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void lr_finished(qk_tap_dance_state_t *state, void *user_data) {
    lr_tap_state.state = cur_dance(state);
    switch (lr_tap_state.state) {
	case TD_SINGLE_TAP:
	  if (layer_state_is(1)) {
	    layer_off(1);
	  } else {
	    layer_on(1);
	  }
	  break;
	case TD_SINGLE_HOLD:
	    layer_on(2);
	    break;
    default:
      break;
    }
}

void lr_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (lr_tap_state.state == TD_SINGLE_HOLD) {
    layer_off(2);
  }
  lr_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[]= {
  [LYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lr_finished, lr_reset)
};
