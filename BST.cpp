#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->data) {
            root->left = insertHelper(root->left, val);
        } else {
            root->right = insertHelper(root->right, val);
        }
        return root;
    }

    int findLongestPath(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(findLongestPath(root->left), findLongestPath(root->right));
    }

    int findMinValue(TreeNode* root) {
        if (root == nullptr) return numeric_limits<int>::max();
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->data;
    }

    void swapLeftAndRight(TreeNode* root) {
        if (root == nullptr) return;
        swap(root->left, root->right);
        swapLeftAndRight(root->left);
        swapLeftAndRight(root->right);
    }

    bool searchValue(TreeNode* root, int val) {
        if (root == nullptr) return false;
        if (root->data == val) return true;
        if (val < root->data) return searchValue(root->left, val);
        else return searchValue(root->right, val);
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    int longestPath() {
        return findLongestPath(root);
    }

    int minValue() {
        return findMinValue(root);
    }

    void swapLeftRight() {
        swapLeftAndRight(root);
    }

    bool search(int val) {
        return searchValue(root, val);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Find minimum data value found in the tree" << endl;
        cout << "4. Change a tree so that the roles of the left and right pointers are swapped at every node" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Display in inorder fashion" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Number of nodes in longest path from root: " << bst.longestPath() << endl;
                break;
            case 3:
                cout << "Minimum data value found in the tree: " << bst.minValue() << endl;
                break;
            case 4:
                bst.swapLeftRight();
                cout << "Tree after swapping left and right pointers at every node." << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << "Value found in the tree." << endl;
                } else {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            case 6:
                cout << "Inorder traversal: ";
                bst.displayInorder();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
