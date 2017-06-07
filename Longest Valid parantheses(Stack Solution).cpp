/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

int Solution::longestValidParentheses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> s;
    int i,n=A.length(),max_length=0;
                int t;
    for(i=0;i<n;++i)
    {
        if(A[i]=='(')
        s.push(i);
        else 
        {
            if(!s.empty() && A[s.top()]=='(')
            {
                s.pop();
                if(s.empty())
                {
                    t=i+1;
                }
                else t=i-s.top();
            }
            else
            {
                s.push(i);
            }
            if(t>max_length)
            max_length=t;
        }
    }
    return max_length;
    
}
