class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        // rotate each layer
        
        for (int i = 0; i < n / 2; i++) {  

            // corners
            
            int temp = matrix[i][i];
            
            matrix[i][i] = matrix[n - i - 1][i];
            
            matrix[n - i - 1][i] = matrix[n - i - 1][n - i - 1];

            matrix[n - i - 1][n - i - 1] = matrix[i][n - i - 1];
            
            matrix[i][n - i - 1] = temp;
            
            // sides
            
            if (i == n / 2) return;
            
            //cout << "i: " << i << endl;
            
            for (int j = 0; j < n - 2 * (i+1); j++) {
                                              
                int k = j+1+i;
            
                temp = matrix[i][k];
                
                matrix[i][k] = matrix[n - 1 - k][i];
                
                matrix[n - 1 - k][i] = matrix[n - 1 - i][n - 1 - k];
                
                matrix[n - 1 - i][n - 1 - k] = matrix[k][n - 1 - i];
                
                matrix[k][n - 1 - i] = temp;
                
            }
        }        
    }
};
