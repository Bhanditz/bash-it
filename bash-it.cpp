#include <game.h>
#include <menu_helper.h>
#include <string>
#include <vector>
#include <allegro5/allegro.h>
using std::string;
using std::vector;

int main()
{
ALLEGRO_DISPLAY* disp = game_window("Bash It!");
// Generate the main menu.
string options[] = {"play","exit"};
dynamic_menu* mainMenu = create_menu(options, 2, NULL, 0);
mainMenu->set_display(disp);
int r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{
vector<string>* soundpackList = get_dir_children("sounds", 2);
string array[soundpackList->size()+1];
for (int x = 0; x < soundpackList->size(); x++)
{
array[x] = (*soundpackList)[x];
}
array[soundpackList->size()] = "Back to main menu.";
dynamic_menu* soundpackMenu = create_menu(array, soundpackList->size()+1, NULL, 0);
soundpackMenu->set_display(disp);
r = soundpackMenu->run_extended("", "", 1, true);
}
}
