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

Control SIDEBAR_CSS = (Control){ .Tag = DIV_TAG, .Class = "SIDE_BAR_CSS", .SubControls = (void *[]){
    &(Control){ .Tag = A_TAG, .href="/doc", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = H1_TAG, .Class = "DOC_TITLE", .Text = "Documentation" },
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="/doc", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Introduction" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Getting started" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = H3_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Extended Standard Lib" },
    &(Control){ .Tag = A_TAG, .href="/doc/string", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "String" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Array" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Map" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "GC" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Thread" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "OS" },
            NULL,
        }},
        NULL
    }},
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Net" },
            NULL,
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
    "position: relative",
    "z-index: 2",
	NULL
}};

CSS NAV_BTN_BOX_CSS = (CSS){ .Class = "NAV_BTN_BOX", .Selector = 1, .Data = (char *[]){
	"color: #fff",
	"margin-right: 5px",
    "border: 2px solid white",
	"border-radius: 15px",
	"text-align: center",
	"width: 100px",
	"display: inline-block",
	NULL
}};

// Non-Selector ( body {} )
CSS BODY_CSS = (CSS){ .Class = "body", .Data = (char *[]){
	"background-color: #000", 
	"color: #fff", 
	NULL 
}};

CSS BODY_BOX = (CSS){ .Class = "BODY_BOX", .Selector = 1, .Data = (char *[]){
    "position: relative",
    "top: 50%",
    "left: 50%",
    "transform: translate(-50%, -50%)",
    "width: 90%",
    "height: 75%",
    "padding-bottom: 10px",
    "border: 2px solid white",
    "border-radius: 10px",
    "overflow-y: scroll",      
    "overflow-x: hidden",      
    "scrollbar-width: none",   
    "-ms-overflow-style: none",
	NULL
}};


CSS TITLE_CSS = (CSS){ .Class = "TITLE_CSS", .Selector = 1, .Data = (char *[]){
	"margin-left: 15px", 
	"margin-right: 10px",
	"background-color: #000", 
	"color: #fff", 
	"display: inline-block",
	"vertical-align: middle",
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

CSS DOC_CODE_CSS = (CSS){ .Class = "doc_code_display", .Selector = 1, .Data = (char *[]) {
	"box-sizing: border-box",
    "margin-left: 12px",
    "margin-right: 30px",
    "padding: 2px",
    "background-color: #171717",
    "color: #fff",
    "border: 1px solid white",
	"border-radius: 5px",
    "transition: 2s",
    "max-height: 200px",
    "overflow-y: auto",
    "white-space: pre-wrap",
    "word-wrap: break-word",
    NULL
}};

CSS DOC_CODE_HOVER_CSS = (CSS){ .Class = "doc_code_display:hover", .Selector = 1, .Data = (char *[]){
    "border-color: #ff0000",
    NULL
}};

CSS PAGE_TITLE_DISPLAY = (CSS){ .Class = "page_title_display", .Selector = 1, .Data = (char *[]) {
    "margin-top: 25px",
    "margin-left: 2%",
    NULL
}};

CSS DOC__TEXT_CSS = (CSS){ .Class = "doc__txt", .Selector = 1, .Data = (char *[]){"margin-top: 25px;", "margin-left: 22px", NULL}};
CSS CODE__TEXT_CSS = (CSS){ .Class = "code__text", .Selector = 1, .Data = (char *[]){
    "margin-left: 2px",
    NULL
}};

CSS SIDE_BAR_CSS = (CSS){ .Class = "SIDE_BAR_CSS", .Selector = 1, .Data = (char *[]){
	"position: fixed",
	"z-index: 1000",
    "top: 0",
    "left: 0",
    "border: none",
    "border-right: 2px solid white",
    "border-top-right-radius: 5px",
    "border-bottom-right-radius: 5px",
    "width: 230px",
    "height: 100%",
    "display: inline-block",
	NULL
}};

CSS DOC_BODY_CSS = (CSS){ .Class = "doc_body", .Selector = 1, .Data = (char *[]){
	"height: 100%",
	"width: 85%",
	
	"margin-left: 230px",
	NULL
}};

CSS DOC_TITLE_CSS = (CSS){ .Class = "DOC_TITLE", .Selector = 1, .Data = (char *[]){
    "margin-left: 10px",
    "text-decoration: none",
	NULL
}};

CSS DOC_OPT_CSS = (CSS){ .Class = "DOC_OPT", .Selector = 1, .Data = (char *[]){
    "background-color: #191919",
    "height: 30px",
    "width: 100%",
    "margin-top: 10px",
    "display: flex", 
    "align-items: center",
    "text-decoration: none",
    "transition: 1s",
	NULL
}};

CSS DOC_OPT_HOVER_CSS = (CSS){ .Class = "DOC_OPT:hover", .Selector = 1, .Data = (char *[]){ "background-color: #fff", "color: #191919", NULL }};

CSS *DocCSS[] = {
	&BODY_CSS,
	&NAV_BAR_CSS,
	&NAV_BTN_BOX_CSS,
	&BODY_BOX,
	&SIDE_BAR_CSS,
	&DOC_TITLE_CSS,
    &DOC_OPT_CSS,
    &DOC_OPT_HOVER_CSS,
    &TITLE_CSS,
    &DOC_CODE_CSS,
    &DOC_CODE_HOVER_CSS,
    &DOC__TEXT_CSS,
    &CODE__TEXT_CSS,
    &CODE_DISPLAY_CSS,
    &CODE_DISPLAY_HOVER_CSS,
    &PAGE_TITLE_DISPLAY,
	&DOC_BODY_CSS,
	NULL
};