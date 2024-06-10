#include <easyx.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <wininet.h>
#include <thread>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

// 定义地图的大小
#define MAP_WIDTH 62
#define MAP_HEIGHT 42

// 定义像素的大小
#define PIXEL_SIZE 15


// 定义颜色
#define FOOD RED
#define SNAKE_HEAD WHITE

// 定义蛇的移动方向
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// 定义蛇头的初始位置
#define SNAKE_HEAD_X 20
#define SNAKE_HEAD_Y 20

using namespace std;

// 游戏初始参数
int score = 0;
int speed = 120;
int direction = RIGHT;

void drewCell(int x, int y, int color); // 画一个像素
void delCell(int x, int y); // 删除一个像素
void up();  //监控上键
void down();  //监控下键
void mleft();  //监控左键
void mright();  //监控右键
void esc();  //监控esc键

// 定义食物类
class food
{
private:
    int x;
    int y;
    friend class snake;  //方便蛇类访问
public:
    food()
    {
        srand((unsigned)time(NULL));
        x = rand() % (40) + 1;
        y = rand() % (40) + 1;
    }
    void draw()     //画出食物图像
    {
        drewCell(x, y, FOOD);
    }
    void clear()    //清除食物图像
    {
        drewCell(x, y, WHITE);
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }

};

class snake
{
private:
    int x;
    int y;
    snake* next;
public:
    snake()
    {
        x = SNAKE_HEAD_X;
        y = SNAKE_HEAD_Y;
        next = NULL;
    }
    void move(int direction, food* f)  
    {
        //创建p节点，用于保存蛇头的位置
        snake* p = new snake;
        p->x = this->x;
        p->y = this->y;
        switch (direction)
        {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        }
        drewCell(x, y, SNAKE_HEAD);     //画出移动后蛇头

        //把后面的节点都往前移动一格
        snake* q = this->next;
        while (q != NULL)
        {
            int tempX = q->x;
            int tempY = q->y;
            q->x = p->x;
            q->y = p->y;
            p->x = tempX;
            p->y = tempY;
            q = q->next;
        }

        //判断是否吃到食物，是则在尾部添加一个节点，否则删除尾部节点图像
        if (isEatFood(f))
        {
            f->clear();
            do
            {
            f->setX(rand() % 40+ 1);
            f->setY(rand() % 40 + 1);
            }while (f->getX() == this->getX() && f->getY() == this->getY()||(f->getX()>40||f->getX()<=0)||(f->getY()>40||f->getY()<=0));
            f->draw();
            score += 1;
            if (score % 5 == 0)
            {
                speedUp();
            }
            snake* sn = new snake;
            sn->x = p->x;
            sn->y = p->y;
            sn->next = NULL;
            snake* t = this;
            while(t->next!=NULL)
            {
                t = t->next;
            }
            t->next = sn;
        }
        else   
        {
            delCell(p->x, p->y);
        }

    }
    bool isEatSelf()        //判断是否吃到自己
    {
        snake* p = this->next;
        while (p != NULL)
        {
            if (p->x == this->x && p->y == this->y)
            {
                return true;
            }
            p = p->next;
        }
        return false;
    }
    bool isHitWall()        //判断是否撞墙
    {
        if (this->x == 0 || this->x == 41 || this->y == 0 || this->y == 41)
        {
            return true;
        }
        return false;
    }
    bool isEatFood(food* f)     //判断是否吃到食物
    {
        if (this->x == f->x && this->y == f->y)
        {
            return true;
        }
        return false;
    }
    void speedUp()      //加速
    {
        if(speed>40)speed -= 10;
    }
    void speedDown()        //减速
    {
        if(speed<120)speed += 10;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    snake* getNext()
    {
        return next;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    void setNext(snake* next)
    {
        this->next = next;
    }
};

//定义历史数据类
class data
{
    private:
        string filename;        //文件名
        vector<int> score;      //存储数据
    public:
        data(string filename)       //初始化文件名
        {
            this->filename = filename;
        }
        void read()     //读取文件，如果不存在则创建文件
        {
            ifstream in(filename);
            if(!in)
            {
                ofstream out(filename);
                if(!out)
                {
                    cout<<"创建文件失败！"<<endl;
                    exit(1);
                }
            }
            int temp;
            while(in>>temp)
            {
                score.push_back(temp);
            }
            in.close();
        }
        void write()        //写入文件
        {
            ofstream out(filename);
            if(!out)
            {
                cout<<"打开文件失败！"<<endl;
                exit(1);
            }
            for(int i=0;i<score.size();i++)
            {
                out<<score[i]<<endl;
            }
            out.close();
        }
        istream& operator<<(int s)     //添加数据
        {
            score.push_back(s);
        }
        void msort()        //排序
        {
            sort(score.begin(),score.end(),greater<int>());
        }
        void show()     //显示数据
        {
            
            for(int i=10;i<score.size()*2+10;i+=2)
            {
                outtextxy(15*PIXEL_SIZE,i*PIXEL_SIZE,_T("第"));
                TCHAR str[10];
                _stprintf_s(str,_T("%d"),(i-8)/2);
                outtextxy(17*PIXEL_SIZE,i*PIXEL_SIZE,str);
                outtextxy(19*PIXEL_SIZE,i*PIXEL_SIZE,_T("名："));
                _stprintf_s(str,_T("%d"),score[(i-8)/2-1]);
                outtextxy(21*PIXEL_SIZE,i*PIXEL_SIZE,str);
            }
        }
        void clear()        //清除数据
        {
            score.clear();
        }
};

class map
{
private:
    int width;
    int height;
public:
    map(int w, int h)       //初始化地图大小
    {
        width = w;
        height = h;
    }
    void start()        //程序开始界面
    {
        //展示标题图片
        IMAGE image;
        TCHAR imagePath[] = _T("R.png");
        loadimage(&image, imagePath);
        putimage(18.5*PIXEL_SIZE,4*PIXEL_SIZE, &image);

        // settextcolor(0x800000);
        // outtextxy(27*PIXEL_SIZE,10*PIXEL_SIZE,_T("贪        吃        蛇"));

        //展示菜单
        settextcolor(RED);
        outtextxy(17*PIXEL_SIZE,20*PIXEL_SIZE,_T("1.开始游戏"));
        outtextxy(24*PIXEL_SIZE,20*PIXEL_SIZE,_T("2.游戏说明"));
        outtextxy(31*PIXEL_SIZE,20*PIXEL_SIZE,_T("3.历史成绩"));
        outtextxy(38*PIXEL_SIZE,20*PIXEL_SIZE,_T("4.退出游戏"));
        settextcolor(YELLOW);
        outtextxy(27*PIXEL_SIZE,30*PIXEL_SIZE,_T("请按数字键选择"));
        settextcolor(WHITE);
        outtextxy(40*PIXEL_SIZE,35*PIXEL_SIZE,_T("江紫檀 2022141460178"));

        //监听键盘输入，根据输入跳转到不同的界面
        while(true)
        {
            if(GetAsyncKeyState('1') & 0x8000)
            {   
                cleardevice();
                game();
                break;
            }
            if(GetAsyncKeyState('2') & 0x8000)
            {  
                cleardevice();
                explain();
                break;
            }
            if(GetAsyncKeyState('3') & 0x8000)
            {  
                cleardevice();
                log();
                break;
            }
            if(GetAsyncKeyState('4') & 0x8000)
            {  
                closegraph();
                exit(0);
                break;
            }
        }
    }

    //游戏界面
    void game()     
    {
        //画出游戏边界
        setlinecolor(WHITE);
        setlinestyle(PS_SOLID | PS_ENDCAP_FLAT);
        line(1*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE, 1*PIXEL_SIZE);       // 上边界线
        line(1*PIXEL_SIZE, 1*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE);     // 左边界线
        line(1*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE); // 下边界线
        line(41*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE);   // 右边界线

        //展示游戏信息和说明
        outtextxy(45*PIXEL_SIZE,5*PIXEL_SIZE,_T("得分："));
        TCHAR str[10];
        _stprintf_s(str,_T("%d"),score);
        outtextxy(48*PIXEL_SIZE,5*PIXEL_SIZE,str);
        outtextxy(45*PIXEL_SIZE,10*PIXEL_SIZE,_T("每个食物得分：1"));
        outtextxy(45*PIXEL_SIZE,15*PIXEL_SIZE,_T("不能撞墙，不能撞自己！"));
        outtextxy(45*PIXEL_SIZE,20*PIXEL_SIZE,_T("用方向键控制蛇的移动方向！"));
        outtextxy(45*PIXEL_SIZE,25*PIXEL_SIZE,_T("F1键加速，F2键减速！"));
        outtextxy(45*PIXEL_SIZE,30*PIXEL_SIZE,_T("按空格键暂停，按BACK键继续！"));
        outtextxy(45*PIXEL_SIZE,35*PIXEL_SIZE,_T("按ESC键退出！"));

        // 初始化蛇和食物
        snake* head = new snake;
        snake* p = new snake;
        head->setX(21);
        head->setY(20);
        p->setNext(NULL);
        head->setNext(p);
        food food;
        do
        {
            food.setX(rand() % 40+ 1);
            food.setY(rand() % 40 + 1);
        }while (food.getX() == head->getX() && food.getY() == head->getY()||(food.getX()>40||food.getX()<=0)||(food.getY()>40||food.getY()<=0));
        food.draw();
        head->move(direction,&food);

        //监听键盘输入，根据输入执行不同的操作
        while(true)
        {
            if(GetAsyncKeyState(VK_SPACE)&0x8000)  //暂停
            {
                while(true)
                {
                    if(GetAsyncKeyState(VK_BACK)&0x8000)
                    {
                        break;
                    }
                }
            }
            if(GetAsyncKeyState(VK_F1)&0x8000)      //加速
            {
                head->speedUp();
            }
            if(GetAsyncKeyState(VK_F2)&0x8000)      //减速
            {
                head->speedDown();
            }
            if(head->isEatSelf()||head->isHitWall())        //判断是否结束游戏
            {
                while(head->getNext()!=NULL)
                {
                    snake* p = head->getNext();
                    head->setNext(p->getNext());
                    delete p;
                }
                cleardevice();
                endgame();
            }

            head->move(direction,&food);    //移动蛇

            //刷新得分
            delCell(48,5);  
            TCHAR str[10];
            _stprintf_s(str,_T("%d"),score);
            outtextxy(48*PIXEL_SIZE,5*PIXEL_SIZE,str);

            //恢复可能被删除的边界线
            line(1*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE, 1*PIXEL_SIZE);       // 上边界线
            line(1*PIXEL_SIZE, 1*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE);     // 左边界线
            line(1*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE); // 下边界线
            line(41*PIXEL_SIZE, 1*PIXEL_SIZE, 41*PIXEL_SIZE, 41*PIXEL_SIZE);   // 右边界线

            //延时以控制蛇的移动速度
            Sleep(speed);
        }
        
        
    }

    //游戏说明界面
    void explain()
    {
        outtextxy(27*PIXEL_SIZE,10*PIXEL_SIZE,_T("游戏说明："));
        outtextxy(27*PIXEL_SIZE,15*PIXEL_SIZE,_T("1.不能撞墙，不能撞自己！"));
        outtextxy(27*PIXEL_SIZE,20*PIXEL_SIZE,_T("2.用方向键控制蛇的移动方向！"));
        outtextxy(27*PIXEL_SIZE,25*PIXEL_SIZE,_T("3.F1键加速，F2键减速！"));
        outtextxy(27*PIXEL_SIZE,30*PIXEL_SIZE,_T("4.按空格键暂停，按ESC键退出！"));
        outtextxy(27*PIXEL_SIZE,35*PIXEL_SIZE,_T("5.按空格键返回！"));
        while (true)
        {
            if(GetAsyncKeyState(VK_SPACE) & 0x8000)
            {   
                cleardevice();
                start();
                break;
            }
        }
    }

    //游戏结束界面
    void endgame()
    {
        outtextxy(27*PIXEL_SIZE,10*PIXEL_SIZE,_T("游戏结束！"));
        outtextxy(27*PIXEL_SIZE,20*PIXEL_SIZE,_T("得分："));
        TCHAR str[10];
        _stprintf_s(str,_T("%d"),score);
        outtextxy(30*PIXEL_SIZE,20*PIXEL_SIZE,str);
        outtextxy(27*PIXEL_SIZE,24*PIXEL_SIZE,score);
        outtextxy(27*PIXEL_SIZE,25*PIXEL_SIZE,_T("按ESC键退出！"));
        outtextxy(27*PIXEL_SIZE,30*PIXEL_SIZE,_T("按空格键回到主菜单！"));

        //把得分写入文件
        data d("score.txt");
        d.read();
        d<<score;
        d.msort();
        d.write();

        while (true)
        {
            if(GetAsyncKeyState(VK_SPACE) & 0x8000)
            {   
                score = 0;
                speed = 120;
                direction = RIGHT;
                cleardevice();
                start();
                break;
            }
        }
        
    }

    //历史成绩界面
    void log()
    {
        settextstyle(20,0,_T("宋体"));
        outtextxy(27*PIXEL_SIZE,3*PIXEL_SIZE,_T("历史成绩："));

        //读取文件中的数据并排序后显示
        data d("score.txt");
        d.read();
        d.msort();
        d.show();

        outtextxy(27*PIXEL_SIZE,38*PIXEL_SIZE,_T("按C键清除所有记录！"));
        outtextxy(27*PIXEL_SIZE,40*PIXEL_SIZE,_T("按空格键返回！"));
        while (true)
        {
            if(GetAsyncKeyState('C') & 0x8000)
            {   
                d.clear();
                d.write();
                cleardevice();
                log();
                break;
            }
            if(GetAsyncKeyState(VK_SPACE) & 0x8000)
            {   
                cleardevice();
                start();
                break;
            }
        }
    }
};



int main()
{   
    //初始化窗口
    initgraph(MAP_WIDTH * PIXEL_SIZE, MAP_HEIGHT * PIXEL_SIZE);
    map m(MAP_WIDTH, MAP_HEIGHT);

    //创建线程，用于监听键盘输入
    thread t1(up);
    thread t2(down);
    thread t3(mleft);
    thread t4(mright);
    thread t5(esc);

    //进入开始界面
    m.start();

    closegraph();
    return 0;
}

void drewCell(int x, int y, int color)
{
    setfillcolor(color);
    fillrectangle(x * PIXEL_SIZE, y * PIXEL_SIZE, (x + 1) * PIXEL_SIZE, (y + 1) * PIXEL_SIZE);

}

void delCell(int x, int y)
{
    setfillcolor(BLACK);
    clearrectangle(x * PIXEL_SIZE, y * PIXEL_SIZE, (x + 1) * PIXEL_SIZE, (y + 1) * PIXEL_SIZE);
}

void up()
{
    while (true)
    {
        if(GetAsyncKeyState(VK_UP)&0x8000)
        {
            if(direction != DOWN)
            {
                direction = UP;
            }
        }
    }
}

void down()
{
    while(true)
    {
        if(GetAsyncKeyState(VK_DOWN)&0x8000)
        {
            if(direction != UP)
            {
                direction = DOWN;
            }
        }
    }
}

void mleft()
{
    while (true)
    {
        if(GetAsyncKeyState(VK_LEFT)&0x8000)
        {
            if(direction != RIGHT)
            {
                        direction = LEFT;
            }
        }
    }
}

void mright()
{
    while (true)
    {
        if(GetAsyncKeyState(VK_RIGHT)&0x8000)
        {
            if(direction != LEFT)
            {
                direction = RIGHT;
            }
        }
    }
}

void esc()
{
    while (true)
    {
        if(GetAsyncKeyState(VK_ESCAPE)&0x8000)
        {
            exit(0);
        }
    }
}