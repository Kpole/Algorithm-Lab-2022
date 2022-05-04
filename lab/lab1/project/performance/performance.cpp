#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include<condition_variable>

#include "../include/InsertionSort.hpp"
#include "../include/MergeSort.hpp"

using namespace std;

string RED = "\033[1;31m";
string GREEN = "\033[1;32m";
string BLUE = "\033[1;34m";
string END = "\033[0m";

string test_input_file = "../data/test/data.in";

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
	}
	cout << GREEN << "Congratulation, you have passed all test cases!" << END << endl << endl;
}

int main() {
	test(new MergeSort());
	test(new InsertionSort());

	return 0;
}