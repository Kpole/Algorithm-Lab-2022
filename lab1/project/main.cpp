#include <iostream>
#include "include/MergeSort.hpp"
#include "include/InsertionSort.hpp"
using namespace std;



int main(){
  MergeSort my_merge_sort;
  InsertionSort my_insertion_sort;
  bool loop = true;
	while (loop) {
		cout << endl;
		cout << "Select a Sort Algorithm to Test Run: " << endl;
		cout << "1.Insertion Sort" << endl;
		cout << "2.Merge Sort" << endl;
		cout << "others to exit" << endl;
		int opt = 0;
		cin >> opt;
		switch (opt) {
		case 1:
      my_insertion_sort.test_sort();
			break;
		case 2:
      my_merge_sort.test_sort();
			break;
		default:
			loop = false;
			break;
		}
		getchar();
		if(opt != 1 && opt != 2) break;
		do {
			cout << "Please enter Enter to continue";
			if(getchar() == 10) break;	
		} while(true);
	}
  return 0;
}