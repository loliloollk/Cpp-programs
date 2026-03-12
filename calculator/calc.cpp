#include <iostream>
using namespace std;

template <class T1, class T2>
auto sum(T1 a, T2 b){
    return a + b;
}

template <class T1, class T2>
auto mult(T1 a, T2 b){
    return a * b;
}

template <class T1, class T2>
auto div(T1 a, T2 b){
    return a / b;
}

template <class T1, class T2>
auto del(T1 a, T2 b){
    return a - b;
}

int main(){
    double a, b;
    char oper;
    cout << "Enter the example:" << endl;
    cin >> a >> oper >> b;
        if (oper == '+'){
            cout << sum(a, b);
        }
        else if (oper == '-'){
            cout << del(a, b);
        }
        else if (oper == '*'){
            cout << mult(a, b);
        }
        else if (oper == '/'){
            cout << div(a, b);
        }
    cin.get();
    return 0;
}