#include <iostream>

class Worker {
    std::string name;
    std::string surname;
    int money;
    std::string dol;
    std::string otchestvo;
    int year;
    bool array = false;
    int size = 1;
    Worker *arrays;

    public:
    Worker(const Worker &worker) {
        this->arrays = new Worker[1];
        this->arrays[this->size - 1] = worker;
        this->array = true;
    }

    Worker() : Worker("Undefined","Undifined","Undefined",60000,2010,"Seller") {}

    Worker(std::string name,std::string surname,std::string otchestvo,int money,int year,std::string dol) {
        this->name = name;
        this->surname = surname;
        this->otchestvo = otchestvo;
        this->money = money;
        this->dol = dol;
    }

    void add(const Worker &worker) {
        this->size++;
        Worker *tmp = this->arrays;
        //delete [] this->books;
        this->arrays = new Worker[this->size];


        for (int i = 0; i < this->size - 1 ; i++) {
            this->arrays[i] = tmp[i];
        }

        this->arrays[this->size - 1] = worker;

        delete [] tmp;
    }

    void moneys(int money) {
        for (int i  = 0; i < this->size; i++) {
            if ((this->arrays[i].money) > money) {
                std::cout << (this->arrays[i].name) << std::endl;
            }
        }
    }

    void years(int year) {
        for (int i  = 0; i < this->size; i++) {
            if ((this->arrays[i].year) > year) {
                std::cout << (this->arrays[i].name) << std::endl;
            }
        }
    }

    void dols(std::string dol) {
        for (int i  = 0; i < this->size; i++) {
            if (this->arrays[i].dol == dol) {
                std::cout << (this->arrays[i].name) << std::endl;
            }
        }
    }


    ~Worker() {
        if (this->array) {
            delete [] this->arrays;
        }
    }
};


int main() {

    Worker worker;

    Worker workers(worker);

    workers.years(2003);

    return 0;
}