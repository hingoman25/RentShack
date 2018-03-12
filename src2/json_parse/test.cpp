#include <iostream> 
#include <string> 
#include<fstream>
#include <vector>

using namespace std; 

bool word_check(string word);
bool word_strip(string& word);
bool word_strip2(string& word);

int main(int argc, char *argv[]) { 
    string word;
    string temp;
    int line_num = 0;
    string my_arr[10000][2];
    ifstream fin;
    int i = 0;
    int j = 0;
    int num_p = 0;
    bool eol = false;
    
    fin.open("rentshack-d2f8f-export.json");
  
    if (fin.fail()) {
        cerr << "Error opening file" <<endl;
        exit(1);
    }

    while (true) {
        fin >> word;
        
        
        if (fin.eof())
            break;
        if (word == "{" || word == ":" || word == "posts" || word=="}"|| word=="}," || word == "")
            continue;
        if (word[1]=='-' && word[word.length()-1]!=',')
            continue;
        eol = word_strip(word);
        if (word == "user-posts") {
            //code to clean up the strings not working
//            for (int i = 0; i < num_p; i++) {
//                for (int j = 0; j < my_arr[i][1].length(); j++) {
//                    string tempw;
//                    if (my_arr[i][0] == "username") {
//                        tempw = my_arr[i][1].substr(0, my_arr[i][1].length() -1);
//                        my_arr[i][1] = tempw;
//                    }
//                }
//            }
            
            //INSERT CODE TO WRITE TO TXT HERE and then call the main.cpp to get most_frequent here 
            
            for (int i = 0; i < num_p; i++) {
                cout << my_arr[i][0] << ":" << my_arr[i][1] << endl;
                cout << endl;
            }
            
            
            
            return 0;
        }
        if (word_check(word)) {
            my_arr[i][j]=word;
            num_p++;
        }
        while (true) {
            bool end_att = false;
            fin >> word;
            if (fin.eof())
                break;
            if (word == "{" || word == ":" || word == "posts" || word=="}" || word == "")
                continue;
            if (word=="},") {
                end_att = true;
            }
                
            if (word[1]=='-' && word[word.length()-1]!=',')
                continue; 
            if (word == "user-posts") {
                return 0;
            }
            eol =word_strip2(word);
            temp = temp + " " + word;
            
            if (eol || end_att) {
                break;
            }
            
        }
        j = 1;
        my_arr[i][j] = temp;
        i++;
        j= 0;
        temp = "";

        
        }
    
    
}

bool word_strip(string& word){
    bool check = false;
 
    if (word[word.length()-1] == ',') {
        check = true;
        
        word = word.substr(1, word.length()-3);
    }
    else {
        word = word.substr(1, word.length()-2);
        //cout << "NORM: " << word <<endl;
    }
    
    //word = temp;
    return check;
}

bool word_strip2(string& word){
    bool check = false;
    
    if (word[word.length()-1] == ',') {
        check = true;
        word = word.substr(0, word.length()-1);
    }
    
    return check;
}

bool word_check(string word) {
    if (word != "email" ||word != "imageURL" ||word != "itemDescription" ||
        word != "pid" || word != "pricePerHour" ||word != "titlePost" ||word != "uid" ||
        word != "username")
        return true;
    return false;
}
