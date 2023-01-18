class Array {
    int *arr;
    int size;
    int cap;

    public:
    explicit Array(int cap) {
        this->arr = new int[cap];
        this->cap = cap;
        size = 0;
    }

    void add_back() {

    }

};


int main() {
    Array array(15);

    array.add_back(1);
    array.add_back(2);
    array.add_back(3);
    array.add_back(4);
    array.add_back(5);
}