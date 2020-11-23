#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	// �������� id �� ���Ѵ�. Find Thread Id
	thread::id this_id = std::this_thread::get_id();
	printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start,
		*(end - 1), sum); // cout ���� ���ؽ�Ʈ ����Ī�� �� ����Ʈ ���� ���̰� �ȴ�. (cout�� ���� ���� ����, printf �� ���ؽ�Ʈ ����Ī�� �Ǿ ��°��� �������� ����. Using cout causes the print values to get twisted when context switches. (cout can interfere with each other, printf does not mix output values even when context is switched.

}

int main() {
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	// �� �����忡�� ���� �κ� �յ��� �����ϴ� ���� # Store the values from each treads in Vector
	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.push_back(thread(worker, data.begin() + i * 2500,
			data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	std::cout << "��ü �� : " << total << std::endl;
}