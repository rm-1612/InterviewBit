/*

Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6

*/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int i,n=A.size(),j;
    if(n==0)
    return 0;
    int left[n],right[n];
    for(i=0;i<n;++i)
    {left[i]=1;
    right[i]=1;}
    for(i=1;i<n;++i)
    {
        for(j=0;j<i;++j)
        {
            if(A[j]<A[i] && left[j]+1>left[i])
            left[i]=left[j]+1;
        }
    }
    for(i=n-2;i>=0;--i)
    {
        for(j=n-1;j>i;--j)
        {
            if(A[j]<A[i] && right[j]+1>right[i])
            right[i]=right[j]+1;
        }
    }
    int max1=INT_MIN;
    for(i=0;i<n;++i)
    {
        left[i]=left[i]+right[i]-1;
        if(left[i]>max1)
        max1=left[i];
    }
    return max1;
    
}
