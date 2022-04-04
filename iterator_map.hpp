#pragma once
#include <cstddef>

namespace ft
{
template<typename K, typename V> 
class iterator_map
{
public:
	typedef K									treepointer;
	typedef V									value_type;
	// typedef typename value_type::key_type		key_type;
  	// typedef typename value_type::mapped_type	mapped_type;
    typedef std::ptrdiff_t						difference_type;
    typedef value_type*							pointer;
    typedef value_type&							reference;
    typedef std::bidirectional_iterator_tag		iterator_category;
	typedef iterator_map<K, const V>			const_iterator; 

private:
	treepointer root;
  	treepointer return_node;
  	treepointer end_node;

public:
	iterator_map(): root(NULL), return_node(NULL), end_node(NULL)
	{
	}
	iterator_map(const treepointer croot, const treepointer creturn, const treepointer cend): root(croot), return_node(creturn), end_node(cend)
	{
	}
	iterator_map(const iterator_map &c): root(c.root), return_node(c.return_node), end_node(c.end_node)
	{
	}

	operator const_iterator()
	{
		return const_iterator(root, return_node, end_node);
	}

	iterator_map& operator=(const iterator_map &c)
  	{
    	this->root = c.root;
    	this->return_node = c.return_node;
    	this->end_node = c.end_node;
    	return (*this);
  	}

	bool operator==(const iterator_map& iterator) const
	{
		return (this->return_node == iterator.return_node);
	}

	bool operator!=(const iterator_map& iterator) const
	{
		return !(*this == iterator);
	}

	iterator_map operator++(int)
	{
		iterator_map ret(*this);
		++(*this);
		return (ret);
	}

	iterator_map& operator++()
	{
		treepointer tmp;
		if (return_node->getRightChild() != NULL)
		{
			return_node = return_node->getRightChild();
			return_node = mostleft(return_node);
		}
		else
		{
		tmp = return_node->parent;
		while (tmp != NULL && return_node == tmp->getRightChild())
		{
			return_node = tmp;
			tmp = tmp->parent;
		}
		return_node = tmp;
		}
		if (return_node == NULL)
		{
		return_node = end_node;
		}
		return (*this);
	}

	iterator_map operator--(int)
	{
		iterator_map ret(*this);
		--(*this);
		return (ret);
	}

	iterator_map& operator--()
	{
		treepointer tmp;

		if (return_node == end_node)
		{
		return_node = end_node->parent;
		return (*this);
		}
		else if (return_node->getLeftChild() != NULL)
		return_node = mostright(return_node->getLeftChild());
		else
		{
		tmp = return_node->parent;
		while (tmp != NULL && return_node == tmp->getLeftChild())
		{
			return_node = tmp;
			tmp = tmp->parent;
		}
		return_node = tmp;
		}
		return (*this);
	}

	reference operator*() const
	{
		return (return_node->data);
	}

	pointer operator->() const
	{
		return (&operator*());
	}
private:
	treepointer mostleft(treepointer c)
	{
		while (c->getLeftChild() != NULL)
			c = c->getLeftChild();
		return (c);
	}

	treepointer mostright(treepointer c)
	{
		while (c->getRightChild() != NULL)
			c = c->getRightChild();
		return (c);
	}
public:
	~iterator_map()
	{
	}

};
}


