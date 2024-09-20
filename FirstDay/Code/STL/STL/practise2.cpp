// 使用‘std::vector’存储一组整数，编写函数删除所有偶数，并输出所有剩余的元素。
// // Use 'std::vector' to store a set of integers, write a function to remove all even numbers, and output all remaining elements.

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// Sept1: 创建并填充std::vector
	// Step 1： 定义std::vector<int> numbers，并初始化为一组整数。
	// Step 1: Define std::vector<int> numbers and initialize it to a set of integers.
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// Sept2: 使用std::remove_if标记要删除的偶数元素
	// Step 2： 使用std::remove_if，传入numbers.begin()和numbers.end()，以及一个Lambda表达式，判断条件为x % 2 == 0，即偶数。
	// Step 2: Use std::remove_if, pass in numbers.begin() and numbers.end(), and a Lambda expression,
	// and the judgment condition is x % 2 == 0, which is an even number.
	auto it = std::remove_if(numbers.begin(), numbers.end(),
		[](int x) { return x % 2 == 0; });

	// Sept3: 使用erase删除偶数元素
	// Step 3： std::remove_if不会真正删除元素，而是将符合条件的元素移到容器末尾，返回新的尾迭代器。
	// 使用numbers.erase(it, numbers.end());删除从it到numbers.end()的元素。
	// Step 3: std::remove_if does not actually delete the elements, but moves the elements that meet the conditions to the end of the container and returns a new tail iterator.
    // Use numbers.erase(it, numbers.end()); to delete the elements from it to numbers.end().
	numbers.erase(it, numbers.end());

	// Sept4： 输出剩余元素
	// Step 4： 遍历numbers，输出剩余的元素。
	// Step 4: Traverse numbers and output the remaining elements.
	std::cout << "删除偶数后的剩余元素：" << std::endl;
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}