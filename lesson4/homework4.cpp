#include <iostream>
#include <string>

class User {
    std::string name;
    int age;
    int *array_o;
    int size_arr;
    int cap; // size * 2
    int mark;

    public:
    User() {
        std::cout << "Input name: ";
        std::cin >> this->name;
        std::cout << "Input age: ";
        std::cin >> this->age;
    }
    User(const User &other) {

        this->array_o = new int[other.size_arr];
        for (int i = 0; i < this->size_arr; ++i) {
            this->array_o[i] = i;
        }
        this->size_arr = other.size_arr;
        this->cap = this->size_arr * 2;
        this->age = other.age; 

    }
    User(std::string name, int age, int *arr, int size,int mark) {
        this->name = name;
        this->age = age;
        this->array_o = arr;
        this->size_arr = size;
        this->cap = this->size_arr * 2;
    }

    void print_data() {
        for (int i = 0; i < this->size_arr;i++) {
            std::cout << this->array_o[i] << "  ";
        }

        std::cout << std::endl;
        
    }

    std::string get_name() {
        return this->name;
    }

    void print_avg_arr() {
        int sum = 0;

        for (int i = 0; i < this->size_arr; i++) {
            sum += this->array_o[i];
        }

        std::cout << sum / this->size_arr << std::endl;
    }

    User &operator+(int val) {
        this->size_arr++;
        int *tmp = this->array_o;
        this->array_o = new int[this->size_arr];
        for (int i = 0; i < this->size_arr - 1; i++) {
            this->array_o[i] = tmp[i];
        }

        this->array_o[this->size_arr - 1] = val;

        return *this;
    }
    User &operator-(int index) {
        this->size_arr--;
        int *tmp = this->array_o;

        this->array_o = new int[this->size_arr];

        for (int i = 0; i < index; i++) {
            this->array_o[i] = tmp[i];
        }

        for (int w = index + 1; w < this->size_arr + 1; w++) {
            this->array_o[w - 1] = tmp[w];
        }

        return *this;
        
    }

    std::string getName() { return this->name; }
    int getAge() { return this->age; }

    void setName(std::string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
};


class Data{
    User *users;
    int size;

    public:
    Data() : Data(1) {}
    Data(const Data &other) {
        this->users = new User[other.size];
        this->size = other.size;
        for (int i = 0; i < this->size; ++i) {
            this->users[i].setName(other.users[i].getName());
            this->users[i].setAge(other.users[i].getAge());
        }
    }
    explicit Data(int count_users) {
        this->users = new User[count_users];
        this->size = count_users;
    }

    void print() {
        for (int i = 0; i < this->size; ++i) {
            this->users[i].print_data();
        }

    }

    void print_users() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->users[i].get_name() << "  ";
        }

        std::cout << std::endl;
    }

    Data &operator+(User &user){
        this->size++;
        User *tmp = this->users;
        delete [] users;
        users = new User[this->size];

        for (int i = 0; i < this->size - 1; i++) {
            users[i] = tmp[i];
        }

        users[this->size - 1] = user;

        return *this;
    }

    ~Data() {
        delete [] this->users;
    }
};


int main()
{
    int arr[3] = {1,2,3};

    User michail("Go",89,arr,3,4);

    michail.print_avg_arr();

    std::cout << std::endl;

    michail + 9 + 8;

    michail - 1;

    michail.print_data();


    Data data;

    data + michail;

    std::cout << std::endl;

    data.print_users();



    
    return 0;
}