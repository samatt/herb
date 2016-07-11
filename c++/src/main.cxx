#include "HerbSniffer.h"
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
  if ( argc != 2 ){
    cout<<"usage: "<< argv[0] <<" <command>\n";
  }
  else {
    if (string(argv[1]) == "sniffer"){
      HerbSniffer sniffer = HerbSniffer();
      sniffer.run();
    }
    else{
      cout<<"Unkown command"<<endl;
    }
  }
}