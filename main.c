#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <str.h>
#include <Net/web.h>

#include "main.h"

String IP;

void err_n_exit(const char *msg) { printf("%s\n", msg); exit(0); }

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
			.Generator 	= LayoutInit,
			.Controls 	= (Control *[]){&header, &COMING_SOON, NULL},
			.ReadOnly 	= 0
		},
		&(WebRoute){
			.Name 		= "documentation",
			.Path 		= "/doc",
			.Handler 	= DocHandler,
			.Generator 	= DesignDoc,
			.ReadOnly 	= 0
		},
		&(WebRoute){
			.Name 		= "installation",
			.Path 		= "/install",
			.Handler	= InstallHandler,
			.Generator 	= DesignInstallation,
			.ReadOnly 	= 0
		},
		&(WebRoute){
			.Name 		= "String Doc",
			.Path 		= "/doc/string",
			.Handler	= StringDocHandler,
			.Generator	= DesignStringDoc,
			.ReadOnly 	= 0
		},
		NULL
	});

	printf("Loaded %ld Routes...!\n", api->CFG.RouteCount);
	api->Run(api, 999, NULL);

	char *BUFFER[1024] = {0};
	fgets((char *)&BUFFER, 1024, stdin);

	api->Destruct(api);
	return 0;
}
