/*

Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.

*/

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
    return "";
    if(A.size()==1)
    return A[0];
    string ans=A[0];
    int n=A.size(),j,k;
    for(int i=1;i<n;++i)
    {
        string s1=ans;
        string s2=A[i];
        ans="";
        for(j=0,k=0;j<s1.length() && j<A[i].length();++j,++k)
        {
            if(s1[j]==A[i][k])
            ans=ans+s1[j];
            else break;
        }
    }
    return ans;
    
    
}
