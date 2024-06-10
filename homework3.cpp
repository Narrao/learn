#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<map>

using namespace std;

//房间信息 
class Room{
public:
    virtual ~Room() {}
    map<string,Room*> exits;//出口连接各个房间
    int state=0;//普通房间为0，有公主为1，有怪兽为2
    virtual string getName() const=0;

    //用户输入后获取屏幕指令,描述房间信息
    void command(const Room* targetRoom){       
        cout << "Welcome to the"<< targetRoom->getName()<<". ";
        if (targetRoom->exits.size()>0)
        {
            cout << "There are"<<targetRoom->exits.size()<<"exits :";
            int i=0;
            for (auto& exit:targetRoom->exits)
            {
                cout << exit.first;
                i++;
                if (i!=targetRoom->exits.size()){
                    cout <<", ";
                }else{
                    cout <<"."<<endl;
                }                
            }
            cout<<"Enter your command:";
        }        
    }

    //根据出口，获取下一个房间
    Room* getExit(/*const Room* currentRoom,*/string& direction) const{
        auto it=exits.find(direction);
        if(it!=exits.end()){
            return it->second;//返回出口连接的下一个房间
        }
        return nullptr;//根据输入无法找到输出，则返回空指针
    }

  
};

class Lobby:public Room{
public:
    //获取房间名字
    string getName() const override { 
        return "lobby"; 
    }
};

class Bedroom:public Room{
public:
    Bedroom(int number) {
        // 使用 number 参数来设置房间的编号
        this->number = number;
    }
    //获取房间名字
    string getName() const override { 
        return "bedroom"; 
    }

private:
    int number;
};

class Kitchen:public Room{
public:
    //获取房间名字
    string getName() const override { 
        return "kitchen"; 
    }
};

class Bathroom:public Room{
public:
    Bathroom(int number) {
        // 使用 number 参数来设置房间的编号
        this->number = number;
    }
    //获取房间名字
    string getName() const override { 
        return "bathroom"; 
    }

private:
    int number;
};

class Balcony:public Room{
public:
    //获取房间名字
    string getName() const override { 
        return "balcony"; 
    }
};

int main(){
    vector<Room*> rooms;

    Room* lobby=new Lobby();
    Room* bedroom1=new Bedroom(1);
    Room* bedroom2=new Bedroom(2);
    Room* kitchen=new Kitchen();
    Room* bathroom1=new Bathroom(1);
    Room* bathroom2=new Bathroom(2);
    Room* balcony=new Balcony();
    //将房间存为数组
    rooms.push_back(lobby);
    rooms.push_back(bedroom1);
    rooms.push_back(bedroom2);
    rooms.push_back(kitchen);
    rooms.push_back(bathroom1);
    rooms.push_back(bathroom2);
    rooms.push_back(balcony);
    //设置地图
    map<string, Room*> lobbyExits = {{"east", kitchen}, {"west", bedroom1},{"up",bedroom2}};
    map<string, Room*> bedroomExits1={{"east",lobby},{"south",bathroom1},{"up",bathroom2}};
    map<string, Room*> bedroomExits2={{"east",balcony},{"west",bathroom2},{"down",lobby}};
    map<string, Room*> bathroomExits1={{"north",bedroom1}};
    map<string, Room*> bathroomExits2={{"east",bedroom2},{"down",bedroom1}};
    map<string, Room*> kitchenExit={{"west",lobby},{"up",balcony}};
    map<string, Room*> balconyExit={{"west",bedroom2},{"down",kitchen}};

    lobby->exits=lobbyExits;
    bedroom1->exits=bedroomExits1;
    bedroom2->exits=bedroomExits2;
    kitchen->exits=kitchenExit;
    bathroom1->exits=bathroomExits1;
    bathroom2->exits=bathroomExits2;
    balcony->exits=balconyExit;
    
    //随机生成有公主和怪兽的房间
    srand(unsigned(time(0)));
    int princessRoom=rand()%6+1;
    int monsterRoom=rand()%6+1;
    while (princessRoom==monsterRoom)//若房间一样则更换
    {
        monsterRoom=rand()%6+1;
    }
    rooms[princessRoom]->state=1;
    rooms[monsterRoom]->state=2;
    //初始化
    cout << "Welcome to the lobby. There are 3 exits: east, west and up."<<endl;
    cout<<"Enter your command:";
    Room* currentRoom=lobby;
    Room* targetRoom;
    string input;
    istringstream iss;
    //bool flag=true;
    //在地图中移动    
    while (true)
    {        
        getline(cin,input);
        iss.str(input);
        iss.clear(); // 清除错误状态
        //istringstream iss(input);
        string gocommand,direction;
        iss >> gocommand >> direction;//分析玩家输入指令
        if (gocommand=="go")
        {
            Room* temptargetRoom=currentRoom->getExit(direction);
            if (temptargetRoom!=nullptr)//能找到出口对应的房间，则判断房间是否包含公主、怪兽，并对房间进行描述
            {
                targetRoom=temptargetRoom;
                
                if (targetRoom->state==2)//遇到怪兽就退出游戏
                {
                    cout<<"The monster is in the room!Game over!"<<endl;
                    break;
                }else if (targetRoom->state==1)
                {
                    cout<<"The pincesses is in this room!Take her to leave!"<<endl;
                    currentRoom->command(targetRoom);
                    targetRoom->state=0;//找到公主后，将房间状态改为0，即普通房间
                    //找到公主后前往lobby即可找到出口
                }
                if (rooms[princessRoom]->state==0&&targetRoom==lobby)//找到公主后回到大厅
                {
                    cout<<"Welcome to the lobby!The door is open.You sucessfully save the princess!"<<endl;
                    break;
                }                               
                currentRoom->command(targetRoom);//描述房间信息
                currentRoom=targetRoom;
            }else{
                cout<<"Wrong command1!"<<endl;
                cout<<"Enter your command:";
                
            }            
        }else{
            cout<<"Wrong command2!"<<endl;
            cout<<"Enter your command:";
            
        }        
    }    

    // 清理房间（删除动态分配的房间）
    for (Room* room : rooms) {
        delete room;
    }

    return 0;
}