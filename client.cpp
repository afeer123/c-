#include"tcp.h"
#pragma warning(disable : 4996) 

void* client(void* client)
{
    SOCKET m_listenSock;
    int send_len = 0;
    int recv_len = 0;
    char send_buf[100];
    char recv_buf[100];
    wsa();
    m_listenSock = INVALID_SOCKET;
    m_listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_listenSock == INVALID_SOCKET)
    {
        cout << "创建失败" << endl;
        system("pause");
        exit(-3);
    }
    cout << m_listenSock << endl;
    UINT uPort;
    cout << "请输入端口： " << endl;
    cin >> uPort;
    system("cls");
    cout << "端口为" << uPort << endl;
    if (uPort <= 0 || uPort > 65535)
    {
        cout << "输入范围为1~65535" << endl;
        system("pause");
        exit(-1);
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.S_un.S_addr = inet_addr("121.199.22.135");
    service.sin_port = htons(uPort);
    if (connect(m_listenSock, (sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        cout << "服务器连接失败" << endl;

        exit(-4);
    }

    while(1) {
        cout << "请输入发送信息:";
        cin >> send_buf;
        send_len = send (m_listenSock, send_buf, 100, 0);
        if (send_len < 0) {
            cout << "发送失败！" << endl;
            break;
        }
        recv_len = recv(m_listenSock, recv_buf, 100, 0);
        if (recv_len < 0) {
            cout << "接受失败！" << endl;
            break;
        }
        else {
            cout << "服务端信息:" << recv_buf << endl;
        }

    }


    system("pause");
    closesocket(m_listenSock);
    return 0;

}

