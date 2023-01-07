#ifndef ROUTES_H
#define ROUTES_H

#include <oyamo/message.h>

void chat_omessage(void *empty, oyamo_message_T *message);
void chat_onjoined(void *empty, oyamo_message_T *message);

#endif // !ROUTES_H