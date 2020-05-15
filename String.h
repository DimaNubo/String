#include <iostream>
using namespace std;

class String
{
public:

    // Конструкторы и деструктор
    String();
    String(const char* strok);
    String(const String& strok);
    String(const String& strok, int start, int end);
    ~String();

    //Метод класса
    int getLength() const;
    void copy(const String& strok, int start, int end);
    int pods(const char c);
    int last(const char c);
    int pos(const char* strok);
    int lastcount(const char c);
    String* part(char c);
    String repeater(String& strok, int n);
    //Перегрузка операторов
    String operator+(const String& strok)const;
    String operator+(const char c)const;
    bool operator==(const String& strok) const;
    String& operator=(const String& strok);
    String& operator=(const char* c);
    bool operator<(const String& strok)const;
    bool operator>(const String& strok)const;
    friend ostream& operator<< (ostream& out, const String& strok);
    friend istream& operator>> (istream& in, String& strok);
    char& operator[] (int number)const;

private:
    // Поля класса
    int m_size;
    char* m_data;
    void setSize(int razmer);
};
