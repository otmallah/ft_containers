/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:33:49 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 03:01:23 by otmallah         ###   ########.fr       */
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
                if (key.second > prev->key.second)
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
            root = re_balance(key);
        }
        void    leftmost()
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->left_child)
                    std::cout << temp->key.second << std::endl;
                temp = temp->left_child;
            }
        }
        void      rightmost()
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->right_child)
                    std::cout << temp->key.second << std::endl;
                temp = temp->right_child;
            }
        }
        void    printInorder() { print(root); }
        bool    find(const  T & _key)
        {
            Node<T> *temp = root;
            if (temp == NULL)
                std::cout << "empty bst\n";
            while (temp)
            {
                if (temp->key.first == _key.first)
                {
                    std::cout << temp->key.second << " true -> " ;
                    return true;
                }
                if (_key.second > temp->key.second)
                    temp = temp->right_child;
                else if (_key.second < temp->key.second)
                    temp = temp->left_child;
            }
            return false;
        }
        size_t count (const T& _key) const
        {
            Node<T> *temp = root;
            if (temp == NULL)
                std::cout << "empty bst\n";
            while (temp)
            {
                if (temp->key.first == _key.first)
                {
                    std::cout << temp->key.second << " true -> " ;
                    return true;
                }
                if (_key.second > temp->key.second)
                    temp = temp->right_child;
                else if (_key.second < temp->key.second)
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
            Node<T> * node1 = root->right_child;
            Node<T> * node2 = node1->left_child;

            node1->left_child = root;
            root->right_child = node2;
            return node1;
        }
        Node<T> *rrotation()
        {
            Node<T> * node1 = root->left_child;
            Node<T> * node2 = node1->right_child;
            
            node1->right_child = root;
            root->left_child = node2 ;
            return node1;
        }
        Node<T> * re_balance(const T & data)
        {
            int balance = getBlanced();

            if (balance > 1 && data.second < root->left_child->key.second)
                return rrotation();
            if (balance < -1 && data.second > root->right_child->key.second)
                return lrotation();
            if (balance > 1 && data.second > root->right_child->key.second)
            {
                root->left_child = lrotation();
                return rrotation();
            }
            if (balance < -1 && data.second < root->left_child->key.second)
            {
                root->right_child = rrotation();
                return lrotation();
            }
            return root;
        }
        bool    empty() { if (height == 0) return true; return false;}
        size_t  size() const { return height; }
        bool    lower_bound(const T& _key)
        {
            Node<T> * prev = NULL;
            Node<T> *temp = root;
            if (temp == NULL)
                std::cout << "empty bst\n";
            while (temp)
            {
                prev = temp;
                if (_key.second > temp->key.second)
                    temp = temp->right_child;
                else if (_key.second < temp->key.second)
                    temp = temp->left_child;
                if (_key.first >= temp->key.first)
                {
                    std::cout << temp->key.second << " true -> " << std::endl;
                    return true;
                }
            }
            return false;
        }
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
    // std::map<char,int> mymap;
    // std::map<char,int>::iterator itlow,itup;

    // mymap['a']=20;
    // mymap['b']=40;
    // mymap['c']=60;
    // mymap['d']=80;
    // mymap['e']=100;

    // itlow=mymap.lower_bound ('b');  // itlow points to b
    // itup=mymap.upper_bound ('d');
    // std::cout << itlow->second << std::endl;

    // return 0;
    AVL_TREE<std::pair<char, int> > root;

    root.insert(std::make_pair('a', 20));
    root.insert(std::make_pair('b', 40));
    root.insert(std::make_pair('c', 60));
    root.insert(std::make_pair('d', 80));
    root.insert(std::make_pair('e', 100));
    //root.insert(std::make_pair('f', 49));

    root.lower_bound(std::make_pair('b', 0));

    root.printInorder();

}