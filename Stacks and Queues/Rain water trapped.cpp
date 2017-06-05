/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

*/


int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    int left[n],right[n];
    left[0]=A[0];
    right[n-1]=A[n-1];
    for(i=1;i<n;++i)
    {
        left[i]=max(left[i-1],A[i]);
    }
    for(i=n-2;i>=0;--i)
    {
        right[i]=max(right[i+1],A[i]);
    }
    long long int amt=0;
    for(i=1;i<n-1;++i)
    {
        amt=amt+min(left[i],right[i])-A[i];
    }
    return amt;   
}


