#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Person
{
protected:
    string person_name;
    int person_age;
    int person_id;
    char person_gender;
public:
    // Default constructor
    Person()
    {
        person_name = "";
        person_age = 0;
        person_id = 0;
        person_gender = '\0';
    }

    // Parameterized constructor
    Person(string name, int age, int id, char gen)
    {
        person_name = name;
        person_age = age;
        person_id = id;
        person_gender = gen;
    }

    // Setters and getters
    void set_person_name(string name)
    {
        person_name = name;
    }
    void set_person_age(int age)
    {
        person_age = age;
    }
    void set_person_id(int id)
    {
        person_id = id;
    }
    void set_person_gender(char gen)
    {
        person_gender = gen;
    }
    string get_person_name()
    {
        return person_name;
    }
    int get_person_age()
    {
        return person_age;
    }
    int get_person_id()
    {
        return person_id;
    }
    char get_person_gender()
    {
        return person_gender;
    }
};

class Department
{
protected:
    string department_name;
    int department_capacity;
    float department_require_gpa;
public:
    // Default constructor
    Department()
    {
        department_name = "";
        department_capacity = 0;
        department_require_gpa = 0.0;
    }

    // Parameterized constructor
    Department(string name, int capacity, float reg_gpa)
    {
        department_name = name;
        department_capacity = capacity;
        department_require_gpa = reg_gpa;
    }

    // Setters and getters
    void set_department_name(string name)
    {
        department_name = name;
    }
    void set_department_capacity(int capacity)
    {
        department_capacity = capacity;
    }
    void set_department_require_gpa(float reg_gpa)
    {
        department_require_gpa = reg_gpa;
    }
    string get_department_name()
    {
        return department_name;
    }
    int get_department_capacity()
    {
        return department_capacity;
    }
    float get_department_require_gpa()
    {
        return department_require_gpa;
    }
};


class University
{
private:
    static University *instancePtr;
    vector<Department> department_vector;
    University() {}
public:
    University(const University& obj) = delete;
    static University *getInstance()
    {
        if(instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }
    // add department information
    void add_department(string name, int capacity, float reg_gpa)
    {
        Department department(name,capacity,reg_gpa);
        department_vector.push_back(department);
    }
//Update department information
    void update_department(string name, float new_reg_gpa)
    {
        for (auto& department : department_vector)
        {
            if (department.get_department_name() == name)
            {
                department.set_department_require_gpa(new_reg_gpa);
                break;
            }
        }
    }

    // Delete department by name
    void delete_department(string name)
    {
        for (int i = 0; i < department_vector.size(); i++)
        {
            if (department_vector[i].get_department_name() == name)
            {
                department_vector.erase(department_vector.begin()+i);
                break;
            }
        }
    }
    // Print all departments
    void print_departments()
    {
        cout << "Departments in the university:" << endl;
        for (auto& department : department_vector)
        {
            cout << "Name: " << department.get_department_name() << endl;
            cout << "Capacity: " << department.get_department_capacity() << endl;
            cout << "Required GPA: " << department.get_department_require_gpa() << endl;
            cout << "----------------------" << endl;
        }
    }
};



University* University::instancePtr = NULL;

int main()
{
    University* university = University::getInstance();

    //Example
    // Adding departments
    university->add_department("Computer Science", 50, 2.5);
    university->add_department("Artificial intelligence", 30, 3.0);
    university->add_department("information system", 80, 2.0);
    // Updating department information
    university->update_department("information system",2.0);
    // Deleting department
    university->delete_department("Computer Science");
    // Print all departments
    university->print_departments();



    return 0;
}
