#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

// #include "util.h"

class MySort {
public:
	std::string sample_input_file = "./data/samples/data.in";
	std::string test_input_file = "./data/test/data.in";
	std::string RED = "\033[1;31m";
	std::string GREEN = "\033[1;32m";
	std::string END = "\033[0m";
	MySort(){}
	~MySort(){}
	void output_vector(std::vector<int>& nums) {
		for (auto num : nums) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
public:
	void test_sort() {
		std::ifstream ifs(sample_input_file);
		if (!ifs.is_open()) {
			std::cout << "open input_file failed" << std::endl;
			return;
		}

		int test_groups = 0, succ_cnt = 0;
		ifs >> test_groups;
		std::cout << test_groups << std::endl;
		for (int t = 1; t <= test_groups; t++) {
			int n = 0;
			ifs >> n;
			std::vector<int> nums(n);
			for(int i = 0; i < n; i++){
				ifs >> nums[i];
			}
			
			auto origin_nums = nums;
			std::sort(origin_nums.begin(), origin_nums.end());
			mysort(nums);

			if (origin_nums != nums) {
				std::cout << "Sample Test Round " << t << ": \t" << RED << " Wrong Answer" << END << std::endl;
				// std::cout << "Input:" << std::endl;
				// output_vector(origin_nums);
				// std::cout << "Output:" << std::endl;
				// output_vector(nums);
			} else {
				std::cout << "Sample Test Round " << t << ": \t" << GREEN << " Accepted" << END << std::endl;
				succ_cnt ++;
			}
		}
		if(succ_cnt != test_groups) {
			std::cout << "The percentage of successful samples: " << succ_cnt << "/" << test_groups << std::endl;
		}
		std::cout << GREEN << "Congratulation, you have passed all test cases!" << END << std::endl;
	}
	
	virtual void mysort(std::vector<int>& nums) = 0;
};