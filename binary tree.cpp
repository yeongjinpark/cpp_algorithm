////n개의 정점을 갖는 이진트리
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable: 4996)
//
//int in[100], post[100], pre[100];
//
//void print_pre(int in1, int in2, int post1, int post2) {
//	int root, a, left;
//	if (in1 > in2 || post1 > post2) {
//		return;
//	}
//	root = post[post2];
//	printf("%d", root);
//
//	a = pre[root];
//	left = a - in1;
//
//	print_pre(in1, a - 1, post1, post1 + left - 1);
//	print_pre(a + 1, in2, post1 + left, post2 - 1);
//
//}
//
//
//int main() {
//	int n, i;
//
//
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {
//		scanf("%d", &in[i]);
//	}
//	for (i = 0; i < n; i++) {
//		scanf("%d", &post[i]);
//	}
//	for (i = 0; i < n; i++) {
//		pre[in[i]] = i;
//	}
//
//	print_pre(0, n - 1, 0, n - 1);
//
//}




///////전위순회한 트리를 후위순회
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//typedef struct Node {
// int data;
// struct Node* lchild;
// struct Node* rchild;
//}Node;
//
//typedef Node* Tree;
//
//Node* NewNode(int data); 
//void initTree(Tree* bst);
//int AddData(Tree* bst, int data);
//void Postorder(Node* sr);
//
//int main(void) {
//
// int array[100];
// Tree tree;
// int n, i;
//
// initTree(&tree);
//
// scanf("%d", &n);
// 
// printf("전위순회 입력: ");
//  for (i = 0; i < n; i++) {
//
//  scanf("%d", &array[i]);
//  AddData(&tree, array[i]);
//
// }
//
//
// printf("\n후위순회:");
// Postorder(tree);
//
// printf("\n");
//}
//
//Node* NewNode(int data) {
// Node* now = (Node*)malloc(sizeof(Node));
// now->data = data;
// now->lchild = now->rchild = NULL;
// return now;
//}
//
//void initTree(Tree* bst) {
// *bst = NULL;
//}
//
//int AddData(Tree* bst, int data) {
// Node* seek = *bst;
// int gap = 0;
// if (seek == NULL) {
//  (*bst) = NewNode(data);
//  return 1;
// }
// while (1) {
//  gap = seek->data - data;
//  if (gap == 0) { 
//   return 0; 
//  }
//
//  if (gap > 0) {
//   if (seek->lchild) {
//    seek = seek->lchild;
//   }
//   else {
//    seek->lchild = NewNode(data);
//    return 1;
//   }
//  }
//  else {
//   if (seek->rchild) {
//    seek = seek->rchild; 
//   }
//   else {
//    seek->rchild = NewNode(data);
//    return 1;
//   }
//
//
//  }
//
// }
// return 1;
//}
//
//
//
//void Postorder(Node* sr) {
// if (sr) {
//  Postorder(sr->lchild);
//  Postorder(sr->rchild);
//  printf("%d ", sr->data);
// }
//}