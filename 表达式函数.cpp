#include"tcp.h";

int wsa()
{
	WSADATA wsadata;
	WORD wVersionRequested = MAKEWORD(1, 1);
	int nResult = WSAStartup(wVersionRequested, &wsadata);
	return nResult;
}
BOOL SOCKET_Select(SOCKET hSocket, int nTimeOut, BOOL bRead)
{
	fd_set fdset;
	timeval tv;
	FD_ZERO(&fdset);
	FD_SET(hSocket, &fdset);
	nTimeOut = nTimeOut > 1000 ? 1000 : nTimeOut;
	tv.tv_sec = 0;
	tv.tv_usec = nTimeOut;

	int iRet = 0;
	if (bRead)
	{
		iRet = select(0, &fdset, NULL, NULL, &tv);
	}
	else
	{
		iRet = select(0, NULL, &fdset, NULL, &tv);
	}

	if (iRet <= 0)
	{
		return FALSE;
	}
	else if(FD_ISSET(hSocket,&fdset))
	{
		return TRUE;
	}
	return FALSE;
}

void menu()
{
	cout << "**********************" << endl;
	cout << "*   1、开启服务器    *" << endl;
	cout << "**********************" << endl;
	cout << "*   2、连接服务器    *" << endl;
	cout << "*** 0、 退 出 ********" << endl;
	cout << "**********************" << endl;
}