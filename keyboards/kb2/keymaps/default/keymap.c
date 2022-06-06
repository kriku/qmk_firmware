#include "kb2.h"


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished_lbrc(qk_tap_dance_state_t *state, void *user_data);
void x_reset_lbrc(qk_tap_dance_state_t *state, void *user_data);
void x_finished_rbrc(qk_tap_dance_state_t *state, void *user_data);
void x_reset_rbrc(qk_tap_dance_state_t *state, void *user_data);
void x_finished_more(qk_tap_dance_state_t *state, void *user_data);
void x_reset_more(qk_tap_dance_state_t *state, void *user_data);

enum {
	TD_DF_2,
	TD_Q_CAPS,
	TD_A_TAB,
	TD_KC_SCLN_ENT,
	TD_I_ESC,
	TD_J_ESC,
	TD_Z_GRV,
	TD_VOLD_MUTE,
	TD_BRC,
	TD_WS,
	TD_ALT_LBRC,
	TD_GUI_RBRC,
	TD_CTL_MORE,
	TD_KC_PDOT_DL,
	TD_PERC_DL,
	TD_1,
	TD_2,
	TD_3,
	TD_4,
	TD_5,
	TD_6,
	TD_7,
	TD_8,
	TD_9,
	TD_0,
	TD_GUI_1,
	TD_GUI_2,
	TD_GUI_3,
	TD_GUI_4,
	TD_GUI_5,
	TD_GUI_6,
	TD_GUI_7,
	TD_GUI_8,
	TD_GUI_9,
	TD_GUI_0,
	TD_P_ESC,
	TD_P_RALT,
};

enum custom_keycodes {
    ALT_TAB,
};

#define LTTAB LT(1, KC_TAB)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_CAPS),
    [TD_I_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_ESC),
    [TD_J_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_ESC),
    [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
    [TD_KC_SCLN_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
    [TD_Z_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_GRAVE),
    [TD_VOLD_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), LSFT(KC_0)),
    [TD_WS] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_LEFT), LCTL(KC_RIGHT)),
    [TD_ALT_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished_lbrc, x_reset_lbrc),
    [TD_GUI_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished_rbrc, x_reset_rbrc),
    [TD_CTL_MORE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished_more, x_reset_more),
    [TD_KC_PDOT_DL] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PDOT, 0),
    [TD_PERC_DL] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_5), KC_MUTE),
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_GUI_1] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_1), LSFT(LALT(KC_1))),
    [TD_GUI_2] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_2), LSFT(LALT(KC_2))),
    [TD_GUI_3] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_3), LSFT(LALT(KC_3))),
    [TD_GUI_4] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_4), LSFT(LALT(KC_4))),
    [TD_GUI_5] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_5), LSFT(LALT(KC_5))),
    [TD_GUI_6] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_6), LSFT(LALT(KC_6))),
    [TD_GUI_7] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_7), LSFT(LALT(KC_7))),
    [TD_GUI_8] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_8), LSFT(LALT(KC_8))),
    [TD_GUI_9] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_9), LSFT(LALT(KC_9))),
    [TD_GUI_0] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_0), LSFT(LALT(KC_0))),
    [TD_P_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_ESC),
    [TD_P_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_RALT),
    [TD_DF_2] = ACTION_TAP_DANCE_DOUBLE(DF(2), DF(0)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		TD(TD_Q_CAPS), KC_W, KC_E, KC_R, KC_T,
        /*  */ KC_Y, KC_U, KC_I, KC_O, KC_P,

		KC_A, KC_S, KC_D, KC_F, KC_G,
        /*  */ KC_H, TD(TD_J_ESC), KC_K, KC_L, KC_SCLN,

		TD(TD_Z_GRV), CTL_T(KC_X), GUI_T(KC_C), ALT_T(KC_V), KC_B,
        /*  */ KC_N, ALT_T(KC_M), GUI_T(KC_COMM), CTL_T(KC_DOT), KC_SLSH,

        /*  */
		LTTAB,  SFT_T(KC_SPACE),
        /*  */
        SFT_T(KC_ENT), LT(2, KC_BSPC)),

    LAYOUT(

           LSFT(KC_INS),	TD(TD_GUI_7), TD(TD_GUI_8), TD(TD_GUI_9),  LSFT(KC_LBRC),//TD(TD_BRC),
           /*  */
           KC_LBRC,	KC_7, KC_8, KC_9, KC_ESC,

           KC_RALT,	TD(TD_GUI_4), TD(TD_GUI_5), TD(TD_GUI_6), LSFT(KC_RBRC),
           /*  */
           KC_QUOT,	KC_4, KC_5, KC_6, KC_0, // LGUI(KC_ENT),

           LGUI(KC_GRV),	TD(TD_GUI_1), TD(TD_GUI_2), TD(TD_GUI_3),  TD(TD_GUI_0),
           /*  */
           KC_RBRC,	KC_1, KC_2, KC_3, KC_0,

        /* LSFT(KC_INS),	TD(TD_GUI_7), TD(TD_GUI_8), TD(TD_GUI_9),  LSFT(KC_LBRC),//TD(TD_BRC), */
        /* /\*  *\/ */
        /* KC_LBRC,	TD(TD_7),   	    TD(TD_8), TD(TD_9), KC_ESC, */

        /* ALT_TAB,	TD(TD_GUI_4), TD(TD_GUI_5), TD(TD_GUI_6), LSFT(KC_RBRC), */
        /* /\*  *\/ */
        /*    KC_QUOT,	TD(TD_4),	    TD(TD_5), TD(TD_6), TD(TD_0), // LGUI(KC_ENT), */

		/* LGUI(KC_GRV),	TD(TD_GUI_1), TD(TD_GUI_2), TD(TD_GUI_3),  TD(TD_GUI_0), */
        /* /\*  *\/ */
        /* KC_RBRC,	TD(TD_1), 	    TD(TD_2), TD(TD_3), TD(TD_0), */

		KC_TRNS,   KC_TRNS,
        /*  */
        SFT_T(KC_ENT), KC_TRNS),

	LAYOUT(
		KC_MINS,   KC_EQL,	   LSFT(KC_MINS),  LSFT(KC_EQL),   TD(TD_WS),
        /*  */
        DF(2),             KC_VOLU,	   KC_UP,	KC_VOLD,   KC_ESC,

        LSFT(KC_W), TD(TD_CTL_MORE), LSFT(KC_9), LSFT(KC_0), LSFT(KC_RBRC),
        /*  */
        KC_QUOT, KC_LEFT, KC_DOWN,	KC_RGHT,   KC_RALT,

        LSFT(KC_4), LSFT(KC_1), LSFT(KC_7), KC_BSLS, LSFT(KC_8),
        /*  */
        KC_RBRC,           KC_LBRC,	   LSFT(KC_3),	LSFT(KC_2), TD(TD_PERC_DL),

        DF(0),	KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT(
		KC_0, KC_7, KC_8, KC_9, KC_QUOT, KC_PMNS, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_0, KC_4, KC_5, KC_6, KC_RBRC, KC_PPLS, KC_F4, KC_F5, KC_F6, KC_F11,
		KC_PDOT, KC_1, KC_2, KC_3, KC_LBRC, KC_PAST, KC_F1, KC_F2, KC_F3, KC_F12,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

static bool intab = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool res = true;
    switch (keycode) {
    case LTTAB:
        if (!record->event.pressed && intab) {
		unregister_code(KC_LGUI);
		intab = false;
	}
	break;
    case KC_A:
	if(!intab) {
		return true;
	} else {
        	if (record->event.pressed) {
			register_code(KC_TAB);
		} else {
			unregister_code(KC_TAB);
		}
		return false;
	}
   case TD(TD_A_TAB):
	if(!intab) {
		return true;
	}
	res = false;
    case ALT_TAB:
        if (record->event.pressed) {
		if(!intab) {
			intab = true;
			layer_clear();
			register_code(KC_LGUI);
			register_code(KC_TAB);
			return false;
		} else {
			register_code(KC_TAB);
		}
        } else {
            // when keycode QMKBEST is released
		unregister_code(KC_TAB);
        }
        break;
    }
    return res;
};

void matrix_init_user (void) {
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (/*state->interrupted ||*/ !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count > 1) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    }

    return TD_UNKNOWN;
}

static td_tap_t xtap_state_lbrc = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished_lbrc(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state_lbrc.state = cur_dance(state);
    switch (xtap_state_lbrc.state) {
        case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); break;
	case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_LSFT); tap_code(KC_9); register_code(KC_9);
    }
}

void x_reset_lbrc(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state_lbrc.state) {
        case TD_SINGLE_TAP: unregister_code(KC_9); unregister_code(KC_LSFT); break;
        case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_9); unregister_code(KC_LSFT);
    }
    xtap_state_lbrc.state = TD_NONE;
}


static td_tap_t xtap_state_rbrc = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished_rbrc(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state_rbrc.state = cur_dance(state);
    switch (xtap_state_rbrc.state) {
        case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_0); break;
        case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: register_code(KC_LGUI); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_LSFT); tap_code(KC_0); register_code(KC_0);
    }
}

void x_reset_rbrc(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state_rbrc.state) {
        case TD_SINGLE_TAP: unregister_code(KC_0); unregister_code(KC_LSFT); break;
        case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_0); unregister_code(KC_LSFT);
    }
    xtap_state_rbrc.state = TD_NONE;
}


    // CTL_T(LSFT(KC_E))
static td_tap_t xtap_state_more = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished_more(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state_more.state = cur_dance(state);
    switch (xtap_state_more.state) {
        case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_E); break;
        case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: register_code(KC_LCTL); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_LSFT); tap_code(KC_E); register_code(KC_E);
    }
}

void x_reset_more(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state_more.state) {
        case TD_SINGLE_TAP: unregister_code(KC_E); unregister_code(KC_LSFT); break;
        case TD_SINGLE_HOLD: case TD_NONE: case TD_UNKNOWN: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_E); unregister_code(KC_LSFT);
    }
    xtap_state_more.state = TD_NONE;
}
