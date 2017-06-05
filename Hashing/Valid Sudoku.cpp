/*

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int Solution::isValidSudoku(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,m=A.size(),n=A[0].size();
    bool row[9][9],col[9][9],s[3][3][9];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    memset(s,false,sizeof(s));
    for(i=0;i<9;++i)
    {
        for(j=0;j<9;++j)
        {
            if(A[i][j]>'0' && A[i][j]<='9')
            {
                int digit=A[i][j]-'1';
                if(row[i][digit])
                return false;
                row[i][digit]=true;
                if(col[j][digit])
                return false;
                col[j][digit]=true;
                if(s[i/3][j/3][digit])
                return false;
                s[i/3][j/3][digit]=true;
            }
        }
    }
    return 1;
}
