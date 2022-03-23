#pragma once
#include <iostream>
#include <string>
#include "Tree.hpp"
#include "Node.hpp"
#define spaces 5

template <typename T>
class AVLTree : public Tree<T>
{
public:
	Node<T> *root; // access the whole tree

	void printtree(Node<T> *pt, int sp)
	{
		if (sp == 0)
			sp = spaces;
		if (pt != NULL)
		{
			printtree(pt->getRightChild(), sp + 10);
			printf("%*d\n\n\n", sp, pt->getData());
			printtree(pt->getLeftChild(), sp + 10);
		}
	}
private:
	void traverseInOrder(Node<T> *node)
	{
		// left subtree -> root -> right subtree
		if (node != NULL)
		{
			traverseInOrder(node->getLeftChild());
			std::cout << node->getData() << "\n";
			traverseInOrder(node->getRightChild());
		}
	}


	Node<T>* insert(T data, Node<T> *node)
	{
		if (node == NULL)
			return new Node<T>(data);
		if (data < node->getData())
			node->SetLeftChild(insert(data, node->getLeftChild()));
		else if (data > node->getData())
			node->SetRightChild(insert(data, node->getRightChild()));
		return node;
	}

	Node<T> *del (T data, Node<T> *node)
	{
		if (node == NULL)
			return NULL;
		// keep searching
		if (data > node->getData())
		{
			node->SetLeftChild(del(data, node->getLeftChild()));
		}
		else if (data < node->getData())
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

	T getMax(Node<T> *node) {
        if (node->getRightChild() != NULL) {
            return getMax(node->getRightChild());
        }
        return node->getData();
    }
	T getMin(Node<T> *node) {
        if (node->getLeftChild() != NULL) {
            return getMin(node->getLeftChild());
        }
        return node->getData();
    }

public:

	bool isEmpty()
	{
		return root == NULL;
	}
	
	T getMax() {
        if (isEmpty()) {
            return 0;
        }
        return getMax(root);
    }

	T getMin() {
        if (isEmpty()) {
            return 0;
        }
        return getMin(root);
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

	// Print the tree
	void printTree(Node<T> *root, std::string indent, bool last) {
	if (root != nullptr) {
		std::cout << indent;
		if (last) {
		std::cout << "R----";
		indent += "   ";
		} else {
		std::cout << "L----";
		indent += "|  ";
		}
		std::cout << root->getData() << std::endl;
		printTree(root->getLeftChild(), indent, false);
		printTree(root->getRightChild(), indent, true);
	}
	}
};

