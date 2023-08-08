#include <iostream>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    std::string *output = (std::string *)userp;
    output->append((char *)contents, total_size);
    
    return total_size;
}


int main() {
	using namespace std;
  
    // curl_global_init must be called at the begining of the program. This may allocate resources like mem, load config etc to
    // initialize libcurl library. it takes parameter flags to initialize SSL, WIN32(for windows) modes to operate connection btw client and server. 
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // curl_easy_init initializes callbacks, datastructures to perform transfer. this is used as callback to handle connection establishing with the server.
    CURL *curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error initializing libcurl." << std::endl;
        return 1;
    }

    // Set the URL to the HTTPS endpoint
    const char *url = "https://dog-api.kinduff.com/api/facts";
    
    /* curl_easy_setopt describes the behavior/funtionality based on 2nd parameter 
      passed to it in the form of CURLOPT_OPTIONS.CURLOPT_OPTIONS varies btw behavior descriptions,callbacks to operate reading/writing data to/from connection,err options in case of unexpected behavior,  network options like allowed protocols, allowed ports, proxies to use, protocol oriented params, security,handling timeouts,connection closing etc..set as operations to the passed CURLhandle to handle connection/data transfer.
       CURLOPT_WRITEFUNCTION is passed to specify libcurl how they need to process received data from server/peer with callback.
       CURLOPT_WRITEDATA is used to specify what reference is passed to write/read callback to write/read contents from/to connection.
    */
     if(curl)
    {
	std::string response_data;
    	curl_easy_setopt(curl, CURLOPT_URL, url);   
    	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);


	//curl_easy_perform performs transfer and fetching data from connection based on the operations set on curl handle.
    	CURLcode res = curl_easy_perform(curl);
    	if (res != CURLE_OK) {
        	std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
    	} 
	else {
        	// trimming the response_data string to capture the exact fact
              int index = 0;  
	      cout<<"the expected fact is:: ";
	      while(response_data[index++] != '[');
	      while(response_data[index++] !='.')
	      {
	         cout<<response_data[index];
	      }
	      cout<<endl;
 	  }

    	// Cleanup
    	curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return 0;
}
