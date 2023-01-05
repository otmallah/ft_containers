/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/05 16:34:40 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <map>
#include <iostream>
#include <map>

class bst
{
    public:
    bst *left;
    bst *right;
    int _data;
    bst() {}
    bst (int data)
    {
        _data = data;
        left = NULL;
        right =  NULL;
    }
};

bst *create(int data)
{
    bst *root = new bst(data);
    return root;
}

bst*    insert(bst *root, int data)
{
    if (root == NULL)
        return root = create(data);
    bst *prev =  NULL;
    bst *temp = root;
    while (root != NULL)
    {
        prev = root;
        if (data > root->_data)
            root = root->right;
        else if (data < root->_data)
            root = root->left;
        else
            break;
    }
    if (data > prev->_data)
        prev->right = create(data);
    else if (data < prev->_data)
        prev->left = create(data);
    return temp;
}

bool    search(bst* root, int data)
{
    if (root == NULL)
        std::cout << "empty bst\n";
    while (root)
    {
        if (root->_data == data)
        {
            return true;
            break;
        }
        if (data > root->_data)
            root = root->right;
        else if (data < root->_data)
            root = root->left;
    }
    return false;
}

void      leftmost(bst *root)
{
    while (root)
    {
        if (!root->left)
            std::cout << root->_data << std::endl;
        root = root->left;
    }
}

void      rightmost(bst *root)
{
    while (root)
    {
        if (!root->right)
            std::cout << root->_data << std::endl;
        root = root->right;
    }
}


bst* deletion(bst *root, int data)
{
    bst* prev =  NULL;
    bst* temp = root;
    if (root->_data == data)
        return NULL;
    while (root)
    {
        if (root->left && root->left->_data == data)
        {
            root->left = NULL;
            break;
        }
        else if (root->right && root->right->_data == data)
        {
            root->right = NULL;
            break;
        }
        if (root->_data > data)
            root = root->left;
        else if (root->_data < data)
            root = root->right;
    }
    return temp;
}

void    printInorder(bst *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    std::cout << root->_data << std::endl;
    printInorder(root->right);
}

int main()
{
    bst *root = NULL;
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 14);
    root = deletion(root, 88);
    printInorder(root);
    // search(root, 22000);
    std::cout << "max value in BST : " ;
    rightmost(root);
    std::cout << "min value in BST : ";
    leftmost(root);
}