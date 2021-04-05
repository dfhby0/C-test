#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int,int> pos;

TreeNode* dfs(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir)
{
  if (pl > pr) return NULL;
  int k = pos[pre[pl]] - il;
  TreeNode* root = new TreeNode(pre[pl]);
  root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
  root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int n = preorder.size();
  for (int i = 0; i < n; i ++ )
    pos[inorder[i]] = i;
  return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
}

void postrav(struct TreeNode *bt)
{
    if(bt!=NULL) {
    postrav(bt->left);
    postrav(bt->right);
    printf("%d ",bt->val);
    }
}

int main()
{
    int n;
    int a;
    TreeNode* bt;
    vector<int>pre;
    vector<int>in;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        pre.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        in.push_back(a);
    }
    postrav(buildTree(pre,in));
    return 0;
}



