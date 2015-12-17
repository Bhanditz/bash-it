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
#include <uiohook.h>

void play(string pack, int info[5]);
void do_dispatch_dumby(uiohook_event* event);


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
hook_set_dispatch_proc(do_dispatch_dumby);
if(hook_run() != UIOHOOK_SUCCESS) {
log("Could not install the hook!\n");
end_game(disp);
return 1;
}
while (r != 3)
{
r = mainMenu->run_extended("", "", 1, true);
if (r == 1)
{
int r2 = soundpackMenu->run_extended("", "", 1, true);
string pack = (*soundpackList)[r2-1];
ifstream f;
f.open(((string)("sounds/")+pack+"/info.dat").c_str());
int info[5];
string s;
do {
getline(f, s);
string s2="";
for(int x =1; x<s.size(); x++) {
s2 += s[x];
}
switch(s[0]) {
case 'c':
info[0] = atoi(s2.c_str());
break;
case 'i':
info[1] = atoi(s2.c_str());
break;
case 'l':
info[2] = atoi(s2.c_str());
break;
case 'p':
info[3] = atoi(s2.c_str());
break;
case 'r':
info[4] = atoi(s2.c_str());
break;
}
} while(s != "");
play(pack, info);
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

void do_dispatch_dumby(uiohook_event* event) {
}

