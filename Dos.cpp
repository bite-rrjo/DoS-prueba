#include "net.h"
#include <color.h>
#include <unistd.h>
#include <fstream>
using namespace std;

struct var{
    string Fr3 = R"(
\e[36m           _____    
\e[36m          / ___ \  
\e[36m         / /__/ | ____               \e[33mHerramientas
\e[36m        / __  _/'/    \+ +       [\e[33m-sms '%number%' '%file%'\e[36m]:\e[37m spam sms
\e[36m       / /  \ \ | |||. |+  +     [\e[33m-BResponse '%url%' '%number%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1
\e[36m   + +/_/ + /_/+'\____/' + +     [\e[33m-xerxer '%url%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1
\e[36m    + +++  +   ++  +  + ++  +
\e[36m   git hub: https://github.com/bite-rrjo\e[0m
)";
    string key = "327";
}var;

int hack(){
    cout << "xd";
    return 0;
}

int main(int argc, char* argv[]){

    string argm = argv[0];
    if(argm == "./rrjo" || argm == "rrjo"){
        string res = Internet.get("https://raw.githubusercontent.com/bite-rrjo/DoS-prueba/main/actualizacion");
        if(Internet.errorGetWeb() == true){
            if(res == var.key ){
                
            }else{
                cout << Red F_Bold " No elimine archivos ni cierre el programa.\n" F_Normal;
                res = Internet.get("https://raw.githubusercontent.com/bite-rrjo/DoS-prueba/main/Dos.cpp");
                if(Internet.errorGetWeb() == true){
                    ofstream file("98381289738127367239f.cpp");
                    file << res;
                    file.close();
                    system("g++ 98381289738127367239f.cpp -o D320125324242342364 -lcurl");
                    remove("98381289738127367239f.cpp");
                    system("./D320125324242342364");
                    cout << White "\n actualizacion completa :)\n" F_Normal;
                    return 0;
                }else{
                    cout << Red " Error en la actualizacion.\n" F_Normal;
                }
            }
        }
        hack();

    }else if(argm == "./D320125324242342364" || argm == "D320125324242342364"){
        sleep(5);
        if(remove("rrjo") != 0){
            cout << Red "error\n";
        }
            rename("D320125324242342364", "rrjo");
            hack();
    }else{
        rename(argm.c_str(), "rrjo");
    }

    return 0;
}
