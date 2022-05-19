#pragma once
#include "MySort.hpp"
/*
该文件为快速排序
*/

class QuickSort: public MySort {
public:
  int partition(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
  }
  void quick_sort(std::vector<int>& nums, int l, int r) {
    // 请在这里完成你的代码
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    quick_sort(nums, 0, nums.size() - 1);
  }
};