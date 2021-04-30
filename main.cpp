#include <iostream>
#include <typeinfo>
#include "entities/Player.h"
#include <chrono>
#include <thread>

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
            default: break;
    }

    cout << "Result : " << result << endl;
}

void battleGenerator(){
    Player minemobs("minemobs", 5, 20);
    Player jerome("jerome226", 2, 15);

    while(!jerome.isDead() && !minemobs.isDead()){
        cout << minemobs.getName() << " attack " << jerome.getName() << endl;
        jerome.damagePlayer(minemobs.getStrength());
        cout << jerome.getName() << " has now " << jerome.getHealth() << " ❤️" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        if(jerome.isDead()) break;
        cout << jerome.getName() << " attack " << minemobs.getName() << endl;
        minemobs.damagePlayer(jerome.getStrength());
        cout << minemobs.getName() << " has now " << minemobs.getHealth() << " ❤️" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    if(jerome.isDead()) {
        cout << minemobs.getName() << " won the fight" << endl;
    }else if(minemobs.isDead()){
        cout << jerome.getName() << " won the fight" << endl;
    }
}

int main() {
    battleGenerator();
    //calculator();
}