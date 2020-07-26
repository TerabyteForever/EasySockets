#include "SpaceSockets.hpp"

using namespace std;

int main(){

    int waiter,sender;
    char message[] = "Hi there from server!";
        int CreateUDPServer = SpaceSockets::UDP(); //Default parameters.
        while(1){

               waiter = SpaceSockets::WaitForMessage(SpaceSockets::sock);
                if(waiter != -1){


                        sender = SpaceSockets::SendMessage(message,MSG_DONTWAIT);

                } else {	
			printf("%s", "Error: WaitForMessage returned 0\n");
			break;
		}


        }





    return 0;
}
