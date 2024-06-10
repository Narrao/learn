#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;

class fraction
{
private:
    int  numerator;//分子
    int denominator;//分母
public:
    fraction();//default ctor
    ~fraction();
    fraction(int a,int b);//Ctor takes two integers as parameters
    fraction(const fraction& obj);//copy ctor

    void simplify(){//约分使分数到最简
        int sign=1;
        if (denominator*numerator < 0) { // 确保分母为正
            denominator = abs(denominator);
            numerator=abs(numerator);
            sign=-1;
        }
        int gcd=__gcd(numerator,denominator);
        numerator/=gcd;
        numerator*=sign;
        denominator/=gcd;
    }
    void display(){
        simplify();
        cout<<numerator<<"/"<<denominator<<endl;
    }
    int getNumerator(){
        return numerator;
    };
    int getDenominator(){
        return denominator;
    };
    // Arithmetical operators: + - * /
    fraction operator+(const fraction& x) const{
        return fraction(this->numerator*x.denominator+this->denominator*x.numerator,this->denominator*x.denominator);
    };
    fraction operator-(const fraction& x) const{
        return fraction(this->numerator*x.denominator-this->denominator*x.numerator,this->denominator*x.denominator);
    };
    fraction operator*(const fraction& x) const{
        return fraction(this->numerator*x.numerator,this->denominator*x.denominator);
    };
    fraction operator/(const fraction& x) const{
        return fraction(this->numerator*x.denominator,this->denominator*x.numerator);
    };

    // Relational operators: < <= == != >= >
    bool operator<( const fraction& x) const{
        return this->numerator*x.denominator < x.numerator*this->denominator;
    }; 
    bool operator<=( const fraction& x) const{
        return this->numerator*x.denominator <= x.numerator*this->denominator;
    }; 
    bool operator>( const fraction& x) const{
        return this->numerator*x.denominator > x.numerator*this->denominator;
    }; 
    bool operator>=( const fraction& x) const{
        return this->numerator*x.denominator >= x.numerator*this->denominator;
    };
    bool operator==( const fraction& x) const{
        return this->numerator == x.numerator && this->denominator == x.denominator;
    }; 
    bool operator!=( const fraction& x) const{
        return !(this->numerator == x.numerator && this->denominator == x.denominator);
    }; 

    // Typecast to double
    operator double() const{
        return numerator/(double)denominator;
    };

    // To string
    operator string() const{
        return to_string(numerator)+"/"+to_string(denominator);
    };

    // Inserter and extractor for streams
    friend istream& operator>>(istream& is,fraction& obj){  //流提取运算符
        // char ws;
        int numerator, denominator;
        is>>numerator;
        is.ignore(numeric_limits<streamsize>::max(), '/'); // 忽略直到 '/' 出现
        is>> denominator;

        obj=fraction(numerator,denominator);
        obj.simplify();
        return is;
    };
    friend ostream& operator<<(ostream& os,const fraction& obj){    //流插入运算符
        os<<obj.numerator<<"/"<<obj.denominator;
        return os;
    };

    // Conversion from a finite decimal string like: 1.414
    static fraction fromDecimalString(const string& DecimalString){
        // 将字符串小数转换成分数
        int dotPos = DecimalString.find('.');
        int numDigitsAfterDot = DecimalString.size() - dotPos - 1;
        int numerator = stoi(DecimalString.substr(0, dotPos) + DecimalString.substr(dotPos + 1));
        int denominator = pow(10, numDigitsAfterDot);
        return fraction(numerator, denominator);
    };
};

fraction::fraction()
{   
    cout<<"默认构造函数"<<endl;
}

fraction::~fraction()
{
    cout<<"析构函数"<<endl;
}

fraction::fraction(int a, int b)
{
    
    numerator=a;
    denominator=b;
    simplify();
}

inline fraction::fraction(const fraction &obj)
{
    this->denominator=obj.denominator;
    this->numerator=obj.numerator;
}

#endif