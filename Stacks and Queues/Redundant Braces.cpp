/*

Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

*/

int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> s;
    int i,n=A.length();
    if(n==0 )
    return 0;
    while(i<n)
    {
        if(A[i]=='(' || A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/')
        s.push(A[i]);
        else if(A[i]==')')
        {
            if(s.top()=='(')
            return 1;
            else 
            {
                while(s.empty()==false && s.top()!='(')
                s.pop();
                s.pop();
            }
        }
        ++i;
    }
    return 0;
}
