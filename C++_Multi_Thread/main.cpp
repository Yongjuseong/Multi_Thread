#include<iostream>
#include<thread>
using namespace std;
//�������� C++ ǥ�ؿ� �����尡 ���, �� �÷��� ���� �ٸ� ������ ���(windows ->CreateThread �� �����带 ���� /  Linux -> pthread_create)
// ���������� ������ ->  ������ �ɼǿ� -pthread �� �߰�)
void func1() {
	for (int i = 0; i < 10; i++) {
		cout << "������1 �۵��� ! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		cout << "������2 �۵��� ! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		cout << "������3 �۵��� ! \n";
	}
}

int main() {
	thread t1(func1); // thread allocation and execution ������ �Ҵ� ����
	thread t2(func2); // thread allocation and execution ������ �Ҵ� ����
	thread t3(func3); // thread allocation and execution ������ �Ҵ� ����

	t1.join(); // thread end -> return ������ ���� �� ���� 
	t2.join(); // thread end -> return ������ ���� �� ����
	t3.join(); // thread end -> return ������ ���� �� ����

	/*
	t1.detach();
	t2.detach();
	t3.detach();
	*/
	cout << "���� �Լ� ����" << endl;

}