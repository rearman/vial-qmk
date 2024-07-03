#include QMK_KEYBOARD_H

/* LAYER KEYS */
#define RE_LWR LT(1, KC_BSPC)
#define RE_RSE LT(2, KC_ENT)

/* MODS */
#define MD_ESC LALT_T(KC_ESC)
#define MD_EQL LCTL_T(KC_EQL)
#define MD_GRV LSFT_T(KC_GRV)
#define MD_LBRC LCTL_T(KC_LBRC)
#define MD_F9 LALT_T(KC_F9)
#define MD_9 LCTL_T(KC_9)

#define MD_SLSH RALT_T(KC_SLSH)
#define MD_MINS RCTL_T(KC_MINS)
#define MD_BSLS RSFT_T(KC_BSLS)
#define MD_RBRC RCTL_T(KC_RBRC)
#define MD_F8 RALT_T(KC_F8)
#define MD_8 RCTL_T(KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------------------------------------.
 * | ESC |  '  |  ,  |  .  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  =  |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  `  |  ;  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | CTL | WIN | LWR | ALT | BSP |    SPC    | ENT | ALT | RSE | APP | CTL |
 * `-----------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_grid(
MD_ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    MD_SLSH,
MD_EQL, KC_A,    KC_O,    KC_E,   KC_U,    KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    MD_MINS,
MD_GRV, KC_SCLN, KC_Q,    KC_J,   KC_K,    KC_X,   KC_B,   KC_M,   KC_W,   KC_V,    KC_Z,    MD_BSLS,
XXXXXXX, KC_LGUI, XXXXXXX, KC_TAB, RE_LWR, KC_SPC, KC_SPC, RE_RSE, KC_DEL, XXXXXXX, KC_APP, XXXXXXX
),

/* Lower 1
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     | PSC |     |     | HME |  U  | PUP | CAP |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | APP |     |     |     | INS |     |  L  |     |  R  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     | DEL |     | END |  D  | PDN |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_grid(
_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_PGUP, KC_CAPS, _______,
_______, KC_APP, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS, XXXXXXX, KC_LEFT, XXXXXXX, KC_RGHT, XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, KC_END,  KC_DOWN, KC_PGDN, XXXXXXX, _______,
_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
),

/* Raise 2
 * ,-----------------------------------------------------------------------.
 * | F09 | F05 | F05 | F03 | F01 | F11 | F12 | F10 | F02 | F04 | F06 | F08 |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  [  |  &  |  %  |  #  |  (  |  !  |  @  |  )  |  *  |  $  |  ^  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_grid(
MD_F9,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F11,  KC_F12,  KC_F10,  KC_F2,   KC_F4,   KC_F6,   MD_F8,
MD_LBRC, KC_AMPR, KC_PERC, KC_HASH, KC_LPRN, KC_EXLM, KC_AT,   KC_RPRN, KC_ASTR, KC_DLR,  KC_CIRC, MD_RBRC,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise) 3
 * ,-----------------------------------------------------------------------.
 * | RST |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  9  |  5  |  5  |  3  |  1  |     |     |  0  |  2  |  4  |  6  |  8  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[3] = LAYOUT_planck_grid(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
MD_9,    KC_7,    KC_5,    KC_3,    KC_1,    XXXXXXX, XXXXXXX, KC_0,    KC_2,    KC_4,    KC_6,    MD_8,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, 1, 2, 3);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}
