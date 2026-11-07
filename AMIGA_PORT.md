LPairs2 2.3.2 for AmigaOS 3.x
=============================

LPairs2 (Michael Speck, LGames), the memory game: turn the cards over two
at a time and find the pairs of animal photographs (or triplets and
quadruplets), alone, against the computer or another player, or in
Survivor mode, where the board grows as long as you keep matching. For
AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG screen, on
OpenGPU's SDL 2.

Base: lpairs2-2.3.2.tar.gz from LGames on SourceForge (sha256
cb87912d685f2385cc06d182a9d33f97af697ed18621b563544933fefe72b592);
there is no Debian package. Branch team2/lpairs2-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the menu over its card demo, New Game, Start Game, cards turned
over (the photographs shown, a mismatch turned back, the time and the
mistakes counted), Escape to the menu, Back, and Quit back to the Shell,
the settings written to lpairs2.conf. The lab is muted, so the sounds
were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later: LIBS:OpenGPU/SDL2.module, SDL2_image.module,
  SDL2_mixer.module and SDL2_ttf.module.


How to play
-----------

Open the LPairs2 icon, or run LPairs2 from a Shell. It opens a window half
as wide as the Workbench (Graphics in the menu has the full screen). Click
the menu's choices; in a game click a card to turn it over. Escape is the
menu at any time; R or the right mouse button starts again after a game.
Hold Shift to see the pictures' names. ReadMe-upstream in the drawer is
upstream's README; data/themes/Standard/CREDITS names every picture's
author and licence. The settings are lpairs2.conf in the drawer.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers and the OpenGPU kit
(see the Makefile's head). The drawer is dist/LPairs2 (and
dist/LPairs2.info).


What was changed
----------------

- src/main.cpp: main() first moves into the drawer and deals at exit with
  the screens OpenGPU's SDL2.module can leave after a full screen game
  (amiga/amiga_start.c and amiga/amiga_screens.c, from the Legend of
  Edgar port).
- src/config.cpp: the settings are PROGDIR:lpairs2.conf; the game starts
  in a window (upstream starts full screen at the desktop's size).
- src/game.cpp: the cards are shuffled with a generator seeded from rand()
  (which main() seeds from the clock): std::random_device throws here, and
  the game stopped as it started.
- src/theme.cpp: the theme's drawer is checked with dirExists(), since a
  drawer cannot be opened as a file on AmigaOS.
- amiga/Makefile.amigaos builds src/Makefile.am's sources with
  amiga/defines.h for configure's config.h (no gettext: English; libnix's
  vasprintf declared), the theme at PROGDIR:data/themes. amiga/amiga_prefix.hpp:
  the C++ streams first in every file (the toolchain's pthread.h wraps
  read() and write() in macros once <unistd.h> is in).
- amiga/stack.c: 512 KB of stack.


Licences
--------

LPairs2: GPL 3 or later (COPYING.txt). Its Standard theme, file by file
in data/themes/Standard/CREDITS: the animal photographs from Wikipedia
under CC BY, CC BY-SA, GFDL, the Free Art Licence or in the public
domain; the backgrounds, card textures and sounds in the public domain;
the Source Sans Pro fonts under the SIL Open Font License (SIL-OFL.txt).
The Amiga files (amiga/): the AmiCradle Team, GPL 3 or later; the icon is
upstream's lpairs2.png, made smaller.
