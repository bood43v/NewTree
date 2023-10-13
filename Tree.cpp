/// Работа с деревом
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BSTree<int>* t1 = new BSTree<int>();
    t1->Insert(5); /// вырожденное 5    
    t1->Insert(10);///                10
    t1->Insert(20);///                    20
    t1->Insert(30);///                        30    
    t1->Insert(40);///                            40
}

