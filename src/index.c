#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

#include <str.h>
#include <map.h>
#include <Net/web.h>

/* Handler test for Web Server */
void IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket) {
	Map new_headers = NewMap();
    new_headers.Append(&new_headers, "Content-Type", "text/html; charset=UTF-8");
    new_headers.Append(&new_headers, "Connection", "close");

	SendResponse(web, socket, OK, new_headers, ((Map){}), route->Template);
}