#ifndef KMP_h
#define KMP_h

#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class KMP {
public:
	KMP();
	~KMP();
	vector<int> pre_kmp(string text);
	vector<int> kmp(string text, string key);	
	void write_suffix(set<string> suffix);
	set < string > autoComplete(vector<int> matches, string key, string text);
	string getSuffix(int pos, string text);
	string getPreffix(int pos, string text);
};

#endif