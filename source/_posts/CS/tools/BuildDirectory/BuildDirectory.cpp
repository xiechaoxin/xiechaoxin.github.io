//
// Created by 谢潮鑫 on 2022/5/23.
//

#include "BuildDirectory.h"

// tabs用于缩进，存放的是0个或多个字符\t
char tmp[MAXSIZE] = {};

//传入一个绝对路径,减去topPath,获取相对路径
string getRelativePath(string currentAbsPath)
{
    string RelPath = currentAbsPath.substr(topPath.length(), currentAbsPath.length() - topPath.length());
    return RelPath;
}

//是否包含特定文件
bool containString(string s)
{

    //按文件名
    for (string str : inhibitDir)
    {
        if (s.length() == str.length() && equal(s.begin(), s.end(), str.begin(), icompare_pred))
        {
            return true;
        }
    }
    //按文件类型,现在只想生成md文件
    //    string fileType[] = {
    //            "log",
    //            "gitignore",
    //            "jar",
    //            "war",
    //            "nar",
    //            "ear",
    //            "zip",
    //            "tar.gz",
    //            "rar",
    //            "ctxt",
    //            "xml",
    //            "ico",
    //            "sw",
    //            "iml",
    //            "settings"
    //    };
    //    //根据扩展名判断
    //    string suffix_str = s.substr(s.find_last_of('.') + 1);
    //    for (string fileT: fileType) {
    //        if (suffix_str.length() == fileT.length() &&
    //            equal(suffix_str.begin(), suffix_str.end(), fileT.begin(), icompare_pred)) {
    //            return true;
    //        }
    //    }
    return false;
}

//忽略大小写
bool icompare_pred(unsigned char a, unsigned char b)
{
    return tolower(a) == tolower(b);
}

string getTopPath(char *argv[])
{
    //获取当前执行文件的绝对路径,进而获取上级文件夹得绝对路径
    char resolved_path[1024];
    realpath(argv[0], resolved_path);
    string s(resolved_path);
    int index1 = s.find_last_of("/"); //这里看下windows\\怎么处理
    string currentAbsPath = s.erase(index1, 20);
    return currentAbsPath;
}

//写 md 文件
void writeFile(const string filePath)
{
    if (containString(getFileNameByPath(filePath)))
    {
        return;
    }
    //创建文件流
    ofstream RMofs;
    ofstream SBofs;
    RMofs.open(filePath + "/README.md", ios::out);
    SBofs.open(filePath + "/_sidebar.md", ios::out);

    //不是顶级目录,就要写返回上级和返回首页
    if (!(filePath == topPath))
    {
        RMofs << "- [返回首页](/README.md)" << endl;
        SBofs << "- [返回首页](/README.md)" << endl;

        string s1 = (getRelativePath(getFileParentPath(filePath))) == "" || (getRelativePath(getFileParentPath(filePath))) == "/" ? "" : getRelativePath(getFileParentPath(filePath));
        string s2 = s1.substr(0, s1.length() - 1);
        string s3 = getFileNameByPath(s2);


        if (s3 != "")
        {
            RMofs << "- [返回上级 " << s3 << "]("
                  << getRelativePath(getFileParentPath(filePath)) << "README.md)" << endl;

            SBofs << "- [返回上级 " << s3 << "]("
                  << getRelativePath(getFileParentPath(filePath)) << "README.md)" << endl;
        }

        RMofs << "  - [" << getFileNameByPath(filePath) << "](" << getRelativePath(filePath) << "/)" << endl; //当前路径

        SBofs << "  - [" << getFileNameByPath(filePath) << "](" << getRelativePath(filePath) << "/)" << endl; //当前路径
    }

    string sb;
    string retSB = tree(filePath, 1, sb);
    RMofs << retSB;
    RMofs.close();
    SBofs << retSB;
    SBofs.close();
    if (!containString(getFileNameByPath(filePath)))
    {
        const char *c = filePath.c_str();
        vector<string> childs = getSubFileAbsPaths(c);
        for (int i = 0; i < childs.size(); i++)
        {
            char ch[256];
            string s = childs[i];
            strcpy(ch, s.c_str());
            if (isDirectory(ch) && !containString(ch))
            {
                writeFile(childs[i]);
            }
        }
    }
}

//对比两个字符串
bool ComparedStr(string str1, string str2)
{
    int Difference = str1.length() - str2.length();
    if (abs(Difference) > 1)
    {
        return false;
    }
    for (int i = 0; i < str1.length() - 1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

string getFileNameByPath(string path)
{
    string::size_type iPos = path.find_last_of('/') + 1;
    string filename = path.substr(iPos, path.length() - iPos);
    return filename;
}

//获取父文件夹绝对路径
string getFileParentPath(string path)
{
    string::size_type iPos = path.find_last_of('/') + 1;
    string filename = path.substr(0, iPos);
    return filename;
}

vector<string> getSubFileAbsPaths(const char *currentPathName)
{
    DIR *dirp = opendir(currentPathName);
    vector<string> v;
    if (dirp == NULL)
    {
        cout << "Opendir <" << currentPathName << "> failed\n"
             << endl;
        v.push_back("Opendir currentPathName failed");
        return v;
    }
    chdir(currentPathName); //进入目录

    string path = getcwd(tmp, sizeof(tmp));

    dirent *p_dirent = NULL;
    while ((p_dirent = readdir(dirp)) != NULL)
    { //逐个读取目录项
        if (p_dirent->d_type == DT_DIR)
        { //目录项是一个目录
            if (strcmp(p_dirent->d_name, ".") != 0 && strcmp(p_dirent->d_name, "..") != 0)
            {
                //排除.和..目录项
                v.push_back(path + '/' + p_dirent->d_name);
            }
        }
        else
        {
            v.push_back(path + '/' + p_dirent->d_name);
        }
    }
    closedir(dirp);
    dirp = NULL;
    return v;
}

//排序
vector<string> sortFileByName(vector<string> v, string s)
{
    if (s == "asc")
    {
        sort(v.begin(), v.end(), less<string>());
    }
    else
    {
        sort(v.begin(), v.end(), greater<string>());
    }
    return v;
}

bool isDirectory(const char *dir_path)
{
    if (dir_path == NULL)
    {
        return false;
    }
    if (opendir(dir_path) == NULL)
    {
        return false;
    }
    return true;
}

string tree(string folderPath, int level, string oldSb)
{
    string sb = oldSb;
    if (containString(getFileNameByPath(folderPath)))
    {
        return "";
    }
    //控制递归层级
    if (level > 1)
    {
        return sb;
    }
    // 需求，每递归一层需要累加两个空格缩进
    string preStr = "  "; //一上来就两个空格，默认第二级，因为第一级设置了【返回首页】【返回上级】
    for (int i = 0; i < level; i++)
    {
        preStr += "  ";
    }
    char c[1024];
    strcpy(c, folderPath.c_str());
    //获取文件夹下的所有文件绝对路径(包含子文件夹)
    vector<string> subFileAbsPathsUnorder = getSubFileAbsPaths(c);

    // 根据文件名排序 asc 升序
    vector<string> subFileAbsPaths = sortFileByName(subFileAbsPathsUnorder, "asc");

    for (int i = 0; i < subFileAbsPaths.size(); i++)
    {

        // 获取相对路径
        string relativePath = getRelativePath(subFileAbsPaths[i]);

        //截取文件扩展名
        string suffix_str = subFileAbsPaths[i].substr(subFileAbsPaths[i].find_last_of('.') + 1);

        char ch[256];
        string s = subFileAbsPaths[i];
        strcpy(ch, s.c_str());
        string sf = getFileParentPath(subFileAbsPaths[i]);
        //是否根目录
        if (ComparedStr(topPath, getFileParentPath(subFileAbsPaths[i])) &&
            !containString(getFileNameByPath(subFileAbsPaths[i])))
        {
            string s;
            s.append("- [").append(getFileNameByPath(subFileAbsPaths[i]).append("](").append(getRelativePath(subFileAbsPaths[i])).append("/)\n"));
            sb.append(s);
        }
        // 是否文件夹
        else if (!containString(getFileNameByPath(subFileAbsPaths[i])) && isDirectory(ch))
        {
            string s;
            s.append(preStr).append("- [").append(getFileNameByPath(subFileAbsPaths[i]).append("](").append(getRelativePath(subFileAbsPaths[i])).append("/)\n"));
            sb.append(s);
        }
        // 是否markdown文件
        else if (!containString(getFileNameByPath(subFileAbsPaths[i])) && suffix_str == "md")
        {
            string s;
            s.append(preStr).append("- [").append(getFileNameByPath(subFileAbsPaths[i]).append("](").append(getRelativePath(subFileAbsPaths[i])).append(")\n"));
            sb.append(s);
        }
        if (isDirectory(ch) && !containString(getFileNameByPath(subFileAbsPaths[i])))
        {
            tree(subFileAbsPaths[i], level + 1, sb);
        }
    }
    // 返回整个文件夹递归后的字符串
    return sb;
}

string appendStr(string src, string str)
{
    return src.append(str);
}

int main(int argc, char *argv[])
{
    topPath = getTopPath(argv);
    string filePath = topPath;
    cout << "正在生成当前目录的文件树结构" << filePath << endl;

    ifstream ifs;
    ifs.open(topPath + "/inhibitdir.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "inhibitDir.txt 文件读取失败 \n继续生成目录结构时,将不会剔除特定的文件和文件夹! 是否继续?\n继续请按1;退出请按任意键\n"
             << endl;
        int i;
        cin >> i;

        if (i != 1)
        {
            return 0;
        }
    }
    string buf;
    int i = 0;
    while (getline(ifs, buf))
    {
        inhibitDir[i] = buf;
        i++;
    }
    cout << "已读取inhibitdir.txt的内容,最后一行内容是" << inhibitDir[i - 1] << endl;
    ifs.close();

    writeFile(filePath);
    cout << "成功生成目录树文件,运行结束" << filePath << endl;
    return 0;
}