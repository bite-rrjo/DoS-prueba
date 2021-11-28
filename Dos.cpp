#include <iostream>
#include <string>
#include <curl/curl.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

#define Black "\e[30m"
#define Red "\e[31m"
#define Green2 "\e[32m"
#define Yellow "\e[33m"
#define Blue "\e[34m"
#define Magenta "\e[35m"
#define Cyan "\e[36m"
#define White "\e[37m"

#define F_italics "\e[3m"
#define F_transparent "\e[8m"
#define F_Normal "\e[0m"
#define F_Bold "\e[1m"
#define F_Strikethrough "\e[9m"
#define F_BlinkingText "\e[5m"

using namespace std;


class Internet{
    private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    bool errorGet = false;

    public:
    int errorGetWeb(){
        bool x = errorGet;
        errorGet = false;
        return x;
    }
     string get(const char* url){
         try{
             CURL *curl;
             CURLcode res;
             string bf;
             curl =curl_easy_init();
             if(curl){
               curl_easy_setopt(curl, CURLOPT_URL, url);
               curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
               curl_easy_setopt(curl, CURLOPT_WRITEDATA, &bf);
               res = curl_easy_perform(curl);
               curl_easy_cleanup(curl);
             }
             errorGet = true;
             return bf;
         }catch(const std::exception& e){
             errorGet = false;
             return "";
         }
         
       errorGet = false;
       return "";
     }



}Internet;

struct var{
    string Fr3 = "\e[36m           _____    \n\e[36m          / ___ \\\n\e[36m         / /__/ | ____               \e[33mHerramientas\n\e[36m        / __  _/'/    \\+ +       [\e[33m-sms '%numero%' '%archivo%'\e[36m]:\e[37m spam sms\n\e[36m       / /  \\ \\ | |||. |+  +     [\e[33m-BResponse '%url%' '%cantidad%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1\n\e[36m   + +/_/ + /_/+'\\____/' + +     [\e[33m-xerxer '%url%' '%puerto%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1\n\e[36m    + +++  +   ++  +  + ++  + v1\n\e[36m   git hub: https://github.com/bite-rrjo\e[0m\n\n";
    string key = "327";
}var;

int hack(int cc, char* agm[]){
    system("clear");
    cout << var.Fr3;
    return 0;
}

int main(int argc, char* argv[]){

    string argm = argv[0];
    if(argm == "./rrjo" || argm == "rrjo"){
        string res = Internet.get("https://raw.githubusercontent.com/bite-rrjo/DoS-prueba/main/actualizacion");
        if(Internet.errorGetWeb() == true){
            stringstream fg(res);
            string line;
            while(getline(fg, line)){
                res = line;
                break;
            }
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
                    cout << White "\n actualizacion completa :)\n" F_Normal;
                    system("./D320125324242342364");
                    return 0;
                }else{
                    cout << Red " Error en la actualizacion.\n" F_Normal;
                }
            }
        }
        hack(argc,argv);

    }else if(argm == "./D320125324242342364" || argm == "D320125324242342364"){
        sleep(5);
        if(remove("rrjo") != 0){
            cout << Red "error\n";
        }
        cout << Yellow "  configurando\n";
            rename("D320125324242342364", "rrjo");
            hack(argc,argv);
    }else{
        rename(argm.c_str(), "rrjo");
    }

    return 0;
}
}
