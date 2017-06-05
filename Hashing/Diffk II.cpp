/*

Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

*/

int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    map<int,int> mp;
    for(int i=0;i<A.size();++i)
    {
        if(mp.find(B+A[i])!=mp.end() || mp.find(A[i]-B)!=mp.end())
        {
            return 1;
        }
        else mp[A[i]]=i;
    }
    return 0;
}
