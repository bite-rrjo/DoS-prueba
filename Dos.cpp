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
    string version = "2";
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

int hack(int cc, char* arm[]){

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
