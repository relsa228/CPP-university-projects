#include <iostream>
#include <vector>
#include "gauss_module.h"
#include "gauss_module_omp.h"
#include "omp.h"

int main() {
    for (int n = 500; n < 2500; n += 500) {
        std::vector<std::vector<double> > matrix(n);
        for (int i = 0; i < n; ++i) {
            matrix[i].resize(n);
            for (int j = 0; j < n; ++j)
                matrix[i][j] = rand();
        }
        std::vector<double> column(n);
        for (int j = 0; j < n; ++j)
            column[j] = rand();

        //double start_time = omp_get_wtime();                              //based
        //std::vector<double> solution = gauss_solving(matrix, column, n);
        //std::cout << n << " " << omp_get_wtime() - start_time << std::endl;

        double start_time_omp = omp_get_wtime();                            //omp
        std::vector<double> solution_omp = gauss_solving_omp(matrix, column, n);
        std::cout << n << " " << omp_get_wtime() - start_time_omp << std::endl;
    }
}