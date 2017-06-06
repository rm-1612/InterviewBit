/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 3]
Return : 2

*/

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size(),diff,ans=0;
    for(i=1;i<n;++i)
    {
        diff=A[i]-A[i-1];
        if(diff>0)
        ans=ans+diff;
    }
    return ans;
}
