/*

Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/


int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    int i,n=A.size();
    for(i=0;i<n;++i)
    {
        if(i==n-1 && A[i]==0)
        return 1;
        if(A[i]==n-i-1 && A[i]!=A[i+1])
        return 1;
    }
    return -1;
    
}
