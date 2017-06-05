/*

Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

*/

int find_min(const vector<int> &A,int low,int high)
{
    if (high < low)
        return 0;
        
    if (high == low)
        return low;
 
    int mid = low + (high - low)/2; /*(low + high)/2;*/
 
    if (mid < high && A[mid+1] < A[mid])
       return (mid+1);
 
    if (mid > low && A[mid] < A[mid - 1])
       return mid;
 
    if (A[high] > A[mid])
       return find_min(A, low, mid-1);
 
    return find_min(A, mid+1, high);
}
 
 
 
int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int p=find_min(A,0,A.size()-1);
    return A[p];
   
}


