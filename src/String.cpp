/*** default constructor; string s1; ***/
String :: String():str(nullptr), length(0){}

/*** parameterised constructor; string s2("Ranjan") ***/
String :: String(const char* p){
	length = mystrlen(p);
	str = new char[length+1];
	mystrcpy(str, p, length);
}
String::String(String&& other) {
    // Transfer ownership of resources
    str = other.str;
    length = other.length;

    // Null out the source
    other.str = nullptr;
    other.length = 0;
}
/*** deep copy constructor; s2 = s1; ***/
String :: String(String& t){
	length = t.length;
	//length = mystrlen(t.str);
	str = new char[length + 1];
	mystrcpy(str, t.str, length);
}

/*** member function ***/
void String :: getstr(){
	if(str==nullptr) return;
	cout<<str<<endl;
}
int String::len(){
	return length;
}
char* String :: begin(void){
	return str;
}

char* String :: end(void){
	//length = strlen(str);
	return str+length-1;
}

/*** operator overloaded member function ***/
String& String :: operator =(String& s1){    // s2 = s1;
	length = s1.length;
	delete str;
	str = new char[length+1];
	
	mystrcpy(str, s1.str, length);
	return *this;
}
String& String :: operator = (const char* ptr){
	length = mystrlen(ptr);
	delete str;
	str = new char[length+1];
	mystrcpy(str, ptr, length);
	
	return *this;
}
String& String::operator=(String&& other) {
    if (this != &other) {
        delete[] str;         // Free existing memory
        str = other.str;      // Steal the resource
        length = other.length;

        other.str = nullptr;  // Nullify source
        other.length = 0;
    }
    return *this;
}
String String :: operator +(String& s1){ // +ope principal: doesn't modify its operands
	String result;
	result.length = length + s1.length;
	result.str = new char[result.length +1];
	mystrcpy(result.str, str, result.length);

	for(int i=0; s1.str[i]; i++){
		result.str[length + i] = s1.str[i]; // overwrite '\0' with first character of s2.str
	}
	result.str[result.length] = '\0';
	return result;  // call move constructor rather than copy

}
String& String :: operator +=(String& s1){
        int i, j = length;
        length = length + s1.length;
        char* temp = new char[length + 1]; // str ko abhi free nhi kr skte
        mystrcpy(temp, str, length);
        for(i=0; s1.str[i]; i++){
                temp[j++] = s1.str[i]; // overwrite '\0' with first character of s1.str
        }
	temp[j] = '\0';
        delete str;     // free resource pointed by str as content already copied to temp;
        str = temp;     // str point the resource pointed by temp;
        temp = nullptr; // avoid temp to become dangling pointer
        return *this;   // safely return the object reference

}
char& String :: operator [](int index){
	if(str==nullptr){
		str = new char[10];
		return str[index];
	}
	if (index < 0 || index > length) 
		throw out_of_range("Index out of range");
	return str[index];
}
bool String :: operator >(String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) > *(s2.str+i);
		}
		i++;
	}
	return *(str+i) > *(s2.str+i);	
}
bool String :: operator <(String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) < *(s2.str+i);
		}
		i++;
	}
	return *(str+i) < *(s2.str+i);	

}
bool String :: operator >=(String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) >= *(s2.str+i);
		}
		i++;
	}
	return *(str+i) >= *(s2.str+i);	

}
bool String :: operator <=(String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) <= *(s2.str+i);
		}
		i++;
	}
	return *(str+i) <= *(s2.str+i);	

}
bool String :: operator != (String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) != *(s2.str+i);
		}
		i++;
	}
	return *(str+i) != *(s2.str+i);	

}
bool String :: operator ==(String s2){
	int i = 0;
	while(*(str+i) && *(s2.str+i)){
		if(*(str + i) != *(s2.str + i)){
			return *(str+i) == *(s2.str+i);
		}
		i++;
	}
	return *(str+i) == *(s2.str+i);	
	
	/*int i = 0;
	while(*(str+i)){
		if(*(str+i) != *(s2.str +i)){ // s2.str; might unauthorize memory access after '\0'
			return 0;
		}
		i++;
	}
	if(*(str+i) == '\0' && *(s2.str + i) == '\0')
		return 1;
	return 0;*/
}

/*** overloaded operator friend function ***/
ostream& operator <<(ostream& out, String& obj){
	out<<obj.str;
	return out;
}
istream& operator >>(istream& in, String& obj){
	if(obj.str == nullptr){ // String s4; cin>>s4; cout<<s4<<endl;

		fstream fin("input.txt", ios::in | ios::out | ios::trunc);
		if(!fin.is_open()) {
			cerr << "Error opening file\n";
			exit(1);
		}

		char ch;
		int count = 0, i =0;

		// Read characters from user and store to file
		while(1)
		{
			cin.get(ch);
			fin.put(ch);
			if (ch == '\n') break;
			count++;
		}

		obj.str = new char[count+1];
		obj.length = count;
		
		// Rewind file to beginning
		fin.seekg(0, ios::beg);
		while(1){
			fin.get(ch);
			if(ch == '\n'){
				obj.str[i] = '\0';
				break;
			}
			obj.str[i++] = ch;
		}
		fin.close();
		remove("input.txt"); // delete file to unnecessary fill hardisk
		return in;
	}
	in>>obj.str;
	return in;
}
String operator+(String& obj, const char* ptr){
    obj.length = obj.length + mystrlen(ptr);
    String temp;
    temp.str = new char[obj.length + 1];
    temp.length = obj.length;
    int i=0, j= 0;
    while(obj.str[i]){
        temp.str[i] = obj.str[i];
        i++;
    }
    while(ptr[j]){
        temp.str[i++] = ptr[j++];
    }
    temp.str[i]= '\0';
    
    return temp;
}
String operator+(const char* ptr, String& obj){
    String temp;
    temp.length = obj.length + mystrlen(ptr);
    temp.str = new char[obj.length + 1];
    
    int i=0, j= 0;
    
    while(ptr[i]){
        temp.str[i] = ptr[i];
        i++;
    }
    while(obj.str[j]){
        temp.str[i++] = obj.str[j++];
    }
    temp.str[i]= '\0';
    
    return temp;    
}
String operator+(String& obj, const char ch){
   String temp;
   temp.length = obj.length + 1;
   temp.str = new char[temp.length + 1];
   int i = 0;
   while(obj.str[i]){
       temp.str[i] = obj.str[i];
       i++;
   }
   temp.str[i++] = ch;
   temp.str[i] = '\0';
   
   return temp;
    
}
String operator+(const char ch, String& obj){
   String temp;
   temp.length = obj.length + 1;
   temp.str = new char[temp.length + 1];
   int i = 0, j=0;
   temp.str[i++] = ch;
   while(obj.str[j]){
       temp.str[i++] = obj.str[j++];
   }
   
   temp.str[i] = '\0';
   
   return temp;    
}

~String(){
		delete[] str;
		cout<<"memory deallocated"<<endl;
	}
