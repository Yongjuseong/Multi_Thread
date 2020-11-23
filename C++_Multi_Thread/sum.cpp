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

	// 쓰레드의 id 를 구한다. Find Thread Id
	thread::id this_id = std::this_thread::get_id();
	printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,
		*(end - 1), sum); // cout 쓰면 컨텍스트 스위칭될 때 프린트 값이 꼬이게 된다. (cout은 서로 간섭 가능, printf 는 컨텍스트 스위칭이 되어도 출력값이 섞이지가 않음. Using cout causes the print values to get twisted when context switches. (cout can interfere with each other, printf does not mix output values even when context is switched.

}

int main() {
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	// 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터 # Store the values from each treads in Vector
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
	std::cout << "전체 합 : " << total << std::endl;
}