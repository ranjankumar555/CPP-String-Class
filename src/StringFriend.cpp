/*** friend function ***/
unsigned int my_strlen(String& obj){
	int i;
	while(*(obj.str+i++));
	return i;	
}
void my_strcpy(String& dest, String& src){
	int i = 0;
	if(dest.length >= src.length){ 
		while(*(src.str+i)){
			*(dest.str+i) = *(src.str+i);
			i++;
		}
		*(dest.str+i) = '\0';
	}
	else{
		delete[] dest.str;
		dest.str = new char[src.length + 1];
		dest.length = src.length;
		mystrcpy(dest.str, src.str, dest.length);
	}

}
void my_strncpy(String& dest, const String& src, unsigned const int len){
	int i = 0;
	if(dest.length >= len){
		while(i<len && *(src.str+i)){
			*(dest.str + i) = *(src.str + i);
			i++;
		}	
	}
	else{
		delete dest.str;
		dest.str = new char[src.length + 1];
		dest.length = src.length;

		while(i<len && *(src.str+i)){
			*(dest.str + i) = *(src.str + i);
			i++;
		}

	}
}
int my_strcmp(const String& s1, const String& s2){
	int i=0;
	while(*(s1.str + i)){
		if(*(s1.str + i) != *(s2.str+i)){
			return *(s1.str+i) - *(s2.str+i);
		}
		i++;
	}
	return *(s1.str+i) - *(s2.str+i);
}
void my_strcat(String& s1, const String& s2){
	int i=0, j=0;

	s1.length += s2.length;
	char *temp = new char[s1.length + 1];
	while(*(s1.str + i)){
		*(temp + i) = *(s1.str + i);
		i++;
	}
	
	while(*(s2.str+j)){
		*(temp+i) = *(s2.str+j);
		i++;
		j++;
	}
	*(temp+i) = '\0';
	delete[] s1.str;
	s1.str = temp;
	s1.length = i;
	temp = nullptr;
}
void my_strncat(String& s1, const String& s2, unsigned int len) {
    unsigned int copyLen = (len < s2.length) ? len : s2.length;

    int newLength = s1.length + copyLen;
    char* temp = new char[newLength + 1];

    int i = 0;
    for (; s1.str[i]; i++) {
        temp[i] = s1.str[i];
    }

    int j = 0;
    while (j < copyLen && s2.str[j]) {
        temp[i++] = s2.str[j++];
    }

    temp[i] = '\0';

    delete[] s1.str;

    s1.str = temp;
    s1.length = newLength;
}

String& my_strrev1(String& obj){
	int len, i, j;
	char temp;
	j = obj.length-1;
	
	for(i = 0; i<j; i++, j--){
		temp = *(obj.str+i);
		*(obj.str+i) = *(obj.str+j);
		*(obj.str+j) = temp;
	}
	return obj;
}
void strrev2(char* startAddr, char* endAddr){ // use own iterator concept; obj.begin(), obj.end()
        
    char temp;
    while(startAddr<endAddr){
        temp = *startAddr;
        *startAddr = *endAddr;
        *endAddr = temp;
        
        startAddr++;
        endAddr--;
    }
}

String& my_strupper(String& obj){
	int i;
	while(*(obj.str+i)){
		if(*(obj.str+i) >='a' && *(obj.str+i) <= 'z'){
			*(obj.str+i) ^= 32;

		}
		i++;
	}
	return obj;
}
String& my_strlower(String& obj){
	int i;
	while(*(obj.str+i)){
		if(*(obj.str+i) >='A' && *(obj.str+i) <= 'Z'){
			*(obj.str+i) ^= 32;
		}
		i++;
	}
	return obj;
}
bool my_strchr(String& obj, char ch){
	int i=0;
	while(*(obj.str + i)){
		if(*(obj.str+i) == ch){
			return 1;
		}
		i++;
	}
	return 0;
}
bool my_strrchr(String& obj, char ch){
	int len = mystrlen(obj.str)-1;
	while(len){
		if(*(obj.str+len) == ch){
			return 1;
		}
		len--;
	}
	return 0;
}
bool my_strstr(const String& mainstr, const String& substr){
        int i = 0, j = 0;
        while(*(mainstr.str+i)){
                if(*(mainstr.str+i) == substr.str[0]){

                        while(*(substr.str+j)){

                                if(*(mainstr.str+i)!=*(substr.str+j))
                                {
                                        j=0;
                                        break;
                                }
                                i++;
                                j++;
                        }
                        if(*(substr.str+j) == '\0'){
                                return 1;
                        }
                }
                i++;
        }
        return 0;
}
// Non member function definition
unsigned int mystrlen(const char *ptr){
	int len;
	for(len=0; ptr[len]; len++);
	return len;
}

void mystrcpy(char* dest, const char* src, int dlen){
	int i;
	for(i = 0; i<dlen && *(src+i); i++){
		*(dest+i) = *(src +i);
	}
	*(dest+i) = '\0';
}

