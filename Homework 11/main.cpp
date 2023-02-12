#include <iostream>

template<typename T>
class List
{
    struct Node {
        T val;
        Node *next;
    };

    Node *head = nullptr;

public:
    List() {}

    void AddToTail(T d)
    {
        if(head == nullptr)
            head = new Node{d,nullptr};
        else
        {
            Node *tmp = head;

            while(tmp->next != nullptr)
                tmp = tmp->next;

            tmp->next = new Node{d,nullptr};
        }
    }

    void AddToHead(T el) {
        Node *tmp = new Node{el,head};
        this->head = tmp;

    }

    void DeleteFromHead() {
        this->head = this->head->next;
    }

    void DeleteAll() {
        this->head = nullptr;
    }

    void DeleteTail() {
        Node *last = this->head;

        while (last->next->next != nullptr) {
            last = last->next;
        }

        last->next = nullptr;
    }

    void Show()
    {
        Node *current = head;

        while(current != nullptr)
        {
            std::cout << current->val << std::endl;
            current = current->next;
        }
    }
};

int main()
{
    List<int> list;

    list.AddToTail(5);
    list.AddToTail(11);

    list.AddToHead(8);
    list.AddToHead(99);

    list.DeleteFromHead();

    list.DeleteTail();

    list.Show();

    list.DeleteAll();

    return 0;
}