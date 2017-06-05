/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    RandomListNode* original=A;
    RandomListNode* clone=NULL;
    map<RandomListNode*,RandomListNode*> mp;
    while(original!=NULL)
    {
        clone = new RandomListNode(original->label);
        mp[original]=clone;
        original=original->next;
    }
    original=A;
    while(original!=NULL)
    {
        clone=mp[original];
        clone->next=mp[original->next];
        clone->random=mp[original->random];
        original=original->next;
    }
    return mp[A];
    
}
