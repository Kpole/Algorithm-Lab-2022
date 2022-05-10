#include <iostream>
#include "include/MergeSort.hpp"
#include "include/InSertionSort.hpp"
using namespace std;
int main(){
  MergeSort my_merge_sort;
  InsertionSort my_insertion_sort;
  bool loop = true;
  vector<int> vec{6,1,2,3,4,5};
	while (loop) {
    cout << endl;
    cout << "Select a Sort Algorithm to Test Run: " << endl;
		cout << "1.Insertion Sort" << endl;
		cout << "2.Merge Sort" << endl;
		cout << "3.Get reverse sort pair number"<<endl;
		cout << "4.Get "<<endl;
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
		case 3:
	//   cout<<my_merge_sort.get_unsort_pair(vec,0,5)<<endl;
	  		break;
		default:
			loop = false;
			break;
		}
		getchar();
		do {
			cout << "Please enter Enter to continue <<endl << Please enter \'q\' to quit";
			char f = getchar();
			if(f == 10){
				break;
			}else if(f == 'q'){return 0;}
		} while(true);
	}
  return 0;
}