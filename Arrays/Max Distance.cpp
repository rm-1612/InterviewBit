/*

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size();
    if(n==0 || n==1)
    return 0;
    int l[n],r[n];
    l[0]=A[0];
    r[n-1]=A[n-1];
    for(i=1;i<n;++i)
    {
        l[i]=min(l[i-1],A[i]);
    }
    for(i=n-2;i>=0;--i)
    {
        r[i]=max(r[i+1],A[i]);
    }
    int max_diff=INT_MIN,j=0;
    i=0;
    while(i<n && j<n)
    {
        if(l[i]<=r[j])
        {
            max_diff=max(max_diff,j-i);
            ++j;
        }
        else
        {
            ++i;
        }
    }
    return max_diff;
    
}
