#include "EasySockets.hpp"

using namespace std;
using namespace EasySockets;


int main(){

    int waiter,sender;
    char message[] = "Hi there from server!";
        int CreateUDPServer = EasySockets::UDP(); //Default parameters.
        while(1){

               waiter = EasySockets::WaitForMessage(EasySockets::sock);
                if(waiter != -1){


                        sender = EasySockets::SendMessage(message,MSG_DONTWAIT);

                }


        }





    return 0;
}