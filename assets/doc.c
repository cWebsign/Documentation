#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../main.h"

CSS **DocCSS = NULL;

void DesignDoc(cWS *web, cWR *r, WebRoute *route, int socket) {
    CSS *DocCSS[] = {
		&(CSS){ .Class = "body", .Data = (char *[]){
				"background-color: #000", 
				"color: #fff", 
				NULL 
			}
		},
		&(CSS){ .Class = "nav_bar_box", .Selector = 1, .Data = (char *[]){
				"margin: auto",
				"float: flex",
				"background-color: #000",
				"color: #fff",
				"width: 700px",
				"border: 2px solid white",
				"border-radius: 15px",
				NULL
			}
		},
		&(CSS){ .Class = "DOC_CSS", .Selector = 1, .Data = (char *[]){
				"margin-top: 55px",
                "position: absolute",
                "top: 50%",
                "left: 50%",
                "transform: translate(-50%, -50%)",
                "width: 90%", 
                "height: 85%", 
                "border: 2px solid white", 
                "border-radius: 10px",
				NULL
			}
		},
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
		NULL
	};

	/* Construct the body */
	Control coming_soon = (Control){ .Tag = BODY_TAG, .Class = "BODY_CSS", .SubControls = (void *[]){
			&(Control){ .Tag = DIV_TAG, .Class = "nav_bar_box", .SubControls = (void *[]){
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
				NULL
			}},
			&(Control){ .Tag = DIV_TAG, .Class = "DOC_CSS", .SubControls = (void *[]){
                &(Control){ .Tag = DIV_TAG, .Class = "SIDE_BAR_CSS", .SubControls = (void *[]){
                    &(Control){ .Tag = H1_TAG, .Class = "DOC_TITLE", .Text = "Documentation" },
                    &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
                        &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
                            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Introduction" },
                            NULL,
                        }},
                        NULL
                    }},
                    &(Control){ .Tag = DIV_TAG, .Class = "DOC_OPT", .SubControls = (void *[]){
                        &(Control){ .Tag = A_TAG, .href="https://discord.gg/vuln", .CSS = (char *[]){"text-decoration: none;", "color: inherit;", NULL}, .SubControls = (void *[]){
                            &(Control){ .Tag = P_TAG, .CSS = (char *[]){"margin-left: 10px;", NULL}, .Text = "Getting started" },
                            NULL,
                        }},
                        NULL
                    }},
                    NULL
                }},
                NULL
            }},
			NULL,
	}};

	Control header = ConstructHeader();
	route->CSS = DocCSS;
	route->Controls = (Control *[]){&header, &coming_soon, NULL};

    int chk = ConstructTemplate(route);
	if(chk < 1)
		printf("[ x ] Error\n");
}