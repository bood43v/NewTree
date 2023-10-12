/// Работа с деревом
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
	TreeNode<int>* root_1 = new TreeNode<int>();
	root_1->Insert(5);/// вырожденное 5    
	root_1->Insert(10);///               10
	root_1->Insert(20);///                   20
	root_1->Insert(30);///                       30    
	root_1->Insert(40);///                           40

	



	cout << "COPY:" << endl;
	TreeNode<int>* root_2 = root_1->CopyTree(root_1);
	
	//root_2->CopyTree(root_1);

	int* arr = new int[root_2->Size()];
	int i = 0;

	root_2->AddToArrayLNR(arr, i);

	for (int i = 0; i < root_2->Size(); i++)
	{
		cout << arr[i] << " ";
	}

}

