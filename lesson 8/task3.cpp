#include <iostream>
namespace q {
    class Point {
    private:
        int x, y;

    public:
        Point() : Point(0, 0) {}

        Point(int x, int y) {
            this->x = x;
            this->y = y;
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

        void setX(int other) {
            this->x = other;
        }

        void setY(int other) {
            this->y = other;
        }

    };
}