#pragma once
#include "MySort.hpp"

class MergeSort: public MySort {
public:
  void merge_sort_aux(std::vector<int>& nums, int left, int right) {

  }
  void mysort(std::vector<int>& nums) {
    int n = nums.size();
    merge_sort_aux(nums, 0, n - 1);
  }
};