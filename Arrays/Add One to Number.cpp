/*

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int s, carry=1;
    s = A.size();
    vector <int> result;
    for(int i=s-1;i>=0;i--)
    {
        int sum;
        sum = A[i] + carry;
        carry = sum/10;
        result.push_back(sum%10);
    }
    result.push_back(carry);
    s = result.size();
    int i = s-1;
    vector<int> ans;
    while(i>=0 && result[i]==0)
    {
        i--;
    }
    while(i>=0)
    {
        ans.push_back(result[i]);
        i--;
    }
    return ans;
}
