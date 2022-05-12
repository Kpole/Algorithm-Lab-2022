#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <condition_variable>

#include "../include/InsertionSort.hpp"
#include "../include/MergeSort.hpp"
#include "../include/HeapSort.hpp"
#include "../include/QuickSort.hpp"
#include "../include/ThreeWayQuickSort.hpp"

using namespace std;

string test_input_file = "../data/test/data.in";

// 时间类，用于测试程序运行时间
class Timer {
public:
	Timer() : start_(), end_() {}

	void start() { start_ = std::chrono::steady_clock::now(); }

	void end() { end_ = std::chrono::steady_clock::now(); }

	double time_span() { 
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(end_ - start_);
		return time_span.count();
	}

private:
	std::chrono::steady_clock::time_point start_;
	std::chrono::steady_clock::time_point end_;
};

void test(MySort* mysort) {
	ifstream ifs(test_input_file);
	if (!ifs.is_open()) {
		cout << "open input_file failed" << endl;
		return;
	}

	Timer timer;

	int test_groups = 0, succ_cnt = 0;
	ifs >> test_groups;
	cout << test_groups << endl;
	for (int t = 1; t <= test_groups; t++) {
		int n = 0;
		ifs >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			ifs >> nums[i];
		}
		
		auto origin_nums = nums;
		sort(origin_nums.begin(), origin_nums.end());

		timer.start();
		mysort->mysort(nums);
		timer.end();


		if (origin_nums != nums) {
			cout << "Sample Test Round " << t << ": \t" << RED << " Wrong Answer" << END << endl;
		} else {
			cout << "Sample Test Round " << t << ": \t" << GREEN << " Accepted" << END << endl;
			succ_cnt ++;
		}
		cout << "Test Size: " << BLUE << nums.size()  << END << " \t";
		cout << "Time cost: " << BLUE << fixed << setprecision(10) << timer.time_span()  << END << " seconds" << endl << endl;
	}
	if(succ_cnt != test_groups) {
		cout << "The percentage of successful samples: " << succ_cnt << "/" << test_groups << endl;
	} else {
		cout << GREEN << "Congratulation, you have passed all test cases!" << END << endl << endl;
	}
}

int main() {
	bool loop = true;
	while (loop) {
		cout << endl;
		cout << "[Performance] Select a Sort Algorithm to Test Run: " << endl;
		cout << "1.Insertion Sort" << endl;
		cout << "2.Merge Sort" << endl;
		cout << "3.Heap Sort" << endl;
		cout << "4.Quick Sort" << endl;
		cout << "5.Three Way Quick Sort" << endl;
		cout << "others to exit" << endl;
		int opt = 0;
		cin >> opt;
		switch (opt) {
		case 1:
			test(new InsertionSort());
			break;
		case 2:
      test(new MergeSort());
			break;
		case 3:
			test(new HeapSort());
			break;
		case 4:
			test(new QuickSort());
			break;
		case 5:
			test(new ThreeWayQuickSort());
			break;
		default:
			loop = false;
			break;
		}
		getchar();
		if(opt < 1 || opt > 5) break;
		do {
			cout << "Please enter Enter to continue";
			if(getchar() == 10) break;	
		} while(true);
	}
	return 0;
}