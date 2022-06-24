//
// Created by 谢潮鑫 on 2022/5/23.
//
#pragma once //避免重复编译
#ifndef CPPLEARN_BUILDDIRECTORY_H
#define CPPLEARN_BUILDDIRECTORY_H
#include <sys/types.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "stdlib.h"
#include <string>
#include <unistd.h> // Linux系统中
//#include <direct.h> // windows系统中
#include <sstream>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

using namespace std;

#define MAXSIZE 500
//一级目录
string topPath;

//不想生成目录的文件
string inhibitDir[30];
//class BuildDirectory {
//
//};
//struct dirent
//{
//    __ino_t d_ino;   /*inode number */ // 节点号索引
//    __off_t d_off;   /*offset to this dirent */ // 在目录文件中的偏移
//    unsigned short int d_reclen;   /*length of this d_name */ // 这个文件的名字长度
//    unsigned char d_type;   /*the type of d_name */ // 文件类型
//    char d_name[256];    /*file name(null-terminated)  */ // 这个是文件名
//};

//忽略大小写
bool icompare_pred(unsigned char a, unsigned char b);

//是否包含特定文件
bool containString(string s);

//查询每个文件夹下的所有文件,获取名称和相对路径,返回拼接后的String
string tree(const char *currentPathName);

//获取当前可执行文件的路径
string getTopPath(char *argv[]);

//写md文件
void writeFile(const string fileAbsPath);

//获得相对路径
string getRelativePath(string basicString);

//拼接两个str
string appendStr(string src, string str);

//获取文件夹下所有文件的绝对路径
vector<string>  getSubFileAbsPaths(const char *currentPathName);

//构建填充md的目录树结构数据
string tree(string filePath, int level, string sb);

//通过路径截取文件名
string getFileNameByPath(string path);

//对比两个字符串
bool ComparedStr(string str1, string str2);

//获取父文件夹绝对路径
string getFileParentPath(string path);

//是否是目录
bool isDirectory(const char*dir_path);

// 排序
vector<string> sortFileByName(vector<string>,string s);
#endif //CPPLEARN_BUILDDIRECTORY_H
