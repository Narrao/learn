#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#define PI 3.141592653589
#define NM 1852
using namespace std;

int x_(double x){
    return (int)(x/0.02);
}

int y_(double y){
    return (int)(y/0.02);
}

class sea{
    private:
        double m[201][251];
        double p1_x,p1_y,p2_x,p2_y,p3_x,p3_y;
    public:
        sea()
        {
            freopen("sea.csv","r",stdin);
            double depth;
            char c;
            for(int i=0;i<=250;i++)
            {
                for(int j = 0;j<=200;j++)
                {
                    cin >> depth >> c;
                    m[j][i] = depth;
                }
            }
            // cout << "{";
            // for(int i=0;i<=200;i++)
            // {
            //     cout << "{";
            //     for(int j = 0;j<250;j++)
            //     {
            //         cout << m[i][j] << ",";
            //     }
            //     cout <<m[i][250] << "},";
            // }
            // cout << "}" << endl;
        }

        double getDepth(double x,double y)
        {
            return m[x_(x)][y_(y)];
        }

        void findTriangle(double x,double y){
            double y1 = 0.02 * (int)(y / 0.02);
            double y2 = 0.02 * (int)(y / 0.02) + 0.02;
            double x1 = 0.02 * (int)(x / 0.02);
            double x2 = 0.02 * (int)(x / 0.02) + 0.02;
            p1_x = x1;
            p1_y = y1;
            p2_x = x2;
            p2_y = y1;
            if(x-x1<0.01){
                p3_x = x1;
                p3_y = y2;
            }else{
                p3_x = x2;
                p3_y = y2;
            }
        }

        double getNowDepth(double x,double y){
            findTriangle(x,y);
            double z1 = m[x_(p1_x)][y_(p1_y)];
            double z2 = m[x_(p2_x)][y_(p2_y)];
            double z3 = m[x_(p3_x)][y_(p3_y)];
            double z = z1 - (z2-z1)*(x-p1_x)/0.02 - (z3-z1)*(y-p1_y)/0.02;
            return z;
        }

        double getgamma(double bt_,double x,double y){
            findTriangle(x,y);
            double x1 = x + 0.005*sin(bt_);
            double y1 = y - 0.005*cos(bt_);
            double gamaa_=atan((getNowDepth(x1,y1)-getNowDepth(x,y))/(0.005*NM));
            return gamaa_;
        }
};

class Solver{
    private:
        sea s;
        double bt_;
        double theta_;
        double eta;
        double ds[401];
        double total;
        double loss;
        double overlen;
    public:
        Solver(double bt,double theta,double eta):eta(eta){
            bt_ = bt*PI/180;
            theta_ = theta*PI/180;
            ds[200] = 0;
            for(int k =0;k<401;k++){
                ds[k] = 0;
            }
            total = 0;
            loss = 0;
            overlen = 0;
        }
        void solve(){
            double w1,w2,d,des,depth,w,x,gamma_,x1,x2,y,eta_;
            double d1[100000],d2[100000];
            int i=1,j=1;
            gamma_ = s.getgamma(bt_,0,0);
            depth = s.getNowDepth(0,0);
            point_x(0,x1,x2);
            total = total + lenx(x1,x2,bt_);
            w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
            w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
            d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * depth) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
            ds[200+j]=d;
            d = (eta * (w1 + w2) - w2 - (sin(theta_ / 2) * depth) / sin(PI / 2 - gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 - gamma_ - theta_ / 2) - 1 / cos(gamma_));
            ds[200-i]=-d;

            while(1){
                for(int k=0;k<100000;k++){
                    d1[k] = 0;
                }
                point_x(ds[200+j],x1,x2);
                total = total + lenx(x1,x2,bt_);
                depth = s.getNowDepth(x1/NM,x2/NM);
                gamma_ = s.getgamma(bt_,x1/NM,x2/NM);
                w = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
                x=(ds[200+j]/cos(bt_)+4*NM/tan(bt_))/(tan(bt_)+1/tan(bt_));
                des = (4*NM-x)/cos(bt_);
                if(w>des||des<0){
                    break;
                }
                int n = 0;
                for(double k = x1;k<=x2;k+=1){
                    y=tan(bt_)*k-ds[200+j]/cos(bt_);
                    depth = s.getNowDepth(k/NM,y/NM);
                    gamma_ = s.getgamma(bt_,k/NM,y/NM);
                    w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
                    w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
                    d = (eta * (w1 + w2) - w1 - (sin(theta_ / 2) * depth) / sin(PI / 2 + gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 + gamma_ - theta_ / 2) - 1 / cos(gamma_));
                    d1[n] = d;
                    n++;
                    eta_ = (w2+(sin(theta_/2)*(depth+(ds[200+j]-ds[200+j-1])*tan(gamma_))/sin(PI/2+gamma_-theta_/2))-(ds[200+j]-ds[200+j-1])/cos(gamma_))/(w1+w2);
                    if(eta_<0) loss -= eta_*(w1+w2)*1.0/cos(gamma_);
                    else if(eta_>0.2) 
                        overlen += abs(1.0/cos(gamma_));
                }
                j++;
                ds[200+j] = ds[200+j-1] + min_(d1);
            }
            while(1){
                for(int k=0;k<100000;k++){
                    d2[k] = 0;
                }
                point_x(ds[200-i],x1,x2);
                total = total + lenx(x1,x2,bt_);
                depth = s.getNowDepth(x1/NM,x2/NM);
                gamma_ = s.getgamma(bt_,x1/NM,x2/NM);
                w = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
                x=(ds[200-i]/cos(bt_)+5*NM)/(tan(bt_)+1/tan(bt_));
                des = x/cos(bt_);
                if(w>des||des<0){
                    break;
                }
                int n = 0;
                for(double k = x1;k<=x2;k+=1){
                    y=tan(bt_)*k-ds[200-i]/cos(bt_);
                    depth = s.getNowDepth(k/NM,y/NM);
                    gamma_ = s.getgamma(bt_,k/NM,y/NM);
                    w1 = (sin(theta_ / 2) * depth) / (sin(PI / 2 - gamma_ - theta_ / 2));
                    w2 = (sin(theta_ / 2) * depth) / (sin(PI / 2 + gamma_ - theta_ / 2));
                    d = (eta * (w1 + w2) - w2 - (sin(theta_ / 2) * depth) / sin(PI / 2 - gamma_ - theta_ / 2)) / (sin(theta_ / 2) * tan(gamma_) / sin(PI / 2 - gamma_ - theta_ / 2) - 1 / cos(gamma_));
                    d2[n] = d;
                    n++;
                    eta_ = (w2+(sin(theta_/2)*(depth+(ds[200-i]-ds[200-i+1])*tan(gamma_))/sin(PI/2-gamma_-theta_/2))-(ds[200-i]-ds[200-i+1])/cos(gamma_))/(w1+w2);
                    if(eta_<0) loss -= eta_*(w1+w2)*1.0/cos(gamma_);
                    else if(eta_>0.2) 
                        overlen += abs(1.0/cos(gamma_));
                }
                i++;
                ds[200-i] = ds[200-i+1] - min_(d2);
            }
        }
        double gettotal(){
            return total;
        }
        double getloss(){
            return loss/(4*NM*5*NM);
        }
        double getoverlen(){
            return overlen;
        }
        void point_x(double sumd,double &x1,double &x2){
            if(bt_==PI/2){
                x1 = sumd;
                x2 = sumd;
            }else if(bt_==0){
                x1 = 0;
                x2 = 4*NM;
            }else{
                x1 = sumd/sin(bt_);
                x2 = x1 +5*NM/tan(bt_);
            }
            if(x1>4*NM){
                x1 = 4*NM;
            }
            if(x1<0){
                x1 = 0;
            }
            if(x2>4*NM){
                x2 = 4*NM;
            }
            if(x2<0){
                x2 = 0;
            }
        }
        double lenx(double x1,double x2,double bt_){
            double len_ = 0;
            if(x1==x2){
                len_ = 5*NM;
            }else if((x1==0&&x2==4*NM)||(x1==4*NM&&x2==0)){
                len_ = 4*NM;
            }else{
                len_ = abs((x2-x1)/cos(bt_));
            }
            return len_;
        }
        double min_(double d1[]){
            double min = 1000;
            for(int i=0;i<100000;i++){
                if(d1[i]>0&&d1[i]<min){
                    min = d1[i];
                }
            }
            return min;
        }



        
};



int main()
{
    // for(double bt =1;bt<90;bt+=1)
    // {
    //     for(double eta =-1;eta<=0.2;eta+=0.01)
    //     {
    //         Solver s(bt,120,eta);
    //         s.solve();
    //         printf("%lf ,%lf ,%lf ,%lf ,%lf\n",bt,eta,s.gettotal(),s.getloss(),s.getoverlen());
    //     }
    // }
    Solver s(60,120,-2);
    s.solve();
    printf("%lf ,%lf ,%lf ,%lf ,%lf\n",30.0,0.1,s.gettotal(),s.getloss(),s.getoverlen());
    sleep(100);
    system("pause");
    return 0;
}