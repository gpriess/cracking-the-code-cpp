#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

//From pg. 73:
// "Write an algorithm such that if an element in an MxN matrix is 0, 
//its entire row and column are set to 0."

void print(const vector<vector<int> >& matrix) {
	
	cout << "matrix: " << endl;
	for(auto y = matrix.begin(); y < matrix.end(); y++) {
		for(auto x = y->begin(); x < y->end(); x++) {
			cout << *x << "\t";
		}
		cout << endl;
	}

	return;
}


void setMatrixZeros(vector<vector<int> >& matrix){

	unordered_set<int> rowsContainingZeros;
	unordered_set<int> columnsContainingZeros;

	//construct hash sets corresponding to the indices of rows
	// and columns that contain a zero
	for(auto y = matrix.begin(); y < matrix.end(); y++) {
		for(auto x = y->begin(); x < y->end(); x++) {
			if(*x == 0) {
				auto row = rowsContainingZeros.find(y - matrix.begin());
				auto col = columnsContainingZeros.find(x - y->begin());
				if(row == rowsContainingZeros.end()) 
					rowsContainingZeros.insert(y - matrix.begin());
				if(col == columnsContainingZeros.end())
					columnsContainingZeros.insert(x - y->begin());
			}
		}
	}
	for(auto y = rowsContainingZeros.begin(); y != rowsContainingZeros.end(); y++) {
		cout << "row: " << *y << endl;
	}
		for(auto y = columnsContainingZeros.begin(); y != columnsContainingZeros.end(); y++) {
		cout << "column: " << *y << endl;
	}

	//set applicable rows to zero
	for(auto y = matrix.begin(); y < matrix.end(); y++) {
		auto row = rowsContainingZeros.find(y - matrix.begin());
		if(row != rowsContainingZeros.end()) {
			for(auto x = y->begin(); x < y->end(); x++) {
				*x = 0;
			}
		}
	}

	//set applicable columns to zero
	for(auto y = matrix.begin(); y < matrix.end(); y++) {
		for(auto x = y->begin(); x < y->end(); x++) {
			auto col = columnsContainingZeros.find(x - y->begin());
			if(col != columnsContainingZeros.end())
					*x = 0;
		}
	}
	
	return;
}



int main(){

	vector<vector<int> > image;
	int m = 4;
	int n = 5;
	for(int y = 0; y < m; y++) {
		vector<int> row;
		for(int x = 0; x < n; x++) {
			row.push_back(x + y*m);
			if((x + y*m) == 10)
				row[x] = 0;
		}
		image.push_back(row);
	}
	print(image);
	setMatrixZeros(image);
	print(image);



	return 0;


}