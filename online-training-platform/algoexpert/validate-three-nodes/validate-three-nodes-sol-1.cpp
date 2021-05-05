using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool isFirstNodeAncestorOfSecond(BST* firstNode, BST* secondNode){
	
	if(firstNode == nullptr) return false;
	
	if(firstNode->value == secondNode->value) return true;
	
	if(secondNode->value < firstNode->value){
		return isFirstNodeAncestorOfSecond(firstNode->left, secondNode);
	}
	
	if(secondNode->value > firstNode->value){
		return isFirstNodeAncestorOfSecond(firstNode->right, secondNode);
	}

}

// Time:  O(h)
// Space: O(h)
bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  
	if(isFirstNodeAncestorOfSecond(nodeOne, nodeTwo)){
		return isFirstNodeAncestorOfSecond(nodeTwo, nodeThree);
	}else if(isFirstNodeAncestorOfSecond(nodeThree, nodeTwo)){
		return isFirstNodeAncestorOfSecond(nodeTwo, nodeOne);
	}
	
  return false;
}

