#include <iostream>
#include <string>

using namespace std;

bool cpp = false, java = false, error = false;
string answer = "";

void Cpp_to_Java(string v){ // cpp로 가정한 경우
    for(int i=0;i<v.length();i++){
        if(isupper(v[i])){
            error = true;
            cpp = false;
            return;
        }
        else if(islower(v[i]))
            answer += v[i];
        else if('_'){
            i++;
            answer += toupper(v[i]);
        }
    }
    return;
}

void Java_to_Cpp(string v){ // java로 가정한 경우
    for(int i=0;i<v.length();i++){
        if (v[i] == '_'){
            error = true;
            java = false;
            return;
        }
        else if(islower(v[i]))
            answer += v[i];
        else if(isupper(v[i])){
            answer += '_';
            answer += tolower(v[i]);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string variable;
    cin >> variable;

    if(isupper(variable[0])){   // 첫 문자부터 대문자 => error
        error = true;
        cpp = false;
        java = false;
    }
    else{
        error = false;
        for(int i=1;i<variable.length();i++){
            if(isupper(variable[i])) {   // 대문자 => java로 가정
                java = true;
                Java_to_Cpp(variable);
                break;
            }
            else if(variable[i] == '_') { // '_' => cpp로 가정
                cpp = true;
                Cpp_to_Java(variable);
                break;
            }
        }
        if(!error && !cpp && !java)
            answer = variable;
    }

    if(error)
        cout << "Error!" << "\n";
    else
        cout << answer << "\n";

    return 0;
}
