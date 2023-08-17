
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course
{
private:
    string course_name;
    string course_code;
    int course_hours;
    vector <Course> prerequisites;
    Professor professor;
    vector <Student> students;

public:

    Course(string name , string code , int hours , vector<Course> pre , Professor prof , vector <Student> student)
    {
        this->course_name = name;
        this->course_code = code ;
        this->course_hours = hours;
        this->prerequisites = pre;
        this->professor = prof;
        this->students = student;

    }


    ~Course()
    {

    }


    string get_course_name()
    {
        return course_name;
    }

    string get_course_code()
    {
        return course_code;
    }

    int get_course_hours()
    {
        return course_hours;
    }

    vector<Course> get_prerequisites()
    {
        return prerequisites;
    }

    Professor get_professor()
    {
        return professor;
    }

    vector<Student> get_students()
    {
        return students;
    }


    void set_course_name(string name)
    {
        course_name = name;
    }

    void set_course_code(string code)
    {
        course_code = code;
    }

    void set_course_hours(int hours)
    {
        course_hours = hours;
    }

    void set_prerequisites(vector<Course> prereqs)
    {
        for (const Course& prerequisite : prereqs)
        {
            prerequisites.push_back(prerequisite);
        }
    }


    void set_professor(Professor prof)
    {
        professor = prof;
    }


     void set_student(Student student)
    {
        students.push_back(student);
    }

};


class University
{
private:

    static University *instance_ptr;

    vector<Course> cource_vector;

    University(){}


public:

    University(const University& obj) = delete;

    static University *get_nstance()
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


    void add_course(string name , string code , int hours , vector<Course> pre , Professor prof , vector<Student> student)
    {
        Course course( name ,  code ,  hours , pre ,  prof ,  student);


        cource_vector.push_back(course);

    }

    bool update_course(string code , int hours)
    {
        bool check = false ;

        for(int i = 0 ; i < cource_vector.size() ; i++)
        {
            if(code == cource_vector[i].get_course_code())
            {
                cource_vector[i].set_course_hours(hours);
                check = true;
                break;
            }
        }

        return check;
    }

    bool delete_course(string code)
    {
        bool check = false ;


        for(int i = 0 ; i < cource_vector.size() ; i++)
        {
            if(code == cource_vector[i].get_course_code())
            {
                cource_vector.erase(cource_vector.begin()+i);
                check = true;
                break;
            }

        }
        return check;
    }



};

University* University::instance_ptr = NULL;



int main()
{

    University *s = University::getInstance();



    return 0;
}




