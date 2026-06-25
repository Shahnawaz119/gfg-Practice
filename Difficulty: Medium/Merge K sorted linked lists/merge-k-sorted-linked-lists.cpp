/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeList(Node* a,Node* b){
        Node* c=new Node(100);
        Node* temp=c;
        while(a!=NULL && b!=NULL){
            if(a->data<=b->data){
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if(a==NULL){
            temp->next=b;
        }
        if(b==NULL){
            temp->next=a;
        }
        
        return c->next;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        if(arr.size()==0){
            return NULL;
        }
        if(arr.size()==1){
            return arr[0];
        }
        while(arr.size()>1){
            Node* a=arr[arr.size()-1];
            arr.pop_back();
            Node* b=arr[arr.size()-1];
            arr.pop_back();
            Node* newNode=mergeList(a,b);
            arr.push_back(newNode);
        }
        return arr[0];
    }
};