#include <iostream>

class NumMatrix {
	using namespace std;
	public:
        vector<vector<pair<int,int>>> matrix;

        NumMatrix(vector<vector<int>>& matrix) {
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
            // Calculating Complet area to row2 and col2;
            int completArea = this->matrix[row2][col2].second;
            int top = 0;
            if(row1 != 0) {
                top = this->matrix[row1-1][col2].second;
            }
            int left = 0;
            if(col1 != 0) {
                left = this->matrix[row2][col1-1].second;
            }
            int duplicate = 0;
            if(row1 != 0 && col1 != 0) {
                duplicate = this->matrix[row1-1][col1-1].second;
            } 
            return completArea - top - left + duplicate; 
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */