/// Работа с деревом
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
	TreeNode<int>* root = new TreeNode<int>();
	root->SetData(2);
	TreeNode<int>* Node_2 = new TreeNode<int>(1);/////         2
	root->SetLeft(Node_2);							////	1       3
	TreeNode<int>* Node_3 = new TreeNode<int>(3);, 
	root->SetRight(Node_3);
	
	TreeNode<int>* Node_4 = new TreeNode<int>(6);
	Node_3->SetRight(Node_4);

	TreeNode<int>* Node_5 = new TreeNode<int>(7);
	Node_4->SetRight(Node_5);

	int* arr = new int[3];

	int i = 0;

	root->AddToArrayLNR(arr, i);

	//root->Delete();
	//Node_2->Delete();
	//Node_3->Delete();

	//root->AddToArray(arr, 0);
	//Node_2->AddToArray(arr, 1);
	//Node_3->AddToArray(arr, 2);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	cout << " Count= " << root->CountNode(root) << endl;
	//if (root->Search(1, root) != nullptr)
	//	cout << root->Search(1, root)->Data();
	//else cout << "Node not found" << endl;
	int x = 7;
	if (root->Search(x) != nullptr)
		cout << root->Search(x)->Data() << endl;
	else cout << "Node not found" << endl;

	int* arr2 = new int[6];

	int j = 0;


	int y = 4;
	root->Insert(y);
	cout << endl;
	root->AddToArrayLNR(arr2, j);
	for (int i = 0; i < 6; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << root->Search(6)->FindMin()->Data() << endl;
	cout << root->Search(4)->Successor()->Data() << endl;
	root->DeleteTree();

	//root->AddToArrayLNR(arr, i);
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << arr[i] << " ";
	//}


}

