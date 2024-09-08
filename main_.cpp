#include<bits/stdc++.h>
using namespace std;

int num1 = 0,num2 = 0,num3 = 0,num4 = 0,mode2 = 0;
int correct_time = 0,incorrect_time = 0;
bool running = true;
vector<vector<string>> answer_list;
string mode1 = "中翻英",answer = "a",again = "no"; 
string english_answer, chinese_answer;
string ans[] = {chinese_answer,english_answer}; 
int mode(){
    srand(time(NULL));
    num3 = rand();
    num3 = num3 % 2;
    if(num3 == 0){
        mode2 = 0;
        return mode2;
    }
    else{
        mode2 = 1;
        return mode2;

    }

}
int main(){
    
    cout << "請輸入有幾個單字";
    cin >> num1;
    //answer_list.push_back(vector<string>(num1-1));
    
    for(int i = 0;i < num1;i++){
        cout<<"請輸入第"<<i+1<<"個單字(英+空白+中)";
        cin >> english_answer >> chinese_answer;
        answer_list.push_back({english_answer,chinese_answer});
        //answer_list[i].push_back(chinese_answer);
    }
    
    
    /*cout << num1 << running << '\n';
    cout << answer_list[0][1] << '\n';*/
    cout << "請選擇模式(A,B,C)(中翻英/英翻中/隨機)";
    cin >> mode1;
    srand(time(NULL));
    if(mode1 == "A"||mode1 == "中翻英"){
        while(num1 > 0 && running){
            num2 = rand();
            num2 = num2 % num1;
            chinese_answer = answer_list[num2][1];
            english_answer = answer_list[num2][0];
            cout <<"題目是:" << chinese_answer << '\n';
            cout << "答案:";
            cin >> answer;
           
            if(answer == english_answer){
                cout << "答對了!" << '\n';
                correct_time ++;
            }
            else{
                cout << "答錯了" << '\n';
                incorrect_time ++;

            }
            answer_list.erase(answer_list.begin() + num1);
            num1 -= 1;
           
            if(num1 > 0){
                cout << "要繼續嗎?(yes/no)";
                cin >> again;
               
                if(again == "yes"){
                    running = true;
                }
                else{
                    running = false;
                }
            }
            else{
                running = false;
            }
        }
    }
    else if(mode1 == "英翻中"||mode1 == "B"){
        while(num1 > 0 && running){
            num2 = rand();
            num2 = num2 % num1;
            english_answer = answer_list[num2][0];
            chinese_answer = answer_list[num2][1];
            cout << "題目是:" << english_answer << '\n';
            cout << "答案:";
            cin >> answer;
           
            if(answer == chinese_answer){
                cout << "答對了!" << '\n';
                correct_time ++;

            }
            else{
                cout << "答錯了!" << '\n';
                incorrect_time ++;

            }
            answer_list.erase(answer_list.begin() + num1);
            num1 -= 1;
           
            if(num1 > 1){
                cout << "要繼續嗎?";
                cin >> again;
              
                if(again == "yes"){
                    running = true;

                }
                else{
                    running = false;
                }
            
            
            }
            else{
                running = false;
            }

        }
            
    }
    else if(mode1 == "隨機"||mode1 == "C"){
        while(running && num1 > 1){
            if(mode2 == 0){
                num4 = 0;
            }
            else if(mode2 == 1){
                num4 = 1;
            }
            num2 = rand();
            num2 = num2 % num1;
            cout << "題目是:" << answer_list[num2][num4] << '\n';
            cout << "答案:";
            cin >> answer;
            if(answer == answer_list[num2][1-num4]){
                cout << "答對了!" << '\n';
                correct_time ++;
            }
            else{
                cout << "答錯了!" << '\n';
                incorrect_time ++;

            }
            if(num1 > 1){
                cout << "要繼續嗎?(yes/no)";
                cin >> again;
                if(again == "yes"){
                    running = true;

                }
                else{
                    running = false;
                }

            }
            else{
                running = false;
            }

        }
        
    }
    return 0;
}