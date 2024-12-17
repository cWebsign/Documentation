#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <str.h>
#include <Net/web.h>

#include "main.h"

String IP;

void err_n_exit(const char *msg) { printf("%s\n", msg); exit(0); }

void DesignTest(cWS *web, cWR *request, WebRoute *route, int socket) {
	printf("Constructing HTML....\n");
	
	Control TEST_FORM = (Control){ .Tag = DIV_TAG, .SubControls = (void *[]){
		&(Control){ .Tag = FORM_TAG, .ID = "test_form", .SubControls = (void *[]){
			&(Control){ .Tag = INPUT_TAG, .Type = "text", .Data = "name=\"username\" value=\"Test\"", .SubControls = NULL },
			NULL
		}},
		NULL
	}};

	Control Header = (Control){ .Tag = HEAD_TAG, .SubControls = (void *[]){
		&TEST_FORM,
		NULL
	}};

	Button SUBMIT = (Button){ .Tag = BUTTON_TAG, .OnClick = 1, .FormID = ((Control *)TEST_FORM.SubControls[0])->ID, .Text = "Submit"};

    int chk = ConstructTemplate(route, (Control *[]){(Control *)&Header, (Control *)&SUBMIT, NULL}, NULL);
	if(chk < 1)
		printf("[ x ] Error\n");
}

void TestHandler(cWS *web, cWR *r, WebRoute *route, int socket) {
	Map new_headers = NewMap();
    new_headers.Append(&new_headers, "Content-Type", "text/html; charset=UTF-8");
    new_headers.Append(&new_headers, "Connection", "close");

	if(r->RequestType.Is(&r->RequestType, "POST")) {
		if(route->Template)
			free(route->Template);

		int sz = strlen("{\"TEST\":\"YAY\"}") + 1;
		route->Template = (char *)malloc(sz);
		memset(route->Template, '\0', sz);
		strcpy(route->Template, "{\"TEST\":\"YAY\"}");

		printf("HERE %s %ld\n", r->Body.data, r->Headers.idx);
	}

	for(int i = 0; i < r->Headers.idx; i++) {
		printf("%s = > %s\n", (char *)((Key *)r->Headers.arr[i])->key, (char *)((Key *)r->Headers.arr[i])->value);
	}

	SendResponse(web, socket, OK, new_headers, ((Map){}), route->Template);
}

int main() {
	IP = NewString("");
	cWS *api = StartWebServer(IP, 80, 0);
	if(!api)
		err_n_exit("[ x ] Error, Unable to start web server....!\n");

	api->CFG.Err404 = "Err404\n\n";
	AddRoutes(api, (WebRoute *[]){
		&(WebRoute){
			.Name 		= "index",
			.Path 		= "/",
			.Handler 	= IndexHandler,
			.Generator 	= LayoutInit
		},
		&(WebRoute){
			.Name 		= "documentation",
			.Path 		= "/doc",
			.Handler 	= DocHandler,
			.Generator 	= DesignDoc
		},
		&(WebRoute){
			.Name 		= "installation",
			.Path 		= "/install",
			.Handler	= InstallHandler,
			.Generator 	= DesignInstallation
		},
		&(WebRoute){
			.Name 		= "String Doc",
			.Path 		= "/doc/string",
			.Handler	= StringDocHandler,
			.Generator	= DesignStringDoc
		},
		&(WebRoute){
			.Name 		= "Test Page",
			.Path 		= "/test",
			.Handler	= TestHandler,
			.Generator 	= DesignTest

		},
		NULL
	});
	AddDynamicHandler(api);

	printf("Loaded %ld Routes...!\n", api->CFG.RouteCount);
	api->Run(api, 999, NULL);

	char *BUFFER[1024] = {0};
	fgets((char *)&BUFFER, 1024, stdin);

	api->Destruct(api);
	return 0;
}
