#pragma once
#include "MySort.hpp"
/*
该文件为三路快速排序（拓展实验）
*/

class ThreeWayQuickSort: public MySort {
public:
  void three_way_quick_sort(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    three_way_quick_sort(nums, 0, nums.size() - 1);
  }
};