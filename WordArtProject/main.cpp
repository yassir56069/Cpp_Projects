#include <iostream>
#include <string>
using namespace std;

class group {
    private:
        string group_name;
        int year;
    
    protected: 
        int num_subjects;
        const int min_mark = 40; 

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

class subject: public group {
    private:
        string subject_name;
        int subject_avg;
    
    protected:
        int mark;

    public:
        subject(){
            cout << "Enter Subject Name: "; cin >> subject_name;
            cout << "Enter Marks In Subject: "; cin >> mark;
            num_subjects ++;
        }

        //Setters
        void setSname(string n){ subject_name = n;}
        void setSavg(int a){ subject_avg = a;}

        //Getters
        string getSname(){return subject_name;}
        int getSavg(){return subject_avg;}
         
        void success_rate(){
            string result = (mark > min_mark) ? "Student Passed" : "Student Failed..";
            cout << result << endl;
            cout << num_subjects << endl;
        }
};

class student: public subject {
    private:
        string id;    

    public:
        student()  {
            cout << "Enter Student ID: "; cin >> id;
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
    s_1.success_rate(); s_2.success_rate();

    cout << "Average: " << calc_avg(s_1 , s_2) << endl;

    return 0;
}

double calc_avg(student s1, student s2) {
    double avg = (s1.getMark() + s2.getMark()) / 2;
    return avg;
}

