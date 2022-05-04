#pragma once
#include "MySort.hpp"

class MergeSort: public MySort {
public:
  void merge_sort_aux(std::vector<int>& nums, int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    merge_sort_aux(nums, left, mid);
    merge_sort_aux(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right) {
      if(nums[i] <= nums[j]) {
        tmp[k++] = nums[i++];
      } else {
        tmp[k++] = nums[j++];
      }
    }
    while(i <= mid) tmp[k++] = nums[i++];
    while(j <= right) tmp[k++] = nums[j++];
    for(int i = left; i <= right; i++){
      nums[i] = tmp[i - left];
    }
  }
  void mysort(std::vector<int>& nums) {
    int n = nums.size();
    merge_sort_aux(nums, 0, n - 1);
  }
};