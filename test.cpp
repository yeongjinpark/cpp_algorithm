//#include <iostream>
//using namespace std;
//
//int t_case,N, S;
//int dot[301];
//
//int main()
//{
//	int res = S;
//	int tmp = 0;
//
//	cin >> t_case;
//
//	for (int i = 0; i < t_case; i++) {
//		cin >> N >> S;
//		for (int j = 0; j < N; j++) {
//			cin >> dot[j];
//
//		}
//		
//		for (int j = 0; j < N; j++) {
//			for (int k = j; k < N; k++) {
//				if (dot[j] > dot[k]) {
//					tmp = dot[j];
//					dot[j] = dot[k];
//					dot[k] = tmp;
//				}
//			}
//		}
//		int a = abs(S - dot[0]);
//		int b = abs(S - dot[N-1]);
//		
//
//		if (a < b) {
//			res = abs(S - dot[0]);
//			for (int j = 0; j < N - 1; j++) {
//				res += abs(dot[j] - dot[j + 1]);
//			}
//		}
//		else {
//			res = abs(S - dot[N-1]);
//			for (int j = N-1; j > 0; j--) {
//				res += abs(dot[j] - dot[j - 1]);
//			}
//		}
//		
//		cout <<"#" << i+1 << " " << res << endl;
//		
//	}
//}


////°ýÈ£ 2°³ ³ª¿­
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning(disable: 4996)
//
//struct data {
//	char str;
//	struct data* next;
//	struct data* pre;
//};
//
//struct data* head, *bmp, *tail;
//void push(char str);
//int pop(char str);
//void empty();
//
//int main(void) {
//	char arr[100];
//	char temp;
//	int i, n, j, len = 0;
//
//
//	for (i = 0; i < 1; i++) {
//		scanf("%s", &arr);
//		len = strlen(arr);
//
//		for (j = 0; j < len; j++) {
//			if (arr[j] == '(' || arr[j] == '[') {
//				push(arr[j]);
//			}
//
//			else if (arr[j] == ')' || arr[j] == ']') {
//				if (pop(arr[j] == 0)) {
//					break;
//				}
//			}
//
//		}
//		if (j < len) {
//			printf("no\n");
//		}
//		else {
//			empty();
//		}
//	}
//}
//
//
//
//void push(char str) {
//	bmp = (struct data*)malloc(sizeof(struct data));
//	bmp->str = str;
//
//	if (head == NULL) {
//		head = bmp;
//		head->pre = NULL;
//		head->next = NULL;
//	}
//	else {
//		bmp->pre = tail;
//	}
//	tail = bmp;
//	tail->next = NULL;
//}
//
//int pop(char str) {
//	char temp;
//	bmp = tail;
//
//	if (tail == NULL) {
//		return 0;
//	}
//
//	if (tail->str == '(') {
//		temp = ')';
//	}
//	else {
//		temp = ']';
//	}
//	if (temp != str) {
//		return 0;
//	}
//
//	tail = tail->pre;
//	free(bmp);
//	if (tail == NULL) {
//		head = NULL;
//	}
//	return 1;
//}
//
//void empty() {
//	bmp = tail;
//
//	if (tail == NULL) {
//		printf("yes\n");
//	}
//
//	else {
//		printf("no\n");
//	}
//}

//°ýÈ£¹®ÀÚ¿­

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)


struct data {
	int num;
	struct data* next;
	struct data* pre;
};

struct data* head, *bmp, *tail;
void push(int num);
void pop();
void empty();
void delllist();

int main(void) {
	char arr[100];
	int i, j, n;
	int len = 0, num = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", &arr);

		len = strlen(arr);

		for (j = 0; j < len; j++) {
			if (arr[j] == '(') {
				push(num);
			}
			else if (arr[j] == ')' && tail != NULL) {
				pop();
			}
			else {
				break;
			}
		}
		if (j < len) {
			printf("no\n");
		}
		else {
			empty();
			delllist();
		}
	}
}

void push(int num) {
	printf("push \n");
	bmp = (struct data*)malloc(sizeof(struct data));
	bmp->num = num;

	if (head == NULL) {
		head = bmp;
		head->pre = NULL;
		head->next = NULL;
	}
	else {
		bmp->pre = tail;
	}
	tail = bmp;
	tail->next = NULL;
	printf("tail: %d, bmp: %d, head: %d \n", tail, bmp, head);
}


void pop() {
	bmp = tail;
	printf("pop \n");
	tail = tail->pre;
	free(bmp);
	if (tail == NULL) {
		head = NULL;
	}
	printf("tail: %d, bmp: %d, head: %d \n", tail, bmp, head);
}

void empty() {
	bmp = tail;

	if (tail == NULL) {
		printf("yes\n");
	}

	else {
		printf("no\n");
	}
}

void delllist() {
	bmp = tail;
	while (bmp != NULL) {
		tail = tail->pre;
		free(bmp);
		bmp = tail;
	}
}