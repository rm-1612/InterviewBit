/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem

*/

int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    int max_reach=0;
    int steps=1;
    if(n<=1)
    return 1;
    for(i=0;i<n;++i)
    {
        --steps;
        if(i+A[i]>max_reach)
        {
            max_reach=i+A[i];
            steps=A[i];
        }
        if(steps==0 && i<A.size()-1)
        return 0;
    }
    return 1;
}
