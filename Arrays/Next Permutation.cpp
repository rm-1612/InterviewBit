/*

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50

*/

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size(),j=n-1;
    for(j=n-1;j>0;--j)
    {
        if(A[j]>A[j-1])
        break;
    }
    if(j==0)
    {
        sort(A.begin(),A.end());
        return ;
    }
    int position=j-1;
    int smallest_greater=A[position+1],pos=position+1;
    for(i=position+2;i<n;++i)
    {
        if(A[i]>A[position] && A[i]<smallest_greater)
        {smallest_greater=A[i];pos=i;}
    }
    int temp=A[pos];
    A[pos]=A[position];
    A[position]=temp;
    sort(A.begin()+position+1,A.end());
    
}
