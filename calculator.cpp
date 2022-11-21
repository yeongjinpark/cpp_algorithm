////계산기

////계산기(우선순위o)

//#include<iostream>

//#include<string>

//#include<vector>

//#include <typeinfo>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template <typename T>

//struct ST_num {

//	T value;

//	struct ST_num* pre = nullptr;

//};

//

//template <typename T>

//class STACK_num {

//private:

//	ST_num<T>* top;

//

//public:

//	STACK_num() : top(nullptr) {}

//	~STACK_num() {}

//

//	void num_push(T _value) {

//		cout << _value << endl;

//		if (_value != -1) {

//		ST_num<T>* node = new ST_num<T>;

//		node->value = _value;

//

//			if (top == nullptr) {

//				top = node;

//			}

//			else {

//				node->pre = top;

//				top = node;

//			}

//		}

//	}

//

//	int num_pop() {

//		ST_num<T>* ptr = top;

//		int num = ptr->value;

//		top = top->pre;

//		delete ptr;

//		return num;

//	}

//

//	int num_clear(char sign) {

//		int val = num_pop();

//		int n = num_pop();

//		

//			switch (sign)

//				{

//					case '+':

//						n += val;

//						break;

//			

//					case '-':

//						n -= val;

//						break;

//			

//					case '*':

//						n *= val;

//						break;

//			

//					case '/':

//						n /= val;

//						break;

//					default:

//						break;

//				}

//		return n;

//	}

//};

//

//

//template <typename T>

//struct ST_sign {

//	char value;

//	struct ST_sign* pre = nullptr;

//};

//

//template <typename T>

//class STACK_sign {

//private:

//	ST_sign<T>* top;

//

//public:

//	STACK_sign() : top(nullptr) {}

//	~STACK_sign() {}

//

//	void sign_push(char _value) {

//		if (_value != -1) {

//			ST_sign<T>* node = new ST_sign<T>;

//			node->value = _value;

//

//			if (top == nullptr) {

//				top = node;

//			}

//			else {

//				node->pre = top;

//				top = node;

//			}

//		}

//	}

//

//	char sign_pop() {

//		ST_sign<T>* ptr = top;

//		char sign = ptr->value;

//		top = top->pre;

//		delete ptr;

//		cout << "sign_pop: " << sign << endl;

//		return sign;

//	}

//

//	int empty() {

//		if (top == NULL) {

//			return 1;

//		}

//		else {

//			return 0;

//		}

//	}

//

//	char sign_pre() {

//		ST_sign<T>* ptr = top;

//		char sign1 = ptr->value;

//		return sign1;

//	}

//};

//

//int main() {

//	string str;

//	cin >> str;

//	STACK_num<int> stack_num;

//	STACK_sign<int> stack_sign;

//	int start = 0, end = 0;

//	char c;

//

//	for (int i = 0; i < str.length(); i++) {

//		if (str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '=') {

//			

//			if (str[i] == '=') {

//				if (str[i - 1] != ')') {

//					end = i - start;

//					stack_num.num_push(stoi(str.substr(start, end)));

//					cout << start << "                    " << end << endl;

//					start = i + 1;

//				}

//				

//

//				cout << "stack_sign : " << stack_sign.empty() << endl;

//				while (stack_sign.empty() == 0) {

//					stack_num.num_push(stack_num.num_clear(stack_sign.sign_pop()));

//				}

//				cout << stack_num.num_pop() << endl;

//				return 0;

//			}

//

//			if (str[i] == '(') {

//				start++;

//			}

//

//			else if (str[i - 1] != ')') {

//				end = i - start;

//				stack_num.num_push(stoi(str.substr(start, end)));

//				cout << start << "                    " << end << endl;

//				start = i + 1;

//			}

//

//			if (stack_sign.empty() == 1 || str[i] == '(' || stack_sign.sign_pre() == '(' ) {

//				stack_sign.sign_push(str[i]);

//			}

//

//			else {

//				if (str[i] == '*' || str[i] == '/') {

//					stack_sign.sign_push(str[i]);

//				}

//				else if(str[i] == '+' || str[i] == '-') {

//					c = stack_sign.sign_pop();

//					stack_num.num_push(stack_num.num_clear(c));

//					stack_sign.sign_push(str[i]);

//				}

//

//				else if (str[i] == ')') {

//					c = stack_sign.sign_pop();

//

//					while (c !='(') {

//						stack_num.num_push(stack_num.num_clear(c));

//						c = stack_sign.sign_pop();

//					}

//

//				}

//			}

//		}

//

//	}

//

//}