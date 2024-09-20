// ����һ��std::map���洢ѧ���������ͳɼ�����д�����������ѧ������Ϣ�����ճɼ��Ӹߵ�������
// Create a std::map to store students' names and grades, write code to output all students' information, and sort them from high to low.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: ���������std::map
    // Step 1: Create and populate std::map
    // Step 1�� ����std::map<std::string, int> studentScores;�������ѧ�������ͳɼ��ļ�ֵ�ԡ�
    std::map<std::string, int> studentScores;
    studentScores["Alice"] = 85;
    studentScores["Bob"] = 92;
    studentScores["Charlie"] = 78;
    studentScores["David"] = 90;

    // Step 2: ��mapת��Ϊvector
    // Step 2: Convert map to vector
    // Step 2�� ʹ��std::vector�Ĺ��캯������studentScores�����ݳ�ʼ����vec�У�
    // std::vector<std::pair<std::string, int>> vec(studentScores.begin(), studentScores.end());
    std::vector<std::pair<std::string, int>> vec(studentScores.begin(), studentScores.end());

    // Step 3: ʹ��std::sort����
    // Step 3: Sort using std::sort
    // Step 3��ʹ��std::sort��vec���������ṩ��һ��Lambda���ʽ��Ϊ�ȽϺ���������pair��second���ɼ������бȽϣ�ʵ�ִӸߵ�������
    std::sort(vec.begin(), vec.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second; // ���ɼ��Ӹߵ������� // Sort by scores from high to low
        });

    // Step 4: ������
    // Step 4: Output results
    // Step 4�� ����������vec�����ѧ�������ͳɼ���
    std::cout << "ѧ���ɼ��б����ɼ��Ӹߵ������򣩣�" << std::endl;
    for (const auto& student : vec) {
        std::cout << "������" << student.first << "���ɼ���" << student.second << std::endl;
    }

    return 0;
}