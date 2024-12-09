#pragma once

#include <Net/web.h>

/* Global Controls for all routes */
extern Control header;
extern Control NAV_BAR;

/* Global CSS for all routes */
extern CSS NAV_BAR;

// Non-Selector ( body {} )
extern CSS BODY_CSS;
extern CSS BODY_BOX;

extern CSS CODE_DISPLAY_CSS;
extern CSS CODE_DISPLAY_HOVER_CSS;
extern CSS PAGE_TITLE_DISPLAY;

Control ConstructHeader();

/* [/] Handler && Designer */
void LayoutInit(cWS *web, cWR *request, WebRoute *route, int socket);
void IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket);

/* [/doc] Handler && Designer */
void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket);
void DocHandler(cWS *web, cWR *r, WebRoute *route, int socket);

/* [/install] Handler && Designer */
void InstallHandler(cWS *web, cWR *r, WebRoute *route, int socket);
void DesignInstallation(cWS *web, cWR *request, WebRoute *route, int socket);