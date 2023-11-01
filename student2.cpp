#include <iostream>
#include <map>
#include <cstring>

struct Student {
    int middle;
    int final;
};

std::map<std::string, Student> studentMap;

void printStudent(const std::pair<std::string, Student>& student) {
    std::cout << "이름 = " << student.first << ", 중간점수 = " << student.second.middle << ", 기말점수 = " << student.second.final << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: student count" << std::endl;
        exit(1);
    }

    int treesize = std::atoi(argv[1]);
    char nametable[treesize * 20]; // 이름을 저장할 테이블


    while(studentMap.size()!=treesize)
    {
        char name[20];
        int middle, final;
        std::cin >> name >> middle >> final;

        Student student;
        student.middle = middle;
        student.final = final;

        if (studentMap.find(name) == studentMap.end()) {
            studentMap[name] = student;
            std::cout << "\"" << name << "\" 님이 트리에 추가되었습니다." << std::endl;
        } else {
            std::cout << "\"" << name << "\" 님이 트리에 이미 존재합니다." << std::endl;
        }
    }

    // 모든 학생 정보 출력
    for (const auto& student : studentMap) {
        printStudent(student);
    }

    return 0;
}