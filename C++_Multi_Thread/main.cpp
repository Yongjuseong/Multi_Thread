#include<iostream>
#include<thread>
using namespace std;
//이전에는 C++ 표준에 쓰레드가 없어서, 각 플랫폼 마다 다른 구현을 사용(windows ->CreateThread 로 쓰레드를 생성 /  Linux -> pthread_create)
// 리눅스에서 컴파일 ->  컴파일 옵션에 -pthread 를 추가)
void func1() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드1 작동중 ! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드2 작동중 ! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드3 작동중 ! \n";
	}
}

int main() {
	thread t1(func1); // thread allocation and execution 쓰레드 할당 실행
	thread t2(func2); // thread allocation and execution 쓰레드 할당 실행
	thread t3(func3); // thread allocation and execution 쓰레드 할당 실행

	t1.join(); // thread end -> return 쓰레드 종료 시 리턴 
	t2.join(); // thread end -> return 쓰레드 종료 시 리턴
	t3.join(); // thread end -> return 쓰레드 종료 시 리턴

	/*
	t1.detach();
	t2.detach();
	t3.detach();
	*/
	cout << "메인 함수 종료" << endl;

}