/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* next=NULL;
        Node* curr=head;
        Node* prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        if(num1==NULL && num2==NULL){
            return NULL;
        }
        while(num1->data==0){
            num1=num1->next;
        }
        while(num2->data==0){
            num2=num2->next;
        }
        // code here
        num1=reverse(num1);
        num2=reverse(num2);
        Node* dummy=new Node(0);
        Node* curr=dummy;
        int carry=0;
        while(num1!=NULL || num2!=NULL){
            int sum=0;
            if(num1!=NULL){
                sum+=num1->data;
                num1=num1->next;
            }
            if(num2!=NULL){
                sum+=num2->data;
                num2=num2->next;
            }
            sum+=carry;
            Node* newNode=new Node(sum%10);
            curr->next=newNode;
            curr=curr->next;
            carry=sum/10;
        }
        if(carry>0){
            Node* newNode=new Node(carry);
            curr->next=newNode;
        }
        Node* ans=reverse(dummy->next);
        return ans;
    }
};