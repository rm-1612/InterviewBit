/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
  */
  
  int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> s;
    for(int i=0;i<A.size();++i)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/")
        {
            int n1=s.top();
            s.pop();
            int n2=s.top();
            s.pop();
            if(A[i]=="+")
            s.push(n1+n2);
            else if(A[i]=="-")
            {
                s.push(n2-n1);
            }
            else if(A[i]=="/")
            {
                s.push(n2/n1);
            }
            else s.push(n1*n2);
        }
        else 
        {
            s.push(stoi(A[i]));
        }
    }
    return s.top();
    
}
