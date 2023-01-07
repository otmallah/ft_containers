/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:33:49 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/07 14:01:08 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        int     height;
    
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
                if (key > prev->key)
                    temp = temp->right_child;
                else if (key < prev->key)
                    temp = temp->left_child;
                else
                    break;
            }
            if (key > prev->key)
                prev->right_child = create(key);
            else if (key < prev->key)
                prev->left_child = create(key);
            height += 1;
            std::cout << getBlanced() << std::endl;
            root = re_balance(key);
        }
        void    leftmost()
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->left_child)
                    std::cout << temp->key << std::endl;
                temp = temp->left_child;
            }
        }
        void      rightmost()
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->right_child)
                    std::cout << temp->key << std::endl;
                temp = temp->right_child;
            }
        }
        void    printInorder() { print(root); }
        bool    search_key(const T& _key)
        {
            Node<T> *temp = root;
            if (temp == NULL)
                std::cout << "empty bst\n";
            while (temp)
            {
                if (temp->key == _key)
                {
                    std::cout << temp->key << " true -> " ;
                    return true;
                }
                if (_key > temp->key)
                    temp = temp->right_child;
                else if (_key < temp->key)
                    temp = temp->left_child;
            }
            return false;
        }
        int countHeight() { return _countHeight(root); }
        int _countHeight(Node<T> * temp)
        {
            if (!temp)
                return 0;
            int left_height = _countHeight(temp->left_child);
            int right_height = _countHeight(temp->right_child);
            if (left_height >= right_height )
                return left_height + 1;
            else
                return right_height + 1;
        }
        int     getBlanced()
        {
            if (!root)
                return (0);
            return _countHeight(root->left_child) - _countHeight(root->right_child);
        }
        Node<T> *lrotation()
        {
            std::cout << "lr = " << root->key << std::endl;
            Node<T> * node1 = root->right_child;
            Node<T> * node2 = node1->left_child;

            node1->left_child = root;
            root->right_child = node2;
            return node1;
        }
        Node<T> *rrotation()
        {
            std::cout << "rr = " << root->key << std::endl;
            Node<T> * node1 = root->left_child;
            Node<T> * node2 = node1->right_child;
            
            node1->right_child = root;
            root->left_child = node2 ;
            return node1;
        }
        Node<T> * re_balance(int data)
        {
            int balance = getBlanced();

            if (balance > 1 && data < root->left_child->key)
                return rrotation();
            if (balance < -1 && data > root->right_child->key)
                return lrotation();
            if (balance > 1 && data > root->right_child->key)
            {
                root->left_child = lrotation();
                return rrotation();
            }
            if (balance < -1 && data < root->left_child->key)
            {
                root->right_child = rrotation();
                return lrotation();
            }
            return root;
        }
    private :
        void    print(Node<T> * node) const
        {
            if (!node)
                return ;
            print(node->left_child);
            std::cout << "value : " << node->key << std::endl;
            print(node->right_child);
        }

};

int main()
{
    AVL_TREE<int> root;
    root.insert(5);
    root.insert(15);
    root.insert(1);
    root.insert(50);
    root.insert(500);
    root.insert(11);

    // root.printInorder();
    // std::cout << root.search_key(50) << std::endl;
    // root.rightmost();
    // root.printInorder();


    // std::cout << "height = " << root.countHeight() << std::endl;

}