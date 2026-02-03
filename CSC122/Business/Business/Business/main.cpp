//
//  main.cpp
//  Business
//
//  Created by Austin Bennett on 7/7/22.
//

#include <iostream>
#include <vector>

#include "input.h"
#include "person.cpp"
#include "laborer.cpp"
#include "manager.cpp"
#include "owner.cpp"

using namespace std;


int main()
{

    vector<Person *> list;

    int choice;

    do
    {
        cout << endl
             << " 1 - Add Laborer\n"
             << " 2 - Add Manager\n"
             << " 3 - Add Owner\n"
             << " 4 - Display List\n"
             << " 5 - Exit.\n"
             << " Enter your choice and press return: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: // Add Laborer
        {
            
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            
            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);
            
            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);
            
            cout << "Job: ";
            string job;
            getline(cin, job);
            
            cout << "Employee ID: ";
            
            string laborerEmployeeID;
            getline(cin, laborerEmployeeID);
            
            cout << "Hourly Salary: ";
            string hourlySalary;
            getline(cin, hourlySalary);
            
            cout << "Hours Worked: ";
            string hoursWorked;
            getline(cin, hoursWorked);

            list.push_back(new Laborer(name, birthday, ssn, job, laborerEmployeeID, hourlySalary, hoursWorked));
            break;
        }
        case 2: // Add Manager
        {
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            
            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);
            
            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);
            
            cout << "Department: ";
            string department;
            getline(cin, department);
            
            cout << "Employee ID: ";
            string managerEmployeeID;
            getline(cin, managerEmployeeID);
            
            cout << "Salary: ";
            string salary;
            getline(cin, salary);

            list.push_back(new Manager(name, birthday, ssn, department, managerEmployeeID, salary));
            break;
        }
        case 3: // Add Owner
        {
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            
            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);
            
            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);
            
            cout << "Percent Owned: ";
            string percentOwned;
            getline(cin, percentOwned);
            
            cout << "Owner Since: ";
            string ownerSince;
            getline(cin, ownerSince);

            list.push_back(new Owner(name, birthday, ssn, percentOwned, ownerSince));
            break;
        }
         case 4: // Display List
             for (int i = 0; i < list.size(); i++)
             {
                 list[i]->Display();
             }
             break;
        case 5: // Exit
            cout << "End of Program.\n";
            break;
        default:
            cout << "Not a Valid Choice. \n"
                 << "Choose again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
