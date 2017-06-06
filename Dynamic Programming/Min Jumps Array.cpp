/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.

*/

int possible(vector<int> &A)
{
    int i,n=A.size(),max_reach=0,steps=1;
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

int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int max_reach=A[0];
    int steps=A[0];
    int i,n=A.size();
    int jumps=1;
    if(A.size()<=1)
    return 0;
    if(possible(A)==0)
    return -1;
    for(i=1;i<A.size();++i)
    {
        if(i==A.size()-1)
        return jumps;
        if(i+A[i]>max_reach)
        {
            max_reach=i+A[i];
        }
        steps--;
        if(steps==0)
        {
            jumps++;
            steps=max_reach-i;
        }
    }
    return jumps;
}
