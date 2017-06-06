/*

Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

 Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none ) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Example :
 S = "rabbbit" T = "rabbit" 

Return 3. And the formations as follows:

S1= "ra_bbit" 
S2= "rab_bit" 
S3="rabb_it"
"_" marks the removed character.

*/

int Solution::numDistinct(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m=T.length(),n=S.length(),i,j;
    int dp[m+1][n+1];
    if(m>n)
    return 0;
    for(i=0;i<=m;++i)
    {
        dp[i][0]=0;
    }
    for(j=0;j<=n;++j)
    dp[0][j]=1;
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(T[i-1]!=S[j-1])
            dp[i][j]=dp[i][j-1];
            else dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
        }
    }
    return dp[m][n];
}
