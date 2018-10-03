// # Gamja Comment 
//
// �̴� ���� �˰��� ����Ʈ�� �з� 'LinkedList'�� ������ Ǯ���� ���Դϴ�.
//
// ��� ���� ����� �����Ͽ�����, �ð��ʰ��� ��������� ���� ����Ǯ���Դϴ�.
// -> �Ŀ� STL�� ����ϸ� ����ȭ�� �Ǵ��� �õ��� �� ���Դϴ�.
//
// => ������ ������ ���� ���� ����Ʈ�� �̿��Ͽ� ������ Ǯ���մϴ�.


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

void LinkedList::IndexAdd(int pIndex, Node *pNode) {	//�� ��° ��ġ�� ������ - ����
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
	if (head != NULL) {			//head�� NULL�̸� ������ �� ���� -> �����Ұ��� ���� ��

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

	//���ڿ� �ޱ�
	string line;
	getline(cin, line);
	int size = line.length();		//�Է¹��� ���ڿ� ����
	char * c = new char[size];
	strcpy(c, line.c_str());

	//���ڿ��� ����Ʈ�� ����
	LinkedList list = LinkedList();
	for (int i = 0; i < line.length(); i++) {
		Node* p = new Node();
		p->next = NULL;
		p->data = c[i];
		list.Add(p);
	}

	
	int comNum;			//��ɾ� ������ �Է� �޴´�.
	cin >> comNum;
	cin.ignore();		//�Է� ���ۿ� ���� �ִ� �͵��� ����ش�.

	int location = size + 1;		//���� Ŀ���� ��ġ
	for (int i = 0; i < comNum; i++) {
		//��ɾ ���پ� ����
		string li;
		getline(cin, li);

		char * c = new char[li.length()];
		strcpy(c, li.c_str());

		if (c[0] == 'L') {
			if (location == 1) continue;	//������ �� ���̸� ����
			else location -= 1;				//Ŀ���� �������� ��ĭ �ű�
		}
		else if (c[0] == 'D') {
			if (location == size + 1) continue;	//������ �� ���̸� ����
			else location += 1;								//Ŀ���� ���������� ��ĭ �ű�
		}
		else if (c[0] == 'B') {
			if (location == 1) continue;	//������ �� ���̸� ����
			else {							//Ŀ�� ���ʿ� �ִ� ���� ����
				list.Remove(location - 1);
				--size;
				--location;
			}
		}
		else if (c[0] == 'P') {
			Node* p = new Node();
			p->next = NULL;
			p->data = c[2];

			if( location == size + 1) list.Add(p);		//������ �ǵ��̸� �׳� Add
			else if (location == 1) list.HeadAdd(p);	//���忡 �Ǿ��̸� head�� Add
			else	list.IndexAdd(location, p);			//���忡 �߰��̸� �ε����� �°� add

			++size;
			++location;
		}
	}

	for (int i = 0; i < size; i++)
		cout << list.Remove(1);
	return 0;
}