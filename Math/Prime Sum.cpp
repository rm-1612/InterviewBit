/*

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

*/

vector<int> Solution::primesum(int A) {
    
    vector<bool> prime;
    vector<int> solution;
    int i,j;
    for(i=0;i<=A;++i)
    prime.push_back(true);
    prime[1]=false;
    for(i=2;i<=sqrt(A);++i)
    {
        if(prime[i])
        {
            for(j=2*i;j<=A;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(i=2;i<A;++i)
    {
        if(prime[i] && prime[A-i])
        {
            solution.push_back(i);
            solution.push_back(A-i);
            return solution;
        }
    }
    
    
    
}
