/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:33:49 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/11 16:56:57 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../utils/utils.hpp"


template <typename T>
class Node
{
    public :
        T key;
        Node * left_child;
        Node * right_child;
        Node()
        {
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

template <typename T, class key_type>
class AVL_TREE
{
    private :
        Node<T> *root;
        size_t     height;
    
    public :
        typedef typename ft::__map_iterator<Node<T>, T> map_iterator;
    public :
        AVL_TREE()
        {
            height = 0;
            root = new Node<T>;
        }
        ~AVL_TREE()
        {
            height = 0;
            deallocate(root);
        }
        void deallocate(Node<T> *bst)
        {
            if (!bst)
                return ;
            deallocate(bst->left_child);
            deallocate(bst->right_child);
            delete bst;
        }
        map_iterator    begin() 
        {
            return map_iterator(root);
        }
        map_iterator    end() const
        {
            map_iterator it = rightmost();
            return it;
        }
        Node<T>* get() const { return root; }
        Node<T> * create(T key)
        {
            Node<T> * new_node = new Node<T>(key);
            return new_node;
        }
        std::pair<map_iterator, bool> insert(const T& key)
        {
            std::pair<map_iterator, bool> result;
            if (height == 0)
            {
                root = create(key);
                result.first = map_iterator(root);
                result.second = true;
                height += 1;
                return result;
            }
            Node<T> * prev = NULL;
            Node<T> * temp = root;
            while (temp)
            {
                prev = temp;
                if (key.first > prev->key.first)
                    temp = temp->right_child;
                else if (key.first < prev->key.first)
                    temp = temp->left_child;
                else
                    break;
            }
            if (key.first > prev->key.first)
            {
                height += 1;
                prev->right_child = create(key);
                result.first = map_iterator(prev->right_child);
                result.second = true;
            }
            else if (key.first < prev->key.first)
            {
                height += 1;
                prev->left_child = create(key);
                result.first = map_iterator(prev->left_child);
                result.second = true;
            }
            else
            {
                result.first = map_iterator(root);
                result.second = false;
            }
            root = re_balance(key);
            return result;
        }
        Node<T>*    leftmost()
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->left_child)
                {
                    return temp;
                }
                temp = temp->left_child;
            }
            return root;
        }
        Node<T>*      rightmost() const
        {
            Node<T> * temp = root;
            while (temp)
            {
                if (!temp->right_child)
                {
                    return temp;
                }
                temp = temp->right_child;
            }
            return root;
        }
        void            printInorder() { print(root); }
        map_iterator    find(const  key_type & _key)
        {
            Node<T> *temp = root;
            if (temp == NULL)
                std::cout << "empty bst\n";
            while (temp)
            {
                if (temp->key.first == _key)
                    return map_iterator(temp);
                if (_key > temp->key.first)
                    temp = temp->right_child;
                else if (_key < temp->key.first)
                    temp = temp->left_child;
            }
            return map_iterator(NULL);
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
                if (_key.first > temp->key.first)
                    temp = temp->right_child;
                else if (_key.first < temp->key.first)
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

            if (balance > 1 && data.first < root->left_child->key.first)
                return rrotation();
            if (balance < -1 && data.first > root->right_child->key.first)
                return lrotation();
            if (balance > 1 && data.first > root->right_child->key.first)
            {
                root->left_child = lrotation();
                return rrotation();
            }
            if (balance < -1 && root->left_child && data.first < root->left_child->key.first)
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
                if (_key.first > temp->key.first)
                    temp = temp->right_child;
                else if (_key.first < temp->key.first)
                    temp = temp->left_child;
                if (_key.first >= temp->key.first)
                {
                    std::cout << temp->key.second << " true -> " << std::endl;
                    return true;
                }
            }
            return false;
        }
        key_type successor(Node<T> * root)
        {
            root = root->right_child;
            while (root->left_child != NULL) 
                root = root->left_child;
            return root->key.first;
        }
        key_type predecessor(Node<T> * root)
        {
            root = root->left_child;
            while (root->right_child != NULL)
                root = root->right_child;
            return root->key.first;
        }
        Node<T>*    erase(map_iterator it)
        {
            return root;    
        }
        void   swap(Node<T>* x)
        {
            std::swap(root, x);
        }
        bool    upper_bound(const T& _key) {
            return lower_bound(_key);}
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
