#include <dynamic_menu.h>
#include <menu_helper.h>


int main()
{
al_init();
al_install_audio();
al_install_keyboard();
al_init_acodec_addon();
ALLEGRO_DISPLAY* disp = al_create_display(640,480);
// Generate the main menu.
string options[] = {"play","exit"};
dynamic_menu* mainMenu = create_menu(options, 2, NULL, 0);
mainMenu->set_display(disp);
int r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{

}
}
