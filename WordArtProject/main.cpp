#include <iostream>
#include <string>
using namespace std;


class students {
    private:
        int mark;
        string id;    

    public:
        students()  {
            cout << "Enter Student ID: "; cin >> id;
            cout << "Enter Marks of student: "; cin >> mark;
        }       

        //Setters
        void setMark(int m) { mark = m; }

        void setId(int i){ id = i; }

        //Getters
        void disp_student() {
            cout << "Student ID: " << getId() << endl;
            cout << "Student Marks: " << getMark() << endl;
        }

        int getMark(){ return mark; }

        string getId(){ return id; }
};

students create_student();
double calc_avg(students, students);
void disp_student(students);

int main() {
    students s_1; cout << endl;
    students s_2; cout << endl;
 
    s_1.disp_student(); cout << endl;
    s_2.disp_student();

    cout << "Average: " << calc_avg(s_1 , s_2) << endl;

    return 0;
}

double calc_avg(students s1, students s2) {
    double avg = (s1.getMark() + s2.getMark()) / 2;
    return avg;
}

