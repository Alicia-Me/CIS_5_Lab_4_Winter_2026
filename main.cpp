#include <iostream>
#include <iomanip>
using namespace std;
//c++ read top to bottom so main is going to be at the bottom

//int calculateSum(const int arr[], int size) // const ref/ pointer

int calculateSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
//------------------------------------
//double getAverage(int sum, int size) // by value ---> sum/length

double getAverage(int sum, int size) {
    return sum / size;
}
//----------------------------------------------------
//void addBonus(int arr[], int size, int bonus = 5) // ref or pointer ? modifies original

void addBonus(int arr[], int size, int bonus = 5) {
    for (int i = 0; i < size; i++) {
        arr[i] += bonus;
    }
}
//----------------------------------------------------
//int findHighest(const int* arr, int size) // pointer, return value

int findHighest(const int* arr, int size) {
    int highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}
//------------------------------------------------------------
//int countPassed(const int arr[], int size) // const ref/pointer, >= 70

int countPassed(const int arr[], int size) {
    int pass = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 70) {
            pass++;
        }
    }
    return pass;
}

/*
In main():

Show original scores
Show sum & average
Add bonus ? show new scores
Show highest & number passed
*/

int main() {
    //1-d array
    int score[5] = { 65, 82, 90, 45, 78 };
    const int length = 5;

   	//Show original scores

    cout << "Original Scores: ";
    for (int i = 0; i < length; i++) {
        cout << score[i] << " ";
    }
  cout << endl;
    //---------------------------------------
    //Show sum & average
    //sum

    int sum = calculateSum(score, length);
    cout << "Sum: " << sum << endl;
       
    //avg
    double avg = getAverage(sum, length);
    cout << "Average: " << avg << endl;

    //-------------------------------------------
    //Add bonus ? show new scores
    //old score will get a bonus of 5
    // 65, 82, 90, 45, 78 ----> 70, 87, 95. 50. 83

    addBonus(score, length);
    cout << "New Scores: ";
    for (int i = 0; i < length; i++) {
        cout << score[i] << " ";
    }
    cout << endl;
//------------------------------------------------------
//Show highest & number passed
    //just print
  
    //high
    cout << "Highest score: " << findHighest(score, length) << endl;
 
   //low
    cout << "Students passed with 70 or better: " << countPassed(score, length) << endl;

    return 0;
}

/*
What stays unchanged when using pass by value?
 variable stays the same because the function only gets a copy

double getAverage(int sum, int size) {
    sum = 0;       
    return sum / size;
}
//basically still 360 and nothing chnages in here when finding the avg
-------------------------------------------------------------------

How does pass by reference change the original array?
The function works with the original array, so any changes affect the actual data.

void addBonus(int arr[], int size, int bonus = 5) {
    for (int i = 0; i < size; i++) {
        arr[i] += bonus;  
    }
}
------------------------------------------------------------------

Why use const with pointers/references when reading only
prevents any changes in the function specifcialy when the fucntion only wants to read the data. Cant modify


int findHighest(const int* arr, int size) {
    int highest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    return highest;
}

*/