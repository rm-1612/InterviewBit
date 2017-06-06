/*

Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

Example :

Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

*/

int Solution::lis(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    int dp[n];
    for(i=0;i<n;++i)
        dp[i]=1;
    int j;
    for(i=1;i<n;++i)
    {
        for(j=0;j<i;++j)
        {
            if(A[j]<A[i] && dp[j]+1>dp[i])
            dp[i]=dp[j]+1;
        }
    }
    int max1=INT_MIN;
    for(i=0;i<n;++i)
    {

        if(dp[i]>max1)
            max1=dp[i];
    }
    return max1;

}
