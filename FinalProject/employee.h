#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include "database.h"

using namespace std;

vector<ClientRequest *> CR;
vector<EventPlan *> EP;
vector<FinancialRequest *> FR;
vector<HRRequest *> HRR;

void CS() {
    string Name = "CS";
    string Password = "000";
    string input1;
    string input2;
    string ClientName;
    int ID;
    string Date;
    string Request;
    string Priority;
    string ClientBudget;
    string Phone;
    while (1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password) {
            cout << "Login successfully!" << endl;
            while (1) {
                cout << "Please choose a function:" << endl;
                cout << "CreateNewClientRequest    SendToSCS    Logout" << endl;
                cin >> input2;
                if (input2 == "CreateNewClientRequest") {
                    cout << "Please input ClientName: ";
                    cin >> ClientName;
                    cout << "Please input ClientPhoneNumber: ";
                    cin >> Phone;
                    cout << "Please input ID: ";
                    cin >> ID;
                    cout << "Please input Date: ";
                    cin >> Date;
                    cout << "Please input Request: ";
                    cin >> Request;
                    cout << "Please input Priority: ";
                    cin >> Priority;
                    cout<< "Please input ClientBudget: ";
                    cin >> ClientBudget;
                    CR.push_back(new ClientRequest(ClientName, ID, Date, Request, Priority, ClientBudget, Phone));
                    cout << "Create successfully!" << endl;
                }
                else if (input2 == "SendToSCS") {
                    CR[CR.size() - 1]->SendToSCS();
                    cout << "Sent to Senior Customer Service successfully!" << endl;
                }
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please Try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void SCS() {
    string Name = "SCS";
    string Password = "000";
    string input1;
    string input2;
    string input3;
    int idx;
    while (1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password) {
            cout << "Login successfully!" << endl;
            while (1) {
                cout << "Please choose a function: " << endl;
                cout << "View    Logout" << endl;
                cin >> input2;
                if (input2 == "View") {
                    for (int i = 0; i < CR.size(); ++i) {
                        if (CR[i]->getSCSAccess() == true) {
                            cout << "\n>>>Index: " << i + 1 
                                 << "\n>>>ClientName: " << CR[i]->getClientName() 
                                 << "\n>>>Date: " << CR[i]->getDate() 
                                 << "\n>>>Request: " << CR[i]->getRequest() 
                                 << "\n>>>Status: " << CR[i]->getStatus() 
                                 << "\n>>>Priority: " << CR[i]->getPriority() << endl;
                        }
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> idx;
                    while (1) {
                        if (CR[idx - 1]->getStatus() == "Approved by Administration Manager") {
                            cout << "The contact information is: " << CR[idx - 1]->getPhone() << ". You can arrange a meeting now!" << endl;
                            break;
                        }
                        else if (CR[idx - 1]->getStatus() == "Rejected by Administration Manager") {
                            cout << "The case has been terminated!" << endl;
                            break;
                        }
                        else {
                            cout << "Please choose a function: " << endl;
                            cout << "Approve   Reject" << endl;
                            cin >> input3;
                            if (input3 == "Approve") {
                                CR[idx - 1]->ChangeStatus("Approved by Senior Customer Service");
                                CR[idx - 1]->SendToFM();
                                cout << "The case has been approved and sent to Finical Manager automatically!" << endl;
                                break;
                            }
                            else if (input3 == "Reject") {
                                CR[idx - 1]->ChangeStatus("Rejected by Senior Customer Service");
                                cout << "The case has been terminated!" << endl;
                                break;
                            }
                            else {
                                cout << "Wrong function! Please Try again!" << endl;
                            }
                        }
                    }
                }
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void FM() {
    string Name = "FM";
    string Password = "000";
    string comment;
    int idx;
    string input1;
    string input2;
    string input3;

    while(1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password) {
            cout << "Login successfully!" << endl;
            while(1) {
                cout << "Please choose a function!" << endl;
                cout << "ViewRequest    ManageBudget    Logout" << endl;
                cin >> input2;
                if (input2 == "ViewRequest") {
                    for (int i = 0; i < CR.size(); ++i) {
                        if (CR[i]->getFMAccess() == true) {
                            cout << "\n>>>Index: " << i + 1
                                 << "\n>>>ClientName: " << CR[i]->getClientName()
                                 << "\n>>>Date: " << CR[i]->getDate()
                                 << "\n>>>Request: " << CR[i]->getRequest()
                                 << "\n>>>Status: " << CR[i]->getStatus()
                                 << "\n>>>Priority: " << CR[i]->getPriority()
                                 << "\n>>>ClientBudget: " << CR[i]->getClientBudget() << endl;
                        }
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> idx;
                    cout << "Please add comment about the budget: ";
                    cin >> comment;
                    CR[idx - 1]->AddComment(comment);
                    CR[idx - 1]->SendToAM();
                    CR[idx - 1]->ChangeStatus("Comment added by Financial Manager");
                    cout << "Added successfully! The case has been sent to Administration Manager automatically!" << endl;
                }
                else if (input2 == "ManageBudget") {
                    string Status;
                    for (int i = 0; i < FR.size(); ++i)
                    {
                        cout << "\n>>>Index: " << i + 1
                             << "\n>>>Department: " << FR[i]->getDepartment()
                             << "\n>>>ID: " << FR[i]->getID()
                             << "\n>>>RequestAmount: " << FR[i]->getRequestAmount()
                             << "\n>>>Reason: " << FR[i]->getReason()
                             << "\n>>>Status: " << FR[i]->getStatus() << endl;
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> idx;
                    cout << "Please update status: ";
                    cin >> Status;
                    FR[idx - 1]->changeStatus(Status);
                    cout << "Status change successfully!" << endl;
                }
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void AM() {
    string Name = "AM";
    string Password = "000";
    int idx;
    string input1;
    string input2;
    string input3;

    while (1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password) {
            cout << "Login successfully!" << endl;
            while(1) {
                cout << "Please choose a function:" << endl;
                cout << "ViewRequest    Logout" << endl;
                cin >> input2;
                if (input2 == "ViewRequest") {
                    for (int i = 0; i < CR.size(); ++i) {
                        if (CR[i]->getAMAccess() == true) {
                            cout << "\n>>>Index: " << i + 1
                                 << "\n>>>ClientName: " << CR[i]->getClientName()
                                 << "\n>>>Date: " << CR[i]->getDate()
                                 << "\n>>>Request: " << CR[i]->getRequest()
                                 << "\n>>>Status: " << CR[i]->getStatus()
                                 << "\n>>>Priority: " << CR[i]->getPriority()
                                 << "\n>>>ClientBudget: " << CR[i]->getClientBudget() 
                                 << "\n>>>FinancialManagerComment: " << CR[i]->getFMComment() << endl;
                        }
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> idx;
                    while (1) {
                        cout << "Please choose a function: " << endl;
                        cout << "Approve   Reject" << endl;
                        cin >> input3;
                        if (input3 == "Approve") {
                            CR[idx - 1]->ChangeStatus("Approved by Administration Manager");
                            cout << "The case has been approved!" << endl;
                            break;
                        }
                        else if (input3 == "Reject") {
                            CR[idx - 1]->ChangeStatus("Rejected by Administration Manager");
                            cout << "The case has been terminated!" << endl;
                            break;
                        }
                        else {
                            cout << "Wrong function! Please Try again!" << endl;
                        }
                    }
                }
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void PMSM() {
    string Name = "PMSM";
    string Password = "000";
    int idx;
    string input1;
    string input2;
    string input3;
    string input4;
    string input5;
    string ClientName;
    int ID;
    string Date;
    int Attendees;
    string ClientBudget;


    while (1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password) {
            cout << "Login successfully!" << endl;
            while(1) {
                cout << "Please choose a function!" << endl;
                cout << "ViewRequest    ManageEvent    ManageBudget    ManageHR    Logout" << endl;
                cin >> input2;
                if (input2 == "ViewRequest") {
                    for (int i = 0; i < CR.size(); ++i) {
                        if (CR[i]->getStatus() == "Approved by Administration Manager") {
                            cout << "\n>>>Index: " << i + 1
                                 << "\n>>>ClientName: " << CR[i]->getClientName()
                                 << "\n>>>ID: " << CR[i]->getID()
                                 << "\n>>>Date: " << CR[i]->getDate()
                                 << "\n>>>Request: " << CR[i]->getRequest()
                                 << "\n>>>Status: " << CR[i]->getStatus()
                                 << "\n>>>Priority: " << CR[i]->getPriority()
                                 << "\n>>>ClientBudget: " << CR[i]->getClientBudget() 
                                 << "\n>>>FinancialManagerComment: " << CR[i]->getFMComment() << endl;
                        }
                    }
                }
                else if (input2 == "ManageEvent") {
                    while (1) {
                        cout << "Please choose a function:\nCreateEvent    CheckEvent    Back" << endl;
                        cin >> input3;
                        if (input3 == "CreateEvent") {
                            cout << "Please input ClientName:";
                            cin >> ClientName;
                            cout << "Please input ID: ";
                            cin >> ID;
                            cout << "Please input Date: ";
                            cin >> Date;
                            cout << "Please input Attendees: ";
                            cin >> Attendees;
                            cout << "Please input Budget: ";
                            cin >> ClientBudget;
                            EP.push_back(new EventPlan(ClientName, ID, Date, Attendees, ClientBudget));
                            cout << "Create successfully!" << endl;
                            while (1) {
                                cout << "Please choose a sub-team to send. Or back."<<endl;
                                cout << "Decoration    Chef    Waitress    Photography    Music    Graphic    Network    Back" << endl;
                                cin >> input4;
                                if (input4 == "Decoration") {
                                    EP[EP.size() - 1]->SendToDecoration();
                                    cout << "Send successfully!" << endl;
                                }
                                else if (input4 == "Chef") {
                                    EP[EP.size() - 1]->SendToChef();
                                    cout << "Send successfully!" << endl;
                                }
                                else if (input4 == "Back") {
                                    cout<<"You are back now."<<endl;
                                    break;
                                }
                                else {
                                    cout << "Wrong function! Please try again!" << endl;
                                }
                            }
                        }
                        else if (input3 == "CheckEvent") {
                            for (int i = 0; i < EP.size(); ++i) {
                                cout << "\n>>>Index: " << i + 1
                                     << "\n>>>ClientName: " << EP[i]->getClientName()
                                     << "\n>>>ID: " << EP[i]->getID()
                                     << "\n>>>Date: " << EP[i]->getDate()
                                     << "\n>>>Attendees: " << EP[i]->getAttendees()
                                     << "\n>>>ClientBudget: " << EP[i]->getBudget()
                                     << "\n>>>CommentAboutBudget: " << EP[i]->getComment()
                                     << "\n>>>Plan: " << EP[i]->getPlan() <<endl;
                            }
                            while(1) {
                                cout << "Please choose an index to continue. Or Back." << endl;
                                cin >> input5;
                                if (isdigit(input5[0])) {
                                    while (1) {
                                        cout << "Please choose a sub-team to send. Or back."<<endl;
                                        cout << "Decoration    Chef    Waitress    Photography    Music    Graphic    Network    Back" << endl;
                                        cin >> input4;
                                        if (input4 == "Chef") {
                                            EP[EP.size() - 1]->SendToChef();
                                            cout << "Send successfully!" << endl;
                                        }
                                        else if (input4 == "Decoration") {
                                            EP[EP.size() - 1]->SendToDecoration();
                                            cout << "Send successfully!" << endl;
                                        }
                                        else if (input4 == "Back") {
                                            cout<<"You are back now."<<endl;
                                            break;
                                        }
                                        else {
                                            cout << "Wrong function! Please try again!" << endl;
                                        }
                                    }
                            
                                }
                                else if (input5 == "Back") {
                                    cout << "You are back now." << endl;
                                    break;
                                }
                                else {
                                    cout << "Wrong function. Please try again." << endl;
                                }
                            }
                        }
                        else if (input3 == "Back") {
                            cout << "You are back!" << endl;
                            break;
                        }
                        else {
                            cout << "Wrong function! Please try again!" << endl;
                        }
                    }
                }
                
                else if (input2 == "ManageBudget") {
                    string Department;
                    string RequestAmount;
                    string Reason;
                   
                    while(1){
                        cout<<"Please choose a function: " << endl;
                        cout << "CreateBudgetRequest    ViewBudgetRequest   Back" << endl;
                        cin >> input3;
                        if(input3 == "CreateBudgetRequest"){
                            cout << "Please input Department: ";
                            cin >> Department;
                            cout << "Please input ID: ";
                            cin >> ID;
                            cout << "Please input RequestAmount: ";
                            cin >> RequestAmount;
                            cout << "Please input Reason: ";
                            cin >> Reason;
                        
                            FR.push_back(new FinancialRequest(Department, ID, RequestAmount, Reason));
                            cout << "Create successfully! The case has been sent to FM automatically." << endl;
                        }
                        else if(input3 == "ViewBudgetRequest")
                        {
                            for (int i = 0; i < FR.size(); ++i) {
                                cout << "\n>>>Index: " << i + 1
                                     << "\n>>>Department: " << FR[i]->getDepartment()
                                     << "\n>>>ID: " << FR[i]->getID()
                                     << "\n>>>RequestAmount: " << FR[i]->getRequestAmount()
                                     << "\n>>>Reason: " << FR[i]->getReason()
                                     << "\n>>>Status: "<<FR[i]->getStatus()<<endl;
                            }
                        }
                        else if(input3 == "Back")
                        {
                            cout << "You are back!" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Wrong function! Please try again!" << endl;
                        }
                    }

                }
                else if (input2 == "ManageHR") {
                    string Department;
                    string ContractType;
                    string ExperienceYear;
                    string JobTitle;
                    string JobDescription;

                    while(1){
                        cout << "Please choose a function: " << endl;
                        cout << "CreateHRRequest    ViewHRRequest   Back" << endl;
                        cin >> input3;
                        if(input3 == "CreateHRRequest"){
                            cout << "Please input Department:";
                            cin >> Department; 
                            cout << "Please input ContractType: ";
                            cin >> ContractType;
                            cout << "Please input ExperienceYear: ";
                            cin >> ExperienceYear;
                            cout << "Please input JobTitle: ";
                            cin >> JobTitle;
                            cout << "Please input JobDescription: ";
                            cin >> JobDescription;


                            HRR.push_back(new HRRequest(Department, ContractType, ExperienceYear, JobTitle, JobDescription));
                            cout << "Create successfully! The case has been sent to HR automatically." << endl;
                        }
                        else if(input3 == "ViewHRRequest")
                        {
                            for (int i = 0; i < HRR.size(); ++i) {
                                cout << "\n>>>Index: " << i + 1
                                     << "\n>>>Department: " << HRR[i]->getDepartment()
                                     << "\n>>>ContractType: " << HRR[i]->getContractType()
                                     << "\n>>>ExperienceYear: " << HRR[i]->getExperienceYear()
                                     << "\n>>>JobTitle: " << HRR[i]->getJobTitle()
                                     << "\n>>>JobDescription: " << HRR[i]->getJobDescription()
                                     << "\n>>>HRStatus: " << HRR[i]->getStatus()<< endl;
                            }
                        }
                        else if(input3 == "Back")
                        {
                            cout << "You are back!" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Wrong function! Please try again!" << endl;
                        }
                    }

                }
                
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void Subteam(string teamtype) {
    string password = "000";
    string input1;
    string input2;
    string plan;
    string comment;
    int index;

    while (1) {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == password) {
            cout << "Login successfully!" << endl;
            while (1) {
                cout << "Please choose a function:" << endl;
                cout << "ViewEvent    Logout" << endl;
                cin >> input2;
                if (input2 == "ViewEvent") {
                    for (int i = 0; i < EP.size(); ++i) {
                        if ((teamtype == "Chef" && EP[i]->getChef()) || (teamtype == "Decoration" && EP[i]->getDecoration())) {
                            cout << "\n>>>Index: " << i + 1
                                 << "\n>>>ClientName: " << EP[i]->getClientName()
                                 << "\n>>>ID: " << EP[i]->getID()
                                 << "\n>>>Date: " << EP[i]->getDate()
                                 << "\n>>>Attendees: " << EP[i]->getAttendees()
                                 << "\n>>>ClientBudget: " << EP[i]->getBudget()
                                 << "\n>>>CommentAboutBudget: " << EP[i]->getComment()
                                 << "\n>>>Plan: " << EP[i]->getPlan() <<endl;
                        }
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> index;
                    while (1) {
                        cout<<"Please choose a function: "<<endl;
                        cout << "AddPlan    AddComment    Back" << endl;
                        cin >> input1;
                        if (input1 == "AddPlan") {
                            cout <<"Please input plan: ";
                            cin >> plan;
                            EP[index - 1]->AddPlan("\n   " + teamtype + ": " + plan);
                            cout << "Plan add successfully." << endl;
                        }
                        else if (input1 == "AddComment") {
                            cout <<"Please input comment: ";
                            cin >> comment;
                            EP[index - 1]->AddComment("\n   " + teamtype + ": " + comment);
                            cout << "Comment add successfully." << endl;
                        }
                        else if (input1 == "Back") {
                            cout<<"You are back now."<<endl;
                            break;
                        }
                        else {
                            cout << "Wrong function! Please try again!" << endl;
                        }
                    }
                }
                else if (input2 == "Logout") {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else {
                    cout << "Wrong function! Please Try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}

void HR() {
    string Name = "HR";
    string Password = "000";
    int idx;
    string input1;
    string input2;
    while(1)
    {
        cout << "Please input password: ";
        cin >> input1;
        if (input1 == Password)
        {
            cout << "Login successfully!" << endl;
            while (1)
            {
                cout << "Please choose a function!" << endl;
                cout << "ManageHR    Logout" << endl;
                cin >> input2;
                if (input2 == "ManageHR")
                {
                    string Status;
                    for (int i = 0; i < HRR.size(); ++i)
                    {
                        cout << "\n>>>Index: " << i + 1
                            << "\n>>>Department: " << HRR[i]->getDepartment()
                            << "\n>>>ContractType: " << HRR[i]->getContractType()
                            << "\n>>>ExperienceYear: " << HRR[i]->getExperienceYear()
                            << "\n>>>JobTitle: " << HRR[i]->getJobTitle()
                            << "\n>>>JobDescription: " << HRR[i]->getJobDescription()
                            << "\n>>>HRStatus: "<< HRR[i]->getStatus() << endl;
                            
                    }
                    cout << "Please choose an index to continue: ";
                    cin >> idx;
                    cout << "Please update status: ";
                    cin >> Status;
                    HRR[idx - 1]->changeStatus(Status);
                    cout << "Status change successfully!" << endl;
                }
                else if (input2 == "Logout")
                {
                    cout << "Logout successfully!" << endl;
                    return;
                }
                else
                {
                    cout << "Wrong function! Please try again!" << endl;
                }
            }
        }
        else {
            cout << "Wrong password! Please try again!" << endl;
        }
    }
}
#endif