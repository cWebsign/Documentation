#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../main.h"

/* Construct the body */
Control STRING_DOC_BODY = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &SIDEBAR,
        NULL
    }},
	NULL,
}};

void DesignStringDoc(cWS *web, cWR *request, WebRoute *route, int socket) {
    route->CSS = DocCSS;
	route->Controls = (Control *[]){&header, &STRING_DOC_BODY, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");
}