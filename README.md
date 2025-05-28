# string-implementation-cpp

This project demonstrates a complete implementation of a `String` class in C++, mimicking the behavior of `std::string` while giving full control over memory management, object semantics, and operator overloading. It is a hands-on demonstration of deep knowledge in object-oriented programming, RAII, and STL-like usability.

## ✨ Features

- Supports various construction styles:
  ```cpp
  String s1;
  String s2("Ranjan Kumar");
  String s3 = "Ranjan Kumar";
  String s4 = s3;  // Deep copy
  s3[0] = 'y';     // Index operator overload


* Stream input/output support:

  ```cpp
  cin >> s4;
  cout << s4 << endl;
  ```
* Fully overloaded comparison operators: `==`, `!=`, `<`, `<=`, `>`, `>=`
* Robust concatenation logic (8 use-cases covered):

  ```cpp
  String s = "Hello" + s2 + " Again" + '!';
  ```
* STL-style iterators: `begin()`, `end()`
* Move semantics: Move constructor and move assignment
* Dynamic memory management with deep copy support
* Length synchronization per object instance

## 🔧 Implementation Highlights

### Member Functions

```cpp
// Constructors and Destructor
String();                         // Default
String(const char* p);            // Parameterized
String(String&& other);           // Move
String(String& other);            // Deep Copy
~String();                        // Destructor

// Core Methods
void getstr();
int len();
char* begin();
char* end();

// Assignment Overloads
String& operator=(String& s2);
String& operator=(const char* ptr);
String& operator=(String&& other);

// Concatenation Overloads
String operator+(String&);
String& operator+=(String&);
String operator+(const char*);
String& operator+=(const char*);
String operator+(const char);
String& operator+=(const char);

// Access and Comparison
char& operator[](int i);
bool operator>(String& s2);
bool operator<(String& s2);
bool operator>=(String& s2);
bool operator<=(String& s2);
bool operator!=(String& s2);
bool operator==(String& s2);
```

### Friend Functions

```cpp
friend ostream& operator<<(ostream&, String&);
friend istream& operator>>(istream&, String&);

// Concatenation
friend String operator+(const char*, String&);
friend String operator+(const char, String&);

// Custom String Functions
friend unsigned int my_strlen(String&);
friend void my_strcpy(String&, String&);
friend void my_strncpy(String&, const String&, unsigned int);
friend int my_strcmp(const String&, const String&);
friend void my_strcat(String&, const String&);
friend void my_strncat(String&, const String&, unsigned int);
friend String& my_strrev1(String&);
friend void my_strrev2(String&, String&);
friend String& my_strupper(String&);
friend String& my_strlower(String&);
friend bool my_strchr(String&, char);
friend bool my_strrchr(String&, char);
friend bool my_strstr(const String&, const String&);
```

## ✅ Concatenation Support

| Expression    | Implementation Type | Status        |
| ------------- | ------------------- | ------------- |
| `s1 + s2`     | Member function     | ✅ Implemented |
| `s1 += s2`    | Member function     | ✅ Implemented |
| `s1 + "abc"`  | Member function     | ✅ Implemented |
| `"abc" + s1`  | Friend function     | ✅ Implemented |
| `s1 += "abc"` | Member function     | ✅ Implemented |
| `s1 + 'a'`    | Member function     | ✅ Implemented |
| `'a' + s1`    | Friend function     | ✅ Implemented |
| `s1 += 'a'`   | Member function     | ✅ Implemented |

📌 Note: `'a' += s1` is invalid due to immutability of literals.

## 🧪 Sample Test Cases

Demonstrated in `main.cpp`:

* Construction, copy, move semantics
* String mutation using `[]` operator
* All concatenation variations
* Comparison logic
* Stream input/output
* Iterator usage
* length synchronization across all instances

## 🛠️ Technologies Used

* C++
* GNU Make
* Valgrind (memory leak checks)
* Vi editor (development environment)

## 📁 Project Structure

```
.
├── String.hpp / String.cpp    # Class declaration and definition
├── main.cpp                   # Test cases for all features
└── Makefile                   # Build automation
```

## 📸 Output Snippet

```bash
s1 = sector india
s2 = bangalore
Length of s2 = 9
s3 = s1 + s2 => sector indiabangalore
s3 += s1 => sector indiabangaloresector india
s3 = s1 + "vector" => sector indiavector
s3 = "vector" + s1 => vectorsector india
s3 += "Vector" => vectorsector indiaVector
s3 = s1 + 'x' => sector indiax
s3 = 'x' + s1 => xsector india
s3 += 'x' => xsector indiax
...
```

---

This project showcases a deep understanding of C++ internals and strong command over modern object-oriented principles. Ideal for roles involving low-level system programming, high-performance applications, or custom STL-style library design.

---
