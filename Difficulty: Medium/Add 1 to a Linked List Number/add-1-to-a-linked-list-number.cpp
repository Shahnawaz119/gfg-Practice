/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head=reverse(head);
        Node* curr=head;
        int carry=1;
        while(curr){
            int sum=curr->data+carry;
            curr->data=sum%10;
            carry=sum/10;
            if(carry==0){
                break;
            }
            
            if(curr->next==NULL && carry>0){
                curr->next=new Node(carry);
                carry=0;
            }
            curr=curr->next;
        }
        head=reverse(head);
        return head;
        // return head of list after adding one
    }
};