#include <iostream>
#include <limits>

template <class T1, class T2>
auto add(T1 a, T2 b){
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
auto sub(T1 a, T2 b){
    return a - b;
}

int main(){
    double a, b;
    char oper;
    bool success = false;
    do{
    std::cout << "Enter the example:" << std::endl;
    std::cin >> a >> oper >> b;
        if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    continue;
        }
        if (oper == '+'){
            std::cout << add(a, b) << std::endl;
            success = true;
        }
        else if (oper == '-'){
            std::cout << sub(a, b) << std::endl;
            success = true;
        }
        else if (oper == '*'){
            std::cout << mult(a, b) << std::endl;
            success = true;
        }
        else if (oper == '/'){
            if (b == 0){
                std::cout << "error. a number cannot be divided by zero" << std::endl;
                continue;
            }
            else std::cout << div(a, b) << std::endl;
            success = true;
        }
    } while(!success);
    std::cin.get();
    return 0;
    }
