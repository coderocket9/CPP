1.CPP HTP CLIENT IMPLEMENTATION TO FETCH DOG FACTS from a public API.
2.Make a C++ program that when run; gets 1 dog fact from the Kinduff dog-api and prints it to screen.
3.API docs: https://kinduff.github.io/dog-api/
4.Http library in the project: licurl ref(https://curl.se/libcurl/).
5.Ubuntu cmd:
  sudo apt-get install libcurl4-openssl-dev.
6.This Project begins with initializing resources, libraries and CUrlhandle using libcurl commands. 
7.Binding operations w.rt the url,n/w protocol, connection type, connection/data handling etc on the handle.
8.This handle is passed to perform transfer. if succeded a callback that we specified to handle data incoming getsc executed and writes response to a response object. else an err is retured.
