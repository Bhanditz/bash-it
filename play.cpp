#include <misc.h>
#include <soundplayer.h>
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

void play(string pack, int info[5]) {
string sounddir = (string)("sounds/")+pack+"/";
sound cpu;
sound player;
sound bgm;
sound lose;
sound reward;
stringstream s;
if(info[1] <= 0) {
s << "sounds/intro.ogg";
}
else {
s << sounddir << "intro" << rand()%info[1] << ".ogg";
play_sound_wait(s.str());
}
for(int x = 0; x<info[0]; x++) {
s.str("");
s << sounddir << "cpu" << x << ".ogg";
cpu.load(s.str());
}
for(int x = 0; x<info[2]; x++) {
s.str("");
s << sounddir << "lose" << x << ".ogg";
cpu.load(s.str());
}
for(int x = 0; x<info[3]; x++) {
s.str("");
s << sounddir << "player" << x << ".ogg";
cpu.load(s.str());
}
for(int x = 0; x<info[4]; x++) {
s.str("");
s << sounddir << "reward" << x << ".ogg";
cpu.load(s.str());
}
bgm.load(sounddir+"bgm.ogg");
bgm.set_loop(true);
bgm.play();
bool done = false;
float time = 2.0;
int score = 0;
do {
int dir = rand()%3-1;
s.str("");
s << sounddir << "cpu" << rand()%info[0] << ".ogg";
cpu.load(s.str());
cpu.set_pan(50*dir);
cpu.play();
keyboard kb;
int pressed = -10000;
int x;
for(x = 0; x < time/0.005; x++) {
al_rest(0.005);
if(kb.key_pressed(ALLEGRO_KEY_LEFT)) {
pressed = -1;
break;
}
else if(kb.key_pressed(ALLEGRO_KEY_RIGHT)) {
pressed = 1;
break;
}
else if((kb.key_pressed(ALLEGRO_KEY_DOWN) || kb.key_pressed(ALLEGRO_KEY_UP))) {
pressed = 0;
break;
}
}
if(dir == pressed) {
if(info[4] > 0) {
s.str("");
s << sounddir << "reward" << rand()%info[4] << ".ogg";
reward.load(s.str());
}
else {
reward.load((string)("sounds/reward.ogg"));
}
player.set_pan(cpu.get_pan());
play_sound_wait(&player);
score++;
}
else {
if(info[2] > 0) {
s.str("");
s << sounddir << "lose" << rand()%info[2] << ".ogg";
lose.load(s.str());
}
else {
lose.load((string)("sounds/lose.ogg"));
}
play_sound_wait(&lose);
screen_reader sr;
s.str("");
s << "Sorry, You lose! Your score was " << score << "!";
sr.speak_any(s.str());
done = true;
}
if(score%2 == 0) {
time -= 0.1;
if(time < 0.25) {
time = 0.25;
}
}
} while(!done);
}

