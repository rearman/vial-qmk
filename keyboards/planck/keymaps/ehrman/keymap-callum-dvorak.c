#include QMK_KEYBOARD_H

enum planck_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

/* LAYER KEYS */
#define RE_LWR LT(_LOWER, KC_BSPC)
#define RE_RSE LT(_RAISE, KC_ENT)

/* HOME ROW MODS */
#define HM_A LGUI_T(KC_A)
#define HM_O LALT_T(KC_O)
#define HM_E LCTL_T(KC_E)
#define HM_U LSFT_T(KC_U)

#define HM_S RGUI_T(KC_S)
#define HM_N RALT_T(KC_N)
#define HM_T RCTL_T(KC_T)
#define HM_H RSFT_T(KC_H)

/* SYMBOL HOME ROW MODS */
#define HM_7 LGUI_T(KC_7)
#define HM_5 LALT_T(KC_5)
#define HM_3 LCTL_T(KC_3)
#define HM_1 LSFT_T(KC_1)

#define HM_0 RSFT_T(KC_0)
#define HM_2 RCTL_T(KC_2)
#define HM_4 RALT_T(KC_4)
#define HM_6 LGUI_T(KC_6)

/* one shot mods */
#define OM_LSFT OSM(MOD_LSFT)
#define OM_LCTL OSM(MOD_LCTL)
#define OM_LALT OSM(MOD_LALT)
#define OM_LGUI OSM(MOD_LGUI)
#define OM_RGUI OSM(MOD_RGUI)
#define OM_RALT OSM(MOD_RALT)
#define OM_RCTL OSM(MOD_RCTL)
#define OM_RSFT OSM(MOD_RSFT)

  const uint16_t PROGMEM ls_combo[] = {KC_BSPC, KC_U, COMBO_END};

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
[_DVORAK] = LAYOUT_planck_grid(
KC_ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH,
KC_EQL, KC_A,    KC_O,    KC_E,   KC_U,    KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,    KC_MINS,
KC_GRV, KC_SCLN, KC_Q,    KC_J,   KC_K,    KC_X,   KC_B,   KC_M,   KC_W,   KC_V,    KC_Z,    KC_BSLS,
XXXXXXX, KC_LGUI, XXXXXXX, KC_TAB, RE_LWR, KC_SPC, KC_SPC, RE_RSE, KC_DEL, XXXXXXX, KC_APP, XXXXXXX
			       ),

/* Lower 1
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     | HME |  U  | PUP | CAP | PSC |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | GUI | ALT | CTL | SFT | INS |     |  L  |     |  R  |     | APP |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     | DEL |     | END |  D  | PDN |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_PGUP, KC_CAPS, KC_PSCR,
XXXXXXX, OM_LGUI, OM_LALT, OM_LCTL, OM_LSFT, KC_INS, XXXXXXX, KC_LEFT, XXXXXXX, KC_RGHT, XXXXXXX, KC_APP,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, KC_END,  KC_DOWN, KC_PGDN, XXXXXXX, _______,
_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
			      ),

/* Raise 2
 * ,-----------------------------------------------------------------------.
 * |  [  |  &  |  %  |  #  |  (  |  !  |  @  |  )  |  *  |  $  |  ^  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | F09 | F05 | F05 | F03 | F01 | F11 | F12 | F10 | F02 | F04 | F06 | F08 |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
KC_LBRC, KC_AMPR, KC_PERC, KC_HASH, KC_LPRN, KC_EXLM, KC_AT,   KC_RPRN, KC_ASTR, KC_DLR,  KC_CIRC, KC_RBRC,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OM_RSFT, OM_RCTL, OM_RALT, OM_RGUI, _______,
KC_F9,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F11,  KC_F12,  KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
			      ),


/* Adjust (Lower + Raise) 3
 * ,-----------------------------------------------------------------------.
 * | RST |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
KC_9,    KC_7,    KC_5,    KC_3,    KC_1,    XXXXXXX, XXXXXXX, KC_0,    KC_2,    KC_4,    KC_6,    KC_8,
XXXXXXX, OM_LGUI, OM_LALT, OM_LCTL, OM_LSFT, XXXXXXX, XXXXXXX, OM_RSFT, OM_RCTL, OM_RALT, OM_RGUI, _______,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
			       ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}
