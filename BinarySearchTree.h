/// ����� BinarySearchTree ��������� ������
/// @author ������ �.�.
#pragma once
#include "TreeNode.h"

/// <summary>
/// ��������� ����� �������� ������ ������, ������������ ����� ���� ������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class BSTree
{
private:
    TreeNode<T>* root;/// ������
    TreeNode<T>* curr;/// ������� ����
   

public:
    /// ����������� ��� ����������
    BSTree() {
        root = nullptr;
        curr = nullptr;
    };

    /// ����������� ��� ����������
    BSTree(const T& node) {
        this->Insert(node);
    };

    /// ����������
    ~BSTree() {};

    /// ������� ������
    T Data(TreeNode<T>* curr) const
    {
        return curr->Data();
    }

    /// ������� ������
    TreeNode<T>* Root() {
        return root;
    }

    /// ���������� ������
    void SetRoot(TreeNode<T>* newRoot) {
        root = newRoot;
    }

    /// �������
    void Insert(const T& key) {
        root->Insert(key);
    }
    
    /// �����
    TreeNode<T>* Search(const T& key) {
        return root->Search(key);
    }

    /// ������
    int Size() {
        return root->Size();
    }

    /// �������
    int Depth() {
        return root->Depth();
    }

    /// ����� �����������
    TreeNode<T>* FindMin() {
        return root->FindMin();
    }

    /// ����� ������������
    TreeNode<T>* FindMax() {
        return root->FindMax();
    }

    /// ��������� ���������� ��� ����
    TreeNode<T>* Successor(const T& key) {
        return root->Successor(key); 
    }

    /// �������� ����
    TreeNode<T>* Remove(const T& key) {
        return root->Remove(root, key);
    }

    /// ������� � ������ LNR
    void AddToArrayLNR(T arr[]) {
        int i = 0;
        root->AddToArrayLNR(arr,i);
    }

    /// ���������� ������
    BSTree<T>* CopyTree() {
        BSTree<T>* copiedTree = new BSTree<T>();
        copiedTree->SetRoot(root->CopyTree());
        return copiedTree;
    }

    /// �������� �������� ���� �����
    void Double() {
        root->Double();
    }
};