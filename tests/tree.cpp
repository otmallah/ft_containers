/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/05 15:13:17 by otmallah         ###   ########.fr       */
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
            return root;
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

void      print_mini(bst *root)
{
    while (root)
    {
        if (!root->left)
            std::cout << root->_data << std::endl;
        root = root->left;
    }
}

void      print_max(bst *root)
{
    while (root)
    {
        if (!root->right)
            std::cout << root->_data << std::endl;
        root = root->right;
    }
}

// int sizeBST(bst* root)
// {
    
// }

void    printInorder(bst *root)
{
    while (root)
    {
        
    }
    
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

    std::cout << root->right->right->_data << std::endl;
    // printInorder(root);
    // search(root, 22000);
    // std::cout << "max value in BST : " ;
    // print_max(root);
    // std::cout << "min value in BST : ";
    // print_mini(root);
}