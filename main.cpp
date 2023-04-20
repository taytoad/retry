/*
retry: a simple command repeater
--------------------------
made by @taytoad on github
toadawork@gmail.com
--------------------
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <csignal>

size_t g_secondsBetween=2;
size_t g_numRetries=0;
std::string g_command="echo \"No command was set or the parameters arent correct.. \nre-run with -h to see usage\" ";

char* g_help_str= R"(retry: a command repeater
--------------------------
made by @taytoad on github
toadawork@gmail.com
--------------------
Usage:
retry "[Command]" options...
-r|-R: number of retries if it fails
-t|-T: time between the command to run it again\n
-h|-H: help menu
)";

bool IsDigit(int character) {
    if(character>='0'&&character<='9')
        return true;

    return false;
}



char* getParameter(char* param) {
    int c=0;
    char* tmp=param;
    for(int t=0; t< strlen(param);t++) {
        //std::cout << param[t] << "\n";
        if(IsDigit(param[t]))
            continue;
        else
            c++;
    }
    return &tmp[c];
}

void checkParameters(int argc, char* argv[]) {

    if(argv[1][0]!='-')
        g_command=argv[1];
    else{
        system(g_command.c_str());
        exit(0);
    }

    for (int i =argc<=2?1:2; i < argc; i++) {
        //directly check for delimeter
        if(argv[i][0]=='-')
            if(!isdigit(argv[i][strlen(argv[i])])) {
                switch(argv[i][1]) {
                    case 'r'|'R':
                        g_numRetries= atoi(getParameter(argv[i]));
                        break;

                    case 't'|'T':
                        g_secondsBetween= atoi(getParameter(argv[i]));
                        break;

                    case 'h'|'H':
                        std::cout << g_help_str;
                        exit(0);
                        break;
                }

            } else {
                if(!(i+1>argc))
                    if(IsDigit(argv[i+1][0]) &&
                       IsDigit(argv[i+1][strlen(argv[i+1])])) {
                        switch (argv[i][1]) {
                            case 'r' | 'R':
                                g_numRetries = atoi(argv[i + 1]);
                                break;
                            case 't' | 'T':
                                g_secondsBetween = atoi(argv[i + 1]);;
                                break;
                        }
                        i++;
                    }
            }

    }
}

int runCommand(std::string command) {
    if(g_numRetries>0)
        for(int i=0;i<g_numRetries-1;i++) {
            system(command.c_str());
            if(g_secondsBetween>0)
                sleep(g_secondsBetween);
        }

    return system(command.c_str());
}

int main(int argc, char* argv[]) {

    if(argc<=1) {
        system(g_command.c_str());
        exit(0);
    }

    checkParameters(argc, argv);

    int retcode = runCommand(g_command);
    if(retcode!=0) {
        runCommand(g_command);
    }

}
