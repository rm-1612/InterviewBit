/*

Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Example:

Grid:
	1 2 3 4
	2 3 4 5
so we will choose
3 and 5 so sum will be 3 + 5 = 8


Note that you can choose more than 2 numbers

*/

int Solution::adjacent(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> B;
    for(int i=0;i<A[0].size();++i)
    {
        B.push_back(max(A[0][i],A[1][i]));
    }
    int i,n=B.size(),incl,excl;
    incl=B[0];
    excl=0;
    for(i=1;i<n;++i)
    {
        //old_excl=excl;
        int new_excl=max(excl,incl);
        incl=excl+B[i];
        excl=new_excl;
    }
    return max(incl,excl);
}
