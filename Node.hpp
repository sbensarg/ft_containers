#pragma once


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

		bool operator<(const node & other_it) const
		{
			return (data < other_it.data);
		}
		bool operator>(const  node & other_it) const
		{
			return (data > other_it.data);
		}
};
