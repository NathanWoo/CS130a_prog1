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



int main (int argv, char** argc) {
	if (argv != 2) {
		cout << "Please provide a file name" << endl;
		return 1;
	}

	ifstream inputFile (argc[1]);
	string line;

	if (inputFile.fail()){
		cout << "Could not open file" << argc[1];
	}

	int k;
	getline (inputFile, line);
	stringstream ss;
	ss << line;
	ss >> k;

	//typedef vector<int> scoreV;
	vector <pair<string, scoreV> >mainV;
	
	while( (getline(inputFile, line)) && (line.length() >0)) {
		int score;
		string id;
		stringstream newss;
		newss << line;
		newss >> id >> score;
		bool inserted;
		inserted = false;

		for (int i = 0; i < mainV.size(); i++){
			if (mainV[i].first == id){
				mainV[i].second.push_back(score);
				inserted = true;
			}
		}
		if (!inserted){
			scoreV v1;			
			v1.push_back(0);
			v1.push_back(score);
			pair<string, scoreV> newStudent (id, v1);
			mainV.push_back(newStudent);	
		}
	}

	int maxscore = 0;
	string maxid = "All the students have less than " + to_string(k) +" scores";

	for (int i = 0; i < mainV.size(); i++){
		int vec_length = mainV[i].second.size() - 1;
		if (vec_length < k)
			continue;
		build_heap(mainV[i].second, vec_length);
		int currentMaxAvg = 0;
		for (int j = 0; j < k; j++){
			currentMaxAvg += get_max(mainV[i].second, vec_length);
			vec_length -= 1;
		}
		if (currentMaxAvg > maxscore){
			maxscore = currentMaxAvg;
			maxid = mainV[i].first;
		}

	}

	 cout << maxid << endl;;
}