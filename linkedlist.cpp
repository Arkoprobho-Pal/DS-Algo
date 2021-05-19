#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
};
class LList{
    public:
        Node* head;
        LList(){
            head=NULL;
        }
        void printList();
        void addNode(int);
        void delNode(int);
};
void LList::addNode(int val){
    //just append nodes
    Node* current=head;
    if(current==NULL){
        //for empty list
        Node* newNode=new Node();
        newNode->val=val;
        newNode->next=NULL;
        head=newNode;
    }
    else{
        while(current->next!=NULL){
            current=current->next;//move current to last node
        }
        Node* newNode=new Node();
        newNode->val=val;
        newNode->next=NULL;
        current->next=newNode;
    }
}
//----------------------------
void LList::printList(){
    Node* current=head;
    cout<<"[";
    while(current){
        cout<<current->val<<" ";
        current=current->next;
    }
    cout<<"]"<<endl;
}
//----------------------------
void LList::delNode(int pos){
    int len=0;
    Node* leng=head;
    while(leng){
        len++;
        leng=leng->next;
    }

    if(len<pos){
        cout<<"List Doesn't consist of such position, as the length of the list is "<<len<<endl;
        return;
    }
    else{
        Node* current=head,*temp;
        temp=current;
        int i=1;
        while(current){
            if(i==pos){
                temp->next=current->next;
                delete(current);
                return;
            }
            temp=current;//assigns previous node of current
            current=current->next;            
            i++;
        }

    }
}
int main(){
    LList* newList=new LList();
    newList->addNode(1);
    newList->addNode(2);
    newList->addNode(3);
    
    newList->addNode(4);
    newList->printList();
    newList->addNode(5);
    newList->delNode(4);
    newList->printList();
    return 0;
}