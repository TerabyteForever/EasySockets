/*

EasySockets 

Lets you to create sockets easily.

Made by Ali Sancakli, 2020 <github.com/TerabyteForever> <alisancakli05@gmail.com>

Made for educational purposes only.

*/
#ifndef EASYSOCKETS_HPP
#define EASYSOCKETS_HPP

#include <iostream>
#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

/*
Errors that returns approximately 500, are related to UDP method.
Errors that returns approximately 550, are related to both TCP and UDP.
Errors that returns approximately 600, are related to TCP method.
 */
#define NO_ERRORS 0
#define SENDTO_ERROR 500
#define RECVFROM_ERROR 501 
#define SOCKET_ERROR 550
#define BIND_ERROR 551
#define CLOSE_ERROR 552 
#define LISTEN_ERROR 600
#define CONNECT_ERROR 601
#define SEND_ERROR 602
#define RECV_ERROR 603
#define ACCEPT_ERROR 604
#define PORT 8080

using namespace std;

namespace EasySockets{
        char UDPServerBuffer[1024] = {0};
        char UDPClientBuffer[1024] = {0};
        bool debug = false;
        int sock,bin,receiver;
        struct sockaddr_in address;   
        

        void setDebugInfo(bool set){

                if(set == true){

                    debug = true;

                }
                else{

                    debug = false;

                }

        }
        int UDP(int domain = AF_INET,in_addr_t ipaddress = INADDR_ANY, int flag = MSG_DONTWAIT){

                address.sin_family = domain;
                address.sin_port = PORT;
                address.sin_addr.s_addr = ipaddress;
                address.sin_port = htons(PORT);
                
                sock = socket(domain,SOCK_DGRAM,0);
                if(sock == -1){

                        
                        return SOCKET_ERROR;
                        if(debug == true){

                        cout<<"Socket creation failed!"<<endl;

                        }

                }
                bin = bind(sock,(struct sockaddr*)&address,sizeof(address));
                if(bin == -1){


                        return BIND_ERROR;
                        if(debug == true){

                        cout<<"Cannot create port!"<<endl;

                        }

                }


                if(sock != -1 && bin != -1){


                        if(debug == true){

                        cout<<"Server created successfully!"<<endl;

                        }


                }




         }
         int SendMessage(char message[],int flags = MSG_DONTWAIT){


                 int sender = sendto(sock,message,sizeof(message),flags,(struct sockaddr*)&address,sizeof(address));
                        if(sender == -1){

                                        return SEND_ERROR;


                        }

         }
        int WaitForMessage(int sockfd, int flag = MSG_DONTWAIT){

     

                receiver = recvfrom(sockfd,UDPServerBuffer,sizeof(UDPServerBuffer),flag,NULL,NULL); //I got an error from here.
                if(receiver == -1){

                                return RECV_ERROR;
                     

                }
                else{


                        printf("%s\n",UDPServerBuffer);


                }



                


                return 0;
        }
        




}
#endif