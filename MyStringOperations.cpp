
class MyString
{
private:
    char *str;
public:
    MyString();
    MyString(const char* s);
    friend MyString operator+(MyString s1,MyString s2);
    MyString operator=(MyString s);
    MyString operator=(char* s);
    MyString operator[](int n);
    MyString operator==(MyString s);
    MyString operator<(MyString s);
    MyString operator>(MyString s);
    MyString operator<<(MyString s);
    MyString operator>>(MyString s);
};