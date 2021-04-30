#include <iostream>
#include <typeinfo>

using namespace std;

bool in_array(const char store[], const int storeSize, const char query) {
    for (size_t i=0; i<storeSize; ++i) {
        if (store[i] == query) {
            return true;
        }
    }
    return false;
}

void calculator(){
    float firstNum, secondNum, result = 0;
    char op;
    char operators[] = {'+', '-', '*', '/'};
    cout << "Write your first number" << endl;
    cin >> firstNum;
    if(cin.fail()){
        cout << "I WAS ASKING FOR A NUMBER" << endl;
        return;
    }
    cout << "Write your operator" << endl;
    cin >> op;
    if(cin.fail() || !in_array(operators, (sizeof(operators)/sizeof(*operators)), op)){
        cout << "I WAS ASKING FOR AN OPERATOR" << endl;
        return;
    }
    cout << "Write your second number" << endl;
    cin >> secondNum;
    if(cin.fail()){
        cout << "I WAS ASKING FOR A NUMBER" << endl;
        return;
    }

    switch (op){
        case '+':
            result = firstNum + secondNum;
            break;
        case '-':
            result = firstNum - secondNum;
            break;
        case '*':
            result = firstNum * secondNum;
            break;
        case '/':
            result = firstNum / secondNum;
            break;
    }

    cout << "Result : " << result << endl;
}

int main() {
    calculator();
}