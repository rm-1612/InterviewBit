/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n=A.size();
    int dp[n],j;
    for(int j=0;j<A[n-1].size();++j)
    dp[j]=A[n-1][j];
    
    for(int i=n-2;i>=0;--i)
    {
        for(j=0;j<A[i].size();++j)
        {
            dp[j]=A[i][j]+min(dp[j],dp[j+1]);
        }
    }
    return dp[0];
    
}
