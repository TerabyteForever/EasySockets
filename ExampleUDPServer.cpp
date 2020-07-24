#include "SpaceSockets.hpp"

using namespace std;
using namespace EasySockets;


int main(){

    int waiter,sender;
    char message[] = "Hi there from server!";
        int CreateUDPServer = SpaceSockets::UDP(); //Default parameters.
        while(1){

               waiter = SpaceSockets::WaitForMessage(EasySockets::sock);
                if(waiter != -1){


                        sender = SpaceSockets::SendMessage(message,MSG_DONTWAIT);

                }


        }





    return 0;
}