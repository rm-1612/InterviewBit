/*

Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.

*/

int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,n=A.length(),m=B.length();
    int dp[n+1][m+1];
    for(i=0;i<=n;++i)
    {
        dp[i][0]=i;
    }
    for(j=0;j<=m;++j)
    {
        dp[0][j]=j;
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
        }
    }
    return dp[n][m];
}
