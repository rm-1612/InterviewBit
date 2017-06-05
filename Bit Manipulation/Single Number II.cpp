/*

Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

*/

int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int bits[32]={0};
    int i,n=A.size(),j;
    for(i=0;i<32;++i)
    {
        for(j=0;j<n;++j)
        {
            if(A[j]&(1<<i))
            ++bits[i];
        }
    }
    for(i=0;i<32;++i)
    bits[i]=bits[i]%3;
    int result=0;
    for(i=0;i<32;++i)
    {
        if(bits[i])
        result=result|(1<<i);
    }
    return result;
}
