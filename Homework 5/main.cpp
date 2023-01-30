#include <iostream>

class Book {
    public:
    std::string name;
    std::string place;
    std::string auther;
    int year;
    int n;
    int size = 1;

    Book *books;

    bool collection = false;

    public:

    Book() : Book("Undefined","Undefined","Undefined",2009,70) {}

    Book(const Book &book) {
        if (book.collection == false) {
            this->collection = true;
            books = new Book[this->size];
            books[this->size - 1] = book;
        }

    }

    Book(std::string name,std::string place,std::string auther,int year,int n) {
        this->name = name;
        this->place = place;
        this->auther = auther;
        this->year = year;
        this->n = n;
    }

    void authers(std::string auther) {
        for (int i  = 0; i < this->size; i++) {
            //std::cout << this->books[i].name;
            if (this->books[i].auther == auther) {
                std::cout << (this->books[i].name) << std::endl;
            }
        }
    }

    void places(std::string place) {
        for (int i  = 0; i < this->size; i++) {
            std::cout << this->books[i].name;
        }
    }

    void years(int year) {
        for (int i  = 0; i < this->size; i++) {
            //std::cout << this->books[i].name;
            if ((this->books[i].year) < year) {
                std::cout << (this->books[i].name) << std::endl;
            }
        }
    }

    void add(const Book &book) {
        this->size++;
        Book *tmp = this->books;
        //delete [] this->books;
        this->books = new Book[this->size];


        for (int i = 0; i < this->size - 1 ; i++) {
            this->books[i] = tmp[i];
        }

        this->books[this->size - 1] = book;

        delete [] tmp;
    }

    ~Book() {
    }
};

int main() {
    Book book("chex","ккк","ввв",666,222);

    Book books(book);
    Book book2;


    books.authers("ввв");
    books.places("ккк");

    books.add(book2);

    std::cout << std::endl;

    books.years(4444);


    return 0;
};