/*

N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:
 List of Books M number of students 

Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.

*/

int ispossible(vector<int> &A,int B,int mid)
{
    int required=1;
    int curr_sum=0;
    int i,n=A.size();
    for(i=0;i<n;++i)
    {
        if(A[i]>mid)
        return false;
        
        if(curr_sum+A[i]>mid)
        {
            ++required;
            curr_sum=A[i];
            if(required>B)
            return false;
        }
        else
        curr_sum+=A[i];
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()<B)
    return -1;
    int sum=0,n=A.size();
    for(int i=0;i<n;++i)
    {
        sum+=A[i];
    }
    int low=0,high=sum;
    int mid,result=INT_MAX;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(ispossible(A,B,mid))
        {
            result=min(result,mid);
            high=mid-1;
        }
        else low=mid+1;
    }
    return result;
}
