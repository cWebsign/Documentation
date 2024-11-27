#pragma once

#include <Net/web.h>

extern const char *BODY_CSS[];
String Construct_Index_Header();
String Construct_Index_Navbar();

String DesignIndex(cWS *web, cWR *r, WebRoute *route, int socket);
void *IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket);

String DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket);
void DocHandler(cWS *web, cWR *r, WebRoute *route, int socket);