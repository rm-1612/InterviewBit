/*

Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.

*/

rst(const vector<int> &A, int B)
{
    int low=0,high=A.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(A[mid]==B && (mid==0 || A[mid-1]<B))
        {
            return mid;
        }
        else if(A[mid]>=B)
        high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int last(const vector<int> &A, int B)
{
    int low=0,high=A.size()-1,n=A.size();
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(A[mid]==B && (mid==n-1 || A[mid+1]>B))
        return mid;
        else if(A[mid]<=B)
        low=mid+1;
        else high=mid-1;
    }
    return -1;
}
 
int Solution::findCount(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int x=first(A,B);
    int y=last(A,B);
    if(x==-1)
    return 0;
    return y-x+1;
    
}
