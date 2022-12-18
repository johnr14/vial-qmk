/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H


/*
 * L_BASE : Linux or layer 0 base layer

 * N_FN : Calculator layer, toogle from KC_APP | KC_SLASH                             [  ]
 * D1_FN : Dynamic layer #1 for vial configuration                                      [  ]
 * D2_FN : Dynamic layer #1 for vial configuration                                      [  ]
 * D3_FN : Dynamic layer #1 for vial configuration                                      [  ]
 * K_FN : KDE shortcuts                                                                 [  ]
 * M_FN : Multimedia layer                                                              [  ]
 * NAV_FN : Navigation layer, and numpad enable layer from KC_APP | KC_ENTER or momentary KC_CAPS  [  ]
 * DMAC_FN : Dynamic macro record play layer, toogle from KC_APP | KC_MENU              [  ]
 * T_FN : Top FN layer when fn key is pressed                                           [  ]
 * S_FN : Super layer momentary FN from KC_APP | KC_RIGHT_CTRL                          [  ]
 *
 * TODO:
 * K_FN
 * Dynamic macro keys
 * I_FN : Vim mode
 * KC_CAPS toogle N_FN layer
 * RGB backlight of layers
 */


//#define IGNORE_MOD_TAP_INTERRUPT

// Special keys
//

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define FN_CAPS LT(N_FN, KC_CAPS) // Momentary nav layer on hold

/*
// For override to be able to assign key quickly
#define FN_DM_REC1 KC_INS
#define FN_DM_REC2 KC_PGUP
#define FN_DM_PLY1 KC_PSCR
#define FN_DM_PLY2 KC_PGDN
#define FN_DM_RSTP KC_MENU
*/


/*
 * Layers enum
 */

enum layers{
  L_BASE,
  N_FN,
  D2_FN,
  S_FN
};



/*
 * KEY OVERRIDES
 */

// This is called when the override activates and deactivates. Enable the S_FN layer on activation and disable on deactivation
// https://docs.qmk.fm/#/feature_key_overrides

/*
bool momentary_layer(bool key_down, void *layer) {
    if (key_down) {
        layer_on((uint8_t)(uintptr_t)layer);
    } else {
        layer_off((uint8_t)(uintptr_t)layer);
    }

    return false;
}

const key_override_t fn_override = {.trigger_mods          = MOD_BIT(KC_RALT) | MOD_BIT(KC_APP) | MOD_BIT(KC_RCTL),     //
                                   .layers                 = ~(1 << S_FN),                                          //
                                   .suppressed_mods        = MOD_BIT(KC_RALT) | MOD_BIT(KC_RCTL),                       //
                                   .options                = ko_option_no_unregister_on_other_key_down,                 //
                                   .negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_RALT) | MOD_BIT(KC_RCTL)),          //
                                   .custom_action          = momentary_layer,                                           //
                                   .context                = (void *)S_FN,                                          //
                                   .trigger                = KC_NO,                                                     //
                                   .replacement            = KC_NO,                                                     //
                                   .enabled                = NULL};
*/


/*
 * LAYER STATE CHANGE
 */

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case NUM_FN:
        // Num FN disable other layers and sets RGB when enables
        layer_clear();
        layer_on(L_BASE);
        layer_on(NUM_FN);
        // TODO: RGB LIGHT
        break;

    default: //  for any other layers, or the default layer
        //rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }

    if(IS_LAYER_OFF(NUM_FN)) {
    layer_off(NUM_FN); // do nothing
    // TODO RGB LIGHT OFF
    }

  return state;
}

*/

/* ORI
[ORI_BASE] = LAYOUT_ansi_82(
     KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(M_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT_ansi_82(
     KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_MENU,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_INS,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
     FN_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(D2_FN), KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

[N_FN] = LAYOUT_ansi_82(
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_0,     KC_PMNS,  KC_PEQL,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_5,     KC_6,     KC_7,     KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_0,     KC_PCMM,  KC_PSLS,            KC_TRNS,  KC_PGUP,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END),

[D2_FN] = LAYOUT_ansi_82(
     KC_TRNS,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG(N_FN),           KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  MO(S_FN), KC_TRNS,  KC_TRNS,  KC_TRNS),

[S_FN] = LAYOUT_ansi_82(
     KC_PWR,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SYRQ,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_WAKE,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_SLEP,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};

/* Blank layer
 *
[BLANK_LAY] = LAYOUT_ansi_82(
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
 *
 *
 [T_FN] = LAYOUT_ansi_82(
     KC_TRNS,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  TG(DMAC_FN),
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG(NUM_FN),         KC_TRNS,   KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  TG(S_FN), KC_TRNS,   KC_TRNS,  KC_TRNS),

 */

/*
 * Special logic for intercepting keys
 */

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    static bool delkey_registered;
    static bool backspacekey_registered;

    switch (keycode) {

        // SHIFT + BACKSPACE = DEL
        // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
        case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        //static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }

        case KC_SPACE:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?

        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_BSPC);
                // Update the boolean variable to reflect the status of KC_DEL
                backspacekey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
                }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (backspacekey_registered) {
                unregister_code(KC_BSPC);
                backspacekey_registered = false;
                return false;
                }
            }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }
/*
        case FN_DM_REC1:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        //static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_CRTL) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_CTRL);
                register_code(DM_REC1);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(DM_REC1);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }*/


        // X C V
        //https://docs.qmk.fm/#/mod_tap
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode

    }
    return true;
}

/*
 * RGB   !
 */

//INDICATOR LEDS

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // lIGHT UP KC_SPACE
    RGB_MATRIX_INDICATOR_SET_COLOR(75, 0, 255, 255);

    // Per layer key illumination
    /*
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];


                if(layer == S_FN) {
                    if (index >= led_min && index <= led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                        rgb_matrix_set_color(index, 0, 255, 255);
                    }
                }
            }
        }
    }
    */

    if (layer_state_is(S_FN)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 0, 0); // KC_ESC
        RGB_MATRIX_INDICATOR_SET_COLOR(13, 255, 0, 0); // KC_PSCR
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 0 ,0); // KC_PGUP
        RGB_MATRIX_INDICATOR_SET_COLOR(58, 255, 0 ,0); // KC_PGDN
        RGB_MATRIX_INDICATOR_SET_COLOR(77, 255, 0 ,0); // KC_APP
        RGB_MATRIX_INDICATOR_SET_COLOR(78, 255, 0 ,0); // KC_RIGHT_CTRL

    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0); // KC_ESC
        RGB_MATRIX_INDICATOR_SET_COLOR(13, 0, 0, 0); // KC_PSCR
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 0, 0, 0); // KC_PGUP
        RGB_MATRIX_INDICATOR_SET_COLOR(58, 0, 0, 0); // KC_PGDN
        RGB_MATRIX_INDICATOR_SET_COLOR(77, 0, 0, 0); // KC_APP
        RGB_MATRIX_INDICATOR_SET_COLOR(78, 0, 0, 0); // KC_RIGHT_CTRL
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(45, 255, 255, 255); // assuming caps lock is at led #5
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(45, 0, 0, 0);
    }
}
