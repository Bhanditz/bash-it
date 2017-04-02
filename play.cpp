#include <include.h>
using std::stringstream;
using std::string;
using std::vector;

void play(string pack) {
string sounddir = (string)("sounds/")+pack+"/";
vector<string>* vec = get_dir_children(sounddir, 1);
int info[6];
if (vec) {
for (int x = 0; x < 6; x++) {
info[x] = 0;
}
for (int x = 0; x < vec->size(); x++) {
if ((*vec)[x].find("intro") != string::npos) {
info[1]++;
}
else if((*vec)[x].find("cpu") != string::npos) {
info[0]++;
}
else if((*vec)[x].find("lose") != string::npos) {
info[2]++;
}
else if((*vec)[x].find("player") != string::npos) {
info[3]++;
}
else if((*vec)[x].find("reward") != string::npos) {
info[4]++;
}
else if ((*vec)[x].find("bgm") != string::npos) {
info[5]++;
}
}
delete vec;
}
else {
log((string)("Could not get list of files in ")+sounddir+"!\n");
return;
}
sound cpu;
sound player;
sound bgm;
sound lose;
sound reward;
stringstream s;
if (info[1] > 0) {
s.str("");
s << sounddir << "intro" << rand()%info[1] << ".opus";
play_sound_wait(s.str());
}
for(int x = 0; x<info[0]; x++) {
s.str("");
s << sounddir << "cpu" << x << ".opus";
cpu.load(s.str());
}
for(int x = 0; x<info[2]; x++) {
s.str("");
s << sounddir << "lose" << x << ".opus";
cpu.load(s.str());
}
for(int x = 0; x<info[3]; x++) {
s.str("");
s << sounddir << "player" << x << ".opus";
cpu.load(s.str());
}
for(int x = 0; x<info[4]; x++) {
s.str("");
s << sounddir << "reward" << x << ".opus";
cpu.load(s.str());
}
if (info[5] > 0) {
s.str("");
s << sounddir << "bgm" << rand()%info[5] << ".opus";
bgm.load(s.str());
bgm.set_loop(true);
bgm.play();
}
bool done = false;
float time = 2.0;
int score = 0;
do {
int dir = rand()%3-1;
if (info[0] > 0) {
s.str("");
s << sounddir << "cpu" << rand()%info[0] << ".opus";
cpu.load(s.str());
cpu.set_pan(50*dir);
cpu.play();
}
else {
log((string)("There appears to be no cpu sounds in the directory ")+sounddir+"!\n");
}
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
if(info[3] > 0) {
s.str("");
s << sounddir << "player" << rand()%info[3] << ".opus";
player.load(s.str());
}
player.set_pan(cpu.get_pan());
play_sound_wait(&player);
score++;
if (score%15 == 0) {
if (info[4] > 0) {
s.str("");
s << sounddir << "reward" << rand()%info[4] << ".opus";
reward.load(s.str());
}
play_sound_wait(&reward);
}
}
else {
if(info[2] > 0) {
s.str("");
s << sounddir << "lose" << rand()%info[2] << ".opus";
lose.load(s.str());
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

