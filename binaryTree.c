#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BiTNode,*BiTree;
//函数声明
void CreateBiTree(BiTNode **T);
void PreOrderBitree(BiTNode *T);
void MiddleOrderBitree(BiTNode *T);
void PostOrderBitree(BiTNode *T);
int TreeDeep(BiTNode *T);
int LeafCount(BiTNode *T);
int main(int argc,const char *argv[]){
	BiTNode *T;
	int j;
	int depth,leafCount=0;
	printf("请输入第一个节点的值，-1表示没有叶节点：\n");
	CreateBiTree(&T);
	printf("先序遍历二叉树：");
	PreOrderBitree(T);
	printf("中序遍历二叉树：");
	printf("\n");
    MiddleOrderBitree(T);
	printf("\n");
	printf("后序遍历二叉树：");
	PostOrderBitree(T);
	printf("\n");
	depth=TreeDeep(T);
	printf("树的深度为：%d\n",depth);
	leafCount=LeafCount(T);
	printf("叶子结点个数为:%d\n",leafCount);
	scanf("%d",&j);
	return 0;
}
//先序遍历
void CreateBiTree(BiTNode **T){//指针的指针
	int ch;
	scanf("%d",&ch);
	if(ch==-1){
		*T=NULL;//叶子结点
		return;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		if(*T==NULL){
			printf("内存分配失败!\n");
			exit(-1);
		}else{
			(*T)->data=ch;
			printf("输入%d的左子节点",ch);
			CreateBiTree(&((*T)->lchild));
			printf("输入%d的右子节点",ch);
			CreateBiTree(&((*T)->rchild));
		}

	}
}
//先序遍历二叉树
void PreOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		printf("%d",T->data);
		PreOrderBitree(T->lchild);
		PreOrderBitree(T->rchild);
	}
}
//中序遍历
void MiddleOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		MiddleOrderBitree(T->lchild);
		printf("%d",T->data);
		MiddleOrderBitree(T->rchild);
	}
	
}
//后续遍历
void PostOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		PostOrderBitree(T->lchild);
		PostOrderBitree(T->rchild);
		printf("%d",T->data);
	}
}
//二叉树的深度
int TreeDeep(BiTNode *T){
	int deep=0;
	if(T==NULL){
		return deep;
	}else{
		int leftdeep=TreeDeep(T->lchild);
		int rightdeep=TreeDeep(T->rchild);
		deep=leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
		return deep;
	}
}
//叶子结点个数
int LeafCount(BiTNode *T)
{
	static int count;
	if(T!=NULL){
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			count++;
		}
		LeafCount(T->lchild);
		LeafCount(T->rchild);
	}
	return count;
}
