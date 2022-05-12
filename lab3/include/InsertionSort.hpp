#pragma once
#include "MySort.hpp"
/*
本文件为插入排序
*/

class InsertionSort: public MySort {
public:
  void mysort(std::vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++){
      int j = i - 1;
      while(j >= 0 && nums[j] > nums[i]) j --;
      j ++;
      int x = nums[i];
      for(int k = i; k > j; k --) nums[k] = nums[k - 1];
      nums[j] = x;
    }
  }
};