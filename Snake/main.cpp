#include <cstdio>
#include <vector>
#include <ctime>
#include <graphics.h>
#include <cstdlib>
using namespace std;

const int BSIZE = 20;
const int WIN_HEIGHT = 30;
const int WIN_WIDTH = 40;
const float DELAY = 0.2;

int score=0;
int dir=4;  // 1 - gore, 2 - dolje, 3 - lijevo, 4 - desno
bool eaten=0, running=1, gameover=0;
char game[30][40];

struct body_part {
    int x, y;

    body_part() {}
    body_part(int x0, int y0) {
        x=x0; y=y0;
    }
};
vector<body_part> snake;

void init()
{
    srand(time(0));
    memset(game, '.', sizeof(game));

    char file[30];
    FILE* f;
    do
    {
        scanf("%s", &file);
        f=fopen(file, "r");
        if(f==NULL)
            printf("No such file!\n");
    } while(f==NULL);

    for(int i=0;i<WIN_HEIGHT;i++)
        fscanf(f, "%s", game[i]);
}

void drawGame()
{
    // BOUNDS
    setcolor(LIGHTGRAY);
    line(0, 0, WIN_WIDTH*BSIZE, 0);
    line(0, 0, 0, WIN_HEIGHT*BSIZE);
    line(0, WIN_HEIGHT*BSIZE, WIN_WIDTH*BSIZE, WIN_HEIGHT*BSIZE);
    line(WIN_WIDTH*BSIZE, 0, WIN_WIDTH*BSIZE, WIN_HEIGHT*BSIZE);


    // SCORE
    setcolor(WHITE);
    char scoretext[20]="Score: ";
    sprintf(scoretext+7, "%i", score);
    outtextxy(WIN_WIDTH*BSIZE-100, 5, scoretext);

    // SNAKE
    setcolor(LIGHTGREEN);
    setfillstyle(1, GREEN);
    for(int i=0;i<snake.size();i++)
    {
        if(i==snake.size()-1) { setcolor(6); setfillstyle(1, 6); }
        bar3d(snake[i].y*BSIZE, snake[i].x*BSIZE, snake[i].y*BSIZE+BSIZE, snake[i].x*BSIZE+BSIZE, 4, 1);
    }

    // TERRAIN
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(game[i][j]=='o')
            {
                setcolor(12);
                setfillstyle(1, RED);
                int x=j*BSIZE+BSIZE/2, y=i*BSIZE+BSIZE/2;
                circle(x, y, BSIZE/2);
                floodfill(x, y, 12);
            }
            else if(game[i][j]=='#')
            {
                setcolor(LIGHTGRAY);
                setfillstyle(1, DARKGRAY);
                bar3d(j*BSIZE, i*BSIZE, j*BSIZE+BSIZE, i*BSIZE+BSIZE, 4, 1);
            }
        }
    }
}

void setFood()
{
    int x, y;
    do
    {
        x=rand()%30, y=rand()%40;
    } while(game[x][y]!='.');
    game[x][y]='o';
}

void getKey()
{
    if(GetAsyncKeyState(VK_UP) && dir!=2) dir = 1;
    else if(GetAsyncKeyState(VK_DOWN) && dir!=1) dir = 2;
    else if(GetAsyncKeyState(VK_LEFT) && dir!=4) dir = 3;
    else if(GetAsyncKeyState(VK_RIGHT) && dir!=3) dir = 4;
    else if(GetAsyncKeyState(VK_ESCAPE)) running=0;
}

void gameLoop()
{
    getKey();

    int x=snake[snake.size()-1].x;
    int y=snake[snake.size()-1].y;
    body_part newBody;

    switch(dir) {
    case 1:
        newBody = body_part(x-1, y);
        if(newBody.x<0) newBody.x+=WIN_HEIGHT;
        break;
    case 2:
        newBody = body_part(x+1, y);
        if(newBody.x+1>WIN_HEIGHT) newBody.x=0;
        break;
    case 3:
        newBody = body_part(x, y-1);
        if(newBody.y<0) newBody.y+=WIN_WIDTH;
        break;
    case 4:
        newBody = body_part(x, y+1);
        if(newBody.y+1>WIN_WIDTH) newBody.y=0;
        break;
    }

    // Check death - u sebe
    for(int i=1;i<snake.size();i++)
        if(snake[i].x==newBody.x && snake[i].y==newBody.y)
            gameover=1;

    // Check death - block
    if(game[newBody.x][newBody.y]=='#')
        gameover=1;

    // Check eating
    if(game[newBody.x][newBody.y]=='o')
    {
        score++;
        eaten=1;
        game[newBody.x][newBody.y]='.';
        setFood();
    }

    // Update position
    if(!eaten) snake.erase(snake.begin());
    snake.push_back(newBody);

    eaten=0;
}

int main()
{
    init();
    initwindow(WIN_WIDTH*BSIZE+9, WIN_HEIGHT*BSIZE+14);

    setFood();
    snake.push_back(body_part(0, 0));
    snake.push_back(body_part(0, 1));
    snake.push_back(body_part(0, 2));

    clock_t start=clock(), current;

    while(running)
    {
        if(!gameover)
        {
            current=clock();

            if(float(current-start)/CLOCKS_PER_SEC >= DELAY)
            {
                gameLoop();

                cleardevice();
                drawGame();

                start=clock();
            }
        }
        else
        {
            cleardevice();
            setcolor(RED);
            outtextxy(WIN_WIDTH*BSIZE/2-25, WIN_HEIGHT*BSIZE/2-5, "Game Over");
            system("pause");
            running=0;
        }
    }
    closegraph();
    return 0;
}
