#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void readFile();			//reads the matrix data from the file 'input.txt'
void MST(int**, int);			//Maximum spanning tree
bool conditionCheck(int**, int);				//checks if the specified condition is true
int min(int, int);				//gives the minimum of the two numbers
bool conditionCheck(int, int, vector<bool>);			//checks if the edge isn't already present in the graph


int main()
{
	readFile();

	exit(0);
}


void readFile()			//reads the matrix data from the file 'input.txt'
{
	int total_nodes = 0;				//total size of the matrix
	int total_cases = 0;					//total test cases present in the input file
	int** mat{};				//for storing the matrix

	cin >> total_cases;				//reading the total test casess			//input is taken from the user in the linear fashion

	for (int a = 0; a < total_cases; a++)			//untill the test cases has ended
	{
		cin >> total_nodes;			//getting the total size of the matrix

		mat = new int* [total_nodes+1];			//setting the size of the matrix

		for (int a = 0; a < total_nodes; a++)				//initializing the matrix
		{
			mat[a] = new int[total_nodes];

			for (int b = 0; b < total_nodes; b++)
			{
				cin >> mat[a][b];				//reading the size of the matrix
			}
		}

		cout << "Case #" << a + 1 << ": ";					//shows the case number
		if (conditionCheck(mat, total_nodes))						//checks for the condition on the matrix
		{
			cout << "Impossible\n";				//if the solution has impossible answer
		}
		else
		{
			cout << total_nodes - 1 << endl;					//displays the total nodes present in the graph

			MST(mat, total_nodes);					//creates the MST of the valid graph and display it

		}
	}

	return;
}


void MST(int** mat, int size)			//Maximum spanning tree
{
	vector<bool> inTree(size+1, false);				//becomes true for the index which is present in the tree
	inTree[0] = true;					//set the start of the Tree with true

	int edges = 0, max = -1, index_one=-1, index_two=-1;			//storage for num of edges, max_weight and the src and edges

	while (edges < size - 1)				//runs until the edges becomes size-1
	{
		max = -1, index_one = -1, index_two = -1;			//resets the value of indexes and max_weight
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
			{
				if (mat[a][b] > max)				//if the edge with max_weight has been found
				{
					if (conditionCheck(a, b, inTree))			//checks if the edge already exist
					{
						max = mat[a][b];			//store the edges weight
						index_one = a, index_two = b;				//store the sources and edges
					}
				}
			}
		}

		if (index_one != -1 && index_two != -1)			//if the new indexes have been found
		{
			inTree[index_one] = true;		inTree[index_two] = true;				//sets the inTree value to true
			cout << index_one << " " << index_two << " " << max << endl;
			edges++;			//increase the counter for the edges in the tree
		}
	}

	return;
}


bool conditionCheck(int** mat1, int size) 			//checks if the specified condition is true
{
	for (int a = 0; a < size; a++)		//loops for checking if the connection to each edge has the samw weight
	{
		for (int b = a+1; b < size; b++)
		{
			for (int c = b + 1; c < size; c++)
			{
				if ((min(mat1[a][b], mat1[b][c]) > mat1[a][c]) || (min(mat1[a][c], mat1[b][c]) > mat1[a][b]) || (min(mat1[a][b], mat1[a][c]) > mat1[b][c]))		//condition that checks if the graph has all the valid
				{
					return true;
				}
			}
		}
	}

	return false;				//returns false if the graph is alright and doesn't follow the condition
}


int min(int a, int b)				//gives the minimum of the two numbers
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}


bool conditionCheck(int a, int b, vector<bool> inTree)			//checks if the edge isn't already present in the graph
{
	if (a == b)		//if the indexes are same
	{
		return false;
	}
	else if ((!inTree[a] && !inTree[b]) || (inTree[a] && inTree[b]))				//if the edges haven;t been added in the tree at all
	{
		return false;
	}
	else		//retunrs true if one of the edge is present in the tree
	{
		return true;
	}
}

