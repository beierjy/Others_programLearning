#include "Tool.h"

/* ************************************
* DWORD EnumerateFileInDrectory(LPSTR szPath)
* 功能    遍历目录下的文件和子目录，将显示文件的
*        文件和文件夹隐藏、加密的属性
* 参数    LPTSTR szPath，为需遍历的路径
* 返回值    0代表执行完成，1代码发生错误
**************************************/
vector<std::string> EnumerateFileInDrectory(const char* szPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	CHAR szFilePath[MAX_PATH];
	vector<string> res;

	//构造代表子目录和文件夹路径的字符串，使用通配符“*”
	strcpy(szFilePath, szPath);
	//注释的代码可以用于查找所有以“.txt结尾”的文件。
	//lstrcat(szFilePath, "\\*.txt");
	strcat(szFilePath, "\\*");
	//查找第一个文件/目录，获得查找句柄
	hListFile = FindFirstFile(szFilePath, &FindFileData);
	//判断句柄
	if (hListFile == INVALID_HANDLE_VALUE)
	{
		printf("错误：%d", GetLastError());
		return res;
		//return 1;
	}
	else
	{
		do
		{
			//判断文件属性，目录
			if (!(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
			{
				res.push_back(FindFileData.cFileName);
			}
			//读者可根据文件属性表中的内容自行添加判断文件属性。

		} while (FindNextFile(hListFile, &FindFileData));
	}
	return res;
}
