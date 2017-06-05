/*

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1

*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,m=A.size(),n=A[0].size(),j;
    bool row[m];
    bool col[n];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[i][j]==0)
            {row[i]=true;col[j]=true;}
        }
    }
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(row[i] || col[j])
            A[i][j]=0;
        }
    }
    
}
