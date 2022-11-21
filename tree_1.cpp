////트리
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable: 4996)
//
//typedef struct Node {
//	char ele;
//	struct Node* left;
//	struct Node* right;
//} Node;
//
//Node *NewNode(char ele) {
//	Node *New;
//	New = (Node*)malloc(sizeof(Node));
//	New->ele = ele;
//	New->left = NULL;
//	New->right = NULL;
//	return New;
//}
//
//Node* search_Node(Node* H, char ele) {
//	if (H != NULL) {
//		if (H->ele == ele) {
//			return H;
//		}
//		else {
//			Node* tmp = search_Node(H->left, ele);
//			if (tmp != NULL) {
//				return tmp;
//			}
//			return search_Node(H->right, ele);
//		}
//	}
//	return NULL;
//}
//void insert_Node(Node* H, char A, char B, char C) {
//	H->ele = A;
//	printf("H: %c \n", H->ele);
//	if (B != '.') {
//		H->left = NewNode(B);
//		printf("H->left: %c \n", H->left->ele);
//	}
//	if (C != '.') {
//		H->right = NewNode(C);
//		printf("H->right: %c \n", H->right->ele);
//	}
//}
//
//void print_pre(Node* H) {    //출력하는 위치에 따라 전위, 중위, 후위 달라짐
//	if (H != NULL) {                 //출력하는 위치가 앞쪽-> 전위순회
//		printf("%c\n", H->ele);
//	}
//	if (H->left != NULL) {
//		print_pre(H->left);
//	}
//
//	//if (H != NULL) {                 //출력하는 위치가 중간-> 중위순회
//	// printf("%c\n", H->ele);
//	//}
//
//	if (H->right != NULL) {
//		print_pre(H->right);
//	}
//
//	//if (H != NULL) {                 //출력하는 위치가 뒤 -> 후위순회
//	// printf("%c\n", H->ele);
//	//}
//}
//
//int main() {
//	Node* H = NewNode(NULL);
//	Node* tmp;
//	int N;
//	int i;
//	char A, B, C;
//	scanf("%d", &N);
//	getchar();
//
//	for (i = 0; i < N; i++) {
//		scanf("%c %c %c", &A, &B, &C);
//		getchar();
//		tmp = search_Node(H, A);
//		if (tmp != NULL) {
//			insert_Node(tmp, A, B, C);
//		}
//		else {
//			printf("H->: %c", H->ele);
//			insert_Node(H, A, B, C);
//		}
//	}
//	print_pre(H);
//}