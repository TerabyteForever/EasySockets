/*

EasySockets 

Lets you to create sockets easily.

Made by Ali Sancakli, 2020 <github.com/TerabyteForever> <alisancakli05@gmail.com>

Made for educational purposes only.


*/
#ifndef SPACESOCKETS_HPP
#define SPACESOCKETS_HPP

#include <iostream>
#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <unistd.h>

/*
Errors that returns approximately 500, are related to UDP method.
Errors that returns approximately 550, are related to both TCP and UDP.
Errors that returns approximately 600, are related to TCP method.
 */
#define SENDTO_ERROR 500
#define RECVFROM_ERROR 501 
#define SOCKET_ERROR 550
#define BIND_ERROR 551
#define LISTEN_ERROR 600
#define CONNECT_ERROR 601
#define SEND_ERROR 602
#define RECV_ERROR 603
#define ACCEPT_ERROR 604
#define CLOSE_ERROR 605 
#define PORT 8080

using namespace std;

namespace SpaceSockets{
        char UDPServerBuffer[1024] = {0};
        char UDPClientBuffer[1024] = {0};
        char TCPClientBuffer[1024] = {0};
        char TCPServerBuffer[1024] = {0};
        int sock,bin,receiver;
        int socktcp, bintcp, listenertcp, acceptortcp, sendertcp, connectortcp, receivertcp, closertcp; //These are for TCP method. They are going to store returning values of syscalls.
        struct sockaddr_in address;   
        struct sockaddr_in address_tcp;
        int addrtcp_length;
        int UDP(int domain = AF_INET,in_addr_t ipaddress = INADDR_ANY, int flag = MSG_DONTWAIT){

                address.sin_family = domain;
                address.sin_port = PORT;
                address.sin_addr.s_addr = ipaddress;
                address.sin_port = htons(PORT);
                
                sock = socket(domain,SOCK_DGRAM,0);
                if(sock == -1){

                        
                        return SOCKET_ERROR;


                }
                bin = bind(sock,(struct sockaddr*)&address,sizeof(address));
                if(bin == -1){


                        return BIND_ERROR;

                }

                        

         }
         int SendMessage(char message[],int flags = MSG_DONTWAIT){


                 int sender = sendto(sock,message,strlen(message),flags,(struct sockaddr*)&address,sizeof(address));
                        if(sender == -1){

                                        return SEND_ERROR;


                        } 


         }
        int WaitForMessage(int sockfd, int flag = MSG_DONTWAIT){

     

                receiver = recvfrom(sockfd,UDPServerBuffer,sizeof(UDPServerBuffer),flag,NULL,NULL); 
                if(receiver == -1){

                                return RECV_ERROR;
                     

                }
                else{


                        printf("%s\n",UDPServerBuffer);
                        

                }



                


                return 0;
        }
        
        int TCP(int domain = AF_INET,in_addr_t ipaddress = INADDR_ANY,int flags = MSG_DONTWAIT, int connectionLimit = 100){
                 
                address_tcp.sin_family = domain;
                address_tcp.sin_port = PORT;
                address_tcp.sin_addr.s_addr = ipaddress;
                address_tcp.sin_port = htons(PORT);       
                addrtcp_length = sizeof(address_tcp);

                socktcp = socket(domain,SOCK_STREAM,0);
                if(socktcp == -1){

                        return SOCKET_ERROR;


                }
                bintcp = bind(socktcp,(const struct sockaddr*)&address_tcp,sizeof(address_tcp));
                if(bintcp == -1){


                        return BIND_ERROR;



                }
                listenertcp = listen(socktcp,connectionLimit);
                if(listenertcp == -1){


                        return LISTEN_ERROR;



                }
                acceptortcp = accept(socktcp,(struct sockaddr*)&address_tcp,(socklen_t*)&addrtcp_length);
                if(acceptortcp == -1){

                                return ACCEPT_ERROR;



                }



        }
        int TCPSendMessage(char message[],int socketFileDesc = EasySockets::socktcp,int flags = MSG_DONTWAIT){

                sendertcp = send(socketFileDesc,message,strlen(message),flags);


                        printf("Sent message : %s",message);


                



        }
        int TCPReceiveMessage(char incomingMessage[],int maximumLengthOfMessage,int flags = MSG_DONTWAIT){

                        if(maximumLengthOfMessage == 0){

                                maximumLengthOfMessage = strlen(incomingMessage);


                        }
                        receivertcp = recv(socktcp,incomingMessage,maximumLengthOfMessage,flags);



                                printf("Client says : %s",incomingMessage);


                        


        }
        int TCPClient(){

                        int clienttcpsock = socket(AF_INET,SOCK_STREAM,0);

                        connectortcp = connect(clienttcpsock,(struct sockaddr*)&address_tcp,(socklen_t)addrtcp_length);
                        if(connectortcp == -1){

                                return CONNECT_ERROR;


                        }




        }
        int CloseTCPConnection(){


                closertcp = close(socktcp);
                if(closertcp == -1){


                                return CLOSE_ERROR;


                }



        }




}
#endif