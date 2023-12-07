#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* BuildTree(vector<int>& data)
{
    if (data.empty() || data[0] == -1 || data[0] == -2)
    {
        return nullptr;
    }

    Node* root = new Node(data[0]);
    queue<Node*> q;
    q.push(root);
    Node* cur = nullptr;
    int count = 0;

    for (int i = 1; i < data.size(); i++)
    {
        if(data[i]!=-1){
            Node* node = new Node(data[i]);
            if (count == 0)
            {
                cur = q.front();
                count++;
                cur->left = node;
            }
            else
            {
                count = 0;
                cur->right = node;
                q.pop();
            }
            if (data[i] != -1 && data[i] != -2)
                q.push(node);
        }
    }
    return root;
}

int depth(Node* root){
    if(root == nullptr)
        return 0;
    return max(depth(root->left), depth(root ->right)) + 1;
}

void preorder(Node *root)
{
    if(root == nullptr)
        return;
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    if (root->data != -1)
        cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    string line;
    getline(cin, line);

    stringstream ss(line);
    int num;
    vector<int> v;

    while (ss >> num)
    {
        v.push_back(num);
    }

    Node *root = BuildTree(v);
    cout << endl;
    cout<<"Inorder : ";
    inorder(root);
    cout<<"\n Preorder : ";
    preorder(root);
    cout<<"\nDepth of Tree : "<< depth(root);
    return 0;
}