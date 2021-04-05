#include <bits/stdc++.h>
using namespace std;

static int wing=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


static void postorder(TreeNode*& T){
    stack<TreeNode*> s;
    TreeNode* p = T;
    TreeNode* r = NULL;
    while(p||s.empty()==false){
        if(p){
            s.push(p);
            p=p->left;
        }
        else{
            p = s.top();
            //GetTop(S,p);
            if(p->right && p->right!=r){
                p=p->right;
                s.push(p);
                p=p->left;
            }
            else{
                p = s.top();
                s.pop();
                cout<<p->val<<" ";
                r = p;
                p = NULL;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int num1, num2;
    int count = 0;
    TreeNode* root = new TreeNode(1);
    unordered_map<int,TreeNode*> it;
    it[1] = root;
    while(n > 0){
        n--;
        count++;
        cin>>num1>>num2;
        TreeNode *curleft = NULL;
        TreeNode *curright = NULL;
        if(num1 != 0){
            curleft = new TreeNode(num1);
            it[num1] = curleft;
        }
        if(num2 != 0){
            curright = new TreeNode(num2);
            it[num2] = curright;
        }
        it[count]->left = curleft;
        it[count]->right = curright;

    }

    postorder(root);
    cout<<endl;
    //cin>>n;
    return 0;
}