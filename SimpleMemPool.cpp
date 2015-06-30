#include<windows.h>
#include<iostream>

using namespace std;

char buf[4100];  //Simple Memory Pool 
#define MEMPOOL 1

#if MEMPOOL

class CTestClass
{    
    char m_chBuf[4096];
};

#else

class CTestClass
{
    char m_chBuf[4096];
public:    
    void *operator new(unsigned int uiSize)
    {
        return (void *)buf;
    }
    void  operator delete(void *p)
    {
    }
};
#endif

int main()
{
    DWORD count = GetTickCount();    
    
    for(unsigned int i=0; i<0xfffff; i++)
    {
        CTestClass *p = new CTestClass;
        delete p;
    }
    
    cout << "Interval = " << GetTickCount()-count << " ms" << endl;
    
	cin.get();
    return 0;
} 

