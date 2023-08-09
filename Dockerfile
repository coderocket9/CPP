#use alphine linux as base image
FROM alpine

WORKDIR /cpp_app
COPY . /cpp_app
RUN apk add libcurl curl-dev
RUN apk add g++
RUN g++ -o client_obj_file client.cpp -lcurl
CMD ["/cpp_app/client_obj_file"] 




