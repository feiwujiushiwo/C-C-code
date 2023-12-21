#pragma once
#include <stdlib.h>
#include "CSTree.h"

template <class VertexType>
Status Insert2Child(CSNode<VertexType> *&treeNode, CSNode<VertexType> *newNode)
{
	Status str = OK;

	if (NULL == treeNode)
	{
		str = ERROR;
	}
	else if (treeNode->lchild == NULL)
	{
		str = Insert2leftChild(treeNode, newNode);
	}
	else
	{
		str = Insert2rightChild(treeNode->lchild, newNode);
	}

	return str;
}

template <class VertexType>
Status Insert2leftChild(CSNode<VertexType> *&treeNode, CSNode<VertexType> *newNode)
{
	Status str = OK;

	if (NULL == treeNode)
	{
		str = ERROR;
	}
	else if (treeNode->lchild == NULL)
	{
		treeNode->lchild = newNode;
		str = OK;
	}
	else
	{
		str = Insert2leftChild(treeNode->lchild, newNode);
	}

	return str;
}

template <class VertexType>
Status Insert2rightChild(CSNode<VertexType> *&treeNode, CSNode<VertexType> *newNode)
{
	Status str = OK;

	if (NULL == treeNode)
	{
		str = ERROR;
	}
	else if (treeNode->lchild == NULL)
	{
		str = INFEASIBLE;
	}
	else
	{
		// TODO: �������������
		CSNode<VertexType> temp = treeNode->lchild;
		if (temp->rchild == NULL)
		{
			temp->rchild = newNode;
		}
		else
		{
			while (temp->rchild != NULL)
			{
				temp = temp->rchild;
			}
			temp->rchild = newNode;
		}
	}

	return str;
}
template <class VertexType>
void PreOrderTraversal(CSNode<VertexType> *treeNode)
{
	if (treeNode != NULL)
	{
		// �ȷ��ʵ�ǰ�ڵ�
		Visit(treeNode);

		// ������ǰ�ڵ�������ӽڵ�
		CSNode<VertexType> *child = treeNode->lchild;
		while (child != NULL)
		{
			PreOrderTraversal<VertexType>(child);
			child = child->rchild;
		}
	}
}
