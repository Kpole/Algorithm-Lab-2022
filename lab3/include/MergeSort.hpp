#pragma once
#include "MySort.hpp"

/*
本文件为归并排序
*/

class MergeSort : public MySort
{
public:
  vector<int> tmp;
  void merge_sort_aux(std::vector<int> &nums, int left, int right)
  {
    if(left >= right) return;
    int mid = (left + right) / 2;
    merge_sort_aux(nums, left, mid);
    merge_sort_aux(nums, mid + 1, right);
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
      if(nums[i] <= nums[j]) {
        tmp[k++] = nums[i++];
      } else {
        tmp[k++] = nums[j++];
      }
    }
    while(i <= mid) tmp[k++] = nums[i++];
    while(j <= right) tmp[k++] = nums[j++];
    for(int i = left; i <= right; i++) nums[i] = tmp[i];
  }

  void mysort(std::vector<int> &nums)
  {
    int n = nums.size();
    if(n == 0) return;
    tmp.resize(n, 0);
    merge_sort_aux(nums, 0, n - 1);
  }
};