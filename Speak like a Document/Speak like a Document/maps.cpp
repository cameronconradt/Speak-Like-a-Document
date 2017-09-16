/*
 * maps.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: cameron
 */




#include <set>
#include <vector>
#include <map>
#include <deque>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{

	srand(time(NULL));
    vector<string> tokens;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
	        tokens.push_back(nopunct);
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;

    // maps
    map <string, int> wordcount;
    map <deque <string>, vector<string>> wordmap;
    deque <string> state;
    state.push_back("");
    state.push_back("");
    //load map
    for(auto s:tokens) {
        //cout << state[0]<<" "<<state[1]<<"="<<s<<endl;
        wordmap[state].push_back(s);
        state.push_back(s);
        state.pop_front();
    }
    for(auto s:tokens) {
        wordcount[s]++;
    }
    /*for (map<string,int>::iterator it=wordcount.begin(); it!=wordcount.end(); ++it)
        cout << it->first<<' ' << it->second<<endl;
    cout << endl;*/
    //Generate Text
    deque <string> current;
    current.push_back("");
    current.push_back("");

    for(int i =0; i < 100; i++) {
        int ind = rand() % wordmap[current].size();
        cout << wordmap[current][ind]<<" ";
        current.push_back(wordmap[current][ind]);
        current.pop_front();
    }
    cout << endl;
}
