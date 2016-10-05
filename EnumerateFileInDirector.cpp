#include "Tool.h"

/* ************************************
* DWORD EnumerateFileInDrectory(LPSTR szPath)
* ����    ����Ŀ¼�µ��ļ�����Ŀ¼������ʾ�ļ���
*        �ļ����ļ������ء����ܵ�����
* ����    LPTSTR szPath��Ϊ�������·��
* ����ֵ    0����ִ����ɣ�1���뷢������
**************************************/
vector<std::string> EnumerateFileInDrectory(const char* szPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	CHAR szFilePath[MAX_PATH];
	vector<string> res;

	//���������Ŀ¼���ļ���·�����ַ�����ʹ��ͨ�����*��
	strcpy(szFilePath, szPath);
	//ע�͵Ĵ���������ڲ��������ԡ�.txt��β�����ļ���
	//lstrcat(szFilePath, "\\*.txt");
	strcat(szFilePath, "\\*");
	//���ҵ�һ���ļ�/Ŀ¼����ò��Ҿ��
	hListFile = FindFirstFile(szFilePath, &FindFileData);
	//�жϾ��
	if (hListFile == INVALID_HANDLE_VALUE)
	{
		printf("����%d", GetLastError());
		return res;
		//return 1;
	}
	else
	{
		do
		{
			//�ж��ļ����ԣ�Ŀ¼
			if (!(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
			{
				res.push_back(FindFileData.cFileName);
			}
			//���߿ɸ����ļ����Ա��е�������������ж��ļ����ԡ�

		} while (FindNextFile(hListFile, &FindFileData));
	}
	return res;
}
