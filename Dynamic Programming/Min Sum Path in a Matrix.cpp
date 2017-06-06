/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
     
     */
     
 int Solution::minPathSum(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size(),n=A[0].size();
    long long int dp[m][n];
    int i,j;
    dp[0][0]=A[0][0];
    for(i=1;i<m;++i)
    {
        dp[i][0]=dp[i-1][0]+A[i][0];
    }
    for(j=1;j<n;++j)
    {
        dp[0][j]=dp[0][j-1]+A[0][j];
    }
    for(i=1;i<m;++i)
    {
        for(j=1;j<n;++j)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+A[i][j];
        }
    }
    return dp[m-1][n-1];
    
}
