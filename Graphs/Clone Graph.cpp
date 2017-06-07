/*

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL)
    return node;
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode* new_node=new UndirectedGraphNode(node->label);
    mp[node]=new_node;
    while(q.empty()==false)
    {
        UndirectedGraphNode* temp=q.front();
        q.pop();
        vector<UndirectedGraphNode*> :: iterator it;
        for(it=temp->neighbors.begin();it!=temp->neighbors.end();++it)
        {
            UndirectedGraphNode* v=*it;
            if(mp[v]==NULL)
            {
                UndirectedGraphNode* n1=new UndirectedGraphNode(v->label);
                mp[v]=n1;
                q.push(v);
            }
            mp[temp]->neighbors.push_back(mp[v]);
        }
    }
    return mp[node];


}
