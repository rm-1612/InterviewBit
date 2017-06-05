/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int ispal(string str)
{
    int i=0,j=str.length()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        return 0;
        ++i;
        --j;
    }
    return 1;
}
 
int Solution::isPalindrome(string str) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0,j=str.length()-1;
    while(i<j)
    {
        str[i]=tolower(str[i]);
        str[j]=tolower(str[j]);
        if(!isalpha(str[i]) && !isdigit(str[i]))
        {
            ++i;
            continue;
        }
        if(!isalpha(str[j]) && !isdigit(str[j]))
            {--j;
            continue;}
        if(str[i]!=str[j])
        return 0;
        else {
            ++i;
            --j;
        }
    }
    return 1;
}
