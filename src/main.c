#include <stdlib.h>
#include "../include/client.h"

int main()
{
    client_init();
    client_set_config();
    client_set_router();
    client_set_events();
    client_start();
    client_shutdown();

    return EXIT_SUCCESS;
}
