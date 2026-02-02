#include <iostream>
using namespace std;
int main (){
unsigned int x;
while (true){
cout << "Введите ширину: ";
cin >> x;
if (x > 0 && x < 30000){
break;
}
else{
    cout << "Недопустимое значение X" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
}
}
unsigned int y;
while (true){
cout << "Введите высоту: ";
cin >> y;
if (y > 0 && y < 30000){
break;
}
else{
    cout << "Недопустимое значение Y" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
}
}
char symbol;
cout << "Введите символ: ";
cin >> symbol;
cin.ignore(10000, '\n');
cout << "" << endl;
for (int i = 0; i < y; i++){
for (int j = 0; j < x; j++){
    cout << symbol;
}
cout << endl;
}
}