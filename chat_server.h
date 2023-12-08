#include <iostream>
#include <string>
#include <unordered_map>
#include <cerrno>			
#include <cstring>	
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#pragma once


bool shutdown_client_connection(int fd, std::unordered_map<int,std::string> &u_map_client);

bool send_message_all(int fd, std::unordered_map<int,std::string> &u_map_client, std::string &str_1);

bool new_client_connection(int fd, struct sockaddr_in *Client_info, std::unordered_map<int,std::string> &u_map_client);

bool save_client_info(int fd, struct sockaddr_in *Client_info, std::unordered_map<int,std::string> &u_map_client);

//	Функция записывает исключения(exception) в файл exception_log
void error_log(const char *name_function, const int int_err, const char *string_err);
// Функция записывает сообщение сообщение, при отправке которого произошла ошибка в файл error_log
void error_msg(std::string &message);
//	Функция записывает ошибки системных вызовов в файл error_log
void exception_log(const char *exc);
//	Функция логирования
void log(const char *s);
