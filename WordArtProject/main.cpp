#include <iostream>
#include <vector>
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
            cout << "Enter Student's The Group Name: "; cin >> group_name;
            cout << "Enter The Student's  Year: "; cin >> year;
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
        //Setters
        void setSname(string n){ subject_name = n;}
        void setSavg(int a){ subject_avg = a;}

        //Getters
        string getSname(){return subject_name;}
        int getSavg(){return subject_avg;}
         
        void add_subject(){
            cout << "Enter The Subject Name: "; cin >> subject_name;
            cout << "Enter Marks In Subject: "; cin >> mark;
            num_subjects ++;
        }

        void success_rate(){
            string result = (mark > min_mark) ? "Student Passed" : "Student Failed..";
            cout << result << endl;
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

void disp_student(student);

int main() {
    vector<string> g1;
    string x;
    int numStudents; 

    cout << "How many students are there?: "; cin >> numStudents;
    
    for (int i = 1; i <= numStudents ; i++){
        cout << i << " ] Name: "; cin >> x;
        g1.push_back(x);
    }


    cout << "Contents of Vector g1: " ; cout << endl;

    for (int i = 0; i < g1.size(); i++){
        cout << i+1 << " | " << g1[i] << endl;
    }

    cout << endl;
    return 0;
}

