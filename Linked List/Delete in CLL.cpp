

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptrptr;
    }
};

Node *deleteNode(Node *head, int key)
{
    // Write your code here.
    if (!head)
        return nullptrptr;
    if (head->next == head && head->data == key)
    {
        delete head;
        return nullptrptr;
    }
    if (head->data == key)
    {
        Node *t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        Node *p = head;
        head = head->next;
        t->next = head;
        p->next = nullptrptr;
        delete p;
        return head;
    }
    Node *second = head;
    Node *first = head->next;
    while (first != head)
    {
        if (first->data == key)
        {
            second->next = first->next;
            first->next = nullptrptr;
            delete first;
            break;
        }
        first = first->next;
        second = second->next;
    }
    return head;
}