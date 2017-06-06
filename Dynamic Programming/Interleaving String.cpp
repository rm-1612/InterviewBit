/*

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int Solution::isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size(),n=B.size(),i,j;
    bool dp[m+1][n+1];
    dp[0][0]=true;
    for(i=1;i<=m;++i)
    {
        if(A[i-1]==C[i-1])
        {
            dp[i][0]=dp[i-1][0];
        }
        else dp[i][0]=false;
    }
    for(j=1;j<=n;++j)
    {
        if(B[j-1]==C[j-1])
        {
            dp[0][j]=dp[0][j-1];
        }
        else dp[0][j]=false;
    }
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
            {
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            else if(A[i-1]==C[i+j-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(B[j-1]==C[i+j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else dp[i][j]=false;
        }
    }
    return dp[m][n];
    
}
