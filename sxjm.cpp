#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#define PI 3.141592653589
using namespace std;
double length(double bt);
void point_x(double bata, double sumd, double &x1, double &x2);
double lenx(double x1, double x2, double bata_);
double min_(vector<double> v);
double max_(vector<double> v);
int main()
{
    cout<<endl<<length(89.9393);
    system("pause");
    return 0;
}

double length(double bt)
{
    double total = 0.0;
    double theta = 120.0;
    double alpha = 1.5;
    double D_0 = 110;
    double eta = 0.1;
    double w1,w2,d,des,depth,w,x;
    double theta_ = theta * PI / 180;
    double alpha_ = alpha * PI / 180;
    double bt_ = bt * PI / 180;
    double gamma_ = atan(tan(alpha_) * sin(bt_));

    double x1, x2;
    point_x(bt, 0, x1, x2);
    total += lenx(x1, x2, bt_);
    vector<double> ds={0};
    vector<double> d1;
    vector<double> d2;

    if (x1 == x2 && x1 == 0)
    {
        w1 = (sin(theta_ / 2) * D_0) / (sin(PI / 2 - gamma_ - theta_ / 2));
        w2 = (sin(theta_ / 2) * D_0) / (sin(PI / 2 + gamma_ - theta_ / 2));
        d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * D_0) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
        ds.push_back(d);
        ds.insert(ds.begin(), -d);
    }
    else
    {
        for (depth = D_0 - x1 * tan(alpha_); depth <= D_0 - x2 * tan(alpha_); depth += 0.1)
        {
            w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
            w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
            d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * depth) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
            d1.push_back(d);
            d = (eta * (w1 + w2) - w2 - (sin(theta_ / 2) * depth) / sin(PI / 2 - gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 - gamma_ - theta_ / 2) - 1 / cos(gamma_));
            d2.push_back(-d);
        }
        ds.push_back(min_(d1));
        ds.insert(ds.begin(), max_(d2));
    }

    while(1){
        d1.clear();
        point_x(bt,accumulate(ds.begin()+2,ds.end(),0),x1,x2);
        total += lenx(x1,x2,bt_);
        if(x1 == 2*1852&&x2==-2*1852){
            depth = D_0 - x1 * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 +alpha_ - theta_ / 2));
            des = 1852 - accumulate(ds.begin()+2,ds.end(),0);
        }else if(x1==x2){
            depth = D_0 - x1 * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 +gamma_ - theta_ / 2));
            des = 2*1852 - accumulate(ds.begin()+2,ds.end(),0);
        }else{
            x = (accumulate(ds.begin()+2,ds.end(),0)/cos(bt_)-2*1852/tan(bt_)+1852)/(tan(bt_)+1/tan(bt_));
            depth = D_0 - x * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 +gamma_ - theta_ / 2));
            des = (2*1852-x)/cos(bt_);
        }

        if (w>des||des<0){
            break;
        }
        if(x1==x2){
            depth = D_0 - x1 * tan(alpha_);
            w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
            w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
            d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * depth) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
            ds.push_back(d);
        }else{
            for(depth = D_0 - x1 * tan(alpha_);depth<=D_0 - x2 * tan(alpha_);depth+=0.1){
                w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
                w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
                d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * depth) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
                d1.push_back(d);
            }
            ds.push_back(min_(d1));
        }
    }
    int i =1;
    while(1){
        d2.clear();
        point_x(bt,accumulate(ds.begin(),ds.begin()+i,0),x1,x2);
        total += lenx(x1,x2,bt_);

        if(x1 ==2*1852&&x2==-2*1852){
            depth = D_0 - x1 * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 -alpha_ - theta_ / 2));
            des = 1852 + accumulate(ds.begin(),ds.begin()+i,0);
        }else if(x1==x2){
            depth = D_0 - x1 * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 -gamma_ - theta_ / 2));
            des = 2*1852 + accumulate(ds.begin(),ds.begin()+i,0);
        }else{
            x=(accumulate(ds.begin(),ds.begin()+i,0)/cos(bt_)+2*1852/tan(bt_)-1852)/(tan(bt_)+1/tan(bt_));
            depth = D_0 - x * tan(alpha_);
            w = (sin(theta_ / 2) * depth) / (sin(PI / 2 -gamma_ - theta_ / 2));
            des = (x+2*1852)/cos(bt_);
        }
        if(w>des||des<0){
            break;
        }

        if(x1==x2){
            depth = D_0 - x1 * tan(alpha_);
            w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
            w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
            d = (eta * (w1 + w2) - w2 - (sin(theta_ / 2) * depth) / sin(PI / 2 - gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 - gamma_ - theta_ / 2) - 1 / cos(gamma_));
            ds.insert(ds.begin(),-d);
        }else{
            for(depth = D_0 - x1 * tan(alpha_);depth<=D_0 - x2 * tan(alpha_);depth+=0.1){
                w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
                w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
                d = (eta * (w1 + w2) - w2 - (sin(theta_ / 2) * depth) / sin(PI / 2 - gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 - gamma_ - theta_ / 2) - 1 / cos(gamma_));
                d2.push_back(-d);
            }
            ds.insert(ds.begin(),max_(d2));
        }
        i++;
    }

    cout << "ds = ";
    for (int i = 0; i < ds.size(); i++)
    {
        cout << ds[i] << ", ";
    }
    return total;
}

void point_x(double bata, double sumd, double &x1, double &x2)
{
    if (bata == 90)
    {
        x1 = sumd;
        x2 = sumd;
    }
    else if (bata == 0)
    {
        x1 = 2 * 1852;
        x2 = -2 * 1852;
    }
    else
    {
        x1 = (1852 + sumd / cos(bata * PI / 180)) / tan(bata * PI / 180);
        x2 = (-1852 + sumd / cos(bata * PI / 180)) / tan(bata * PI / 180);
    }
    if (x1 > 2 * 1852)
        x1 = 2 * 1852;
    if (x2 > 2 * 1852)
        x2 = 2 * 1852;
    if (x1 < -2 * 1852)
        x1 = -2 * 1852;
    if (x2 < -2 * 1852)
        x2 = -2 * 1852;
}

double lenx(double x1, double x2, double bata_)
{
    double len_ = 0;
    if (x1 == x2)
    {
        len_ = 2 * 1852;
    }
    else if (x1 == 2 * 1852 && x2==-2*1852)
    {
        len_ = 4 * 1852;
    }
    else
    {
        len_ = (x1 - x2) / cos(bata_);
    }
    return len_;
}

double min_(vector<double> v)
{
    double min = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < min)
            min = v[i];
    }
    return min;
}

double max_(vector<double> v)
{
    double max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}