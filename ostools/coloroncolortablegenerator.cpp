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
    string val;
    string valstr;

    colordata(int val, string valstr) {
        this->val = to_string(val);
        this->valstr = valstr;
    }
};

vector<colordata> colormap;
vector<colordata> brightcolormap;

int main() {
    colormap.push_back(colordata(0, "B"));
    colormap.push_back(colordata(1, "BL"));
    colormap.push_back(colordata(2, "G"));
    colormap.push_back(colordata(3, "C"));
    colormap.push_back(colordata(4, "R"));
    colormap.push_back(colordata(5, "M"));
    colormap.push_back(colordata(6, "BR"));
    colormap.push_back(colordata(7, "LG"));
    brightcolormap.push_back(colordata(0, "DG"));
    brightcolormap.push_back(colordata(1, "LB"));
    brightcolormap.push_back(colordata(2, "LGR"));
    brightcolormap.push_back(colordata(3, "LC"));
    brightcolormap.push_back(colordata(4, "LR"));
    brightcolormap.push_back(colordata(5, "LM"));
    brightcolormap.push_back(colordata(6, "Y"));
    brightcolormap.push_back(colordata(7, "W"));

    //we can map to all the color datas with the enum
    //iterate through 0 - 7 and create an enum with the
    //all the different combinations of fg:bg hex values set
    cout << "enum VGACOLOR {" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "\t" + colormap[i].valstr + colormap[j].valstr + "," << endl;
            cout << "\t" + colormap[i].valstr + brightcolormap[j].valstr + "," << endl;
            cout << "\t" + brightcolormap[i].valstr + colormap[j].valstr + "," << endl;
            cout << "\t" + brightcolormap[i].valstr + brightcolormap[j].valstr + "," << endl;
        }
    }
    cout << "};" << endl;
    cout << "const uint32 VGACOLORLEN = 256;" << endl;
    cout << "uint8 VGACOLORARR[VGACOLORLEN]  = {" << endl;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "\t(((0x" + colormap[i].val + "|0x8) << 4) + 0x" + colormap[j].val + "|0x8) << 8," << endl;
            cout << "\t(((0x" + colormap[i].val + "|0x8) << 4) + 0x" + brightcolormap[j].val + ") << 8," << endl;
            cout << "\t((0x" + brightcolormap[i].val + " << 4) + (0x" + colormap[j].val + "|0x8)) << 8," << endl;
            cout << "\t((0x" + brightcolormap[i].val + " << 4) + 0x" + brightcolormap[j].val + ") << 8," << endl;
            count++;
        }
    }
    cout << "};" << endl;
    cout << "uint8* VGACOLORSTRARR[VGACOLORLEN]  = {" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "\t\"" + colormap[i].valstr + colormap[j].valstr + "\"," << endl;
            cout << "\t\"" + colormap[i].valstr + brightcolormap[j].valstr + "\"," << endl;
            cout << "\t\"" + brightcolormap[i].valstr + colormap[j].valstr + "\"," << endl;
            cout << "\t\"" + brightcolormap[i].valstr + brightcolormap[j].valstr + "\"," << endl;
        }
    }
    cout << "};" << endl << endl;
    return 0;
}