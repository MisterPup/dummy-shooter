/*
 * Client.h
 *
 *  Created on: 29/set/2013
 *      Author: misterpup
 */

#include <pthread.h>

#ifndef CLIENT_H_
#define CLIENT_H_

struct thread_arg
{
	int socket;
	int endCopy;
	int exit;
} typedef thread_arg;

class Client
{
	public:

		char* hostname;
		int port_number;
		int serverSocket;

		bool connected;
		bool threadStarted;

		pthread_t connectionThread;
		thread_arg t_args;

		Client(char* hostname, int port_number);
		virtual ~Client();
		bool connectToServer(char* serverHostname);
		void disconnectFromServer();
		void startConnection();
		void start();
		//void* readWriteSocket(void *t);
};

#endif /* CLIENT_H_ */
