#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("./data.txt");
    string temp;
    // Read In line by line
    vector<string> res;
    while (getline(fin, temp)) {
        res.push_back(temp);
    }
    
    fin.close();
    
    // Read In word by word
    ifstream fin2("./data.txt");
    vector<string> res2;
    while (getline(fin2, temp, ' ')) {
        res2.push_back(temp);
    }
    for (auto i : res2) {
        cout << i <<endl;
    }
    return 0;
}
