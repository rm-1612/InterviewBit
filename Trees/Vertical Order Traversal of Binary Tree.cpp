/*

Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> >sol;
    if(A==NULL)
    return sol;
    queue<pair<TreeNode*,int> > q;
    q.push(make_pair(A,0));
    map<int,vector<int> > mp;
    mp[0].push_back(A->val);
    while(q.empty()==false)
    {
        pair<TreeNode*,int>  p=q.front();
        q.pop();
        TreeNode* current=p.first;
        int dist=p.second;
        if(current->left)
        {
            q.push(make_pair(current->left,dist-1));
            mp[dist-1].push_back(current->left->val);
        }
        if(current->right)
        {
            q.push(make_pair(current->right,dist+1));
            mp[dist+1].push_back(current->right->val);
        }
        
    }
    map<int,vector<int> > :: iterator it;
    for(it=mp.begin();it!=mp.end();++it)
    {
        sol.push_back(it->second);
    }
    return sol;
    
}
