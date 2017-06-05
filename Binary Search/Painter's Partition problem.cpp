/*

You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50

*/

long long int ispossible(vector<int> &C,int A,int mid)

{
    long long int required=1;
    long long int curr_sum=0;
    for(int i=0;i<C.size();++i)
    {
        if(C[i]>mid)
        return false;
        if(curr_sum+C[i]>mid)
        {
            ++required;
            curr_sum=C[i];
            if(required>A)
            return false;
        }
        else curr_sum+=C[i];
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=C.size();
    long long int start=0,result=INT_MAX;
    long long int sum=0;
    for(i=0;i<n;++i)
    sum+=C[i];
    long long int end=sum,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(ispossible(C,A,mid))
        {
            result=min(result,mid);
            end=mid-1;
        }
        else start=mid+1;
    }
    return (result*B)%10000003;
    
    
}
