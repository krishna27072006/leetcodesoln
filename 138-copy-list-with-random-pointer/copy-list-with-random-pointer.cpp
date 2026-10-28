
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        unordered_map<Node*,Node*> m;
        Node*ans=NULL;
        Node*temp=head;
        Node*temp1=NULL;
        while(temp!=NULL){
            Node*neww=new Node(temp->val);
            m[temp]=neww;
            if(temp1!=NULL){
                temp1->next=neww;
            }
            if(ans==NULL) {
                ans=neww;
            }
            temp1=neww;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                m[temp]->random=m[temp->random];
            }
            temp=temp->next;
        }
        return ans;
    }
};
