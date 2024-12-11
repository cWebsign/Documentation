#pragma once

#include <Net/web.h>

/* Global Controls for all routes */
extern Control header;
extern Control NAV_BAR;
extern Control SIDEBAR;

/* Global CSS for all routes */
extern CSS NAV_BAR_CSS;
extern CSS NAV_BTN_BOX_CSS;

// Non-Selector ( body {} )
extern CSS BODY_CSS;
extern CSS BODY_BOX;

extern CSS TITLE_CSS;

extern CSS SIDE_BAR_CSS;

extern CSS DOC_BODY_CSS;
extern CSS DOC_CODE_CSS;
extern CSS DOC_CODE_HOVER_CSS;

extern CSS DOC_TITLE_CSS;
extern CSS DOC_OPT_CSS;
extern CSS DOC_OPT_HOVER_CSS;

extern CSS CODE_DISPLAY_CSS;
extern CSS CODE_DISPLAY_HOVER_CSS;
extern CSS PAGE_TITLE_DISPLAY;

extern CSS DOC__TEXT_CSS;
extern CSS CODE__TEXT_CSS;

Control ConstructHeader();

/* [/] Handler && Designer */
void LayoutInit(cWS *web, cWR *request, WebRoute *route, int socket);
void IndexHandler(cWS *web, cWR *r, WebRoute *route, int socket);

/* [/doc] Handler && Designer */
extern CSS *DocCSS[];
void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket);
void DocHandler(cWS *web, cWR *r, WebRoute *route, int socket);

/* [/install] Handler && Designer */
void InstallHandler(cWS *web, cWR *r, WebRoute *route, int socket);
void DesignInstallation(cWS *web, cWR *request, WebRoute *route, int socket);

void DesignStringDoc(cWS *web, cWR *request, WebRoute *route, int socket);
void StringDocHandler(cWS *web, cWR *request, WebRoute *route, int socket);