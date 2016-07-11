
#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"

int main(int argc,char*argv[])
{
	binarytreenode* root;
	root = createBinaryTree(10);
	inorder(root);
}
