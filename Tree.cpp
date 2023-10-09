/// Работа с деревом
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
	TreeNode<int>* root_3 = new TreeNode<int>();
	root_3->Insert(10);//          10  
	root_3->Insert(5);//       5        15
	root_3->Insert(2);///  2     6   12
	root_3->Insert(6);///
	root_3->Insert(15);///           
	root_3->Insert(12);///  

	cout << root_3->Search(11)->Data() << endl;
	root_3->Remove(5);




	cout << root_3->SearchParent(2)->Data();

}

