#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <str.h>
#include <Net/request.h>

int main() {
	String URL = NewString("google.com");

	Map headers = NewMap();
	headers.Append(&headers, "User-Agent", "cLib__NET");
	headers.Append(&headers, "Accept", "*/*");

	HTTPClientResponse r = RequestURL(URL, headers, __GET__);

	/* Find redirects */
	for(int i = 0; i < r.Headers.idx; i++) {
		if(!strcmp(((Key *)r.Headers.arr[i])->key, "Location")) {
			printf("Redirect Found: %s\n", ((Key *)r.Headers.arr[i])->value);

			String new_url = NewString(((Key *)r.Headers.arr[i])->value);
			new_url.TrimAt(&new_url, 0);
			HTTPClientResponse c = RequestURL(
				new_url,
				headers,
				__GET__
			);
			new_url.Destruct(&new_url);

			printf("Status Code: %d | Headers: %ld | Body: \r\n%s\r\n", c.StatusCode, c.Headers.idx, c.Body.data);
			return 0;
		}
	}

	printf("%d\n", (int)r.StatusCode);
	printf("%ld\n", r.Headers.idx);
	printf("%s\n", r.Body.data);
	return 0;
}
