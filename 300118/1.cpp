#include <iostream>
#include <ctime>
using namespace std;

struct Element {
	int val;
	Element *list_next;
};

class List
{
public:
	Element *pFirst; //������ ������� ������
	Element *pLast; //��������� ������� ������
	int countElements; //����������
	//�����������
	List() {
		pFirst = NULL;
		countElements = 0;
	}
	void addToList(int val);
	void addToListIndex(int val, int Index);
	void delOneEl(int Index);
	void printList();
	void delAllList();
	void Mix();
	void sort();

	//����������
	~List() { delAllList(); }
};

//�������� � �����
void List::addToList(int val) {
	
	Element *temp = new Element;
	if (pFirst == NULL)
		pFirst = temp;
	else
		pLast->list_next = temp;
	temp->val = val;
	temp->list_next = NULL;
	pLast = temp;
	countElements++;
}

//�������� �� �������
void List::addToListIndex(int val, int Index) {
	Element *temp = new Element;
	Element *pTemp = pFirst;
	if (pFirst == NULL)
	{
		pFirst = temp;
		temp->val = val;
		temp->list_next = NULL;
		pLast = temp;
	}
	else
	{
		if (Index>countElements) { cout << "�����-�� ������...\n�� �� ������� ��� ��� �� ���:)\n�����������!!"; system("pause");
		}
		else
		for (int a = 0; a<Index - 1; a++)
		{
			pTemp = pTemp->list_next;
		}
		temp->list_next = pTemp->list_next;
		pTemp->list_next = temp;
		temp->val = val;
		if(Index == countElements) pLast = temp;
}
	countElements++;
}

//������� �� �������
void List::delOneEl(int Index) {
	Element *pTemp = pFirst;
	if (countElements <= Index) { cout << "�����-�� ������...\n�� �� ������� ��� ��� �� ���:)\n�����������!!"; system("pause");
	}
	else if (Index == 0)
	{
		pTemp = pTemp->list_next;
		delete pFirst;
		pFirst = pTemp;
	}
	else if (Index == countElements-1)
	{
		for (int a = 0; a<Index-1; a++)
		{
			pTemp = pTemp->list_next;
		}
		pLast = pTemp;
		pLast->list_next = NULL;
		pTemp = pTemp->list_next;
		delete pTemp;
	}
	else
	{			
		for (int a = 0; a<Index - 1; a++)
		{
			pTemp = pTemp->list_next;
		}
		Element *pTemp2 = pTemp;
		pTemp = pTemp->list_next;
		Element *pTempDel = pTemp;		
		pTemp = pTemp->list_next;
		pTemp2->list_next = pTemp;
		delete pTempDel;
	}
	if(countElements>0)
	countElements--;
}

//����� ������
void List::printList() {
	system("cls");
	Element *pTemp = pFirst;
	int a = 0;
	while (pTemp != NULL)
	{
		cout << pTemp->val << " ";
		pTemp = pTemp->list_next;
		a++;
		if (a % 10 == 0)cout << endl;
	}
	cout << endl << "���������� ���������: " << countElements << endl << endl << endl;
	system("pause");
}

//�������� ������
void List::delAllList() {
	while (pFirst != NULL)
	{
		Element *pTemp = pFirst;
		pFirst = pFirst->list_next;
		delete pTemp;
	}
	cout << endl << "������ ������." << endl;
	countElements = 0;
	system("pause");
}

//�������� ����������
void List::Mix() {
	
	int rndCE;
	if (countElements == 0) { cout << "������ ����!\n"; system("pause"); }
	else 
		for (int a = 0; a < 50; a++)
		{
			Element *pTemp = pFirst;
			rndCE = rand() % countElements;
			for (int b = 0; b < rndCE; b++)
			{
				pTemp = pTemp->list_next;
				int itmp = pTemp->val;
				pTemp->val = pFirst->val;
				pFirst->val = itmp;
			}
		}
		system("cls");
	if (countElements > 0)cout << "������ ���������!!!" << endl << endl;
	
	system("pause");
	printList();
}

void List::sort() {
	bool descending = false;
	system("cls");
	cout << "�� ��������?\n" << "���� ��- ������� 1\n"
		<< "����� -������� 0\n";
	cin >> descending;
	for (Element *pFTemp = pFirst; pFTemp != NULL; pFTemp = pFTemp->list_next)	
	{
		for (Element *pSTemp = pFTemp; pSTemp != NULL; pSTemp = pSTemp->list_next)
		{
			if (descending == false)
			{
				if (pFTemp->val > pSTemp->val)
				{
					int tmp = pFTemp->val;
					pFTemp->val = pSTemp->val;
					pSTemp->val = tmp;
				}
			}
			else
				if (pFTemp->val < pSTemp->val)
				{
					int tmp = pFTemp->val;
					pFTemp->val = pSTemp->val;
					pSTemp->val = tmp;
				}
		}
	}
	system("cls");
	if (descending == false)
	cout << "������ ������������ ��  �����������!!!" << endl << endl;
	else
	cout << "������ ������������ �� ��������!!!" << endl << endl;
	system("pause");
	printList();
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	List lst;
	bool work = true;
	while (work)
	{
		system("cls");
		cout << "��� �� ������ ������� (������� ��������������� �����):" << endl;
		cout << "1) ������� ������" << endl;
		cout << "2) �������� ����� ������� � �����" << endl;
		cout << "3) �������� ����� ������� �� ������������ �������" << endl;
		cout << "4) ������� ������� �� ������������ �������" << endl;
		cout << "5) ����������" << endl;
		cout << "6) �������������" << endl;
		//�� �� ����...
		cout << "7) ��� �������!!!" << endl;
		cout << "8) �������� ���� ������" << endl;
		cout << "9) ��������� ������" << endl;
		cout << "_____________________" << endl;
		cout << "10) �������� ��� 10 ���� � �����" << endl;
		cout << "0) �������� 10 ��������� ����� � �����(�� 0 �� 99)" << endl;
		cout << "-1) �������� 10 ��������� ����� � �����(�� -50 �� 50)" << endl;
		short nowDo;
		cin >> nowDo;
	doALL:
		switch (nowDo) {

			//10 ��������� ����� � �����(�� -50 �� 50)
		case -1: {
			for (int a = 0; a < 10; a++) {
				int rnd = rand() % 101 - 50;
				lst.addToList(rnd);
			}
			lst.printList();
			break;
		}

				 //10 ��������� ����� � �����(0-99)
		case 0: {
			for (int a = 0; a < 10; a++) {
				int rnd = rand() % 100;
				lst.addToList(rnd);
			}
			lst.printList();
			break;
		}

				//������� ������
		case 1: {
			lst.printList();
			break;
		}

				//��������
		case 2: {
			system("cls");
			cout << "(�� ����������� �������)" << endl;
			cout << "������� �������: ";
			int newint2;
			cin >> newint2;
			lst.addToList(newint2);
			break;
		}

				//�������� �� ������������ �������
		case 3: {
			system("cls");
			cout << "(�� ����������� ������� �� ������������ �������)" << endl;
			cout << "������� �������: ";
			int newint3;
			cin >> newint3;
			cout << "������� ������: ";
			int ind3;
			cin >> ind3;
			lst.addToListIndex(newint3, ind3);
			break;
		}

				//������� � ������������ �������
		case 4: {
			system("cls");
			cout << "(�� �������� ������� � ������������ �������)" << endl;
			int ind4;
			cout << "������� ������: ";
			cin >> ind4;
			lst.delOneEl(ind4);
			break;
		}

				//����������
		case 5: {
			lst.Mix();
			break;
		}

				//����������
		case 6: {
			lst.sort();
			break;
		}

			do7:
		case 7:
		{
			int static random1;
			random1 = rand() % 12 - 1;
			cout << random1;
			if (random1 != 7) {
				system("cls");
				cout << random1;
				cout << "��� \"������\" ";
				if (random1 == -1) { cout << "���������� 10 c�������� ����� � �����(�� -50 �� 50)."; }
				if (random1 == 0) { cout << "���������� 10 c�������� ����� � �����(0-99)!!"; }
				if (random1 == 1) { cout << "����� ����� ������!!"; }
				if (random1 == 2) { cout << "���������� ��������."; }
				if (random1 == 3) { cout << "���������� �������� �� ������������ ������."; }
				if (random1 == 4) { cout << "�������� �������� � ������������ �������."; }
				if (random1 == 5) { cout << "������������� ������."; }
				if (random1 == 6) { cout << "���������� ������."; }
				if (random1 == 8) { cout << "������� ����� ������ :("; }
				if (random1 == 9) { cout << "���������� ������!!!\n ���� :(\n"; return 0; }
				if (random1 == 10) { cout << "�������� � ����� ���� 10 ����"; }
				nowDo = random1;
				if (random1 != 9)cout << "\n�����������!!!\n";
				system("pause");
				system("cls");

				goto doALL;
			}
			else
				goto do7;
			break;
		}

		//�������� ���� ������
		case 8: {
			lst.delAllList();
			break;
		}

				//��������� ������
		case 9: {
			work = false;
			break;
		}
				//�������� � ����� ��� 10 ����
		case 10: {
			for (int a = 0; a < 10; a++) {
				lst.addToList(a);
			}
			lst.printList();
			break;
		}
		}
	}
	return 0;
}