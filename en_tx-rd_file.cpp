#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#pragma GCC optimize("Ofast")

using namespace std;
/*
void p_string(const string s){
    for(const auto &i:s) cout<<(int)(i)<<' ';
    cout<<endl;
}
*/
bool try_again(){
    string again;
    cout << "Do you want to keep going? (Y/N): ";
    cin >> again;
    return (again == "Y");
}

int ask(vector<vector<string>> &ans_list, int mod = 0){
    string q, a, answer;
    int r = rand() % ans_list.size();
    if(mod){
        q = ans_list[r][0];
        a = ans_list[r][1];
    } else {
        q = ans_list[r][1];
        a = ans_list[r][0];
    }
    cout << "question: " << q << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(cin.fail()){ // check if input was successful
        cerr << "Error: invalid input" << endl;
        return 0;
    }
    ans_list.erase(ans_list.begin() + r);
    if(answer == a){
        cout << "Correct!" << endl;
        //ans_list.erase(ans_list.begin() + r);
        return 1;
    }
    cout << "db*" ;
    //p_string(answer);
    //p_string(a);
    cout << "The correct answer is: " << a << endl;
    return 0;
}

int read_file(vector<vector<string>> &ans_list){
    FILE *fp = freopen("wordbank.txt", "r", stdin);
    if(!fp){ // check if file was opened successfully
        cerr << "Error: unable to open file" << endl;
        return 0;
    }
    string english_answer, chinese_answer;
    int word_count = 0;
    while(cin >> chinese_answer >> english_answer){
        ans_list.push_back({chinese_answer, english_answer});
        word_count++;
    }
    cin.clear();
    freopen("CON", "r", stdin);

    return word_count;
}

int main(){
    int correct_time = 0, ask_time = 0;
    srand(time(NULL)); // seed the random number generator
    vector<vector<string>> answer_list;
    string english_answer, chinese_answer, mode;
    int num1;

    num1 = read_file(answer_list);
    cout << "db: " << num1 << endl;

    cout << "請選擇模式 (A/B/C)(中翻英/英翻中/隨機)";
    cin >> mode;

    do{
        ask_time++;
        if(mode == "A" || mode == "中翻英"){
            correct_time += ask(answer_list);
        } else if(mode == "B" || mode == "英翻中"){
            correct_time += ask(answer_list, 1);
        } else if(mode == "C" || mode == "隨機"){
            int randmode = rand() % 2;
            correct_time += ask(answer_list, randmode);
        } else {
            ask_time--;
            cout << "Invalid mode. Please choose A, B, or C." << endl;
            cout << "請選擇模式(A,B,C)(中翻英/英翻中/隨機)";
            cin >> mode;
        }
    } while(answer_list.size() && try_again());
    cout << "GAME OVER! " << '\n' ;//<< '|' << correct_time << '/' << ask_time << '|' << '\n';
}