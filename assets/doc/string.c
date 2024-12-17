#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../main.h"

/* Construct the body */
Control STRING_DOC_BODY = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &SIDE_BAR,
        NULL
    }},
	NULL,
}};

void DesignStringDoc(cWS *web, cWR *request, WebRoute *route, int socket) {
    int chk = ConstructTemplate(route, (Control *[]){&header, &STRING_DOC_BODY, NULL}, DocCSS);
	if(chk < 1)
		printf("[ x ] Error\n");
}