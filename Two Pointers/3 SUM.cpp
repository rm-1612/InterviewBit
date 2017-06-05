/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/
int Solution::threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(),A.end());
    int i,j,k,n=A.size(),diff,min_value=INT_MAX,ans;
    if(n<3)
    return 0;
    for(i=0;i<n-2;++i)
    {
        j=i+1;
        k=n-1;
        while(j<k)
        {
            int diff=fabs(A[i]+A[j]+A[k]-B);
            if(diff==0)
            return B;
            if(diff<min_value)
            {
                ans=A[i]+A[j]+A[k];
                min_value=diff;
            }
            if(A[i]+A[j]+A[k]<=B)
            ++j;
            else --k;
        }
    }
    return ans;
    
    
}
