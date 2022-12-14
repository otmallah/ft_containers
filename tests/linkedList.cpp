/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:59 by otmallah          #+#    #+#             */
/*   Updated: 2023/01/02 13:02:07 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>
#include <stack>
#include "stack/stack.hpp"
#include <sys/time.h>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <list>

#include "./containers_test/srcs/base.hpp"
#include "./containers_test/srcs/vector/common.hpp"


#include <unistd.h>
#include <sys/time.h>
#include "containers_test/srcs/base.hpp"

class  Node
{
	public:
		int number;
	Node *next;
};

void print(Node *temp)
{
	while (temp != NULL)
	{
		printf("data = %d\n", temp->number);
		temp = temp->next;
	}
}

Node	*addNodeHead(Node *temp, int data)
{
	Node *new_data = new Node();
	new_data->number = data;
	new_data->next = (temp);
	return new_data;
}


Node	*addNodetail(Node *temp, int data)
{
	Node *saver = temp;
	Node *new_data = new Node();
	new_data->number = data;
	new_data->next = NULL;
	while (saver->next != NULL)
		saver = saver->next;
	saver->next = new_data;
	return temp;	
}

int		Node_size(Node *node)
{
	int i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return i;
}

Node *Add(Node *node, int position, int data)
{
	Node *temp = node;
	if (position > Node_size(node) && position < Node_size(node))
	{
		std::cout << "out of range" << std::endl;
		return NULL;
	}
	Node *new_data = new Node();
	Node *prev = NULL;
	int i = 0;
	while (temp->next != NULL)
	{
		if (i == position)
		{
			prev->next = new_data;
			new_data->number = data;
			new_data->next = temp;
		}
		prev = temp;
		temp = temp->next;
		i++;
	}
	return node;
}

Node	*removeNode(Node *node, int position)
{
	Node *temp = node;
	if (position > Node_size(node) && position < Node_size(node))
	{
		std::cout << "out of range" << std::endl;
		return NULL;
	}
	Node *prev = NULL;
	int i = 0;
	while (temp->next != NULL)
	{
		if (i == position)
		{
			prev->next = temp->next;
			return node;
		}
		prev = temp;
		temp = temp->next;
		i++;
	}
	return node;
}

int main(void)
{
	Node *head = NULL;
	head = addNodeHead(head , 0);
	for (size_t i = 0; i < 10; i++)
		head = addNodetail(head, i + 1);
	head = removeNode(head, 2);
	print(head);
	
}