int main()
{
// Generate the main menu.
string options* = {"play","exit"};
dynamic_menu* mainMenu = create_menu(options, 2, NULL, 0);
r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{

}
}
