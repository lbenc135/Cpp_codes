#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;


int W, H, EX, XI, YI;
int polje[20][20];



string to_string(int a) {
    ostringstream ss;
    ss << a;
    return ss.str();
}


string simulate(int x, int y, string dir, bool rock);



int dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}


pair<int,int> nextPos(int x, int y, string dir) {
    pair<int, int> p = make_pair(-1,-1);
    int type = abs(polje[y][x]);
    switch(type)
    {
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 12:
        case 13:
            p = make_pair(x, y+1);
            break;
        case 2:
        case 6:
            if(dir=="LEFT") p = make_pair(x+1, y);
            else if(dir=="RIGHT") p = make_pair(x-1, y);
            break;
        case 4:
            if(dir=="TOP") p = make_pair(x-1, y);
            else if(dir=="RIGHT") p = make_pair(x, y+1);
            break;
        case 5:
            if(dir=="LEFT") p = make_pair(x, y+1);
            else if(dir=="TOP") p = make_pair(x+1, y);
            break;
        case 10:
            p = make_pair(x-1, y);
            break;
        case 11:
            p = make_pair(x+1, y);
            break;
    };
    return p;
}

string nextDir(int x, int y, string dir) {
    string d="";
    int type = abs(polje[y][x]);
    switch(type)
    {
        case 1:
            d = "TOP";
            break;
        case 3:
            if(dir=="TOP") d = "TOP";
            break;
        case 7:
            if(dir=="TOP" || dir=="RIGHT") d = "TOP";
            break;
        case 8:
            if(dir=="LEFT" || dir=="RIGHT") d = "TOP";
            break;
        case 9:
            if(dir=="LEFT" || dir=="TOP") d = "TOP";
            break;
        case 12:
            if(dir=="RIGHT") d = "TOP";
            break;
        case 13:
            if(dir=="LEFT") d = "TOP";
            break;

        case 2:
        case 6:
            if(dir=="LEFT" || dir=="RIGHT") d = dir;
            break;

        case 4:
            if(dir=="TOP") d = "RIGHT";
            else if(dir=="RIGHT") d = "TOP";
            break;
        case 5:
            if(dir=="LEFT") d = "TOP";
            else if(dir=="TOP") d = "LEFT";
            break;
        case 10:
            if(dir=="TOP") d = "RIGHT";
            break;
        case 11:
            if(dir=="TOP") d = "LEFT";
            break;
    };
    return d;
}

int rotate(int type, string dir) {
    if(type < 0) return type;
    switch(type) {
        case 0:
        case 1:
            return type;
        case 2: return 3;
        case 3: return 2;
        case 4: return 5;
        case 5: return 4;

        case 6:
            if(dir=="LEFT") return 9;
            else return 7;
        case 7:
            if(dir=="LEFT") return 6;
            else return 8;
        case 8:
            if(dir=="LEFT") return 7;
            else return 9;
        case 9:
            if(dir=="LEFT") return 8;
            else return 6;

        case 10:
            if(dir=="LEFT") return 13;
            else return 11;
        case 11:
            if(dir=="LEFT") return 10;
            else return 12;
        case 12:
            if(dir=="LEFT") return 11;
            else return 13;
        case 13:
            if(dir=="LEFT") return 12;
            else return 10;
    }
}

string branch(int x, int y, string dir, string rot, bool rock, bool r180=false) {
    string otherRot = "RIGHT";
    if(rot=="RIGHT") otherRot = "LEFT";


    // rotate left
    polje[y][x] = rotate(polje[y][x], rot);
    if(r180) polje[y][x] = rotate(polje[y][x], rot);

    string afterD = nextDir(x, y, dir);
    if(rock && afterD != "") afterD="";
    else if(rock && afterD == "") afterD="!";

    if(afterD != "") {
        string com = simulate(x, y, dir, rock);

        polje[y][x] = rotate(polje[y][x], otherRot);  // return to original rotation
        if(r180) polje[y][x] = rotate(polje[y][x], otherRot);

        if(com != "") return to_string(x) + ' ' + to_string(y) + ' ' + rot;
    } else {
        polje[y][x] = rotate(polje[y][x], otherRot);  // return to original rotation
        if(r180) polje[y][x] = rotate(polje[y][x], otherRot);
    }

    return "";
}


string simulate(int x, int y, string dir, bool rock=false) {
    if(x==EX && y==H-1 && !rock) return "WAIT";

    pair<int,int> nextP = nextPos(x, y, dir);
    string nextD = nextDir(x, y, dir);

    int nx = nextP.first, ny = nextP.second;

    string afterD = nextDir(nx, ny, nextD);
    if(rock && afterD != "") afterD="";
    else if(rock && afterD == "") return "WAIT";
    // if i don't rotate next block and can travel in it
    if(afterD != "") {
        string command = simulate(nx, ny, nextD, rock);
        if (command == "") { // can't travel somewhere further if not rotated

            if(polje[ny][nx]>1) {
                string result = branch(nx, ny, nextD, "LEFT", rock);
                if(result != "") return result;
            }

            // if block rotate left != rotate right and not found solution when rotated left
            if(polje[ny][nx] > 5) {
                // rotate right
                string result = branch(nx, ny, nextD, "RIGHT", rock);
                if(result != "") return result;


                // rotate 180
                result = branch(nx, ny, nextD, "LEFT", rock, true);
                if(result != "") return result;
            }
        } else
            return command;

    } // i need to rotate it
    else {
        int t = polje[ny][nx];
        if(t<0 && rock) return simulate(nx, ny, nextD, rock);
        if(t<0) return "";  // not rotatable

        if(polje[ny][nx]>1) {
            // rotate left
            string result = branch(nx, ny, nextD, "LEFT", rock);
            if(result != "") return result;
        }

        // if block rotate left != rotate right and not found solution when rotated left
        if(polje[ny][nx] > 5) {
            string result = branch(nx, ny, nextD, "RIGHT", rock);
            if(result != "") return result;


            // rotate 180
            result = branch(nx, ny, nextD, "LEFT", rock, true);
            if(result != "") return result;
        }
    }

    return "";
}



int main()
{
    cin >> W >> H; cin.ignore();
    cerr << W << ' ' << H << endl;
    for (int i = 0; i < H; i++) {
        for(int j=0; j<W; j++) {
            cin >> polje[i][j];
            cerr << polje[i][j] << ' ';
        }
        cerr << endl;
    }
    cin >> EX; cin.ignore();
    cerr << EX << endl;

    // game loop
    while (1) {
        string POSI;
        cin >> XI >> YI >> POSI; cin.ignore();
        cerr << XI << ' ' << YI << ' ' << POSI << endl;

        int mindist=10000;
        string commandrock="";

        int R; // the number of rocks currently in the grid.
        cin >> R; cin.ignore();
        cerr << R << endl;
        for (int i = 0; i < R; i++) {
            int XR, YR;
            string POSR;
            cin >> XR >> YR >> POSR; cin.ignore();
            cerr << XR << ' ' << YR << ' ' << POSR << endl;

            string comrock = simulate(XR, YR, POSR, true);
            if(comrock != "" && comrock != "WAIT") {
                char dir[6];
                int x, y;
                sscanf (comrock.c_str(), "%i %i %s", &x, &y, dir);
                if(dist(x, y, XR, YR) < mindist && (x!=XI || y!=YI)) {
                    mindist = dist(x, y, XR, YR);
                    commandrock = comrock;
                }
            }
        }


        // One line containing on of three commands: 'X Y LEFT', 'X Y RIGHT' or 'WAIT'
        string command = simulate(XI, YI, POSI);
        string finalcmd = "WAIT";

        char dir[6];
        int x, y;

        // decide which command to give
        if(command != "WAIT") {
            sscanf (command.c_str(), "%i %i %s", &x, &y, dir);
            if(dist(x, y, XI, YI)<=1 || commandrock == "") {
                finalcmd = command;
            } else {
                finalcmd = commandrock;
            }

        } else if(commandrock != "") {
            finalcmd = commandrock;
        }

        if(finalcmd != "WAIT") {
            sscanf (finalcmd.c_str(), "%i %i %s", &x, &y, dir);
            polje[y][x] = rotate(polje[y][x], string(dir));
        }

        cout << finalcmd << endl;
    }
}
