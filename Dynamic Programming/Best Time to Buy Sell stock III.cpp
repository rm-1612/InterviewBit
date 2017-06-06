/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation : 
  Day 1 : Buy 
  Day 2 : Sell
  Day 3 : Buy
  Day 4 : Sell
  
  */
  
  int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    if(n==0)
    return 0;
    int left[n],right[n];
    left[0]=0;
    right[n-1]=0;
    int min1=A[0];
    int max1=A[n-1];
    for(i=1;i<n;++i)
    {
        min1=min(A[i],min1);
        left[i]=max(left[i-1],A[i]-min1);
    }
    for(i=n-2;i>=0;--i)
    {
        max1=max(max1,A[i]);
        right[i]=max(right[i+1],max1-A[i]);
    }
    int ans=INT_MIN;
    for(i=0;i<n;++i)
    {
        ans=max(ans,left[i]+right[i]);
    }

return ans;    
}
