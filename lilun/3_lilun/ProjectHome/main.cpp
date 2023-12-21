#include <stdlib.h>

#include "CSTree.h"
#include "CSTree.cpp"

int main(int argc,char* argv[]) {

	Status stt;

	//ºÚµ•≤‚ ‘
	CSTree<int> troot = (CSNode<int>*)malloc(sizeof(CSNode<int>));
	if (NULL == troot) {
		return -1;
	}

	troot->lchild = NULL;
	troot->nextsibling = NULL;

	CSNode<int>* aNode = (CSNode<int>*)malloc(sizeof(CSNode<int>));
	stt = Insert2rightChild(troot, aNode);

	free(troot);
	free(aNode);

	return 0;
}
