#include"tcp.h"



void* say_hello(void* args)
{
    SOCKET m_listenSock;
    int send_len = 0;
    int recv_len = 0;
    int len = 0;
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
    cout <<"端口为"<< uPort << endl;
    if (uPort <= 0 || uPort > 65535)
    {
        cout << "输入范围为1~65535" << endl;
        system("pause");
        exit(-1);
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.S_un.S_addr = INADDR_ANY;
    service.sin_port = htons(uPort);
    if (bind(m_listenSock, (sockaddr*)&service, sizeof(sockaddr_in)) == SOCKET_ERROR)
    {
        cout << "绑定失败" << endl;
        system("pause");
        exit(-2);
    }
    if (listen(m_listenSock, 5) == SOCKET_ERROR)
    {
        cout << "监听失败" << endl;
        system("pause");
        exit(-4);
    }
    while (true)
    {
        if (SOCKET_Select(m_listenSock, 100, TRUE))
        {
            sockaddr_in clientAddr;
            int iLen = sizeof(sockaddr_in);
            SOCKET accSock = accept(m_listenSock, (struct sockaddr*)&clientAddr, &iLen);
            if (accSock == INVALID_SOCKET)
            {
                cout << "接受客户端请求失败" << endl;
                continue;
            }

            while (1)
            {
                recv_len = recv(accSock, recv_buf, 100, 0);
                if (recv_len < 0)
                {
                    cout << "接受失败！" << endl;
                    break;
                }
                else
                {
                    cout << "客户端信息:" << recv_buf << endl;
                }
                cout << "请输入回复信息:";
                cin >> send_buf;
                send_len = send(accSock, send_buf, 100, 0);
                if (send_len < 0)
                {
                    cout << "发送失败！" << endl;
                    break;
                }

                Sleep(100);
            }

        }

    }
   

    system("pause");
    closesocket(m_listenSock);
    return 0;

}

