#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int characters=0,alpha=0,digits=0,lines=1,spaces=0;
	char ch;
	ofstream fout("multiline.txt");
	cout<<"Enter Text:";
	while(cin.get(ch) && ch!='#')
		fout.put(ch);
	fout.close();
	ifstream fin("multiline.txt");
	while(fin.get(ch)){
		characters++;
		if(isalpha(ch))
			alpha++;
		else if(isdigit(ch))
			digits++;
		else if(ch==' ')
			spaces++;
		else if(ch=='\n')
			lines++;
	}
	fin.close();
	cout << "\nTotal characters:"<< characters<<endl;
    cout << "Total alphabets: " << alpha << endl;
    cout << "Total digits: " << digits << endl;
    cout << "Total lines: " << lines << endl;
    cout << "Total spaces: " << spaces << endl;
    return 0;
}
