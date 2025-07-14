class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptrptr;
    }
};
class MyLinkedList
{
public:
    Node *head;
    MyLinkedList()
    {
        head = nullptrptr;
    }

    int get(int index)
    {
        if (!head || index < 0)
            return -1;

        int x = 0;
        Node *t = head;
        while (t)
        {
            x++;
            t = t->next;
        }
        if (index >= x)
            return -1;
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void addAtHead(int val)
    {
        Node *t = new Node(val);
        if (!head)
        {
            head = t;
            return;
        }
        t->next = head;
        head = t;
    }

    void addAtTail(int val)
    {
        Node *t = new Node(val);
        if (!head)
        {
            head = t;
            return;
        }
        Node *x = head;
        while (x->next)
        {
            x = x->next;
        }
        x->next = t;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *t = head;
        Node *n = new Node(val);

        for (int i = 0; i < (index - 1) && t; i++)
        {

            t = t->next;
        }
        if (!t)
            return;
        Node *y = t->next;
        n->next = t->next;
        t->next = n;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || !head)
            return;
        if (index == 0)
        {
            Node *t = head;
            head = head->next ? head->next : nullptrptr;
            delete t;
            return;
        }
        Node *t = head;
        for (int i = 0; i < (index - 1) && t; i++)
        {

            t = t->next;
        }
        if (!t || !t->next)
            return;
        Node *y = t->next;
        t->next = t->next->next ? t->next->next : nullptrptr;
        delete y;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */