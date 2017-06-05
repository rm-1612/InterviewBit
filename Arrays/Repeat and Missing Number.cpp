/*

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0,n=A.size(),x=0,y=0,xor1=0;
    vector<int> result;
    if(n==0 || n==1)
    return result;
    for(i=0;i<n;++i)
    xor1=xor1^A[i];
    for(i=1;i<=n;++i)
    xor1=xor1^i;
    int right_set_bit=xor1 & ~(xor1-1);
    for(i=0;i<n;++i)
    {
        if(right_set_bit & A[i])
        x=x^A[i];
        else y=y^A[i];
    }
    for(i=1;i<=n;++i)
    {
        if(right_set_bit & i)
        x=x^i;
        else y=y^i;
    }
    for(i=0;i<n;++i)
    {
        if(A[i]==x)
        break;
    }
    if(i<n)
    {
        
    result.push_back(x);
    result.push_back(y);
    }
    else 
    {
        
    result.push_back(y);
    result.push_back(x);
    }
    
}
