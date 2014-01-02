//
//  B10.1.4.cpp
//  计算概论
//
//  Created by 李喆 on 13-11-28.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//第4题：4:扩号匹配问题
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
//输入
//输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
//注意：cin.getline(str,100)最多只能输入99个字符！
//输出
//对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
//样例输入
//((ABCD(x)
//)(rttyy())sss)(
//样例输出
//((ABCD(x)
//$$
//)(rttyy())sss)(
//?            ?$
//提示
//输入多行数据需要使用while(cin.getline(...))来处理，cin.getline以及cin>>会在读入到输入结束（EOF）时返回false。


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[101];
    char symbol[101];
    while (cin.getline(str, 101)) {
    for (int i=0; i<strlen(str); i++) {
        cout << str[i];
    }
    cout << endl;
        for (int i=0; i<101; i++) {
            symbol[i]='\0';
        }
    
    for (int i=0; i<strlen(str); i++) {
        switch (str[i]) {
            case '(':
                symbol[i]='$';
                break;
            case ')':
                symbol[i]='?';
                for (int j=i-1; j>=0; j--) {
                    if (symbol[j]=='$') {
                        symbol[i]=' ';
                        symbol[j]=' ';
                        break;
                    }
                }
                break;
            default:
                symbol[i]=' ';
                break;
        }
    }
    for (int i=0; i<strlen(symbol); i++) {
        cout << symbol[i];
    }
    cout << endl;
    }
    return 0;
}
