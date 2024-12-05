#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

const char *DOC_CSS[] = {
    "margin-top: 55px",
    "position: absolute",
    "top: 50%",
    "left: 50%",
    "transform: translate(-50%, -50%)",
    "width: 90%", 
    "height: 85%", 
    "border: 2px solid white", 
    "border-radius: 10px",
    NULL
};

const char *SIDE_BAR_CSS[] = {
    "position: absolute",
    "top: 0",
    "left: 0",
    "border: none",
    "border-right: 2px solid white",
    "border-top-right-radius: 5px",
    "border-bottom-right-radius: 5px",
    "width: 230px",
    "height: 100%",
    NULL
};

const char *DOC_TITLE[] = {
    "margin-left: 10px",
    "text-decoration: none",
    NULL
};

const char *DOC_OPT[] = {
    "background-color: #191919",
    "height: 30px",
    "width: 100%",
    "margin-top: 10px",
    "display: flex", 
    "align-items: center",
    "text-decoration: none",
    NULL
};

void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket) {
    // Control header = LayoutInit();

	// /* Construct the body */
	// Control coming_soon = (Control){ .Tag = BODY_TAG, .CSS = (char **)BODY_CSS, .SubControls = (void *[]){
	// 		&(Control){ .Tag = DIV_TAG, .CSS = (char **)NAV_BOX, .SubControls = (void *[]){
	// 			&(Control){ .Tag = H1_TAG, .Text = "cLib+", .CSS = (char **)TITLE_CSS}, NULL
	// 		}},
	// 		&(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_CSS, .SubControls = (void *[]){
    //             &(Control){ .Tag = DIV_TAG, .CSS = (char **)SIDE_BAR_CSS, .SubControls = (void *[]){
    //                 &(Control){ .Tag = H1_TAG, .CSS = (char **)DOC_TITLE, .Text = "Documentation" },
    //                 &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
    //                     &(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_OPT, .SubControls = (void *[]){
    //                         &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Introduction" },
    //                         NULL,
    //                     }},
    //                     NULL
    //                 }},
    //                 &(Control){ .Tag = DIV_TAG, .CSS = (char **)DOC_OPT, .SubControls = (void *[]){
    //                     &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
    //                         &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Getting started" },
    //                         NULL,
    //                     }},
    //                     NULL
    //                 }},
    //                 NULL
    //             }},
    //             NULL
    //         }},
	// 		NULL,
	// }};

	// route->CSS = (char **)DOC_PAGE_STYLE;
	// route->Controls = (Control *[]){&header, &coming_soon, NULL};
    // int chk = ConstructTemplate(route);
	// if(chk < 1)
	// 	printf("[ x ] Error\n");
}