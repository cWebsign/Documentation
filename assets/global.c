#include <stdio.h>

#include <Net/web.h>
#include "../main.h"

/* 
*
*
*   [ GLOBAL HTML CONTROLS ]
*
*/
Control header = (Control){ .Tag = HEAD_TAG, .SubControls = (void *[]){
	&(Control){ .Tag = TITLE_TAG, .Text = "cLib+ | Websign Framework\0", },
	NULL
}};

Control NAV_BAR = (Control){ .Tag = DIV_TAG, .Class = "nav_bar_box", .SubControls = (void *[]){
	&(Control){ .Tag = H1_TAG, .Class = "TITLE_CSS", .Text = "cLib+" },
	&(Control){ .Tag = A_TAG, .href = "/", .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
				&(Control){ .Tag = P_TAG, .Text = "Home" },
				NULL
		}},
		NULL
	}},
	&(Control){ .Tag = A_TAG, .href = "/install", .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
				&(Control){ .Tag = P_TAG, .Text = "Installation" },
				NULL
		}},
		NULL
	}},
	&(Control){ .Tag = A_TAG, .href = "/doc", .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
				&(Control){ .Tag = P_TAG, .Text = "Doc" },
				NULL
		}},
		NULL
	}},
	&(Control){ .Tag = A_TAG, .href = "/faq", .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
				&(Control){ .Tag = P_TAG, .Text = "FAQ" },
				NULL
		}},
		NULL
	}},
	&(Control){ .Tag = A_TAG, .href = "https://github.com/clibplus/Net", .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .Class = "NAV_BTN_BOX", .SubControls = (void *[]){
				&(Control){ .Tag = P_TAG, .Text = "Source Code" },
				NULL
		}},
		NULL
	}},
	NULL
}};


/*
*
*
* [ GLOABAL CSS ]
*
*/

CSS NAV_BAR_CSS = (CSS){ .Class = "NAV_BAR_BOX", .Selector = 1, .Data = (char *[]){
	"margin: auto",
	"float: flex",
	"background-color: #000",
	"color: #fff",
	"width: 800px",
	"border: 2px solid white",
	"border-radius: 15px",
	NULL
}};

// Non-Selector ( body {} )
CSS BODY_CSS = (CSS){ .Class = "body", .Data = (char *[]){
    "position: relative",
	"background-color: #000", 
	"color: #fff", 
	NULL 
}};

CSS BODY_BOX = (CSS){ .Class = "BODY_BOX", .Selector = 1, .Data = (char *[]){
    "margin-top: 55px",
    "position: absolute",
    "top: 50%",
    "left: 50%",
    "transform: translate(-50%, -50%)",
    "width: 90%",
    "padding-bottom: 10px",
    "border: 2px solid white",
    "border-radius: 10px",
	NULL
}};

CSS CODE_DISPLAY_CSS = (CSS){ .Class = "code_display", .Selector = 1, .Data = (char *[]) {
    "width: 95%",
    "padding: 2px",
    "background-color: #171717",
    "color: #fff",
    "border: 2px solid white",
    "margin-left: 2%",
    "transition: 2.5px",
    NULL
}};

CSS CODE_DISPLAY_HOVER_CSS = (CSS){ .Class = "code_display:hover", .Selector = 1, .Data = (char *[]){
    "border-color: #ff0000",
    NULL
}};

CSS PAGE_TITLE_DISPLAY = (CSS){ .Class = "page_title_display", .Selector = 1, .Data = (char *[]) {
    "margin-top: 25px",
    "margin-left: 2%",
    NULL
}};