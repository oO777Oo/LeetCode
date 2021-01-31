#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int counter = 0;
    for(int i = 0; i < grid.size(); i++) {
        int size = grid[i].size();
        int mid = size / 2;
        int start = 0;
        int end = size;
        while (true) {
            if (grid[i][size - 1] >= 0) {
                break;
            }
            if (grid[i][0] < 0) {
               counter += size;
                break;
            }
            if(grid[i][mid] < 0 && grid[i][mid - 1] >= 0) {
                counter += (size - mid);
                break;
            } else if (grid[i][mid] >= 0) {
               start = mid + 1;
               mid = (end + start) / 2;
            } else if (grid[i][mid] < 0) {
                end = mid - 1;
                mid = (end + start) / 2;
            }
        }
    }
    return counter;
}

int main() {
    /** Test Cases
      * {{5,1,0},{-5,-5,-5}}
      * {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}
      * {{3,-1,-3,-3,-3},{2,-2,-3,-3,-3},{1,-2,-3,-3,-3},{0,-3,-3,-3,-3}}
     */
    vector<vector<int>> grid = {{3,-1,-3,-3,-3},{2,-2,-3,-3,-3},{1,-2,-3,-3,-3},{0,-3,-3,-3,-3}};
    std::cout << countNegatives(grid) << endl;
    return 0;
}
