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
    // 优先级比较
    bool operator < (const TreeNode* lhs, const TreeNode* rhs) {
        return lhs->freq > rhs->freq;
    }
};

TreeNode* huffman(vector<TreeNode*>& C) {
    int n = C.size();
    // 创建一个最小堆
    // Q.push(x) 表示将 x 入堆
    // TreeNode* p = Q.top() 表示取出堆顶
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> Q;
    // 把C放入Q中
    for (int i = 0; i < n; i++) {
        Q.push(C[i]);
    }
    double freq1=0;
    double freq2=0;
    double sumfreq=0;
    

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


// 输出每个叶子节点的哈夫曼编码
void out_symbol_code(TreeNode* root, string code = "") {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->symbol << ":" << code << endl;
    }
    if (root->left != NULL) {
        out_symbol_code(root->left, code + '0');  // 左节点编码加0
    }
    if (root->right != NULL)
    {
        out_symbol_code(root->right, code + '1'); // 右节点编码加1
    }
}

string double_to_string(double x) {
  char s[20];
  sprintf(s, "%.2f", x);
  return string(s);
}

// 递归打印树结构
void print_tree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        print_tree(node->right, prefix + (isLeft ? "|     " : "      "), false);
    }

    cout << prefix + (isLeft ? "|-----" : "|-----") + (node->symbol == ' ' ? double_to_string(node->freq) : string("") + node->symbol + "(" + double_to_string(node->freq) + ")") + "\n";

    if (node->left) {
        print_tree(node->left, prefix + (isLeft ? "      " : "|     "), true);
    }
}

// 销毁树
void destory(TreeNode* root) {
    if (root == NULL)
        return;
    destory(root->left);
    destory(root->right);
    delete root;
}

TreeNode* huffman(string symbols, vector<double> freqs) {
    vector<TreeNode *> C;
    for (size_t i = 0; i < freqs.size(); i++) {
        C.push_back(new TreeNode(symbols[i], freqs[i]));
    }
    return huffman(C);
}

int main() {
    string symbols = "ABCDEFGHIJKL";
    vector<double> freqs = { 10.1, 8, 18, 11.1, 6.6, 1.2, 4.4, 9.2, 13.5, 2.1, 10.3, 5.5 };

    TreeNode *root = huffman(symbols, freqs);
    print_tree(root);
    out_symbol_code(root);
    
    destory(root);
    return 0;
}
