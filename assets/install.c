#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

CSS *InstallationCSS[] = {
	&BODY_CSS,
	&NAV_BAR,
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
    &CODE_DISPLAY_CSS,
    &CODE_DISPLAY_HOVER_CSS,
    &PAGE_TITLE_DISPLAY,
    &(CSS){ .Class = "__text", .Selector = 1, .Data = (char *[]){
            "font-size: 17px",
            NULL
        }
    },
    NULL
};

Control coming_soon = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &(Control){ .Tag = H1_TAG, .Class = "page_title_display", .Text = "Installation" },
        &(Control){ .Tag = P_TAG, .Class = "page_title_display __text", .Text = "Install Websign's dependencies with a few commands listed below! (Developed and Tested On Ubuntu 20.04)" },
        &(Control){ .Tag = DIV_TAG, .Class = "code_display", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px", NULL}, .Text = "sudo apt update -y && apt upgrade -y<br />sudo install build-essential libssl-dev gcc make git -y<br />git clone https://github.com/clibplus/clibplus.git<br />cd clibplus<br />make<br />cd ..<br />rm -r clibplus<br />pm -i str<br />pm -i arr<br />pm -i map<br />pm -i Net<br />mv /usr/local/lib/Net/* /usr/local/lib/<br />rm -rf /usr/local/lib/Net<br />cd ~/" },
            NULL
        }},
        &(Control){ .Tag = P_TAG, .Class = "page_title_display __text", .Text = "Now lets install Websign!" },
        &(Control){ .Tag = DIV_TAG, .Class = "code_display", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px", NULL}, .Text = "<br />git clone https://github.com/clibplus/Net.git<br />cd Net<br />gcc -c web.c web_config.c designer.c -lstr -larr -lmap -lpthread -g -g1<br />ar rcs websign.a *.o; rm *.o; mv websign.a /usr/local/lib/libwebsign.a<br />cd ..<br />rm -r Net<br />" },
            NULL
        }},
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