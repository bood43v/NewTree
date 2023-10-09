/// Работа с деревом
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
	TreeNode<int>* root_6 = new TreeNode<int>();
	root_6->Insert(1);///   0
	root_6->Insert(0);///   
	int* arr = new int[2];

	int i = 0;

	root_6->AddToArrayLNR(arr, i);

	for (int i = 0; i < 2; i++)
	{
		cout << arr[i] << " ";
	}

	cout << root_6->Size() << endl;
	cout << root_6->Depth() << endl;



}

