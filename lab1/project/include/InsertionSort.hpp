#pragma once
#include "MySort.hpp"

class InsertionSort: public MySort {
public:
  void mysort(std::vector<int>& nums) {
    int key,i,j;
    for (j=1;j<nums.size();j++)
    {
        key=nums[j];
        i=j-1;
        while ((i>=0)&&(nums[i]>key)){
          nums[i+1]=nums[i];
          i--;
        }
        nums[i+1] = key;
    }
  }
};