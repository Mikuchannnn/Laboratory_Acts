#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
#define NUM_STATIONS 1000 // Simulating 1000 weather stations
#define NUM_DAYS 365      // Data for a year
int main()
{
    std::vector<std::vector<double>> temperatures(NUM_STATIONS,
                                                  std::vector<double>(NUM_DAYS));
// Initialize weather data with random temperatures (0°C to 40°C)
#pragma omp parallel for collapse(2)
    for (int i = 0; i < NUM_STATIONS; i++)
    {
        for (int j = 0; j < NUM_DAYS; j++)
        {
            temperatures[i][j] = (rand() % 4000) / 100.0; // Random values
        }
    }
    std::vector<double> avg_temps(NUM_STATIONS, 0.0);
    double start_time = omp_get_wtime(); // Start timer
// Parallel computation of average temperature for each station
#pragma omp parallel for
    for (int i = 0; i < NUM_STATIONS; i++)
    {
        double sum = 0;
        for (int j = 0; j < NUM_DAYS; j++)
        {
            sum += temperatures[i][j];
        }
        avg_temps[i] = sum / NUM_DAYS;
    }
    double end_time = omp_get_wtime(); // End timer
    // Display execution time
    std::cout << "Time taken for parallel processing: " << end_time - start_time << " seconds\n";
    return 0;
}