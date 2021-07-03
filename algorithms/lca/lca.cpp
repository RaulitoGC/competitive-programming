#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"

#define loop(i,n) for(int i = 0; i < n ; i++)
#define read(n) cin >> n
#define readSS(ss1,ss2) cin >> ss1 >> ss2
#define write(n) cout << n << "\n"

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))
#define vi vector<int>
#define vf vector<float>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

#define MAX 100005

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// Node for tree
struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int _val): val(_val), left(nullptr), right(nullptr){};
  Node(int _val, Node* _left, Node* _right): val(_val), left(_left), right(_right){};
};

// Return LCA for nodeOne and nodeTwo
// Algorithm : If we know that there is a node that is equals to nodeOne
// or nodeTwo, we return that node. So, when a root node which has left and right node 
// not equals to null, it means that this node is the LCA. On the other hand, return null
// if that root does not contain in its children nodeOne or nodeTwo.
Node* lca(Node* root , Node* nodeOne, Node* nodeTwo){

  // If the root is null, return null ( no answer or is leaf's children)
  if(root == nullptr){
    return nullptr;
  }

  // Compare if root is equal to nodeOne or nodeTwo
  if(root == nodeOne || root == nodeTwo){
    return root;
  }

  // Get lca with left/right as a root
  Node* left = lca(root->left, nodeOne, nodeTwo);
  Node* right = lca(root->right, nodeOne, nodeTwo);

  // LCA found from algorithm explanation
  if(left != nullptr && right != nullptr){
    return root;
  }

  // This can be a children of leaf
  if(left == nullptr && right == nullptr){
    return nullptr;
  }

  // In case there is a left or right with value not equal to null,
  // return that node
  return (left != nullptr)? left : right;
}

int main(){

  Node* root = new Node(1);

  Node* nodeTwo = new Node(2);
  Node* nodeThree = new Node(3);
  root->left = nodeTwo;
  root->right = nodeThree;

  Node* nodeFour = new Node(4);
  Node* nodeFive = new Node(5);
  nodeTwo->left = nodeFour;
  nodeTwo->right = nodeFive;

  Node* nodeSix = new Node(6);
  Node* nodeSeven = new Node(7);
  nodeThree->left = nodeSix;
  nodeThree->right = nodeSeven;
	cout << root->val << endl;
  Node* res = lca(root, nodeThree, root);
  test();
  if(res == nullptr){
    cout << " lca null" << endl;
  }
	cout << res->val << endl;
	return 0;
}
