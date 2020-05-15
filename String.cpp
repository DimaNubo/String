#include"String.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

String::String()
{
    m_data = new char[1];
    m_data[0] = 0;
    m_size = 1;
}

String::String(const char* strok)
{
    m_data = NULL;
    m_size = strlen(strok) + 1;
    m_data = new char[m_size + 1];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = strok[i];
    }
    m_data[m_size] = 0;
}

String::String(const String& strok)
{
    m_size = strok.getLength();
    m_data = new char[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = strok[i];
    }
}

String::String(const String& strok, int start, int end)
{
    m_data = NULL;
    m_size = end - start + 2;
    m_data = new char[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = strok[start + i];
    }
    m_data[m_size - 1] = 0;
}
String::~String()  
{
    delete[] m_data;
}

int String::getLength() const
{
    return m_size;
}

String String::operator+(const String& strok) const
{
    String sum(*this);
    sum.setSize(m_size + strok.getLength() - 1);
    for (int i = m_size - 1; i < sum.getLength(); i++) {
        sum[i] = strok[i - (m_size - 1)];
    }
    return sum;
}

String String::operator+(const char c)const {
    String res(*this);
    if (res.m_size != 1) {
        res.setSize(m_size + 1);
    }
    else {
        res.setSize(m_size + 2);
    }
    res[res.getLength() - 2] = c;
    return res;
}
String& String::operator=(const String& strok) {
    if (*this == strok) {
        return *this;
    }
    if (m_data != NULL) {
        delete[] m_data;
    }
    m_size = strok.getLength();
    m_data = NULL;
    m_data = new char[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = strok[i];
    }
    return *this;
}

String& String::operator=(const char* c) {
    String temp(c);
    *this = temp;
    return *this;
}

bool String::operator==(const String& strok) const {
    if (m_size == strok.getLength()) {
        int i = 0;
        while (m_data[i] == strok[i]) {
            i++;
        }
        if (i == m_size)
        {
            return true;
        }
    }
    return false;
}


bool String::operator<(const String& strok) const {
    for (int i = 0; i < (m_size < strok.getLength() ? m_size : strok.getLength()); i++) {
        if (m_data[i] < strok[i]) return true;
        else if (m_data[i] > strok[i]) return false;
    }
    return false;
}

bool String::operator>(const String& strok) const {
    for (int i = 0; i < (m_size < strok.getLength() ? m_size : strok.getLength()); i++) {
        if (m_data[i] > strok[i]) return true;
        else if (m_data[i] < strok[i]) return false;
    }
    return false;
}

char& String::operator[](int number) const {
    return m_data[number];
}

void String::copy(const String& strok, int start, int end) {
    String copy(strok, start, end);
    *this = copy;
}

int String::pods(const char c)
{
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == c)
            return i;
    return 0;
}
int String::last(const char c)
{
    int last = 0;
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == c)
            last = i;
    return last;
}
int String::pos(const char* strok)
{
    int sizechar = strlen(strok);
    int count = 0;
    int  i;
    for (i = sizechar; i < m_size; i++)
    {
        if (m_data[i] == strok[i])
            count++;
        else
            count = 0;
        if (count == sizechar)
            break;
    }
    if (count == sizechar)
        return i - count;
    return 0;
}
int String::lastcount(const char c)
{
    int count = 0;
    for (int i = 0; i < m_size; i++)
        if (m_data[i] == c)
            count++;
    return count;
}
String* String::part(char c)
{
    int count = this->lastcount(c);
    String* res = NULL;
    int arraysize;
    if (m_size - 2 != this->last(c) || this->pods(c) != 0)
    {
        arraysize = count + 1;
        res = new String[arraysize];
    }
    else
    {
        arraysize = count;
        res = new String[arraysize];
    }
    res[0] = *this;
    for (int i = 1; i < arraysize; i++)
    {
        int start = res[i - 1].pods(c);
        int end = res[i - 1].getLength() - 1;
        String copy(res[i - 1], start + 1, end);
        res[i] = copy;
        res[i - 1].setSize(start + 1);
    }
    return res;
}
String String::repeater(String& strok, int razmer)
{
    if (strok.getLength() == 0)
        throw "getLength = 0";
    String res(strok);
    for (int i = 0; i < razmer - 1; i++)
    {
        res = res + strok;
    }
    return res;
}

void String::setSize(int razmer) {
    if (m_size != razmer) {
        int copysize = m_size;
        char* copy = m_data;
        m_size = razmer;
        m_data = NULL;
        m_data = new char[m_size];
        if (razmer >= copysize) {
            for (int i = 0; i < copysize; i++)
                m_data[i] = copy[i];
            m_data[razmer - 1] = 0;
        }
        else {
            for (int i = 0; i < razmer; i++)
                m_data[i] = copy[i];
            m_data[razmer - 1] = 0;
        }
        delete[] copy;
    }
}
ostream& operator<<(ostream& out, const String& strok) {
    out << strok.m_data << endl;
    return out;
}
istream& operator>>(istream& in, String& strok) {
    char get[256];
    in.getline(get, 256);
    String right(get);
    strok = right;
    return in;
}

