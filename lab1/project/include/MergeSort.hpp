// #pragma once
// #include "MySort.hpp"
// using namespace std;
// class MergeSort: public MySort {
// public:
//   int get_unsort_pair(std::vector<int> &nums,int left,int right){
//     if(left >= right)return 0;
//     int mid = (left+right)/2;
//     int l1 = get_unsort_pair(nums,left,mid) +  get_unsort_pair(nums,mid + 1,right);
//     l1 += get_unsort_pair_compare(nums,left,mid,right);
//     return l1;
//   }
//   int get_unsort_pair_compare(std::vector<int> &nums,int left,int mid, int right){
//     int pairNum = 0;
//     int len = right-left +1;
//     int *tmp = new int[len];
//     int l = left, r = mid +1, pos = 0;
//     while(l<=mid && r<=right){
//       if(nums[l] > nums[r]){
//         pairNum += mid-l+1;
//       }
//       tmp[pos++] = nums[l]<=nums[r]?nums[l++]:nums[r++];
//     }
//     while(l<=mid){
//       tmp[pos++] = nums[l++];
//     }
//     while(r<=right){
//       tmp[pos++] = nums[r++];
//     }
//     for(int i=0;i<len;i++){
//       nums[left+i] = tmp[i];
//     }
//     cout << left << ' ' << right << ' ' << pairNum << endl;
//     delete[] tmp;
//     return pairNum;
//   }

//   void merge(std::vector<int> &nums, int left,int mid,int right){
//     int l=right-left+1;
//     int *tmp = new int[l];
//     int i=left,j=mid+1,pos=0;
//     while(i<=mid && j<=right){
//       tmp[pos++] = nums[i]<=nums[j]?nums[i++]:nums[j++];
//     }
//     while(i<=mid){
//       tmp[pos++] = nums[i++];
//     }
//     while(j<=right){
//       tmp[pos++] = nums[j++];
//     }
//     for(int i=0;i<l;i++){
//         nums[left+i] = tmp[i];
//     }
//     delete[] tmp;
//   }
//   void merge_sort_aux(std::vector<int>& nums, int left, int right) {
//     if(left >= right){return;}
//     int mid = (left+right)/2;
//     merge_sort_aux(nums,left,mid);
//     merge_sort_aux(nums,mid + 1,right);
//     merge(nums,left,mid,right);
//   }
//   void mysort(std::vector<int>& nums) {
//     int n = nums.size();
//     merge_sort_aux(nums, 0, n - 1);
//   }
// };

#pragma once
#include "MySort.hpp"
using namespace std;
class MergeSort: public MySort {
public:
  void merge_sort_aux(std::vector<int>& nums, int left, int right) {
    int mid;
  //merge-sort
    if (left<right){
      mid=(left+right)/2;
      merge_sort_aux( nums, left, mid);
      merge_sort_aux( nums, mid+1, right);
    }else{return;}
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1];
    int R[n2];

    // std::vector<int> L;
    // std::vector<int> R;
    // for(int i=0;i<n1;i++){
    //   L.push_back(nums[left+i]);
    // }
    // for(int j=0;j<n2;j++){
    //   R.push_back(nums[mid+1+j]);
    // }
    for(int i=0;i<n1;i++){
      L[i] = nums[left+i];
    }
    for(int i=0;i<n2;i++){
      R[i] = nums[mid+1+i];
    }
    int m=0;
    int n=0;
    for(int k=left;k<=right;k++){ 
      if(m<n1 && n<n2){
        if (L[m]<=R[n]){
          nums[k]=L[m];
          m++;
        }else{
          nums[k]=R[n];
          n++;
        }
      }else{
        if(m<n1){
          nums[k] = L[m++];
        }
        if(n<n2){
          nums[k] = R[n++];
        }
      }
    }
  }
  void mysort(std::vector<int>& nums) {
    int n = nums.size();
    merge_sort_aux(nums, 0, n - 1);
  }
};