/*

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > vec;
    if(A==0)
    return vec;
    vector<int> v1;
    v1.push_back(1);
    vec.push_back(v1);
    int i;
    vector<int> v2;
    for(i=2;i<=A;++i)
    {
        v2.clear();
        v2.push_back(1);
        for(int j=1;j<v1.size();++j)
        {
            v2.push_back(v1[j]+v1[j-1]);
        }
        v2.push_back(1);
        vec.push_back(v2);
        v1=v2;
    }
    return vec;
    
}
