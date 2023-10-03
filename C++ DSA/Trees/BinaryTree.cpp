#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

class Queue {
private:
    vector<Node*> nodes;

public:
    void enqueue(Node* node) {
        nodes.push_back(node);
    }

    Node* dequeue() {
        if (nodes.empty()) {
            return nullptr;
        }

        Node* frontNode = nodes.front();
        nodes.erase(nodes.begin());
        return frontNode;
    }

    bool isEmpty() {
        return nodes.empty();
    }
};

Node* BuildTree(vector<int>& data) {
    if (data.empty() || data[0] == -1)
        return nullptr;

    Node* root = new Node(data[0]);
    Queue q;
    q.enqueue(root);
    Node* cur = nullptr;
    int count = 0;

    for (int i = 1; i < data.size()-1; i++) {
        Node* node = new Node(data[i]);

        if (count == 0) {
            cur = q.dequeue();
        }

        if (count == 0) {
            count++;
            cur->leftChild = node;
        } else {
            count = 0;
            cur->rightChild = node;
        }

        if (data[i] != -1) {
            q.enqueue(node);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->leftChild);
    if(root->data != -1) cout << root->data << " ";
    inorder(root->rightChild);
}
int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    int num;
    vector<int> v;

    while (ss >> num) {
        v.push_back(num);
    }

    cout << "Integers stored in the vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    Node* root = BuildTree(v);
    cout<<endl;
    inorder(root);
    return 0;
}