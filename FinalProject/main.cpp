#include <iostream>
#include <vector>
#include <string>
#include "login.h"
#include "employee.h"
#include "database.h"

using namespace std;

extern vector<ClientRequest *> CR;
extern vector<EventPlan *> EP;
extern vector<FinancialRequest *> FR;
extern vector<HRRequest *> HRR;

int main() {
    string input1;

    while (1) {
        cout << "Please choose a function:" << endl;
        cout << "Login    Exit" << endl;
        cin >> input1;
        if(input1 == "Exit") {
            for (auto i : CR) {
                delete i;
            }
            for (auto i : EP) {
                delete i;
            }
            for (auto i : FR) {
                delete i;
            }
            for (auto i : HRR) {
                delete i;
            }
            cout << "You have exited the system!" << endl;
            return 0;
        }
        else if (input1 == "Login") {
            login();
        }
        else {
            cout << "Wrong function! Please try again" << endl;
        }
    }
    return 0;
}