#include <stdio.h>
#include <stdlib.h>

/*approach: take the k nearest neighbors, and for 
each neighbor check if that neoghbor increased or decreased from the previous
day. use the majority of the k nearest neighbors to determine 
whether or not to return an increase or a decrease in the stock market */

int data_size = 30000;


float* getDataArray(char* filename);
int* getRiseAndFall(float* data, int arrlen);
int KNNPredictCurrentDay(int* outcomes, int k, int currentDay);
int getCurrentDay(float* arr);
int KNNtrain(int* outcomes, float* data);
int getcurrentDay(int* arr);

int main(int argc, char** argv){
    float* data = getDataArray("data.txt");
    int* binaryOutcomes = getRiseAndFall(data, data_size);
    int predictionAccuracies = KNNtrain(binaryOutcomes, data);
    printf("%d\n", predictionAccuracies);
    return 0;
}

float* getDataArray(char* filename){
    float* arr = malloc(sizeof(float) * 30000);
    FILE *fp;
    // Open the file for writing
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

     // Read integers from the file until the end of file is reached
    float num = 0.0;
    int i = 0;
    while (fscanf(fp, "%f", &num) == 1) {
        arr[i] = num;
        i++;
    }
    // Close the file
    fclose(fp);
    //return the malloced array
    return arr;
}

/* predict today outcome, whether it be rising or falling*/

int KNNPredictCurrentDay(int* outcomes, int k, int currentDay){
    int* count = malloc(sizeof(int) * 2); //for the number of 0's or 1's
    printf("starting outcome at index %d is %d\n", currentDay, outcomes[currentDay]);
    for(int i = currentDay; i > currentDay - k; i--){
        printf("outcome at index %d is %d\n", i, outcomes[i]);
        count[outcomes[i]]++;
    }
    if(count[0] > count[1]){
        return 0;
    }
    return 1;
}


/* get rise and fall is an algorithm to get the binary outcome (rise and fall, 1 or 0)
of each day from the first day in the dataset to today */

int* getRiseAndFall(float* data, int arrlen){
    int* riseAndFall = malloc(sizeof(int) * arrlen);
    for(int i = 1; i < arrlen; i++){
        if (data[i] != 0){
            if (data[i] > data[i - 1]){
                riseAndFall[i] = 1;
            }
            else{
                riseAndFall[i] = 0;
            }
        }
    }
    return riseAndFall;
}


/*to find the current day and the nearest values associated with it*/

int getCurrentDay(float* arr){
    for(int i = 0; i < data_size; i++){
        if(arr[i + 1] == 0){
            printf("the current day is %d\n", i);
            return i;
        }
    }
    return -1;
}

/* find the value of k that most accurately predicts the nearest neighbor */

int KNNtrain(int* outcomes, float* data){
    //we will try every k value from k == 1 to k == 20
    float* accuracy = malloc(sizeof(int) * 21);
    int currentDay = getCurrentDay(data);
    //printf("current day is %d\n", (currentDay));
    for(int k = 1; k < 21; k++){
        int correct = 0;
        for(int i = 1; i <= currentDay; i++){
            int downAndUp[2] = {0, 0};
            for(int j = i - 1; j >= (i - k) && j >= 0; j--){
                downAndUp[outcomes[j]]++;
            }
            if (downAndUp[0] > downAndUp[1] && outcomes[i] == 0 || downAndUp[1] > downAndUp[0] && outcomes[i] == 1){
                correct += 1;
            }
        }
        accuracy[k] = (float) correct / currentDay; // the accuracy of the current k neighbors is the number of correct guesses it made over the number of total days it guessed
    }
    int bestKVal = 0;
    float curmax = 0.0;
    for(int i = 2; i < 21; i++){
        if (accuracy[i] > curmax){
            curmax = accuracy[i];
            bestKVal = i;
        }
    }
    return bestKVal;
}