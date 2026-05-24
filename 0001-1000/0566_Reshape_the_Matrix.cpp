/*
Problem Number: 0566
Problem Name: Reshape the Matrix

Difficulty: Easy

Topics:
Array, Matrix, Simulation

Approach:
Check whether reshaping is possible.

If total number of elements does not match:
return original matrix.

Otherwise:
traverse the original matrix and
fill the new reshaped matrix row-wise.

Time Complexity:
O(m × n)

Space Complexity:
O(r × c)
*/

class Solution {
public:

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int m = mat.size();
        int n = mat[0].size();

        // Reshape not possible
        if(m * n != r * c) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));

        int row = 0;
        int col = 0;

        // Traverse original matrix
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                ans[row][col] = mat[i][j];

                col++;

                // Move to next row
                if(col == c) {

                    col = 0;
                    row++;
                }
            }
        }

        return ans;
    }
};
