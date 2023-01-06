/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/06 19:26:22 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <map>
#include <iostream>
#include <map>
int heightLeft = 0;
int heightRight = 0;


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
int     getBlanced(bst * root);

bst *lrotation(bst * root);
bst *create(int data)
{
    bst *root = new bst(data);
    return root;
}

bst *lrotation(bst * root)
{
    puts("hana");
    bst *node1 = root->right;
    bst *node2 = node1->left;

    node1->left = root;
    root->right = node2;
    return node1;
}

bst *rrotation(bst * root)
{
    bst * node1 = root->left;
    bst * node2 = node1->right;
    
    node1->right = root;
    root->left = node2 ;
    return node1;
}

bst * re_balance(bst *temp, int data)
{
    int balance = getBlanced(temp);

    std::cout << "balance = " << balance << std::endl;
    if (balance > 1 && data < temp->left->_data)
        return rrotation(temp);
    if (balance < -1 && data > temp->right->_data)
        return lrotation(temp);
    if (balance > 1 && data > temp->right->_data)
    {
        temp->left = lrotation(temp);
        return rrotation(temp);
    }
    if (balance < -1 && data < temp->left->_data)
    {
        temp->right = rrotation(temp);
        return lrotation(temp);
    }
    return temp;
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
    return re_balance(temp, data);
}

bool    search(bst* root, int data)
{
    if (root == NULL)
        std::cout << "empty bst\n";
    while (root)
    {
        if (root->_data == data)
        {
            std::cout << root->_data << std::endl;
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
        heightLeft++;
        root = root->left;
    }
}

void      rightmost(bst *root)
{
    while (root)
    {
        if (!root->right)
            std::cout << root->_data << std::endl;
        heightRight++;
        root = root->right;
    }
}

void deallocate(bst *bst)
{
    if (!bst)
        return ;
    deallocate(bst->left);
    deallocate(bst->right);
    delete bst;
}

bst* deletion(bst *root, int data)
{
    bst* prev =  NULL;
    bst* temp = root;
    if (root->_data == data)
    {
        return NULL;
    }
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

int i = 0;
// void size(bst* root)
// {
//     if (!root)
//         return;
//     size(root->left);
//     size(root->right);
//     i++;
// }

int countHeight(bst * root)
{
    if (!root)
        return 0;
    int left_height = countHeight(root->left);
    int right_height = countHeight(root->right);
    if (left_height >= right_height )
        return left_height + 1;
    else
        return right_height + 1;
}

int     getBlanced(bst * root)
{
    if (!root)
        return (0);
    return countHeight(root->left) - countHeight(root->right);
}

int main()
{
    {
    bst *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    // root = insert(root, 9);
    // root = insert(root, 11);
    // root = insert(root, 15);
    // root = insert(root, 17);
    // root = insert(root, 20);
    //deletion(root, );
    printInorder(root);
    //size(root);
    //std::cout << countHeight(root->left) << std::endl;
    //std::cout << getBlanced(root) << std::endl;
    std::cout << "max value in BST : " ;
    rightmost(root);
    std::cout << "min value in BST : ";
    leftmost(root);
    // std::cout << " h left = " << heightLeft - heightRight << std::endl;
    // std::cout << " h left = " << heightRight - heightLeft << std::endl;
    // if (heightLeft - heightRight > 1 || heightLeft - heightRight < -1 )
    //     std::cout << "unbalanced tree " << std::endl;
    }
    //system("leaks a.out");
}