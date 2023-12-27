#include <iostream>
using namespace std;
template<class T>
class Node{
public:
    T Data;
    Node<T>* pNext;
    Node(){
        pNext=nullptr;
        this->Data=T();
    }
    Node(T Data){
        pNext=nullptr;
        this->Data=Data;
    }
    ~Node(){
    ///Empty
    }
};///End of Node class
template<class T>
class stackList{
    public:
    Node<T>* Head;
    int listSize;
    stackList(){
        this->Head=nullptr;
        listSize=T();
    }
    void push(T Data){
    if(Head == nullptr){
            Head=new Node<T>(Data);
        }
    else if(Head != nullptr){
            listSize++;
            Node<T>* temp=Head;
            Head = new Node<T>(Data);
            Head->pNext=temp;
        }
    }

    T pop(){
        if(Head == nullptr){
                 throw runtime_error("Error: Attempting to pop from an empty stack");
        }
        else{
            listSize--;
            Node<T>* temp=Head;
            Head = Head->pNext;
            T poppedValue = temp->Data;
            delete temp;
            return poppedValue;
        }
    }
    void display(){
        Node<T>* temp=Head;
        if(temp == nullptr){
            cout<<"Empty"<<endl;
        }
        while(temp != nullptr){
                    cout<<temp->Data<<endl;
                    temp=temp->pNext;
            }
    }
    void clearStack(){
        Node<T>* temp=Head;
        while(temp != nullptr){
                    pop();
                    temp=temp->pNext;
            }

    }
    ~stackList(){
            this->clearStack();
    }
} ;///End of queue
template<class T>
class queueList{
    public:
    Node<T>* Head;
    Node<T>* Tail;
    int listSize;
    queueList(){
        this->Head=this->Tail=nullptr;
        listSize=T();
    }
    void InQueue(T Data){
    if(Head == nullptr){
            Tail=Head=new Node<T>(Data);
        }
    else if(Head != nullptr){
            listSize++;
            Node<T>* temp=Tail;
            Tail = new Node<T>(Data);
            temp->pNext=Tail;
        }
    }

    T deQueue(){
        if(Head == nullptr){
                 throw runtime_error("Error: Attempting to pop from an empty stack");
        }
        else{
            listSize--;
            Node<T>* temp=Head;
            Head = Head->pNext;
            T poppedValue = temp->Data;
            delete temp;
            return poppedValue;
        }
    }
    void display(){
        Node<T>* temp=Head;
        if(temp == nullptr){
            cout<<"Empty"<<endl;
        }
        while(temp != nullptr){
                    cout<<temp->Data<<endl;
                    temp=temp->pNext;
            }
    }
    void clearQueue(){
        Node<T>* temp=Head;
        while(temp != nullptr){
                    deQueue();
                    temp=temp->pNext;
            }

    }
    ~queueList(){
            this->clearQueue();
    }
} ;
int main() {
    stackList<int> myStack; // Creating an instance of stackList with int as the data type

    // Pushing elements onto the stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    // Displaying the stack
    cout << "Stack elements:" << endl;
    myStack.display();

    // Popping an element from the stack
    cout << "Popped element: " << myStack.pop() << endl;

    // Displaying the updated stack
    cout << "Updated stack elements:" << endl;
    myStack.display();

    // Clearing the stack
    myStack.clearStack();

    // Displaying the cleared stack
    cout << "Cleared stack elements:" << endl;
    myStack.display();

    // Creating an instance of queueList with int as the data type
    queueList<int> myQueue;

    // Enqueuing elements
    myQueue.InQueue(20);
    myQueue.InQueue(25);

    // Displaying the queue
    cout << "Queue elements:" << endl;
    myQueue.display();

    // Dequeuing an element
    cout << "Dequeued element: " << myQueue.deQueue() << endl;

    // Displaying the updated queue
    cout << "Updated queue elements:" << endl;
    myQueue.display();

    // Clearing the queue
    myQueue.clearQueue();

    // Displaying the cleared queue
    cout << "Cleared queue elements:" << endl;
    myQueue.display();

    return 0;
}

