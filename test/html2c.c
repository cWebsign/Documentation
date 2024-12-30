#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <OS/file.h>
#include <Net/web.h>

int main() {
	File html_file = Openfile("t.txt", FILE_READ);
	html_file.Read(&html_file);

	Control **Controls = ParseHTMLContent(html_file.data);
	html_file.Destruct(&html_file);

	int i = 0;
	while(Controls[i] != NULL) {
		char *Tag = FindTag(Controls[i]);
		if(!Tag)
			printf("ERROR\n");

		printf("Tag: %s\n", Tag);


		free(Controls[i]->ID);
		free(Controls[i]->Type);
		free(Controls[i]->Text);
		free(Controls[i]->Class);
		free(Controls[i]->href);
		free(Controls[i]->Data);
		free(Controls[i]->OnClickJS);
		free(Controls[i]);
		i++;
	}

	return 0;
}
