#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int m, n;
int balls;
string polje[1000], temp[1000];


struct State {
    int x[1000], y[1000];
    int shotl[1000];
    bool put[1000];

    State() {
        for(int i=0;i<1000;i++)
            put[i] = true;
    }
};


bool branch(State state, int i, int dx, int dy);


bool dfs(State state) {
    for(int i=0; i<balls; i++) {
        if(state.put[i]) continue;

        int x = state.x[i], y = state.y[i];

        // IS IN HOLE?
        char cur = temp[y][x];
        if(cur == 'H') {
            temp[y][x] = '#';
            state.put[i] = true;
            if(dfs(state)) return true;

            state.put[i] = false;
            temp[y][x] = 'H';
            return false;
        }

        if(state.shotl[i]==0) return false;


        // UP
        if(y-state.shotl[i]>=0) {
            bool can = true;
            for(int j=1; j<=state.shotl[i]; j++)
                if(!(temp[y-j][x] == '.' || (temp[y-j][x] == 'X' && j!=state.shotl[i]) || (j==state.shotl[i] && temp[y-j][x] == 'H'))) {
                    can = false;
                    break;
                }
            if(can && branch(state, i, 0, -state.shotl[i])) return true;
        }
        // DOWN
        if(y+state.shotl[i]<n) {
            bool can = true;
            for(int j=1; j<=state.shotl[i]; j++)
                if(!(temp[y+j][x] == '.' || (temp[y+j][x] == 'X' && j!=state.shotl[i]) || (j==state.shotl[i] && temp[y+j][x] == 'H'))) {
                    can = false;
                    break;
                }
            if(can && branch(state, i, 0, +state.shotl[i])) return true;
        }
        // RIGHT
        if(x+state.shotl[i]<m) {
            bool can = true;
            for(int j=1; j<=state.shotl[i]; j++)
                if(!(temp[y][x+j] == '.' || (temp[y][x+j] == 'X' && j!=state.shotl[i]) || (j==state.shotl[i] && temp[y][x+j] == 'H'))) {
                    can = false;
                    break;
                }
            if(can && branch(state, i, +state.shotl[i], 0)) return true;
        }
        // LEFT
        if(x-state.shotl[i]>=0) {
            bool can = true;
            for(int j=1; j<=state.shotl[i]; j++)
                if(!(temp[y][x-j] == '.' || (temp[y][x-j] == 'X' && j!=state.shotl[i]) || (j==state.shotl[i] && temp[y][x-j] == 'H'))) {
                    can = false;
                    break;
                }
            if(can && branch(state, i, -state.shotl[i], 0)) return true;
        }



        return false;
    }
}

bool branch(State state, int i, int dx, int dy) {
    if(dy>0) {
        for(int j=0; j<dy; j++)
            temp[state.y[i]+j][state.x[i]] = 'v';
    } else if(dy<0) {
        for(int j=0; j>dy; j--)
            temp[state.y[i]+j][state.x[i]] = '^';
    } else if(dx>0) {
        for(int j=0; j<dx; j++)
            temp[state.y[i]][state.x[i]+j] = '>';
    } else if(dx<0) {
        for(int j=0; j>dx; j--)
            temp[state.y[i]][state.x[i]+j] = '<';
    }


    // DEBUG
    cerr << endl;
    for(int j=0;j<n;j++) cerr << temp[j] << endl;


    state.y[i]+=dy;
    state.x[i]+=dx;
    state.shotl[i]--;


    if(dfs(state)) return true;     //****** DFS


    state.y[i]-=dy;
    state.x[i]-=dx;
    state.shotl[i]++;


    if(dy>0) {
        for(int j=0; j<dy; j++)
            temp[state.y[i]+j][state.x[i]] = polje[state.y[i]+j][state.x[i]];
    } else if(dy<0) {
        for(int j=0; j>dy; j--)
            temp[state.y[i]+j][state.x[i]] = polje[state.y[i]+j][state.x[i]];
    } else if(dx>0) {
        for(int j=0; j<dx; j++)
            temp[state.y[i]][state.x[i]+j] = polje[state.y[i]][state.x[i]+j];
    } else if(dx<0) {
        for(int j=0; j>dx; j--)
            temp[state.y[i]][state.x[i]+j] = polje[state.y[i]][state.x[i]+j];
    }
    //temp[state.y[i]][state.x[i]] = '0';

    // DEBUG
    cerr << endl;
    for(int j=0;j<n;j++) cerr << temp[j] << endl;
    return false;
}


int main()
{
    cin >> m >> n; cin.ignore();
    State sState;
    for (int i = 0; i < n; i++) {
        cin >> polje[i]; cin.ignore();
        temp[i] = polje[i];

        for(int j=0; j<m; j++) {
            if(polje[i][j]>='0' && polje[i][j]<='9') {
                sState.x[balls] = j;
                sState.y[balls] = i;
                sState.shotl[balls] = polje[i][j]-'0';
                sState.put[balls] = false;
                balls++;
            }
        }
    }


    dfs(sState);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(temp[i][j]=='v' || temp[i][j]=='>' || temp[i][j]=='<' || temp[i][j]=='^')
                cout << temp[i][j];
            else
                cout << '.';
        }
        cout << endl;
    }

    return 0;
}
