#include "data_stat.h"
double max(double *data, int n) {
    double max = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
double min(double *data, int n) {
    double min = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}
double variance(double *data, int n) {
    double mean_v = mean(data, n);
    double meanForSquares = 0;
    double variance;
    for (int i = 0; i < n; i++) {
        meanForSquares += data[i] * data[i];
    }
    meanForSquares = meanForSquares / n;
    variance = meanForSquares - mean_v * mean_v;
    return variance;
}
