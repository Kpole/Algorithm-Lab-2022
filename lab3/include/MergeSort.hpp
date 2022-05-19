#pragma once
#include "MySort.hpp"

/*
本文件为归并排序，可以直接套用 lab1 的代码
*/

class MergeSort : public MySort
{
public:
  void merge_sort_aux(std::vector<int> &nums, int left, int right)
  {
  }

  void mysort(std::vector<int> &nums)
  {
    int n = nums.size();
    if(n == 0) return;
    merge_sort_aux(nums, 0, n - 1);
  }
};