/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    vector<vector<int> > result;
    int n=A.size(),i,j,k;
    if(n<3)
    return result;
    for(i=0;i<n-2;++i)
    {
        if(i==0 || A[i]>A[i-1])
        {
            j=i+1;
        k=n-1;
        while(j<k)
        {
            if(A[i]+A[j]+A[k]==0)
            {
                vector<int> vec;
                vec.push_back(A[i]);
                vec.push_back(A[j]);
                vec.push_back(A[k]);
                result.push_back(vec);
                ++j;
                --k;
                while(j<k && A[j]==A[j-1])
                ++j;
                while(k>j && A[k]==A[k+1])
                --k;
            }
            else if(A[i]+A[j]+A[k]<0)
            ++j;
            else --k;
        }
        }
        
    }
    return result;
}
