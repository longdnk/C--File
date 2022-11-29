
#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    double math;
    double physic;
    double chemistry;
public:
    Student() { }

    Student(const string &name, double math, double physic, double chemistry) : name(name), math(math), physic(physic), chemistry(chemistry) {
        this->name = name;
        this->math = math;
        this->physic = physic;
        this->chemistry = chemistry;
    }

    const string &getName() const {
        return name;
    }

    double getMath() const {
        return math;
    }

    double getPhysic() const {
        return physic;
    }

    double getChemistry() const {
        return chemistry;
    }

    void display();

    double avgPoint() {
        return (this->math + this->physic + this->chemistry) / 3;
    }

    static vector<Student> getStudentMaxAvg(vector<Student> vt) {
        double maxPoint = 0;
        vector<Student> res;
        for (int i = 0; i < vt.size(); ++i) {
            maxPoint = max(maxPoint, vt[i].avgPoint());
        }
        for (int i = 0; i < vt.size(); ++i) {
            if (vt[i].avgPoint() == maxPoint) {
                res.emplace_back(vt[i]);
            }
        }
        return res;
    }

    static vector<Student> getStudentMaxMath(vector<Student> vt) {
        double maxMath = 0;
        vector<Student> res;
        for (int i = 0; i < vt.size(); ++i) {
            maxMath = max(maxMath, vt[i].math);
        }
        for (int i = 0; i < vt.size(); ++i) {
            if (vt[i].math == maxMath) {
                res.emplace_back(vt[i]);
            }
        }
        return res;
    }

    static vector<Student> getStudentMaxPhysic(vector<Student> vt) {
        double maxPhysic = 0;
        vector<Student> res;
        for (int i = 0; i < vt.size(); ++i) {
            maxPhysic = max(maxPhysic, vt[i].physic);
        }
        for (int i = 0; i < vt.size(); ++i) {
            if (vt[i].physic == maxPhysic) {
                res.emplace_back(vt[i]);
            }
        }
        return res;
    }

    static vector<Student> getStudentMaxChemistry(vector<Student> vt) {
        double maxChemistry = 0;
        vector<Student> res;
        for (int i = 0; i < vt.size(); ++i) {
            maxChemistry = max(maxChemistry, vt[i].chemistry);
        }
        for (int i = 0; i < vt.size(); ++i) {
            if (vt[i].chemistry == maxChemistry) {
                res.emplace_back(vt[i]);
            }
        }
        return res;
    }
};

void Student::display() {
    cout << "Name: " << this->name << '\n'
        << "Point math: " << this->math << '\n'
        << "Point physic: " << this->physic << '\n'
        << "Point chemistry: " << this->chemistry << '\n'
        << "Average: " << this->avgPoint() << '\n';
}