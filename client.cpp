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
        cout << "����ʧ��" << endl;
        system("pause");
        exit(-3);
    }
    cout << m_listenSock << endl;
    UINT uPort;
    cout << "������˿ڣ� " << endl;
    cin >> uPort;
    system("cls");
    cout << "�˿�Ϊ" << uPort << endl;
    if (uPort <= 0 || uPort > 65535)
    {
        cout << "���뷶ΧΪ1~65535" << endl;
        system("pause");
        exit(-1);
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.S_un.S_addr = inet_addr("121.199.22.135");
    service.sin_port = htons(uPort);
    if (connect(m_listenSock, (sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        cout << "����������ʧ��" << endl;

        exit(-4);
    }

    while(1) {
        cout << "�����뷢����Ϣ:";
        cin >> send_buf;
        send_len = send (m_listenSock, send_buf, 100, 0);
        if (send_len < 0) {
            cout << "����ʧ�ܣ�" << endl;
            break;
        }
        recv_len = recv(m_listenSock, recv_buf, 100, 0);
        if (recv_len < 0) {
            cout << "����ʧ�ܣ�" << endl;
            break;
        }
        else {
            cout << "�������Ϣ:" << recv_buf << endl;
        }

    }


    system("pause");
    closesocket(m_listenSock);
    return 0;

}

