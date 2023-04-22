#include "List.h"

List::List()
{

    Node* dummyHead = new Node(DUMMY_HEAD_ID, nullptr);

    setHead(dummyHead);
    setTail(dummyHead);
   
}

List::~List() 
{
    makeEmpty();
}

// getters:
Node* List::getHead()           const
{
    return head->getNext();
}
Node* List::getTail()           const
{
    return tail;
}
// setters:
void List::setHead(Node* _head)
{
    this->head = _head;
}
void List::setTail(Node* _tail)
{
    this->tail = _tail;
}

// methods:
bool List::isEmpty() const 
{
	return head == tail; // if dummy head is head and tail at the list.
}

void List::makeEmpty() 
{
    Node* temp = this->head;

    while (temp != nullptr)
    {
        this->head = this->head->getNext();
        delete temp;
        temp = this->head;
    }
}

void List::insertDataToList(int id, Node* next)
{
    Node* newNode = new Node(id, next);
    this->insertNodeToList(newNode);
}

void List::insertNodeToList(Node* node)
{

    Node* after = findNodeToAddAfter(node->getTownID());
    Node* before = after->getNext();

    if (before == nullptr) // add town to end list
    {
        this->tail->setNext(node);
        setTail(node);
    }
    else
    {
        after->setNext(node);
        node->setNext(before);
    }
    
}

Node* List::findNodeToAddAfter(int id)      const
{
    Node* after = this->head; // dummy head
    Node* before = after->getNext();

    while (before != nullptr && before->getTownID() < id)
    {
        after = before;
        before = before->getNext();
    }

    return after;
}