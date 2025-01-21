// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;

class Node{
    public:
    string name;
    int roll;
    int sem;
    double cgpa;
    double marks;
    Node *next;
    

    
    Node(string name, int roll, int sem, double gpa, double marks){
        this->name=name;
        this->roll=roll;
        this->sem=sem;
        cgpa=gpa;
        this->marks=marks;
        next=NULL;    
    }
    
    
};

class Queue{
    private:
    Node *front, *rear;
    int count;
    int maxSize;
    
    public:
    
    Queue(int max){
        count =0;
        maxSize=max;
        front=rear=NULL;
    }
    
    bool isFull(){
        if(count==maxSize){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isEmpty(){
        if(count==0){
            return true;
        }
        else{
            return false;
        }
    }
    
    void Enqueue(string name, int roll, int sem, double gpa, double mark){
    if(isFull()){
        cout << "Queue is full. Cannot add more students.\n";
        return;
    }
    
        Node *newNode=new Node(name, roll, sem, gpa, mark);
    if(isEmpty()){
        front =rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
    count++;
  
}

    void Dequeue(){
        
        if(isEmpty()){
            return;
        }
        
        Node *curr=front;
        front=front->next;
        delete curr;
        count--;
    
        if (isEmpty()) {
            rear = NULL;
        }
        
    }
    
    
  
  void sort(){
      cout<<"\nAfter Sorting w.r.t to CGPA:\n";
      
      for(Node* i=front;i!=NULL;i=i->next){
          for(Node* j=i->next;j!=NULL;j=j->next){
              if(i==j){
                  return;
              }
              if(i->cgpa<j->cgpa){
                    swap(i->name, j->name);
                    swap(i->roll, j->roll);
                    swap(i->sem, j->sem);
                    swap(i->cgpa, j->cgpa);
                    swap(i->marks, j->marks);
              }
          }
      }
  }
  
  void print(){
      Node *curr=front;
      while(curr!=NULL){
         cout<<"Student: "<<"| Name: "<<curr->name <<"| CGPA: "<<curr->cgpa<<"| Semester: "<<curr->sem<<"| Marks: "<<curr->marks<<endl;
         curr=curr->next;
      }
  }
  
void search(int rollNum){
    Node *curr=front;
    
    while(curr!=NULL){
        if(curr->roll==rollNum){
            cout<<"Found: "<<rollNum<<" Name: "<<curr->name <<"| CGPA: "<<curr->cgpa<<"| Semester: "<<curr->sem<<"| Marks: "<<curr->marks<<endl;
            return;
        }
        curr=curr->next;
    }
}
    
};


int main() {
   Queue Q1(10);
   
Q1.Enqueue("Waleed", 0566, 3, 3.7,70);
Q1.Enqueue("Ahmed", 3921, 1, 2.7,50);
Q1.Enqueue("Ali", 8757, 5, 3.9,99);

Q1.print();

Q1.sort();

Q1.print();

    return 0;
}