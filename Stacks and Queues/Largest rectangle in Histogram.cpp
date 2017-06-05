/*

Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size();
    int max_area=INT_MIN;
    int area_with_top=0;
    i=0;
    stack<int> s;
    while(i<n)
    {
        if(s.empty() || A[s.top()]<=A[i])
        {
            s.push(i);
            ++i;
        }
        else
        {
            int tp=s.top();
            s.pop();
            if(s.empty())
            {
                area_with_top=i*A[tp];
            }
            else
            {
                area_with_top=A[tp]*(i-s.top()-1);
            }
            if(area_with_top>max_area)
            max_area=area_with_top;
        }
    }
    while(s.empty()==false)
    {
        int tp=s.top();
        s.pop();
        if(s.empty())
        area_with_top=i*A[tp];
        else area_with_top=A[tp]*(i-s.top()-1);
        if(area_with_top>max_area)
        max_area=area_with_top;
    }
    return max_area;
}
