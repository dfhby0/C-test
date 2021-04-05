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
int maxSum = INT_MIN;
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