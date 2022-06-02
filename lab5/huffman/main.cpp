#include "util.hpp"




TreeNode* huffman(vector<TreeNode*>& tree) {
    int n = tree.size();
    // 创建一个小顶堆
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> q;
    // 把 tree 放入 q 中
    for (int i = 0; i < n; i++) {
        q.push(tree[i]);
    }

    // 请注意，非叶子结点的 symbol 不需要赋值

    while(q.size() >= 2) {
        TreeNode *root = new TreeNode();
        root->left = q.top(); q.pop();
        root->right = q.top(); q.pop();
        root->freq = root->left->freq + root->right->freq;
        q.push(root);
    }

    return q.top();
}

/**
 * @brief 销毁树结构
 * 
 * @param root 
 */
void destory(TreeNode* root) {
    if (root == NULL)
        return;
    destory(root->left);
    destory(root->right);
    delete root;
}

/**
 * @brief 对 symbols 中的字符，根据 freqs 中的频率构建哈夫曼树，返回树的根结点
 * 
 * @param symbols 
 * @param freqs 
 * @return TreeNode* 
 */
TreeNode* huffman(string symbols, vector<double> freqs) {
    vector<TreeNode *> tree;
    for (size_t i = 0; i < freqs.size(); i++) {
        tree.push_back(new TreeNode(symbols[i], freqs[i]));
    }
    return huffman(tree);
}

int main() {
    string symbols = "ABCDEFGHIJKL";
    vector<double> freqs = { 10.1, 8, 18, 11.1, 6.6, 1.2, 4.4, 9.2, 13.5, 2.1, 10.3, 5.5 };

    // 构建哈夫曼树
    TreeNode *root = huffman(symbols, freqs);
    // 打印哈夫曼树结构
    print_tree(root);
    // 输出每个字符的 Huffman 编码
    out_symbol_code(root);
    
    destory(root);
    return 0;
}
