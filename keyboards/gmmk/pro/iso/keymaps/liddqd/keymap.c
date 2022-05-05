/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        MO(_FN1),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______,                   _______,
        _______, _______, RGB_VAD, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______, _______,          _______,
        _______, _______, _______, RGB_HUI, _______, _______, RESET,   NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


};
/*
    LED LAYOUT (total 98 addr LED)(
        ___0___, ___6___, __12___, __18___, __23___, __28___, __34___, __39___, __44___, __50___, __56___, __61___, __66___, __70___,          SRLKNOB,
        ___1___, ___7___, __13___, __19___, __24___, __29___, __35___, __40___, __45___, __51___, __57___, __62___, __79___, __86___           __73___,
        ___2___, ___8___, __14___, __20___, __25___, __30___, __36___, __41___, __46___  __52___, __58___, __63___, __90___,                   __76___,
        ___3___, ___9___, __15___, __21___, __26___, __31___, __37___, __42___, __47___, __53___, __59___, __64___, __95___, __97___,          __87___,
        ___4___, __67___, __10___, __16___, __22___, __27___, __32___  __38___, __43___, __48___, __54___, __60___,          __91___, __94___, __83___,
        ___5___, __11___, __17___,                            __33___,                            __49___, __55___, __65___, __96___, __98___, __80___
    ),

    LEFT SIDE LED        RIGHT SIDE LED
        __68___,           __69___,
        __71___,           __72___,
        __74___,           __75___,
        __77___,           __78___,
        __81___,           __82___,
        __84___,           __85___,
        __88___,           __89___,
        __92___,           __93___,

     Been verfied by tedious work late at night, dont expect there to be no mistakes. Done on ISO version. ANSI is probably slightly different layout.

*/

// clang-format on
int RGB_FKEYS[] = {6, 12, 18, 23, 28, 34, 39, 44, 50, 56, 61, 66};
int RGB_ALPHAS[] = {8, 14, 20, 25, 30, 36, 51, 46, 52, 58, 63, 
                    9, 15, 21, 26, 31, 37, 42, 47, 53, 59, 64,
                    10, 16, 22, 27, 32, 38, 43};
int RGB_MISC[] = {1, 67, 48, 54, 60, 62, 79, 90, 95};
int RGB_EDIT[] = {2, 3, 33, 86, 97};
int RGB_NUMERICS[] = {7, 13, 19, 24, 29, 35, 40, 45, 51, 57};
int RGB_MODIFIERS[] = {4, 5, 11, 17, 49, 55, 65, 91};
int RGB_NAVIGATION[] = {0, 94, 96, 98, 80};
int RGB_CONTEXTUAL[] = {70, 73, 76, 87, 83};
int RGB_SIDES_LEFT[] = {68, 71, 74, 77, 81, 84, 88, 92};
int RGB_SIDES_RIGHT[] = {69, 72, 75, 78, 82, 85, 89, 93};
int RGB_LAYER_1[] = {
        6,  //KC_F1
        12, //KC_F2
        18, //KC_F3
        23, //KC_F4
        28, //KC_F5
        34, //KC_F6
        39, //KC_F7
        44, //KC_F8
        50, //KC_F9
        56, //KC_F10
        61, //KC_F11
        7,  //KC_1
        86, //KC_BSPC
        14, //KC_W
        15, //KC_S
        16, //KC_X
        37, //KC_H
        42, //KC_J
        47, //KC_K
        53, //KC_Li
	59, //KC_SCLN
        46, //KC_I
        41, //KC_U /KC_PGUP
        52, //KC_O /KC_PGDN
        94, //KC_UP
        96, //KC_LEFT
        98, //KC_DOWN
        80, //KC_RGHT
        32 //KC_B
};

// Loop for setting groups of LED's each cycle function
void rgb_matrix_set_group(int *index, int array_size, uint8_t red, uint8_t green, uint8_t blue) {
	for (uint8_t i = 0; i < array_size; i++){
		rgb_matrix_set_color(index[i], red, green, blue);
	}
}

void rgb_matrix_indicators_kb(void) {
	// letter keys change on CAPS Lock ALL leds except rgb_side
	if (host_keyboard_led_state().caps_lock) {
		rgb_matrix_set_group(RGB_MODIFIERS, (&RGB_MODIFIERS)[1] - RGB_MODIFIERS, 255, 0, 0);
		rgb_matrix_set_group(RGB_NAVIGATION, (&RGB_NAVIGATION)[1] - RGB_NAVIGATION, 255, 0, 0);
		rgb_matrix_set_group(RGB_CONTEXTUAL, (&RGB_CONTEXTUAL)[1] - RGB_CONTEXTUAL, 255, 0, 0);
		rgb_matrix_set_group(RGB_EDIT, (&RGB_EDIT)[1] - RGB_EDIT, 255, 0, 0);
		rgb_matrix_set_group(RGB_SIDES_LEFT, (&RGB_SIDES_LEFT)[1] - RGB_SIDES_LEFT, 255, 0, 0);
		rgb_matrix_set_group(RGB_SIDES_RIGHT, (&RGB_SIDES_RIGHT)[1] - RGB_SIDES_RIGHT, 255, 0, 0);
	}
	if (layer_state_is(1)) {
		rgb_matrix_set_group(RGB_ALPHAS, (&RGB_ALPHAS)[1] - RGB_ALPHAS, 0, 0, 0);
		rgb_matrix_set_group(RGB_NUMERICS, (&RGB_NUMERICS)[1] - RGB_NUMERICS, 0, 0, 0);
		rgb_matrix_set_group(RGB_MISC, (&RGB_MISC)[1] - RGB_MISC, 0, 0, 0);
		rgb_matrix_set_group(RGB_LAYER_1, (&RGB_LAYER_1)[1] - RGB_LAYER_1, 0, 255, 255);
		rgb_matrix_set_color(32, RGB_RED);
	}
}
// set RGB indicators
/*void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    if  (layer_state_is(1)) {
        //rgb_matrix_set_color_all(RGB_OFF); //side led off

        //keep side led
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
        }
        rgb_matrix_set_color(32, RGB_RED);      //KC_B
    }
} */

// rgb red when RESET
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RESET:  // when activating RESET mode for flashing
            if (record->event.pressed) {
                rgb_matrix_set_color_all(255, 0, 0);
                rgb_matrix_driver.flush();
            }
            return true;
    }
    return true; // Process all other keycodes normally
}

/*
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    if (mods_state & MOD_BIT(KC_RSFT) ) { // If you are holding L shift,
       
       if (clockwise) {
           tap_code(KC_J);
       } else {
           tap_code(KC_K);
       }
    /*} else if (mods_state & MOD_BIT(KC_RSFT) ) { // If you are holding R shift,
       if (clockwise) {
           tap_code(KC_C);
       } else {
           tap_code(KC_D);
       }
    } else if (mods_state & MOD_BIT(KC_LCTL)) {  // if holding Left Ctrl,
       if (clockwise) {
           tap_code(KC_E);
       } else {
           tap_code(KC_F);
       }
    } else if (mods_state & MOD_BIT(KC_RCTL)) {  // if holding Right Ctrl,
       if (clockwise) {
           tap_code(KC_G);
       } else {
           tap_code(KC_H);
       }
    } else if (mods_state & MOD_BIT(KC_LALT)) {  // if holding Left Alt,
       if (clockwise) {
           tap_code(KC_I);
       } else {
           tap_code(KC_J);
       }
       */ 
    } else  {
        switch(get_highest_layer(layer_state)) {
            case _FN1:
                if (clockwise) {
                    tap_code(KC_PGDN);
              } else {
                    tap_code(KC_PGUP);
              }
            break;
            default:
               if (clockwise) {
                       tap_code(KC_VOLU);
                } else {
                        tap_code(KC_VOLD);
                }
        }
    }
    return true;
}
