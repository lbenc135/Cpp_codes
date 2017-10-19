#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define TABLE_NAME "tablica.csv"
#define WINCLASS "TfuRacStCakU"
#define WINNAME NULL
#define WINCHILD1 "TPanel"
#define WINCHILD2 "TRxDBCalcEdit"

HWND hwndClass;     // Maska 2 - TPanel

const int numItems = 4;
const string itemName[] = {"Elektricna energija", "Vodne usluge", "Toplinska energija", "Ostali troskovi"};
const int itemNum[] = {6, 4, 2, 8};

fstream fstr;
int rows=0, cols=0;
string data[500][15];
string restoreS[7];

string splitResult[15];
int splitString(string s, char c=';')
{
    int it=0;
    string temp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==c)
        {
            splitResult[it++]=temp;
            temp="";
        }
        else if(s[i]==',' && it>=2)
            temp+='.';
        else
            temp+=s[i];
    }
    splitResult[it++]=temp;

    return it;
}

string to_string(double a)
{
    char buf[35];
    sprintf(buf, "%.2f", a);
    return string(buf);
}



void ispisTablice()
{
    for(int i=0;i<rows-1;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout << data[i][j] << "\t\t";
        }
        cout << endl;
    }
}

void analyseTable()
{
    // Split csv string data
    for(int i=0;i<rows;i++)
    {
        cols=splitString(data[i][0]);
        for(int j=0;j<cols;j++)
            data[i][j]=splitResult[j];
    }
}

void loadTable()
{
    for( ; getline(fstr, data[rows][0]) ; rows++)
        ;
    analyseTable();
    cout << "Tablica ucitana." << endl;
}

void initHandle()
{
    HWND hwndWindow = FindWindow(WINCLASS, WINNAME);

	if(hwndWindow != NULL)
    {
        hwndClass = FindWindowEx(hwndWindow, NULL, WINCHILD1, NULL);
        hwndClass = FindWindowEx(hwndWindow, hwndClass, WINCHILD1, NULL);

		if(hwndClass == NULL)
            cerr << "Class not found!" << endl;
	}
	else cerr << "Window not found!" << endl;
}

void injectInProgram(string className, string val, int N=0)
{
    HWND hwndControl = FindWindowEx(hwndClass, NULL, className.c_str(), NULL);
    for(int i=0;i<N;i++)
        hwndControl = FindWindowEx(hwndClass, hwndControl, className.c_str(), NULL);

    if(hwndControl != NULL)
    {
        SendMessage(hwndControl, EM_SETSEL, 0, -1);
        for(int i=0;i<val.length();i++)
            SendMessage(hwndControl, WM_CHAR, val[i], NULL);
    }
    else cerr << "Control not found!" << endl;
}



int main(int argc, char *argv[])
{
    fstr.open(TABLE_NAME);
    if(!fstr.good())
    {
        cout << "Ucitavanje tablice nije uspjelo! Provjerite je li 'tablica.csv' u istom folderu kao i ovaj program." << endl;
        system("pause");
        return 0;
    }
    loadTable();
    fstr.close();


    cout << "Unesite vrijednosti za elektricnu energiju, vodu, toplinsku energiju i ostale troskove tim redom:\n";
    double vals[4];
    cin >> vals[0] >> vals[1] >> vals[2] >> vals[3];

    while(true)
    {
        cout << "Unesite broj organizacije i stavke (1=struja, 2=voda, 3=toplina, 4=ostalo):\n";
        int br, st;
        cin >> br >> st;

        initHandle();

        if(br>rows || br<=0) cout << "Pogresan unos!" << endl;
        else
        {
            char buf[150];

            cout << data[br-1][0] << " " << data[br-1][1] << endl;

            if(vals[--st])
            {
                string arg = "%i.) " + itemName[st] + ":\n    (%.2f x %.2f" + (st==2?")":"%%)");
                sprintf(buf, arg.c_str(), st+1, vals[st], atof(data[br-1][itemNum[st]].c_str()));
                string napomena=string(buf);
                cout << napomena << "\t\t";

                double val = vals[st] * atof(data[br-1][itemNum[st]].c_str());
                if(st!=2) val/=100;
                cout << "Value: " << val << endl << endl;

                injectInProgram("TMCSDBMemo", napomena);
                injectInProgram("TRxDBCalcEdit", to_string(val), 4);
            }
        }
    }
}
