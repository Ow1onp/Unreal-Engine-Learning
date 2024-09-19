// 创建一个std::map，存储学生的姓名和成绩，编写代码输出所有学生的信息，按照成绩从高到低排序。
// Create a std::map to store students' names and grades, write code to output all students' information, and sort them from high to low.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: 创建并填充std::map
    // Step 1: Create and populate std::map
    std::map<std::string, int> studentScores;
    studentScores["Alice"] = 85;
    studentScores["Bob"] = 92;
    studentScores["Charlie"] = 78;
    studentScores["David"] = 90;

    // Step 2: 将map转换为vector
    // Step 2: Convert map to vector
    std::vector<std::pair<std::string, int>> vec(studentScores.begin(), studentScores.end());

    // Step 3: 使用std::sort排序
    // Step 3: Sort using std::sort
    std::sort(vec.begin(), vec.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second; // 按成绩从高到低排序 // Sort by scores from high to low
        });

    // Step 4: 输出结果
    // Step 4: Output results
    std::cout << "学生成绩列表（按成绩从高到低排序）：" << std::endl;
    for (const auto& student : vec) {
        std::cout << "姓名：" << student.first << "，成绩：" << student.second << std::endl;
    }

    return 0;
}