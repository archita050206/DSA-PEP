

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = nullptr;
        }
    };



Node *removeLoop(Node *head)
{
    if (!head)
        return nullptr;
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            Node *t = slow;
            while (t && t->next != slow)
            {
                t = t->next;
            }
            if (t->next)
                t->next = nullptr;
            break;
        }
    }
    return head;
}