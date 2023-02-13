#include <iostream>

namespace list_class {
    template<typename T>
    class List {
        int size = 0;
        struct Node {
            T val;
            Node *next;
        };

        Node *head = nullptr;

        public:
        List() {}

        std::string get_type() {
            return "list";
        }

        void add_to_begin(T val) {
            this->size++;
            Node *tmp = new Node{val,nullptr};
            tmp->next = this->head;

            this->head = tmp->next;
        }

        T operator[](int index) {
            Node *tmp = this->head;
            for (int i = 0; i < index; i++) {
                tmp = tmp->next;
            }

            return tmp->val;
        }

        int get_size() {
            return this->size;
        }
    };
}