#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

CSS *InstallationCSS[] = {
	&BODY_CSS,
	&NAV_BAR_CSS,
	&BODY_BOX,
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
    &(CSS){ .Class = "code_display", .Selector = 1, .Data = (char *[]) {
            "margin-left: 22px",
            "padding: 5px",
            "margin-right: 30px",
            "background-color: #171717",
            "color: #fff",
            "border: 2px solid white",
            "transition: 2s",
            "max-height: 150px",
            "overflow-y: auto",
            "white-space: pre-wrap",
            "word-wrap: break-word",
            NULL
        }
    },
    &(CSS){ .Class = "code_display:hover", .Selector = 1, .Data = (char *[]){ "border-color: #ff0000", NULL }},
    &PAGE_TITLE_DISPLAY,
    &(CSS){ .Class = "__text", .Selector = 1, .Data = (char *[]){ "font-size: 17px", NULL }},
    NULL
};

Control coming_soon = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &(Control){ .Tag = H1_TAG, .Class = "page_title_display", .Text = "Installation" },
        
        &(Control){ .Tag = P_TAG, .Class = "page_title_display __text", .Text = "You can use cLib+'s Package Manager to install cLib+ Libraries with the following commands!" },
        &(Control){ .Tag = DIV_TAG, .Class = "code_display", .Text = "sudo apt update -y && apt upgrade -y<br />sudo install build-essential libssl-dev gcc make git -y<br />git clone https://github.com/clibplus/clibplus.git<br />cd clibplus<br />make<br />cd ..<br />rm -r clibplus<br />pm --h" },
        &(Control){ .Tag = P_TAG, .Class = "page_title_display __text", .Text = "Install Websign's dependencies with a few commands listed below! (Developed and Tested On Ubuntu 20.04)" },
        &(Control){ .Tag = DIV_TAG, .Class = "code_display", .Text = "sudo apt update -y && apt upgrade -y<br />sudo install build-essential libssl-dev gcc make git -y<br />git clone https://github.com/clibplus/clibplus.git<br />cd clibplus<br />make<br />cd ..<br />rm -r clibplus<br />pm -i str<br />pm -i arr<br />pm -i map<br />pm -i Net<br />mv /usr/local/lib/Net/* /usr/local/lib/<br />rm -rf /usr/local/lib/Net<br />cd ~/" },
        &(Control){ .Tag = P_TAG, .Class = "page_title_display __text", .Text = "Now lets install Websign!" },
        &(Control){ .Tag = DIV_TAG, .Class = "code_display", .Text = "<br />git clone https://github.com/clibplus/Net.git<br />cd Net<br />gcc -c web.c web_config.c designer.c -lstr -larr -lmap -lpthread -g -g1<br />ar rcs websign.a *.o; rm *.o; mv websign.a /usr/local/lib/libwebsign.a<br />cd ..<br />rm -r Net<br />" },
        NULL
    }},
	NULL,
}};
void DesignInstallation(cWS *web, cWR *request, WebRoute *route, int socket) {
	route->CSS = InstallationCSS;
	route->Controls = (Control *[]){&header, &coming_soon, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");
}