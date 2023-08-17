#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student: public Person{
private:
    float student_gpa;
    int student_level;
public:
    // Default constructor
    Student() {
        student_gpa = 0.0;
        student_level = 0;
    }

    // Parameterized constructor
    Student(string name, int age, int id, char gen, float gpa, int lvl)
        : Person(name, age, id, gen) {
        student_gpa = gpa;
        student_level = lvl;
    }

    // Setters and getters
    void set_student_gpa (float gpa){
        student_gpa = gpa;
    }
    void set_student_level (int lvl){
        student_level = lvl;
    }
    float get_student_gpa(){
        return student_gpa;
    }
    int get_student_level(){
        return student_level;
    }
};

class Professor: public Person{
private:
    string degree;
    int salary;
public:
     // Default constructor
    Professor() {
        degree = "";
        salary = 0;
    }

    // Parameterized constructor
    Professor(string s, int a, int id, char ge, string dg, int sl)
        : Person(s, a, id, ge) {
        degree = dg;
        salary = sl;
    }

    // Setters and getters
    void set_degree (string dg){
        degree = dg;
    }
    void set_salary (int sl){
        salary = sl;
    }
    string get_degree(){
        return degree;
    }
    int get_salary(){
        return salary;
    }

};
class University
{
private:

    static University *instance_ptr;

    vector <Student> students;
     vector <Professor> profs;

    University(){}


public:

    University(const University& obj) = delete;

    static University *get_instance()
    {
        if(instance_ptr == NULL)
        {
            instance_ptr = new University();
            return instance_ptr;
        }
        else
        {
            return instance_ptr;
        }
    }

void add_student(string name, int age, int id, char gen, float gpa, int lvl)
{
    Student s ( name,age, id, gen, gpa, lvl);
    students.push_back(s);
}
void add_professpor(string s, int a, int id, char ge, string dg, int sl )
{
    Professor p (s, a, id, ge, dg, sl);
    profs.push_back(p);
}


bool update_prof_salary(int professor_id, int salary)
{
    bool check =true;
        for(int i=0;i<profs.size();i++){
            if(professor_id == profs[i].get_person_id()){
                    profs[i].set_salary(salary);
                break;
    }
    else{
    check= false;
    }

            }
            return check;
}

bool update_student_gpa(int id, int gpa)
{
    bool check =true;
        for(int i=0;i<students.size();i++){
            if(id==students[i].get_person_id()){
                    students[i].set_student_gpa(gpa);
                break;
    }
    else{
    check= false;
    }
            }
            return check;
}
bool delete_student(int id)
    {
         bool check =true;
        for(int i=0;i<students.size();i++){
            if(id==students[i].get_person_id()){
                   students.erase (students.begin()+i);
                break;
    }
    else{
    check= false;
    }
            }
            return check;

        }

        bool delete_prof(int id)
    {
         bool check =true;
        for(int i=0;i<profs.size();i++){
            if(id==profs[i].get_person_id()){
                   profs.erase (profs.begin()+i);
                break;
    }
    else{
    check= false;
    }
            }
            return check;

        }
};
University* University::instance_ptr = NULL;
int main()
{

    return 0;
}
