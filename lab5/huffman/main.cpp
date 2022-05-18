#include "util.hpp"

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    char symbol;       // 编码的字母
    double freq;       // 对应的频率
    TreeNode *left;    // 左孩子
    TreeNode *right;   // 右孩子
    // 构造函数
    TreeNode()
        : symbol('\0'), freq(0), left(NULL), right(NULL) {}
    // 用symbol和freq构造
    TreeNode(char symbol_, double freq_)
        : symbol(symbol_), freq(freq_), left(NULL), right(NULL) {}
    // 比较哪个节点的频率更高
    bool operator()(const TreeNode* lhs, const TreeNode* rhs) {
        return lhs->freq > rhs->freq;
    }
};

TreeNode* Huffman(vector<TreeNode*>& C) {
    int n = C.size();
    // 创建一个最小堆
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> Q;
    // 把C放入Q中
    for (int i = 0; i < n; i++) {
        Q.push(C[i]);
    }
    int freq1=0;
    int freq2=0;
    int sumfreq=0;
    char tempsymbol;
    
    while(Q.size()>=2) {
        TreeNode *root1=new TreeNode();
        freq1=Q.top()->freq;
        root1->left=Q.top();
        Q.pop();
        freq2=Q.top()->freq;
        root1->right=Q.top();
        Q.pop();
        sumfreq=freq1+freq2;
        root1->freq=sumfreq;
        root1->symbol=' ';
        Q.push(root1);
    }
    // 请完成huffman编码的程序
    return Q.top();
}

void OutputAllSymbolCode(TreeNode* root, string code = "") {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->symbol << ":" << code << endl;
    }
    if (root->left != NULL) {
        OutputAllSymbolCode(root->left, code + '0');  // 左节点编码加0
    }
    if (root->right != NULL)
    {
        OutputAllSymbolCode(root->right, code + '1'); // 右节点编码加1
    }
}

void printTree(TreeNode* root){
    if (root == NULL)
        return;
    if (root->symbol!=' ') {
        cout << root->symbol  << endl;
    }
    else{
        cout<<root->freq<<endl;
    }
    if (root->left != NULL) {
        printTree(root->left);  // 左节点编码加0
    }
    if (root->right != NULL)
    {
        printTree(root->right); // 右节点编码加1
    }
}
// 销毁树
void Destory(TreeNode* root) {
    if (root == NULL)
        return;
    Destory(root->left);
    Destory(root->right);
    delete root;
}

TreeNode* Huffman(string symbols, vector<double> freqs) {
    vector<TreeNode *> C;
    for (size_t i = 0; i < freqs.size(); i++) {
        C.push_back(new TreeNode(symbols[i], freqs[i]));
    }
    return Huffman(C);
}

int main() {
    string symbols = "ABCDEFGHIJKL";
    vector<double> freqs = { 10.1, 8, 18, 11.1, 6.6, 1.2, 4.4, 9.2, 13.5, 2.1, 10.3, 5.5 };
    // string symbols = "abcde";
    
   //  vector<double> freqs = {1, 2, 3, 4, 5};

    TreeNode *root = Huffman(symbols, freqs);
    printTree(root);
    OutputAllSymbolCode(root);
    
    Destory(root);
    Pause();
    return 0;
}
