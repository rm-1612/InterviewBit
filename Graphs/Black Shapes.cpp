/*

Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

*/

bool issafe(int row,int column,vector<vector<bool> > &visited,vector<string> &A)
{
    int m=A.size();
    int n=A[0].length();
    if(row>=0 && row<m && column>=0 && column<n && !visited[row][column] && A[row][column]=='X')
    return true;
    return false;
}

int dfs(int row,int column,vector<vector<bool> > &visited,vector<string> &A)
{
    visited[row][column]=true;
    int rows[4]={-1,0,0,1};
    int cols[4]={0,-1,1,0};
    
    for(int k=0;k<4;++k)
    {
        if(issafe(row+rows[k],column+cols[k],visited,A))
        dfs(row+rows[k],column+cols[k],visited,A);
    }
}


int Solution::black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size();
    int n=A[0].length();
    int i,j;
    vector<vector<bool> > visited;
    for(i=0;i<m;++i)
    {
        vector<bool> vec;
        for(j=0;j<n;++j)
        {
            vec.push_back(false);
        }
        visited.push_back(vec);
    }
    int count=0;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[i][j]=='X' && !visited[i][j])
            {
                ++count;
                dfs(i,j,visited,A);
            }
        }
    }
    return count;
}
