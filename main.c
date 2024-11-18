#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <web.h>
#include <str.h>

String IP;

void err_n_exit(const char *msg) { printf("%s\n", msg); exit(0); }

/* Function to design the index page, Separate files and//or functions can be used for this */
void *DesignIndex(cWS *web, cWR *request, int socket) {
	/* Setting a header */

	/* Define Controls */
	Control header = (Control){ .Tag = HEAD_TAG };
	Control title = (Control){ .Tag = TITLE_TAG, .Text = "cLib+ Web Server | cWD Framework\0" };

	/* Create a Control *[] array starting with the */
	Control *header_controls[] = {&header, &title, NULL};
	String header_html = ConstructDesign(header_controls);

	Control body = (Control){ .Tag = BODY_TAG, .CSS = (char **)BODY_CSS};

	Control text1 = (Control){ .Tag = P_TAG, .Text = "Test\0", .Data = "id=\"no\" name=\"no\"\0"};
	Control text2 = (Control){ .Tag = P_TAG, .Text = "Test\0", .Data = "id=\"no1\" name=\"no1\"\0"};
	Control text3 = (Control){ .Tag = P_TAG, .Text = "Test\0", .Data = "id=\"no2\" name=\"no2\"\0"};

	Control *body_design[] = { 
		&body, 
		&text1,
		&text2,
		&text3,
		NULL
	};

	String resp = ConstructDesign(body_design);

	printf("<html>%s%s</html>\n", header_html.data, resp.data);
}

void *IndexHandler(cWS *web, cWR *request, int socket) {
	String resp = NewString("<html><head><title>MyPage</title></head><body>cLib+ WebServer By Algo1337</body></html>\r\n");
	
	char num[100];
	sprintf(num, "%ld", resp.idx);

	Map new_headers = NewMap();
    new_headers.Append(&new_headers, "Content-Type", "text/html; charset=UTF-8");
	new_headers.Append(&new_headers, "Content-Length", (const char *)&num);
    new_headers.Append(&new_headers, "Connection", "close");

	SendResponse(web, socket, OK, ((Map){}), ((Map){}), resp.data);
	resp.Destruct(&resp);
}

int main() {
	IP = NewString("");
	cWS *api = StartWebServer(IP, 80, 0);
	api->CFG.Err404 = "Dick n Balls";
	AddRoute(api, (WebRoute){
		.Name 		= "index",
		.Path 		= "/",
		.Handler 	= IndexHandler,
		.Generator 	= DesignIndex,
	});
	if(!api)
		err_n_exit("[ x ] Error, Unable to start web server....!\n");

	printf("Loaded %ld Routes...!\n", api->CFG.RouteCount);
	api->Run(api, 999, NULL);

	char *BUFFER[1024];
	fgets((char *)&BUFFER, 1024, stdin);

	api->Destruct(api);
	return 0;
}
