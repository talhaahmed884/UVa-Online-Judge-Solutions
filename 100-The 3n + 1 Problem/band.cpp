#include <iostream>
#include <algorithm>
using namespace std;


int algo(int a);
int band(int, int);


int main()
{
    int i = 0, j = 0;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" "<<band(i, j)<<endl;
    }

    return 0;
}


int algo(int a)
{
    int cycle = 1;

    while (a!=1)
    {
        a = (a % 2 != 0) ? (a * 3 + 1) : (a = a / 2);

        cycle++;
    }

    return cycle;
}


int band(int val_one, int val_two)
{
    int minn = (val_one < val_two) ? val_one : val_two;   int maxx = (val_one > val_two) ? val_one : val_two;   int maxCycle = -1, cycle = 0;

    for(int a = minn; a <= maxx; a++)
    {
        cycle = algo(a);    maxCycle = (cycle < maxCycle) ? maxCycle : cycle;
    }

    return maxCycle;
}