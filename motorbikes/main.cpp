#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m, v, totalTurns;
string polje[4];
string commands[] = {"SPEED", "WAIT", "JUMP", "UP", "DOWN", "SLOW"};


struct State {
    int x[4], y[4];
    bool l[4];
    int live, s, turns;
    bool goodPath;

    State() {}

    State(int s) {
        this->s = s;
        goodPath = true;
    }

    State(State* prev) {
        for(int i=0;i<4;i++) {
            x[i] = prev->x[i];
            y[i] = prev->y[i];
            l[i] = prev->l[i];
        }
        live = prev->live;
        s = prev->s;
        goodPath = true;
    }
};

State simulate(State state, string command) {
    State newState = new State(&state);
    newState.turns = state.turns + 1;
    bool move = true;
    int dir=1;


    // update new state
    if(command == "WAIT") {

    } else if(command == "JUMP") {

    } else if(command == "SPEED") {
            newState.s++;

    } else if(command == "UP" || command == "DOWN") {
        if(command == "UP") dir = -1;

        for(int i=0;i<m;i++)
            if(newState.l[i]==true &&
                (newState.y[i]==0 && dir==-1 || dir==1 && newState.y[i]==3))
                move = false;
        if(move)
            for(int i=0;i<m;i++)
                newState.y[i]+=dir;
        else
            newState.goodPath = false;

    } else if(command == "SLOW") {
        newState.s--;

    }


    for(int i=0; i<m; i++)
        newState.x[i] += newState.s;


    // evaluate new state
    if(newState.s == 0) newState.goodPath = false;
    if(newState.turns + totalTurns > 50) newState.goodPath = false;

    for(int i=0; i<m; i++) {
        if(newState.l[i] == false) continue;

        // if bike lands in hole
        if(polje[newState.y[i]][newState.x[i]] == '0') {
            newState.live--;
            newState.l[i] = false;

        } else if(command != "JUMP") {  // if bike drove in a hole
            for(int j=state.x[i]+1; j<newState.x[i]; j++) {
                if(polje[state.y[i]][j] == '0' ||
                    ((command=="UP" || command=="DOWN") && polje[newState.y[i]][j]=='0'))  {
                        newState.live--;
                        newState.l[i] = false;
                        break;
                }
            }
        }
    }

    if(newState.live < v)
        newState.goodPath = false;

    return newState;
}


string dfs(State state) {
    if(state.turns > 10) return "WAIT";

    State newState;
    for(int i=0;i<6;i++) {
        cerr << commands[i] << " ";
        newState = simulate(state, commands[i]);
        if(newState.goodPath == false)
            continue;

        // if not complete, dfs
        bool complete = true;
        for(int j=0; j<m; j++)
            if(newState.x[j] < polje[0].length() - 1) {
                string command = dfs(newState);
                cerr << command << " ";
                if(command != "") return commands[i];
                complete = false;
                break;
            }
        if(complete) return commands[i];
        cerr << endl;
    }
    return "";
}



int main()
{
    cin >> m >> v;
    for(int i=0;i<4;i++)
        cin >> polje[i];

    // game loop
    while (1) {
        totalTurns++;
        int s, live=0; // the motorbikes' speed
        cin >> s;
        State startState = new State(s);

        for (int i=0;i<m;i++) {
            int x, y, a;
            cin >> x >> y >> a;
            startState.x[i] = x;
            startState.y[i] = y;
            startState.l[i] = a;
            if(a) live++;
        }
        startState.live = live;
        startState.turns = 0;


        // A single line containing one of 6 keywords: SPEED, SLOW, JUMP, WAIT, UP, DOWN.
        cout << dfs(startState) << endl;
    }
}
