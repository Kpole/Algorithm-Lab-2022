#pragma once
#include "MySort.hpp"

class InsertionSort: public MySort {
public:
  void mysort(std::vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++){
      int j = i - 1;
      while(j >= 0 && nums[j] > nums[i]) j --;
      j ++;
      int tmp = nums[i];
      for(int k = i; k > j; k--) nums[k] = nums[k - 1];
      nums[j] = tmp;
    }
  }
};