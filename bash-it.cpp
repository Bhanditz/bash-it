#include <misc.h>
#include <menu_helper.h>
#include <string>
#include <vector>
#include <allegro5/allegro.h>
using std::string;
using std::vector;
#include <iostream>
#include <fstream>
using std::ifstream;

void play(string pack);


int main()
{
ALLEGRO_DISPLAY* disp = game_window("Bash It!");
int r = 0;
// Generate the main menu.
string options[] = {"play","credits","exit"};
dynamic_menu* mainMenu = create_menu(vector<string>(options, options+3), vector<string>()/*, vec, vec2*/);
mainMenu->set_display(disp);
vector<string>* soundpackList = get_dir_children("sounds", 2);
soundpackList->push_back("Back to main menu.");
dynamic_menu* soundpackMenu = create_menu(*soundpackList, vector<string>());
soundpackMenu->set_display(disp);
while (r != 3)
{
r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{
int r2 = soundpackMenu->run_extended("", "", 1, true);
string pack = (*soundpackList)[r2-1];
play(pack);
}
if (r == 2)
{
credits(disp, "Bash It");
}
}
delete mainMenu;
delete soundpackMenu;
delete soundpackList;
end_game(disp);
}
