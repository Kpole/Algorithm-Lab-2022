#pragma once
#include "MySort.hpp"
/*
该文件为快速排序
*/

class QuickSort: public MySort {
public:
  int partition(std::vector<int>& nums, int p, int q) {
    swap(nums[p], nums[rand() % (q - p + 1) + p]);
    int pivot = nums[p];
    int i = p;
    for(int j = p + 1; j <= q; j++){
      if(nums[j] <= pivot) {
        i = i + 1;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i], nums[p]);
    return i;
  }
  void quick_sort(std::vector<int>& nums, int l, int r) {
    if(l < r) {
      int m = partition(nums, l, r);
      quick_sort(nums, l, m - 1);
      quick_sort(nums, m + 1, r);
    }
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    quick_sort(nums, 0, nums.size() - 1);
  }
};