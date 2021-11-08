#include <vector>
#include <string>
#include <cassert>
#include "login.h"
#include "employee.h"
#include "database.h"

using namespace std;

int main() {
    vector<HRRequest *> HRTest;

    // Create
    HRTest.push_back(new HRRequest("Department1", "Full", "3", "JobTitle1", "JobDescription1"));

    // Test
    assert(HRTest[0]->getContractType() == "Full");
    assert(HRTest[0]->getDepartment() == "Department1");
    assert(HRTest[0]->getExperienceYear() == "3");
    assert(HRTest[0]->getHRAcces() == false);
    assert(HRTest[0]->getJobDescription() == "JobDescription1");
    assert(HRTest[0]->getJobTitle() == "JobTitle1");
    assert(HRTest[0]->getStatus() == "Created");

    // Send
    HRTest[0]->sendHRAccess();

    // Test
    assert(HRTest[0]->getHRAcces() == true);

    // Change status
    HRTest[0]->changeStatus("test");

    // Test
    assert(HRTest[0]->getStatus() == "test");

    for (auto i : HRTest) {
        delete i;
    }

    return 0;
}