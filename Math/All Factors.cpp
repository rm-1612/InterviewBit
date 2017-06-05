/*

Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

*/

vector<int> Solution::allFactors(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    for(int i=1;i<=sqrt(A);++i)
    {
        if(A%i==0)
        {vec.push_back(i);
        if(A/i!=i)
        vec.push_back(A/i);}
    }
    sort(vec.begin(),vec.end());
    return vec;
}
