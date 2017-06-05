/*

Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1

*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int diff=INT_MAX,i=0,j=0,k=0,p=A.size(),q=B.size(),r=C.size(),maximum,minimum;
    
    while(i<p && j<q && k<r)
    {
        minimum=min(A[i],min(B[j],C[k]));
        maximum=max(A[i],max(B[j],C[k]));
        int res=maximum-minimum;
        if(res<diff)
        {
            diff=res;
        }
        if(A[i]==minimum)
        ++i;
        else if(B[j]==minimum)
        ++j;
        else ++k;
    }
    return diff;
    
}
