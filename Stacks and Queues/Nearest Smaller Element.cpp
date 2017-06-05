/*

Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10]
Return : [-1, 4, -1, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    vector<int> ans;
    int n=A.size();
    if(n==0)
    return ans;
    ans.push_back(-1);
    stack<int> s;
    s.push(A[0]);
    for(int i=1;i<n;++i)
    {
        if(A[i]>s.top())
        {
            ans.push_back(s.top());
            s.push(A[i]);
        }
        else
        {
            while(s.empty()==false && s.top()>=A[i])
            {
                s.pop();
            }
            if(s.empty())
            ans.push_back(-1);
            else 
            {
                ans.push_back(s.top());
            }
            s.push(A[i]);
        }
    }
    return ans;
}
