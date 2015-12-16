#include <misc.h>
#include <menu_helper.h>
#include <string>
#include <vector>
#include <allegro5/allegro.h>
using std::string;
using std::vector;

int test(dynamic_menu* m, int pos, void* test);

int main()
{
ALLEGRO_DISPLAY* disp = game_window("Bash It!");
int r;
// Generate the main menu.
string options[] = {"play","credits","exit"};
vector<f> vec(0);
vec.resize(2, NULL);
vec[1] = &test;
vector<void*> vec2(0);
vec2.resize(2, NULL);
string test2 = "test";
vec2[1] = &test2;
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

int test(dynamic_menu* m, int pos, void* test) {
if(test) {
screen_reader sr;
sr.speak_any(*((string*)(test)));
return 1;
}
return 0;
}

