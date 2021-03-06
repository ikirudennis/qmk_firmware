#include QMK_KEYBOARD_H
#include "muse.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum preonic_layers {
  _QWERTY,
  _ARROW,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Macro name shortcuts
enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  ARROW,
  NUMPAD,
  LOWER,
  RAISE
};

enum macros {
  M_CAPS,
  M_SHRUG,
  M_ESHRUG
};

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
[_QWERTY] = LAYOUT_preonic_grid ( \
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC, \
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLASH, \
  LT(_RAISE, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,                KC_G,    KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT, \
  KC_RSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT, \
  KC_LSFT,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(_LOWER, KC_SPC),  LT(_RAISE, KC_SPC),  RAISE,   MT(MOD_LGUI, KC_MINUS), MT(MOD_LALT, KC_EQUAL), MT(MOD_LCTL, KC_LBRC),  MT(MOD_LSFT, KC_RBRC) \
),
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
[_NUMPAD] = LAYOUT_preonic_grid ( \
  KC_ESC, KC_PSLS, KC_PAST, KC_PMNS,  _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_P7,  KC_P8,   KC_P9,   KC_PPLS,  _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_P4,  KC_P5,   KC_P6,   KC_PPLS,  _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_P1,  KC_P2,   KC_P3,   KC_PENT,  _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_P0,  KC_P0,   KC_PDOT, KC_PENT,  _______, _______, _______, _______, _______, _______, _______, _______ \
),
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
[_LOWER] =  LAYOUT_preonic_grid (
  KC_ESC,  KC_F1,    KC_F2,   KC_F3,    KC_F4,          KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_DEL, \
  KC_MUTE, KC_BSPC,  KC_UP,   KC_DEL,   KC_WWW_FORWARD, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSLS,  KC_P7,   KC_P8,  KC_P9, \
  _______, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_WWW_REFRESH, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAST,  KC_P4,   KC_P5,  KC_P6, \
  KC_VOLU, KC_MPRV,  KC_MPLY, KC_MNXT,  KC_WWW_BACK,    KC_WH_D, KC_BTN3, KC_WH_U, KC_PMNS,  KC_P1,   KC_P2,  KC_P3, \
  KC_VOLD, _______,  _______, _______,  _______,        _______, _______, _______, KC_PPLS,  KC_PENT, KC_P0,  KC_PDOT \
),

/* Raise
 * ,---------------------------------------------------------------------------------------.
 * | Esc  | F11  | F12  |  F13 |  F14 | F15  | F16  | F17  | F18  | F19  |  F20 | NUMLOCK  |
 * |------+------+------+------+------+------+------+------+------+------+------+----------|
 * |      | Bksp | PgUp |  Del |eShrug|  sf  | Home | PgUp | PgDn | End  |      | SCRLOCK  |
 * |------+------+------+------+------+------+------+------+------+------+------+----------|
 * |      | Home | PgDn |  End | Shrug|  sh  | Left | Down |  Up  | Right|      |          |
 * |------+------+------+------+------+------+------+------+------+------+------+----------|
 * |      | Pause| Ins  |   -  |   =  | Print|Screen|      |      |      |      | Enter    |
 * |------+------+------+------+------+------+------+------+------+------+------+----------|
 * |      |      |      |      |      |             |      |      |      |      |          |
 * `---------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid ( \
  KC_ESC,  KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NUMLOCK, \
  M(M_CAPS), KC_BSPC, KC_PGUP, KC_DEL,  M(M_ESHRUG), _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,  KC_SCROLLLOCK, \
  _______, KC_HOME, KC_PGDN, KC_END,  M(M_SHRUG), _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,  _______, \
  _______, KC_PAUSE, KC_INS, KC_MINUS, KC_EQUAL, KC_PSCR, KC_PSCR, KC_GRV, _______, _______,  _______,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______ \
),

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
[_ADJUST] = LAYOUT_preonic_grid ( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, LCTL(LSFT(KC_EJCT)), _______, _______, _______, _______, \
  _______, _______,  MU_MOD, AU_ON,   AU_OFF,  MI_ON,   MI_OFF,  KC_EJCT, BL_STEP, BL_BRTG, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, ARROW,   QWERTY,  NUMPAD,  _______, _______, \
  _______, _______, _______, _______, _______, RESET,   RESET,   _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(STARTUP_SOUND);

float tone_qwerty[][2] = SONG(QWERTY_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float tone_music_on[][2] = SONG(MUSIC_ON_SOUND);
float tone_arrow[][2] = SONG(ONE_UP_SOUND);
float tone_caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif

/*void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case NUMPAD:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_goodbye);
            #endif
            set_single_persistent_default_layer(_NUMPAD);
          }
          return false;
          break;
        case ARROW:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_arrow);
            #endif
            set_single_persistent_default_layer(_LOWER);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

/*void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}*/

#ifdef AUDIO_ENABLE

void startup_user()
{
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    stop_all_notes();
}

void music_on_user(void)
{
    PLAY_SONG(tone_music_on);
}

void play_goodbye_tone(void)
{
  PLAY_SONG(tone_goodbye);
}

#endif

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case M_CAPS:
      if (record->event.pressed) {
        register_code(KC_CAPS);
        PLAY_SONG(tone_caps_on);
      } else {
        unregister_code(KC_CAPS);
        PLAY_SONG(tone_caps_off);
      }
      return false;
      break;
    case M_SHRUG:
      if (record->event.pressed) {
        return MACRO(I(10), D(LALT), T(0), T(0), T(A), T(F), U(LALT), T(BSLASH), D(LSHIFT), T(MINUS), T(9), U(LSHIFT), D(LALT), T(3), T(0), T(C), T(4), U(LALT), D(LSHIFT), T(0), T(MINUS), U(LSHIFT), T(SLASH), D(LALT), T(0), T(0), T(A), T(F), U(LALT), END);
      }
      return false;
      break;
    case M_ESHRUG:
      if (record->event.pressed) {
        return MACRO(I(10), D(LSHIFT), T(7), U(LSHIFT), T(S), T(H), T(R), T(U), T(G), T(SCLN), END);
      }
      return false;
      break;
  }
  return MACRO_NONE;
};
