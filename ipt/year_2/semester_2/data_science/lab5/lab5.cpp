// g++ -fopenmp -W -Wall -O2 -std=c++11 lab5.cpp

#include <omp.h>
#include <iostream>
#include <vector>
#include <ctime>

#define ui unsigned

using namespace std;

int main(){
    vector<double> vec1;
    vector<double> vec2;
    double result = 0;
    clock_t t1;

    vector<double> times;
    double average = 0;

    srand(time(0));
    for (ui i = 0; i < 1000000; ++i) // Заповнення першого вектора випадковими числами
    {
        vec1.push_back(rand() / 1000);
    }
    for (ui i = 0; i < 1000000; ++i) // Заповнення другого вектора випадковими числами
    {
        vec2.push_back(rand() / 1000);
    }

    for (int j = 0; j < 100; ++j)
    {
        t1 = clock();
        #pragma omp parallel for num_threads(16) schedule(guided, 62500)
        for (ui i = 0; i < 1000000; ++i) // Скалярний добуток векторів
        {
            result = result + (vec1[i] * vec2[i]);
        }
        t1 = clock() - t1;
        times.push_back(t1);
    }

    for (int j = 0; j < 100; ++j)
    {
        average = times[j] + average;
    }
    cout << average/100 << " mks" << endl;
    return 0;
}