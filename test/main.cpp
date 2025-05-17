#include "String.h"
/*** main function ***/
int main(){
	
	String s1("vector india");
	s1[0] = 's';
	s1.getstr();	
	
	String s2 = "bangalore";
	s2.getstr();
	cout<<s2.len()<<endl;
	
	String s3;
	s3 = s1 + s2;
	s3.getstr();
	cout<<s3.len()<<endl;
	
	for(int i = 0; i<s3.len(); i++){
		cout<<s3[i]<<" ";
	}
	cout<<endl;
	
	/*String s4, s5;
	cout<<"enter s4 and s5"<<endl;
	cin>>s4>>s5;
	cout<<"S4:"<<s4<<endl; //failed
	cout<<"s4 len = "<<s4.len()<<endl;
	s5.getstr();
	cout<<"s5 len = "<<s5.len()<<endl;*/

	String s6; //failed
	for(int i = 0; i<5; i++){
		cin>>s6[i]; 
	}
	for(int i = 0; i<5; i++){
		cout<<s6[i]<<endl; 
	}
	cout<< "sizeof: "<<sizeof(String)<<endl;

	return 0;
}

/*
// main.cpp
#include "String.h"
#include <iostream>
using namespace std;

int main() {
    String s1("hello");
    String s2("world");
    String s3;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // Concatenation
    s3 = s1 + s2;
    cout << "s3 = s1 + s2: " << s3 << endl;

    // += operator
    s1 += s2;
    cout << "s1 += s2: " << s1 << endl;

    // Comparison
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 != s2: " << (s1 != s2) << endl;
    cout << "s1 > s2: " << (s1 > s2) << endl;
    cout << "s1 < s2: " << (s1 < s2) << endl;

    // Subscript operator
    cout << "s1[0]: " << s1[0] << endl;

    // Assignment from const char*
    s3 = "new string";
    cout << "s3 = \"new string\": " << s3 << endl;

    // Reversing
    cout << "Reversed s3: " << my_strrev1(s3) << endl;

    // Uppercase
    cout << "Upper s3: " << my_strupper(s3) << endl;

    // Lowercase
    cout << "Lower s3: " << my_strlower(s3) << endl;

    // Find character
    cout << "my_strchr(s3, 'S'): " << my_strchr(s3, 'S') << endl;

    // Find last occurrence
    cout << "my_strrchr(s3, 's'): " << my_strrchr(s3, 's') << endl;

    // Substring
    String sub("stri");
    cout << "my_strstr(s3, sub): " << my_strstr(s3, sub) << endl;

    return 0;
}


*/
