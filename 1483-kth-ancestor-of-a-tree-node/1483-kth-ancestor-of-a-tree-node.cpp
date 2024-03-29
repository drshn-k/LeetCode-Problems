class TreeAncestor {
public:
    vector<vector<int>> jumps;
vector<int> lvls;
void traverse(vector<int>& path, vector<vector<int>> &tree, int i, int l) {
    lvls[i] = l;
    for (int p = 1; p <= path.size(); p <<= 1)
        jumps[i].push_back(path[path.size() - p]);
    path.push_back(i);
    for (auto ch : tree[i])
        traverse(path, tree, ch, l + 1);
    path.pop_back();
}
TreeAncestor(int n, vector<int>& parent) {
    vector<vector<int>> tree(n);
    jumps = vector<vector<int>>(n);
    lvls = vector<int>(n);
    for (auto i = 1; i < n; ++i)
        tree[parent[i]].push_back(i);
    traverse(vector<int>() = {}, tree, 0, 0);
}
int getKthAncestor(int node, int k) {
    if (k == 0)
        return node;
    if (lvls[node] < k)
        return -1;
    auto p = 1, pos = 0;
    while ((p << 1) <= k) {
        p <<= 1;
        ++pos;
    }
    return getKthAncestor(jumps[node][pos], k - p);
}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */