#ifndef CLIENT_H
#define CLIENT_H

void client_init();
void client_set_config();
void client_set_router();
void client_set_events();
int client_start();
void client_read_terminal();
void client_shutdown();

#endif // !CLIENT_H