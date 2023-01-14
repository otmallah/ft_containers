/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:33:49 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/15 00:16:14 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../utils_map/bidirectional_iterator.hpp"

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

template <typename T, class key_type , class compare ,class Allocator = std::allocator<Node<T> > >
class AVL_TREE
{
    private :
        Node<T> *root;
        size_t     height;
        Allocator alloc;
        int     counter;
        compare    key_comp; 
        
    
    public :
        typedef typename ft::__map_iterator<Node<T>, T, key_type> map_iterator;
        typedef typename ft::__map_iterator< Node<T>,  T, key_type> const_map_iterator;
    public :

        AVL_TREE()
        {
            height = 0;
            root = alloc.allocate(1);
            alloc.construct(root, T());
        }
        ~AVL_TREE()
        {
            height = 0;
            deallocate(root);
        }
        size_t getsize() const { return height;}
        void clear(Node<T> *bst)
        {
            if (!bst)
                return ;
            height = 0;
            clear(bst->left_child);
            clear(bst->right_child);
            alloc.destroy(bst);
        }
        void deallocate(Node<T> *bst)
        {
            if (!bst)
                return ;
            deallocate(bst->left_child);
            deallocate(bst->right_child);
            delete bst;
        }
        map_iterator    begin() const
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
            Node<T> * new_node = alloc.allocate(1);
            alloc.construct(new_node, key);
            new_node->left_child = NULL;
            new_node->right_child = NULL;
            return new_node;
        }
        std::pair<map_iterator, bool> insert(const T& key)
        {
            //puts("hana");
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
                if (key.first == temp->key.first)
                    break;
                else if (key_comp(key.first, temp->key.first))
                    temp = temp->left_child;
                else
                    temp = temp->right_child;
            }
            if (key_comp(prev->key.first, key.first))
            {
                height += 1;
                prev->right_child = create(key);
                result.first = map_iterator(prev->right_child);
                result.second = true;
            }
            else if (key_comp(key.first, prev->key.first))
            {
                height += 1;
                prev->left_child = create(key);
                result.first = map_iterator(prev->left_child);
                result.second = true;
            }
            else
            {
                result.first = map_iterator(temp);
                result.second = false;
            }
        //root = re_balance(key);
            return result;
        }
        Node<T>*    leftmost()
        {
            Node<T> * temp = root;
            while (temp && !temp->left_child)
                temp = temp->left_child;
            return root;
        }
        Node<T>*    _leftmost(Node<T> * root)
        {
            Node<T> * temp = root;
            while (temp->left_child)
                temp = temp->left_child;
            return temp;
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
            while (temp)
            {   
                if (temp->key.first == _key)
                    return map_iterator(root, _key, 0);
                if (_key > temp->key.first)
                    temp = temp->right_child;
                else if (_key < temp->key.first)
                    temp = temp->left_child;
            }
            return map_iterator(NULL);
        }
        size_t count (const key_type& _key) const
        {
            Node<T> *temp = root;
            while (temp)
            {
                if (temp->key.first == _key)
                {
                    return 1;
                }
                if (_key > temp->key.first)
                    temp = temp->right_child;
                else if (_key < temp->key.first)
                    temp = temp->left_child;
            }
            return 0;
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
        map_iterator    lower_bound(const key_type& _key) 
        {
            map_iterator first = begin();
            map_iterator last = end();
            while (first != last)
            {
                if (key_comp(first->first, _key) == false)
                break;
                ++first;
            }
            return (first);
        }
        const_map_iterator    lower_bound(const key_type& _key) const
        {
            const_map_iterator first = begin();
            const_map_iterator last = end();
            while (first != last)
            {
                if (key_comp(first->first, _key) == false)
                break;
                ++first;
            }
            return (first);
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
        map_iterator    upper_bound(const key_type& _key)
        {
            map_iterator first = begin();
            map_iterator last = end();
            last++;
            while (first != last)
            {
                if (key_comp(_key, first->first) == true)
                    break;
                first++;
            }
            return (first);
        }
        const_map_iterator    upper_bound(const key_type& _key) const
        {
            const_map_iterator first = begin();
            const_map_iterator last = end();
            last++;
            while (first != last)
            {
                if (key_comp(_key, first->first) == true)
                    break;
                first++;
            }
            return (first);
        }
        Node<T> *   erase(Node<T> * _root, const key_type& key)
        {
            if (!_root)
                return NULL;
            if (key_comp(_root->key.first, key))
                _root->right_child = erase(_root->right_child, key);
            else if (key_comp(key, _root->key.first))
                _root->left_child = erase(_root->left_child, key);
            else if (key == _root->key.first)
            {
                this->counter = 1;
                if (_root->left_child == NULL and _root->right_child == NULL)
                {
                    delete _root;
                    height--;
                    return NULL;
                }
                else if (_root->left_child == NULL)
                {
                    height--;
                    Node<T> * temp = _root->right_child;
                    delete _root;
                    return temp;
                }
                else if (_root->right_child == NULL)
                {
                    height--;
                    Node<T> * temp = _root->left_child;
                    delete _root;
                    return temp;
                }
                Node<T> * temp = _leftmost(root->right_child); 
                if (temp)
                {
                    height--;
                    root->key.first = temp->key.first;
                    root->right_child = erase(root->right_child, temp->key.first);
                }
                height--;
            }
            return _root;
        }
        void erase(map_iterator it)
        {
            root = erase(root, it->first);
        }
        size_t erase(const key_type& key)
        {
            root = erase(root, key);
            if (counter == 1)
                return 1;
            return 0;
        }

        void    swap(AVL_TREE &x)
        {
            std::swap(this->root, x.root);
            std::swap(this->alloc, x.alloc);
            std::swap(this->height, x.height);
            std::swap(this->key_comp, x.key_comp);
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
