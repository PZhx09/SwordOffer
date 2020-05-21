#include <iostream>
#include <cstring>


using namespace std;
//知识点:三种传入参数类型
//指针、引用的符号
//运算符重载
//strlen函数  -->有效元素的数目而不是集合大小

class CMyString
{
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& STR);
	~CMyString(void);

	char* getString(void);	//过去字符串值

	/*CMyString& operator=(const CMyString& str)
	{
		if (this == &str)
			return *this;
		delete[]this->m_pData;
		this->m_pData = new char[strlen(str.m_pData)];
		strcpy(this->m_pData, str.m_pData);
		return *this;
	}*/
	//也可以考虑下安全性的问题，例如delete之后没有足够的空间new
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