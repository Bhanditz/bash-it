#include <include.h>
using std::string;
using std::vector;
using std::ifstream;

void play(string pack, ALLEGRO_DISPLAY* disp);


int main(int argc, char **argv)
{
ALLEGRO_DISPLAY* disp = game_window("Bash It!");
if (disp) {
vector<string>* soundpackList = get_dir_children("sounds", 2);
soundpackList->push_back("Back to main menu.");
dynamic_menu* soundpackMenu = create_menu(*soundpackList, vector<string>());
string ret = "";
do {
ret = generic_menu(vector<string>(), "", false);
if (ret == "play") {
int r2 = soundpackMenu->run_extended("", "", 1, true);
string pack = (*soundpackList)[r2-1];
play(pack, disp);
}
}
while (ret != "invalid" && ret != "exit" && ret != "escape");
if (soundpackMenu) {
delete soundpackMenu;
}
if (soundpackList) {
delete soundpackList;
}
end_game(disp);
return 0;
}
return 1;
}
