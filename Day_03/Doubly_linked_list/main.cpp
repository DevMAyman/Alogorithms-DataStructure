#include <iostream>
using namespace std;
template <class T>
class Node{
    public:
    T Data;
    Node<T> * pNext;
    Node<T> * pPrev;
        Node(){
            Data=T();//Initialize with Default value
            pNext=pPrev=nullptr;
        }

        Node(T Data){
            this->Data=Data;
            pNext=pPrev=nullptr;
        }
        ~Node<T>(){
        }
};///End of Node class
template <class T>
class doublyLinkedList{
Node<T> * pHead;
Node<T> * pTail;
int listSize;
public:
    doublyLinkedList(){
        pHead=pTail=nullptr;
        listSize=0;
    }
    doublyLinkedList(doublyLinkedList &myList)
    {
        this->pHead=nullptr;
        this->pTail=nullptr;
        Node<T> * temp=myList.pHead;
        while(temp != nullptr){
            this->Add(temp->Data);
            temp=temp->pNext;
    }

}
    ///---------------------------------------------------Add Function----------------------------------------------------------------
    void Add(T Data){
    ///Add for first time
    if(pHead==nullptr){
        pHead=pTail=new Node<T>(Data);
    }

    ///Add at the end
    else{
        (*pTail).pNext=new Node<T>(Data);
        (*((*pTail).pNext)).pPrev=pTail;
         pTail=(*pTail).pNext;
    }
        listSize++;
}
void ClearList() {
    Node<T>* current = pHead;
    while (current != nullptr) {
        Node<T>* next = current->pNext;
        delete current;
        current = next;
    }
    pHead = pTail = nullptr;
    listSize = 0;
}

void Display(){
Node<T> * temp;
temp=this->pHead;
while(temp != nullptr){
    cout<<(temp->Data)<<endl;
    temp=temp->pNext;
}
}
int Search(T Data){
Node<T> * temp=this->pHead;
int mySize=0;
while(temp != nullptr){
    if(temp->Data==Data){
        return mySize;
    }
    else{
        temp=temp->pNext;
        mySize++;
    }
}
    return -1;
}
};///End of doublyLinkList class
int main()
{
    doublyLinkedList<int>* myList= new doublyLinkedList<int>();
    (*myList).Add(5);
    (*myList).Add(6);
    (*myList).Add(7);
    (*myList).Add(8);
    myList->Display();
    cout<<(myList->Search(6))<<endl;
    doublyLinkedList<int>* myList2=new doublyLinkedList<int>(*myList);
    return 0;
}
