/************************************************
** Author: Andrea Hayes
** Date: May 9, 2020
** Purpose: Sort names alphabetically by last name.
** Input: File 
** Processing: Selection Sort
** Output: Alphabatized names
*************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
void selectionSort(string [], int);
void swap(int&, int&);
int main() {

    const int NUM = 20;
    ifstream names;
    string people[NUM];

    names.open("../names.txt");
    if (!names) {
        cout << "Error Opening file.";
        return 1;
    }
    
    cout << "Unsorted Names: " << endl;
    for (int i = 0; i < NUM; i++) {
        getline(names, people[i]);
        cout << people[i] << " ";
        cout << endl;
   }
    cout << endl;

    selectionSort(people, NUM);

    cout << "Sorted names: " << endl;
    for (auto element : people) {
        cout << element << " ";
        cout << endl;
    }
    
    return 0;
}
void selectionSort(string people[], int size) {
    int minIndex;
    string minValue;

    for (int start= 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = people[start];
        for (int index = start + 1; index < size; index++) {
            if (people[index] < minValue) {
                minValue = people[index];
                minIndex = index;
            }
        }
        swap(people[minIndex], people[start]);
    }
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
