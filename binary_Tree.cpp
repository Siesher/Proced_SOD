#include <iostream>
#include <string>

struct ProgramVersion {
    int major;
    int minor;
    int patch;
    std::string name;

    bool operator<(const ProgramVersion& other) const {
        if (major != other.major) return major < other.major;
        if (minor != other.minor) return minor < other.minor;
        if (patch != other.patch) return patch < other.patch;
        return name < other.name;
    }

    bool operator>(const ProgramVersion& other) const {
        return other < *this;
    }

    bool operator==(const ProgramVersion& other) const {
        return major == other.major && minor == other.minor && patch == other.patch && name == other.name;
    }
};

std::ostream& operator<<(std::ostream& os, const ProgramVersion& pv) {
    os << pv.name << " v" << pv.major << "." << pv.minor << "." << pv.patch;
    return os;
}

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
};

template <typename T>
TreeNode<T>* createNode(const T& value) {
    TreeNode<T>* newNode = new TreeNode<T>{value, nullptr, nullptr};
    return newNode;
}

template <typename T>
void insertNode(TreeNode<T>*& root, const T& value) {
    if (root == nullptr) {
        root = createNode(value);
    } else if (value < root->data) {
        insertNode(root->left, value);
    } else {
        insertNode(root->right, value);
    }
}

template <typename T>
TreeNode<T>* searchNode(TreeNode<T>* root, const T& value) {
    if (root == nullptr || root->data == value) {
        return root;
    } else if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

template <typename T>
TreeNode<T>* findMin(TreeNode<T>* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

template <typename T>
TreeNode<T>* deleteNode(TreeNode<T>* root, const T& value) {
    if (root == nullptr) {
        return root;
    } else if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode<T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode<T>* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode<T>* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

template <typename T>
void inorderTraversal(TreeNode<T>* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

template <typename T>
void preorderTraversal(TreeNode<T>* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

template <typename T>
void postorderTraversal(TreeNode<T>* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

template <typename T>
void deleteTree(TreeNode<T>*& root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

int main() {
    TreeNode<ProgramVersion>* root = nullptr;

    ProgramVersion v1{1, 0, 0, "ProgramA"};
    ProgramVersion v2{1, 1, 0, "ProgramA"};
    ProgramVersion v3{2, 0, 0, "ProgramB"};
    ProgramVersion v4{1, 0, 1, "ProgramA"};
    ProgramVersion v5{1, 2, 0, "ProgramA"};

    insertNode(root, v1);
    insertNode(root, v2);
    insertNode(root, v3);
    insertNode(root, v4);
    insertNode(root, v5);

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    ProgramVersion searchValue{1, 1, 0, "ProgramA"};
    TreeNode<ProgramVersion>* foundNode = searchNode(root, searchValue);
    if (foundNode) {
        std::cout << "Node with value " << searchValue << " found." << std::endl;
    } else {
        std::cout << "Node with value " << searchValue << " not found." << std::endl;
    }

    ProgramVersion deleteValue{1, 0, 0, "ProgramA"};
    root = deleteNode(root, deleteValue);
    std::cout << "Inorder traversal after deleting " << deleteValue << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}



