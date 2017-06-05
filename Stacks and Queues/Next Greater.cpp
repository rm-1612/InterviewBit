/*

Given an array, find the next greater element G[i] for every element A[i] in the array. The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
Elements for which no greater element exist, consider next greater element as -1.

Example:

Input : A : [4, 5, 2, 10]
Output : [5, 10, 10, -1]

Example 2:

Input : A : [3, 2, 1]
Output : [-1, -1, -1]

*/

vector<int> Solution::nextGreater(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int > result;
    int i,n=A.size();
    if(n==0)
    return result;
    if(n==1)
    {
        result.push_back(-1);
        return result;
    }
    result.push_back(-1);
    stack<int> s;
    s.push(A[n-1]);
    for(i=n-2;i>=0;--i)
    {
        if(s.empty() || A[i]<s.top())
        {
            result.push_back(s.top());
            s.push(A[i]);
        }
        else
        {
            while(s.empty()==false  && A[i]>=s.top() )
            {
                s.pop();
            }
            if(s.empty())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(s.top());
            }
            s.push(A[i]);
        }
    }
    reverse(result.begin(),result.end());
    return result;
    
}
