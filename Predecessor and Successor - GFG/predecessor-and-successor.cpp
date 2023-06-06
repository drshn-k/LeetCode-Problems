//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
  
    public:
    void findpre(Node* root ,int key,Node* &pre,int &minm){
        // just smaller than key
        if(root == NULL) return ;
        if(root->key < key) {
            if(key - root->key < minm){
                minm = key- root->key;
                pre = root;
            }
        }
        if(key > root->key)
            findpre(root->right,key,pre,minm);
        else findpre(root->left,key,pre,minm);
    }
    void findsuc(Node* root, int key,Node* &suc,int &minm){
        // just greater than key
        if(root == NULL) return ;
        if(root->key > key) {
            if(root->key - key < minm){
                minm = root->key - key;
                suc = root;
            }
        }
        if(key >= root->key)
            findsuc(root->right,key,suc,minm);
        else findsuc(root->left,key,suc,minm);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        int minm = INT_MAX;
         findpre(root,key,pre,minm);
          minm = INT_MAX;
         findsuc(root,key,suc,minm);
    }
        // Your code goes here
    
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}
// } Driver Code Ends