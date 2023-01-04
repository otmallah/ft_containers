/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:11:58 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/04 16:35:13 by otmallah         ###   ########.fr       */
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
    bst (int data)
    {
        _data = data;
        left = NULL;
        right =  NULL;
    }
};

bst *creat(int data)
{
    bst *root = new bst(data);
    return root;
}

bst    *search(bst *root, int data)
{
    if (data < root->_data)
        search(root->left, data);
    else if (data > root->_data)
        search(root->right, data);
    return root;
}

bst*    insert(bst *root, int data)
{
    bst *mp = root;
    if (mp == NULL)
    {
        mp = creat(20);
        return root;
    }
    while (mp)
    {
        if (data > mp->_data)
            mp = mp->right;
        else if (data < mp->_data)
            mp = mp->left;
        else
        {
            mp = creat(data);
            return root;
        }
    }
    return root;
}

void inorder(bst *tmp)
{
    if (tmp == NULL)
        return;
    inorder(tmp->left);
    std::cout << tmp->_data << std::endl;
    inorder(tmp->right);
}

int main()
{
    bst *root  = NULL;
    root = insert(root, 20);
    s
}
