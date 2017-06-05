/*

Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]

*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    int i=0,j=0;
    if(A.size()==0 || B.size()==0)
    return vec;
    while(i<A.size() && j<B.size())
    {
        if(A[i]<B[j])
        {
            ++i;
        }
        else if(A[i]==B[j])
        {
            vec.push_back(A[i]);
            ++i;
            ++j;
        }
        else 
        {
            ++j;
        }
    }
    
    return vec;
}
