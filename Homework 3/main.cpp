#include <iostream>

using namespace std;


namespace funcs {
    unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
      if (a % b == 0)
        return b;
      if (b % a == 0)
        return a;
    
      if (a > b)
        return greatest_common_divisor(a%b, b);
      return greatest_common_divisor(a, b%a);
    }
    
    unsigned int least_common_multiple(unsigned int a, unsigned int b) {
      return (a*b)/greatest_common_divisor(a,b);
    }
    
}

namespace DROBI {
    class Drob {
        int chislitel = 1;
        int znamenatel = 1;
        
        public:
        Drob() {}
        
        Drob(int chisl, int znamenatel) {
            this->chislitel =  chisl;
            this->znamenatel = znamenatel;
        }
        
        void chisl(int chisl) {
            
            this->chislitel = chisl;
            
            cout << endl << "изменено" << endl;
            
        }
        
        void znam(int znamen) {
            this->znamenatel = znamen;
        }
        
        void print() {
            if (this->chislitel != 0) {
                cout << endl << this->chislitel << " / " << this->znamenatel;
            } else {
                cout << endl << "1";
            }
        }
        
        int get_znamen() {
            return this->znamenatel;
        }
        
        int get_chisl() {
            return this->chislitel;
        }
        
        Drob &operator+(Drob t) {
            
            int zna = funcs::least_common_multiple(this->znamenatel,t.get_znamen());
            
            int drob_1_chisl = (this->chislitel) * (zna / this->znamenatel);
            
            int drob_2_chisl = (t.get_chisl()) * (zna / t.get_znamen());
            
            int sum = drob_1_chisl + drob_2_chisl;
            
            int nod = funcs::greatest_common_divisor(sum,zna);
            
            sum /= nod;
            
            zna /= nod;
            
            this->chislitel = sum;
            this->znamenatel = zna;
            
            return *this;
        }
        
        Drob &operator*(Drob t) {
            int chisl = this->chislitel * t.get_chisl();
            int znam = this->znamenatel * t.get_znamen();
            
            int nod = funcs::greatest_common_divisor(chisl,znam);
            
            chisl /= nod;
            
            znam /= nod;
            
            this->chislitel = chisl;
            this->znamenatel = znam;
            
            return *this;
        
        }
        
        Drob &operator/(Drob t) {
            int chisl = this->chislitel * t.get_znamen();
            int znam = this->znamenatel * t.get_chisl();
            
            int nod = funcs::greatest_common_divisor(chisl,znam);
            
            chisl /= nod;
            
            znam /= nod;
            
            this->chislitel = chisl;
            this->znamenatel = znam;
            
            return *this;
        
        }
        
        Drob &operator-(Drob t) {
            
            int zna = funcs::least_common_multiple(this->znamenatel,t.get_znamen());
            
            int drob_1_chisl = (this->chislitel) * (zna / this->znamenatel);
            
            int drob_2_chisl = (t.get_chisl()) * (zna / t.get_znamen());
            
            int sum = drob_1_chisl - drob_2_chisl;
            
            int nod = funcs::greatest_common_divisor(sum,zna);
            
            sum /= nod;
            
            zna /= nod;
            
            this->chislitel = sum;
            this->znamenatel = zna;
            
            return *this;
        }
        
        
    };
}

int main()
{
    DROBI::Drob drob1(2,4);
    
    DROBI::Drob drob2(2,4);
    
    drob1 + drob2 - drob2;

    drob1.print();

    return 0;
}
