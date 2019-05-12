#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
#define z() Sleep(2000)

#define loop(i,n) for(int i = 0; i < n ; i++)

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

struct Node {
	int value;
	Node *next;
};

class LinkedList{

public:
	LinkedList(){
        head = NULL;
    }
	
	void addValue(int value){
        Node *node = new Node();   
        node->value = value;             
        node->next = head;         
        head = node;              
    }
    
    int popValue(){
	    Node *node = head;
        int ret = node->value;
        
        head = head->next;
        delete node;
        return ret;
    }
	
	int getMidValue(){
		Node *rabbit = head;
		while(rabbit->next != NULL){
			rabbit = rabbit->next;
			debug(rabbit->value);
			if(rabbit->next != NULL){
				rabbit = rabbit->next;	
				debug(rabbit->value);
			}	
			head = head->next;
			debug(head->value);
		}
		return head->value;	
	}
	
	Node *removeDuplicate(){
		Node *first = head;
		Node *temp =  first->next;
	
		while(first->value != temp->value){
			first = temp;
			temp = temp->next;
		}
		
		first->next = temp->next;
		temp->next = NULL;
		delete temp;
		return first;	
	}	
    

private:
	Node *head;
};




int main(){
	
//	LinkedList list;
//
//  list.addValue(7);
//  list.addValue(5);
//	list.addValue(1);
//	list.addValue(1);
	
	LinkedList list;

    list.addValue(8);
    list.addValue(8);
	list.addValue(7);
	list.addValue(6);
	list.addValue(4);
	
	Node *pointer_to_list =  list.removeDuplicate();

    cout << pointer_to_list->value << endl;
	
	return 0;
}
