/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

*/

bool isvalid(vector<string> &A,int r,int c)
{
    int m=A.size(),n=A[0].length();
    if(r>=0 && r<m && c>=0 && c<n)
    return true;
    return false;
}

bool search(vector<string> &A, string B,int r,int c,int index)
{
    if(index==B.length())
    return true;
    int rows[4]={-1,0,0,1};
    int cols[4]={0,-1,1,0};
    
    for(int k=0;k<4;++k)
    {
        if(isvalid(A,r+rows[k],c+cols[k]) )
        {
            if(A[r+rows[k]][c+cols[k]]==B[index])
            {
                
            if(search(A,B,r+rows[k],c+cols[k],index+1))
            return true;
            }
        }
    }
    return false;
}


int Solution::exist(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,m=A.size(),n=A[0].length();
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[i][j]==B[0])
            {
                if(search(A,B,i,j,1))
                return true;
            }
        }
    }
    return false;
    
}
