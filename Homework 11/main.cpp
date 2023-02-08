#include <iostream>

template<typename T>
class Task {
    struct Lists {
        Lists *next;
        T val;
    };

    Lists *head;

    public:

    Task() {
        this->head = new Lists();
    }

    void print() {
        Lists *tmp = this->head;
        while (tmp->next != nullptr) {
            std::cout << tmp->val << std::endl;
            tmp = tmp->next;
        }
    }

    void AddToHead(T el) {
        Lists *tmp = this->head;
        Lists *tmp2 = new Lists();
        tmp2->val = el;

        tmp2->next = tmp;

        this->head = tmp2;
    }

    void AddToTail

    ~Task() {
        delete [] this->head;
    }

};

int main() {

    Task<int> task;

    task.AddToHead(10);

    task.print();

    return 0;
}