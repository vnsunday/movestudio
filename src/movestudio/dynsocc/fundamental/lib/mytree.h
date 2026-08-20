/*
 * mytree.h
 *
 *  Created on: Dec 10, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_LIB_MYTREE_H_
#define APP_FUNDAMENTAL_LIB_MYTREE_H_


#include <stdlib.h>
#include <iostream>
#include <vector>

template <class T,class V>
class TreeNode
{
private:
	T id;
	V value;

	std::vector<TreeNode*> vchild;
public:
	TreeNode(T t,V v)
	{
		id = t;
		value = v;
	}

	int addChild(TreeNode* n)
	{
		bool bDup = false;	// Duplicate
		for (int i=0;i<vchild.size();i++)
		{
			if (vchild[i].id == n->id)
			{
				bDup = true;
				break;
			}
		}

		if (!bDup)
		{
			vchild.push_back(n);
			return 0;
		}
		else
		{
			return 1;
		}

	}
};

template<class T,class V>
class Tree
{
private:
public:
	Tree()
	{
	}

	int addNode(T t, V v)
	{
		return 0;
	}
};

#endif /* APP_FUNDAMENTAL_LIB_MYTREE_H_ */
