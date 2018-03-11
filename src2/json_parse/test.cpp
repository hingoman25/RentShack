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
    string temp, line;
    int line_num = 0;
    //vector<vector<string> > str_vec;
    string my_arr[1000][2];
    ifstream fin;
    ifstream lin;
    bool eol = false;
    
    fin.open("rentshack-d2f8f-export.json");
    //lin.open("rentshack-d2f8f-export.json");
  
    if (fin.fail()) {
        cerr << "Error opening file" <<endl;
        exit(1);
    }
    int i = 0;
    int j = 0;
    
    while (true) {
        //getline(lin, line);
        fin >> word;
        
        cout << "word is: " << word <<endl;
        //cout << "line is: " << line <<endl;
        //cout << "im here 1" <<endl;
        
        //I want to ignore the inputted word if line % 10 = 3
        //line count??
        
        if (fin.eof())
            break;
        if (word == "{" || word == ":" || word == "posts" || word=="}"|| word=="}," || word == "")
            continue;
        eol = word_strip(word);
        if (word == "user-posts")
            return 0;
        if (word_check(word)) {
            my_arr[i][j]=word;
        }
        while (true) {
            fin >> word;
            if (fin.eof())
                break;
            if (word == "{" || word == ":" || word == "posts" || word=="}" || word=="}," || word == "")
                continue;
            if (word == "user-posts")
                return 0;
            //cout << "PRE: " << word <<endl;
            eol =word_strip2(word);
            //cout << "POST: " << word <<endl;
            temp = temp + " " + word;
            if (eol) {
                break;
            }
        }
        //cout << "TEMP IS: " <<temp <<endl;
        j = 1;
        my_arr[i][j] = temp;
        i++;
        j= 0;
        temp = "";
        //cout << word <<endl;
        
          //******Using STOI need to modify make, see piazza
    //      if (first_word) {
    //          weight = stoi(word);
    //          first_word = false;
    //          continue;
    //      }
    //
    //      my_trie.search_node(word);
    //
    //      //im at the end of the line, need to set weight, reset bool
    //      if (fin.peek() == '\n' || fin.peek() == '\r') {
    //          Trie::node* p = my_trie.getCurr();
    //          p->weight = weight;
    //          my_trie.setCurr(my_trie.getRoot()); //set curr equal to root
    //          first_word = true;
    //      }
    //
        
        }
    for (int i = 0; i < 9; i++) {
        cout << my_arr[i][0] << ":" << cout << my_arr[i][1] <<endl;
        cout << endl;
        cout <<endl;
    }
    
}

bool word_strip(string& word){
    bool check = false;
 
    if (word[word.length()-1] == ',') {
        check = true;
        
        word = word.substr(1, word.length()-3);
        //cout << "EOL word is: " <<word <<endl;
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
