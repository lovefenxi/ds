#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;//������ת��
typedef int KeyType;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
	
} Status;

typedef struct BiTNode {
	
		ElementType data;//����Ԫ��
	struct BiTNode *lchild;//����ָ��
	struct BiTNode *rchild; //�Һ���ָ��

} BiTNode, *BiTree;//�������ڵ�����


bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key);//�����������Ĳ���
Status InsertBST(BiTree &Root, KeyType key);     //����������δ�ҵ��ؼ��ֵĲ���͹���һ�ö���������,TreeΪ������ָ��
void PreOrderTraverse(BiTree Tree);//�������
void InOrderTraverse(BiTree Tree);//�������
void VisitBiTree(BiTree Tree);//������ڵ�
int Delete(BiTree &Tree);//ɾ���ڵ�
int DeleteBST(BiTree &Tree, KeyType key);//�����������ҵ��ؼ��ֵ�ɾ��


bool SearchBST(BiTree Tree, BiTree f, BiTree &p, KeyType key) {
	int flag = 0;//�ж��Ƿ���ҳɹ�
	if (!Tree) {
		p = f;
		flag = 0;//δ���ҳɹ�
		return false;
	}
	else if (key == Tree->data) {
		p = Tree;
		flag = 1; //���ҳɹ�
		return true;
	}
	else if (key < Tree->data) {//����������������
		flag = 0;
		return SearchBST(Tree->lchild, Tree, p, key);
		
	}
	else if (key > Tree->data) {//����������������
		flag = 0;
		return SearchBST(Tree->rchild, Tree, p, key);
		
	}
	
}

Status InsertBST(BiTree &Root, KeyType key)     //����������δ�ҵ��ؼ��ֵĲ���͹���һ�ö���������,TreeΪ������ָ��
 {
	BiTree p, s;
	if (!SearchBST(Root, NULL, p, key))    //���Ҳ��ɹ�
		 {
		s = (struct BiTNode *) malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (p == NULL)    //����������Ϊ�յ�ʱ�򣬽��*s������Ϊ�µĸ����
			 Root = s;
		else if (key < p->data)
			 p->lchild = s;//���*s����Ϊ����
		else
		     p->rchild = s;//���*s����Ϊ�Һ���
	     }
	

		return OK;
	
		}


void PreOrderTraverse(BiTree Tree)//�������
 {
	if (Tree != NULL) {
		
			printf("%d, ", Tree->data);
		PreOrderTraverse(Tree->lchild); //�������������
		PreOrderTraverse(Tree->rchild);//�������������
		
	}
	}


void InOrderTraverse(BiTree Tree)//�������
 {
	if (Tree != NULL) {
		
			InOrderTraverse(Tree->lchild);//�������������
		printf("%d, ", Tree->data);
		InOrderTraverse(Tree->rchild);//�������������
		
	}
	
		}

void VisitBiTree(BiTree Tree) //������ڵ�
 {
	if (Tree->data != ' ') {

		printf("%c ", Tree->data);
		
	}

 }

int Delete(BiTree &Tree)//ɾ���ڵ�
 {
	BiTree q, s;
	if (!Tree->rchild) {    //������Ϊ��
		q = Tree;
		Tree = Tree->lchild;//�ؽ�����������
		free(q);
		
	}
	else if (!Tree->lchild) {   //������Ϊ��
		q = Tree;
		Tree = Tree->rchild; //�ؽ�����������
		free(q);
		
	}
	else {  //������������Ϊ��
		q = Tree;
		s = Tree->lchild;
		while (s->rchild) {   //����������������ɾ����ǰ��
			q = s;
			s = s->rchild;
			
		}
		Tree->data = s->data;  //sָ��ɾ������ǰ��
		if (q != Tree) {
			q->rchild = s->lchild;//�ؽ�*q��������
			
		}
		else {
			q->lchild = s->lchild;//�ؽ�*q��������
			
		}
		delete s;
		
	}

	return true;

	}

int DeleteBST(BiTree &Tree, KeyType key)//�����������ҵ��ؼ��ֵ�ɾ��
 {
	if (!Tree)
		 return false;
	else {
		if (key == Tree->data) {
			return Delete(Tree);  //�ҵ��ؼ���Ϊkey������Ԫ��
			
		}
		else if (key < Tree->data) {
			return DeleteBST(Tree->lchild, key);//�ؼ���С�ڽ��Ļ�������������
			
		}
		else {
			return DeleteBST(Tree->rchild, key); //�ؼ��ִ��ڽ��Ļ�������������
			
		}
	
	}
	}

int main() {
	ElementType element[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	KeyType key[5] = { 13, 8, 5, 20, 6 };
	int i, j, n1, n2;
	BiTree Tree, pp;
		Tree = NULL;
		for (i = 0; i < 12; i++) {
		  
			InsertBST(Tree, element[i]);
	
	       }
	PreOrderTraverse(Tree);
	printf("\n");
	
		for (j = 0; j < 5; j++) {
		if (SearchBST(Tree, NULL, pp, key[j])) {
			DeleteBST(Tree, key[j]);
			PreOrderTraverse(Tree);
			printf("\n");
			
		}
		else {
			InsertBST(Tree, key[j]);
			PreOrderTraverse(Tree);
			printf("\n");
			
		}
		
	}
	
		return 0;
	
}