#ifndef SORT_PERFORMANCE_H
#define SORT_PERFORMANCE_H

#include "insertion_sort.h"
#include "merge_sort.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

#include "util.h"

using SortFunction = std::function<void(std::vector<int>&)>;

const int kNumSize = 10000;

static std::vector<int> kNums;

void GenerateTestNums(int num_size) {
	// generate test nums
	if (kNums.empty()) {
		Random rnd(-1000, 1000);
		for (int i = 0; i < num_size; i++) {
			kNums.push_back(rnd.GenRandomNumber());
		}
	}
}

void TestSortPerformance(SortFunction sort) {

	// get test nums
	std::vector<int> nums = kNums;

	// start performance test
	Timer timer;
	timer.Start();

	sort(nums);

	timer.End();

	std::cout << "cost: " << timer.TimeSpan() << "seconds" << std::endl;

}

void TestInsertSortPerformance() {
	std::cout << "Testing insertion sort" << std::endl;
	TestSortPerformance(InsertionSort);
}

void TestMergeSortPerformance() {
	std::cout << "Testing merge sort" << std::endl;
	TestSortPerformance(MergeSort);
}

void Performance(int num_size = kNumSize) {

	// generate test nums
	GenerateTestNums(num_size);

	// firstly to test insertion sort
	TestInsertSortPerformance();
	// std::cout << "Press any key to continue" << std::endl;
	// getchar();

	// secondly to test merge sort
	TestMergeSortPerformance();
	// std::cout << "Press any key to continue" << std::endl;
	// getchar();
}


#endif