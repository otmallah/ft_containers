#include <iostream>

template <typename T>
class Node
{
    public :
        T key;
        Node * left_child;
        Node * right_child;
        Node()
        {
            key = T();
            left_child = NULL;
            right_child = NULL;
        }
        Node(const T& data)
        {
            this->key = data;
            this->left_child = NULL;
            this->right_child = NULL;
        }
};

template <typename T>
class AVL_TREE
{

    private :
        Node<T> *root;
        size_t     height;
    
    public :
        AVL_TREE()
        {
            height = 0;
            root = new Node<T>;
        }
        Node<T> * create(T key)
        {
            Node<T> * new_node = new Node<T>(key);
            return new_node;
        }
        void insert(const T& key)
        {
            if (height == 0)
                root = create(key);
            Node<T> * prev = NULL;
            Node<T> * temp = root;
            while (temp)
            {
                prev = temp;
                if ( key.second > prev->key.second)
                    temp = temp->right_child;
                else if (key.second < prev->key.second)
                    temp = temp->left_child;
                else
                    break;
            }
            if (key.second > prev->key.second)
                prev->right_child = create(key);
            else if (key.second < prev->key.second)
                prev->left_child = create(key);
            height += 1;
            //root = re_balance(key);
        }
        void    printInorder() { print(root); }
    private :
        void    print(Node<T> * node) const
        {

            if (!node)
                return ;
            print(node->left_child);
            std::cout << "value : " << node->key.second << std::endl;
            print(node->right_child);
        }

};

#include <map>

int main()
{
    AVL_TREE<std::pair<int, int> > root;


    root.insert(std::make_pair(1, 2));
    root.insert(std::make_pair(3, 0));
    root.insert(std::make_pair(2, 6));
    root.insert(std::make_pair(9, 10));
    root.insert(std::make_pair(4, 13));
    root.insert(std::make_pair(10, 49));
    // root.insert(3);
    // root.insert(3);
    // root.insert(30);
    // root.insert(13);
    // root.insert(7);

    root.printInorder();


}
