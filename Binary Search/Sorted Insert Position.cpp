/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

int bin_search(vector<int> &A, int B)
{
    int low=0,high=A.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(A[mid]==B)
        return mid;
        else if(A[mid]>B)
        high=mid-1;
        else low=mid+1;
    }
    return -1;
}
 
int sorted_position(vector<int> &A, int B)
{
    int low=0,n=A.size();
    int high=n-1,mid,ans;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B && (mid==0 || A[mid-1]<B))
        return mid;
        else if(A[mid]>=B)
        {
            high=mid-1;
        }
        else 
        {
            low=mid+1;
        }
    }
    return low;
}
 
 
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int x=bin_search(A,B);
    if(x!=-1)
    return x;
    int p=sorted_position(A,B);
    return p;
    
}
