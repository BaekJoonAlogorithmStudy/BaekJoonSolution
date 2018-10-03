// # Gamja Comment 
//
// 이는 백준 알고리즘 사이트의 분류 'LinkedList'의 문제를 풀이한 것입니다.
//
// 결과 값은 제대로 구현하였지만, 시간초과로 통과하지는 못한 문제풀이입니다.
// -> 후에 STL을 사용하면 최적화가 되는지 시도해 볼 것입니다.
//
// => 에디터 문제는 단일 연결 리스트를 이용하여 문제를 풀이합니다.


#include <iostream>
#include <sstream>
#include <string.h>


using namespace std;

class Node {
public:
	Node* next;
	char data;
};

class LinkedList {

public:
	LinkedList();
	~LinkedList();
	void Add(Node* pNode);
	void HeadAdd(Node *pNode);
	void IndexAdd(int pIndex, Node *pNode);
	char Remove(int pIndex);
private:
	Node* head;
	Node* tail;
	int size;

};


LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}
LinkedList::~LinkedList() {

}


void LinkedList::HeadAdd(Node *pNode) {
	if (head == NULL) {
		head = pNode;
		tail = pNode;
	}
	else {
		Node* prevHead = head;
		head = pNode;
		pNode->next = prevHead;
	}
}
void LinkedList::Add(Node* pNode) {

	if (head == NULL) {
		head = pNode;
		tail = pNode;
	}
	else {
		Node* Prev = tail;
		Prev->next = pNode;
		tail = pNode;
	}
	++size;
}

void LinkedList::IndexAdd(int pIndex, Node *pNode) {	//몇 번째 위치에 넣을지 - 인자
	Node* Prev = head;
	Node* add = head;
	int i = 1;
	while (!(add == NULL)) {
		if (i == pIndex) {
			if (add == head && add == tail) {
				head = pNode;
				pNode->next = add;
			}
			else if (add == head && add != tail) {
				head = pNode;
				pNode->next = add;
			}
			else if (add != head && add == tail) {
				Prev->next = pNode;
				pNode->next = add;
				tail = add;
			}
			else {
				Prev->next = pNode;
				pNode->next = add;
			}
			break;
		}
		Prev = add;
		add = add->next;
		i++;
	}

}
char LinkedList::Remove(int pIndex) {
	char retVal = -1;
	if (head != NULL) {			//head가 NULL이면 제거할 것 없음 -> 제거할것이 있을 때

		Node* Prev = head;
		Node* del = head;
		int i = 1; 
		while (!(del == NULL)) {
			if (i == pIndex) {
				if (del == head && del == tail) {
					head = NULL;
					tail = NULL;
				}
				else if(del == head && del != tail) {
					head = del->next;
				}
				else if (del != head && del == tail) {
					tail = Prev;
				}
				Prev->next = del->next;
				retVal = del->data;
				del->next = NULL;
				break;
			}
			Prev = del;
			del = del->next;
			i++;
		}

		--size;
	}
	return retVal;
}

int main() {

	//문자열 받기
	string line;
	getline(cin, line);
	int size = line.length();		//입력받은 문자열 길이
	char * c = new char[size];
	strcpy(c, line.c_str());

	//문자열을 리스트에 저장
	LinkedList list = LinkedList();
	for (int i = 0; i < line.length(); i++) {
		Node* p = new Node();
		p->next = NULL;
		p->data = c[i];
		list.Add(p);
	}

	
	int comNum;			//명령어 갯수를 입력 받는다.
	cin >> comNum;
	cin.ignore();		//입력 버퍼에 남아 있는 것들을 비워준다.

	int location = size + 1;		//현재 커서의 위치
	for (int i = 0; i < comNum; i++) {
		//명령어를 한줄씩 본다
		string li;
		getline(cin, li);

		char * c = new char[li.length()];
		strcpy(c, li.c_str());

		if (c[0] == 'L') {
			if (location == 1) continue;	//문장의 맨 앞이면 무시
			else location -= 1;				//커서를 왼쪽으로 한칸 옮김
		}
		else if (c[0] == 'D') {
			if (location == size + 1) continue;	//문장의 맨 뒤이면 무시
			else location += 1;								//커서를 오른쪽으로 한칸 옮김
		}
		else if (c[0] == 'B') {
			if (location == 1) continue;	//문장의 맨 앞이면 무시
			else {							//커서 왼쪽에 있는 문자 삭제
				list.Remove(location - 1);
				--size;
				--location;
			}
		}
		else if (c[0] == 'P') {
			Node* p = new Node();
			p->next = NULL;
			p->data = c[2];

			if( location == size + 1) list.Add(p);		//문장의 맨뒤이면 그냥 Add
			else if (location == 1) list.HeadAdd(p);	//문장에 맨앞이면 head에 Add
			else	list.IndexAdd(location, p);			//문장에 중간이면 인덱스에 맞게 add

			++size;
			++location;
		}
	}

	for (int i = 0; i < size; i++)
		cout << list.Remove(1);
	return 0;
}