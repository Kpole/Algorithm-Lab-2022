#pragma once
#include "MySort.hpp"
/*
该文件为三路快速排序（拓展实验）
*/

class ThreeWayQuickSort: public MySort {
public:
  void three_way_quick_sort(std::vector<int>& nums, int p, int q) {
    if(p >= q) return;
    int pivot = nums[rand() % (q - p + 1) + p];
    int i = p, j = p, k = q;
    while(i <= k) {
      if(nums[i] < pivot) {
        swap(nums[i], nums[j]);
        i ++; j ++;
      } else if(nums[i] > pivot) {
        swap(nums[i], nums[k]);
        k --;
      } else i ++;
    }
    three_way_quick_sort(nums, p, j - 1);
    three_way_quick_sort(nums, k + 1, q);
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    three_way_quick_sort(nums, 0, nums.size() - 1);
  }
};