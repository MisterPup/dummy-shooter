/*
 * Client.h
 *
 *  Created on: 29/set/2013
 *      Author: misterpup
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <pthread.h>

using namespace std;

struct thread_arg
{
	int socket;
	int endCopy;
	int exit;
} typedef thread_arg;

class Client
{
	public:

		string hostname;
		int port_number;
		int serverSocket;

		bool connected;
		bool threadStarted;

		pthread_t connectionThread;
		thread_arg t_args;

		Client();
		Client(string hostname, int port_number);
		virtual ~Client();
		Client(const Client& other);
		Client& operator=(const Client& other);

		void init();
		bool connectToServer();
		void disconnectFromServer();
		void startConnection();
		void start();
		//void* readWriteSocket(void *t);
};

#endif /* CLIENT_H_ */
