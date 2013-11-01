#include <iostream>
#include <stdlib.h>

#include "commands.h"

using namespace std;

int main(int argc, char* argv[]){

    std::string signal;
    std::string config;
    
    //Syntax check
    if(argc != 3){
        cout << "Syntax error" << endl << "Syntax: " << argv[0] << " <signal> <config file>" << endl;
        exit(0);
    }else{
        signal = argv[1];
        config = argv[2];
    }

    commands c;
    c.init(signal, config);
    
    return 0;
}

