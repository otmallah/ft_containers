/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/08 01:12:15 by otmallah         ###   ########.fr       */
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

    if (balance > 1 && data < temp->left->_data)
        return rrotation(temp);
    if (balance < -1 && temp->right && data > temp->right->_data)
        return lrotation(temp);
    if (balance > 1 && temp->right && data > temp->right->_data)
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
    //return temp;
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

bst*      leftmost(bst *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
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

void deallocate(bst *bst)
{
    if (!bst)
        return ;
    deallocate(bst->left);
    deallocate(bst->right);
    delete bst;
}

int successor(bst * root) {
  root = root -> right;
  while (root -> left != NULL) root = root -> left;
  return root -> _data;
}
int predecessor(bst * root) {
  root = root -> left;
  while (root -> right != NULL) root = root -> right;
  return root -> _data;
}
 
 
bst* deletion(bst *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key > root -> _data)
        root -> right = deletion(root -> right, key);
    else if (key < root -> _data)
        root->left = deletion(root -> left, key);
    else {
        if (root -> left == NULL && root -> right == NULL)
            root = NULL;
        else if (root -> right != NULL)
        {
            root -> _data = successor(root);
            root->right = deletion(root -> right, root -> _data);
        } 
        else
        {
            root -> _data = predecessor(root);
            root -> left = deletion(root -> left, root -> _data);
        }
    }
    return root;
//     bst* prev =  NULL;
//     bst* temp = root;
//     if (!root)
//         return NULL;
//     while (root)
//     {
//         prev = root;
//         if (root->_data > data)
//             root = root->left;
//         else if (root->_data < data)
//             root = root->right;
//         else
//             break;
//     }
//     if (!root)
//         return temp;

//     if (root->left == NULL && root->right == NULL)
//     {
//         if (prev == NULL)
//             temp = NULL;
//         else if (prev->left == root)
//             prev->left = NULL;
//         else
//             prev->right = NULL;
//     }
//     else if (root->left == NULL)
//     {
//         if (prev == NULL)
//             temp = root->right;
//         else if (prev->left == root)
//             prev->left = root->right;
//         else
//             prev->right = root->right;
//     }
//     else if (root->right == NULL)
//     {
//         if (prev == NULL)
//             temp = root->left;
//         else if (prev->left == root)
//             prev->left = root->left;
//         else
//             prev->right = root->right;
//     }
// else {
//     bst * successor = root->right;
//     prev = root;
//     while (successor->left != NULL) {
//       prev = successor;
//       successor = successor->left;
//     }
//     root->_data = successor->_data;
//     if (root->left == successor) {
//       prev->left = successor->right;
//     } else {
//       prev->right = successor->right;
//     }
//   }
    //temp = re_balance(temp, root->_data);
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
    root = deletion(root, 10);
    root = deletion(root, 30);
    // root = deletion(root, 40);
    // root = deletion(root, 40);
    //root = insert(root, 80);
    printInorder(root);
    }
    //system("leaks a.out");
}