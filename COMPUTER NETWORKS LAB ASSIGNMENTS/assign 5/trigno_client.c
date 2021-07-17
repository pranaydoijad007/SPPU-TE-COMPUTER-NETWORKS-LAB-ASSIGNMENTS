//############QJ Technologies###########
//#Author: Qaidjohar Jawadwala		 # 
//#Email: info@qjtechnologies.com 	 #
//#Website: www.qjtechnologies.com     #
//######################################


#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
//#include<math.h>



int main(int argc, char* argv[])
{
/*Variables*/
	int sock;
	float num1,result;
	char buffer[1024],buffer1[1024];
	struct hostent *host;
	struct sockaddr_in server;
	int choice;
	host = gethostbyname(argv[1]);
/*Socket*/
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == -1)
	{
		perror("Socket Failed");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	server.sin_port = htons(5000);
	memcpy(&server.sin_addr,host->h_addr,host->h_length);
	
/*Connect*/
	
	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0)
	{
			perror("Connect Failed");
			exit(1);
	}

	//Number 1 input
	printf("\nEnter number:");
	scanf("%f",&num1);
	printf("num 1 %f",num1);

	printf("\nOperations ::: "
			"\n1. sin"
			"\n2. cos"
			"\n3. tan"
			"\n4 cot"
			"\n5 sec"
			"\n6 cosec"
			"\nEnter Choice Number :: ");
	scanf("%d",&choice);
	
/*Send*/
	//Sending Number 1
	if(send(sock,&num1,sizeof(float),0)<0)
	{
		perror("send failed");
		exit(1);
	}

	//Sending Operator choice number
	if(send(sock,&choice,sizeof(int),0)<0)
	{
		perror("operator Failed");
		exit(1);
	}

	//Receiving the addition resule
	recv(sock,&result,sizeof(float),0);
	
	printf("Answer is : %f\n",result);
	return 0;
}
