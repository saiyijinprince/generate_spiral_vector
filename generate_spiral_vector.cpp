#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > results(n);
	if (n == 1) {
		vector<int> v;
		v.push_back(1);
		results[0] = v;
		return results;
	}

	//pre-initialize the vectors.
	for (int i=0; i<n; ++i) {
		vector<int> r(n);
		results[i] = r;
	}	

	int max = n*n;

	int count = 0;
	int row = 0, col = 0;
	int col_end = n-1, row_end = n-1, col_start = 0, row_start = 0;
	while (count < max) {
		for (col = col_start; col <= col_end; ++col) {
			results[row][col] = ++count;
		}
		--col; //bring back within bounds when it exited the last for loop

		//Check to break if we do the last part of the spiral
		if (count == max)
			return results;

		++row_start; //to prevent overlap when doing edges
		
		for (row = row_start; row <= row_end; ++row) {
			results[row][col] = ++count;
		}
		--row; //bring back within bounds when it exited the last for loop

		--col_end; //to prevent overlap when doing edges

		for (col = col_end; col >= col_start; --col) {
			results[row][col] = ++count;
		}
		++col; //bring back within bounds when it exited the last for loop

		--row_end; //to prevent overla when doing edges.

		for (row = row_end; row >= row_start; --row) {
			results[row][col] = ++count;
		}
		++row; //bring back within bounds when it exited the last for loop

		++col_start; //to prevent overla when doing edges.
	}

	return results;
}

int main() {
	int n = 2;
	vector<vector<int>> results = generateMatrix(n);

	for (int i = 0; i < results.size(); ++i) {
		for (int j = 0; j<results[i].size(); ++j) {
			cout << results [i][j] << "\t";
		}
		cout << endl;
	}

	int u;
	cin >> u;
}