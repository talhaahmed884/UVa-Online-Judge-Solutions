#include <iostream>
#include <vector>
#include <string>
using namespace std;


void BGC(vector<int>*, vector<int>*, vector<int>*, int*, string*);
void BCG(vector<int>*, vector<int>*, vector<int>*, int*, string*);


int main()
{
    vector<int> bin_one, bin_two, bin_three;
    int int_one, int_two, int_three, int_four, int_five, int_six, int_seven, int_eight, int_nine, minSum = 0;
    string order;

    while(cin>>int_one>>int_two>>int_three>>int_four>>int_five>>int_six>>int_seven>>int_eight>>int_nine)
    {
        bin_one.clear();    bin_two.clear();    bin_three.clear();

        bin_one.push_back(int_one);     bin_one.push_back(int_two);     bin_one.push_back(int_three);
        bin_two.push_back(int_four);    bin_two.push_back(int_five);    bin_two.push_back(int_six);
        bin_three.push_back(int_seven);   bin_three.push_back(int_eight); bin_three.push_back(int_nine);

        int minSum = -1;    string order;
        BGC(&bin_one, &bin_two, &bin_three, &minSum, &order);
        BCG(&bin_one, &bin_two, &bin_three, &minSum, &order);
        cout<<order<<" "<<minSum<<endl;
    }

    return 0;
}


void BGC(vector<int>* bin_one, vector<int>* bin_two, vector<int>* bin_three, int* minSum, string* order)
{
    int sum = 0;

    for(int a=0; a<3; a++)
    {
        if(a == 0)
        {
            sum = bin_one[0][1]+bin_one[0][2]+bin_two[0][0]+bin_two[0][2]+bin_three[0][0]+bin_three[0][1];
            *minSum = sum;  *order = "BGC";
        }
        else if(a == 1)
        {
            sum = bin_one[0][0]+bin_one[0][2]+bin_two[0][0]+bin_two[0][1]+bin_three[0][1]+bin_three[0][2];
            if(*minSum != sum)
            {
                *minSum = min(*minSum, sum);
                if(*minSum == sum)
                {
                    *order = "GCB";
                }
            }
            else
            {
                string temp = "GCB";    *order = min(temp, *order);
            }   
        }
        else if(a == 2)
        {
            sum = bin_one[0][0]+bin_one[0][1]+bin_two[0][1]+bin_two[0][2]+bin_three[0][0]+bin_three[0][2];
            if(*minSum != sum)
            {
                *minSum = min(*minSum, sum);
                if(*minSum == sum)
                {
                    *order = "CBG";
                }
            }
            else
            {
                string temp = "CBG";        *order = min(temp, *order);
            }
        }
    }
    
    return;
}


void BCG(vector<int>* bin_one, vector<int>* bin_two, vector<int>* bin_three, int* minSum, string* order)
{
    int sum = 0;

    for(int a=0; a<3; a++)
    {
        if(a == 0)
        {
            sum = bin_one[0][1]+bin_one[0][2]+bin_two[0][0]+bin_two[0][1]+bin_three[0][0]+bin_three[0][2];
            if(*minSum != sum)
            {
                *minSum = min(sum, *minSum);
                if(*minSum == sum)
                {
                    *order = "BCG";
                }
            }
            else
            {
                string temp = "BCG";        *order = min(temp, *order);   
            }
        }
        else if(a == 1)
        {
            sum = bin_one[0][0]+bin_one[0][1]+bin_two[0][0]+bin_two[0][2]+bin_three[0][1]+bin_three[0][2];
            if(*minSum != sum)
            {
                *minSum = min(sum, *minSum);
                if(*minSum == sum)
                {
                    *order = "CGB";
                }
            }
            else
            {
                string temp = "CGB";    *order = min(temp, *order);
            }
            
        }
        else if(a == 2)
        {
            sum = bin_one[0][0]+bin_one[0][2]+bin_two[0][1]+bin_two[0][2]+bin_three[0][0]+bin_three[0][1];
            if(*minSum != sum)
            {
                *minSum = min(*minSum, sum);
                if(*minSum == sum)
                {
                    *order = "GBC";
                }
            }
            else
            {
                string temp = "GBC";        *order = min(temp, *order);
            }
        }
    }
    
    return;
}

