#include "EasySockets.hpp"



int main(){

        int CreateUDPClient = EasySockets::UDP();
        while(1){

                EasySockets::SendMessage("Hello world!",MSG_DONTWAIT);
                


        }


    return 0;
}