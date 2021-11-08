#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>

using namespace std;

class ClientRequest {
private:
    string ClientName;
    int ID;
    string Date;
    string Request;
    string Status;
    string Priority;
    string FMComment;
    string ClientBudget;
    string Phone;
    bool CSAccess;
    bool SCSAccess;
    bool FMAccess;
    bool AMAccess;
public:
    ClientRequest() {}
    ClientRequest(string ClientName, int ID, string Date, string Request, string Priority, string ClientBudget, string Phone) {
        this->ClientName = ClientName;
        this->ID = ID;
        this->Date = Date;
        this->Request = Request;
        this->Priority = Priority;
        this->Status = "Created";
        this->FMComment = "";
        this->ClientBudget = ClientBudget;
        this->CSAccess = true;
        this->SCSAccess = false;
        this->FMAccess = false;
        this->AMAccess = false;
        this->Phone = Phone;
    }
    void SendToSCS() {
        this->SCSAccess = true;
    }
    void SendToFM() {
        this->FMAccess = true;
    }
    void AddComment(string comment) {
        this->FMComment = comment;
    }
    void SendToAM() {
        this->AMAccess = true;
    }
    void ChangeStatus(string status) {
        this->Status = status;
    }
    bool getSCSAccess() {
        return this->SCSAccess;
    }
    bool getFMAccess() {
        return this->FMAccess;
    }
    bool getAMAccess() {
        return this->AMAccess;
    }
    string getClientName() {
        return this->ClientName;
    }
    string getDate() {
        return this->Date;
    }
    string getRequest() {
        return this->Request;
    }
    string getStatus() {
        return this->Status;
    }
    string getPriority() {
        return this->Priority;
    }
    string getClientBudget() {
        return this->ClientBudget;
    }
    string getFMComment() {
        return this->FMComment;
    }
    string getPhone() {
        return this->Phone;
    }
    int getID() {
        return this->ID;
    }
};

class EventPlan {
private:
    string ClientName;
    int ID;
    string Date;
    int Attendees;
    string ClientBudget;
    bool Decoration;
    bool Chef;
    string CommentAboutBudget;
    string Plan;

public:
    EventPlan() {}
    EventPlan(string ClientName, int ID, string Date, int Attendees, string ClientBudget) {
        this->ClientName = ClientName;
        this->ID = ID;
        this->Date = Date;
        this->Attendees = Attendees;
        this->ClientBudget = ClientBudget;
        this->Decoration = false;
        this->Chef = false;
        this->CommentAboutBudget = "";
        this->Plan = "";
    }
    void SendToDecoration() {
        Decoration = true;
    }
    void SendToChef() {
        Chef = true;
    }
    bool getDecoration() {
        return this->Decoration;
    }
    bool getChef() {
        return this->Chef;
    }
    void AddComment(string comment) {
        this->CommentAboutBudget += comment + " ";
    }
    void AddPlan(string plan) {
        this->Plan += plan + " ";
    }
    string getClientName() {
        return this->ClientName;
    }
    string getDate() {
        return this->Date;
    }
    string getComment() {
        return this->CommentAboutBudget;
    }
    string getPlan() {
        return this->Plan;
    }
    int getAttendees() {
        return this->Attendees;
    }
    string getBudget() {
        return this->ClientBudget;
    }
    int getID() {
        return this->ID;
    }
};

class FinancialRequest{
private:
    string Department;
    int ID;
    string RequestAmount;
    string Reason;
    bool FMAccess;
    string Status;

public:
    FinancialRequest() {}
    FinancialRequest(string Department, int ID, string RequestAmount, string Reason) {
        this->Department = Department;
        this->ID = ID;
        this->RequestAmount = RequestAmount;
        this->Reason = Reason;
        this->FMAccess = false;
        this->Status = "Created";
    }
    string getDepartment() {
        return this->Department;
    }
    int getID() {
        return this->ID;
    }
    string getRequestAmount() {
        return this->RequestAmount;
    }
    string getReason() {
        return this->Reason;
    }
    void sendFMAccess() {
        this->FMAccess = true;
    }
    bool getFMAccess() {
        return this->FMAccess;
    }
    void changeStatus(string Status) {
        this->Status = Status;
    }
    string getStatus() {
        return this->Status;
    }
};

class HRRequest{
private:
    string Department;
    string ContractType;
    string ExperienceYear;
    string JobTitle;
    string JobDescription;
    bool HRAccess;
    string Status;

public:
    HRRequest(){}
    HRRequest(string Department, string ContractType, string ExperienceYear, string JobTitle, string JobDescription) {
    this->Department = Department;
    this->ContractType = ContractType;
    this->ExperienceYear = ExperienceYear;
    this->JobTitle = JobTitle;
    this->JobDescription = JobDescription;
    this->HRAccess = false;
    this->Status = "Created";
    }    
    string getDepartment(){
        return this->Department;
    }
    string getContractType(){
        return this->ContractType;
    }
    string getExperienceYear(){
        return this->ExperienceYear;
    }
    string getJobTitle(){
        return this->JobTitle;
    }
    string getJobDescription(){
        return this->JobDescription;
    }
    void sendHRAccess(){
        this->HRAccess = true;
    }
    bool getHRAcces(){
        return this->HRAccess;
    }
    void changeStatus(string Status){
        this->Status = Status;
    }
    string getStatus(){
        return this->Status;
    }
};
#endif