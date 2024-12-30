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
	
	Control TEST_FORM = (Control){ .Tag = BODY_TAG, .SubControls = (void *[]){
		&(Control){ .Tag = DIV_TAG, .SubControls = (void *[]){
			&(Control){ .Tag = FORM_TAG, .ID = "test_form", .SubControls = (void *[]){
				&(Control){ .Tag = INPUT_TAG, .Type = "text", .Data = "name=\"username\" value=\"Test\"" },
				NULL
			}},
			&(Control){ .Tag = BUTTON_TAG, .OnClick = 1, .FormID = "test_form", .Text = "Submit"},
			NULL
		}},
		NULL
	}};

	Control Header = (Control){ .Tag = HEAD_TAG, .SubControls = (void *[]){
		&(Control){ .Tag = TITLE_TAG, .Text = "Test Endpoint", .SubControls = NULL },
		NULL
	}};

	Control *Controls[] = {
		&Header,
		&TEST_FORM,
		NULL
	};
	
    int chk = ConstructTemplate(route, Controls, NULL);
	if(chk < 1)
		printf("[ x ] Error\n");

	String header_list = DumpControls(&Header, 0);
	String form_list = DumpControls(&TEST_FORM, 0);
	printf("%s\n", header_list.data);
	printf("%s\n", form_list.data);

	header_list.Destruct(&header_list);
	form_list.Destruct(&form_list);
}

void TestHandler(cWS *web, cWR *r, WebRoute *route, int socket) {
	Map new_headers = NewMap();
    new_headers.Append(&new_headers, "Content-Type", "text/html; charset=UTF-8");
    new_headers.Append(&new_headers, "Connection", "close");

	printf("Req Info: Request Inbound Type: %s | Headers: %ld | Queries: %ld\r\n", r->RequestType.data, r->Queries.idx, r->Headers.idx);
	printf("Body: %s\r\n", r->Body.data);

	if(r->RequestType.Is(&r->RequestType, "POST")) {
		if(route->Template)
			free(route->Template);

		if(r->Body.StartsWith(&r->Body, "{") && r->Body.EndsWith(&r->Body, "}"))
			printf("Valid JSON\n");

		route->Template = strdup("{\"lol\":\"yay\"}\n");
	}

	// for(int i = 0; i < r->Headers.idx; i++) {
	// 	printf("%s = > %s\n", (char *)((Key *)r->Headers.arr[i])->key, (char *)((Key *)r->Headers.arr[i])->value);
	// }

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
	// AddDynamicHandler(api);
	
    File t = Openfile("test.txt", FILE_WRITE_READ);
	String control_list = DumpControls(&COMING_SOON, 0);
	
    t.Write(&t, control_list.data);
	t.Destruct(&t);
	control_list.Destruct(&control_list);

	printf("Loaded %ld Routes...!\n", api->CFG.RouteCount);
	api->Run(api, 999, NULL);

	char *BUFFER[1024] = {0};
	fgets((char *)&BUFFER, 1024, stdin);

	api->Destruct(api);
	return 0;
}
