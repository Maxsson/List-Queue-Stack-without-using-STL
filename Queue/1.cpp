#include <iostream>
#include <ctime>
using namespace std;

struct Element {
	int val;
	Element *list_next;
};

class Queue
{
public:
	Element *pFirst; //������ ������� �������
	Element *pLast; //��������� ������� �������
	int countElements; //����������
					   //�����������
	Queue() {
		pFirst = NULL;
		countElements = 0;
	}
	void addToQueue(int val);	
	void remove();
	void printQueue();
	void delAllQueue();
	//����������
	~Queue() { delAllQueue(); }
};

//�������� � �����
void Queue::addToQueue(int val) {

	Element *temp = new Element;
	if (pFirst == NULL) { pFirst = temp; } 
	else { pLast->list_next = temp; }
	temp->val = val;
	temp->list_next = NULL;
	pLast = temp;
	countElements++;
}
//������� 
void Queue::remove() {
	if(pFirst != NULL)
	{ 
	Element *pTemp = pFirst;
		pTemp = pTemp->list_next;
		delete pFirst;
		pFirst = pTemp;
	if (countElements>0)
		countElements--;
	system("cls");
	cout << "������� ������.\n";
	system("pause");
	}
	else
	{
		system("cls");
		cout << "������� � ��� �����.\n��� �������-��?\n";
		system("pause");
	}
}

//����� �������
void Queue::printQueue() {
	system("cls");
	cout << "�������: ";
	Element *pTemp = pFirst;
	int a = 0;
	while (pTemp != NULL)
	{
		cout << pTemp->val << " ";
		pTemp = pTemp->list_next;
		a++;
		if (a % 10 == 0)cout << endl;
	}
	cout << endl << "���������� ��������� � �������: " << countElements << endl << endl << endl;
	system("pause");
}

//�������� �������
void Queue::delAllQueue() {
	while (pFirst != NULL)
	{
		Element *pTemp = pFirst;
		pFirst = pFirst->list_next;
		delete pTemp;
	}
	cout << endl << "������� �������." << endl;
	countElements = 0;
	system("pause");
}



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	Queue que;
	bool work = true;
	while (work)
	{
		system("cls");
		cout << "��� �� ������ ������� (������� ��������������� �����):" << endl;
		cout << "1) ������� �������" << endl;
		cout << "2) �������� ����� �������" << endl;	
		cout << "3) ������� �������" << endl;
		cout << "8) �������� ��� �������" << endl;
		cout << "9) ��������� ������" << endl;
		short nowDo;
		cin >> nowDo;
		switch (nowDo) {
		//������� �������
		case 1: {
			que.printQueue();
			break;
		}

		//��������
		case 2: {
			system("cls");
			cout << "(�� ����������� �������)" << endl;
			cout << "������� �������: ";
			int newint2;
			cin >> newint2;
			que.addToQueue(newint2);
			break;
		}
		//������� 
		case 3: {
			system("cls");
			que.remove();
			break;
		}
		//�������� ��� �������
		case 8: {
			que.delAllQueue();
			break;
		}
		//��������� ������
		case 9: {
			work = false;
			break;
		}				
		}
	}
	return 0;
}