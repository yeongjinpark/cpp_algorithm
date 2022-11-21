//////루트없는 트리에서 각 노드의 부모를 구하는 프로그램
//#include<stdio.h>
//#pragma warning(disable: 4996)
//
//int Graph[1001][1001] = { 0 };
//int BFSvisit[1001] = { 0 };
//int queue[1001];
//int array[1001];
//
//void BFS(int v, int N) {
//	int front = 0, rear = 0, pop, i;
//
//
//	queue[0] = v;
//	rear++;
//	BFSvisit[v] = 1;
//
//	while (front < rear) {
//		pop = queue[front];
//		front++;
//
//		for (i = 1; i <= N; i++) {
//			if (Graph[pop][i] == 1 && BFSvisit[i] == 0) {
//				queue[rear] = i;
//				rear++;
//				BFSvisit[i] = 1;
//				array[i] = pop;
//			}
//		}
//	}
//	printf("\n");
//	for (i = 2; i <= N; i++) {
//		printf("%d ", array[i]);
//	}
//
//	return;
//}
//
//
//int main() {
//	int N;
//	int i, x, y;
//
//	scanf("%d", &N);
//
//	for (i = 0; i < N - 1; i++) {
//		scanf("%d %d", &x, &y);
//		Graph[x][y] = 1;
//		Graph[y][x] = 1;
//	}
//	printf("\n");
//	BFS(1, N);
//
//
//	return 0;
//
//}

//////전위순회한 트리를 bfs로 전환
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//int Graph[1001] = { 0 };
//int BFSvisit[1001] = { 0 };
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
//void bfs(Tree* bst,int v, int n);
//
//int main(void) {
// int arr[100];
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
//  scanf("%d", &arr[i]);
//  AddData(&tree, arr[i]);
// }
//  bfs(&tree, 1, n);
//
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
//void bfs(Tree* bst ,int v, int n) {
// Node* tree = *bst;
// Node* queue[1001];
// Node* pop;
// int array[100];
// int front = 0, rear = 0, i;
//
// queue[0] = tree;
// rear++;
// 
// printf("root:%d \n", tree->data);
// printf("left:%d \n", tree->lchild->data);
// printf("right:%d \n", tree->rchild->data);
//
// while (front < rear) {
//  pop = queue[front];
//  front++;
//  printf("pop: %d \n", pop->data);
//  array[front] = pop->data;
//  if (pop->lchild) {
//   printf("left: %d \n", pop->lchild->data);
//   queue[rear] = pop->lchild;
//   rear++;
//  }
//  if (pop->rchild) {
//   printf("right: %d \n", pop->rchild->data);
//   queue[rear] = pop->rchild;
//   rear++;
//  }
// }
// for (i = 1; i <= n; i++) {
//  printf("%d\n", array[i]);
// }
//
//
// return;
//
//}





////트리 지름 구하기2
//#include<stdio.h>
//#pragma warning(disable: 4996)
//
//int Graph[1001][1001] = { 0 };
//int BFSvisit[1001] = { 0 };
//int queue[1001];
//
//
//void BFS(int v, int N) {
// int front = 0, rear = 0, pop, i;
// int max = 0;
// int a;
//
//
// queue[0] = v;
// rear++;
// BFSvisit[v] = 1;
//
// while (front < rear) {
//  pop = queue[front];
//  front++;
//
//  a = rear;
//  for (i = 1;i <= N;i++) {
//   if (Graph[pop][i] == 1 && BFSvisit[i] == 0) {
//    queue[rear] = i;
//    rear++;
//    BFSvisit[i] = BFSvisit[pop] + 1;
//  
//   }
//  }
//  if (a == rear) {
//   printf("%d : %d \n", pop, BFSvisit[pop]);
//  }
// }
//
//
//
// /*for (i = 0;i < N;i++) {
//  if (BFSvisit[i]>max) {
//  max = BFSvisit[i];
//  }
// }
// printf("%d", max);*/
//
// return;
//}
//
//int main() {
// int N;
// int i, x, y;
// 
// scanf("%d", &N);
// 
// for (i = 0; i < N-1; i++) {
//  scanf("%d %d", &x, &y);
//  Graph[x][y] = 1;
//  Graph[y][x] = 1;
// }
// printf("\n");
// BFS(1, N);
//
// return 0;
//}
//


////루트 없는 트리->BFS
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//int Graph[1001][1001] = { 0 };
//int BFSvisit[1001] = { 0 };
//int queue[1001];
//int array[1001];
//
//typedef struct Node {
//	int data;
//	struct Node* lchild;
//	struct Node* rchild;
//}Node;
//
//typedef Node* Tree;
//
//Node* NewNode(int data);
//void initTree(Tree* bst);
//int AddData(Tree* bst, int data1, int data2, int v);
//void BFS(Tree* bst, int v, int n);
//
//int main() {
//	int arr1[100];
//
//
//	Tree tree;
//	int n, i;
//
//	initTree(&tree);
//
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {
//
//		scanf("%d %d", &arr1[i]);
//		AddData(&tree, arr1[i]);
//	}
//
//
//}
//
//Node* NewNode(int data) {
//	Node* now = (Node*)malloc(sizeof(Node));
//	now->data = data;
//	now->lchild = now->rchild = NULL;
//	return now;
//}
//
//void initTree(Tree* bst) {
//	*bst = NULL;
//}
//
//int AddData(Tree* bst, int data1, int data2, int v) {
//	Node* seek = *bst;
//	Node* pop;
//	int front = 0, rear = 0, i;
//
//	queue[0] = v;
//	rear++;
//
//	if (seek == NULL) {
//		(*bst) = NewNode(data1);
//		return 1;
//	}
//
//	while (1) {
//		pop = queue[front];
//		front++;
//
//
//		if (pop->lchild) {
//			pop->lchild = NewNode();
//			queue[rear] = pop->lchild;
//			rear++;
//		}
//
//
//
//		if (pop->rchild) {
//			pop->rchild = NewNode();
//
//		}
//
//
//	}
//
//
//
//}
//
//
//void BFS(Tree* bst, int v, int n) {
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


//////전위순회한 트리를 bfs로 전환
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//int Graph[1001] = { 0 };
//int BFSvisit[1001] = { 0 };
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
//void bfs(Tree* bst,int v, int n);
//
//int main(void) {
// int arr[100];
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
//  scanf("%d", &arr[i]);
//  AddData(&tree, arr[i]);
// }
//  bfs(&tree, 1, n);
//
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
//void bfs(Tree* bst ,int v, int n) {
// Node* tree = *bst;
// Node* queue[1001];
// Node* pop;
// int array[100];
// int front = 0, rear = 0, i;
//
// queue[0] = tree;
// rear++;
// 
// printf("root:%d \n", tree->data);
// printf("left:%d \n", tree->lchild->data);
// printf("right:%d \n", tree->rchild->data);
//
// while (front < rear) {
//  pop = queue[front];
//  front++;
//  printf("pop: %d \n", pop->data);
//  array[front] = pop->data;
//  if (pop->lchild) {
//   printf("left: %d \n", pop->lchild->data);
//   queue[rear] = pop->lchild;
//   rear++;
//  }
//  if (pop->rchild) {
//   printf("right: %d \n", pop->rchild->data);
//   queue[rear] = pop->rchild;
//   rear++;
//  }
// }
// for (i = 1; i <= n; i++) {
//  printf("%d\n", array[i]);
// }
//
//
// return;
//
//}


////트리 지름 구하기2
//#include<stdio.h>
//#pragma warning(disable: 4996)
//
//int Graph[1001][1001] = { 0 };
//int BFSvisit[1001] = { 0 };
//int queue[1001];
//
//
//void BFS(int v, int N) {
// int front = 0, rear = 0, pop, i;
// int max = 0;
// int a;
//
//
// queue[0] = v;
// rear++;
// BFSvisit[v] = 1;
//
// while (front < rear) {
//  pop = queue[front];
//  front++;
//
//  a = rear;
//  for (i = 1;i <= N;i++) {
//   if (Graph[pop][i] == 1 && BFSvisit[i] == 0) {
//    queue[rear] = i;
//    rear++;
//    BFSvisit[i] = BFSvisit[pop] + 1;
//  
//   }
//  }
//  if (a == rear) {
//   printf("%d : %d \n", pop, BFSvisit[pop]);
//  }
// }
//
//
//
// /*for (i = 0;i < N;i++) {
//  if (BFSvisit[i]>max) {
//  max = BFSvisit[i];
//  }
// }
// printf("%d", max);*/
//
// return;
//}
//
//int main() {
// int N;
// int i, x, y;
// 
// scanf("%d", &N);
// 
// for (i = 0; i < N-1; i++) {
//  scanf("%d %d", &x, &y);
//  Graph[x][y] = 1;
//  Graph[y][x] = 1;
// }
// printf("\n");
// BFS(1, N);
//
// return 0;
//}
//


////루트 없는 트리->BFS
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//
//int queue[1001];
//int array[1001];
//int x[1001];
//int y[1001];
//
//
//typedef struct Node {
//	int data;
//	struct Node* lchild;
//	struct Node* rchild;
//}Node;
//
//typedef Node* Tree;
//
//Node* NewNode(int data);
//void initTree(Tree* bst);
//int AddData(Tree* bst, int data1, int data2, int v, int n);
//void BFS(Tree* bst, int v, int n);
//
//int main() {
//	Tree tree;
//	int n, i;
//
//	initTree(&tree);
//
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {
//
//		scanf("%d %d", &x[i], &y[i]);
//		AddData(&tree, &x[i], &y[i], 1, n);
//	}
//
//
//}
//
//Node* NewNode(int data) {
//	Node* now = (Node*)malloc(sizeof(Node));
//	now->data = data;
//	now->lchild = now->rchild = NULL;
//	return now;
//}
//
//void initTree(Tree* bst) {
//	*bst = NULL;
//}
//
//int AddData(Tree* bst, int data1, int data2, int v, int n) {
//	Node* seek = *bst;
//	Node* arr[1001];
//	int used[100] = { 0, };
//	int flag = 0;
//
//	int front = 0, rear = 0, i;
//
//	if (seek == NULL) {
//		return 1;
//	}
//
//	arr[front] = seek;
//	rear++;
//
//	while (front < rear) {
//		flag = 0;
//		for (i = 0; i < n; i++) {
//			if ((x[i] == arr[front]->data || y[i] == arr[front]->data) && used[i] == 0) {
//				if (x[i] == arr[front]->data) {
//					if (flag == 0) {
//						arr[front]->lchild = NewNode(y[i]);
//						arr[rear] = arr[front]->lchild;
//						rear++;
//						flag = 1;
//					}
//					else {
//						arr[front]->rchild = NewNode(y[i]);
//						arr[rear] = arr[front]->rchild;
//						rear++;
//					}
//					front++;
//				}
//				else {
//					if (flag == 0) {
//						arr[front]->lchild = NewNode(x[i]);
//						arr[rear] = arr[front]->lchild;
//						rear++;
//						flag = 1;
//					}
//					else {
//						arr[front]->rchild = NewNode(x[i]);
//						arr[rear] = arr[front]->rchild;
//						rear++;
//					}
//					front++;
//				}
//				used[i] = 1;
//			}
//		}
//	}
//
//}
//
//
//void BFS(Tree* bst, int v, int n) {
//
//}




////카카오 프렌즈 컬러링북 문제
//
//#include<iostream>
//
//#include<vector>
//
//using namespace std;
//
//
//
//int arr[101][101];
//
//bool visit[100][100] = { false, };
//
//int n, m;
//
//int cnt;
//
//
//
//int dx[4] = { 0,0,1,-1 };
//
//int dy[4] = { -1,1,0,0 };
//
//
//
//
//
//int max(int a, int b) {
//
//	return a > b ? a : b;
//
//}
//
//
//
//int dfs(int x, int y) {
//
//	int count = 1;
//
//
//
//	for (int i = 0; i < 4; i++) {
//
//		int next_x = x + dx[i];
//
//		int next_y = y + dy[i];
//
//
//
//		if (visit[next_x][next_y]) continue;
//
//		if (!visit[next_x][next_y] && arr[next_x][next_y] == arr[x][y]) {
//
//			visit[next_x][next_y] = true;
//
//			count += dfs(next_x, next_y);
//
//		}
//
//	}
//
//	return count;
//
//}
//
//
//
//int main() {
//
//	int max_res = 0;
//
//	cin >> m >> n;
//
//	for (int i = 0; i < m; i++) {
//
//		for (int j = 0; j < n; j++) {
//
//			cin >> arr[i][j];
//
//		}
//
//	}
//
//
//
//	for (int i = 0; i < m; i++) {
//
//		for (int j = 0; j < n; j++) {
//
//			if (!visit[i][j] && arr[i][j] > 0) {
//
//				cnt++;
//
//				visit[i][j] = true;
//
//				int tmp = dfs(i, j);
//
//				max_res = max(tmp, max_res);
//
//			}
//
//			cout << visit[i][j];
//
//		}
//
//		cout << endl;
//
//	}
//
//	cout << endl;
//
//	cout << cnt << " " << max_res << endl;
//
//
//
//}


