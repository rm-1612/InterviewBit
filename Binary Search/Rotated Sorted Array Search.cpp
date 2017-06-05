/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

*/

int find_min(const vector<int> &A,int low,int high)
{
    if(high<low)
    return 0;
    if(high==low)
    return low;
    int mid=low+(high-low)/2;
    if(mid<high && A[mid]>A[mid+1])
    return mid+1;
    if(mid>low && A[mid]<A[mid-1])
    return mid;
    if(A[mid]<A[high])
    return find_min(A,low,mid-1);
    return find_min(A,mid+1,high);
}
 
int bin_search(const vector<int> &A,int low,int high,int B)
{
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]==B)
        return mid;
        else if(A[mid]>B)
        high=mid-1;
        else low=mid+1;
    }
    return -1;
}
 
int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int p=find_min(A,0,A.size()-1);
    int x;
    int i,n=A.size();
    if(B>=A[p] && B<=A[n-1])
    {
        x=bin_search(A,p,n-1,B);
    }
    else x=bin_search(A,0,p-1,B);
    return x;
}
 
