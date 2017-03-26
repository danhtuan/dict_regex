#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/**
 * match a char c with regex
 * if not match return 0
 * else return 1, update mark
 */
int match(char c, string regex, int marked[]){
    int len = regex.length();
    for(int i = 0; i < len; i++){
        //cout<<" "<<c<<"?"<<regex[i];
        if((marked[i] == 0) && (c == regex[i])){
            marked[i] = 1;
            //cout<<" T";
            return 1;
        }
        if((marked[i] == 0) && (regex[i] == ' ')){
            marked[i] = 1;
            return 1;
        }
    }
    return 0;
}
/**
 * check if word is formed from regex
 * RULE: regex = {c| c in {a-z} or space} |regex| = 7 
 *       word is checked against regex 
 */
int isformed(string word, string regex){
    int rlen = regex.length();
    int wlen = word.length();
    if(wlen > rlen){
        return 0;
    }
    int* marked = new int[rlen];
    for(int i = 0; i < rlen; i++){
        marked[i] = 0;
    }
    for(int i = 0; i < wlen; i++){
        if(match(word[i], regex, marked)){
            continue;
        }else{
            return 0;
        }
    }
    return 1;
}
int main(){
    string word;
    string tile7="ab  aag";
    ifstream fdict("dictionary.txt");
    if(fdict.is_open()){
        while(getline(fdict, word)){
            cout<<word<<"--"<<tile7;
            if(isformed(word, tile7)){
                cout<<"-->VALID"; 
            }else{
                cout<<"-->INVALID";
            }
            cout<<endl;
        }
        fdict.close();
    }else{
        cout<<"Unable to open file";
    }
    return 0;
}

