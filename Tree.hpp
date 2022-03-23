#pragma once
#include "Node.hpp"

template <typename T>

class Tree
{
public:
	virtual Tree<T>* insert(T data);
	virtual void del(T data);
	virtual void traverse();
	virtual T getMax();
	virtual T getMin();
	virtual bool isEmpty();
};