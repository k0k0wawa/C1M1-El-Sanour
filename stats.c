#include "stats.h"

/**
 * @brief The main program which does some staics operations
 * 
 * @return 0 on success and 1 otherwise
 */
int main(void) {
	int arr[] = {0, 1, 2, 3, 5, 4};
	int len = 6;

	print_array(arr, len);
	print_statistics(arr, len);

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
