#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char const *argv[],char const *envp[]) 
{   
    int new_socket2, valread;
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
    
    new_socket2 = atoi(argv[1]);
   
    int userid = setuid(65534);
        if(userid == -1)
        {
            printf("Error in changing user id");
            exit(EXIT_FAILURE);
        }
        valread = read( new_socket2 , buffer, 1024); 
        printf("%s\n",buffer ); 
        send(new_socket2 , hello , strlen(hello) , 0 ); 
        printf("Hello message sent\n");
    
    return 0;
}
