#include <game-kit/game.h>

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

}
delete mainMenu;
al_uninstall_audio();
al_uninstall_keyboard();
al_destroy_display(disp);
al_uninstall_system();
}
