/*

Given an array of non negative integers A, and a range (B, C), 
find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C

Continuous subsequence is defined as all the numbers A[i], A[i + 1], .... A[j]
where 0 <= i <= j < size(A)

Example :

A : [10, 5, 1, 0, 2]
(B, C) : (6, 8)
ans = 3 
as [5, 1], [5, 1, 0], [5, 1, 0, 2] are the only 3 continuous subsequence with their sum in the range [6, 8]

 NOTE : The answer is guranteed to fit in a 32 bit signed integer. 
 
 */
 
 int Solution::numRange(vector<int> &A, int B, int C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int curr_sum=0,i=0,n=A.size(),j=0,count=0;
    while(i<n && j<n)
    {
        curr_sum+=A[j];
        if(curr_sum>=B && curr_sum<=C)
        {
            ++count;++j;
        }
        else if(curr_sum<B)
        {
            ++j;
        }
        else if(curr_sum>C)
        {
            ++i;
            j=i;
            curr_sum=0;
        }
        if(j==A.size())
        {
            curr_sum=0;
            ++i;
            j=i;
        }
    }
    return count;
}
