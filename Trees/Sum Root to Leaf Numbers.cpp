/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

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
 
 int evaluate(vector<int> &v)
 {
     int n=v.size();
     int i;
     int ten=1;
     int sum=0;
     for(i=n-1;i>=0;--i)
     {
         int temp=ten*v[i];
         temp%=1003;
         ten=ten*10;
         ten%=1003;
         sum=sum+temp;
         sum%=1003;
     }
     return sum;
 }
 
void find_sum(TreeNode* A,vector<int> &row,long long int &sum)
{
    if(A==NULL)
    return ;
    if(A->left==NULL && A->right==NULL)
    {
        row.push_back(A->val);
        sum+=evaluate(row);
        sum%=1003;
        row.pop_back();
        return ;
    }
    row.push_back(A->val);
    find_sum(A->left,row,sum);
    find_sum(A->right,row,sum);
    row.pop_back();
    
}
int Solution::sumNumbers(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int sum=0;
    vector<int> row;
    find_sum(A,row,sum);
    return sum;
}
