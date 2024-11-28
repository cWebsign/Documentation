#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

const char *DOC_CSS[] = {
    "margin-top: 55px;",
    "position: absolute;",
    "top: 50%;",
    "left: 50%;",
    "transform: translate(-50%, -50%);",
    "width: 90%;", 
    "height: 85%;", 
    "border: 2px solid white;", 
    "border-radius: 10px;",
    NULL
};

const char *SIDE_BAR_CSS[] = {
    "position: absolute;",
    "top: 0;",
    "left: 0;",
    "border: none;",
    "border-right: 2px solid white;",
    "border-top-right-radius: 5px;",
    "border-bottom-right-radius: 5px;",
    "width: 230px;",
    "height: 100%;", // Ensures full height
    NULL
};

const char *DOC_TITLE[] = {
    "margin-left: 10px;",
    "text-decoration: none;",
    NULL
};

const char *DOC_OPT[] = {
    "background-color: #191919;",
    "height: 30px;",
    "width: 100%;",
    "margin-top: 10px;",
    "display: flex;", 
    "align-items: center;",
    "text-decoration: none;",
    NULL
};

String DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket) {
    String template = Construct_Index_Header();
	String nav_bar = Construct_Index_Navbar();

	/* Construct the body */
	Control coming_soon = (Control){ .Tag = BODY_TAG, .CSS = (char **)BODY_CSS, .SubControls = (void *[]){
			&(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_CSS, .SubControls = (void *[]){
                &(Control){ .Tag = DIV_TAG, .CSS = (char **)SIDE_BAR_CSS, .SubControls = (void *[]){
                    &(Control){ .Tag = H1_TAG, .CSS = (char **)DOC_TITLE, .Text = "Documentation" },
                    &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
                        &(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_OPT, .SubControls = (void *[]){
                            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Introduction" },
                            NULL,
                        }},
                        NULL
                    }},
                    &(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_OPT, .SubControls = (void *[]){
                        &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
                            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Quick Start-up" },
                            NULL,
                        }},
                        NULL
                    }},
                    NULL
                }},
                NULL
            }},
			NULL,
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