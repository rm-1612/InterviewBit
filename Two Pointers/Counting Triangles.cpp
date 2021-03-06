/*

You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/

int Solution::nTriang(vector<int> &A) {
    
    long long int i=0,n=A.size(),j,k,ctr=0;
    if(n<3)
    return 0;
    int M=1000000007;
    sort(A.begin(),A.end());
    for(i=0;i<n-2;++i)
    {
        k=i+2;
        for(j=i+1;j<n;++j)
        {
            while(k<n && A[i]+A[j]>A[k])
            ++k;
            ctr=(ctr%M+(k-j-1)%M)%M;
        }
    }
    return ctr;
    
}
