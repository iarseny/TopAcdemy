#include <iostream>

class Point {
 private:
    int x, y;

 public:
    Point() : Point(0, 0) {}

    Point(const Point &other) : Point(other.x, other.y) {}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point &operator=(const Point &other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    Point operator+(int val) const {
        return Point(this->x + val, this->y + val);
    }
    Point operator+(const Point &other) const {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    void print() {
        std::cout << "[" << this->x << ", " << this->y << "]\n";
    }

    int getX() const {
        return this->x;
    }
    int getY() const {
        return this->y;
    }

};

    std::ostream &operator<<(std::ostream &out, const Point& point) {
        out << "[" << point.getX() << ", " << point.getY() << "]";
        return out;
    }


template <typename T>
class Array {
 private:
    T* arr;
    int size;
    int cap;
    void back(T *arr,int size) {
        for (int w = this->size; w < this->size + size; w++) {
            this->arr[w] = arr[w - this->size];
        }

        this->size = this->size + size;
    }
 public:
    Array() {
        this->arr = nullptr;
        size = 0;
        cap = 0;
    }

    int getSize() {return this->size; }

    Array(const Array &other) : Array(other.arr, other.size) {}

    Array(const T* arr, int size) {
        this->cap = size * 2;
        this->arr = new T[this->cap];
        this->size = size;
        for (int i = 0; i < size; ++i) {
            this->arr[i] = arr[i];
        }
    }

    T &operator[](int index) {
        return this->arr[index];
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->arr[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    void add_back(T val) {
        if (this->size + 1 <= this->cap) {
            this->size++;
            this->arr[this->size - 1] = val;
        }
    }

    void delete_index(int index) {
        //delete [] this->arr[index];
        for (int i = index + 1; i < this->size; i++) {
            this->arr[i - 1] = this->arr[i];
        }

        this->size--;
    }

    ~Array() {
        delete [] this->arr;
    }

    void add_index(T vav,int index) {
        if (this->size + 1 <= this->cap) {


            for (int i = index; i < this->size - 1; i++) {
                this->arr[i + 1] = this->arr[i];

            }

            this->arr[index] = vav;

            this->size++;

        }
    }

    void plus_all(T val) {

        for (int i = 0; i < this->size; i++) {
            this->arr[i] = this->arr[i] + val;
        }

    }

    void minus_all(T val) {
        for (int i = 0; i < this->size; i++) {\
            this->arr[i] = this->arr[i] - val;
        }
    }
    
    void add_back(T *arr,int size) {
        if (this->size + size <= this->cap) {
            this->back(arr,size);
        } else {
            T *tmp = this->arr;
            int new_cap = this->cap;
            while(this->size + size > new_cap) {
                new_cap *= 2;
            }

            this->arr = new T[new_cap];

            this->cap = new_cap;

            for (int i = 0; i < this->size; i++) {
                this->arr[i] = tmp[i];
            }

            
            this->add_back(arr,size);
        }

    }
};

    template <typename T>
    std::ostream &operator<<(std::ostream &out, Array<T> array) {
        out << "[ ";
        for (int i = 0; i < array.getSize(); ++i) {
            out << array[i];
            if (i != array.getSize() - 1) {
                out << ", ";
            }
        }
        out << " ]";
        return out;
    }


template <typename T>
void print_any(const T &val) {
    std::cout << val + val << "\n";
}

int main()
{
    Point points[3] = {Point(1,2), Point(3, 6), Point(8, 56)};
    //int arr[5] { 1, 2, 3, 4, 5};

    Point test_point(5,6);

    Point test_point2(4,3);

    Point test_point3(1,1);

    Point test_point4(2,2);

    Point test_point_array[3] = {Point(2,2), Point(3, 6), Point(8, 56)};

    Array<Point> template_array(points, 3);
    std::cout << template_array << "\n";

    template_array.add_back(test_point);

    std::cout << template_array << "\n";

    template_array.delete_index(1);

    std::cout << template_array << "\n";

    template_array.add_index(test_point2,1);

    std::cout << template_array << "\n";

    template_array.plus_all(test_point3);

    std::cout << template_array << "\n";

    template_array.minus_all(test_point4);

    std::cout << template_array << std::endl;

    std::cout << std::endl;

    template_array.add_back(test_point_array,3);

    std::cout << template_array << std::endl;

}