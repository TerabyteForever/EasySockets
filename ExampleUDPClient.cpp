#include "SpaceSockets.hpp"



int main(){

        int CreateUDPClient = SpaceSockets::UDP();
        while(1){

                SpaceSockets::SendMessage("Hello world!",MSG_DONTWAIT);
                


        }


    return 0;
}