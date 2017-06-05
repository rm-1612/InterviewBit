/*

Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110

*/

string Solution::findDigitsInBinary(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==0)
    return "0";
    string str="";
    int num=A;
    while(num>0)
    {
        if(num%2==0)
        str=str+'0';
        else str=str+'1';
        num/=2;
    }
    reverse(str.begin(),str.end());
    return str;
    
}

