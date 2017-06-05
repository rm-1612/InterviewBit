/*

Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int max_length=0,length,p=0,q=0,n=A.size();
    map<char,int> mp;
    while(q<n)
    {
        if(mp.find(A[q])==mp.end())
        {
            mp[A[q]]=1;
            ++q;
        }
        else
        {
            while(A[p]!=A[q])
            {
                mp.erase(A[p]);
                ++p;
            }
            if(p!=q)
            ++p;
            mp.erase(A[q]);
        }
        length=q-p;
        max_length=max(max_length,length);
    }
    return max_length;
}
