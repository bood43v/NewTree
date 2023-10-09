/// Класс узел дерева
/// @author Будаев Г.Б.
#pragma once

template <class T>
class TreeNode
{
private:
    TreeNode<T>* left;
    TreeNode<T>* right;
    T data;
public:


    /// Конструктор без параметров
    TreeNode() :
        data(NULL), left(nullptr), right(nullptr) {};

    /// Конструктор
    TreeNode(const T& data_, TreeNode<T>* left_ = nullptr, TreeNode<T>* right_ = nullptr) :
        data(data_), left(left_), right(right_) {};


    /// Вернуть указатель на левого потомка
    TreeNode<T>* Left() const {
        return left;
    };


    /// Вернуть указатель на правого потомка
    TreeNode<T>* Right() const {
        return right;
    };

    /// Установить левого потомка
    void SetLeft(TreeNode<T>* node_)
    {
        left = node_;
    }

    /// Установить прпвого потомка
    void SetRight(TreeNode<T>* node_)
    {
        right = node_;
    }

    /// Установить прпвого потомка
    void SetData(T data_)
    {
        data = data_;
    }

    /// Вернуть данные
    T Data() const
    {
        return data;
    }

    /// Поиск узла в дереве с возвратом указателя на узел, если он есть
    TreeNode<T>* Search(const T& item)
    {
        TreeNode<T>* t = this;

        while (t != nullptr)
        {
            if (item == t->Data())
                break;
            else
            {
                //root_ = t;
                if (item < t->Data())
                    t = t->Left();
                else
                    t = t->Right();
            }
        }
        return t;
    }

    /// Вставка узла
    void Insert(const T& key)
    {
        /// Eсли такого узла нет
        if (this->Search(key) == nullptr)
        {
            // t — текущий узел, parent — предыдущий узел
            TreeNode<T>* t = this, * parent = nullptr, * newNode;
            newNode = new TreeNode<T>(key);
            // Дойти до конца ветки
            while (t != nullptr)
            {
                // обновить указатель parent и идти направо или налево
                parent = t;
                if (key < t->Data())
                    t = t->Left();
                else
                    t = t->Right();
            }

            // если key меньше родительского узла, вставить в качестве левого сына
            if (key < parent->Data())
                parent->SetLeft(newNode);

            else
                // если key больше родительского узла
                parent->SetRight(newNode);
        }
    }

    /// Поиск минимального в ветке (или дереве)
    TreeNode<T>* FindMin() {
        TreeNode<T>* curr = this;
        if (curr == nullptr) return nullptr;
        while (curr->Left() != nullptr)
            curr = curr->Left();
        return curr;
    }

    TreeNode<T>* Successor() {
        T key = this->Data();
        TreeNode<T>* curr = this;
        if (curr == nullptr) return nullptr;
        if (curr->Right() != nullptr) {
            return curr->Right()->FindMin();
        }
        else {
            TreeNode<T>* successor = nullptr;
            TreeNode<T>* ancestor = this;
            while (ancestor != curr) {
                if (curr->Data() < ancestor->Data()) {
                    successor = ancestor;
                    ancestor = ancestor->Left();
                }
                else
                    ancestor = ancestor->Right();
            }
            return successor;
        }
    }

    /*/// Поиск узла в дереве с возвратом указателя на узел, если он есть
    TreeNode<T>* Search(const T& item, TreeNode<T>* root_)
    {
        TreeNode<T>* t = root_;
        root_ = nullptr;
        while (t != nullptr)
        {
            if (item == t->Data())
                break;
            else
            {
                root_ = t;
                if (item < t->Data())
                    t = t->Left();
                else
                    t = t->Right();
            }
        }
        return t;
    }*/

    void Remove(T key) {
        if (this->Search(key) != nullptr) {
            Delete(this->Search(key))
        }
    }

    /// Удаление узла
    void Delete() {
        delete this;
    }

    /// Удаление дерева
    void DeleteTree() {
        if(this->Left() != nullptr)
        this->Left()->DeleteTree();

        if (this->Right() != nullptr)
        this->Right()->DeleteTree();

        if (this != nullptr)
        this->Delete();
    }

    /// Добавление узла в массив
    void AddToArray(T arr[], int &i) {
        arr[i] = this->Data();
        i++;
    }

    /// Печать 
    void PrintNodeData()
    {
        if (this != nullptr)
        {
            std::cout << "Data of node: " << this->Data() << std::endl;
        }
        else
        {
            std::cout << "Node is null" << std::endl;
        }
    }

    /// Обход LNR и вывод в массив
    void AddToArrayLNR(T arr[], int& i)
    {
        if (this == nullptr)
            return;
        this->Left()->AddToArrayLNR(arr, i);
        this->AddToArray(arr, i);
        this->Right()->AddToArrayLNR(arr, i);
    }

    /// Обход NLR и вывод в массив
    void AddToArrayNLR(T arr[], int& i)
    {
        if (this == nullptr)
            return;
        this->AddToArray(arr, i);
        this->Left()->AddToArrayNLR(arr, i);
        this->Right()->AddToArrayNLR(arr, i);
    }

    /// Обход RLN и вывод в массив
    void AddToArrayRNL(T arr[], int& i)
    {
        if (this == nullptr)
            return;
        this->Right()->AddToArrayRNL(arr, i);
        this->AddToArray(arr, i);
        this->Left()->AddToArrayRNL(arr, i);
    }

    /// Количество листьев
    int CountNode(TreeNode<T>* node_) {
        int left, right;

        if (node_->Left() == nullptr && node_->Right() == nullptr)
            return 1;

        if (node_->Left() != nullptr)
            left = CountNode(this->Left());
        else left = 0;

        if (node_->Right() != nullptr)
            right = CountNode(node_->Right());
        else right = 0;

        return left + right + 1;
    }
};