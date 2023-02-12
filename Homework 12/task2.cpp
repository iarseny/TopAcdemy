#include <iostream>
#include <list>
#include <algorithm>

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

    void clone(const List &list) {
        this->head = list.head;
    }

    Node *operator+(const List &list) {

        Node *tmp_node = list.head;

        if (this->size_now <= this->size) {
            Node *tmp = head;

            while(tmp->next != nullptr)
                tmp = tmp->next;

            tmp->next = tmp_node;

            this->size_now++;

            return this->head;
        } else {
            std::cout << "Размер маленький, увеличиваем его в 2 раза!";
            size *= 2;
            Node *tmp = head;

            while(tmp->next != nullptr)
                tmp = tmp->next;

            tmp->next = tmp_node;

            this->size_now++;

            return this->head;
        }

    }


    Node *operator*(const List &list) {
        std::list<int> list_res;
        Node *check = list.head;

        Node *tmp = head;

        while(tmp != nullptr) {
            if (std::find(list_res.begin(),list_res.end(),tmp->val) != list_res.end()) {
                list_res.push_back(tmp->val);
            }
            tmp = tmp->next;
        }

        Node *new_list = nullptr;
        Node *new_list_return = new_list;

        for (int i = 0; i < list_res.size(); i++) {
            new_list->val = list_res.front() + i;
            new_list->next = nullptr;
            new_list = new_list->next;
        }

        return new_list_return;
    }

};

int main() {

    List list;

    list.add_head(5);

    list.add_back(4);

    list.show();

    return 0;
}