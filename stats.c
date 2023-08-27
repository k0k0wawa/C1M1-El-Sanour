#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/**
 * @brief The main program which does some staics operations
 * 
 * @return 0 on success and 1 otherwise
 */
int main(void) {
    int arr[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                     114, 88,   45,  76, 123,  87,  25,  23,
                     200, 122, 150, 90,   92,  87, 177, 244,
                     201,   6,  12,  60,   8,   2,   5,  67,
                       7,  87, 250, 230,  99,   3, 100,  90};

    print_array(arr, SIZE);
    print_statistics(arr, SIZE);
    print_array(arr, SIZE);

    return (0);
}


int print_statistics(int arr[], int len) {
    int median, max, min;
    float mean;

    median = find_median(arr, len);
    mean = find_mean(arr, len);
    max = find_maximum(arr, len);
    min = find_minimum(arr, len);

    printf("The statics are: \n");
    printf("The median is: %d\nThe mean is: %.2f\nThe max is: %d\nThe min is: %d\n", median, mean, max, min);
    printf("\n");
    return (0);
}


int print_array(int arr[], int len) {
    int i;

    printf("The array contents are: \n");
    for (i = 0; i < len; i++) {
	    printf("The element number %d = %d\n", i + 1, arr[i]);
    }
    printf("\n");

    return (0);
}


int find_median(int arr[], int len) {
    int i ,median;

    sort_array(arr, len);

    median = arr[(int)(len / 2)]; 
    return (median);
}


float find_mean(int arr[], int len) {
    int i;
    float mean, sum;

    sum = 0;

    for (i = 1; i < len; i++) {
	    sum += i; 
    }
    mean = (sum + 0.0) / (float)len ;

    return (mean);
}


int find_maximum(int arr[], int len) {
    int i ,max;
    max = arr[0];

    for (i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return (max);
}


int find_minimum(int arr[], int len) {
    int i ,min;
    min = arr[0];

    for (i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return (min);
}


int sort_array(int arr[], int len) {
    int i;
    int j;
    int temp;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
	    }
        }
    }

    return (0);
}
