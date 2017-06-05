

/*

You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,n=A.size();
    int count1=0,count2=0,index1=-1,index2=-1;
    for(i=0;i<n;++i)
    {
        if(A[i]==A[index1])
        {++count1;}
        else if(A[i]==A[index2])
        {++count2;}
        else
        if(count1==0)
        {
            index1=i;
            ++count1;
        }
        else if(count2==0)
        {
            index2=i;
            ++count2;
        }
        else
        {
            --count1;
            --count2;
        }
    }
    count1=0,count2=0;
    for(i=0;i<n;++i)
    {
        if(A[i]==A[index1])
        ++count1;
        else if(A[i]==A[index2])
        ++count2;
    }
    if(count1>n/3)
    return A[index1];
    else if(count2>n/3)
    return A[index2];
    else return -1;
    
}
