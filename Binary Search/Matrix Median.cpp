/*

Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.

*/

int Solution::findMedian(vector<vector<int> > &A) {
    
    int m=A.size();
    int n=A[0].size();
    int total=m*n;
    int low=0,high=INT_MAX,mid;
    while(high-low>1)
    {
        mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<m;++i)
        {
            int p=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
            count=count+p;
        }
        if(count>= total/2+1)
        high=mid;
        else low=mid;
    }
    return high;
}
