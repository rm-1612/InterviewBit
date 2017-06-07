/*

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

bool diff(string str,string s)
{
    int i,n=str.length();
    int count=0;
    for(i=0;i<n;++i)
    {
        if(str[i]!=s[i])
        ++count;
        if(count>1)
        return false;
    }
    if(count==1)
    return true;
    return false;
}


int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(start==end)
    return 1;
    
    queue<pair<string,int> > q;
    q.push(make_pair(start,1));
    while(q.empty()==false)
    {
        pair<string,int> p=q.front();
        q.pop();
        string s=p.first;
        int step=p.second;
        
        int it;
        for(it=0;it<dictV.size();++it)
        {
            string str=dictV[it];
            if(diff(str,s))
            {
                q.push(make_pair(str,step+1));
                dictV.erase(dictV.begin()+it);
                if(str==end)
                return step+1;
            }
        }
        
    }
    
    return 0;
}
