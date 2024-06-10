#include <iostream>
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")
#include<thread>
void recive1(SOCKET sockClient, SOCKADDR_IN addrClient) {
    char recvBuf[100]={0};
    while (true) {
        int a=recvfrom(sockClient, recvBuf, 100, 0, NULL, NULL);
        if(a!=-1)std::cout << recvBuf << std::endl;
    }
}
void send1(SOCKET sockClient, SOCKADDR_IN addrClient) {
    char sendBuf[100];
    while (true) {
        std::cin >> sendBuf;
        sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR *) &addrClient, sizeof(SOCKADDR));
    }
}
int main() {
    //windows下创建一个udp套接字，链接到120.46.204.140:5010
    WSADATA wsaData;
    SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
    SOCKADDR_IN addrClient;
    addrClient.sin_addr.S_un.S_addr = inet_addr("120.46.204.140");
    addrClient.sin_family = AF_INET;
    addrClient.sin_port = htons(5010);
    bind(sockClient, (SOCKADDR *) &addrClient, sizeof(SOCKADDR));
    //发送数据
    std::thread t0(recive1, sockClient, addrClient);
    std::thread t1(send1, sockClient, addrClient);
    t1.join();
    t0.join();
    closesocket(sockClient);
    WSACleanup();
    return 0;
}
