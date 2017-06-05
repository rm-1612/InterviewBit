/*

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size(),wl=0,wr=0,best_window=INT_MIN,best_l=0,zero=0;
    
    while(wr<n)
    {
        if(zero<=B)
        {
            if(A[wr]==0)
            ++zero;
            ++wr;
        }
        if(zero>B)
        {
            if(A[wl]==0)
            --zero;
            ++wl;
        }
        if(wr-wl>best_window)
        {
            best_window=wr-wl;
            best_l=wl;
        }
    }
    vector<int> result;
    for(i=best_l;i<best_l+best_window;++i)
    {
        result.push_back(i);
    }
    return result;
}
