#pragma once

enum napoli1084_layers {
#ifdef NAPOLI1084_QWERTY_ENABLE
    LYR_QWERTY, // Default layer on keyboards I share with other people
    LYR_QNAVNUM, // Navigation/numpad layer for qwerty users
#endif
    LYR_WORKNAP, // My main default layer, based on Workman layout
    LYR_GAME, // Game layer
    LYR_NAVNUM, // Navigation (arrows, home/end, page up/down) / numpad layer
    LYR_FRSYMBOL, // French symbols layer
    LYR_FRCAPS, // Capital french symbols layer
#ifdef MOUSEKEY_ENABLE
    LYR_MOUSE, // Mouse layer
#endif
#ifdef NAPOLI1084_QWERTY_ENABLE
    LYR_FN, // Function keys layer
#endif
    LYR_F1F12, // F keys layer
    LYR_WINDOWS // Windows combos layers
};

#define OSQNVNUM OSL(LYR_QNAVNUM)
#define OSFN OSL(LYR_FN)
#define TOQWERT TO(LYR_QWERTY)
#define TTGAME TT(LYR_GAME)
#define TTNVNUM TT(LYR_NAVNUM)
#define TTF1F12 TT(LYR_F1F12)
#define TTWIN TT(LYR_WINDOWS)
#define TTWKNAP TT(LYR_WORKNAP)
#define LTWIN_T LT(LYR_WINDOWS,KC_T)
#define LTF1_N LT(LYR_F1F12,KC_N)

#ifdef MOUSEKEY_ENABLE
#define TTMOUSE TT(LYR_MOUSE)
#else
#define TTMOUSE KC_NO
#endif

// Placeholder for key being held to toggle current layer.
#define HOLDLYR KC_TRANSPARENT

#define CTL_A LCTL(KC_A)
#define CTL_S LCTL(KC_S)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_F LCTL(KC_F)
#define CTL_P LCTL(KC_P)
#define CTL_O LCTL(KC_O)
#define CTL_F7 LCTL(KC_F7)

// Hold for CTL/SFT, tap for char
#define LCTL_Q LCTL_T(KC_Q)
#define LSFT_A LSFT_T(KC_A)
#define LCTL_Z LCTL_T(KC_Z)
#define RCTL_SC RCTL_T(KC_SCOLON)
#define RSFT_I RSFT_T(KC_I)
#define RCTL_SL RCTL_T(KC_SLASH)

#define WINSFTL LGUI(LSFT(KC_LEFT))
#define WINSFTR LGUI(LSFT(KC_RIGHT))
#define WINDOWN LGUI(KC_DOWN)
#define ALT_F4  LALT(KC_F4)
#define WINLEFT LGUI(KC_LEFT)
#define WINUP LGUI(KC_UP)
#define WINRGHT LGUI(KC_RIGHT)
#define WINCTLL LCTL(LGUI(KC_LEFT))
#define WINCTLR LCTL(LGUI(KC_RIGHT))

////////////////////////////////////////////////////////////////////////////////////////////////////
// Tap Dance declarations

#ifdef TAP_DANCE_ENABLE

enum tap_dance_id{
    tap_dance_h_esc,
    tap_dance_ctl_z_ctl_a,
    tap_dance_ctl_s_ctl_x,
    tap_dance_ctl_c_F5,
    tap_dance_F7_ctl_F7,
    tap_dance_ctl_f_F3,
    tap_dance_ctl_p_ctl_o,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for H, twice for Escape
    [tap_dance_h_esc] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_ESC),
    [tap_dance_ctl_z_ctl_a] = ACTION_TAP_DANCE_DOUBLE(CTL_Z, CTL_A),
    [tap_dance_ctl_s_ctl_x] = ACTION_TAP_DANCE_DOUBLE(CTL_S, CTL_X),
    [tap_dance_ctl_c_F5] = ACTION_TAP_DANCE_DOUBLE(CTL_C, KC_F5),
    [tap_dance_F7_ctl_F7] = ACTION_TAP_DANCE_DOUBLE(CTL_F7, KC_F7),
    [tap_dance_ctl_f_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, CTL_F),
    [tap_dance_ctl_p_ctl_o] = ACTION_TAP_DANCE_DOUBLE(CTL_P, CTL_O),
};

#define TD_H_ESC TD(tap_dance_h_esc)
#define TD_CTLZ TD(tap_dance_ctl_z_ctl_a)
#define TD_CTLS TD(tap_dance_ctl_s_ctl_x)
#define TD_CTLC TD(tap_dance_ctl_c_F5)
#define TD_CTLF TD(tap_dance_ctl_f_F3)
#define TD_F7 TD(tap_dance_F7_ctl_F7)
#define TD_CTLP TD(tap_dance_ctl_p_ctl_o)

#endif // #ifdef TAP_DANCE_ENABLE
////////////////////////////////////////////////////////////////////////////////

#ifdef UNICODEMAP_ENABLE

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    uni_a_CIRCUMFLEX,
    uni_a_DIAERESIS,
    uni_a_GRAVE,
    uni_c_CEDILLA,
    uni_e_ACUTE,
    uni_e_CIRCUMFLEX,
    uni_e_DIAERESIS,
    uni_e_GRAVE,
    uni_i_CIRCUMFLEX,
    uni_i_DIAERESIS,
    uni_n_TILDE,
    uni_o_CIRCUMFLEX,
    uni_o_DIAERESIS,
    uni_s_SHARP,
    uni_u_CIRCUMFLEX,
    uni_u_DIAERESIS,
    uni_u_GRAVE,
    uni_y_DIAERESIS,
    uni_A_CIRCUMFLEX,
    uni_A_DIAERESIS,
    uni_A_GRAVE,
    uni_C_CEDILLA,
    uni_E_ACUTE,
    uni_E_CIRCUMFLEX,
    uni_E_DIAERESIS,
    uni_E_GRAVE,
    uni_I_CIRCUMFLEX,
    uni_I_DIAERESIS,
    uni_N_TILDE,
    uni_O_CIRCUMFLEX,
    uni_O_DIAERESIS,
    uni_S_SHARP,
    uni_U_CIRCUMFLEX,
    uni_U_DIAERESIS,
    uni_U_GRAVE,
    uni_Y_DIAERESIS
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [uni_a_CIRCUMFLEX] = 0x00E2, // â
    [uni_a_DIAERESIS] = 0x00E4, // ä
    [uni_a_GRAVE] = 0x00E0, // à
    [uni_c_CEDILLA] = 0x00E7, // ç
    [uni_e_ACUTE] = 0x00E9, // é
    [uni_e_CIRCUMFLEX] = 0x00EA, // ê
    [uni_e_DIAERESIS] = 0x00EB, // ë
    [uni_e_GRAVE] = 0x00E8, // è
    [uni_i_CIRCUMFLEX] = 0x00EE, // î
    [uni_i_DIAERESIS] = 0x00EF, // ï
    [uni_n_TILDE] = 0x00F1, // ñ
    [uni_o_CIRCUMFLEX] = 0x00F4, // ô
    [uni_o_DIAERESIS] = 0x00F6, // ö
    [uni_s_SHARP] = 0x00DF, // ß
    [uni_u_CIRCUMFLEX] = 0x00FB, // û
    [uni_u_DIAERESIS] = 0x00FC, // ü
    [uni_u_GRAVE] = 0x00F9, // ù
    [uni_y_DIAERESIS] = 0x00FF, // ÿ
    [uni_A_CIRCUMFLEX] = 0x00C2, // Â
    [uni_A_DIAERESIS] = 0x00C4, // Ä
    [uni_A_GRAVE] = 0x00C0, // À
    [uni_C_CEDILLA] = 0x00C7, // Ç
    [uni_E_ACUTE] = 0x00C9, // É
    [uni_E_CIRCUMFLEX] = 0x00CA, // Ê
    [uni_E_DIAERESIS] = 0x00CB, // Ë
    [uni_E_GRAVE] = 0x00C8, // È
    [uni_I_CIRCUMFLEX] = 0x00CE, // Î
    [uni_I_DIAERESIS] = 0x00CF, // Ï
    [uni_N_TILDE] = 0x00D1, // Ñ
    [uni_O_CIRCUMFLEX] = 0x00D4, // Ô
    [uni_O_DIAERESIS] = 0x00D6, // Ö
    [uni_S_SHARP] = 0x1E9E, // ẞ
    [uni_U_CIRCUMFLEX] = 0x00DB, // Û
    [uni_U_DIAERESIS] = 0x00DC, // Ü
    [uni_U_GRAVE] = 0x00D9, // Ù
    [uni_Y_DIAERESIS] = 0x0178, // Ÿ
};

#define a_CIRCM XP(uni_a_CIRCUMFLEX, uni_A_CIRCUMFLEX)
#define a_DIAER XP(uni_a_DIAERESIS, uni_A_DIAERESIS)
#define a_GRAVE XP(uni_a_GRAVE, uni_A_GRAVE)
#define c_CEDIL XP(uni_c_CEDILLA, uni_C_CEDILLA)
#define e_ACUTE XP(uni_e_ACUTE, uni_E_ACUTE)
#define e_CIRCM XP(uni_e_CIRCUMFLEX, uni_E_CIRCUMFLEX)
#define e_GRAVE XP(uni_e_GRAVE, uni_E_GRAVE)
#define e_DIAER XP(uni_e_DIAERESIS, uni_E_DIAERESIS)
#define i_CIRCM XP(uni_i_CIRCUMFLEX, uni_I_CIRCUMFLEX)
#define i_DIAER XP(uni_i_DIAERESIS, uni_I_DIAERESIS)
#define n_TILDE XP(uni_n_TILDE, uni_N_TILDE)
#define o_CIRCM XP(uni_o_CIRCUMFLEX, uni_O_CIRCUMFLEX)
#define o_DIAER XP(uni_o_DIAERESIS, uni_O_DIAERESIS)
#define s_SHARP XP(uni_s_SHARP, uni_S_SHARP)
#define u_CIRCM XP(uni_u_CIRCUMFLEX, uni_U_CIRCUMFLEX)
#define u_DIAER XP(uni_u_DIAERESIS, uni_U_DIAERESIS)
#define u_GRAVE XP(uni_u_GRAVE, uni_U_GRAVE)
#define y_DIAER XP(uni_y_DIAERESIS, uni_Y_DIAERESIS)

#define A_CIRCM X(uni_A_CIRCUMFLEX)
#define A_DIAER X(uni_A_DIAERESIS)
#define A_GRAVE X(uni_A_GRAVE)
#define C_CEDIL X(uni_C_CEDILLA)
#define E_ACUTE X(uni_E_ACUTE)
#define E_CIRCM X(uni_E_CIRCUMFLEX)
#define E_GRAVE X(uni_E_GRAVE)
#define E_DIAER X(uni_E_DIAERESIS)
#define I_CIRCM X(uni_I_CIRCUMFLEX)
#define I_DIAER X(uni_I_DIAERESIS)
#define N_TILDE X(uni_N_TILDE)
#define O_CIRCM X(uni_O_CIRCUMFLEX)
#define O_DIAER X(uni_O_DIAERESIS)
#define S_SHARP X(uni_S_SHARP)
#define U_CIRCM X(uni_U_CIRCUMFLEX)
#define U_DIAER X(uni_U_DIAERESIS)
#define U_GRAVE X(uni_U_GRAVE)
#define Y_DIAER X(uni_Y_DIAERESIS)

#endif // #ifdef UNICODEMAP_ENABLE

////////////////////////////////////////////////////////////////////////////////
