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
    // 请在这里完成你的代码
  }
  void build_max_heap(std::vector<int>& nums) {
    // 请在这里完成你的代码
  }
  void mysort(std::vector<int>& nums) {
    length = nums.size();
    nums.insert(nums.begin(), 0); // 在开头插入一个元素，使得待排序元素下标从 1 开始

    // 请在这里完成你的代码
    
    nums.erase(nums.begin()); // 删除开头元素
  }
};
