// ����һ��std::map���洢ѧ���������ͳɼ�����д�����������ѧ������Ϣ�����ճɼ��Ӹߵ�������
// Create a std::map to store students' names and grades, write code to output all students' information, and sort them from high to low.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: ���������std::map
    // Step 1: Create and populate std::map
    std::map<std::string, int> studentScores;
    studentScores["Alice"] = 85;
    studentScores["Bob"] = 92;
    studentScores["Charlie"] = 78;
    studentScores["David"] = 90;

    // Step 2: ��mapת��Ϊvector
    // Step 2: Convert map to vector
    std::vector<std::pair<std::string, int>> vec(studentScores.begin(), studentScores.end());

    // Step 3: ʹ��std::sort����
    // Step 3: Sort using std::sort
    std::sort(vec.begin(), vec.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second; // ���ɼ��Ӹߵ������� // Sort by scores from high to low
        });

    // Step 4: ������
    // Step 4: Output results
    std::cout << "ѧ���ɼ��б����ɼ��Ӹߵ������򣩣�" << std::endl;
    for (const auto& student : vec) {
        std::cout << "������" << student.first << "���ɼ���" << student.second << std::endl;
    }

    return 0;
}