#include <vector>
#include <string>
#include <cassert>
#include "login.h"
#include "employee.h"
#include "database.h"

using namespace std;

int main() {
    vector<EventPlan *> EPTest;

    // Create
    EPTest.push_back(new EventPlan("Alice", 1, "1015", 10, "10"));
    EPTest.push_back(new EventPlan("Bob", 2, "1016", 20, "25"));

    // Test
    assert(EPTest[0]->getClientName() == "Alice");
    assert(EPTest[0]->getAttendees() == 10);
    assert(EPTest[0]->getBudget() == "10");
    assert(EPTest[0]->getChef() == false);
    assert(EPTest[0]->getComment() == "");
    assert(EPTest[0]->getDate() == "1015");
    assert(EPTest[0]->getDecoration() == false);
    assert(EPTest[0]->getID() == 1);
    assert(EPTest[0]->getPlan() == "");
    assert(EPTest[1]->getClientName() == "Bob");
    assert(EPTest[1]->getAttendees() == 20);
    assert(EPTest[1]->getBudget() == "25");
    assert(EPTest[1]->getChef() == false);
    assert(EPTest[1]->getComment() == "");
    assert(EPTest[1]->getDate() == "1016");
    assert(EPTest[1]->getDecoration() == false);
    assert(EPTest[1]->getID() == 2);
    assert(EPTest[1]->getPlan() == "");

    // Send
    EPTest[0]->SendToChef();
    EPTest[1]->SendToDecoration();

    // Test
    assert(EPTest[0]->getChef() == true);
    assert(EPTest[0]->getDecoration() == false);
    assert(EPTest[1]->getChef() == false);
    assert(EPTest[1]->getDecoration() == true);

    // AddPlan
    EPTest[0]->AddPlan("abc");
    EPTest[1]->AddPlan("def");

    // Test
    assert(EPTest[0]->getPlan() == "abc ");
    assert(EPTest[1]->getPlan() == "def ");

    // AddComment
    EPTest[0]->AddComment("xxx");
    EPTest[1]->AddComment("yyy");

    // Test
    assert(EPTest[0]->getComment() == "xxx ");
    assert(EPTest[1]->getComment() == "yyy ");

    for (auto i : EPTest) {
        delete i;
    }

    return 0;
}