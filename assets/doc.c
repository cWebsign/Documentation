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

/* Construct the body */
Control DOC_BODY = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
	&NAV_BAR,
	&(Control){ .Tag = DIV_TAG, .Class = "BODY_BOX", .SubControls = (void *[]){
        &SIDE_BAR,
        &(Control){ .Tag = DIV_TAG, .Class = "doc_body", .SubControls = (void *[]){
            &(Control){ .Tag = H1_TAG, .CSS = (char *[]){"margin-left: 20px", NULL}, .Text = "Introduction" },
            &(Control){ .Tag = A_TAG, .CSS = (char *[]){"text-decoration: none", NULL}, .href="/install", .SubControls = (void *[]){
                &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 20px;", "color: #fff", NULL}, .Text = "For steps to install, check out Installation Page! (Click Here)" },
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

    if(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[3])->SubControls[0])->Text)
        free(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[3])->SubControls[0])->Text);

    ((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[3])->SubControls[0])->Text = (char *)malloc(4096);
    memset(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[3])->SubControls[0])->Text, '\0', 4096);
    fread(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[3])->SubControls[0])->Text, sz, 1, basic_file.fd);

    File gen_file = Openfile("assets/examples/hello_world.txt", FILE_READ_WRITE);
    if(!gen_file.fd)
        printf("ERROR\n");

        
    fseek(gen_file.fd, 0L, SEEK_END);
    sz = ftell(gen_file.fd);
    fseek(gen_file.fd, 0L, SEEK_SET);
    
    if(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[5])->SubControls[0])->Text)
        free(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[5])->SubControls[0])->Text);

    ((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[5])->SubControls[0])->Text = (char *)malloc(4096);
    memset(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[5])->SubControls[0])->Text, '\0', 4096);
    fread(((Control *)((Control *)((Control *)((Control *)DOC_BODY.SubControls[1])->SubControls[1])->SubControls[5])->SubControls[0])->Text, sz, 1, gen_file.fd);

	route->CSS = DocCSS;

    Control **Template = (Control **)malloc(sizeof(Control *) * 3);
    Template[0] = &header;
    Template[1] = &DOC_BODY;
    Template[2] = NULL;

	route->Controls = Template;

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");

    basic_file.Destruct(&basic_file); 
    gen_file.Destruct(&gen_file);

    free(Template[0]);
    free(Template[1]);
    free(Template);
}