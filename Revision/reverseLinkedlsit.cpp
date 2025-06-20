/*
que: To reverse the linked list : 1->2->3->4-NULL
 revers: 4->3->2->1->NULL;

*/

 #include<iostream>
 #include<stack>
 using namespace std;

 class node{
    public:
    int data;
    node* next;

    node(int new_data){
        data=new_data;
        next=NULL;
    }
 };
 void print(node* head){
    if(head==NULL)return;

    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }

 // to reverse the linked list
 //using 1 brute solution using stack 
 // where time complexity O(2N)
 // space complexity O(N) using stack space to store the n elements 


 node* reverse1(node* head){
    //step 1 add all the elements into the stack
    node* temp=head;
    stack<int>st;

    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    //taking out the top element
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
           st.pop();
           temp=temp->next;
    }
   // delete st;

return head;
 }

 //optimal approach 
 // using three pointer prev, temp,front
 // we are not using any external data structur
 // tc:O(N)
 //sc:O(1)

 node* reverse2(node* head){

    node* prev=NULL;
    node* temp=head;
    node* front;

    //here the concept is we are not changing the date but changing the links 
    //between the nodes

    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev; //now will be the new head
 }

 //3: is using the recursion
 // tc=O(n)
 //sc=O(n) stack space memory

 node* reverse3(node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //slove for the small problem
    node* new_head=reverse3(head->next);
    //as per original ll
    node* front=head->next;

    //as per ll is come as reversed
    front->next=head;
    head->next=NULL;
    return new_head;
 }


 int main(){
    node* a=new node(1);
    a->next=new node(2);
    a->next->next=new node(3);
    a=reverse1(a);
    print(a);
    cout<<endl;
    a=reverse2(a);
    print(a);
    cout<<endl;
    a=reverse3(a);
    print(a);

 }