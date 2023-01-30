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
};