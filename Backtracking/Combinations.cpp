/*

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.

*/

void find_combinations(vector<int> &d,vector<vector<int> > &result,int i,int n,int k)
{
    if(k==0)
    {result.push_back(d);return;}
    if(i==n)
    return ;
    for(int j=i;j<n;++j)
    {
        d.push_back(j+1);
        find_combinations(d,result,j+1,n,k-1);
        d.pop_back();
    }
}


vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> d;
    vector<vector<int> > result;
    find_combinations(d,result,0,n,k);
    return result;
    
}
