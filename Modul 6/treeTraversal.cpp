#include <iostream>
#include <string>
#include "RedBlackTree.h" 
using namespace std;

void printPreorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode) {
    if (node == nilNode) return;
    
    cout << " " << node->key;
    printPreorder(node->left, nilNode);
    printPreorder(node->right, nilNode);
}

void printInorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode) {
    if (node == nilNode) return;
    
    printInorder(node->left, nilNode);
    cout << " " << node->key;
    printInorder(node->right, nilNode);
}

void printPostorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode) {
    if (node == nilNode) return;
    
    printPostorder(node->left, nilNode);
    printPostorder(node->right, nilNode);
    cout << " " << node->key;
}

int main() {
    int n;
    cin >> n;
    
    RedBlackTree tree;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        if (!tree.contains(val)) {
            tree.insert(val);
        }
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        
        if (tree.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }
        
        const RedBlackTree::Node* rootNode = tree.root();
        const RedBlackTree::Node* nilNode = tree.nil();
        
        if (query == "PREORDER" || query == "ALL") {
            cout << "[Preorder] :";
            printPreorder(rootNode, nilNode);
            cout << endl;
        }
        if (query == "INORDER" || query == "ALL") {
            cout << "[Inorder]  :";
            printInorder(rootNode, nilNode);
            cout << endl;
        }
        if (query == "POSTORDER" || query == "ALL") {
            cout << "[Postorder]:";
            printPostorder(rootNode, nilNode);
            cout << endl;
        }
    }
    
    return 0;
}