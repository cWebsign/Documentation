#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

#include <str.h>
#include <Net/web.h>

CSS *IndexCSS[];

void LayoutInit(cWS *web, cWR *request, WebRoute *route, int socket) {
	printf("Constructing CSS....\n");
	CSS *IndexCSS[] = {
		&(CSS){ .Class = "body", .Data = (char *[]){
				"background-color: #000", 
				"color: #fff", 
				NULL 
			}
		},
		&(CSS){ .Class = "nav_bar_box", .Selector = 1, .Data = (char *[]){
				"margin: auto",
				"float: flex",
				"background-color: #000",
				"color: #fff",
				"width: 700px",
				"border: 2px solid white",
				"border-radius: 15px",
				NULL
			}
		},
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
		&(CSS){ .Class = "NAV_BTN_BOX", .Selector = 1, .Data = (char *[]){
				"color: #fff",
				"margin-right: 5px",
				"border: 2px solid white",
				"border-radius: 15px",
				"text-align: center",
				"width: 100px",
				"display: inline-block",
				NULL
			}
		},
		NULL
	};

	printf("Constructing HTML....\n");
	/* Define a parent html/tag (Useful for DIVs) and the subcontrols to be in it */
	Control header = (Control){ .Tag = HEAD_TAG, .SubControls = (void *[]){
			&(Control){ .Tag = TITLE_TAG, .Text = "cLib+ | Websign Framework\0", },
			NULL
	}};

	/* Construct the body */
	Control coming_soon = (Control){ .Tag = BODY_TAG, .SubControls = (void *[]){
			&(Control){ .Tag = DIV_TAG, .Class = "nav_bar_box", .SubControls = (void *[]){
				&(Control){ .Tag = H1_TAG, .Class = "TITLE_CSS", .Text = "cLib+" },
				&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
						&(Control){ .Tag = P_TAG, .Text = "Home" },
						NULL
				}},
				&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
						&(Control){ .Tag = P_TAG, .Text = "Installation" },
						NULL
				}},
				&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
						&(Control){ .Tag = P_TAG, .Text = "Doc" },
						NULL
				}},
				&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
						&(Control){ .Tag = P_TAG, .Text = "FAQ" },
						NULL
				}},
				NULL
			}},
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

	route->CSS = IndexCSS;
	route->Controls = (Control *[]){&header, &coming_soon, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");
}