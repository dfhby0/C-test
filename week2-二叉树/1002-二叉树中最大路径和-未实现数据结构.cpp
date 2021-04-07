/*
二叉树中的最大路径和
Description

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。


Input
输入第一行为一个整数 n (1 <= n <= 100000), 表示二叉树的节点个数。

接下来共有 n 行, 每行有 3 个整数 l、r 和 val, 分别表示第 i (i为每一行的行号)个节点的左孩子和右孩子下标以及第 i 个节点的权值, 左/右孩子下标值为 0 表示当前节点没有左孩子/右孩子. 根节点的下标始终为 1.


Output
输出单独的一行, 即当前二叉树的最大路径和


Sample Input 1 

5
2 3 -10
0 0 9
4 5 20
0 0 15
0 0 7
Sample Output 1

42
Hint

样例中共 5 个节点,

输入的开始 5 表示共5个节点

接下来第 1 行, 2 3 -10 表示节点 1 的左孩子为 2 号节点, 右孩子为 3 号节点, 节点 1 的权值为 -10

第 2 行 0 0 9 表示节点 2 没有左孩子也没有右孩子, 节点 2 的权值为 9

第 3 行 4 5 20 表示节点 3 的左孩子为 4 号节点, 右孩子为 5 号节点, 节点 3 的权值为 20

第 4 行 0 0 15 表示节点 4 没有左孩子也没有右孩子, 节点 4 的权值为 15

第 5 行 0 0 7 表示节点 5 没有左孩子也没有右孩子, 节点 5 的权值为 7

从而可以得到下面的二叉树, 对于该二叉树, 最大路径和对应的路径为 4 - 3 - 5, 对应路径和的值为 15 + 20 + 7 = 42

![](2021-04-07-23-54-53.png)
*/

#include<iostream>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int data;
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x,int y) : data(x),val(y), left(NULL), right(NULL) {}
};
int maxSum = -1000000;
int maxGain(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);
    int priceNewpath = node->val + leftGain + rightGain;

    maxSum = max(maxSum, priceNewpath);

    return node->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) {
    maxGain(root);
    return maxSum;
}

int main(){

    int n;
    cin>>n;
    int num1, num2, dataval;
    int count = 0;
    TreeNode* root = new TreeNode(1,0);
    unordered_map<int,TreeNode*> it;
    it[1] = root;
    while(n > 0){
        n--;
        count++;
        cin>>num1>>num2>>dataval;
        TreeNode *curleft = NULL;
        TreeNode *curright = NULL;
        if(num1 != 0){
            curleft = new TreeNode(num1,0);
            it[num1] = curleft;
        }
        if(num2 != 0){
            curright = new TreeNode(num2,0);
            it[num2] = curright;
        }
        it[count]->left = curleft;
        it[count]->right = curright;
        it[count]->val = dataval;

    }

    int maxn;
    maxn = maxPathSum(root);
    cout<<maxn;
    return 0;
}