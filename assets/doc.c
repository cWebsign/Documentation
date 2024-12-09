#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

char *BASIC_HELLO_WORLD = NULL;
char *GEN_HELLO_WORLD = NULL;

CSS *DocCSS[] = {
	&BODY_CSS,
	&NAV_BAR,
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
    &(CSS){ .Class = "doc_code_display", .Selector = 1, .Data = (char *[]) {
            "margin-left: 260px",
            "margin-right: 30px",
            "padding: 2px",
            "background-color: #171717",
            "color: #fff",
            "border: 2px solid white",
            "transition: 2.5s",
            "max-height: 200px",
            "overflow-y: auto",
            "white-space: pre-wrap",
            "word-wrap: break-word",
            NULL
        }
    },
    &(CSS){ .Class = "doc_code_display:hover", .Selector = 1, .Data = (char *[]){
            "border-color: #ff0000",
            NULL
        }
    },
    &(CSS){ .Class = "doc__txt", .Selector = 1, .Data = (char *[]){"margin-top: 25px;", "margin-left: 260px", NULL}},
    &(CSS){ .Class = "code__text", .Selector = 1, .Data = (char *[]){
            "margin-left: 2px",
            NULL
        }
    },
    &CODE_DISPLAY_CSS,
    &CODE_DISPLAY_HOVER_CSS,
    &PAGE_TITLE_DISPLAY,
	NULL
};

/* Construct the body */
Control DOC_BODY = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &(Control){ .Tag = DIV_TAG, .Class = "SIDE_BAR_CSS", .SubControls = (void *[]){
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
            NULL
        }},
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