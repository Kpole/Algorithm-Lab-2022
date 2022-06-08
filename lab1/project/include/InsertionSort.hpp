#pragma once
#include "MySort.hpp"

class InsertionSort: public MySort {
public:
  void mysort(std::vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++) {
      int x = nums[i];
      int j = i - 1;
      while(j >= 0 && nums[j] > x) {
        nums[j + 1] = nums[j];
        j --;
      }
      nums[j + 1] = x;
    }
  }
};