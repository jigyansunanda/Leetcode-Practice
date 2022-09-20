class Solution {
public:
    string getDirections(TreeNode* root, int s, int t) {
        string source = "", destination = "";
        getDirections(root, s, source);
        getDirections(root, t, destination);
        while (!source.empty() and !destination.empty() and source.back() == destination.back()) {
            source.pop_back();
            destination.pop_back();
        }
        reverse(destination.begin(), destination.end());
        return string(source.size(), 'U') + destination;
    }

    bool getDirections(TreeNode* root, int s, string& path) {
        if (root == NULL) return false;
        if (root->val == s) return true;
        if (root->left and getDirections(root->left, s, path)) {
            path.push_back('L');
        } else if (root->right and getDirections(root->right, s, path)) {
            path.push_back('R');
        }
        return !path.empty();
    }
};