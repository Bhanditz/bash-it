#include <include.h>
using std::stringstream;
using std::string;
using std::vector;

void play(string pack) {
float currentTime = 0;
float shortestTime = 0;
float longestTime = 0;
float totalTime = 0;
ALLEGRO_TIMER* timer = NULL;
float time = 2.0;
int score = 0;
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
stringstream bragScore;
stringstream s;
if (info[1] > 0) {
s.str("");
s << sounddir << "intro" << rand()%info[1] << ".opus";
play_sound_wait(s.str());
}
else {
screen_reader sr;
sr.speak_any("3");
al_rest(0.5);
sr.speak_any("2");
al_rest(0.5);
sr.speak_any("1");
al_rest(0.5);
sr.speak_any("go!");
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
if (!timer)
{
timer = al_create_timer(0.005);
al_start_timer(timer);
}
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
if(kb.key_pressed(ALLEGRO_KEY_LEFT) || kb.key_pressed(ALLEGRO_KEY_J)) {
pressed = -1;
break;
}
else if(kb.key_pressed(ALLEGRO_KEY_RIGHT) || kb.key_pressed(ALLEGRO_KEY_L)) {
pressed = 1;
break;
}
else if((kb.key_pressed(ALLEGRO_KEY_DOWN) || kb.key_pressed(ALLEGRO_KEY_UP) || kb.key_pressed(ALLEGRO_KEY_K) || kb.key_pressed(ALLEGRO_KEY_I))) {
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
// Keep track of the fastest and slowest reaction times.
currentTime = al_get_timer_count(timer) * 0.005;
totalTime = al_get_timer_count(timer) * 0.005 + currentTime;
if (shortestTime > currentTime)
{
shortestTime = currentTime;
}
if (longestTime < currentTime)
{
longestTime = currentTime;
}
score++;
play_sound_wait(&player);
// Reset the timer
al_set_timer_count(timer, 0);
if (score%15 == 0) {
if (info[4] > 0) {
s.str("");
s << sounddir << "reward" << rand()%info[4] << ".opus";
reward.load(s.str());
}
play_sound_wait(&reward);
// Reset the timer
al_set_timer_count(timer, 0);
}
}
else {
bgm.stop();
if(info[2] > 0) {
s.str("");
s << sounddir << "lose" << rand()%info[2] << ".opus";
lose.load(s.str());
}
play_sound_wait(&lose);
screen_reader sr;
s.str("");
s << "You lose! Your score was " << score << "! Your fastest reaction time was";
bragScore << "In #2MB #bashIt I scored " << score << "! My fastest reaction time was";
s << shortestTime << ((shortestTime == 1)?" second!":" seconds!");
bragScore << shortestTime << ((shortestTime == 1)?" second!":" seconds!");
s << "Your slowest reaction time was";
bragScore << "My slowest reaction time was";
s << shortestTime << ((shortestTime == 1)?" second!":" seconds!");
bragScore << shortestTime << ((shortestTime == 1)?" second!":" seconds!");
s << "Your average reaction time was";
bragScore << "My average reaction time was";
s << totalTime / score << ((totalTime / score == 1)?" second!":" seconds!");
bragScore << totalTime / score << ((totalTime / score == 1)?" second!":" seconds!");
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

