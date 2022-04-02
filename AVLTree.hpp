#pragma once
#include <iostream>
#include <string>
#include <algorithm>    // std::max
#include "pair.hpp"

#define spaces 5
template <typename T>
class Node
{
	public:
		T data;
		Node<T> *parent;
		Node<T> *leftChild;
		Node<T> *rightChild;
		int height;
	public:
		typedef T		value_t;
        typedef Node<T>	node;
		Node() : parent(NULL), leftChild(NULL), rightChild(NULL), data(value_t()) {}
		Node(value_t d) : height(1), data(d), parent(NULL), leftChild(NULL), rightChild(NULL) {}
		Node (const Node &src) : height(src.height), data(src.data), parent(src.parent), leftChild(src.leftChild), rightChild(src.rightChild) {}  

		//getters
		value_t getData() const {
			return this->data;
		}

		node *getRightChild() const {
			return this->rightChild;
		}
		
		node *getLeftChild() const {
			return this->leftChild;
		}

		node *getParent() const {
			return this->parent;
		}

		int getHeight() const {
			return this->height;
		}
		//setters
		void SetData(value_t d) {
			this->data = d;
		}

		void SetParent(node *p) {
			this->parent = p;
		}

		void SetRightChild(node *r) {
			this->rightChild = r;
		}

		void SetLeftChild(node *l) {
			this->leftChild = l;
		}

		void SetHeight(int h) {
			this->height = h;
		}
};


template <typename F, typename S, typename key_comp, typename Alloc>
class AVLTree
{
public:
	typedef ft::pair<const F, S> value_t;
    typedef Node<value_t> tree_s;
    typedef typename Alloc::template rebind<Node<value_t> >::other  alloc_type;

	alloc_type alloc;
	key_comp comp;
	tree_s *root;
	tree_s *last_elem;
	size_t nbrofnodes;
	
	AVLTree(): root(NULL), nbrofnodes(0)
	{
		this->last_elem = alloc.allocate(1);
	}

	AVLTree(const AVLTree &c)
	{
		this->alloc=c.alloc;
		this->comp = c.comp;
		this->nbrofnodes = c.nbrofnodes;
		this->root = copy_tree(c.root, NULL);
		this->last_elem = alloc.allocate(1);
		if (this->root != NULL)
            this->last_elem->parent = mostright(this->root);
	}
	
	tree_s *copy_tree(tree_s *c, tree_s *par)
	{
		if (c == NULL)
			return (NULL);
		tree_s *ret = this->alloc.allocate(1);
		this->alloc.construct(ret, tree_s(*c));
		ret->parent = par;
		ret->l = copy_tree(c->l, ret);
		ret->r = copy_tree(c->r, ret);
		return (ret);
	}


	void setParent(tree_s *n, tree_s *p)
	{
		if (n == NULL)
			return ;
		setParent(n->getRightChild(), n);
		n->parent = p;
		setParent(n->getLeftChild(), n);
	}

	void printtree(tree_s *pt, int sp)
	{
		if (sp == 0)
			sp = spaces;
		if (pt != NULL)
		{
			printtree(pt->getRightChild(), sp + 10);
			printf("%*d\n\n\n", sp, pt->getData().first);
			printtree(pt->getLeftChild(), sp + 10);
		}
	}

	void traverseInOrder(tree_s *node)
	{
		// left subtree -> root -> right subtree
		if (node != NULL)
		{
			traverseInOrder(node->getLeftChild());
			std::cout << node->getData().first << "\n";
			traverseInOrder(node->getRightChild());
		}
	}

	int height(tree_s *node)
	{
		return node != NULL ? node->getHeight() : 0;
	}

	tree_s* rotateRight(tree_s *node)
	{
		tree_s* leftNode = node->getLeftChild();
		tree_s* centreNode = leftNode->getRightChild();
		leftNode->SetRightChild(node);
		node->SetLeftChild(centreNode);
		setParent(leftNode, node->parent); // set parent of the new node with the previous node parent
		updateHeight(node);
		updateHeight(leftNode);
		return leftNode;
	}

	tree_s* rotateLeft(tree_s *node)
	{
		tree_s* rightNode = node->getRightChild();
		tree_s* centreNode = rightNode->getLeftChild();
		rightNode->SetLeftChild(node);
		node->SetRightChild(centreNode);
		setParent(rightNode, node->parent); // set parent of the new node with the previous node parent
		updateHeight(node);
		updateHeight(rightNode);
		return rightNode;
	}

	int balance(tree_s *node) {
        return node != NULL ? height(node->getLeftChild()) - height(node->getRightChild()) : 0;
    }

	tree_s* applyRotation(tree_s *node)
	{
		int balanceFactor = balance(node);
		if (balanceFactor > 1)
		{
			// left-heavy
			if (balance(node->getLeftChild()) < 0)
			{
				node->SetLeftChild(rotateLeft(node->getLeftChild()));
			}
			return rotateRight(node);
		}
		if (balanceFactor < -1)
		{
			//right-heavy
			if (balance(node->getRightChild()) > 0)
			{
				node->SetRightChild(rotateRight(node->getRightChild()));
			}
			return rotateLeft(node);
		}
		this->last_elem->parent = mostright(this->root);
		return node;
	}

	void updateHeight(tree_s *node)
	{
		int maxHeight = std::max(
			height(node->getLeftChild()),
			height(node->getRightChild())
		);
		node->SetHeight(maxHeight + 1);
	}

	tree_s* inser(value_t data,tree_s *node, tree_s* pa)
    {
        if (node == NULL)
        {
            node = alloc.allocate(1);
            alloc.construct(node, data);
            node->height = 1;
            node->parent = pa;
            this->nbrofnodes++;
            return node;
        }
        if (data.first == node->getData().first)
            return NULL;
        if (!comp(node->getData().first, data.first)) // operator < 
            node->SetLeftChild(inser(data, node->getLeftChild(), node));
        else if (!comp(data.first, node->getData().first))
            node->SetRightChild(inser(data, node->getRightChild(), node));
        updateHeight(node);
        return applyRotation(node);
    }

	tree_s* erase(tree_s* node, const F &d)
	{
		if (node == NULL)
			return NULL;
		if (comp(node->getData().first, d))  // operator >
			node->SetRightChild(erase(node->getRightChild(), d));
		else if (comp(d, node->getData().first))
			node->SetLeftChild(erase(node->getLeftChild(), d));
		else
		{
			if (node->getLeftChild() != NULL)
			{
				tree_s* cur = node;
				tree_s* tmp;
				tmp = mostright(node->getLeftChild());
				node = alloc.allocate(1);
				alloc.construct(node, *tmp);
				node->SetRightChild(cur->getRightChild());
				node->SetParent(cur->getParent());
				node->SetLeftChild(erase(cur->getLeftChild(), tmp->getData().first));
				alloc.destroy(cur);
				alloc.deallocate(cur, 1);

			}
			else if (node->getRightChild() != NULL)
			{
				tree_s* cur = node;
				tree_s* tmp;
				tmp = mostleft(node->getRightChild());
				node = alloc.allocate(1);
				alloc.construct(node, *tmp);
				node->SetLeftChild(cur->getLeftChild());
				node->SetParent(cur->getParent());
				node->SetRightChild(erase(cur->getRightChild(), tmp->getData().first));
				alloc.destroy(cur);
				alloc.deallocate(cur, 1);
			}
			else
			{
				alloc.destroy(node);
				alloc.deallocate(node, 1);
				this->nbrofnodes--;
                return NULL;
			}
		}
		updateHeight(node);
        return applyRotation(node);
	}

	tree_s *mostleft(tree_s *s)
	{
		if (s == NULL)
			return (s);
		while (s->getLeftChild() != NULL)
			s = s->getLeftChild();
		return (s);
	}

	tree_s *mostright(tree_s *s)
	{
		if (s == NULL)
			return (s);
		while (s->getRightChild() != NULL)
			s = s->getRightChild();
		return (s);
	}

	bool isEmpty()
	{
		return root == NULL;
	}
	
	void traverse()
	{
		traverseInOrder(root);
	}

	tree_s *insert(value_t data)
	{
		root = inser(data, root, NULL);
		return this->root;
	}

	void del(F data)
	{
		root = erase(root, data);
	}

	// Print the tree
	void printTree(tree_s *root, std::string indent, bool last) {
	if (root != nullptr) {
		std::cout << indent;
		if (last) {
		std::cout << "R----";
		indent += "   ";
		} else {
		std::cout << "L----";
		indent += "|  ";
		}
		std::cout << root->getData().first << std::endl;
		printTree(root->getLeftChild(), indent, false);
		printTree(root->getRightChild(), indent, true);
	}
	}
};

