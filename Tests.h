/// Тестирование методов класса дерева и узла дерева
/// @author Будаев Г.Б.
#pragma once
#include "TreeNode.h"
int main()
{

	TreeNode<int>* Node_1 = new TreeNode<int>();
	Node_1->SetData(5);
	TreeNode<int>* Node_2 = new TreeNode<int>(1);
	TreeNode<int>* Node_3 = new TreeNode<int>(3);

	return 0;
}