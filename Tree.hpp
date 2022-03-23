#pragma once

template <typename T>

class Tree
{
public:
	virtual Tree<T>* insert(T data) = 0;
	virtual void del(T data) = 0;
	virtual void traverse() = 0;
	virtual T getMax() = 0;
	virtual T getMin() = 0;
	virtual bool isEmpty() = 0;
};