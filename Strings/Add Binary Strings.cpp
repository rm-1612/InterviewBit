/*


Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

*/

string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.length(),m=B.length(),i,j,carry=0;
    string ans="";
    i=n-1;j=m-1;
    while(i>=0 && j>=0)
    {
        int x=A[i]-'0';
        int y=B[j]-'0';
        int sum=(x+y+carry);
        int r=sum%2;
        char ch=r+'0';
        ans=ans+ch;
        carry=sum/2;
        --i;
        --j;
    }
    while(i>=0)
    {
        int x=A[i]-'0';
        int sum=(x+carry);
        int r=sum%2;
        char ch=r+'0';
        ans=ans+ch;
        carry=sum/2;
        --i;
    }
    while(j>=0)
    {
        int y=B[j]-'0';
        int sum=(y+carry);
        int r=sum%2;
        char ch=r+'0';
        ans=ans+ch;
        carry=sum/2;
        --j;
    }
    if(carry>0)
    {
        char ch=carry+'0';
        ans=ans+ch;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

