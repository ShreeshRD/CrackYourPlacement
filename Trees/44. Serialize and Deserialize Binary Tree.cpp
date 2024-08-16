#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        serialDFS(root, ans);
        cout << ans << endl;
        return ans;
    }

    void serialDFS(TreeNode *root, string &ans)
    {
        if (!root)
            ans += "# ";
        else
        {
            ans += to_string(root->val) + " ";
            serialDFS(root->left, ans);
            serialDFS(root->right, ans);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    TreeNode *deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};