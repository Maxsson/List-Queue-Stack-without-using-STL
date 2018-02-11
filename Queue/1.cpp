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
	Element *pFirst; //первый элемент очереди
	Element *pLast; //последний элемент очереди
	int countElements; //количество
					   //Конструктор
	Queue() {
		pFirst = NULL;
		countElements = 0;
	}
	void addToQueue(int val);	
	void remove();
	void printQueue();
	void delAllQueue();
	//Деструктор
	~Queue() { delAllQueue(); }
};

//Добавить в конец
void Queue::addToQueue(int val) {

	Element *temp = new Element;
	if (pFirst == NULL) { pFirst = temp; } 
	else { pLast->list_next = temp; }
	temp->val = val;
	temp->list_next = NULL;
	pLast = temp;
	countElements++;
}
//удалить 
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
	cout << "Элемент удален.\n";
	system("pause");
	}
	else
	{
		system("cls");
		cout << "Очередь и так пуста.\nЧто удалять-то?\n";
		system("pause");
	}
}

//Вывод очередь
void Queue::printQueue() {
	system("cls");
	cout << "Очередь: ";
	Element *pTemp = pFirst;
	int a = 0;
	while (pTemp != NULL)
	{
		cout << pTemp->val << " ";
		pTemp = pTemp->list_next;
		a++;
		if (a % 10 == 0)cout << endl;
	}
	cout << endl << "Количество элементов в очереди: " << countElements << endl << endl << endl;
	system("pause");
}

//Очистить очередь
void Queue::delAllQueue() {
	while (pFirst != NULL)
	{
		Element *pTemp = pFirst;
		pFirst = pFirst->list_next;
		delete pTemp;
	}
	cout << endl << "Очередь очищена." << endl;
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
		cout << "Что Вы хотите сделать (введите соответствующее число):" << endl;
		cout << "1) Вывести очередь" << endl;
		cout << "2) Добавить новый элемент" << endl;	
		cout << "3) Удалить элемент" << endl;
		cout << "8) Очистить всю очередь" << endl;
		cout << "9) Завершить работу" << endl;
		short nowDo;
		cin >> nowDo;
		switch (nowDo) {
		//Вывести очередь
		case 1: {
			que.printQueue();
			break;
		}

		//Добавить
		case 2: {
			system("cls");
			cout << "(Вы добавляеете элемент)" << endl;
			cout << "Введите элемент: ";
			int newint2;
			cin >> newint2;
			que.addToQueue(newint2);
			break;
		}
		//Удалить 
		case 3: {
			system("cls");
			que.remove();
			break;
		}
		//Очистить всю очередь
		case 8: {
			que.delAllQueue();
			break;
		}
		//Завершить работу
		case 9: {
			work = false;
			break;
		}				
		}
	}
	return 0;
}