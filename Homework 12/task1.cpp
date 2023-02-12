#include <iostream>

class List {

    struct Node {
        int val;
        Node *next;
    };

    int size;
    int size_now = 0;

    Node *head = nullptr;

    public:

    List(int size) {
        this->size = size;
    }

    List() : List(5) {}

    void add_head(int val) {
        if (this->size_now <= this->size) {
            Node *new_node = new Node{val,head};
            this->head = new_node;
            this->size_now++;
        } else {
            std::cout << "Размер маленький, увеличиваем его в 2 раза!";
            size *= 2;
            this->add_head(val);
        }
    }

    void add_back(int d) {
        if (this->size_now <= this->size) {
            if (head == nullptr)
                head = new Node{d,nullptr};
            else
            {
                Node *tmp = head;

                while(tmp->next != nullptr)
                    tmp = tmp->next;

                tmp->next = new Node{d,nullptr};
            }

            this->size_now++;
        } else {
            std::cout << "Размер маленький, увеличиваем его в 2 раза!";
            size *= 2;
            this->add_head(d);
        }
    }

    void show() {
        Node *node = head;

        while (node != nullptr) {
            std::cout << node->val << std::endl;
            node = node->next;
        }
    }

};

int main() {

    List list;

    list.add_head(5);

    list.add_back(4);

    list.show();

    return 0;
}