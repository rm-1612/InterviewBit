/*

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

*/

tart(const vector<int> &A, int B)
{
    int low=0,n=A.size();
    int high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B && (mid==0 || A[mid-1]<B))
        return mid;
        else if(A[mid]>=B)
        high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int end(const vector<int> &A, int B)
{
    int low=0,n=A.size();
    int high=n-1,mid;   
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B && (mid==n-1 || A[mid+1]>B))
        return mid;
        else if(A[mid]<=B)
        low=mid+1;
        else high=mid-1;
    }
    return -1;
}
 
 
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> vec;
    int p=start(A,B);
    int q=end(A,B);
    vec.push_back(p);
    vec.push_back(q);
    return vec;
}
