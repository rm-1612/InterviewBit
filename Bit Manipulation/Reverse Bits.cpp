/*

Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

*/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int bits[32]={0},i=0;
    while(A>0)
    {
        bits[i]=A%2;
        A=A/2;
        ++i;
    }
    unsigned int B=0,j=0;
    for(int i=31;i>=0;--i)
    {
        B=B+bits[i]*pow(2,j);
        ++j;
    }
    return B;
}
