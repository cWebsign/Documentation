#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

#include <str.h>
#include <Net/web.h>

const char *BODY_CSS[] = {
	"background-color: #000;", "color: #fff;", NULL };

const char *NAV_BOX[] = {
	"margin: auto;",
	"float: flex;",
	"background-color: #000;",
	"color: #fff;",
	"width: 300px;",
	"border: 2px solid white;",
	"border-radius: 15px;",
	NULL
};

const char *COMING_SOON_CSS[] = {
	"position: fixed;",
	"top: 50%;",
	"left: 50%;",
	"transform: translate(-50%, -50%);",
	"width: 300px",
	NULL
};

const char *TITLE_CSS[] = {
	"margin-left: 5px;", "background-color: #000;", "color: #fff", NULL };

void *CSS_STYLE[][2] = {
	{(void *)"body", (void *)BODY_CSS},
	{(void *)"nav_bar_box", (void *)NAV_BOX},
	NULL
};

String Construct_Index_Header() {
	/* Define a parent html/tag (Useful for DIVs) and the subcontrols to be in it */
	Control header = (Control){ .Tag = HEAD_TAG, .SubControls = (void *[]){
			&(Control){ .Tag = TITLE_TAG, .Text = "cLib+ Web Server | cWD Framework\0", },
			NULL
	}};

	/* Construct the design for the output */
	return ConstructParent(&header, 0);
}

String Construct_Index_Navbar() {
	/* Construct a Nav bar */
	Control NAV_BAR = (Control){ .Tag = DIV_TAG, .CSS = (char **)NAV_BOX, .SubControls = (void *[]){
			&(Control){ .Tag = H1_TAG, .Text = "cLib+", .CSS = (char **)TITLE_CSS}, NULL
	}};

	return ConstructParent(&NAV_BAR, 0);
}

/* Function to design the index page, Separate files and//or functions can be used for this */
String DesignIndex(cWS *web, cWR *request, WebRoute *route, int socket) {
	String template = Construct_Index_Header();
	String nav_bar = Construct_Index_Navbar();

	/* Construct the body */
	Control coming_soon = (Control){ .Tag = BODY_TAG, .CSS = (char **)BODY_CSS, .SubControls = (void *[]){
			&(Control){ .Tag = DIV_TAG, .CSS = (char **)COMING_SOON_CSS, .SubControls = (void *[]){
					&(Control){ .Tag = H1_TAG, .Text = "cLib+ C Extension", .CSS = (char *[]){"color: #fff;", "font-size: 25px", "margin-left: 50%", NULL} },
					&(Control){ .Tag = A_TAG, .href = "https://discord.gg/4wJbTaRTHB", .SubControls = (void *[]){
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

	String resp = ConstructParent(&coming_soon, 0);
	
	if(nav_bar.idx > 0)
		template.AppendArray(&template, ((const char *[]){nav_bar.data, "\r\n", NULL}));
		
	if(resp.idx > 0)
		template.AppendArray(&template, ((const char *[]){resp.data, "\n\n", NULL}));

	/* Free data */
	resp.Destruct(&resp);
	nav_bar.Destruct(&nav_bar);

	/* Output to Web (Console for testing) */
	return template;
}