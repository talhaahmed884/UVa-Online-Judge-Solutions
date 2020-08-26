#include <iostream>
#include <list>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <algorithm>
using namespace std;
using namespace boost;


void printBlocks(vector<list<int>>, int size);
void band(vector<list<int>>*, int);
int findBlocks(vector<list<int>>, int, int);
void moveOnto(vector<list<int>>*, int, int, int);
void moveOver(vector<list<int>>*, int, int, int);
void pileOnto(vector<list<int>>*, int, int, int);
void pileOver(vector<list<int>>*, int, int, int);


int main()
{
    int size;    cin>>size;     cin.ignore();

    vector<list<int>> blocks;

    for(int a=0; a<size; a++)
    {
        list<int> temp;     temp.push_back(a);      blocks.push_back(temp);
    }

    band(&blocks, size);

    printBlocks(blocks, size);

    return 0;
}


void printBlocks(vector<list<int>> blocks, int size)
{
    for(int a=0; a<size; a++)
    {
        list<int> temp;     temp = blocks[a];      cout<<a<<":";
        
        while(!temp.empty())
        {
            cout<<" "<<temp.front();    temp.pop_front();
        }

        cout<<endl;
    }

    return;
}


void band(vector<list<int>>* blocks, int size)
{
    string input;
    while (1)
    {
        getline(cin, input);

        if(input == "quit")
        {
            return;
        }
        else
        {
            vector<string> output;
            split(output, input, is_any_of(" "));

            if(output[1] != output[3] and findBlocks(blocks[0], size, stoi(output[1])) != findBlocks(blocks[0], size, stoi(output[3])))
            {
                if(output[0] == "move")
                {
                    if (output[2] == "onto")
                    {
                        moveOnto(blocks, size, stoi(output[1]), stoi(output[3]));
                    }
                    else if(output[2] == "over")
                    {
                        moveOver(blocks, size, stoi(output[1]), stoi(output[3]));
                    }
                }
                else if(output[0] == "pile")
                {
                    if (output[2] == "onto")
                    {
                        pileOnto(blocks, size, stoi(output[1]), stoi(output[3]));
                    }
                    else if(output[2] == "over")
                    {
                        pileOver(blocks, size, stoi(output[1]), stoi(output[3]));
                    }
                }
            }
        }
    }

    return;
}


void moveOnto(vector<list<int>>* blocks, int size, int a, int b)
{    
    if(!blocks[0][a].empty())
    {
        while(!blocks[0][a].empty())
        {
            if(blocks[0][a].front() != a)
            {
                blocks[0][blocks[0][a].front()].push_back(blocks[0][a].front());    blocks[0][a].pop_front();
            }
            else
            {
                blocks[0][a].pop_front();
            }
        }
    }
    else
    {
        int index = findBlocks(blocks[0], size, a);
        
        list<int> temp;
        while(blocks[0][index].front() != a)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front(); 
        }
        blocks[0][index].pop_front();

        while(!blocks[0][index].empty())
        {
            blocks[0][blocks[0][index].front()].push_back(blocks[0][index].front());    blocks[0][index].pop_front(); 
        }

        blocks[0][index] = temp;
    }
    
    if(!blocks[0][b].empty())
    {
        while(!blocks[0][b].empty())
        {
            if(blocks[0][b].front() != b)
            {
                blocks[0][blocks[0][b].front()].push_back(blocks[0][b].front());    blocks[0][b].pop_front();
            }
            else
            {
                blocks[0][b].pop_front();
            }
        }

        blocks[0][b].push_back(b);      blocks[0][b].push_back(a);
    }
    else
    {
        int index = findBlocks(blocks[0], size, b);

        list<int> temp;
        while(blocks[0][index].front() != b)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front(); 
        }
        temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front();

        while(!blocks[0][index].empty())
        {
            blocks[0][blocks[0][index].front()].push_back(blocks[0][index].front());    blocks[0][index].pop_front(); 
        }

        blocks[0][index] = temp;    blocks[0][index].push_back(a);
    }

    return;
}


int findBlocks(vector<list<int>> blocks, int size, int b)
{
    for(int a=0; a<size ;a++)
    {
        list<int>::iterator it = find(blocks[a].begin(), blocks[a].end(), b);
        if(blocks[a].end() != it)
        {
            return a;
        }        
    }

    return -1;
}


void moveOver(vector<list<int>>* blocks, int size, int a, int b)
{
    if(!blocks[0][a].empty())
    {
        while(!blocks[0][a].empty())
        {
            if(blocks[0][a].front() != a)
            {
                blocks[0][blocks[0][a].front()].push_back(blocks[0][a].front());    blocks[0][a].pop_front();
            }
            else
            {
                blocks[0][a].pop_front();
            }
        }
    }
    else
    {
        int index = findBlocks(blocks[0], size, a);
        
        list<int> temp;
        while(blocks[0][index].front() != a)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front(); 
        }
        blocks[0][index].pop_front();

        while(!blocks[0][index].empty())
        {
            blocks[0][blocks[0][index].front()].push_back(blocks[0][index].front());    blocks[0][index].pop_front(); 
        }

        blocks[0][index] = temp;
    }
    
    if(!blocks[0][b].empty())
    {
        blocks[0][b].push_back(a);
    }
    else
    {
        blocks[0][findBlocks(blocks[0], size, b)].push_back(a);
    }

    return;
}


void pileOnto(vector<list<int>>* blocks, int size, int a, int b)
{
    if(!blocks[0][b].empty())
    {
        while(!blocks[0][b].empty())
        {
            if(blocks[0][b].front() != b)
            {
                blocks[0][blocks[0][b].front()].push_back(blocks[0][b].front());    blocks[0][b].pop_front();
            }
            else
            {
                blocks[0][b].pop_front();
            }
        }

        blocks[0][b].push_back(b);
    }
    else
    {
        int index = findBlocks(blocks[0], size, b);

        list<int> temp;
        while(blocks[0][index].front() != b)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front();
        }
        temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front();

        while(!blocks[0][index].empty())
        {
            blocks[0][blocks[0][index].front()].push_back(blocks[0][index].front());    blocks[0][index].pop_front(); 
        }

        blocks[0][index] = temp;    b = index;
    }

    if(!blocks[0][a].empty())
    {
        while(!blocks[0][a].empty())
        {
            blocks[0][b].push_back(blocks[0][a].front());  blocks[0][a].pop_front();
        }
    }
    else
    {
        int index = findBlocks(blocks[0], size, a);

        list<int> temp;
        while(blocks[0][index].front() != a)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front(); 
        }

        while(!blocks[0][index].empty())
        {
            blocks[0][b].push_back(blocks[0][index].front());  blocks[0][index].pop_front();
        }
        
        blocks[0][index] = temp;
    }
    
    return;
}


void pileOver(vector<list<int>>* blocks, int size, int a, int b)
{ 
    if(blocks[0][b].empty())
    {
        b = findBlocks(blocks[0], size, b);
    }
    
    if(!blocks[0][a].empty())
    {
        while(!blocks[0][a].empty())
        {
            blocks[0][b].push_back(blocks[0][a].front());       blocks[0][a].pop_front();
        }
    }
    else
    {
        int index = findBlocks(blocks[0], size, a);

        list<int> temp;
        while(blocks[0][index].front() != a)
        {
            temp.push_back(blocks[0][index].front());   blocks[0][index].pop_front(); 
        }

        while(!blocks[0][index].empty())
        {
            blocks[0][b].push_back(blocks[0][index].front());       blocks[0][index].pop_front();
        }

        blocks[0][index] = temp;
    }

    return;
}

