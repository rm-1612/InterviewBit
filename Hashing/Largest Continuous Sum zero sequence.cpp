/*

Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.
 
 */
 
 vector<int> Solution::lszero(vector<int> &A) {
    
    map<int,int> mp;
    int i,n=A.size();
    int sum=0;
    int end_index=-1,max_length=0;
    for(i=0;i<n;++i)
    {
        sum=sum+A[i];
        if(sum==0)
        {
            if(max_length<i+1)
            {
                max_length=i+1;
                end_index=i;
            }
        }
        else
        {
            if(mp.find(sum)!=mp.end())
            {
                if(max_length<i-mp[sum])
                {
                    max_length=i-mp[sum];
                    end_index=i;
                }
            }
            else mp[sum]=i;
        }
    }
    vector<int> result;
    for(i=end_index-max_length+1;i<=end_index;++i)
    {
        result.push_back(A[i]);
    }
    return result;
    
}
