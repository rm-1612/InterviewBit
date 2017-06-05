/*

Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3

*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int low=1,high=A,ans=1;
    if(A<=1)
    return A;
    while(low<=high)
    {
        long long int mid=low+(high-low)/2;
        if(mid*mid<=A)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
