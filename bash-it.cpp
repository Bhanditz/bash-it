#include <game.h>
#include <menu_helper.h>

int main()
{
game-window("Bash It!")
// Generate the main menu.
string options[] = {"play","exit"};
dynamic_menu* mainMenu = create_menu(options, 2, NULL, 0);
mainMenu->set_display(disp);
int r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{
vector<string>* soundpackList = function();
string array[soundpackList->size()];
for (int x = 0; x < soundpackList->size(); x++)
{
array[x] = (*soundpackList)[x];
}
dynamic_menu* soundpackMenu = create_menu(soundpackList, soundpackList->size(), NULL, 0);
soundpackMenu->set_display(disp);
int r = soundpackMenu->run_extended("", "", 1, true);
}
}
