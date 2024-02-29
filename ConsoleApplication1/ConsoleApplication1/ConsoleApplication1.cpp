#include <iostream>
#include <iomanip>
#include <time.h>
#include <climits>
const int MAX_SIZE = 100; 

int countColumnsWithZero(int matrix[MAX_SIZE][MAX_SIZE], int k, int n) {
    int count = 0;

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j] == 0) {
                count++;
                break;
            }
        }
    }

    return count;
}

void findRowWithLongestSeries(int matrix[MAX_SIZE][MAX_SIZE], int k, int n) {
    int maxSeriesRow = -1;
    int maxSeriesLength = 0;

    for (int i = 0; i < k; ++i) {
        int currentSeriesLength = 1;

        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == matrix[i][j - 1]) {
                currentSeriesLength++;
            }
            else {
                currentSeriesLength = 1;
            }

            if (currentSeriesLength > maxSeriesLength) {
                maxSeriesLength = currentSeriesLength;
                maxSeriesRow = i;
            }
        }
    }

    if (maxSeriesRow != -1) {
        std::cout << "Row number with the largest series of identical elements: " << maxSeriesRow + 1 << std::endl;
    }
    else {
        std::cout << "The matrix does not contain a series of identical elements." << std::endl;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int k, n;


    std::cout << "k: ";
    std::cin >> k;

    std::cout << "n: ";
    std::cin >> n;


    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }


    std::cout << "Count col with 0: "
        << countColumnsWithZero(matrix, k, n) << std::endl;

    findRowWithLongestSeries(matrix, k, n);

    return 0;
}