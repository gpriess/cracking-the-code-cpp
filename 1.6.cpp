#include <iostream>
#include <utility>
#include <vector>
using namespace std;


//	From pg. 73:
// 	"Given an image represented by an NxN matrix, where each pixel
// 	 in the image is 4 bytes, write a method to rotate the image
//	 by 90 degrees. Can you do this in place?"


void print(const vector<vector<int> >& vect){
	
	cout << "vect: " << endl;
	for(auto y = vect.begin(); y < vect.end(); y++){
		for(auto x = y->begin(); x < y->end(); x++){
			cout << *x << "\t";
		}
		cout << endl;
	}
}

//rotates an NxN image matrix by 90 degrees clockwise
void rotateCW90(vector<vector<int> >& image){

	int n = image.size();
	int r = (image.size()/2);
	int c = ((image.size() + 1)/2);
	for(int x = 0; x < r; x++){
		for(int y = 0; y < c; y++){
			int temp = image[x][y];
			image[x][y] = image[y][n-1-x];
			image[y][n-1-x] = image[n-1-x][n-1-y];
			image[n-1-x][n-1-y] = image[n-1-y][x];
			image[n-1-y][x] = temp;
		}

	}

	return;
}



int main(){

	//forms vector of specified
	vector<vector<int> > image;
	int size = 4;
	for(int y = 0; y < size; y++){
		vector<int> row;
		for(int x = 0; x < size; x++){
			row.push_back(x + y*size);
		}
		image.push_back(row);
	}
	print(image);
	rotateCW90(image);
	print(image);




	return 0;

}