#include <iostream>
#include <cstring>


using namespace std;
//֪ʶ��:���ִ����������
//ָ�롢���õķ���
//���������
//strlen����  -->��ЧԪ�ص���Ŀ�����Ǽ��ϴ�С

class CMyString
{
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& STR);
	~CMyString(void);

	char* getString(void);	//��ȥ�ַ���ֵ

	/*CMyString& operator=(const CMyString& str)
	{
		if (this == &str)
			return *this;
		delete[]this->m_pData;
		this->m_pData = new char[strlen(str.m_pData)];
		strcpy(this->m_pData, str.m_pData);
		return *this;
	}*/
	//Ҳ���Կ����°�ȫ�Ե����⣬����delete֮��û���㹻�Ŀռ�new
	CMyString& operator=(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString tmp(str);
			char* tmppoint = tmp.m_pData;
			tmp.m_pData = this->m_pData;
			this->m_pData = tmppoint;
		}
		return *this;
	}
private:
	char* m_pData;
};
/*int main()
{
	char p[] = "1234";
	cout << strlen(p) << endl;
}*/