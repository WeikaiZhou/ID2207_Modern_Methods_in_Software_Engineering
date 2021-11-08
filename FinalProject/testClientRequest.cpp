#include <vector>
#include <string>
#include <cassert>
#include "login.h"
#include "employee.h"
#include "database.h"

using namespace std;

int main() {
    vector<ClientRequest *> CRTest;

    // Create request
    CRTest.push_back(new ClientRequest("Alice", 1, "1015", "a...b...c...", "high", "10", "1234567"));
    CRTest.push_back(new ClientRequest("Bob", 2, "1014", "A...B...C...", "Medium", "20", "12356"));

    // Test
    assert(CRTest[0]->getAMAccess() == false);
    assert(CRTest[0]->getClientBudget() == "1");
    assert(CRTest[0]->getClientName() == "Alice");
    assert(CRTest[0]->getDate() == "1015");
    assert(CRTest[0]->getFMAccess() == false);
    assert(CRTest[0]->getFMComment() == "");
    assert(CRTest[0]->getID() == 1);
    assert(CRTest[0]->getPhone() == "1234567");
    assert(CRTest[0]->getPriority() == "high");
    assert(CRTest[0]->getRequest() == "a...b...c...");
    assert(CRTest[0]->getSCSAccess() == false);
    assert(CRTest[0]->getStatus() == "Created");
    assert(CRTest[1]->getAMAccess() == false);
    assert(CRTest[1]->getClientBudget() == "20");
    assert(CRTest[1]->getClientName() == "Bob");
    assert(CRTest[1]->getDate() == "1014");
    assert(CRTest[1]->getFMAccess() == false);
    assert(CRTest[1]->getFMComment() == "");
    assert(CRTest[1]->getID() == 2);
    assert(CRTest[1]->getPhone() == "12356");
    assert(CRTest[1]->getPriority() == "Medium");
    assert(CRTest[1]->getRequest() == "A...B...C...");
    assert(CRTest[1]->getSCSAccess() == false);
    assert(CRTest[1]->getStatus() == "Created");

    // Send to SCS
    CRTest[0]->SendToSCS();

    // Test
    assert(CRTest[0]->getSCSAccess() == true);
    assert(CRTest[1]->getSCSAccess() == false);
    
    // Change status
    CRTest[0]->ChangeStatus("test");

    // Test
    assert(CRTest[0]->getStatus() == "test");
    assert(CRTest[1]->getStatus() == "Created");

    // Send to FM
    CRTest[0]->SendToFM();

    // Test
    assert(CRTest[0]->getFMAccess() == true);
    assert(CRTest[1]->getFMAccess() == false);

    // Add comment
    CRTest[0]->AddComment("comment");

    // Test
    assert(CRTest[0]->getFMComment() == "comment");
    assert(CRTest[1]->getFMComment() == "");

    // Send to AM
    CRTest[0]->SendToAM();

    // Test
    assert(CRTest[0]->getAMAccess() == true);
    assert(CRTest[1]->getAMAccess() == false);

    for (auto i : CRTest) {
        delete i;
    }

    return 0;
}