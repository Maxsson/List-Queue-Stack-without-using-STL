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
	Element *pFirst; //первый элемент списка
	Element *pLast; //последний элемент списка
	int countElements; //количество
	//Конструктор
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

	//Деструктор
	~List() { delAllList(); }
};

//Добавить в конец
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

//Добавить по индексу
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
		if (Index>countElements) { cout << "Какая-то ошибка...\nНо мы сделаем вид что ее нет:)\nПродолжайте!!"; system("pause");
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

//удалить по индексу
void List::delOneEl(int Index) {
	Element *pTemp = pFirst;
	if (countElements <= Index) { cout << "Какая-то ошибка...\nНо мы сделаем вид что ее нет:)\nПродолжайте!!"; system("pause");
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

//Вывод списка
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
	cout << endl << "Количество элементов: " << countElements << endl << endl << endl;
	system("pause");
}

//Очистить список
void List::delAllList() {
	while (pFirst != NULL)
	{
		Element *pTemp = pFirst;
		pFirst = pFirst->list_next;
		delete pTemp;
	}
	cout << endl << "Список очищен." << endl;
	countElements = 0;
	system("pause");
}

//Случайно перемешать
void List::Mix() {
	
	int rndCE;
	if (countElements == 0) { cout << "Список пуст!\n"; system("pause"); }
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
	if (countElements > 0)cout << "Список перемешан!!!" << endl << endl;
	
	system("pause");
	printList();
}

void List::sort() {
	bool descending = false;
	system("cls");
	cout << "По убыванию?\n" << "Если да- нажмите 1\n"
		<< "Иначе -нажмите 0\n";
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
	cout << "Список отсортирован по  возрастанию!!!" << endl << endl;
	else
	cout << "Список отсортирован по убыванию!!!" << endl << endl;
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
		cout << "Что Вы хотите сделать (введите соответствующее число):" << endl;
		cout << "1) Вывести список" << endl;
		cout << "2) Добавить новый элемент в конец" << endl;
		cout << "3) Добавить новый элемент на определенную позицию" << endl;
		cout << "4) Удалить элемент на определенной позиции" << endl;
		cout << "5) Перемешать" << endl;
		cout << "6) Отсортировать" << endl;
		//Ну не знаю...
		cout << "7) Мне повезет!!!" << endl;
		cout << "8) Очистить весь список" << endl;
		cout << "9) Завершить работу" << endl;
		cout << "_____________________" << endl;
		cout << "10) Добавить все 10 цифр в конец" << endl;
		cout << "0) Добавить 10 случайных чисел в конец(от 0 до 99)" << endl;
		cout << "-1) Добавить 10 случайных чисел в конец(от -50 до 50)" << endl;
		short nowDo;
		cin >> nowDo;
	doALL:
		switch (nowDo) {

			//10 Случайных чисел в конец(от -50 до 50)
		case -1: {
			for (int a = 0; a < 10; a++) {
				int rnd = rand() % 101 - 50;
				lst.addToList(rnd);
			}
			lst.printList();
			break;
		}

				 //10 Случайных чисел в конец(0-99)
		case 0: {
			for (int a = 0; a < 10; a++) {
				int rnd = rand() % 100;
				lst.addToList(rnd);
			}
			lst.printList();
			break;
		}

				//Вывести список
		case 1: {
			lst.printList();
			break;
		}

				//Добавить
		case 2: {
			system("cls");
			cout << "(Вы добавляеете элемент)" << endl;
			cout << "Введите элемент: ";
			int newint2;
			cin >> newint2;
			lst.addToList(newint2);
			break;
		}

				//Добавить на определенную позицию
		case 3: {
			system("cls");
			cout << "(Вы добавляеете элемент на определенную позицию)" << endl;
			cout << "Введите элемент: ";
			int newint3;
			cin >> newint3;
			cout << "Введите индекс: ";
			int ind3;
			cin >> ind3;
			lst.addToListIndex(newint3, ind3);
			break;
		}

				//Удалить с определенной позиции
		case 4: {
			system("cls");
			cout << "(Вы удаляете элемент с определенной позиции)" << endl;
			int ind4;
			cout << "Введите индекс: ";
			cin >> ind4;
			lst.delOneEl(ind4);
			break;
		}

				//Перемешать
		case 5: {
			lst.Mix();
			break;
		}

				//Сортировка
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
				cout << "Вам \"выпало\" ";
				if (random1 == -1) { cout << "добавление 10 cлучайных чисел в конец(от -50 до 50)."; }
				if (random1 == 0) { cout << "добавление 10 cлучайных чисел в конец(0-99)!!"; }
				if (random1 == 1) { cout << "вывод всего списка!!"; }
				if (random1 == 2) { cout << "добавление элемента."; }
				if (random1 == 3) { cout << "добавление элемента на определенный индекс."; }
				if (random1 == 4) { cout << "удаление элемента с определенной позиции."; }
				if (random1 == 5) { cout << "перемешивание списка."; }
				if (random1 == 6) { cout << "сортировка списка."; }
				if (random1 == 8) { cout << "очистка всего списка :("; }
				if (random1 == 9) { cout << "ЗАВЕРШЕНИЕ РАБОТЫ!!!\n ПОКА :(\n"; return 0; }
				if (random1 == 10) { cout << "добавить в конец всех 10 цифр"; }
				nowDo = random1;
				if (random1 != 9)cout << "\nПоздравляем!!!\n";
				system("pause");
				system("cls");

				goto doALL;
			}
			else
				goto do7;
			break;
		}

		//Очистить весь список
		case 8: {
			lst.delAllList();
			break;
		}

				//Завершить работу
		case 9: {
			work = false;
			break;
		}
				//Добавить в конец все 10 цифр
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