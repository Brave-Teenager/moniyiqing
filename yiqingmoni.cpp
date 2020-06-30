#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

using namespace std;
static int n = 21;
// 触发感染  在中心点的位置的附近都会被感染  感染就为1  未感染为0
int main() {
    int sum = 0;
    int a[21][21];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    a[10][10] = 1;
    cout<<"按任意键继续\n";
    _getch();
    // 根据感染的人 1  附件的人 有 0.1 的概率为1 
    while (1) {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {

                    if (i -1>= 0) {   
                        if (rand() % 10 == 1) {//up  0.1的概率感染附件的人 随机数来确认
                            a[i - 1][j] = 1;
                        }
                    }
                    if (j + 1 < 21 && i - 1 >= 0) {
                        if (rand() % 10 == 1) {//right up
                            a[i - 1][j + 1] = 1;
                        }
                    }
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if (rand() % 10 == 1) {//left up
                            a[i - 1][j - 1] = 1;
                        }
                    }
                    if (i + 1 < 21) {
                        if (rand() % 10 == 1) {//down
                            a[i + 1][j] = 1;
                        }
                    }
                    if (j - 1 < 21) {
                        if (rand() % 10 == 1) {//left
                            a[i][j - 1] = 1;
                        }
                    }
                    if (j + 1 < 21) {
                        if (rand() % 10 == 1) {//right
                            a[i][j + 1] = 1;
                        }
                    }
                    if (j + 1 < 21 && i + 1 < 21) {
                        if (rand() % 10 == 1) {//right down
                            a[i + 1][j + 1] = 1;
                        }
                    }
               
                    if (i + 1 < 21 && j - 1 >=0) {
                        if (rand() % 10 == 1) {//left down
                            a[i + 1][j - 1] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                 cout << a[i][j] << "  ";
                 if (a[i][j] == 1){
                     sum++;
                 }
            }
            cout << endl;
        }
        if (sum == 441) {
            cout << "感染人数已满"<<endl;
            break;
        }
   
        cout << "按任意键继续  按ESC退出" << endl;

        char c = _getch();
        if (c == 27) {
            cout << "ESC退出" << endl;
            exit(0);//退出程序
        }

        cout << endl << endl;
    }
    cout << "运行结束"<<endl;
    system("pause");
    return 0;
}