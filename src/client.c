#include "../include/common.h"
#include "../include/client.h"
#include "../include/routes.h"

#include <oyamo/client.h>

void client_init()
{
    oyamo_set_verbose(OYAMO_VERBOSE_ALL);
    oyamo_client_init();

    attr = malloc(sizeof(struct CLIENT_ATTR_STRUCT));
}

void client_set_config()
{
    oyamo_client_config_T *config = oyamo_client_get_default_config("127.0.0.1", 5323);
    config->thread = true;
    oyamo_client_set_config(config);
}

void client_set_router()
{
    oyamo_router_T *router = oyamo_router_create();

    oyamo_router_route_T *routeJoined = oyamo_router_create_route("user", "set-username", chat_onjoined);
    oyamo_router_route_T *routeMessage = oyamo_router_create_route("chat", "send-message", chat_omessage);

    oyamo_router_set_route(router, routeJoined);
    oyamo_router_set_route(router, routeMessage);

    oyamo_client_set_router(router);
}

void client_set_events()
{
    // ...
}

int client_start()
{
    if (oyamo_client_go() != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    client_read_terminal();
}

void client_read_terminal()
{
    char message[1024];
    static char username[20];

    oyamo_message_T *chat_message = oyamo_message_create("chat", "send-message");
    printf("Username> ");
    fgets(username, 20, stdin);
    username[strcspn(username, "\r\n")] = 0;

    json_object_object_add(chat_message->parameters, "username", json_object_new_string(username));

    while (1)
    {
        fgets(message, 1024, stdin);
        message[strcspn(message, "\r\n")] = 0;

        if (strcmp(message, "/exit") == 0)
        {
            break;
        }

        json_object_object_add(chat_message->parameters, "message", json_object_new_string(message));
        oyamo_client_send(chat_message);
    }

    oyamo_message_free(chat_message);
}

void client_shutdown()
{
    oyamo_client_shutdown();
}
