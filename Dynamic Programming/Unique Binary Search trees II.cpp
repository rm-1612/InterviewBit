/*

Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
   */
   
  int Solution::numTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int dp[A+1];
    dp[0]=1;
    int i,j;
    for(i=1;i<=A;++i)
    {
        dp[i]=0;
        for(j=0;j<i;++j)
        {
            dp[i]=dp[i]+dp[j]*dp[i-j-1];
        }
    }
    return dp[A];
    
}
