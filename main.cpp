#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sorting{

	string str;
	string priorityTable;

	int actions = 0;

	int getIndex(char c){
		for(int i = 0; i < priorityTable.size(); i ++){
			if(priorityTable[i] == c)
				return i;
		}
		return -1;
	}
	void swap(int x, int y){
		char tmp = str[x];
		str[x] = str[y];
		str[y] = tmp;
	}

public:
	Sorting(string str, string priorityTable){
		this -> str = str;
		this -> priorityTable = priorityTable;
	}
	void sort(){
		while(str != priorityTable){
			//cout<<"checkpoint1"<<endl;
			for(int i = str.size() - 1; i > 0; i --){
				if(getIndex(str[i]) < getIndex(str[i-1])){
					swap(i, i-1);
					actions++;
					//cout<<str<<endl;
				}
			}
		}
	}
	int getActions(){
		return actions;
	}
};
int main(){
	fstream file("data.txt", ios::in);
	string line;
	int num = 0;

	int n;
	string jas, malgosia;
	while(getline(file, line)){
		if(num == 0){
			n = std::stoi(line);
		}
		else if(num == 1){
			jas = line;
		}
		else if(num == 2){
			malgosia = line;
		}
		num++;
	}
	Sorting sorting(malgosia, jas);
	sorting.sort();
	cout<<sorting.getActions()<<endl;
}