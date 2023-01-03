/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linkedList.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:13:08 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/02 21:10:24 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Node 
{
    public :
        void *data;
        Node *next;
        Node *prev;
};

void    initial(Node **node)
{
    // (*node)->next = NULL;
    // (*node)->prev = NULL;
    (*node) = NULL;
}

Node    *addHead(Node *node, void *data)
{
    Node *new_data = new Node();
    new_data->data = data;
    new_data->next = node;
    new_data->prev = NULL;
    if (node != NULL)
        node->prev = new_data;
    return new_data;
}

Node    *addtail(Node *node, void *data)
{
    Node *new_data = new Node();
    Node *temp = node;
    new_data->data = data;
    new_data->next = NULL;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_data;
    new_data->prev = temp;
    return node;
}


void    print(Node* node)
{
    while (node != NULL)
    {
        std::cout << "data = " << *(int *)node->data << std::endl;
        node = node->next;
    }
}

void    print_prev(Node *node)
{
    while (node->next)
        node = node->next;
    while (node)
    {
        std::cout << "prev = " << *(int *)node->data << std::endl;
        node = node->prev;
    }
}

void    removeNode(Node *node, void *data)
{
    Node *temp = node;
    while (temp->next)
    {
        if (*(int *)temp->data == *(int *)data)
        {
            temp->data = NULL;
            temp->prev->next = temp->next;
        }
        temp = temp->next;
    }
    
}

int     size(Node *node)
{
    int i = 0;
    while (node)
    {
        i++;
        node =  node->next;
    }
    return (i);
}

Node    *insertPosition(Node *node, void *data, int position)
{
    int i = 0;
    Node *temp = node;
    Node *new_data = new Node();
    new_data->data = data;
    while (temp)
    {
        if (position == 0)
            return addHead(node, data);
        else if (position == size(node))
            return addtail(node, data);
        else if (i == position)
        {
            temp->prev->next = new_data;
            new_data->next = temp;
            new_data->prev = temp->prev;
            new_data->next->prev = new_data;
        }
        temp = temp->next;
        i++;
    }
    return node;
}

int main()
{
    Node *head = new Node();
    initial(&head);
    int a[] = {1, 2, 3 , 4, 5};
    int b = 0;
    head = addHead(head, &b);
    for (size_t i = 0; i < 5; i++)
        addtail(head, &a[i]);
    int number = 1800;
    head = insertPosition(head, &number, 5);
    print(head);
}