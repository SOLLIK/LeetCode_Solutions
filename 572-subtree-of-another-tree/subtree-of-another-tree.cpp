/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "$#";
        }

        return "$" + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    vector<int> z_function(string s) {
        vector<int> z(s.length());
        int l = 0, r = 0, n = s.length();
        for(int i = 1; i < n; i++) {
            if(i <= r) {
                z[i] = min(r - i + 1, z[i - l]); 
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sr = serialize(root);
        string ssR = serialize(subRoot);
        string combined = ssR + "|" + sr;

        vector<int> z_value = z_function(combined);
        int sub_len = ssR.length();

        for(int i = sub_len + 1; i < combined.length(); i++) {
            if(z_value[i] == sub_len) {
                return true;
            }
        }
        return false;
    }
};