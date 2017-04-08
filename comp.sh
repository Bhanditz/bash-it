#!/bin/bash

g++ -ggdb -I/usr/include/speech-dispatcher -Igame-kit -Igame-kit/allegro_stuff -Igame-kit/screen-reader game-kit/allegro_stuff/keyboard.cpp game-kit/allegro_stuff/dynamic_menu.cpp game-kit/allegro_stuff/sound.cpp game-kit/screen-reader/screen_reader.cpp game-kit/menu_helper.cpp game-kit/misc.cpp game-kit/soundplayer.cpp play.cpp game.cpp -lallegro -lallegro_audio -lallegro_acodec -lallegro_ttf -lallegro_font -lspeechd && mv a.out bash-it
