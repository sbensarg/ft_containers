#pragma once


template <typename T>
class Node
{
	public:
		T data;
		Node<T> *leftChild;
		Node<T> *rightChild;
	public:
		//getters
		Node(T d)
		{
			this->data = d;
			this->leftChild = NULL;
			this->rightChild = NULL;
		}
		T getData() const {
			return this->data;
		}

		Node<T>	*getRightChild() const {
			return this->rightChild;
		}
		
		Node<T> *getLeftChild() const {
			return this->leftChild;
		}
		//setters
		void SetData(T d) {
			this->data = d;
		}

		void SetRightChild(Node<T> *r) {
			this->rightChild = r;
		}

		void SetLeftChild(Node<T> *l) {
			this->leftChild = l;
		}

		bool operator<(const Node<T> & other_it) const
		{
			return (data < other_it.data);
		}
		bool operator>(const  Node<T> & other_it) const
		{
			return (data > other_it.data);
		}
};
