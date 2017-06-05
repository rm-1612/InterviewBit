/*

Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/

int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int flag=0;
    if(A<0)
    {
        flag=1;
        A=A*(-1);
    }
    int num=A,n=0;
    while(num>0)
    {
        int maxVal = (INT_MAX-(num%10))/10;
        if(n>maxVal){
            return 0;
        }
        n=n*10+num%10;
        num=num/10;
    }
    if(flag==1)
    n=n*(-1);
    return n;
    
}
