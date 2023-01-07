#include "../include/routes.h"

void chat_omessage(void *empty, oyamo_message_T *message)
{
    struct json_object *username_object;
    struct json_object *message_object;

    json_object_object_get_ex(message->parameters, "username", &username_object);
    json_object_object_get_ex(message->parameters, "message", &message_object);

    const char *username_string = json_object_get_string(username_object);
    const char *message_string = json_object_get_string(message_object);

    printf("%s: %s\n", username_string, message_string);
}

void chat_onjoined(void *empty, oyamo_message_T *message)
{
    oyamo_print_success("An user joined to chat...");
}
