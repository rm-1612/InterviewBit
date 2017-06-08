/*

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is
 [ "cats and dog", "cat sand dog" ] 

Make sure the strings are sorted in your result.

*/

void solve(string A,int n,unordered_set<string> dictSet,string answer,vector<string> &result)
{
    for(int i=1;i<=n;++i)
    {
        string prefix=A.substr(0,i);
        if(dictSet.find(prefix)!=dictSet.end())
        {
            if(i==n)
            {
                answer=answer+prefix;
                result.push_back(answer);
                return ;
            }
            solve(A.substr(i,n-i),n-i,dictSet,answer+prefix+" ",result);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> result;
    unordered_set<string> dictSet(B.begin(), B.end());
    int n=A.length();
    solve(A,n,dictSet,"",result);
    return result;
}
