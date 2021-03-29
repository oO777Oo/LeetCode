#include <iostream>
#include <vector>


class MatrixManipulation;
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K);


int main(int argc, char const *argv[]) {
	return 0;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
	// Preparing matrix to work with.
	MatrixManipulation matrix(mat);
    std::vector<std::vector<int>> ans;
    int vertical = mat.size() - 1;
    int horizontal = mat[0].size() - 1;
    for(int i = 0; i < mat.size(); i++) {
        std::vector<int> v;
        for(int j = 0; j < mat[i].size(); j++) {
            // Init left top corner
            int verticalTopLeft = i - K;
            int horizontalTopLeft = j - K;

            // Init right bottom corner
            int verticalBottRight = i + K;
            int horizontalBottRight = j + K;


            if (verticalTopLeft < 0) {
                verticalTopLeft = 0;
            }

            if (horizontalTopLeft < 0) {
                horizontalTopLeft = 0;
            }

            if (verticalBottRight > vertical) {
                verticalBottRight = vertical;
            }

            if(horizontalBottRight > horizontal) {
                horizontalBottRight = horizontal;
            }
            v.push_back(matrix.sumRegion(verticalTopLeft, horizontalTopLeft, verticalBottRight, horizontalBottRight));
        }
        ans.push_back(v);
    }
    return ans;
}

// Help Class to do calculation
class MatrixManipulation {
	/* Idea is to calculate area. which can be calculated with formula
	    	Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)
	   For example we have this matrix
		O--|--|--|--|--|
		|--|--A--|--|--B
		|--|--|--|--|--|
		|--|--|--|--|--|
		|--|--C--|--|--D
	*/
	public:
		std::vector<std::vector<std::pair<int,int>> matrix;
		
		MatrixManipulation(std::vector<std::vector<int>>& matrix) {
			if (matrix.size() == 0 || matrix[0].size() == 0) return;
	        for (int i = 0; i < matrix.size(); i++) {
	            int liniarSum = 0;
	            std::vector<std::pair<int,int>> v;

	            for (int j = 0; j < matrix[i].size(); j++) {
	                liniarSum += matrix[i][j];
	                if (i != 0) {
	                    std::pair<int,int> inter = {matrix[i][j], liniarSum + this->matrix[i-1][j].second};
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
	        if (row1 != 0) { 							  // to avoid index out of bounds.
	            top = this->matrix[row1-1][col2].second; // SUM(OB) is from (0,0) -> (row1-1, col2);
	        }
	        if (col1 != 0) { 						  // to avoid index out of bounds.
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

