// String.h
#ifndef STRING_H
#define STRING_H

#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

// Non member function prototype
unsigned int mystrlen(const char *ptr);
void mystrcpy(char*, const char*, int);

/*** String class implementation ***/
class String{
	private: 
	char *str;
	unsigned int length;
	
	public:
 	/*** Constructor ***/
	String();		// default
	String(const char* p);	// parameterised
	String(String&& other); // move 
	String(String& t);	// deep copy
	~String();	
	/*** member function ***/
	void getstr(void);
	int len(void);
 	char* begin(void);
	char* end(void);	

	/*** operator overloaded member function ***/
	String& operator=(String& s2);
	String& operator=(const char* ptr);
	String& operator=(String&& other);  // Move assignment
	String operator +(String&);
	String& operator +=(String&);
	char& operator [](int i);
	bool operator >(String s2);
	bool operator <(String s2);
	bool operator >=(String s2);
	bool operator <=(String s2);
	bool operator !=(String s2);
	bool operator ==(String s2);

	friend ostream& operator <<(ostream& out, String& obj);
	friend istream& operator >>(istream& in, String& obj);
	friend String operator+(String& obj, const char* ptr);
	friend String operator+(const char* ptr, String& obj);
	friend String operator+(String& obj, const char ch);
	friend String operator+(const char ch, String& obj);

	/*** friend function ***/
	friend unsigned int my_strlen(String& s);
	friend void my_strcpy(String& s1, String& s2);
	friend void my_strncpy(String& dest, const String& src, unsigned const int len);
	friend int my_strcmp(const String& s1, const String& s2);
	friend void my_strcat(String& s1, const String& s2);
	friend void my_strncat(String& s1, const String& s2, unsigned const int len);
	friend String& my_strrev1(String& str);
	friend void my_strrev2(String& startAddr, String& endAddr);
	friend String& my_strupper(String& str);
	friend String& my_strlower(String& str);
	friend bool my_strchr(String& str, char ch);
	friend bool my_strrchr(String& str, char ch);
	friend bool my_strstr(const String& mainstr, const String& substr);
};

#endif // STRING_H

