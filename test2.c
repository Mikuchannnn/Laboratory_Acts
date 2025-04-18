#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_process = N / size;

    int *local_matrix = (int *)malloc(rows_per_process * N * sizeof(int));
    int *result = NULL;

    if (rank == 0)
    {
        int matrix[N][N];
        int value = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                matrix[i][j] = value++;
            }
        }
        result = (int *)malloc(N * N * sizeof(int));
        MPI_Scatter(matrix, rows_per_process * N, MPI_INT,
                    local_matrix, rows_per_process * N, MPI_INT,
                    0, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Scatter(NULL, rows_per_process * N, MPI_INT,
                    local_matrix, rows_per_process * N, MPI_INT,
                    0, MPI_COMM_WORLD);
    }

    int *local_result = (int *)malloc(rows_per_process * N * sizeof(int));
    for (int i = 0; i < rows_per_process * N; i++)
    {
        local_result[i] = local_matrix[i];
    }

    MPI_Gather(local_result, rows_per_process * N, MPI_INT,
               result, rows_per_process * N, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Result Matrix:\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%2d ", result[i * N + j]);
            }
            printf("\n");
        }
        free(result);
    }

    free(local_matrix);
    free(local_result);
    MPI_Finalize();
    return 0;
}