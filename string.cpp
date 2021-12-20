#include <cstring> 
#include <iostream>
#include <vector>
class String{
private:
    int n = 0;
    int last = 0;
    char* str = new char[0];
public:
    String() = default;
   /* String(const char* c): n(c.size()), last(c.size() * 2), str(new char[c.size() * 2]) {
        memcpy(c, str, n);
    }*/ //конструктор от C-style
    String(int n): n(n), last(n * 2), str(new char[n * 2]) {}
    String(int n, char c): n(n), last(n * 2), str(new char[n * 2]) {  //создание строки из длинны n из символа c
        memset(str, c, n);
    }
    String(String& other): n(other.n), last(n), str(new char[other.n]){  //копирующий конструктор
        memcpy(other.str, str, n);
    }
    String& operator=(String& other){  //оператор присваивания
        String copy = other;
	swap(copy);
	return *this;
    }
    ~String(){
        delete[] str;
    }
    void swap(String& other){ //свап двух стрингов
        std::swap(other.n, n);
	std::swap(other.str, str);
	std::swap(other.last, last);
    }
    int length(){
        return n;
    }
    void cast(String& string, int n){ // делает строку string длинны n
        String copy(n);
        swap(copy);
    }
    void push_back(char c){
        n += 1;
	if(last == n){
       	    cast(*this, n);
	    return;
	}
        str[n - 1] = c;
    }
    void pop_back(){
        n -= 1;
	if(n <= last / 4){
	    cast(*this, n);
	    return;
        }
    }
    char& front(){
        return str[0];
    }
    char& back(){
        return str[n - 1];
    }

    String& operator+=(String& other){
        for(int i = 0; i < other.n; ++i){
	    push_back(other.str[i]);
        }
	return *this;
    }
    int find(String& string);
    int rfind(String& string);
    String& substr(int start, int count){
        String res(count);
	for(int i = start; i < count + start; ++i){
	    res.str[i - start] = str[i];
	}
	return res;
    }
    void clear(){
        String res(0);
	swap(res);
	return;
    }
    bool empty(){
        if(n == 0){
	    return true;
	}
	return false;
    }
    char& operator[](int i){
        return *(str + i);
    }
};

String& operator+(String& string, String& other){
    String copy = string;
    return copy += other;
}

int String::find(String& other){
    int k = 0;
    for(int i = 0; i < n; ++i){
        if(str[i] == other.str[k]){
	    k += 1;
	}
	else{
	    k = 0;
	}
	if(k == other.n){
	    return i - k - 1;
	}
    }
    return n;
}

int String::rfind(String& other){
    int k = other.n - 1;
    for(int i = n - 1; i >= 0; --i){
        if(str[i] == other.str[k]){
            k -= 1;
        }
        else{
            k = other.n - 1;
        }
        if(k == other.n){
            return i + k;
        }

    }
    return n;
}
/*
std::iostream& operator>>(std::iostream& in, String& string){
    string.clear();
    char c;
    while(in.peek() != '\n'){
        in >> c;
	string.push_back(c);
    }
    return in;
}

std::ofstream operator<<(std::ofstream& out, String& string){
    for(int i = 0; i < string.n; ++i){
        out << string.str[i];
    }
    return out;
}
*/
int main(){
    
}
