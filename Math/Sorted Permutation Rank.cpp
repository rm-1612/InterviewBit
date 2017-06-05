/*

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

*/

int count_smaller(string A,int index)
{
    int ctr=0;
    for(int j=index+1;j<A.length();++j)
    {
        if(A[j]<A[index])
        ++ctr;
    }
    return ctr;
}

int Solution::findRank(string A) {
    int M=1000003;
    int fact[100005],i;
    fact[0]=1;
    fact[1]=1;
    for(i=2;i<=100000;++i)
    {
        fact[i]=(fact[i-1]%M*i%M)%M;
    }
    int n=A.length();
    int rank=0;
    for(i=0;i<n;++i)
    {
        int p=count_smaller(A,i);
        rank=rank%M+(fact[n-i-1]%M*p%M)%M;
    }
    rank=rank+1;
    return rank;
}
