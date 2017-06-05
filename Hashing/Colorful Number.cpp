/*

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/

int Solution::colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string str=to_string(A);
    map<int,int> mp;
    for(int i=0;i<str.length();++i)
    {
        int x=str[i]-'0';
        if(mp.find(x)!=mp.end())
        return 0;
        mp[x]=1;
        for(int j=i+1;j<str.length();++j)
        {
            int p=str[j]-'0';
            x=x*p;
            if(mp.find(x)!=mp.end())
            return 0;
            mp[x]=1;
        }
    }
    return 1;
}
