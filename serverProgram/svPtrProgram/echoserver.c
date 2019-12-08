#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <event.h>

#define PORT 24000
#define BACKLOG -1
#define BUFSIZE 256

struct event accept_ev;
struct event_base *ebase;
int listener_sd;

void accept_handler(int listener,short event,void *arg);
void recv_handler(int listener,short event,void *arg);

int main(int argc,const char* argv[])
{
	struct sockaddr_in sin;
	int result;

	memset(&sin,0,sizeof(struct sockaddr_in));
	
	if((listener_sd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0)
	{
		perror("socket error:");
		return -1;
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(PORT);

	if(bind(listener_sd,(struct sockaddr*)&sin,sizeof(struct sockaddr)) < 0)
	{
		perror("bind error:");
		return -1;
	}
	if(listen(listener_sd, BACKLOG) < 0)
	{
		perror("listen error:");
		return -1;
	} 
	ebase = event_base_new();
	
	event_set(&accept_ev, listener_sd, EV_READ | EV_PERSIST, accept_handler, &accept_ev);
	event_base_set(ebase,&accept_ev);
	event_add(&accept_ev,NULL);
	
	event_base_dispatch(ebase);

	event_base_free(ebase);
	return 0;
}

void accept_handler(int listener, short event,void *arg)
{
	struct event *ev;
	struct sockaddr_in addr;
	int client;
	socklen_t addrlen = sizeof(addr);

	if(event & EV_READ)
	{
		client = accept(listener,(struct sockaddr*)&addr,&addrlen);
		ev = (struct event*)malloc(sizeof(struct event));
		event_set(ev, client, EV_READ | EV_PERSIST, recv_handler,ev);
		event_base_set(ebase,ev);
		event_add(ev,NULL);
		printf("connection accepted\n");
	}
}

void recv_handler(int client, short event,void *arg)
{
	char buf[BUFSIZE];
	struct event *ev = (struct event*)arg;
	ssize_t recvlen;
	
	if(event & EV_READ)
	{
		if((recvlen = recv(client, buf,BUFSIZE-1,0)) <= 0)
		{
			event_del(ev);
			free(ev);
			close(client);
			printf("connection closed\n");
		}
		else
		{
			printf("MACCLE");
			send(client,buf,recvlen, 0);
		}
	}
}

