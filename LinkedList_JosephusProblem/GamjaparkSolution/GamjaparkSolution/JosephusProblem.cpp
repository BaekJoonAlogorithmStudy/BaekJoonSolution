// # Gamja Comment 
//
// 이는 백준 알고리즘 사이트의 분류 'LinkedList'의 문제를 풀이한 것입니다.
//
//	* Linked List 
//		1. 각 노드가 데이터와 포인터를 갖고, 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 자료 구조
//		2. 종류
//			1) 단일 연결 리스트
//			2) 이중 연결 리스트
//			3) 원형 연결 리스트
//
//	=> 조세푸스 문제는 원형 연결 리스트를 이용하여 문제를 풀이합니다.

#include <iostream>
#include <sstream>

using namespace std;

class Node {
public:
	Node* next;
	int data;
};

class LinkedList {



public:
	LinkedList();
	~LinkedList();
	void Add(Node* pNode);
	int Remove(int pIndex);
private:
	Node* tail;
	int size;

};


LinkedList::LinkedList() {
	tail = NULL;
	size = 0;
}
LinkedList::~LinkedList() {

}
void LinkedList::Add(Node* pNode) {

	if (tail == NULL) {
		tail = pNode;
		tail->next = tail;
	}
	else {
		Node* Prev = tail;
		Node* head = tail->next;

		tail = pNode;
		Prev->next = tail;
		tail->next = head;
	}
	++size;
}
int LinkedList::Remove(int pIndex) {
	int retVal = -1;

	if (size > 1) {
		for (int i = 1; i < pIndex; i++) {
			tail = tail->next;
		}
		Node* removeMember = tail->next;
		retVal = removeMember->data;

		tail->next = removeMember->next;
		removeMember = NULL;
		--size;
	}
	else if (size == 1) {
		retVal = tail->data;
		tail = NULL;
		size = 0;
	}

	return retVal;
}

void JosephusProblem(int N, int M) {

	LinkedList list = LinkedList();
	for (int i = 1; i <= N; i++) {
		Node* p = new Node();
		p->data = i;
		p->next = NULL;
		list.Add(p);
	}
	cout << "<";
	for (int i = 1; i <= N; i++) {
		cout << list.Remove(M);
		if (i == N) cout << ">";
		else cout << ", ";
	}

}

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int a[2] = { 0 };
	int i = 0;

	while (ss >> line) {
		a[i] = atoi(line.c_str());
		i++;
		if (i == 2) break;
	}

	JosephusProblem(a[0], a[1]);

	return 0;
}