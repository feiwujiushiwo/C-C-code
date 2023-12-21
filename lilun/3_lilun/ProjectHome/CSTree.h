#pragma once
#include "opConstant.h"

#ifndef CSTree_H
#define CSTree_H

template<class VertexType>
struct CSNode {
	VertexType key;

	CSNode<VertexType>* nextsibling;
	CSNode<VertexType>* lchild;
};


template<class KeyType>
using CSTree = CSNode<KeyType>*;

template<class VertexType>
Status Insert2Child(CSNode<VertexType>*& treeNode, CSNode<VertexType>* newNode);
template<class VertexType>
Status Insert2leftChild(CSNode<VertexType>* &treeNode, CSNode<VertexType>* newNode);
template<class VertexType>
Status Insert2rightChild(CSNode<VertexType>* &treeNode, CSNode<VertexType>* newNode);

#endif
