// MaxHeap.cpp 
// Nathan Wu 
#include "MaxHeap.h"
#include <iostream>

void MaxHeap::swap(int index1, int index2){
	int temp = vdata[index1];
	vdata[index1] = vdata[index2];
	vdata[index2] = temp;
}

void MaxHeap::percolate_up(int i){
	int p = i/2;
	int current = i;
	while (current > 0 && vdata[p] < vdata[current]){
		swap(p, current);
		current = p;
		p = p/2;
	}
}

void MaxHeap::percolate_down(int i){
	int length = vdata.size();
	int leftchild = i*2;
	int rightchild = i*2 + 1;
	int maxindex = i;
	if(lefchild <= length && vdata[leftchild] > vdata[maxindex])
		maxindex = leftchild;
	if(rightchild <= length && vdata[rightchild] > vdata[maxindex])
		maxindex = rightchild;
	if (maxindex != i){
		swap(maxindex, i);
		percolate_down(maxindex);
	}
}