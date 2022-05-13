#include <iostream>
#include <string>
using namespace std;


class students {
    public:
        string id;
        double mark;
        students();
};

students create_student();
double calc_avg(students, students);
void disp_student(students);

int main() {
    students s_1; students s_2;

    cout << endl << endl;
    disp_student(s_1); disp_student(s_2);
    cout << "Average: " << calc_avg(s_1,s_2) << endl;

    return 0;
}

double calc_avg(students s1, students s2) {
    double avg = (s1.mark + s2.mark) / 2;
    return avg;
}

void disp_student(students s){
    cout << "Student ID: " << s.id << endl;
    cout << "Student Name" << s.mark << endl;
}

students::students(){
    cout << "Enter Student ID: "; cin >> id;
    cout << "Enter Marks of student: "; cin >> mark;
}


