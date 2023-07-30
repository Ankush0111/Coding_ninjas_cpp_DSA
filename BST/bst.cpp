#include<bits/stdc++.h>
using namespace std;
class node{
  public:
        int data;
        node *left;
        node *right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node  *insertintoBST(node *root, int d){
    //base case
    if(root == NULL) {
        root = new node(d);
        return root;
    }
    if(d > root->data){
        //inert in right part 0f tree
        root->right = insertintoBST(root->right, d);
    }

    else{
        //inert in left part 0f tree
        root->left = insertintoBST(root->left, d);
    }
    return root;
}
void buildBST(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertintoBST(root, data);
        cin>>data;
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
void elementsInRangeK1K2(node *root, int k1, int k2) {
	if(root == NULL)
		return;
	
	if(root->data > k1)
		elementsInRangeK1K2(root->left, k1, k2);

	if(root->data >= k1 && root->data <=k2)
		cout<<root->data<<" ";

	if(root->data < k2)
		elementsInRangeK1K2(root->right, k1, k2);
}
//check BST
int maximum(node *root){
    if(root == NULL)    
        return INT_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(node *root){
    if(root == NULL)    
        return INT_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(node *root){
    if(root == NULL){
        return true;
    }
    int lmax =maximum(root->left);
    int rmin =minimum(root->right);
    bool output = (root->data > lmax) && (root->data <= rmin) && isBST(root->right) && isBST(root->right);
    return output;
}
//construct bst from a sorted array.
node *Tree(int *input, int start, int end){
	if(start>end){
		return NULL;
	}
	int	mid = (start+end)/2;
	node *root = new node (input[mid]);

	root->left = Tree(input, start, mid-1);
	root->right = Tree(input, mid+1, end);
}
node *constructTree(int *input, int n) {
	return Tree(input, 0, n-1);
}
//find path
vector<int>* getPath(node *root , int data) {
	if(root == NULL)
		return NULL;

	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	vector<int>* leftout = getPath(root->left, data);
	if(leftout != NULL){
		leftout->push_back(root->data);
		return leftout;
	}
	vector<int>* rightout = getPath(root->right, data);
	if(rightout != NULL){
		rightout->push_back(root->data);
		return rightout;
	}
	else{
		return NULL;
	}
}
void insertDuplicateNode(node *root) {
    // Write your code here
    if(root == NULL)
        return;
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);

    node *duplicateNode = new node(root->data);
    duplicateNode->left = root->left;
    root->left = duplicateNode;
}
//pair sum
void inorderPair(node *root, vector<int> &in){
	if(root == NULL)
		return;
	
	inorderPair(root->left, in);
	in.push_back(root->data);
	inorderPair(root->right, in);
}
void printNodesSumToS(node *root, int s) {
	vector<int> arr;
	inorderPair(root, arr);
	int i=0,j=arr.size()-1;
	while (i < j){
	int sum = arr[i]+arr[j];

        if (sum == s)
            cout << arr[i] << " " << arr[j] << endl;
        else if (sum > s) {
          j--;
        } else if (sum < s)
          i++;
        }
}
//Get LCA of a BST
int getLCA(node *root , int val1 , int val2){
	if(root==NULL)
        return -1;
    if(root->data == val1 || root->data== val2)
        return root->data;
    
    int left=getLCA(root->left,val1,val2);
    int right =getLCA(root->right,val1,val2);
    
    if(left== -1 && right == -1)
       return -1;
    else if( left!=-1 &&right ==-1)
        return left;
     else if( left==-1 &&right !=-1)
        return right;
     else
         return root->data;
}
//Replace with Sum of greater nodes
int replace(node *root,int sum)
{
    if(root==NULL)
        return sum;
    
     sum=replace(root->right,sum);
      sum=sum +root->data;
      root->data=sum;
      sum =replace(root->left,sum);
    
   return  sum;
    
}
void replaceWithLargerNodesSum(node *root) {
    if(root==NULL)return; 
    int ans =replace(root,0);
    
    return ;
}
//largest BST
class Pair {
    
public:
  int minimum;
  int maximum;
  bool bst;
  int height;
};

Pair BST(node *root) {
  if (root == NULL) {
    Pair obj;
    obj.minimum = INT_MAX;
    obj.maximum = INT_MIN;
    obj.bst = true;
    obj.height = 0;
    return obj;
  }

  Pair left = BST(root->left);
  Pair right = BST(root->right);

  int minimum = min(root->data, min(left.minimum, right.minimum));
  int maximum = max(root->data, max(left.maximum, right.maximum));
  bool isBSTfinal = (root->data > left.maximum) &&
                    (root->data < right.minimum) && left.bst && right.bst;

  Pair obj;
  obj.minimum = minimum;
  obj.maximum = maximum;
  obj.bst = isBSTfinal;
  if (isBSTfinal) {
    obj.height = 1 + max(left.height, right.height);
  } else
    obj.height = max(left.height, right.height);
  return obj;
}

int largestBSTSubtree(node *root) {
  // Write your code here
  return BST(root).height;
}
int main(){
    node *root = NULL;
    cout<<"Enter the data:"<<endl;
    buildBST(root);
    
    cout<<"print BSt:"<<endl;
    Levelordertraversal(root);

    cout<<"printing preorder:"<<endl;
    preorder(root);

    cout<<"printing inorder:"<<endl;
    inorder(root);

    cout<<"printing postorder:"<<endl;
    postorder(root);

    cout<<isBST(root);

    return 0;
}