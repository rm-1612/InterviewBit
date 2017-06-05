/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

*/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int flag=0,i,n=A.size();
    for(i=0;i<n;++i)
    {
        if(A[i]>0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        int max=INT_MIN;
        for(i=0;i<n;++i)
        {
            if(A[i]>max)
            max=A[i];
        }
        return max;
    }
    int sum=0,max_sum=0;
    for(i=0;i<n;++i)
    {
        sum=sum+A[i];
        if(sum<0)
        {
            sum=0;
        }
        if(sum>max_sum)
        {
            max_sum=sum;
        }
    }
    return max_sum;
    
}
