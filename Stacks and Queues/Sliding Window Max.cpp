/*

A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max of the array. 
 
 */
 
 vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    int i,n=A.size();
    if(B>n)
    {
        int max=INT_MIN;
        for(i=0;i<n;++i)
        {if(A[i]>max)
        max=A[i];}
        ans.push_back(max);
        return ans;
    }
    deque<int> q;
    for(i=0;i<B;++i)
    {
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        q.push_back(i);
    }
    for(;i<n;++i)
    {
        ans.push_back(A[q.front()]);
        while(!q.empty() && i-B>=q.front())
        q.pop_front();
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        q.push_back(i);
    }
    ans.push_back(A[q.front()]);
    return ans;
    
}
