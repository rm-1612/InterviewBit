/*

Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*/

vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,top=0,bottom=2*A-1,left=0,right=2*A-1,dir=0,e=A;
    vector<vector<int> > vec;
    vector<int> v(2*A);
    for(i=0;i<=2*A-1;++i)
    vec.push_back(v);
    while(top<=bottom && left<right)
    {
            for(j=left;j<=right;++j)
            {
                vec[top][j]=e;
            }
            ++top;
            for(i=top;i<=bottom;++i)
            {
                vec[i][right]=e;
            }
            --right;
            for(j=right;j>=left;--j)
            {
                vec[bottom][j]=e;
            }
            --bottom;
            for(i=bottom;i>=top;--i)
            {
                vec[i][left]=e;
            }
            ++left;
        --e;
    }
    
    return vec;
}
