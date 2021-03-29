#include <iostream>

class NumMatrix {
	using namespace std;
	public:
        vector<vector<pair<int,int>>> matrix;

        NumMatrix(vector<vector<int>>& matrix) {
        	/* Init matrix in a matrix with pair
        	1. on pair index 0 will be the original value
        	2. on pair index 1 will be the sum. */
            if (matrix.size() == 0 || matrix[0].size() == 0) return;
            for (int i = 0; i < matrix.size(); i++) {
                int liniarSum = 0;
                vector<pair<int,int>> v;

                for (int j = 0; j < matrix[i].size(); j++) {
                    liniarSum += matrix[i][j];
                    if (i != 0) {
                        pair<int,int> inter = {matrix[i][j], liniarSum + this->matrix[i-1][j].second};
                        v.push_back(inter);
                    } else {
                        pair<int,int> inter = {matrix[i][j], liniarSum};
                        v.push_back(inter);
                    }
                }
                this->matrix.push_back(v);
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
        	/* Idea is to calculate area. which can be calculated with formula
        	Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)*/
            int completArea = this->matrix[row2][col2].second;  // Sum(OD) is from (0,0) -> (row2, col2); 
            int top = 0; 									   // SUM(OB);
            int left = 0; 									  // SUM(OC)
            int duplicate = 0;
            
            if (row1 != 0) { 
            											  // to avoid index out of bounds.
                top = this->matrix[row1-1][col2].second; // SUM(OB) is from (0,0) -> (row1-1, col2);
            }
            
            if (col1 != 0) { 
            										  // to avoid index out of bounds.
                left = this->matrix[row2][col1-1].second; // SUM(OC) is from (0,0) -> (row2, col1-1);
            }
            
            if (row1 != 0 && col1 != 0) {
            									  // to avoid index out of bounds.
                duplicate = this->matrix[row1-1][col1-1].second; // SUM(OA) if from (0,0) -> (row1-1, col1 - 1);
                /* duplicate is 2 times extract from area because of top and left. This part is intersection part of this 2 area 
                   that's why is needed to add it back. */
            } 
            return completArea - top - left + duplicate; 
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */