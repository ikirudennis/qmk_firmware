#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _ARROW 12
#define _NUMPAD 13
#define _LOWER 14
#define _RAISE 15
#define _ADJUST 16

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define ARROW M(_ARROW)
#define NUMPAD M(_NUMPAD)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define M_CAPS 5
#define M_SHRUG 6
#define M_ESHRUG 7

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    | Raise|   -  |  =   |  [   |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC},
  {KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLASH},
  {LT(_RAISE, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,                KC_G,    KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT},
  {KC_RSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT },
  {KC_LSFT,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(_LOWER, KC_SPC),  KC_SPC,  RAISE,   MT(MOD_LGUI, KC_MINUS), MT(MOD_LALT, KC_EQUAL), MT(MOD_LCTL, KC_LBRC),  MT(MOD_LSFT, KC_RBRC)}
},
/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   /  |   *  |   -  |   4  |   5  |   6  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   7  |   8  |   9  |   +  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   4  |   5  |   6  |   +  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  | Enter|   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   0  |   0  |  .   | Enter| Lower|    Space    | Raise|   -  |  =   |   [  |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {KC_ESC, KC_PSLS, KC_PAST, KC_PMNS,  _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_P7,  KC_P8,   KC_P9,   KC_PPLS,  _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_P4,  KC_P5,   KC_P6,   KC_PPLS,  _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_P1,  KC_P2,   KC_P3,   KC_PENT,  _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_P0,  KC_P0,   KC_PDOT, KC_PENT,  _______, _______, _______, _______, _______, _______, _______, _______},
},
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | BkSpc|   Up |  Del | Forwd| MBtn1| MUp  | MBtn2|   /  |   7  |   8  |  9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right| Refr | MLeft| MDn  |MRight|   *  |   4  |   5  |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ | Prev | Play | Next | Back | MWDn | MBtn3| MWUp |   -  |   1  |   2  |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |      |      |      |      |      |      |      |   +  | Enter|   0  |  .   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F1,    KC_F2,   KC_F3,    KC_F4,          KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_DEL},
  {KC_MUTE, KC_BSPC,  KC_UP,   KC_DEL,   KC_WWW_FORWARD, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSLS,  KC_P7,   KC_P8,  KC_P9},
  {_______, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_WWW_REFRESH, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAST,  KC_P4,   KC_P5,  KC_P6},
  {KC_VOLU, KC_MPRV,  KC_MPLY, KC_MNXT,  KC_WWW_BACK,    KC_WH_D, KC_BTN3, KC_WH_U, KC_PMNS,  KC_P1,   KC_P2,  KC_P3},
  {KC_VOLD, _______,  _______, _______,  _______,        _______, _______, _______, KC_PPLS,  KC_PENT, KC_P0,  KC_PDOT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Bksp | PgUp |  Del |eShrug|  sf  | Home | PgUp | PgDn | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Home | PgDn |  End | Shrug|  sh  | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Pause| Ins  |      |      | Print|Screen|      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,  KC_NUMLOCK},
  {_______, KC_BSPC, KC_PGUP, KC_DEL,  M(M_ESHRUG), KC_SHRUG_FACE, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,  _______},
  {M(M_CAPS), KC_HOME, KC_PGDN, KC_END,  M(M_SHRUG), KC_SHRUG_HAND, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,  _______},
  {_______, KC_PAUSE, KC_INS, _______, _______, KC_PSCR, KC_PSCR, _______, _______, _______,  _______,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |AGNorm|AGSwap|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud On|AudOff|MidiOn|MdiOff| Eject|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus On|MusOff| Sleep| Wake | Arrow|QWERTY|NUMPAD|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Reset   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  MI_ON,   MI_OFF,  KC_EJCT, BL_STEP,    _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, ARROW,   QWERTY,  NUMPAD,  _______, _______},
  {_______, _______, _______, _______, _______, RESET,   RESET,   _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE
float start_up[][2] = {
  {440.0*pow(2.0,(14)/12.0), 20},
  {440.0*pow(2.0,(26)/12.0), 8},
  {440.0*pow(2.0,(18)/12.0), 20},
  {440.0*pow(2.0,(26)/12.0), 8}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);

float goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          break;
        case _NUMPAD:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_NUMPAD);
          }
          break;
        case _ARROW:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL<<_LOWER);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case M_CAPS:
          if (record->event.pressed) {
            register_code(KC_CAPS);
            backlight_level(BACKLIGHT_LEVELS);
            breathing_toggle();
          } else {
            unregister_code(KC_CAPS);
          }
          break;
        case M_SHRUG:
          if (record->event.pressed) {
            return MACRO(I(10), D(LALT), T(0), T(0), T(A), T(F), U(LALT), T(BSLASH), D(LSHIFT), T(MINUS), T(9), U(LSHIFT), D(LALT), T(3), T(0), T(C), T(4), U(LALT), D(LSHIFT), T(0), T(MINUS), U(LSHIFT), T(SLASH), D(LALT), T(0), T(0), T(A), T(F), U(LALT), END);
          }
          break;
        case M_ESHRUG:
          if (record->event.pressed) {
            return MACRO(I(10), D(LSHIFT), T(7), U(LSHIFT), T(S), T(H), T(R), T(U), T(G), T(SCLN), END);
          }
          break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(start_up, false, 0);
  #endif
}

#ifdef AUDIO_ENABLE

void play_goodbye_tone()
{
  PLAY_NOTE_ARRAY(goodbye, false, 0);
  _delay_ms(150);
}

#endif
