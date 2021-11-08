#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <iostream>
#include "employee.h"

using namespace std;

void login() {
    string username;
    while (1) {
        cout << "Please enter username: ";
        cin >> username;
        if (username == "CS") {
            CS();
        }
        else if (username == "SCS") {
            SCS();
        }
        else if (username == "FM") {
            FM();
        }
        else if (username == "AM") {
            AM();
        }
        else if (username == "PM" || username == "SM") {
            PMSM();
        }
        else if (username == "Chef") {
            Subteam("Chef");
        }
        else if (username == "Decoration") {
            Subteam("Decoration");
        }
        else if (username == "HR"){
            HR();
        }
        else {
            cout << "Wrong username! Please try again!" << endl;
        }
        return;
    }
}
 
#endif