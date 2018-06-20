#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum color {
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    brown = 6,
    lightgray = 7, 
    darkgray = 0,
    lightblue = 1,
    lightgreen = 2,
    lightcyan = 3,
    lightred = 4,
    lightmagenta = 5,
    yellow = 6,
    white = 7
};

class colordata {
public:
    bool light;
    string val;
    string valstr;

    colordata(bool light, int val, string valstr) {
        this->light = light;
        this->val = to_string(val);
        this->valstr = valstr;
    }
};

vector<colordata> colormap;
vector<colordata> brightcolormap;

int main() {
    colormap.push_back(colordata(false, 0, "BLACK"));
    colormap.push_back(colordata(false, 1, "BLUE"));
    colormap.push_back(colordata(false, 2, "GREEN"));
    colormap.push_back(colordata(false, 3, "CYAN"));
    colormap.push_back(colordata(false, 4, "RED"));
    colormap.push_back(colordata(false, 5, "MAGENTA"));
    colormap.push_back(colordata(false, 6, "BROWN"));
    colormap.push_back(colordata(false, 7, "LIGHTGRAY"));
    brightcolormap.push_back(colordata(true, 0, "DARKGRAY"));
    brightcolormap.push_back(colordata(true, 1, "LIGHTBLUE"));
    brightcolormap.push_back(colordata(true, 2, "LIGHTGREEN"));
    brightcolormap.push_back(colordata(true, 3, "LIGHTCYAN"));
    brightcolormap.push_back(colordata(true, 4, "LIGHTRED"));
    brightcolormap.push_back(colordata(true, 5, "LIGHTMAGENTA"));
    brightcolormap.push_back(colordata(true, 6, "YELLOW"));
    brightcolormap.push_back(colordata(true, 7, "WHITE"));

    //we can map to all the color datas with the enum
    //iterate through 0 - 7 and create an enum with the
    //all the different combinations of fg:bg hex values set
    cout << endl;
    cout << "enum VGACOLOR {" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "\t" + colormap[i].valstr + "ON" + colormap[j].valstr + " = 0x" + colormap[j].val + colormap[i].val + "," << endl;
            cout << "\t" + colormap[i].valstr + "ON" + brightcolormap[j].valstr + " = 0x" + colormap[j].val + brightcolormap[i].val + "," << endl;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "\t" + brightcolormap[i].valstr + "ON" + brightcolormap[j].valstr + " = 0x" + brightcolormap[j].val + brightcolormap[i].val + "," << endl;
            cout << "\t" + brightcolormap[i].valstr + "ON" + colormap[j].valstr + " = 0x" + brightcolormap[j].val + colormap[i].val + "," << endl;
        }
    }
    cout << "};" << endl << endl;
    return 0;
}