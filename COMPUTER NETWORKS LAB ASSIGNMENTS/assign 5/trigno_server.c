//############QJ Technologies###########
//#Author: Qaidjohar Jawadwala		 # 
//#Email: info@qjtechnologies.com 	 #
//#Website: www.qjtechnologies.com     #
//######################################

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <math.h>
# define pi 3.142

int main(int argc, char* argv[])
{
	/*Variables*/
	int sock,csock;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int sin_size,choice;
	float num1,result;
	char buffer[1024],buffer1[1024];
	
	/*Socket*/
	if((sock = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("Failed to Create Socket");
		exit(1);
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);
	
	
	/*bind*/
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
	{
		perror("Bind Failed");
		exit(1);
	}
	
	
	/*listen*/
	
	if(listen(sock,5) == -1)
	{
			perror("Listen failed");
			exit(1);
	}
	
	/*Accept*/
	while(1)
	{
		sin_size = sizeof(client);
		csock = accept(sock,(struct sockaddr *)&client, &sin_size); 
		if(csock == -1)
		{
				perror("Accept Failed");
		}
		 //printf("\n I got a connection");
		printf("Connetion Received from: %s:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		
		//Receive Number 1
		if(recv(csock,&num1,sizeof(float),0)<0)
		{
			perror("Receive 1 Failed");
			exit(1);
		}
		printf("Num1:%f\n",num1);

		/*
		//Receive Number 2
		if(recv(csock,&num2,sizeof(int),0)<0)
		{
			perror("Receive 2 Fialed");
			exit(1);
		}
		printf("Num2:%d\n",num2);
		*/

		//Receive operator choice
		if(recv(csock,&choice,sizeof(int),0)<0)
		{
			perror("operato failed Fialed");
			exit(1);
		}
		printf("operator choice :%d\n",choice);
		
		//Perform specific operation and store in result

		if(choice == 1){
			printf("Calculating sin of %f",num1);
			
			result = sin(num1*(pi/180));		// Pi / 180 = degree to radian conversion
			printf("result %f",result);
		}else if(choice == 2){
			printf("Calculating cos of %f",num1);
			result = cos(num1*(pi/180));
			printf("result %f",result);
		}else if(choice == 3){
			printf("Calculating tan of %f",num1);
			result = tan(num1*(pi/180));
			printf("result %f",result);
		}else if(choice == 4){
			printf("Calculating cot of %f",num1);
			result = (1/tan(num1*(pi/180)));
			printf("result %f",result);
		}else if(choice == 5){
			printf("Calculating sec of %f",num1);
			result = (1/cos(num1*(pi/180)));
			printf("result %f",result);
		}else if(choice == 6){
			printf("Calculating cosec of %f",num1);
			result = (1/sin(num1*(pi/180)));
			printf("result %f",result);
		}else{
			printf("wrong choice given");
			result = 0;
		}

		printf("Result:%f\n",result);
		//Send result to the server
		if(send(csock,&result,sizeof(float),0)<0)
		{
			perror("Send Failed");
			exit(1);
		}
		
	/*Close*/
		close(csock);
	}
	
	

return 0;
}
