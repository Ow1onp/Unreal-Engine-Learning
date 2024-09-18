# C++ Advanced Syntax and Features: STL

## 1. Introduction to STL

### 1.1 What is STL

The Standard Template Library (STL) is an important part of the C++ Standard Library. It provides a set of general, reusable, template-based components for data storage and manipulation. STL consists of containers, iterators, algorithms, and function objects, and is designed to allow programmers to write general code in an efficient and concise way.

#### 1.2 Components of STL

- **Containers**: A collection of objects used to store and manage data. Containers provide implementations of various data structures, such as arrays, linked lists, trees, hash tables, etc.

- **Iterators**: Provides a unified way to traverse elements in a container. Iterators are similar to pointers and support access and manipulation of container elements.

- **Algorithms**: A set of general algorithm functions used to operate on data in containers, such as sorting, searching, copying, modifying, etc.
- **Function Objects**: Also known as functors, objects that behave like functions and can be passed as parameters in algorithms.
- **Adapters**: Used to modify the interface of containers, iterators, or function objects to adapt to different needs.

#### 1.3 Advantages of STL

- **Efficiency**: The algorithms and containers in STL are carefully designed and optimized to provide efficient performance.
- **Versatile**: Based on the template mechanism, STL can be applied to various data types and data structures.
- **Reusability**: STL provides a large number of ready-made components, reducing the need to reinvent the wheel.
- **Readability and maintainability**: Code using STL is more concise and easier to read, which helps improve code quality.

## 2. Common containers

STL provides a variety of containers to meet different application needs. They are mainly divided into sequential containers and associative containers.

#### 2.1 Sequential containers

Sequential containers store data in the order in which elements are inserted. Commonly used sequential containers include:

- **'std::vector' (dynamic array)**

- **Features**: Supports fast random access, continuous element storage, and supports efficient addition and deletion of elements at the end.

- **Applicable scenarios**: Scenarios that require frequent random access and adding elements at the end.

- **Example:**

```c++
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
int firstElement = vec[0]; // Access the first element
```

- **‘std::deque' (double-ended queue)**

- **Features**: Supports efficient addition and deletion of elements at the head and tail, and the random access performance is slightly inferior to `vector`.

- **Applicable scenarios**: Scenarios that require insertion and deletion operations at both the head and the tail.

- **Example:**

```c++
std::deque<int> deq;
deq.push_front(10);
deq.push_back(20);
int firstElement = deq.front(); // Access the first element
```

- **‘std::list’ (bidirectional linked list)**

- **Features**: Elements are not stored continuously, supporting efficient insertion and deletion at any position, but not supporting random access.

- **Applicable scenarios**: Scenarios where elements need to be frequently inserted and deleted at the middle position.

- **Example**:

```c++
std::list<int> lst;
lst.push_back(10);
lst.push_front(20);
auto it = lst.begin();
lst.insert(it, 30); // Insert 30 at the beginning
```

#### 2.2 Associative containers

Associative containers store elements according to key values, usually based on trees or hash tables.

- **'std::map' (mapping container)**

- **Features**: Store data in the form of key-value pairs, with unique keys and automatic sorting.

- **Applicable scenarios**: Scenarios where you need to quickly find the corresponding value based on the key.

- **Example**

```c++
std::map<std::string, int> studentScores;
studentScores["Alice"] = 95;
studentScores["Bob"] = 88;
int aliceScore = studentScores["Alice"]; // Access Alice's score
```

- **'std::unordered_map' (unordered map)**
- **Features**: Based on hash table implementation, the key is unique, but the order is not guaranteed, and the search speed is faster.
- **Applicable scenarios**: There is no requirement for the order of elements, but efficient search is required.

- **'std::set' (collection container)**

- **Features**: Store unique elements and automatically sort.

- **Applicable scenarios**: Scenarios that need to store non-duplicate elements and care about the order of elements.

- **Example**

```c++
std::set<int> uniqueNumbers;
uniqueNumbers.insert(10);
uniqueNumbers.insert(20);
uniqueNumbers.insert(10); // Duplicate elements will not be inserted
```

- **std::unordered_set（Unordered Set）**

- **Features**: Based on hash table, element order is not guaranteed.

#### 2.3 Container Selection

- **Random access required:** Choose `std::vector` or `std::deque`.

- **Frequent insertion/deletion required:**
- At the head and tail: `std::deque`.
- In the middle: `std::list`.
- **Fast search required:**
- Order required: `std::map` or `std::set`.
- No order required: `std::unordered_map` or `std::unordered_set`.

### 3. Iterators

Iterators are objects used in STL to traverse container elements, similar to pointers. Through iterators, algorithms can access different containers in a consistent way.

#### 3.1 Types of iterators

- **Input Iterator**: Read-only, supports self-increment and dereference.

- **Output Iterator**: Write-only, supports self-increment and dereference.

- **Forward Iterator**: Readable and writable, can only move forward.

- **Bidirectional Iterator**: Readable and writable, supports forward and backward movement.

- **Random Access Iterator**: Readable and writable, supports access and arithmetic operations at any position.

#### Common iterator operations

- **Create iterator:**

```c++
std::vector<int>::iterator it = vec.begin();
```

- **Access elements:**

```c++
int vlue = *it;
```

- **Move iterator:**

- Forward: **‘++it’**** or **‘it++’**
- Backward: **‘--it’** or **‘it--’**

- **Traverse iterator**

```c++
for(auto it = container.begin(); it != container.end(); ++it)
{
// Access element *it
}
```

- **Operations specific to random access iterators:**

- Arithmetic operations: **‘it + n’**, **‘it - n’**

- Comparison operations: **‘it < it2’**, **‘it >= it2'**

#### 3.3 Correspondence between common iterator categories and containers

- **Random access iterators:** std::vector, std::deque, std::array
- **Bidirectional iterators:** std::list, std::set, std::map
- **Forward iterators:** std::forward_list