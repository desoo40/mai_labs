//
//
//
//
//#include <string.h>
//#include <stdio.h>
////#include <unistd.h>
//#include "zmq.h"
//
//int main(int argc, char const *argv[])
//{
//	void* context = zmq_ctx_new();
//	void* respond = zmq_socket(context, ZMQ_REP);
//
//	zmq_bind(respond, "tcp://*:4040");
//	printf("Starting...\n");
//
//	for (;;)
//	{
//		printf("1\n");
//		zmq_msg_t request;
//		printf("1\n");
//		zmq_msg_init(&request);
//		printf("1\n");
//		zmq_msg_recv(&request, respond, 0);
//		printf("1\n");
//		printf("Received: hello\n");
//		zmq_msg_close(&request);
//		//sleep(1); // sleep one second
//		zmq_msg_t reply;
//		zmq_msg_init_size(&reply, strlen("world"));
//		memcpy(zmq_msg_data(&reply), "world", strlen("hello"));
//		zmq_msg_send(&reply, respond, 0);
//		zmq_msg_close(&reply);
//	}
//	zmq_close(respond);
//	zmq_ctx_destroy(context);
//
//	return 0;
//}