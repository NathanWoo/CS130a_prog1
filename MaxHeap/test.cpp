//main.cpp created by Nathan Wu, perm 6134910, for CS 130A, on Jul 13, 2019 

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream> 

using namespace std;

typedef vector<int> scoreV;



void percolate_up (scoreV& arr, int i) {
	int p = i/2;
	int current = i;
	while (current > 1 && arr[p] < arr[current]){
		int temp = arr[p];
		arr[p] = arr[current];
		arr[current] = temp;
		current = p;
		p = p/2;
	}
}

void percolate_down(scoreV& arr, int i, int length){
	int leftchild = i*2;
	int rightchild = i*2 + 1;
	int maxindex = i;
	if(leftchild <= length && arr[leftchild] > arr[maxindex])
		maxindex = leftchild;
	if(rightchild <= length && arr[rightchild] > arr[maxindex])
		maxindex = rightchild;
	if (maxindex != i){
		int temp = arr[i];
		arr[i] = arr[maxindex];
		arr[maxindex] = temp;
		percolate_down(arr, maxindex, length);
	}
}

void build_heap(scoreV& arr, int length){
	int start_index = (length/2);
	for (int i = start_index; i >= 1; i--){ 
    percolate_down(arr, i, length); 
	} 
}

int get_max(scoreV& arr, int length){
	int max = arr[1];
	arr[1] = arr[length];
	percolate_down(arr, 1, length-1);
	return max;
}



int main () {

	vector<int> a;
	a.push_back(0);
	a.push_back(10);
	a.push_back(20);
	a.push_back(3);
	a.push_back(15);
	a.push_back(9);
	a.push_back(5);
	a.push_back(7);
	int vlength = a.size() - 1;
	cout<< "The length is "<<vlength<<endl;
	build_heap(a, vlength);
	for (int i = 1; i < vlength + 1; i++){
		cout << i << " : " << a[i] << endl;
	}

	for (int i = 0; i < 7; i++){
		int max;
		max = get_max(a, vlength);
		cout << "this max is " << max << endl;
		vlength -= 1;
	}


}