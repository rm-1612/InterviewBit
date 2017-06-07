/*

Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.

*/

void bfs(int num,int n,int m,vector<int> &vec)
{
    queue<int> q;
    q.push(num);
    while(q.empty()==false)
    {
        int nextnum=q.front();
        q.pop();
        if(nextnum>=n && nextnum<=m)
        vec.push_back(nextnum);
        if(num==0 || nextnum>m)
        continue;
        int lastdigit=nextnum%10;
        int nextnumA=nextnum*10+lastdigit-1;
        int nextnumB=nextnum*10+lastdigit+1;
        if(lastdigit==0)
        {
            q.push(nextnumB);
        }
        else if(lastdigit==9)
        {
            q.push(nextnumA);
        }
        else
        {
            q.push(nextnumA);
            q.push(nextnumB);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> vec;
    for(int i=0;i<=9;++i)
    {
        bfs(i,A,B,vec);
    }
    sort(vec.begin(),vec.end());
    return vec;
    
}
