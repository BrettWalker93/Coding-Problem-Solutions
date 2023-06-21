class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));
        
        for (int i = 0; i < 9; i++) {            
            for (int j = 0; j < 9; j++) {
                
                string c = "";
                c.push_back(board[i][j]);

                if (c != ".") {                    
                    int idx = stoi(c) - 1;                    
                    //check row
                    if (rows[i][idx]) { 
                        //cout << "row " << i << " and index " << idx << " is true" << endl;
                        return false;
                    }
                    else rows[i][idx] = true;                                        
                    //check col
                    if (cols[j][idx]) return false;
                    else cols[j][idx] = true;                    
                    //check box
                    if (i < 3) {                        
                        if (j < 3) {
                            if (boxes[0][idx]) return false;
                            else boxes[0][idx] = true;
                        }                         
                        else if (j < 6) {
                            if (boxes[1][idx]) return false;
                            else boxes[1][idx] = true;
                        }                        
                        else {
                            if (boxes[2][idx]) return false;
                            else boxes[2][idx] = true;
                        }
                    }                    
                    else if (i < 6) {                        
                        if (j < 3) {
                            if (boxes[3][idx]) return false;
                            else boxes[3][idx] = true;
                        }                         
                        else if (j < 6) {
                            if (boxes[4][idx]) return false;
                            else boxes[4][idx] = true;
                        }                        
                        else {
                            if (boxes[5][idx]) return false;
                            else boxes[5][idx] = true;
                        }
                    }                    
                    else {                        
                        if (j < 3) {
                            if (boxes[6][idx]) return false;
                            else boxes[6][idx] = true;
                        }                         
                        else if (j < 6) {
                            if (boxes[7][idx]) return false;
                            else boxes[7][idx] = true;
                        }                        
                        else {
                            if (boxes[8][idx]) return false;
                            else boxes[8][idx] = true;
                        }                        
                    }                                        
                }                
            }            
        }        
        return true;         
    }
};
