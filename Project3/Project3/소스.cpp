#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#pragma warning(disable:4996)
using namespace std;
void rotate(char arr[][6], int cnt)
{
	if (cnt == 0) return;
	char changed[6][6];
	for (int i = 0; i < 6; i++) 
		for (int j = 0; j < 6; j++) 
			changed[j][5 - i] = arr[i][j];
		
	if (cnt == 1)
	{
		printf("회전 후 배열\n");
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				printf("%c ", changed[i][j]);
			}
			printf("\n");
		}
	}
	rotate(changed, --cnt);
}


int main()
{
	int num = 0;
	int cnt = 0;
	char arr[6][6] = {
		' ', ' ', ' ', ' ', ' ', ' ',
		'A','A','B','B','C','C',
		'D','D','E','E','F','F',
		'G','G','H','H','I','I',
		'J','J','K','K','L','L',
		' ', ' ', ' ', ' ', ' ', ' '
	};
	
	printf("입력?(cw90/cw180/cw270/cw360/rcw90/rcw180/rcw270) : ");
	string str ="";
	cin >> str;
	if (str[0] == 'r')
	{
		num = stoi(str.substr(3, 3));
		cnt = (num * 3)/90;
	}
	else
	{
		num = stoi(str.substr(2, 3));
		cnt = num / 90;
	}
	printf("원본 배열\n");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; ++j)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	rotate(arr, cnt);
}