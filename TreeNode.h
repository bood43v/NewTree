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
    /// Добавление узла в массив
    void AddToArray(T arr[], int& i) {
        arr[i] = this->Data();
        i++;
    }
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
    TreeNode<T>* Search(const T& key)
    {
        TreeNode<T>* t = this;
        
        if (t == nullptr) return nullptr;

        while (t != nullptr)
        {
            if (key == t->Data())
                break;
            else
            {
                //root_ = t;
                if (key < t->Data())
                    t = t->Left();
                else
                    t = t->Right();
            }
        }
        return t;
    }

    /// todo: Не работает в вырожденном дереве

    /// Поиск узла в дереве с возвратом указателя на узел, если он есть
    TreeNode<T>* SearchParent(const T& key)
    {
        TreeNode<T>* t = this;
        TreeNode<T>* parent = nullptr;

        if (t->Search(key) == nullptr) return nullptr;
        if (t->Data() == key) return nullptr;

        while (t != nullptr)
        {
            if ((t->Left() != nullptr && key == t->Left()->Data()) || (t->Right() != nullptr && key == t->Right()->Data()) )
            {
                parent = t;
                break;
            }  
            else
            {
                if (key < t->Data())
                   t = t->Left();
                else
                   t = t->Right();
            }
        }
        
        return parent;
    }
   /* root_1->Insert(5);/// вырожденное 5    
    root_1->Insert(10);///               10
    root_1->Insert(20);///                   20
    root_1->Insert(30);///                       30    
    root_1->Insert(40);///                      40
     */

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
            // если узлов нет, то вставить в качестве корневого узла
            if (parent->Data() == NULL)
                this->SetData(newNode->Data());
            // если key меньше родительского узла, вставить в качестве левого сына
            else if (key < parent->Data())
                parent->SetLeft(newNode);

            else
                // если key больше родительского узла
                parent->SetRight(newNode);
        }
    }


    /// <summary>
    /// Количество узлов - размер дерева
    /// </summary>
    /// <returns></returns>
    int Size()
    {
        int left, right;
        TreeNode<T>* node = this;
        if (node->Left() == nullptr && node->Right() == nullptr)
            return 1;


        if (node->Left() != nullptr)
            left = node->Left()->Size();
        else left = 0;

        if (node->Right() != nullptr)
            right = node->Right()->Size();
        else right = 0;

        return left + right + 1;
    }

    /// Глубина дерева
    int Depth() {
        TreeNode<T>* t = this;
        int depthLeft, depthRight, depth;
        /// Если дерево пустое
        if (t == nullptr) {
            depth = -1;
        }
        else {
            depthLeft = t->Left()->Depth();
            depthRight = t->Right()->Depth();
            depth = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
        }
        return depth;
    }

    /// Поиск минимального в ветке (или дереве)
    TreeNode<T>* FindMin() {
        TreeNode<T>* curr = this;
        if (curr == nullptr) return nullptr;
        while (curr->Left() != nullptr)
            curr = curr->Left();
        return curr;
    }

    /// Поиск максимального в ветке (или дереве)
    TreeNode<T>* FindMax() {
        TreeNode<T>* curr = this;
        if (curr == nullptr) return nullptr;
        while (curr->Right() != nullptr)
            curr = curr->Right();
        return curr;
    }

    /// Следующий наибольший узел
    TreeNode<T>* Successor(const T &key) {
        /// текущий узел
        TreeNode<T>* curr = this->Search(key);
        /// если пустой
        if (curr == nullptr) return nullptr;
        /// если есть правый потомок ищем его самого левого потомка
        if (curr->Right() != nullptr) {
            return curr->Right()->FindMin();
        }
        /// если нет
        else {
            TreeNode<T>* successor = nullptr;
            /// то запоминаем предка
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

    TreeNode<T>* Remove(TreeNode<T>* root, const T &key) {
        TreeNode<T>* parent;

        /// Если пусто
        if (root == nullptr) return nullptr;

        if (key < root->Data()) {
            /// Рекурсивно удаляем значение из левого поддерева
            root->SetLeft(Remove(root->Left(), key));
        }
        else if (key > root->Data()) {
            /// Рекурсивно удаляем значение из правого поддерева
            root->SetRight(Remove(root->Right(), key));
        }
        /// Найден узел, который нужно удалить
        else {
            if (root->Left() == nullptr && root->Right() == nullptr) {
                /// Узел не имеет потомков
                delete root;
                root = nullptr;
            }
            else if (root->Left() == nullptr) {
                /// Узел имеет только правого потомка
                parent = root;
                root = root->Right();
                delete parent;
            }
            else if (root->Right() == nullptr) {
                /// Узел имеет только левого потомка
                parent = root;
                root = root->Left();
                delete parent;
            }
            else {
                // Узел имеет оба потомка
                TreeNode<T>* parent = root->Right()->FindMin();
                root->SetData(parent->Data());
                root->SetRight(Remove(root->Right(), parent->Data()));
            }
        }
        return root;
    }

    /// Удаление узла
    void Delete() {
        delete this;
        //this = nullptr;
    }

    /// Удаление дерева
    void DeleteTree(TreeNode<T>* root) {
        if (root == nullptr)
            return;

        if (root->Left() != nullptr)
            DeleteTree(root->Left());

        if (root->Right() != nullptr)
            DeleteTree(root->Right());

        delete root;
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
    void AddToArrayLNR(T arr[], int &i)
    {
        if (this != nullptr)
        {
            this->Left()->AddToArrayLNR(arr, i);
            this->AddToArray(arr, i);

            this->Right()->AddToArrayLNR(arr, i);
        }
    }

    /// Обход NLR и вывод в массив
    void AddToArrayNLR(T arr[], int &i)
    {
        if (this == nullptr)
            return;
        this->AddToArray(arr, i);
        this->Left()->AddToArrayNLR(arr, i);
        this->Right()->AddToArrayNLR(arr, i);
    }

    /// Обход RLN и вывод в массив
    void AddToArrayRNL(T arr[], int &i)
    {
        if (this == nullptr)
            return;
        this->Right()->AddToArrayRNL(arr, i);
        this->AddToArray(arr, i);
        this->Left()->AddToArrayRNL(arr, i);
    }

    /// Удвоение значения всех узлов
    template <class T>
    void Double(TreeNode<T>* root) {
        if (root == nullptr) return;
        root->SetData(root->Data()*2);
        root->Left()->Double(root->Left());
        root->Right()->Double(root->Right());
    }

    /// Копирование дерева
    TreeNode<T>* CopyTree(const TreeNode<T>* root)
    {
        /// root - указатель на текущий узел
        if (root == nullptr)
            return nullptr;

        /// Создаем новое дерево и задаем ему значение корня первого дерева
        TreeNode<T>* newRoot = new TreeNode<T>(root->Data());
        /// Рекурсивно вызываем метод для левого и правого поддерева
        newRoot->SetLeft(CopyTree(root->Left()));
        newRoot->SetRight(CopyTree(root->Right()));

        return newRoot;
    }
};


//void Remove(T key) {
//    TreeNode<T>* parent;
//    TreeNode<T>* root = this;
//    /// Если дерево пустое
//    if (root == nullptr) return /*nullptr*/;
//    if (key < root->Data()) {
//        /// Удаление в левом поддереве
//        root->Left()->Remove(key);
//    }
//    else if (key > root->Data()) {
//        /// Удаление в правом поддереве
//        root->Right()->Remove(key);
//    }
//    /// Если узел найден
//    else {
//        /// Если нет потомков
//        if (root->Left() == nullptr && root->Right() == nullptr) {
//            root->Delete();
//            //root = nullptr;
//        }
//        /// Имеет только левого потомка
//        else if (root->Left() != nullptr && root->Right() == nullptr) {
//            root->SearchParent(key)->SetLeft(root->Left());
//            root->Delete();
//        }
//        /// Имеет только правого потомка
//        else if (root->Right() != nullptr && root->Left() != nullptr) {
//            root->SearchParent(key)->SetRight(root->Right());
//            root->Delete();
//        }
//        /// Имеет оба потомка
//        else {
//            TreeNode<T>* successor = root->Successor();
//            root = successor;
//            successor->Remove();
//        }
//    }
//    //return root;
//}



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