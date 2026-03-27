#include <ios>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int main(){
    int stCount;
    cout << "Enter the number of students" << endl;
    cin >> stCount;
    vector<double> grades(stCount);

    for(int i = 0; i < stCount; i++){
        cout << "Enter the average grade for student " << i + 1 << endl;
        cin >> grades[i];
        if(cin.fail()){
            cout << "\n" << "Invalid input. Please enter a numerical grade." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
    }
        cout << "\n";
    }

    double sum = 0, maxGrade = grades[0], minGrade = grades[0];

    for(int i = 0; i < stCount; i++){
        sum += grades[i];
        if(grades[i] < minGrade) minGrade = grades[i];
        if(grades[i] > maxGrade) maxGrade = grades[i];
    }

    double classAverage = sum / grades.size();
    cout << "Class average grade is: " << classAverage << endl <<
    "The minimal grade is: " << minGrade << endl <<
    "The maximum grade is: " << maxGrade << endl;
    return 0;
}
