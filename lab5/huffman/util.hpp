#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;


string RED = "\033[1;31m";
string GREEN = "\033[1;32m";
string BLUE = "\033[1;36m";
string END = "\033[0m";

/*
    调试输出
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string &s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v) {
    if(v.size() > 100) {
        return END +  "[hidden] data is too long" + BLUE;
    }
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
            if(typeid(x) == typeid(vector<int>)) res += "\n";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}


void debug_out() {
    cerr << END << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << BLUE << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


template <typename T>
bool compare_result(string sample_name, T &my_ans, T &answer) {
    bool equal = (my_ans == answer);
    if (!equal) {
        cerr << sample_name << ": \t" << RED << " Wrong Answer" << END << endl;
        debug(my_ans);
        debug(answer);
    } else {
        cerr << sample_name << ": \t" << GREEN << " Accepted" << END << endl;
    }
    return equal;
}

/**
 * @brief TreeNode 结构体定义
 * 
 */
struct TreeNode {
    char symbol;       // 编码的字母
    double freq;       // 对应的频率
    TreeNode *left;    // 左孩子
    TreeNode *right;   // 右孩子
    // 构造函数
    TreeNode()
        : symbol('\0'), freq(0), left(NULL), right(NULL) {}
    // 用symbol和freq构造 TreeNode 对象
    TreeNode(char symbol_, double freq_)
        : symbol(symbol_), freq(freq_), left(NULL), right(NULL) {}
    // () 函数，用于规定优先队列比较运算
    bool operator () (const TreeNode* lhs, const TreeNode* rhs) {
        return lhs->freq > rhs->freq;
    }
};

/**
 * @brief 输出每个叶子节点的哈夫曼编码
 * 
 * @param root 
 * @param code 
 */
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

/**
 * @brief double 转 str（带精度控制）
 * 
 * @param x 
 * @return string 
 */
string double_to_string(double x) {
    char s[20];
    sprintf(s, "%.2f", x);
    return string(s);
}

/**
 * @brief 递归打印树结构
 * 
 * @param node 
 * @param prefix 
 * @param isLeft 
 */
void print_tree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        print_tree(node->right, prefix + (isLeft ? "|     " : "      "), false);
    }

    cout << prefix + (isLeft ? "|-----" : "|-----") + (!isalpha(node->symbol) ? double_to_string(node->freq) : string("") + node->symbol + "(" + double_to_string(node->freq) + ")") + "\n";

    if (node->left) {
        print_tree(node->left, prefix + (isLeft ? "      " : "|     "), true);
    }
}