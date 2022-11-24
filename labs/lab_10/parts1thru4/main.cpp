#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* buildtree() {
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    /* tree structure

          1
         / \
        2   3
       / \
      4   5

     */
    return root;
}


void inorderTraversal(TreeNode* root) {
    if (root->left) {
        inorderTraversal(root->left);
    }
    std::cout << root->val << " ";
    if (root->right) {
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    std::cout << root->val << " ";
    if (root->left) {
        preorderTraversal(root->left);
    }
    if (root->right) {
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root->left) {
        inorderTraversal(root->left);
    }
    if (root->right) {
        inorderTraversal(root->right);
    }
    std::cout << root->val << " ";
}

void LevelOrderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    std::queue<TreeNode *> cue;
    cue.push(root);

    while (!cue.empty()) {
        TreeNode *nodeptr = cue.front();
        std::cout << nodeptr->val << " ";
        cue.pop();
        if (nodeptr->left) {
            cue.push(nodeptr->left);
        }
        if (nodeptr->right) {
            cue.push(nodeptr->right);
        }
    }
}

std::vector<int> level_order_nodes(TreeNode* root) {
    std::vector<int> nodevec = {};
    if (!root) {
        return nodevec;
    }

    std::queue<TreeNode *> cue;
    cue.push(root);

    while (!cue.empty()) {
        TreeNode *nodeptr = cue.front();
        nodevec.push_back(nodeptr->val);
        cue.pop();
        if (nodeptr->left) {
            cue.push(nodeptr->left);
        }
        if (nodeptr->right) {
            cue.push(nodeptr->right);
        }
    }
    return nodevec;
}

template <typename T>
bool vector_contains(std::vector<T> vec, T target) {
    for (T t : vec) {
        if (target == t) {
            return true;
        }
    }
    return false;
}

bool bst_has(int target, TreeNode *root) {
    return vector_contains(level_order_nodes(root), target);
}

int bst_depth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int left_depth = bst_depth(root->left);
    int right_depth = bst_depth(root->right);
    return std::max(left_depth, right_depth) + 1;
}


int main() {
    std::cout << "Building tree" << std::endl;;
    TreeNode* root = buildtree();
    
    std::cout << "Part 1" << std::endl;
    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nPart 2" << std::endl;
    std::cout << "Level Order Traversal: ";
    LevelOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nPart 3" << std::endl;
    int t1 = 3, t2 = 9;
    std::cout << "Is " << t1 << " in the BST? " << bst_has(t1, root) << std::endl;
    std::cout << "Is " << t2 << " in the BST? " << bst_has(t2, root) << std::endl;
    
    std::cout << "\nPart 4" << std::endl;
    std::cout << "Max depth of BST is " << bst_depth(root) << std::endl;
    return 0;
}
