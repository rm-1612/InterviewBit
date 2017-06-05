/*

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/

long long int power(int x, int n, int d)
{
    if(x==0)
    return 0;
    if(n==0)
    return 1;
    long long int temp=power(x,n/2,d)%d;
    if(n%2==0)
    return (temp%d*temp%d)%d;
    else return (temp%d*temp%d*x%d)%d;
}
int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int t=power(x,n,d);
    if(t<0)
    return t+d;
    else return t;
    
}
