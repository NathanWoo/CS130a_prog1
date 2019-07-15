//MaxHeap.h
#ifndef MAXHEAP_H
#define MAXHEAP_H


class MaxHeap {
public:
	void buildheap();
	void insert()
	int deletemax();


 private:
    std::vector<int> vdata; 
    void percolate_up(int i); 
    void percolate_down(int i); 
    void swap(int index1, int index2);
}; 

#endif