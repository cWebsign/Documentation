#pragma once

#include <Net/web.h>

extern CSS *IndexCSS[];

void LayoutInit(cWS *web, cWR *request, WebRoute *route, int socket);
void IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket);

void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket);
void DocHandler(cWS *web, cWR *r, WebRoute *route, int socket);