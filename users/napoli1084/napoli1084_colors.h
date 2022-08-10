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

#pragma once

#include "quantum/color.h"

// Didn't like HSV_PINK when I tried it, I try to stick to 255 for sat & val
#define NAPOLI1084_HSV_PINK 234, 255, 255

// HSV_ORANGE was too yellow to my taste
#define NAPOLI1084_HSV_ORANGE 15, 255, 255

#define NAPOLI1084_HSV_LYR_WORKNAP HSV_GREEN
#define NAPOLI1084_HSV_LYR_GAME HSV_RED
#define NAPOLI1084_HSV_LYR_NAVNUM HSV_CYAN
#define NAPOLI1084_HSV_LYR_FRSYMBOL HSV_YELLOW
#define NAPOLI1084_HSV_LYR_FRCAPS NAPOLI1084_HSV_ORANGE
#define NAPOLI1084_HSV_LYR_FN HSV_PURPLE
#define NAPOLI1084_HSV_LYR_F1F12 HSV_MAGENTA
#define NAPOLI1084_HSV_LYR_WINDOWS HSV_WHITE

