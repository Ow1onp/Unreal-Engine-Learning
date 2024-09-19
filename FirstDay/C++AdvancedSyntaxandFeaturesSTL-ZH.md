# C++进阶语法和特性：STL

## 1.STL简介

### 1.1 什么是STL

标准模板库（Standard Template Library，简称STL）是C++标准库的重要组成部分，它提供了一套通用的、可重用的、基于模板的组件，用于数据存储和操作。STL由容器、迭代器、算法和函数对象等部分组成，旨在让程序员以高效、简洁的方式编写通用代码。



#### 1.2 STL的组成部分

- **容器（Containers）**：用于存储和管理数据的对象集合。容器提供了各种数据结构的实现，如数组、链表、树、哈希表等。
- **迭代器（Iterators）**：提供了一种统一的方式来遍历容器中的元素。迭代器类似于指针，支持对容器元素的访问和操作。
- **算法（Algorithms）**：一组通用的算法函数，用于对容器中的数据进行操作，如排序、搜索、复制、修改等。
- **函数对象（Function Objects）**：也称为仿函数，行为类似函数的对象，可以在算法中作为参数传递。
- **适配器（Adapters）**：用于修改容器、迭代器或函数对象的接口，以适应不同的需求。



#### 1.3 STL的优势

- **高效性**：STL中的算法和容器经过精心设计和优化，提供了高效的性能。
- **通用性**：基于模板机制，STL可以适用于各种数据类型和数据结构。
- **可重用性**：STL提供了大量现成的组件，减少了重复造轮子的必要。
- **可读性和可维护性**：使用STL的代码更简洁、更易读，有助于提高代码质量。



### 2.常用容器

STL提供了多种容器，用于满足不同的应用需求。主要分为顺序容器和关联容器。

#### 2.1 顺序容器

顺序容器按照元素插入的顺序存储数据，常用的顺序容器包括：

- **'std::vector'(动态数组)**

  - **特点**：支持快速随机访问，元素连续存储，支持在末尾高效地添加和删除元素。

  - **适用场景**：需要频繁随机访问和在末尾添加元素的场景。

  - **示例：**

    ```c++
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    int firstElement = vec[0]; // 访问第一个元素
    ```



- **‘std::deque’(双端队列)**

  - **特点**：支持在头尾高效地添加和删除元素，随机访问性能稍逊于`vector`。

  - **适用场景**：需要在头部和尾部都进行插入和删除操作的场景。

  - **示例：**

    ```c++
    std::deque<int> deq;
    deq.push_front(10);
    deq.push_back(20);
    int firstElement = deq.front(); // 访问第一个元素
    ```



- **‘std::list’（双向链表）**

  - **特点**：元素不连续存储，支持在任意位置高效地插入和删除，但不支持随机访问。

  - **适用场景**：需要频繁在中间位置插入和删除元素的场景。

  - **示例**：

    ```c++
    std::list<int> lst;
    lst.push_back(10);
    lst.push_front(20);
    auto it = lst.begin();
    lst.insert(it, 30); // 在开头插入30
    ```



#### 2.2 关联容器

关联容器根据键值对元素进行存储，通常基于树或哈希表实现。

- **’std::map‘（映射容器）**

  - **特点**：以键值对的形式存储数据，键唯一且自动排序。

  - **适用场景**：需要根据键快速查找对应值的场景。

  - **示例**

    ```c++
    std::map<std::string, int> studentScores;
    studentScores["Alice"] = 95;
    studentScores["Bob"] = 88;
    int aliceScore = studentScores["Alice"]; // 访问Alice的成绩
    ```

    

- **’std::unordered_map‘（无序映射）**
  - **特点**：基于哈希表实现，键唯一，但不保证顺序，查找速度更快。
  - **适用场景**：对元素顺序无要求，但需要高效查找的场景。



- **’std::set‘（集合容器）**

  - **特点**：存储唯一元素，自动排序。

  - **适用场景**：需要存储不重复元素，并且关心元素顺序的场景。

  - **示例**

    ```c++
    std::set<int> uniqueNumbers;
    uniqueNumbers.insert(10);
    uniqueNumbers.insert(20);
    uniqueNumbers.insert(10); // 重复元素不会插入
    ```

    

- **std::unordered_set（无序集合）**

  - **特点**：基于哈希表，不保证元素顺序。

    

#### 2.3 容器的选择

- **需要随机访问：** 选择`std::vector`或`std::deque`。
- **需要频繁插入/删除：**
  - 在头尾：`std::deque`。
  - 在中间位置：`std::list`。
- **需要快速查找：**
  - 需要顺序：`std::map`或`std::set`。
  - 不需要顺序：`std::unordered_map`或`std::unordered_set`。



### 3. 迭代器

迭代器是STL中用于遍历容器元素的对象，类似于指针。通过迭代器，算法可以以一致的方式访问不同的容器。

#### 3.1迭代器的类型

- **输入迭代器（Input Iterator）**：只读，支持自增和解引用。
- **输出迭代器（Output Iterator）**：只写，支持自增和解引用。
- **前向迭代器（Forward Iterator）**：可读可写，只能向前移动。
- **双向迭代器（Bidirectional Iterator）**：可读可写，支持向前和向后移动。
- **随机访问迭代器（Random Access Iterator）**：可读可写，支持任意位置的访问和算术运算。

#### 常用迭代器操作

- **创建迭代器：**

  ```c++
  std::vector<int>::iterator it = vec.begin();
  ```

- **访问元素：**

  ```c++
  int vlue = *it;
  ```

- **移动迭代器：**

  - 前进：**‘++it’****或**‘it++’**
  - 后退：**‘--it’**或**‘it--’**

- **遍历迭代器**

  ```c++
  for(auto it = container.begin(); it != container.end(); ++it)
  {
  	// 访问元素 *it
  }
  ```

- **随机访问迭代器特有操作：**

  - 算术运算：**‘it + n’**、**‘it - n’**

  - 比较运算：**‘it < it2’**、**'it >= it2'**

    

#### 3.3 常用迭代器类别与容器对应关系

- **随机访问迭代器：** std::vector、std::deque、std::array
- **双向迭代器：** std::list、std::set、std::map
- **前向迭代器：** std::forward_list

### 4.常用算法

STL算法是对容器数据进行操作的通用函数，使用模板实现，具有很高的复用性。

#### **4.1 算法的使用**

算法通常接受迭代器作为参数，这样可以操作任何支持该迭代器类型的容器。

- 基本格式

  ```c++
  std::algorithm_name(container.begin(), container.end(), additional_parameters);
  ```

#### **4.2 常用算法示例**

- **排序算法**

  - **'std::sort':**对范围内的元素进行排序，要求随机访问迭代器。

    ```c++
    std::vector<int> numbers = {4, 2, 5, 1, 3};
    std::sort(numbers.begin(), numbers.end());
    // 排序后：1, 2, 3, 4, 5
    ```

  - **自定义比较函数：**

    ```c++
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    // 排序后：5, 4, 3, 2, 1
    ```

- **查找算法**

  - **’std::find‘：**在范围内查找等于指定值的元素。

    ```c++
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    if(it != numbers.end()) {
        // 找到元素
    }
    ```

  - **’std::find_if‘：**根据条件查找元素

    ```c++
    auto it = std::find_if(numbers.begin(), numbers.end(),
                           [](int x){ return x > 3; });
    ```

- **遍历算法**

  - **’std::for_each‘：**对范围内的每个元素执行指定操作。

    ```c++
    std::for_each(numbers.begin(), numbers.end(),
                  [](int x){ std::cout << x << " "; });
    ```

- **修改算法**

  - **’std::copy‘：**将元素复制到另一个范围。

    ```c++
    std::vector<int> dest(5);
    std::copy(numbers.begin(), numbers.end(), dest.begin());
    ```

  - **’std::transform‘：**对元素进行转换后复制。

    ```c++
    std::transform(numbers.begin(), numbers.end(), dest.begin(),
                   [](int x){ return x * 2; });
    ```

- **删除算法**

  - **’std::remove‘：**移除等于指定值的元素（需结合容器的`erase`方法）。

    ```c++
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 3), numbers.end());
    ```

  - **’std::remove_if‘：**根据条件移除元素。

    ```c++
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                  [](int x){ return x % 2 == 0; }), numbers.end());
    // 移除所有偶数
    ```

#### 4.3 注意事项

- **算法不改变容器大小**：`std::remove`等算法不会实际删除元素，而是将符合条件的元素移到容器末尾，需要配合`erase`删除。
- **算法的适用范围**：某些算法需要特定类型的迭代器，如`std::sort`要求随机访问迭代器，因此不能用于`std::list`。
- **使用Lambda表达式**：在算法中传递函数对象或Lambda表达式，增强了算法的灵活性。



### **5. 小结**

- **STL是C++强大的标准库，提供了丰富的容器、迭代器和算法。**
- **选择合适的容器和算法，可以显著提高程序的性能和可维护性。**
- **理解迭代器的类型和特性，有助于正确使用算法。**
- **善用Lambda表达式和函数对象，可以编写出更加简洁和高效的代码。**