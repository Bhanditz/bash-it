@echo off
set allegro_ver="5.0.10"
set allegro_link="MT"
cl /O2 /EHsc /MT /Igame-kit/allegro_stuff /Igame-kit/screen-reader /Igame-kit/allegro_stuff/include -Igame-kit game-kit/misc.cpp game-kit/menu_helper.cpp game-kit/soundplayer.cpp play.cpp bash-it.cpp game-kit/allegro_stuff/sound.cpp game-kit/allegro_stuff/keyboard.cpp game-kit/allegro_stuff/dynamic_menu.cpp game-kit/screen-reader/screen_reader.cpp /link /nologo /out:horseshoes.exe /libpath:game-kit/allegro_stuff /libpath:game-kit/screen-reader dolapi.lib saapi32.lib nvdaControllerClient32.lib allegro_acodec-%allegro_ver%-%allegro_link%.lib allegro_audio-%allegro_ver%-%allegro_link%.lib allegro_font-%allegro_ver%-%allegro_link%.lib allegro_ttf-%allegro_ver%-%allegro_link%.lib allegro-%allegro_ver%-%allegro_link%.lib
pause