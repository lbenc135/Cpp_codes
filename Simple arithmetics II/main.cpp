#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        long long a,b,temp;
        char sign;
        cin >> a >> sign >> b;
        switch(sign){
        case '+':
            temp=a+b;
            break;
        case '-':
            temp=a-b;
            break;
        case '/':
            temp=a/b;
            break;
        case '*':
            temp=a*b;
            break;
        }

        cin >> sign;
        while(sign!='=')
        {
            cin >> b;
            switch(sign){
            case '+':
                temp+=b;
                break;
            case '-':
                temp-=b;
                break;
            case '/':
                temp/=b;
                break;
            case '*':
                temp*=b;
                break;
            }
            cin >> sign;
        }
        cout << temp << endl;
    }
}
