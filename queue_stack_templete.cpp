////실습 10-1

//#include<iostream>

//using namespace std;

//

//

//template<typename Type>

//Type add(Type x, Type y) {

//	return x + y;

//}

//

////template<typename Type1, typename Type2>

////Type2 add(Type1 x, Type2 y) {

////	return x + y;

////}

//

//

//

//int main() {

//	int a = add(3, 4);

//	double b = add(3.4, 5.3);

//	double c = add(3.0, 4.5);

//

//	cout << "a: " << a << ", b:" << b<< endl;

//	cout << ", c:" << c <<endl;

//}





////실습10-8

//#include<iostream>

//using namespace std;

//

//template<typename Type>

//class Add {

//private:

//	Type x;

//	Type y;

//

//public:

//	Add(Type x, Type y) :

//		x(x),y(y){

//

//	}

//

//	void getresult() {

//		Type z = x + y;

//		cout << "\nresult: " << z;

//	}

//};

//

//

//template<> void Add<char>::getresult() {

//	char str[3];

//	str[0] = x;

//	str[1] = y;

//	str[2] = '\0';

//

//	cout << "\nresult: " << str;

//}

//

//int main() {

//	Add<int> a1(1, 2);

//	a1.getresult();

//

//	Add<double> a0(1.2, 2.1);

//	a0.getresult();

//

//	Add<char> a2('x', 'y');

//	a2.getresult();

//

//	return 0;

//}









////실습 10-9

//#include<iostream>

//using namespace std;

//

//template<typename Type>

//class Add {

//private:

//	Type x;

//	Type y;

//	Type z;

//

//public:

//	Add(Type x, Type y) :

//		x(x), y(y) {

//

//	}

//

//	void getresult() {

//		z = x + y;

//	}

//

//	void printresult() {

//		cout << "result: " << z << endl;

//	}

//};

//

//template<>

//class Add<char> {

//private:

//	char x;

//	char y;

//	char z[3];

//

//public:

//	Add(char x, char y) :

//		x(x), y(y) {

//

//	}

//

//	void getresult() {

//		z[0] = x;

//		z[1] = y;

//		z[2] = '\0';

//	}

//

//	void printresult() {

//		cout << "result: " << z << endl;

//	}

//};

//

//int main() {

//	Add<int> a1(1, 2);

//	a1.getresult();

//	a1.printresult();

//

//	Add<double> a0(1.2, 2.1);

//	a0.getresult();

//	a0.printresult();

//

//	Add<char> a2('x', 'y');

//	a2.getresult();

//	a2.printresult();

//

//	return 0;

//}











////싱글링크드리스트

//#include<iostream>

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//};

//

//template <typename T>

//class Singlelinked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//public:

//	Singlelinked_list(): head(nullptr),tail(nullptr){}

//	~Singlelinked_list() {}

//

//	void AddNode(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//		}

//

//		else {

//			tail->next = node;

//			tail = tail->next;

//		}

//	}

//

//	void Removenode(T _value) {

//		Node<T>* ptr = head;

//		Node<T>* tmp = ptr;

//

//		while (ptr != nullptr) {

//			if (ptr->value == _value) {

//				break;

//			}

//			else {

//				tmp = ptr;

//				ptr = ptr->next;

//			}

//		}

//

//		if (ptr == nullptr) {

//			cout << "찾을 수 없는 노드입니다." << endl;

//		}

//		else {

//			size--;

//			cout << "삭제된 노드의 값: " << ptr->value<<endl;

//			tmp->next = ptr->next;

//			delete ptr;

//		}

//	}

//

//	void show() {

//		Node<T>* node = head;

//

//		while (node != nullptr) {

//			cout << node->value << "->";

//			node = node->next;

//		}

//		cout << endl;

//	}

//

//	void Deletelist() {

//		Node<T>* ptr = head;

//

//		while (ptr != nullptr) {

//			head = ptr -> next;

//			delete ptr;

//			ptr = head;

//		}

//		delete head;

//		size = 0;

//		cout << "리스트가 삭제되었습니다," << endl;

//	}

//

//	void Removetail() {

//		Node<T>* ptr = head;

//		Node<T>* tmp = new Node<T>;

//

//		while (ptr->next != nullptr) {

//			tmp = ptr;

//			ptr = ptr->next;

//		}

//		size--;

//		tail = tmp;

//		tail->next = nullptr;

//		delete ptr;

//	}

//

//	void Removehead() {

//		Node<T>* ptr = head;

//		head = ptr->next;

//		size--;

//		delete ptr;

//	}

//

//	void Addhead(T _value) {

//		Node<T>* ptr = new Node<T>();

//

//		size++;

//		ptr->next = head;

//		ptr->value = _value;

//		head = ptr;

//	}

//

//	void Addposition(int _index, T _value) {

//		if (size<_index || 0>_index) {

//			cout << "해당하는 인덱스값은 없습니다," << endl;

//			return;

//		}

//

//		Node<T>* ptr = head;

//		Node<T>* tmp = ptr;

//		Node<T>* node = new Node<T>;

//

//		node->value = _value;

//		node->next = nullptr;

//

//		for (int i = 0; i < _index - 1; i++) {

//			tmp = ptr;

//			ptr = ptr->next;

//		}

//		tmp->next = node;

//		node->next = ptr;

//		size++;

//	}

//

//	void Searchvalude(T _value) {

//		Node<T>* ptr = head;

//		int index = 0;

//		bool isFind = false;

//

//		while (ptr != nullptr) {

//			index++;

//			if (ptr->value == _value) {

//				cout << _value << "값은 인덱스" << index << "번째있습니다," << endl;

//				isFind = true;

//				break;

//			}

//			ptr = ptr->next;

//		}

//		if (isFind == false) {

//			cout << _value << "값은 리스트에 없습니다" << endl;

//		}

//	}

//

//	int Size() {

//		return size;

//	}

//};

//

//int main() {

//	Singlelinked_list<int> list;

//

//	list.AddNode(10);

//	list.AddNode(11);

//	list.AddNode(14);

//	list.AddNode(18);

//	list.AddNode(1);

//	list.Addposition(2, 7);

//	list.show();

//	list.Searchvalude(10);

//	cout << "리스트의 크기" << list.Size() << endl;

//

//	list.Addhead(4);

//	list.AddNode(9);

//	list.show();

//

//	list.Removehead();

//	list.show();

//	list.Removetail();

//	list.Removenode(14);

//	list.Searchvalude(14);

//

//	list.show();

//	cout << "리스트의 크기" << list.Size() << endl;

//

//	list.Deletelist();

//	list.AddNode(10);

//	list.show();

//	cout << "리스트의 크기" << list.Size() << endl;

//

//	return 0;

//}









////정수 저장하는 큐-싱글리스트

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//		}

//

//		else {

//			tail->next = node;

//			tail = tail->next;

//		}

//	}

//

//	void pop() {

//		Node<T>* ptr = head;

//		if (head == nullptr) {

//			cout << "-1" << endl;		

//		}

//		else {

//			cout << head->value << endl;

//			head = ptr->next;

//			size--;

//			delete ptr;

//		}

//	}

//

//	void size1() {

//		if (size < 0) {

//			size = 0;

//		}

//		cout << size << endl;

//	}

//

//	void empty() {

//		if (head == nullptr) {

//			cout << "1" << endl;

//		}

//		else {

//			cout << "0" << endl;

//		}

//	}

//

//	void front() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << head->value << endl;

//		}

//	}

//

//	void back() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << tail->value << endl;

//		}

//	}

//};

//

//int main() {

//	linked_list<int> list;

//	int n,x;

//	string s;

//

//	cin >> n;

//

//	for (int i = 0; i < n; i++) {

//		cin >> s;

//

//		if (s == "push") {

//			cin >> x;

//			list.push(x);

//		}

//

//		else if (s == "pop") {

//			list.pop();

//		}

//

//		else if (s == "size") {

//			list.size1();

//		}

//

//		else if (s == "empty") {

//			list.empty();

//		}

//

//		else if (s == "front") {

//			list.front();

//		}

//

//		else if (s == "back") {

//			list.back();

//		}

//	}

//}











////정수를 저장하는 큐 || 스택-2중링크드

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//	}

//

//	void pop() {

//		//정수를 저장하는 2중 링크드 큐

//		//Node<T>* ptr = head;

//

//		//if (head == nullptr) {

//		//	cout << "-1" << endl;

//		//}

//		//else {

//		//	cout << head->value << endl;

//		//	head = head->next;

//		//	size--;

//		//	delete ptr;

//		//}

//

//

//		//정수를 저장하는 2중 링크드 스택

//		Node<T>* ptr = tail;

//		cout << "head" << head << endl;

//		cout << "tail" << tail << endl;

//

//		if (tail == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << tail->value << endl;

//			tail = tail->pre;

//			size--;

//			delete ptr;

//		}

//	}

//

//	void size1() {

//		if (size < 0) {

//			size = 0;

//		}

//		cout << size << endl;

//	}

//

//	void empty() {

//		if (head == nullptr) {

//			cout << "1" << endl;

//		}

//		else {

//			cout << "0" << endl;

//		}

//	}

//

//	void front() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << head->value << endl;

//		}

//	}

//

//	void back() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << tail->value << endl;

//		}

//	}

//};

//

//int main() {

//	linked_list<int> list;

//	int n, x;

//	string s;

//

//	cin >> n;

//

//	for (int i = 0; i < n; i++) {

//		cin >> s;

//

//		if (s == "push") {

//			cin >> x;

//			list.push(x);

//		}

//

//		else if (s == "pop") {

//			list.pop();

//		}

//

//		else if (s == "size") {

//			list.size1();

//		}

//

//		else if (s == "empty") {

//			list.empty();

//		}

//

//		else if (s == "front") {

//			list.front();

//		}

//

//		else if (s == "back") {

//			list.back();

//		}

//	}

//}













////n장의 카드

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//

//	void push(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//	

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//			tail->next = nullptr;

//	}

//

//	int pop() {

//		Node<T>* ptr = head;

//

//		int num = head->value;

//		head = head->next;

//		size--;

//		delete ptr;

//		return num;

//	}

//	

//	int size1() {

//		retrun size;

//	}

//}

//

//int main() {

//	linked_list<int> list;

//	int i, n, a=0;

//	int flag = 0;

//

//	cin >> n;

//

//	for (i = 0; i < n; i++) {

//		list.push(i+1);

//	}

//

//	while (1) {

//		if (flag == 0) {

//			a=list.pop();

//			if (size() == 1) {

//				cout << a << endl;

//				break;

//			}

//			flag = 1;

//		}

//

//		else {

//			a = list.pop();

//			list.push(a);

//			flag = 0;

//		}

//	}

//}



////n장의 카드 한 장 남을떄까지 반복

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//

//	void push(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//	}

//

//	int pop() {

//		Node<T>* ptr = head;

//

//		int num = head->value;

//		head = head->next;

//		size--;

//		delete ptr;

//		return num;

//	}

//

//	int size1() {

//		return size;

//	}

//};

//

//int main() {

//	linked_list<int> list;

//	int i, n, a = 0;

//	int flag = 0;

//

//	cin >> n;

//

//	for (i = 0; i < n; i++) {

//		list.push(i + 1);

//	}

//

//	while (1) {

//		if (flag == 0) {

//			a = list.pop();

//			if (list.size1()== 1) {

//				cout << list.pop()<< endl;

//				break;

//			}

//			flag = 1;

//		}

//

//		else if(flag==1) {

//			a = list.pop();

//			list.push(a);

//			flag = 0;

//		}

//	}

//}









////프린터 큐

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	T target;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//	int cnt = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push(T _value, T _target) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->target = _target;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//	}

//	

//	int max() {

//		Node<T>* ptr = head;

//		int max1 = 0;

//

//		while (ptr != nullptr) {

//			if (max1 < ptr->value) {

//				max1 = ptr->value;

//			}

//			ptr = ptr->next;

//		}

//		return max1;

//	}

//

//	int pop() {

//		Node<T>* ptr = head;

//		int t = head->target; 

//		int num = head->value;

//		if (head->next != nullptr) {

//			if (max() == num) {

//				cnt = cnt + 1;

//				if (t == 1) {

//					cout << cnt << endl;

//					return 1;

//				}

//			}

//			else {

//				push(num, t);

//			}

//			head = head->next;

//			size--;

//			delete ptr;

//			return 0;

//		}

//		else {

//			cnt++;

//			cout << cnt << endl;

//			return 1;

//		}

//	}

//

//};

//

//int main() {

//	int i, n,j;

//	int a, b, max=0;

//	int arr[100];

//	cin >> n;

//

//	for (i = 0; i < n; i++) {

//		linked_list<int> list;

//		cin >> a >> b;

//

//		for (j = 0; j < a; j++) {

//			cin >> arr[j];

//			if (b == j) {

//				list.push(arr[j], 1);

//			} else {

//				list.push(arr[j], 0);

//			}

//		}

//

//		while (1) {

//			if (list.pop() == 1) {

//				break;

//			}

//		}

//	}

//}





//

////요세푸스- 원형 큐

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	int value;

//	struct Node<int>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template<typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push(T _value) {

//		Node<T>* node = new Node<T>;

//

//		node->value = _value;

//		node->next = nullptr;

//		size++;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = head;

//		head->pre = tail;

//

//	}

//

//

//	void pop(int x) {

//		Node<T>* ptr = head;

//		int count = 1;

//		if (size > 1) {

//			for (count = 1; count < x; count++) {

//				ptr = ptr->next;

//			}

//			ptr->pre->next = ptr->next;

//			ptr->next->pre = ptr->pre;

//			head = ptr->next;

//			tail = ptr->pre;

//			size--;

//		}

//		cout << ptr->value << " ";

//		delete ptr;

//	}

//

//};

//

//

//int main() {

//	linked_list<int> list;

//	int i, a, b;

//

//	cin >> a >> b;

//

//	for (i = 0; i < a; i++) {

//		list.push(i + 1);

//	}

//

//	for (i = 0; i < a; i++) {

//		list.pop(b);

//	}

//}









////정수를 저장하는 덱

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int size = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push_front(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->next = head;

//			head->pre = node;

//			head = head->pre;

//		}

//		head->pre = nullptr;

//	}

//

//	void push_back(T _value) {

//		Node<T>* node = new Node<T>;

//		size++;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//	}

//

//

//	void pop_front() {

//		Node<T>* ptr = head;

//		if (head == nullptr || tail==nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << head->value << endl;

//			head = ptr->next;

//			cout << "haed: " << head->value << "back: " << tail->value << endl;

//			if (size == 1) {

//				head = nullptr;

//				tail = nullptr;

//			}

//			size--;

//			delete ptr;

//		}

//	}

//

//	void pop_back() {

//		Node<T>* ptr = tail;

//

//		if (tail == nullptr || head==nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << tail->value << endl;

//			tail = ptr->pre;

//			cout << "haed: " << head->value << "back: " << tail->value << endl;

//			if (size == 1) {

//				head = nullptr;

//				tail = nullptr;

//			}

//			size--;

//			delete ptr;

//		}

//	}

//

//	void size1() {

//		if (size < 0) {

//			size = 0;

//		}

//		cout << size << endl;

//	}

//

//	void empty() {

//		if (head == nullptr) {

//			cout << "1" << endl;

//		}

//		else {

//			cout << "0" << endl;

//		}

//	}

//

//	void front() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << head->value << endl;

//		}

//	}

//

//	void back() {

//		if (head == nullptr) {

//			cout << "-1" << endl;

//		}

//		else {

//			cout << tail->value << endl;

//		}

//	}

//};

//

//int main() {

//	linked_list<int> list;

//	int n, x;

//	string s;

//

//	cin >> n;

//

//	for (int i = 0; i < n; i++) {

//		cin >> s;

//

//		if (s == "push_front") {

//			cin >> x;

//			list.push_front(x);

//		}

//

//		else if (s == "push_back") {

//			cin >> x;

//			list.push_back(x);

//		}

//

//		else if (s == "pop_front") {

//			list.pop_front();

//		}

//

//		else if (s == "pop_back") {

//			list.pop_back();

//		}

//

//		else if (s == "size") {

//			list.size1();

//		}

//

//		else if (s == "empty") {

//			list.empty();

//		}

//

//		else if (s == "front") {

//			list.front();

//		}

//

//		else if (s == "back") {

//			list.back();

//		}

//	}

//}







////양방향 순환 큐

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int cnt_l = 0;

//	int cnt_r = 1;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push_back(T _value) {

//		cout << endl << endl << "push b" << endl;

//		Node<T>* node = new Node<T>;

//

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//		cout << "head: " << head->value << endl;

//		cout << "tail: " << tail->value << endl;

//		cout << "node: " << node->value << endl;

//	}

//

//	void push_front(T _value) {

//		cout << endl << endl << "push f" << endl;

//		Node<T>* node = new Node<T>;

//		node->value = _value;

//		node->next = nullptr;

//

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->next = head;

//			head->pre = node;

//			head = head->pre;

//		}

//		head->pre = nullptr;

//		cout << "head: " << head->value << endl;

//		cout << "tail: " << tail->value << endl;

//		cout << "node: " << node->value << endl;

//	}

//

//	int pop_front() {

//		cout << endl << endl << "pf"<< endl;

//		Node<T>* ptr = head;

//

//		int value = ptr->value;

//

//		head = head->next;

//		head->pre = nullptr;

//		cout << "head: " << head->value << endl;

//		cout << "ptr: " << ptr->value << endl;

//		cout << "tail: " << tail->value << endl;

//

//		delete ptr;

//		return value;

//	}

//

//	int pop_back() {

//		cout << endl << endl << "pb" << endl;

//		Node<T>* ptr = tail;

//

//		int value = ptr->value;

//

//		tail = tail->pre;

//		cout << "head: " << head->value << endl;

//		cout << "tail: " << tail->value << endl;

//		cout << "ptr: " << ptr->value << endl;

//

//		delete ptr;

//		return value;

//	}

//

//	int left(int x) {

//		cout << endl << "left start" << endl;

//		int res = 0;

//		while (1) {

//			Node<T>* ptr = head;

//			cout << endl << endl << "left: " << ptr->value << endl;

//			if (ptr->value != x) {

//

//				push_back(pop_front());

//				cnt_l++;

//			}

//			else {

//				pop_front();

//				break;

//			}

//		}

//		res = cnt_l;

//		cnt_l = 0;

//		return res;

//	}

//

//

//	int right(int x) {

//		cout << endl << "right start" << endl;

//		int res = 0;

//		while (1) {

//			Node<T>* ptr = tail;

//			cout << endl << endl << "right" << ptr->value << endl;

//			if (head->value != x) {

//				push_front(pop_back());

//				cnt_r++;

//			}

//			else {

//				pop_front();

//				break;

//			}

//		}

//		res = cnt_r;

//		cnt_r = 0;

//		return res;

//	}

//

//	int left_find(int x) {

//		Node<T>* ptr = head;

//		int res = 0;

//		while (1) {

//			if (ptr->value != x) {

//				ptr = ptr->next;

//				cnt_l++;

//			}

//

//			else {

//				break;

//			}

//		}

//		res = cnt_l;

//		cnt_l = 0;

//		return res;

//	}

//

//	int right_find(int x) {

//		Node<T>* ptr = tail;

//		int res = 0;

//		while (1) {

//			if (ptr->value != x) {

//				ptr = ptr->pre;

//				cnt_r++;

//			}

//

//			else {

//				break;

//			}

//		}

//		res = cnt_r;

//		cnt_r = 0;

//		return res;

//	}

//

//};

//

//int main() {

//	linked_list<int> list;

//	int i, n, m,res=0;

//	int arr[100];

//

//	cin >> n >> m;

//

//	for (i = 1; i <= m; i++) {

//		cin >>arr[i];

//	}

//

//	for (i = 1; i <= n; i++) {

//		list.push_back(i);

//	}

//

//	for (i = 1; i <= m; i++) {

//		if (list.left_find(arr[i]) <= list.right_find(arr[i])) {

//			res+=list.left(arr[i]);

//		}

//		else {

//			res+=list.right(arr[i]);

//		}

//	}

//	cout << res << endl;

//}







//

//////정수배열 연산 언어AC - 덱 사용

//#include<iostream>

//#pragma warning (disable: 4996)

//using namespace std;

//

//template<typename T>

//struct Node {

//public:

//	T value;

//	struct Node<T>* next = nullptr;

//	struct Node<T>* pre = nullptr;

//};

//

//template <typename T>

//class linked_list {

//private:

//	Node<T>* head;

//	Node<T>* tail;

//	int cnt = 0;

//

//public:

//	linked_list() : head(nullptr), tail(nullptr) {}

//	~linked_list() {}

//

//	void push_front(T _value) {

//		Node<T>* node = new Node<T>;

//		node->value = _value;

//		node->next = nullptr;

//		cnt++;

//	

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->next = head;

//			head->pre = node;

//			head = head->pre;

//		}

//		head->pre = nullptr;

//	}

//	

//	void push_back(T _value) {

//		Node<T>* node = new Node<T>;

//		node->value = _value;

//		node->next = nullptr;

//		cnt++;

//	

//		if (head == nullptr) {

//			head = node;

//			tail = node;

//			head->pre = nullptr;

//			head->next = nullptr;

//		}

//		else {

//			node->pre = tail;

//			tail->next = node;

//			tail = tail->next;

//		}

//		tail->next = nullptr;

//	}

//

//

//	void pop_front() {

//		Node<T>* ptr = head;

//		//cout << "front : " << head->value << endl;

//		if (head == nullptr) {

//			cout << "error" << endl;

//		}

//		else {

//			head = head->next;

//			cnt--;

//			delete ptr;

//		}

//	}

//

//	void pop_back() {

//		Node<T>* ptr = tail;

//

//		//cout << "tail : " << tail << endl;

//

//		if (tail == nullptr) {

//			cout << "error" << endl;

//		}

//

//		else {

//			tail = tail->pre;

//			cnt--;

//			delete ptr;

//		}

//	}

//

//	void reverse(int flag) {

//		if (flag == 1) {

//			pop_front();

//		}

//

//		else if (flag == 0) {

//			pop_back();

//		}

//	}

//

//	void out(int flag) {

//		if (flag == 1) {

//			Node<T>* ptr = head;

//			if (cnt < 0) {

//				cout << "error" << endl;

//			}

//			else {

//				cout << "[";

//				while (head != nullptr) {

//					cout << head->value << " , ";

//					head = head->next;

//				}

//				cout << "]";

//			}

//			

//		}

//

//		else if (flag == 0) {

//			Node<T>* ptr = tail;

//

//			if (cnt < 0) {

//				cout << "error" << endl;

//			}

//			else {

//				cout << "[";

//				while (tail != nullptr) {

//					cout << tail->value << " , ";

//					tail = tail->pre;

//				}

//				cout << "]";

//			}

//		}

//		cout<<endl;

//	}

//

//

//};

//

//int main() {

//	int i,j,t,n,flag=1;

//	string p;

//	int arr[100];

//

//	cin >> t;

//

//	for (i = 0; i < t; i++) {

//		flag = 1;

//		linked_list<int> list;

//		cin >> p;

//		cin >> n;

//

//		for (j = 0; j < n; j++) {

//			cin >> arr[j];

//		}

//		for (j = 0; j < n; j++) {

//			list.push_back(arr[j]);

//		}

//

//		for (j = 0; j < p.length(); j++) {

//			if (p[j] == 'R') {

//				flag = !flag;

//			}

//

//			else if (p[j] == 'D') {

//				list.reverse(flag);

//			}

//		}

//

//		list.out(flag);

//	}

//

//}



//
//
//////정수배열 연산 언어AC    덱+ 스택 
//
//#include<iostream>
//
//#pragma warning (disable: 4996)
//
//using namespace std;
//
//
//
//template<typename T>
//
//struct Node {
//
//public:
//
//	T value;
//
//	struct Node<T>* next = nullptr;
//
//	struct Node<T>* pre = nullptr;
//
//};
//
//
//
//template <typename T>
//
//class linked_list {
//
//private:
//
//	Node<T>* head;
//
//	Node<T>* tail;
//
//	int cnt = 0;
//
//
//
//public:
//
//	linked_list() : head(nullptr), tail(nullptr) {}
//
//	~linked_list() {}
//
//
//
//	void push_front(T _value) {
//
//		Node<T>* node = new Node<T>;
//
//		node->value = _value;
//
//		node->next = nullptr;
//
//
//
//		if (head == nullptr) {
//
//			head = node;
//
//			tail = node;
//
//			head->pre = nullptr;
//
//			head->next = nullptr;
//
//		}
//
//		else {
//
//			node->next = head;
//
//			head->pre = node;
//
//			head = head->pre;
//
//		}
//
//		head->pre = nullptr;
//
//		cout << "d: " << node->value << endl;
//
//	}
//
//
//
//	void push_back(T _value) {
//
//		Node<T>* node = new Node<T>;
//
//		node->value = _value;
//
//		node->next = nullptr;
//
//
//
//		if (head == nullptr) {
//
//			head = node;
//
//			tail = node;
//
//			head->pre = nullptr;
//
//			head->next = nullptr;
//
//		}
//
//		else {
//
//			node->pre = tail;
//
//			tail->next = node;
//
//			tail = tail->next;
//
//		}
//
//		tail->next = nullptr;
//
//		cout << "d: " << node->value << endl;
//
//	}
//
//
//
//
//
//	int pop_front() {
//
//		Node<T>* ptr = head;
//
//
//
//
//
//		if (head == nullptr) {
//
//			cout << "error" << endl;
//
//			return -1;
//
//		}
//
//
//
//		else {
//
//			cout << "front:" << head->value << endl;
//
//			int num = ptr->value;
//
//			head = head->next;
//
//			delete ptr;
//
//			return num;
//
//		}
//
//	}
//
//
//
//	void out() {
//
//		Node<T>* ptr = head;
//
//
//
//		cout << "[";
//
//		while (1) {
//
//			cout << head->value;
//
//			head = head->next;
//
//			if (head != nullptr) {
//
//				cout << " , ";
//
//			}
//
//			else {
//
//				cout << "]" << endl;
//
//				break;
//
//			}
//
//		}
//
//	}
//
//
//
//};
//
//
//
//template <typename T>
//
//struct node2 {
//
//public:
//
//	T value;
//
//	struct node2<T>* next = nullptr;
//
//	struct node2<T>* pre = nullptr;
//
//};
//
//
//
//
//
//template <typename T>
//
//class linked_stack {
//
//private:
//
//	node2<T>* head;
//
//	node2<T>* tail;
//
//
//
//public:
//
//	linked_stack() : head(nullptr), tail(nullptr) {}
//
//	~linked_stack() {}
//
//
//
//	void push(T _value) {
//
//		node2<T>* node = new node2<T>;
//
//		node->value = _value;
//
//		node->next = nullptr;
//
//
//
//		if (head == nullptr) {
//
//			head = node;
//
//			tail = node;
//
//		}
//
//		else {
//
//			tail->next = node;
//
//			tail = tail->next;
//
//		}
//
//		cout << "stack: " << node->value << endl;
//
//
//
//	}
//
//
//
//	int pop() {
//
//		node2<T>* ptr = head;
//
//		int num = ptr->value;
//
//		head = head->next;
//
//		delete ptr;
//
//		return num;
//
//	}
//
//
//
//};
//
//
//
//
//
//
//
//int main() {
//
//	int i, j, k, t, n, re;
//
//	string p;
//
//	int arr[100];
//
//
//
//	cin >> t;
//
//
//
//	for (i = 0; i < t; i++) {
//
//		linked_list<int> list;
//
//		linked_stack<int> st;
//
//		cin >> p;
//
//		cin >> n;
//
//
//
//		for (j = 0; j < n; j++) {
//
//			cin >> arr[j];
//
//		}
//
//		for (j = 0; j < n; j++) {
//
//			list.push_back(arr[j]);
//
//		}
//
//
//
//		for (j = 0; j < p.length(); j++) {
//
//			if (p[j] == 'R') {
//
//				for (k = 0; k < n; k++) {
//
//					st.push(list.pop_front());
//
//				}
//
//				for (k = 0; k < n; k++) {
//
//					list.push_front(st.pop());
//
//				}
//
//			}
//
//
//
//			else if (p[j] == 'D') {
//
//				re = list.pop_front();
//
//				n--;
//
//			}
//
//		}
//
//		if (re != -1) {
//
//			list.out();
//
//		}
//
//		else {
//
//			continue;
//
//		}
//
//	}
//
//
//
//}