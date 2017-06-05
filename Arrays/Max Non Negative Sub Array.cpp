/*

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index


*/

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    vector<int> result;
    long long int sum=0,max_sum=0,length=0,max_length,index;
    for(i=0;i<n;++i)
    {
        if(A[i]>=0)
        {sum+=A[i];++length;}
        else
        {
            sum=0;
            length=0;
        }
        if(sum>max_sum)
        {
            max_sum=sum;
            max_length=length;
            index=i-max_length+1;
        }
        else if(sum==max_sum)
        {
            if(length>max_length)
            {
                max_length=length;
                index=i-max_length+1;
            }
        }
        
    }
    for(i=index;i<index+max_length;++i)
    result.push_back(A[i]);
    return result;
    
}
