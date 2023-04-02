/*
Copyright 2022 NapOli1084 (@napoli1084)

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

#ifdef RGBLIGHT_ANIMATIONS
#error RGBLIGHT_ANIMATIONS is defined
#endif

#define NAPOLI1084_LAYOUT( \
    leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0, leftIndex3Row0, rightIndex3Row0, rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
    leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1, leftIndex3Row1, rightIndex3Row1, rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
    leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2, leftIndex3Row2, rightIndex3Row2, rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
    leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3, leftIndex3Row3, rightIndex3Row3, rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
    leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftIndex3Row4, rightIndex3Row4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
    leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftIndex1Row5, leftIndex2Row5, leftIndex3Row5, rightIndex3Row5, rightIndex2Row5, rightIndex1Row5, rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5, \
    leftThumb0, leftThumb1, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1, rightThumb0 \
) \
    LAYOUT_ortho_5x14( \
        leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1,     rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
        leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2,     rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
        leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3,     rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
        leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4,     rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
        leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow5, leftMiddleRow5, leftThumb1    , leftThumb2    ,     rightThumb2    , rightThumb1    , rightMiddleRow5, rightRingRow5, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4 \
    )

#define NAPOLI1084_LAYOUT_STD( \
    leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0, leftIndex3Row0, rightIndex3Row0, rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
    leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1, leftIndex3Row1, rightIndex3Row1, rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
    leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2, leftIndex3Row2, rightIndex3Row2, rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
    leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3, leftIndex3Row3, rightIndex3Row3, rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
    leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftIndex3Row4, rightIndex3Row4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
    leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftIndex1Row5, leftIndex2Row5, leftIndex3Row5, rightIndex3Row5, rightIndex2Row5, rightIndex1Row5, rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5, \
    leftThumb0, leftThumb1, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1, rightThumb0 \
) \
    LAYOUT_ortho_5x14( \
        leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1,     rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
        leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2,     rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
        leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3,     rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
        leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4,     rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
        leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftThumb1    , leftThumb2    ,     rightThumb2    , rightThumb1    , rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5 \
    )

#include "napoli1084_keymap.h"

