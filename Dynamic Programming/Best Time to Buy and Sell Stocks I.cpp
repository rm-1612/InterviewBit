/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1

*/

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size(),min1=INT_MAX,result=INT_MIN;
    if(n<2)
    return 0;
    for(i=0;i<n;++i)
    {
        min1=min(min1,A[i]);
        result=max(A[i]-min1,result);
    }
    return result;
}
