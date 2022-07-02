#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

void bottomview(Node* root,map<int,int> &mp){
    if(root==NULL)
        return;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(!q.empty()){

        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int line = p.second;

        mp[line] = node->data;

        if(node->left)
            q.push({node->left,line-1});
        if(node->right)
            q.push({node->right,line+1});
            
        
    }
}

int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->right->left=new Node(4);
    root->left->left=new Node(6);
    root->right->left->left=new Node(8);
    root->right->left->right=new Node(9);

    map<int,int> mp;

    bottomview(root,mp);

    for(auto value : mp){
        cout<<value.second<<" ";
    }

    
    

    return 0;
}