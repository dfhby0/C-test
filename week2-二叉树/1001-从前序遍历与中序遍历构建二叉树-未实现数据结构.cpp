/*
从前序与中序遍历序列构建二叉树
Description

从前序与中序遍历序列构建二叉树，返回其后序序列


Input
输入包含三行

第一行为一个正整数 n （1<=n<=100000）, 表示二叉树的节点个数

第二行为 n 个正整数用空格隔开, 表示二叉树的先序遍历结果

第三行为 n 个正整数用空格隔开, 表示二叉树的中序遍历结果


Output
输出单独一行, 表示二叉树后序遍历的结果


Sample Input 1 

8
1 3 2 5 6 7 4 8
3 1 5 7 6 2 8 4
Sample Output 1

3 7 6 5 8 4 2 1
*/
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



