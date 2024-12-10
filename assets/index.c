#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

#include <str.h>
#include <Net/web.h>

CSS *IndexCSS[] = {
	&BODY_CSS,
	&NAV_BAR_CSS,
	&NAV_BTN_BOX_CSS,
	&(CSS){ .Class = "COMING_SOON_CSS", .Selector = 1, .Data = (char *[]){
			"position: fixed",
			"top: 50%",
			"left: 50%",
			"transform: translate(-50%, -50%)",
			"width: 300px",
			NULL
		}
	},
	&(CSS){ .Class = "TITLE_CSS", .Selector = 1, .Data = (char *[]){
			"margin-left: 15px", 
			"margin-right: 10px",
			"background-color: #000", 
			"color: #fff", 
			"display: inline-block",
			"vertical-align: middle",
			NULL
		}
	},
	NULL
};

Control COMING_SOON = (Control){ .Tag = BODY_TAG, .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "COMING_SOON_CSS", .SubControls = (void *[]){
			&(Control){ .Tag = H1_TAG, .Text = "cLib+ C Extension", .CSS = (char *[]){"color: #fff;", "font-size: 25px", "margin-left: 50%", NULL} },
			&(Control){ .Tag = A_TAG, .href = "https://discord.gg/4wJbTaRTHB", .CSS = (char *[]){"text-decoration: none;", NULL}, .SubControls = (void *[]){
					&(Control){  .Tag = DIV_TAG, .Type = NULL, .SubControls = (void *[]){
							&(Control){ .Tag = P_TAG, .Type = NULL, .Text = "Join our discord for daily updates! Join Now", .CSS = (char *[]){"color: #fff;", "font-size: 15px", NULL} },
							NULL
					}},
					NULL
			}},
			NULL
	}},
	NULL
}};

void LayoutInit(cWS *web, cWR *request, WebRoute *route, int socket) {
	printf("Constructing HTML....\n");
	route->CSS = IndexCSS;
	route->Controls = (Control *[]){&header, &COMING_SOON, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");
}