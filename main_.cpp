#include<iostream>
#include<vector>
#include<string>
#pragma GCC optimize("Ofast")//就想加速一下 O_O

using namespace std;

bool try_again(){
    string again;
    cout << "Do you want to try again? (Y/N): ";
    cin >> again;
    return (again == "Y");
}

void ask(vector<vector<string>> &ans_list,int mod = 0){//mod(模式):0是中翻英,1是英翻中
    string q,a,answer;//q是題目,a是答案
    int r = rand() % ans_list.size();
    if(mod){
        q = ans_list[r][0];
        a = ans_list[r][1];
    }
    else{
        q = ans_list[r][1];
        a = ans_list[r][0];
    }
    cout<<"question: "<<q<<endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == a){
        cout << "Correct!" << endl;
        ans_list.erase(ans_list.begin()+r);//刪除已答對的
    }
    else{
        cout << "Incorrect, the correct answer is: " << a << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);//關閉stdio
    srand(time(NULL));//種子設定
    vector<vector<string>> answer_list;
    string english_answer, chinese_answer, mode;//mode是模式
    int num1;
    
    cout << "請輸入有幾個單字";
    cin >> num1;

    if(!(num1)) return 0;
    
    for(int i = 0;i < num1;i++){//輸入單字
        cout<<"請輸入第"<<i+1<<"個單字(英+空白+中)";
        cin >> english_answer >> chinese_answer;
        answer_list.push_back({english_answer,chinese_answer});
    }

    cout << "請選擇模式(A,B,C)(中翻英/英翻中/隨機)";
    cin >> mode;
    
    do{//開始回答
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