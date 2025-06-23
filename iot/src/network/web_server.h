#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <WebServer.h>

extern WebServer server;

void setCORSHeaders();
void initWebServer();
void printServerInfo();
void handleWebServerClients();

#endif