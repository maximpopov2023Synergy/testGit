#include <iostream>
#include <ctime>

using namespace std;

string navodim_krasotu(40, '_'); //������ ������� ��� ��������� ������

class BranchFinances { //����� �������
public:
	BranchFinances() {} //������ ����������� �� ���������

	const double MONEY_TO_STAFF = 35.0; //����������� ���������� ��� �������
	const double MONEY_TO_AURORS = 15.0;
	const double PERCENT = 0.07;
	const double MONEY_TO_RENT = 50;
	const double MANY_MONEY = 270.0;

	double all_expenses; //���������� ��� ������� ���� ��������

	double random() { //������� � ���� ��� ��������� �������
		srand(time(0));
		double many_money = 250.0 + rand() % 250;
		return many_money;
	}

	double d = random(); //���� �������

	double my_rent() {//������� ��� �������� ������
		if (d > 270) {
			return MONEY_TO_RENT + (d - MANY_MONEY) * PERCENT; //���� ������� ������ 270
		}
		else
			return MONEY_TO_RENT;// ���� ������� ������ 270
	}

	void account_expenses() {
		all_expenses = my_rent() + MONEY_TO_AURORS + MONEY_TO_STAFF; //����� ��� �������� ���� ��������
	}

	void show_expenses() { //����� ��� ������ ���� ������
		cout << navodim_krasotu << endl << endl;
		cout << "The revenue is " << random() << " " << "galleons." << endl; //�������
		cout << navodim_krasotu << endl << endl;
		cout << "All expenses " << all_expenses << " " << "galleons." << endl;//��� �������
		cout << navodim_krasotu << endl << endl;
		cout << "The rent is " << my_rent() << " " << "galleons." << endl; //������
		cout << navodim_krasotu << endl << endl;
	}

	void show_profit() {
		cout << "The profit is: " << random() - all_expenses << " galleons" << endl; //����� ��� ������ ������ �������
		cout << navodim_krasotu << endl << endl;
	}

	~BranchFinances() {
		cout << "Clean!" << '\n'; //����������
	}

};

class NewBranch : public BranchFinances { //������ ����� ��� ������ �������
	string name_of_branch;//� ��������� ��������� ����������
public:
	NewBranch(string Name) {//�����������
		name_of_branch = Name;
		cout << "Welcome to " << '"' << name_of_branch << '"' << " branch of Ollivander's!"; //�����������
	}
	~NewBranch() {
		cout << "Have a nice day!" << endl; //����������
	}
};

int main() {
	cout << "Please, insert branch name: "; //������� ��������
	string s;
	cin >> s; //������
	NewBranch my_branch(s); //��������� � �����
	cout << endl;
	my_branch.random(); //�� � �������
	my_branch.account_expenses();
	my_branch.show_expenses(); //� �����
	my_branch.show_profit();
}
