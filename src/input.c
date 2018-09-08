#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../include/stream.h"

#define READ_BUF_SIZE 64

ssize_t readall(int fd, void * data, size_t count) {
  ssize_t bytesRead;
  char * dataPtr;
  size_t total;

  dataPtr = data;
  total = 0;

  while (count) {
    bytesRead = read(fd, dataPtr, count);

    dataPtr += bytesRead;
    count -= bytesRead;
    total += bytesRead;
  }

  return total;
}

int     read_int(char delim){
  int       res;
  char      char_buf[1];
  char      str[2] = "\0";
  stream_t  *int_stream;

  int_stream = stream_init();

  read(0, char_buf, 1);
  while(char_buf[0] != delim){
    str[0] = char_buf[0];
    stream_append(int_stream, str);
    read(0, char_buf, 1);
  }

  res = atoi(int_stream->str);
  stream_destroy(int_stream);
  return res;
}

char**    read_map(int h, int w){
  char   char_buf[1];
  char   **map;
  
  map = (char**) malloc(h * sizeof(char*));
  
  for(int i = 0; i < h; i++){
    map[i] = (char*) malloc(w * sizeof(char));
    readall(0, map[i], w); // read horisontal line
    read(0, char_buf, 1); // read \n
  }
  return map;
}

char     read_symbol(){
  char res;

  char   char_buf[1];
  read(0, char_buf, 1); //read my symbol
  res = char_buf[0];
  read(0, char_buf, 1); //read \n

  return res;
}


void     read_inp(filler_t *filler, info_t *info){
  char symbol;
  int w;
  int h;
  int fig_w;
  int fig_h;
  char** board;
  char** figure;

  symbol = read_symbol();
  filler->symbol = symbol;

  h = read_int(' ');
  filler->h = h;

  w = read_int('\n');
  filler->w = w;

  board = read_map(h, w);
  filler->board = board;

  fig_h = read_int(' ');
  info->fig_h = fig_h;

  fig_w = read_int('\n');
  info->fig_w = fig_w;

  figure = read_map(fig_h, fig_w);
  info->figure = figure;
}
