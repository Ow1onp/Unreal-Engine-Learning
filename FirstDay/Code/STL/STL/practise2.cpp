// ʹ�á�std::vector���洢һ����������д����ɾ������ż�������������ʣ���Ԫ�ء�
// // Use 'std::vector' to store a set of integers, write a function to remove all even numbers, and output all remaining elements.

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// Sept1: ���������std::vector
	// Step 1�� ����std::vector<int> numbers������ʼ��Ϊһ��������
	// Step 1: Define std::vector<int> numbers and initialize it to a set of integers.
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// Sept2: ʹ��std::remove_if���Ҫɾ����ż��Ԫ��
	// Step 2�� ʹ��std::remove_if������numbers.begin()��numbers.end()���Լ�һ��Lambda���ʽ���ж�����Ϊx % 2 == 0����ż����
	// Step 2: Use std::remove_if, pass in numbers.begin() and numbers.end(), and a Lambda expression,
	// and the judgment condition is x % 2 == 0, which is an even number.
	auto it = std::remove_if(numbers.begin(), numbers.end(),
		[](int x) { return x % 2 == 0; });

	// Sept3: ʹ��eraseɾ��ż��Ԫ��
	// Step 3�� std::remove_if��������ɾ��Ԫ�أ����ǽ�����������Ԫ���Ƶ�����ĩβ�������µ�β��������
	// ʹ��numbers.erase(it, numbers.end());ɾ����it��numbers.end()��Ԫ�ء�
	// Step 3: std::remove_if does not actually delete the elements, but moves the elements that meet the conditions to the end of the container and returns a new tail iterator.
    // Use numbers.erase(it, numbers.end()); to delete the elements from it to numbers.end().
	numbers.erase(it, numbers.end());

	// Sept4�� ���ʣ��Ԫ��
	// Step 4�� ����numbers�����ʣ���Ԫ�ء�
	// Step 4: Traverse numbers and output the remaining elements.
	std::cout << "ɾ��ż�����ʣ��Ԫ�أ�" << std::endl;
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}