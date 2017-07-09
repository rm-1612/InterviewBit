/*

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes 
- Your solution should run in linear time and not take memory more than O(height of T).
- Assume all values in BST are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

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
int Solution::t2Sum(TreeNode* A, int B) {
    
    
    int done1=0,done2=0;
    stack<TreeNode* > s1;
    stack<TreeNode* > s2;
    TreeNode* current1=A;
    TreeNode* current2=A;
    int val1,val2;
    while(1)
    {
        while(!done1)
        {
            if(current1!=NULL)
            {
            s1.push(current1);
            current1=current1->left;
            }
            else 
            {
                if(s1.empty())
                done1=1;
                else 
                {
                    current1=s1.top();
                    s1.pop();
                    val1=current1->val;
                    current1=current1->right;
                    done1=1;
                }
            }
        }
        while(!done2)
        {
            if(current2!=NULL)
            {
                s2.push(current2);
                current2=current2->right;
            }
            else
            {
                if(s2.empty())
                done2=1;
                else
                {
                    current2=s2.top();
                    s2.pop();
                    val2=current2->val;
                    current2=current2->left;
                    done2=1;
                }
            }
        }
        if(val1!=val2 && val1+val2==B)
        return true;
        else if(val1+val2<B)
        done1=false;
        else if(val1+val2>B)
        done2=false;
        if(val1>=val2)
        return false;
    }
    
    
    
}
