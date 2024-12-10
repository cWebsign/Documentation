#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

char *BASIC_HELLO_WORLD = NULL;
char *GEN_HELLO_WORLD = NULL;

CSS *DocCSS[] = {
	&BODY_CSS,
	&NAV_BAR_CSS,
	&NAV_BTN_BOX_CSS,
	&BODY_BOX,
	&(CSS){ .Class = "SIDE_BAR_CSS", .Selector = 1, .Data = (char *[]){
			"position: absolute",
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
		}
	},
	&(CSS){ .Class = "DOC_TITLE", .Selector = 1, .Data = (char *[]){
            "margin-left: 10px",
            "text-decoration: none",
			NULL
		}
	},
	&(CSS){ .Class = "DOC_OPT", .Selector = 1, .Data = (char *[]){
            "background-color: #191919",
            "height: 30px",
            "width: 100%",
            "margin-top: 10px",
            "display: flex", 
            "align-items: center",
            "text-decoration: none",
            "transition: 1s",
			NULL
		}
	},
    &(CSS){ .Class = "DOC_OPT:hover", .Selector = 1, .Data = (char *[]){ "background-color: #fff", "color: #191919", NULL }},
    &TITLE_CSS,
    &DOC_CODE_CSS,
    &DOC_CODE_HOVER_CSS,
    &DOC__TEXT_CSS,
    &CODE__TEXT_CSS,
    &CODE_DISPLAY_CSS,
    &CODE_DISPLAY_HOVER_CSS,
    &PAGE_TITLE_DISPLAY,
	NULL
};

Control SIDEBAR_CSS = (Control){ .Tag = DIV_TAG, .Class = "SIDE_BAR_CSS", .SubControls = (void *[]){
    &(Control){ .Tag = H1_TAG, .Class = "DOC_TITLE", .Text = "Documentation" },
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px; color: #afafaf", NULL}, .Text = "Introduction" },
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
    &(Control){ .Tag = A_TAG, .href="#", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
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

/* Construct the body */
Control DOC_BODY = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &SIDEBAR_CSS,
        &(Control){ .Tag = P_TAG, .Class = "doc__txt", .Text = "Getting started with a Hello World!" },
        &(Control){ .Tag = DIV_TAG,.Class = "doc_code_display", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 3px;", NULL} },
            NULL
        }},
        &(Control){ .Tag = P_TAG, .Class = "doc__txt", .Text = "Using a template generation function for the Hello World" },
        &(Control){ .Tag = PRE_TAG,.Class = "doc_code_display", .SubControls = (void *[]){
            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 3px;", NULL} },
            NULL
        }},
        NULL
    }},
	NULL,
}};

void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket) {
    File basic_file = Openfile("assets/examples/basic_hello_world.txt", FILE_READ_WRITE);
    if(!basic_file.fd)
        printf("ERROR\n");

    fseek(basic_file.fd, 0L, SEEK_END);
    int sz = ftell(basic_file.fd);
    fseek(basic_file.fd, 0L, SEEK_SET);

    if(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[2])->SubControls[0])->Text)
        free(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[2])->SubControls[0])->Text);

    ((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[2])->SubControls[0])->Text = (char *)malloc(4096);
    memset(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[2])->SubControls[0])->Text, '\0', 4096);
    fread(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[2])->SubControls[0])->Text, sz, 1, basic_file.fd);

    File gen_file = Openfile("assets/examples/hello_world.txt", FILE_READ_WRITE);
    if(!gen_file.fd)
        printf("ERROR\n");

        
    fseek(gen_file.fd, 0L, SEEK_END);
    sz = ftell(gen_file.fd);
    fseek(gen_file.fd, 0L, SEEK_SET);

    if(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[4])->SubControls[0])->Text)
        free(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[4])->SubControls[0])->Text);

    ((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[4])->SubControls[0])->Text = (char *)malloc(4096);
    memset(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[4])->SubControls[0])->Text, '\0', 4096);
    fread(((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[4])->SubControls[0])->Text, sz, 1, gen_file.fd);

	route->CSS = DocCSS;
	route->Controls = (Control *[]){&header, &DOC_BODY, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");

    basic_file.Destruct(&basic_file); 
    gen_file.Destruct(&gen_file);    
}