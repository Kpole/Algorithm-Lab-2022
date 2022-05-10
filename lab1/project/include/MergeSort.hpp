#pragma once
#include "MySort.hpp"
class MergeSort : public MySort
{
public:
  void merge_sort_aux(std::vector<int> &nums, int left, int right)
  {
    if (left >= right)
      return;
    int mid = (left + right) / 2;
    merge_sort_aux(nums, left, mid);
    merge_sort_aux(nums, mid + 1, right); //先分
    merge(nums, left, mid, right);        //再治
  }

  //分治思想的“治”部分，将有序的两个部分合并成一个有序部分
  void merge(std::vector<int> &a, int start, int mid, int end)
  {
    int i, j, k = 0;
    i = start;
    j = mid + 1;
    int *temp; //临时数组用来存放有序数列部分
    temp = (int *)malloc((end - start + 1) * sizeof(int));
    while (i <= mid && j <= end)
    {
      if (a[i] < a[j])
        temp[k++] = a[i++];
      else
        temp[k++] = a[j++];
    }

    if (j == end + 1)
    {
      while (i <= mid)
        temp[k++] = a[i++];
    }
    if (i == mid + 1)
    {
      while (j <= end)
        temp[k++] = a[j++];
    }

    for (i = 0, j = start; i < k; i++, j++)
      a[j] = temp[i];
    delete []temp;
  }

  void mysort(std::vector<int> &nums)
  {
    int n = nums.size();
    merge_sort_aux(nums, 0, n - 1);
  }
};