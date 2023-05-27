//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/class Solution{
    public:
    Node* reverse(Node* node) {
        Node* prev= NULL;
        Node* curr = node;
        while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;  
        }
        
       return prev; 
    }
    struct Node* modifyTheList(struct Node *head)
    {
        Node* node = head;
        int cnt = 0;
        while(node){
            cnt++;
            node =node->next;
        }
       Node* slow = head;
       Node* fast = head;
       Node* prev;
       while(fast && fast->next) {
           prev = slow;
           slow = slow->next;
           fast= fast->next->next;
       }
       if(cnt%2){
        Node* helper = reverse(slow->next);
       slow->next = helper;
       }
       else{
       Node* helper = reverse(slow);
       prev->next = helper; 
       }
       
       
       
       slow = head;
       fast = head;
       while(fast && fast->next)
       {
           slow = slow->next;
           fast = fast->next->next;
       }
    
       fast = head;
       if(cnt%2)
       slow = slow->next;
       while(slow){
           int val = fast->data;
           fast->data = slow->data-val;
           slow->data = val;
           slow = slow->next;
           fast = fast->next;
           
       }
       
       
       slow = head;
       fast = head;
       prev = NULL;
       
        while(fast && fast->next) {
            prev = slow;
          slow = slow->next;
          fast= fast->next->next;
      }
       
    if(cnt%2){
        Node* helper2 = reverse(slow->next);
       slow->next = helper2;
       }
       else{
       Node* helper2 = reverse(slow);
       prev->next = helper2; 
       }
       
       return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends