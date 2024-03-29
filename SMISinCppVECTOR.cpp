// SMISinCppVECTOR.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


struct info
{
	unsigned int id;
	string name;
	double cs_mark, eng_mark, sum_mark;
};


info null(void);
void clear(void);
bool menu(vector<info> &addr);
bool progress(vector<info> &addr);
void welcome(void);
vector<info>::iterator compare(vector<info> &addr, double mark);
void input(vector<info> &addr);
void dele(vector<info> &addr);
bool _del(vector<info> &addr);
vector<info>::iterator search_name(vector<info> &addr, string target);
void print_name(vector<info>::iterator &iter);
void find(vector<info> &addr, int func_num);

info null(void) {
	info str;
	str.name = "0";
	return str;
}

void clear(void) {
	system("pause");
	system("cls");
}

bool menu(vector<info> &addr) {
	char check = 'Y';
	while (check != 'E' || check != 'e') {
		cout << "Welcome to SIMS vekver!!!" << endl;
		cout << "1.List All Failded Students' Names" << endl;
		cout << "2.Add Newer" << endl;
		cout << "3.Delete Loser" << endl;
		cout << "4.List All 'Good' Students" << endl;
		cout << "0. Exit" << endl;
		if (progress(addr)) {
			break;
		}
	}
	clear();
	cout << "Thank you for using! :)" << endl;
	return true;
}

bool progress(vector<info> &addr) {
	int i;
	cin >> i;
	switch (i)
	{
	case 0:
		return true;
	case 1:
		find(addr, i);
		break;
	case 2:
		input(addr);
		break;
	case 3:
		dele(addr);
		break;
	case 4:
		find(addr, i);
		break;
	default:
		break;
	}
	return false;
}

void welcome(void) {
	cout << "No Student Info Found!" << endl;
	cout << "Inputting function has been processing...";
	clear();
}

vector<info>::iterator compare(vector<info> &addr, double mark) {
	vector<info>::iterator iter;
	for (iter = addr.begin(); iter != addr.end(); ++iter) {
		if (iter->sum_mark > mark) {
			continue;
		}
		else {
			break;
		}
	}
	return iter;
}

void input(vector<info> &addr) {
	info temp_stuc;
	char check = 'Y';
	int count = addr.size();
	while (check == 'Y' || check == 'y') {
		cout << "Input ID,NAME,Mark of COMPUTER_SCIENCE and ENGLISH: ";
		cin >> temp_stuc.id >> temp_stuc.name >> temp_stuc.cs_mark >> temp_stuc.eng_mark;
		temp_stuc.sum_mark = temp_stuc.cs_mark + temp_stuc.eng_mark;
		if (count != 0) {
			addr.insert(compare(addr, temp_stuc.sum_mark), temp_stuc);
		}
		else {
			addr.push_back(temp_stuc);
		}
		++count;
		cout << "Y or y to Continue...";
		cin >> check;
	}
	cout << "End of Inputting" << endl;
}

void dele(vector<info> &addr) {
	if(addr.size() != 0){
		cout << "Input Student name which you wanna delete its information: ";
		if (_del(addr)) {
			cout << "Success!" << endl;
		}
		else {
			cout << "Not Found!!!" << endl;
		}
	}
	else {
		cout << "No Member Exists!!!" << endl;
	}
}

bool _del(vector<info> &addr) {
	string name;
	cin >> name;
	vector<info>::iterator iter = search_name(addr, name);
	if (iter->name != "0") {
		addr.erase(iter);
		return true;
	}
	else {
		addr.pop_back();
		return false;
	}
}

vector<info>::iterator search_name(vector<info> &addr, string target) {
	if (addr.size() <= 1) {
		if (target == addr.at(0).name) {
			vector<info>::iterator iter = addr.begin();
			return iter;
		}
		else {
			addr.push_back(null());
			return addr.end();
		}
	}
	else {
		for (vector<info>::iterator iter = addr.begin(); iter != addr.end(); ++iter) {
			if (iter->name == target) {
				return iter;
			}
		}
		cout << "ERROR!!!" << endl;
		addr.push_back(null());
		return addr.end();
	}
	
}

void print_name(vector<info>::iterator &iter) {
	cout << iter->name;
}

void find(vector<info> &addr, int func_num) {
	switch (func_num)
	{
	case 1:
		for (vector<info>::iterator iter = addr.begin(); iter != addr.end(); ++iter) {
			bool it_does = false;
			if (iter->cs_mark < 60) {
				cout << "CS ";
				it_does = true;
			}
			if (iter->eng_mark < 60) {
				cout << "ENG ";
				it_does = true;
			}
			if (it_does) {
				print_name(iter);
				cout << endl;
			}
		}
		break;
	case 4:
		for (vector<info>::iterator iter = addr.begin(); iter != addr.end(); ++iter) {
			if (iter->sum_mark / 2 >= 70 && iter->sum_mark / 2 <= 90) {
				print_name(iter);
				cout << endl;
			}
		}
		break;
	default:
		cout << "That's Not Possible!" << endl;
		break;
	}
}

int main()
{
	vector<info> students;
	welcome();
	input(students);
	while (1) {
		if (menu(students)) {
			students.clear();
			return 0;
		}
		clear();
	}
	return 1;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
