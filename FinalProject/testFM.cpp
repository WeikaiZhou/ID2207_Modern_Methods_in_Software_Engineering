#include <vector>
#include <string>
#include <cassert>
#include "login.h"
#include "employee.h"
#include "database.h"

using namespace std;

int main() {
    vector<FinancialRequest *> FRTest;
    // Create
   
    FRTest.push_back(new FinancialRequest("Production",1,"100","extra flower"));
    FRTest.push_back(new FinancialRequest("Service",2,"200","extra food"));
    
    
    
    // Test
    
    assert(FRTest[0]->getDepartment() == "Production");
    assert(FRTest[0]->getID() == 1);
    assert(FRTest[0]->getRequestAmount() == "100");
    assert(FRTest[0]->getReason() == "extra flower");
    assert(FRTest[0]->getFMAccess() == false );
    assert(FRTest[0]->getStatus() == "Created");
    
    assert(FRTest[1]->getDepartment() == "Service");
    assert(FRTest[1]->getID() == 2);
    assert(FRTest[1]->getRequestAmount() == "200");
    assert(FRTest[1]->getReason() == "extra food");
    assert(FRTest[1]->getFMAccess() ==  false );
    assert(FRTest[1]->getStatus() == "Created");
    // Send to FM
    
    FRTest[0]->sendFMAccess();
    assert(FRTest[0]->getFMAccess() == true);
    assert(FRTest[1]->getFMAccess() == false);
    // Change status
    FRTest[0]->changeStatus("test");

    // Test
    assert(FRTest[0]->getStatus() == "test");
    assert(FRTest[1]->getStatus() == "Created");


    // Test
    assert(FRTest[0]->getFMAccess() == true);
    assert(FRTest[1]->getFMAccess() == false);

  

    for (auto i : FRTest) {
        delete i;
    }

    return 0;
}
