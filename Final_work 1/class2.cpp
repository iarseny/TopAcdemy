#include <iostream>
#include <stdlib.h>

namespace class_algoritm {

    int comp1 (const void * a, const void * b)
    {
    return ( *(int*)a - *(int*)b );
    }
    template<typename T>
    class Algoritm {
        public:

        Algoritm() {}

        void print(T array) {
            if (array.get_type() == "array") {
                for (int i = 0; i < array.get_size(); i++) {
                    std::cout << array[i] << " ";
                }

                std::cout << std::endl;
            
            } else {
                
            }
            
        }

        void middle(T arr) {
            double sum = 0;
            for (int i = 0; i < arr.get_size(); i++) {
                sum += arr[i];
            }

            std::cout << std::endl << sum / arr.get_size();
        }

        void max(T arr) {
            int max = arr[0];

            for (int i = 1; i < arr.get_size(); i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }

            std::cout << std::endl << max;
        }

        void min(T arr) {
            int min = arr[0];

            for (int i = 1; i < arr.get_size(); i++) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }

            std::cout << std::endl << min;
        }

        void median(T arr) {
            if (arr.get_size() % 2 == 1) {
                std::cout << std::endl << arr[arr.get_size() / 2];
            } else {
                std::cout << std::endl << (arr[arr.get_size() / 2] + arr[arr.get_size() / 2 - 1]) / 2;
            }
        }

        void sort(T arr) {
            int *new_array = new int[arr.get_size()];

            for (int i = 0; i < arr.get_size(); i++) {
                new_array[i] = arr[i];
            }

            qsort (new_array, arr.get_size(), sizeof(int), comp1);

            for (int i = 0; i < arr.get_size(); i++) {
                arr.set_index(i,new_array[i]);
            }
        }


    };
}
