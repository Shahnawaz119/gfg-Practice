/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        unordered_set<int> s;
        Node* curr=new Node(-1);
        curr->next=head;
        Node* prev=curr;
        while(head){
            if(s.find(head->data)==s.end()){
                s.insert(head->data);
                prev=prev->next;
                head=head->next;
                
            }else{
                if(head->next==NULL){
                    prev->next=NULL;
                    break;
                }else{
                    prev->next=head->next;
                    head=prev->next;
                }
            }
        }
        return curr->next;
    }
};