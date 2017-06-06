/*

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/

int hist(vector<int> v)
{
    int area_with_top=INT_MIN,max_area=INT_MIN;
    stack<int> s;
    int i=0;
    while(i<v.size())
    {
        if(s.empty() || v[i]>=v[s.top()])
        {
            s.push(i);
            ++i;
        }
        else 
        {
            int t=s.top();
            s.pop();
            if(s.empty())
            area_with_top=i*v[t];
            else area_with_top=v[t]*(i-s.top()-1);
        if(area_with_top>max_area)
        max_area=area_with_top;
        }
    }
    while(s.empty()==false)
    {
        int t=s.top();
            s.pop();
            if(s.empty())
            area_with_top=i*v[t];
            else area_with_top=v[t]*(i-s.top()-1);
         if(area_with_top>max_area)
        max_area=area_with_top;
    }
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,m=A.size(),n=A[0].size(),max_area=INT_MIN;
    for(i=0;i<m;++i)
    {
        vector<int> v;
        for(j=0;j<n;++j)
        {
            if(i==0)
            {
                v.push_back(A[i][j]);
            }
            else 
            {
                if(A[i][j]==1)
                {
                    A[i][j]=A[i-1][j]+A[i][j];
                }
                v.push_back(A[i][j]);
            }
        }
        int area=hist(v);
        if(area>max_area)
        max_area=area;
    }
    return max_area;
}
