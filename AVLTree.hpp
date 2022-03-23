#pragma once
#include <iostream>
#include <string>
#include "Tree.hpp"
#include "Node.hpp"


template <typename T>
class AVLTree : public Tree<T>
{
private:
	Node<T> *root; // access the whole tree


	void traverseInOrder(Node<T> *node)
	{
		// left subtree -> root -> right subtree
		if (node != NULL)
		{
			traverseInOrder(node->getLeftChild());
			std::cout << node;
			traverseInOrder(node->getRightChild());
		}
	}

		Node<T>* insert(T data, Node<T> *node)
	{
		if (node == NULL)
			return new Node<T>(data);
		
		if (data.compare(node->getData()) < 0)
			node->SetLeftChild(insert(data, node->getLeftChild()));
		else if (data.compare(node->getData()) > 0)
			node->SetRightChild(insert(data, node->getRightChild()));
		return node;
	}

	Node<T> *del (T data, Node<T> *node)
	{
		if (node == NULL)
			return NULL;
		// keep searching
		if (data.compare(node->getData()) < 0)
		{
			node->SetLeftChild(del(data, node->getLeftChild()));
		}
		else if (data.compare(node->getData()) > 0)
		{
			node->SetRightChild(del(data, node->getRightChild()));
		}
		else // delete the node we found
		{
			// One Child
			if (node->getLeftChild() == NULL)
			{
				return node->getRightChild();
			}
			else if (node->getRightChild() == NULL)
			{
				return node->getLeftChild();
			}
			// Two Children
			T bla = getMax(node->getLeftChild());
			node->SetData(bla); // predecessor
			node->SetLeftChild(del(node->getData(), node->getLeftChild()));
		}
		return NULL;
	}

public:
	
	bool isEmpty()
	{
		return root == NULL;
	}
	
	T getMax() {
        if (isEmpty()) {
            return NULL;
        }
        return getMax(root);
    }

    T getMax(Node<T> node) {
        if (node.getRightChild() != NULL) {
            return getMax(node.getRightChild());
        }
        return node.getData();
    }

	T getMin()
	{
		if (isEmpty())
			return NULL;

		Node<T> *node = root;
		while (node->getLeftChild() != NULL)
		{
			node = node->getLeftChild();	
		}
		return node->getData();
	}

	T getMax(Node<T> *node)
	{
		if (isEmpty())
			return NULL;

		while (node->getRightChild() != NULL)
		{
			node = node->getRightChild();	
		}
		return node->getData();
	}

	void traverse()
	{
		traverseInOrder(root);
	}

	Tree<T> *insert(T data)
	{
		root = insert(data, root);
		return this;
	}

	void del(T data)
	{
		root = del(data, root);
	}
};

