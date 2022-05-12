#pragma once
#include "MySort.hpp"
/*
本文件为堆排序
*/

class HeapSort: public MySort {
public:
  int heap_size;
  int length;
  void max_heapify(std::vector<int>& nums, int i) {
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = 0;
    if (l <= heap_size && nums[l] > nums[i]) {
      largest = l;
    } else {
      largest = i;
    }
    if (r <= heap_size && nums[r] > nums[largest]) {
      largest = r;
    }
    if(largest != i) {
      swap(nums[i], nums[largest]);
      max_heapify(nums, largest);
    }
  }
  void build_max_heap(std::vector<int>& nums) {
    heap_size = length;
    for (int i = length / 2; i >= 1; i--) {
      max_heapify(nums, i);
    }
  }
  void mysort(std::vector<int>& nums) {
    length = nums.size();
    nums.insert(nums.begin(), 0); // 在开头插入一个元素，使得待排序元素下标从 1 开始

    build_max_heap(nums);
    for(int i = length; i >= 2; i--) {
      swap(nums[1], nums[i]);
      heap_size -= 1;
      max_heapify(nums, 1);
    }
    
    nums.erase(nums.begin()); // 删除开头元素
  }
};
