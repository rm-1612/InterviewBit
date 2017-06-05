/*

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

*/

int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=1;
    int i,n=A.size();
    int index=0;
    for(i=1;i<n;++i)
    {
            if(A[i]==A[index])
            {
                ++count;
            }
            else --count;
            if(count==0)
            {
                index=i;
                count=1;
            }
    }
    count=0;
    for(i=0;i<n;++i)
    {
        if(A[i]==A[index])
        ++count;
    }
    if(count>n/2)
    return A[index];
}
