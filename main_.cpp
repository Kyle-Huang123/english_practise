#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool try_again(){
    string again;
    cout << "Do you want to try again? (Y/N): ";
    cin >> again;
    return (again == "Y");
}

void ask(vector<vector<string>> &ans_list,int mod = 0){
    string q,a,answer;
    int r = rand() % ans_list.size();
    if(mod){
        q = ans_list[r][0];
        a = ans_list[r][1];
    }
    else{
        q = ans_list[r][1];
        a = ans_list[r][0];
    }
    ans_list.erase(ans_list.begin()+r);
    cout<<"question: "<<q<<endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == a){
        cout << "Correct!" << endl;
    }
    else{
        cout << "Incorrect, the correct answer is: " << a << endl;
    }
}

int main(){
    srand(time(NULL));
    vector<vector<string>> answer_list;
    string english_answer, chinese_answer, mode;
    int num1;
    
    cout << "請輸入有幾個單字";
    cin >> num1;

    if(!(num1)) return 0;
    
    for(int i = 0;i < num1;i++){
        cout<<"請輸入第"<<i+1<<"個單字(英+空白+中)";
        cin >> english_answer >> chinese_answer;
        answer_list.push_back({english_answer,chinese_answer});
    }

    cout << "請選擇模式(A,B,C)(中翻英/英翻中/隨機)";
    cin >> mode;

    do{
        if(mode == "A"||mode == "中翻英"){
            ask(answer_list);
        }
        else if(mode == "B"||mode == "英翻中"){
            ask(answer_list,1);
        }
        else if(mode == "C"||mode == "隨機"){
            int randmode = rand() % 2;
            ask(answer_list,randmode);
        }
    }while(answer_list.size()&&!(try_again()));
}