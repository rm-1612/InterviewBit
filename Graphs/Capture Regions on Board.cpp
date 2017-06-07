/*

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

void fill(vector<vector<char> > &A,int r,int c)
{
    int m=A.size();
    int n=A[0].size();
    if(r<0 || r>=m || c<0 || c>=n )
    return ;
    if(A[r][c]!='-')
    return ;
    A[r][c]='O';
    fill(A,r+1,c);
    fill(A,r-1,c);
    fill(A,r,c-1);
    fill(A,r,c+1);
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size();
    int n=A[0].size();
    int i,j;
    
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[i][j]=='O')
            A[i][j]='-';
        }
    }
    for(j=0;j<n;++j)
    {
        if(A[0][j]=='-')
        {
            fill(A,0,j);
        }
    }
    for(i=0;i<m;++i)
    {
        if(A[i][n-1]=='-')
        fill(A,i,n-1);
    }
    for(j=n-1;j>=0;--j)
    {
        if(A[m-1][j]=='-')
        fill(A,m-1,j);
    }
    for(i=m-1;i>=0;--i)
    {
        if(A[i][0]=='-')
        fill(A,i,0);
    }
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[i][j]=='-')
            A[i][j]='X';
        }
    }
    
}
