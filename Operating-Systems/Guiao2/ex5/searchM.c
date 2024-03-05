#include "matrix.h"

int main(int argc, char *argv[]) {
    // generate random matrix
    int **matrix = createMatrix();

    // print matrix
    printMatrix(matrix);

    if (valueExists(matrix, 0) == 1) {
        printf("O valor existe...\n");
    } else {
        printf("O valor não existe...\n");
    }

    // free matrix
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}