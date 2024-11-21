#pragma once

#include <Net/web.h>

String DesignIndex(cWS *web, cWR *request, int socket);
void *IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket);