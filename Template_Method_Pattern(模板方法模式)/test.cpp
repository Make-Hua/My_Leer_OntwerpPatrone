#include <iostream>
 
class ResumeA {
public:
    void SetPersonalInfo() {
        std::cout << "A's PersonalInfo" << std::endl;
    }
    void SetEducation() {
        std::cout << "A's Education" << std::endl;
    }
    void SetWorkExp() {
        std::cout << "A's Work Experience" << std::endl;
    }
};
 
class ResumeB {
public:
    void SetPersonalInfo() {
        std::cout << "B's PersonalInfo" << std::endl;
    }
    void SetEducation() {
        std::cout << "B's Education" << std::endl;
    }
    void SetWorkExp() {
        std::cout << "B's Work Experience" << std::endl;
    }
};
 
int main() {
    ResumeA A;
    ResumeB B;

    A.SetPersonalInfo();
    A.SetEducation();
    A.SetWorkExp();
 
    B.SetPersonalInfo();
    B.SetEducation();
    B.SetWorkExp();

    return 0;
}