#include"tcp.h"
#define NUM_THREADS 5


int main()
{
    menu();
    pthread_t PID1;
    pthread_t PID2;
    int ret;
    int b = 0;
    cin >> b;
    switch (b)
    {
    case 1:
       ret = pthread_create(&PID1, NULL, say_hello, NULL);
        if (ret != 0)
        {
            cout << "线程创建失败" << endl;
            exit(-1);
        }
        pthread_exit(NULL);
        
        break;
    case 2:
       ret = pthread_create(&PID2, NULL, client, NULL);
        if (ret != 0)
        {
            cout << "线程创建失败" << endl;
            exit(-1);
        }
        pthread_exit(NULL);

        break;
    case 0:
        system("pause");
        return 0;
        break;
    }
    system("pause");
    return 0;
}