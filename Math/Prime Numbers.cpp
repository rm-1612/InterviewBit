/*

Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.

*/

vector<int> Solution::sieve(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int prime[A+1];
    memset(prime,1,sizeof(prime));
    prime[1]=0;
    for(int i=2;i<=sqrt(A);++i)
    {
        if(prime[i])
        for(int j=2*i;j<=A;j+=i)
        prime[j]=0;
    }
    vector<int> vec;
    for(int i=2;i<=A;++i)
    {
        if(prime[i])
        vec.push_back(i);
    }
    return vec;
}
