#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data of left: " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data of right: " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void buildtreelevelorder(node *root)
{
    queue<node *> q;
    cout << "Enter root data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for:" << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for:" << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void Levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // traverse one level
            cout << endl;
            if (!q.empty())
            {
                // queue has still any child node
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// other approach for lvel order tree traversal
void printLevelWise(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << ":";

        if (temp->left)
        {
            q.push(temp->left);
            cout << "L:" << temp->left->data;
        }
        else
            cout << "L:-1";

        cout << ",";

        if (temp->right)
        {
            q.push(temp->right);
            cout << "R:" << temp->right->data << endl;
        }
        else
            cout << "R:-1" << endl;
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int countnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->left);
}
bool isNodePresent(node *root, int x) {
    while(root!=NULL && root->data != x){
        root = x<root->data? root->left:root->right;
    }
    return root;
}
int height(node *root) {
	if(root ==NULL)
		return 0;

	int l = height(root->left);
	int r = height(root->right);
	
	return 1 + max(l, r);
}
void mirrorBinaryTree(node* root) {
    // Write your code here
	if(!root)
		return;
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);
	swap(root->left, root->right);
}
int getSum(node *root) {
    // Write your code here
	if(!root)
		return 0;
	
	int ans = root->data;
	int l = getSum(root->left);
	ans +=l;
	int r=getSum(root->right);
	ans +=r;
	return ans;
}
bool isBalanced(node *root) {
	// Write your code here
	if(!root){
		return true;
	}
}
void zigZagOrder(node *root) {
    // Write your code here
 if(!root)
     return;
    
    stack<node *> s1;
    stack<node *> s2;
    
    s1.push(root);
    
    while(!s1.empty() && !s1.empty())
    {
        while(!s1.empty()){ 
            node * top=s1.top();
            s1.pop();
            cout<<top->data<<" ";
        
            if(top->left)
                s2.push(top->left);
            if(top->right)
                s2.push(top->right);
        }
        
        cout<<endl;
        
        while(!s2.empty()){
            node * top=s2.top();
            s2.pop();
            cout<<top->data<<" ";
            
            if(top->right)
                s1.push(top->right);
            if(top->left)
                s1.push(top->left);
        }
        cout<<endl;
        
    }
     
}
void printNodesWithoutSibling(node *root) {
    // Write your code here
    if(root==NULL)
        return;
    
    if(root->left && !root->right)
    {  cout<<root->left->data<<" ";
    
       printNodesWithoutSibling(root->left); 
    }
     else if(!root->left && root->right)
    {  
        cout<<root->right->data<<" ";
    
       printNodesWithoutSibling(root->right); 
    }
	else 
    {
        printNodesWithoutSibling(root->left); 
        printNodesWithoutSibling(root->right); 
    }
}
int main()
{
    node *root = NULL;
    // create tree
    root = buildtree(root);
    cout<< "level order traversal:"<<endl;
    Levelordertraversal(root);
    cout<<"inorder traversal:"<<endl;
    inorder(root);
    cout<<"Num of nodes: "<<countnodes(root)<<endl;
    return 0;
    /*buildtreelevelorder(root);
    Levelordertraversal(root);*/
}
