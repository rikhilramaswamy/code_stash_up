class Solution {
public:
    bool validate_digit_position(int row, int col, int digit, auto & board){
        //cout<<"\n validate_digit_position invoked for : row: "<<row<<"\t col: "<<col<<"\t dig: "<<digit;
        assert( row >=0 && row < 9);
        assert( col >=0 && col < 9);
        // horizontal conflicts
        for(int i = 0; i < 9; i++){
            if(board[row][i] != '.'){
                if((board[row][i] - '0') == digit)
                    return false;
            }
        }
        
        //cout<<"\trig1";
        // vertical conflicts 
        for(int i = 0; i < 9 ; i++){
            if(board[i][col] != '.'){
                if((board[i][col] - '0') == digit)
                    return false;
            }        
        }
        
        //cout<<"\trig2";

        // get base address of associated quadrant 
        int x = row - (row % 3);
        int y = col - (col % 3);
        
        // cout<<"\trig3";

        
        // Quadrant 3*3 conflict
        for( int i = 0; i < 3; i++){
            for(int j = 0; j < 3 ; j++){
                //cout<<"\t x: "<<x<<"\t y: "<<y<<"\tx+i:"<<x+i<<"\t y+j: "<<y+j;
                if(board[x+i][y+j] != '.'){
                    if((board[x+i] [y+j] - '0') == digit){
                        return false;
                    }  
                }
            }
        }
        
        // cout<<"\trig4";

        
        return true;
    }
    
    
    bool backtrack(auto & board, int row, int col){
        // we have placed all the 9*9 cell with right values
        if( row == 9)  return true;
        
        // we are done with all digits of row: row ; So move to the next row 
        if( col == 9) return backtrack(board, row+1, 0);
        //cout<<"\n backtrack invoked with row: "<<row<<"\t col: "<<col<<"\t board[r][c]"<<board[row][col];

        
        if(board[row][col] != '.') return backtrack(board, row, col+1);
        
        // try to see what digit can be placed in cell[row][col]
        for(int d = 1; d <= 9; d++){
            if(validate_digit_position(row, col, d, board)){
                // freeze digit
                board[row][col] = '0'+ d;  // TODO: is this correct???
                if( backtrack(board, row, col+1)) return true; // this line is magic; it takes care of STOPPING the backtracking algo once we have ONE solution
                //undo choice
                board[row][col] = '.';   
            }       
        }   
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        assert(n == 9);
        int m = board[0].size();
        assert(m == 9);
        
        
        backtrack(board, 0, 0);
    }
};
