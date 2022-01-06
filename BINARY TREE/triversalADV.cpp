#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct node
{
    int val;
    node *left;
    node *right;
    node(int data)
    {
        val = data;
        left = right = NULL;
    }
};


// =====================================================================//
 
vector<vector<int>> verticalTraversal(node* root) { // 1 left to pass
	map<int, vector<int> > m;  
	queue<pair<int, node*> > q;
	q.push(make_pair(0, root));  
	while(!q.empty()) {
		set<pair<int, int> > tmp;  
		int len=q.size();
		for(int i=0;i<len;++i) {
			auto p=q.front();q.pop();
			tmp.insert(make_pair(p.first, p.second->val));
			if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
			if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
		}
		for(auto p : tmp) m[p.first].push_back(p.second);
	}

	vector<vector<int> > res;
	for(auto kv : m) res.push_back(kv.second);
	return res;
}

void getVerticalOrder(node* root, int vertical, map<int, vector<int>> &m) // dont pass all test case 
{
	if (root == NULL) return;

	m[vertical].push_back(root->val);
	getVerticalOrder(root->left, vertical-1, m);
	getVerticalOrder(root->right, vertical+1, m);
}

void printVerticalOrder(node* root)
{
	// <vertical, on vertical>
	map < int,vector<int> > m;
	int vertical = 0;
	getVerticalOrder(root, vertical,m);
	for(auto i: m){
        cout<<i.first<<" -> ";
        for(auto j: i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> verticalTraversalStriverBFS(node* root) { // pass all testcase 
    // map< vertical < map<level,multi nodes> >
    map<int, map<int, multiset<int>>> nodes;
    // queue< pair<node*,pair<vertical,level>> >
    queue<pair<node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node -> val);
        if (node -> left) {
           todo.push({node -> left, {x - 1, y + 1}});
        }
        if (node -> right) {
           todo.push({node -> right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes) { // for every vertical
        vector<int> col;
        for (auto q : p.second) {  // for every level on vertical
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

vector<vector<int>> verticalTraversalDFS(node* root) { 
    map<int, map<int, multiset<int>>> nodes;
    traverse(root, 0, 0, nodes);
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
            }
        ans.push_back(col);
    }
    return ans;
}

void traverse(node* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
    if (root) {
       nodes[x][y].insert(root -> val);
       traverse(root -> left, x - 1, y + 1, nodes);
       traverse(root -> right, x + 1, y + 1, nodes);
    }
}


//===================================================================//
vector<vector<int>> level_wise(node *root);
void PrintV(vector<int> &v);
void PrintVV(vector<vector<int>> &v);
int main()
{
/*
         1
       /  \
     2     3
    /  \    \  
   4    5    6
      /     / \
     7     8   9
    /    /      \
  10    11       12

*/
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    root->left->right->left->left = new node(10);
    root->right->right->left->left = new node(11); 
    root->right->right->right->right = new node(12);
    vector<int> v;
    vector<vector<int>> vv;
    vv = verticalTraversal(root);
    PrintVV(vv); 
    cout<<"=============================="<<endl; 
    
// 4 10 
// 2 7 
// 1 5 11 
// 3 8 
// 6 
// 9 
// 12 


    return 0;
}

void PrintV(vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void PrintVV(vector<vector<int>> &v)
{
    for(auto i: v)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}
vector<vector<int>> level_wise(node *root)
{   
    queue<node*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            node* fr = q.front();
            q.pop();
            level.push_back(fr->val);
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        ans.push_back(level);
    }
    return ans;
}