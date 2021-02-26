#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    queue<Node*> Q;
		Q.push(this);
		vector<string> res;
		while(!Q.empty()){
			Node* current = Q.front();
			res.push_back(current->name);
			Q.pop();
			vector<Node*> v = current->children;
			for(int i = 0 ; i < v.size() ; i++){
				Q.push(v[i]);
			}
		}
    return res;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
