using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void populateNodesToParents(BinaryTree* node, 
														BinaryTree* parent, 
														unordered_map<int, BinaryTree*> &nodesToParents){
	if(node != nullptr){
		nodesToParents[node->value] = parent;
		populateNodesToParents(node->left, node, nodesToParents);
		populateNodesToParents(node->right, node, nodesToParents);
	}
}

BinaryTree* getNodeFromValue(int target, BinaryTree* tree, unordered_map<int, BinaryTree*> nodesToParents){
	if(tree->value == target){
		return tree;
	}
	
	BinaryTree* nodeParent = nodesToParents[target];
	BinaryTree* left = nodeParent->left;
	if(left != nullptr && left->value == target){
		return left;
	}
	
	return nodeParent->right;
}

vector<int> BFSForNodesDistance(BinaryTree* targetNode, unordered_map<int, BinaryTree*> nodesToParents, int k){
	deque<pair<BinaryTree*, int>> queue = {
		make_pair(targetNode, 0)
	};
	unordered_set<int> visited = {targetNode->value};
	
	while(!queue.empty()){
		
		auto currentNode = queue.front().first;
		auto distanceFromTarget = queue.front().second;
		queue.pop_front();
		
		if(distanceFromTarget == k){
			vector<int> nodesDistanceK;
			for(auto item: queue){
				nodesDistanceK.push_back(item.first->value);
			}
			nodesDistanceK.push_back(currentNode->value);
			return nodesDistanceK;
		}
		
		vector<BinaryTree*> connectedNodes = {
			currentNode->left,
			currentNode->right,
			nodesToParents[currentNode->value]
		};
		
		for(auto node: connectedNodes){
			if(node == nullptr || visited.find(node->value) != visited.end()) continue;
			
			visited.insert(node->value);
			queue.push_back(make_pair(node, distanceFromTarget + 1));
			
		}
	}
	
	return {};
}

vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
  unordered_map<int, BinaryTree*> nodesToParents;
	populateNodesToParents(tree, nullptr, nodesToParents);
	BinaryTree* targetNode = getNodeFromValue(target, tree, nodesToParents);
  return BFSForNodesDistance(targetNode, nodesToParents, k);
}

