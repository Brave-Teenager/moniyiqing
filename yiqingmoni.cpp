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
// ������Ⱦ  �����ĵ��λ�õĸ������ᱻ��Ⱦ  ��Ⱦ��Ϊ1  δ��ȾΪ0
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
    cout<<"�����������\n";
    _getch();
    // ���ݸ�Ⱦ���� 1  �������� �� 0.1 �ĸ���Ϊ1 
    while (1) {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {

                    if (i -1>= 0) {   
                        if (rand() % 10 == 1) {//up  0.1�ĸ��ʸ�Ⱦ�������� �������ȷ��
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
            cout << "��Ⱦ��������"<<endl;
            break;
        }
   
        cout << "�����������  ��ESC�˳�" << endl;

        char c = _getch();
        if (c == 27) {
            cout << "ESC�˳�" << endl;
            exit(0);//�˳�����
        }

        cout << endl << endl;
    }
    cout << "���н���"<<endl;
    system("pause");
    return 0;
}