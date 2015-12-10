#include <dynamic_menu.h>
#include <menu_helper.h>


int main()
{
// Generate the main menu.
string options[] = {"play","exit"};
dynamic_menu* mainMenu = create_menu(options, 2, NULL, 0);
int r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{

}
}
