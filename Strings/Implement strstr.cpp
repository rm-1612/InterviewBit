/*

Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

*/

int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,n=haystack.length(),m=needle.length(),k;
    for(i=0;i<n;++i)
    {
        if(haystack[i]==needle[0])
        {
            j=0,k=i;
            while(haystack[k]==needle[j] && j<m && k<n)
            {
                ++k;
                ++j;
            }
            if(j==m)
            return i;
        }
        
    }
    
    return -1;
}
