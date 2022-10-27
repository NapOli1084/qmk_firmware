Copyright 2022 [NapOli1084](https://github.com/NapOli1084)

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

---

This folder contains definitions and functions I use on multiple of my keymaps.
For more info on the setup of this folder, see [user space](../../docs/feature_userspace.md).

All my keymaps are using keycodes from [napoli1084_keycodes.h](./napoli1084_keycodes.h).
My keymaps are mostly for split ergo keyboards which have different layouts,
so I'm abstracting keycodes with a set of defines such that I can easily change
a key mapping without having to change all my keymaps.

My default layer is based on Workman with some differences for mods,
command (backspace, enter, etc.) and num row (that I use for shortcuts).
Navigation keys and num pad are on a separate layer.
Then I have "symbol" layers which in addition to punctuations,
contain French accent letter keys.
Finally I have layers for F keys, Windows shortcuts and system/keyboard functions.

My keymaps are:

* [Dactyl-Manuform 6x6](../../keyboards/handwired/dactyl_manuform/6x6/keymaps/napoli1084/keymap.c)
* [Dactyl](../../keyboards/handwired/dactyl_promicro/keymaps/napoli1084/keymap.c)
* [Ergodox](../../keyboards/ergodox_ez/keymaps/napoli1084/keymap.c)
* [Viterbi](../../keyboards/keebio/viterbi/keymaps/napoli1084/keymap.c)

There is a bunch of features I'm using with all of them:

* Caps Word
* One-shot layer keys with 2 taps toggle
* Tap Dance
* Unicode Map with WinCompose on Windows

I also have a couple custom features I implemented in my user space:

* Multiple "symbol modes" to allow typing independently of the OS keyboard layout:

  * Unicode (default), can be used with any OS keyboard layout as long as WinCompose is running.
  * CAFR (Canadian French), can be used when OS layout is CAFR.
  * CMS (Canadian Multilingual Standard), can be used when OS layout is CMS.
  * US, can be used when OS layout is US. Doesn't support French accent letters.

  Each of these "modes" adapts the keycodes sent such that the same keys are used
  even though the OS layout might be different.
  They are implemented in [napoli1084_symbolkeys.c](./napoli1084_symbolkeys.c)
  and cycled with keycode `NC_SYMD`.

* Custom [tap dances](./napoli1084_tapdance.c).
* [RGB layers for underglow RGB lighting](./napoli1084_rgblayers.c).
* [RGB layers and custom controls for in-switch RGB matrix](./napoli1084_rgbmatrix.c).
