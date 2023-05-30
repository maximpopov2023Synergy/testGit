#include <iostream>
#include <ctime>

using namespace std;

string navodim_krasotu(40, '_'); //создаём строчку для красивого вывода

class BranchFinances { //класс создаем
public:
	BranchFinances() {} //пустой конструктор по умолчанию

	const double MONEY_TO_STAFF = 35.0; //константные переменные для расчёта
	const double MONEY_TO_AURORS = 15.0;
	const double PERCENT = 0.07;
	const double MONEY_TO_RENT = 50;
	const double MANY_MONEY = 270.0;

	double all_expenses; //переменная для расчёта всех расходов

	double random() { //функция с гспч для генерации выручки
		srand(time(0));
		double many_money = 250.0 + rand() % 250;
		return many_money;
	}

	double d = random(); //наша выручка

	double my_rent() {//функция для подсчёта аренды
		if (d > 270) {
			return MONEY_TO_RENT + (d - MANY_MONEY) * PERCENT; //если выручка больше 270
		}
		else
			return MONEY_TO_RENT;// если выручка меньше 270
	}

	void account_expenses() {
		all_expenses = my_rent() + MONEY_TO_AURORS + MONEY_TO_STAFF; //метод для подсчёта всех расходов
	}

	void show_expenses() { //метод для вывода всех данных
		cout << navodim_krasotu << endl << endl;
		cout << "The revenue is " << random() << " " << "galleons." << endl; //выручка
		cout << navodim_krasotu << endl << endl;
		cout << "All expenses " << all_expenses << " " << "galleons." << endl;//все расходы
		cout << navodim_krasotu << endl << endl;
		cout << "The rent is " << my_rent() << " " << "galleons." << endl; //аренда
		cout << navodim_krasotu << endl << endl;
	}

	void show_profit() {
		cout << "The profit is: " << random() - all_expenses << " galleons" << endl; //метод для вывода чистой прибыли
		cout << navodim_krasotu << endl << endl;
	}

	~BranchFinances() {
		cout << "Clean!" << '\n'; //деструктор
	}

};

class NewBranch : public BranchFinances { //создаём класс для нового филиала
	string name_of_branch;//с приватной строковой переменной
public:
	NewBranch(string Name) {//конструктор
		name_of_branch = Name;
		cout << "Welcome to " << '"' << name_of_branch << '"' << " branch of Ollivander's!"; //приветствие
	}
	~NewBranch() {
		cout << "Have a nice day!" << endl; //деструктор
	}
};

int main() {
	cout << "Please, insert branch name: "; //введите название
	string s;
	cin >> s; //вводим
	NewBranch my_branch(s); //запускаем в класс
	cout << endl;
	my_branch.random(); //ну и подсчет
	my_branch.account_expenses();
	my_branch.show_expenses(); //и вывод
	my_branch.show_profit();
}
