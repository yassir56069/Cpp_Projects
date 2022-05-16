#include <iostream>
#include <string>
using namespace std;

class group {
    private:
        string group_name;
        int year;
    
    public:
        group()  {
            cout << "Enter The Group Name: "; cin >> group_name;
            cout << "Enter The Group's Year: "; cin >> year;
        }       

        //Setters
        void setGname(string n){group_name = n;}
        void setYear(int y){year = year;}

        //Getters
        string getGname(){return group_name;}
        int getGYear(){return year;}
};

class student: public group {
    private:
        int mark;
        string id;    

    public:
        student()  {
            cout << "Enter Student ID: "; cin >> id;
            cout << "Enter Marks of student: "; cin >> mark;
        }       

        //Setters
        void setMark(int m) { mark = m; }
        void setId(int i){ id = i; }

        //Getters
        int getMark(){ return mark; }
        string getId(){ return id; }

        void disp_student() {
            cout << "Student ID: " << getId() << endl;
            cout << "Student Marks: " << getMark() << endl;
            cout << "Student Year: " << getGYear() << endl;
        }
};

double calc_avg(student, student);
void disp_student(student);

int main() {
    student s_1; cout << endl;
    student s_2; cout << endl;
 
    s_1.disp_student(); cout << endl; 
    s_2.disp_student(); cout << endl; 

    cout << "Average: " << calc_avg(s_1 , s_2) << endl;

    return 0;
}

double calc_avg(student s1, student s2) {
    double avg = (s1.getMark() + s2.getMark()) / 2;
    return avg;
}

