#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

template<typename T>
void insert_sorted(std::vector <T>& vec, T x) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (x <= *it) {
            vec.emplace(it, x);
            return;
        }
    }
}

template<typename T>
void print_vector(const std::vector <T>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) std::cout << *it << " ";

    std::cout << std::endl;
}

void task1() {
    std::vector <float> V = { 0.32, 1.403, 2.51, 7.23, 8, 9.611 };
    float insert = 3.72;

    std::cout << "TASK1\nInitial vector: \n";

    print_vector(V);
    insert_sorted(V, insert);

    std::cout << "\nInsert value: " << insert << std::endl << std::endl;
    std::cout << "Result vector: \n";

    print_vector(V);

    std::cout << "-----------------------\n";
}


void task2() {
    srand(time(NULL));

    int Sz = 100;
    float error = 0.0;

    std::vector <float> Vec_float;
    std::vector <int> Vec_int;

    std::cout << "\nTASK2\n";

    Vec_float.reserve(Sz);
    Vec_int.reserve(Sz);

    for (int i = 0; i < Sz; ++i) Vec_float.emplace_back(rand() % 100 + (float)(rand() % 100) / 100);
    for (int i = 0; i < Sz; ++i) Vec_int.emplace_back((int)Vec_float[i]);

    std::cout << "Float vector:\n";
    print_vector(Vec_float);


    std::cout << "\nInteger vector:\n";
    print_vector(Vec_int);

    for (int i = 0; i < Sz; ++i) error += pow(Vec_float[i] - Vec_int[i], 2);

    std::cout << std::endl << "Error = " << error << std::endl;

    std::cout << "-----------------------\n";
}

int main() {
    task1();
    task2();

    return 0;
}