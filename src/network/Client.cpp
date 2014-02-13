/*
 * Client.cpp
 *
 *  Created on: 29/set/2013
 *      Author: misterpup
 */

#include "Client.h"
#include "../renderer/Renderer.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

void* readWriteSocket(void *t);

#define DEBUG_ACTIVE 0

Client::Client()
{
	this->hostname = "";
	this->port_number = -1;

	init();
}

Client::Client(string hostname, int port_number)
{
	this->hostname = hostname;
	this->port_number = port_number;

	init();
}

void Client::init()
{
	serverSocket = -1;

	connected = false;
	threadStarted = false;
	connectionThread = 0;
}

Client::~Client()
{
	disconnectFromServer();
}

Client& Client::operator=(const Client& other)
{
	hostname = other.hostname;
	port_number = other.port_number;
	serverSocket = other.serverSocket;

	init();

	return *this;
}

Client::Client(const Client& other)
{
	hostname = other.hostname;
	port_number = other.port_number;
	serverSocket = other.serverSocket;

	init();
}

//sarebbe da prendere l'hostname da una finestra di dialogo
bool Client::connectToServer()
{
	if(!connected)
	{
	    struct sockaddr_in serv_addr;
	    struct hostent *server;

	    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	    if (serverSocket < 0)
	    {
	    	cout << "ERROR opening socket" << endl;
	    	return false;
	    }

	    server = gethostbyname(hostname.c_str());
	    if (server == NULL)
	    {
	        cout << "ERROR, no such host" << endl;
	        return false;
	    }

	    memset((char *) &serv_addr, 0, sizeof(serv_addr));

	    serv_addr.sin_family = AF_INET;
	    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

	    serv_addr.sin_port = htons(port_number);
	    if (connect(serverSocket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
	    {
	    	cout << "ERROR connecting" << endl;
	    	return false;
	    }

	    fcntl(serverSocket, F_SETFL, O_NONBLOCK); //socket non bloccante in read

	    connected = true;
	}

	return true;
}

void Client::disconnectFromServer()
{
	cout << "Disconnect: IsConnected? " << connected << endl;

	if(connected)
	{
		if(threadStarted) //blocca thread prima di chiudere la socket, per evitare di interrompere un lavoro a metà
		{
			t_args.exit = 1;
			cout << "Stopping thread" << endl;
			pthread_join(connectionThread, NULL);
			threadStarted = false;
			t_args.exit = 0;
			cout << "Thread stopped" << endl;
		}

		close(serverSocket);
		connected = false;
	}
}

void Client::startConnection()
{
	pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	t_args.socket = serverSocket;
	t_args.endCopy = 0;
	t_args.exit = 0;

	int ret = pthread_create(&connectionThread, &attr, readWriteSocket, (void *)&t_args);
	if(ret == 0)
		threadStarted = true;
	//non serve più, perchè t_args non è una variabile locale
	//while(!t_args.endCopy) //prima di proseguire copio i dati
	//	sleep(0.1);
}

void* readWriteSocket(void *t)
{
	int socket = ((thread_arg*)t)->socket;
	((thread_arg*)t)->endCopy = 1;
	/*
	int sleep_micros = 1000; //senza una piccola sleep dopo un pò le stampe si incasinano
	//hint kep: ritardo rete 70 - 100 ms

    while(1)
    {
    	if(((thread_arg*)t)->exit)
    		break;

    	Renderer* renderer = Renderer::getInstance();
    	Player2D player = renderer->getGame()->getInstance()->getPlayerSystem().getPlayer();

		char tmp[256];
		sprintf(tmp, "%f, %f, %f, %f", player.getCurPosX(), player.getCurPosY(), player.getCurPosZ(), player.getDegRotation());

		//int nwrite =
		write(socket, tmp, sizeof(tmp));
		if(DEBUG_ACTIVE)
			cout << "Client Write: " << tmp << endl;

    	char buffer[256];

		int nread = read(socket, buffer, sizeof(buffer));
		if(nread > 0)
		{
			if(DEBUG_ACTIVE)
				cout << "Client Read: " << buffer << endl;

			char* curToken;
			curToken = strtok (buffer," ,");
			newPosXOther = strtod(curToken, NULL);

			curToken = strtok (NULL," ,");
			newPosYOther = strtod(curToken, NULL);

			curToken = strtok (NULL," ,");
			newPosZOther = strtod(curToken, NULL);

			curToken = strtok (NULL," ,");
			degRotationOther = strtod(curToken, NULL);
		}

		usleep(sleep_micros);
    }*/

    pthread_exit(t);
}
