#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Recursive function to add a value to the tree
    Node* addNode(Node* node, T value) {
        if (node == nullptr) {
            node = new Node(value);
        }
        else if (value < node->data) {
            node->left = addNode(node->left, value);
        }
        else {
            node->right = addNode(node->right, value);
        }
        return node;
    }

    // In-order traversal (ascending)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Reverse in-order traversal (descending)
    void descending(Node* node) {
        if (node != nullptr) {
            descending(node->right);
            std::cout << node->data << " ";
            descending(node->left);
        }
    }

    // Recursive search
    bool searchNode(Node* node, T value) {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        else if (value < node->data)
            return searchNode(node->left, value);
        else
            return searchNode(node->right, value);
    }

    // Free memory
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    ~BinaryTree() {
        deleteTree(root);
    }

    void add(T value) {
        root = addNode(root, value);
    }

    void printAscending() {
        std::cout << "Ascending order: ";
        inorder(root);
        std::cout << std::endl;
    }

    void printDescending() {
        std::cout << "Descending order: ";
        descending(root);
        std::cout << std::endl;
    }

    bool contains(T value) {
        return searchNode(root, value);
    }
};

// Main function to test the binary tree
int main() {
    BinaryTree<int> tree;

    // Adding elements
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    // Tree traversal
    tree.printAscending();    // Output: 20 30 40 50 60 70 80
    tree.printDescending();   // Output: 80 70 60 50 40 30 20

    // Search for a value
    int val = 40;
    if (tree.contains(val)) {
        std::cout << val << " was found in the tree." << std::endl;
    }
    else {
        std::cout << val << " was not found in the tree." << std::endl;
    }

    return 0;
}
