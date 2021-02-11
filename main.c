#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define BILLION 1E9
#define SIZE 10000

void *freqElement(float *array) {
    float element = 0;
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        float tempElement = array[i];
        int tempCount = 0;
        for (int j = 0; j < SIZE; j++) {

            if (array[j] == tempElement) {
                tempCount++;
            }
        }
        if (tempCount > count) {
            element = tempElement;
            count = tempCount;
        }
    }
    printf("Most Frequently Occurred Value of the List: %.2f\nThe Occurrence Count of the Value (%.2f): %d times\n\n",
           element, count, element);


}

void *minValue(float *array) {
    int location = 0;
    for (int c = 1; c < SIZE; c++)
        if (array[c] < array[location])
            location = c;

    printf("Minimum Value of the List: %.2f\nThis is the %dth element of the list.\n\n", array[location], location);
}

void *maxValue(float *array) {
    int location = 0;
    for (int c = 1; c < SIZE; c++)
        if (array[c] > array[location])
            location = c;

    printf("Maximum Value of the List: %.2f\nThis is the %dth element of the list.\n\n", array[location], location);
}

void *squareOfSumOfValue(float *array) {

    float total = 0;
    for (int i = 0; i < SIZE; i++) {
        total = total + array[i];

    }
    float square = total * total;
    printf("Square of the sum of values in the list: %.2f\n\n", square);

}


void *meanAndStandardDeviation(float *array) {

    float total = 0;
    for (int i = 0; i < SIZE; i++) {
        total = total + array[i];

    }
    float averageOfList = total / SIZE;
    printf("Mean of the List Elements: %.2f\n", averageOfList);
    float tempArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        tempArray[i] = pow(array[i] - averageOfList, 2);
    }
    float totalTemp = 0;
    for (int i = 0; i < SIZE; i++) {
        totalTemp = totalTemp + tempArray[i];
    }
    float averageOfTempList = totalTemp / SIZE - 1;

    float sd = sqrt(averageOfTempList);
    printf("Standard Deviation of the List Elements: %.2f\n\n", sd);

}


int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));
    float randomNum;
    float a = 100.0;
    float arrayRandom[SIZE];
    for (int i = 0; i < SIZE; i++) {
        randomNum = ((float) rand() / (float) (RAND_MAX)) * a;
        arrayRandom[i] = randomNum;
        //printf("%.2f, %.2f \n", randomNum, arrayRandom[i]);
    }

    struct timespec requestStart, requestEnd;
    clock_gettime(CLOCK_REALTIME, &requestStart);
    printf("Operations have started and are in progress !\n\n--- Results ---\n\n");
    squareOfSumOfValue(arrayRandom);
    minValue(arrayRandom);
    maxValue(arrayRandom);
    freqElement(arrayRandom);
    meanAndStandardDeviation(arrayRandom);


    clock_gettime(CLOCK_REALTIME, &requestEnd);
    double accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    printf("Total execution time: %lf ms\n", accum);

    return 0;
}







