#include <ios>
#include <iostream>
#include <limits>
using namespace std;
int main(){
    int stCount;
    cout << "Enter the number of students" << endl;
    cin >> stCount;
    if (stCount < 1) {
        cout << "No data provided." << endl;
        return 0;
    }

    double* arr = new double[stCount];

    for(int i = 0; i < stCount; i++){
        cout << "Enter the average grade for " << i + 1 << " student" << endl;
        cin >> arr[i];
        if(cin.fail()){
            cout << "\n" << "Invalid input. Please enter a numerical grade." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
    }
        cout << "\n";
    }

    double sum = 0, maxGrade = arr[0], minGrade = arr[0];

    for(int i = 0; i < stCount; i++){
        sum += arr[i];
        if(arr[i] < minGrade) minGrade = arr[i];
        if(arr[i] > maxGrade) maxGrade = arr[i];
    }
    delete[] arr;

    double classAverage = sum / stCount;
    cout << "Class average grade is: " << classAverage << endl <<
    "The minimal grade is: " << minGrade << endl <<
    "The max grade is: " << maxGrade << endl;
    return 0;
}
