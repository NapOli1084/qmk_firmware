#pragma once

#include "napoli1084_keycodeenums.h"
#include "quantum.h"


// One-shot layer keys
#define OSQNVNUM OSL(LYR_QNAVNUM)
#define OSFN OSL(LYR_FN)
#define OSFRCAPS OSL(LYR_FRCAPS)

// Layer TO keys
#define TODEFLT TO(LYR_DEFAULT)

// Layer Tap-Toggle keys
#define TTGAME TT(LYR_GAME)
#define TTNVNUM TT(LYR_NAVNUM)
#define TTF1F12 TT(LYR_F1F12)
#define TTWIN TT(LYR_WINDOWS)
#define TTWRKNP TT(LYR_WORKNAP)

#ifdef NAPOLI1084_MOUSE_LAYER_ENABLE
    #define TTMOUSE TT(LYR_MOUSE)
#else
    #define TTMOUSE KC_NO
#endif

// Layer-tap (layer when held, key code when tapped)
#define LTWIN_T LT(LYR_WINDOWS,KC_T)
#define LTF1_N LT(LYR_F1F12,KC_N)

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

#define TD_H_ESC TD(tap_dance_h_esc)
#define TD_CTLZ TD(tap_dance_ctl_z_ctl_a)
#define TD_CTLS TD(tap_dance_ctl_s_ctl_x)
#define TD_CTLC TD(tap_dance_ctl_c_F5)
#define TD_CTLF TD(tap_dance_ctl_f_F3)
#define TD_F7 TD(tap_dance_F7_ctl_F7)
#define TD_CTLP TD(tap_dance_ctl_p_ctl_o)

#define NC_RSET TD(tap_dance_reset)

#endif // #ifdef TAP_DANCE_ENABLE
////////////////////////////////////////////////////////////////////////////////

#define UN_HASH X(uni_HASH)
#define UN_APOS XP(uni_APOSTROPHE, uni_QUOTATION)
#define UN_COMM XP(uni_COMMA, uni_LESSTHAN)
#define UN_DOT XP(uni_DOT, uni_GREATERTHAN)
#define UN_SLSH XP(uni_SLASH, uni_QUESTION)
#define UN_DQUO X(uni_QUOTATION)
#define UN_AT X(uni_AT)
#define UN_LBRC XP(uni_LEFTBRACKET, uni_LEFTCURLYBRACKET)
#define UN_RBRC XP(uni_RIGHTBRACKET, uni_RIGHTCURLYBRACKET)
#define UN_BSLS XP(uni_BACKSLASH, uni_PIPE)
#define UN_CIRC X(uni_CIRCUMFLEX)
#define UN_GRAV XP(uni_GRAVE, uni_TILDE)
#define UN_LCBR X(uni_LEFTCURLYBRACKET)
#define UN_RCBR X(uni_RIGHTCURLYBRACKET)
#define UN_PIPE X(uni_PIPE)
#define UN_TILD X(uni_TILDE)
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

////////////////////////////////////////////////////////////////////////////////

// Worknap Keys

#define WN_ESC KC_ESC
#define WN_1 TD_CTLZ
#define WN_2 TD_CTLS
#define WN_3 TD_CTLC
#define WN_4 CTL_V
#define WN_5 TD_F7

#define WN_6 KC_TAB
#define WN_7 TD_CTLF
#define WN_8 KC_SPACE
#define WN_9 TD_CTLP
#define WN_0 KC_0
#define WN_DEL KC_DELETE
#define WN_APP KC_APP

#define WN_TAB KC_TAB
#define WN_Q LCTL_Q
#define WN_D KC_D
#define WN_R KC_R
#define WN_W KC_W
#define WN_B KC_B

#define WN_J KC_J
#define WN_F KC_F
#define WN_U KC_U
#define WN_P KC_P
#define WN_SCOL RCTL_SC
#define WN_BSPC KC_BSPC

#define WN_LSFT KC_LSFT
#define WN_A LSFT_A
#define WN_S KC_S
#define WN_H TD_H_ESC
#define WN_T LTWIN_T
#define WN_G KC_G

#define WN_Y KC_Y
#define WN_N LTF1_N
#define WN_E KC_E
#define WN_O KC_O
#define WN_I RSFT_I
#define WN_RSFT KC_RSFT

#define WN_LCTL KC_LCTL
#define WN_Z LCTL_Z
#define WN_X KC_X
#define WN_M KC_M
#define WN_C KC_C
#define WN_V KC_V

#define WN_K KC_K
#define WN_L KC_L
#define WN_COMM UN_COMM
#define WN_DOT UN_DOT
#define WN_SLSH UN_SLSH
#define WN_RCTL KC_RCTL

#define WN_LWIN KC_LCTL
#define WN_LALT KC_LALT
#define WN_RALT KC_LALT
#define WN_RWIN KC_LWIN

// Thumb keys
#define WN_LTB1 OSL(LYR_NAVNUM)
#define WN_LTB2 KC_SPACE
#define WN_LTB3 OSL(LYR_F1F12)
#define WN_LTB4 TTGAME
#define WN_RTB1 OSL(LYR_FRSYMBOL)
#define WN_RTB2 KC_ENTER
#define WN_RTB3 OSL(LYR_WINDOWS)
#define WN_RTB4 TTMOUSE
