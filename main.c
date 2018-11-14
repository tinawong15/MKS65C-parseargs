# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char ** parse_args( char * line ) {
  char * ptr = line;
  char ** array = calloc(1, sizeof(char **));
  int index = 0;
  while(ptr != NULL){
    line = strsep(&ptr, " ");
    array[index] = calloc(256, sizeof(char *));
    if (index == 0){
      array[index] = line;
      index++;
      array[index] = calloc(256, sizeof(char *));
      array[index] = ptr;
    }
    else{
      array[index] = ptr;
    }
    //increment
    index++;
  }
  return array;
}


int main(int argc, char const *argv[]) {
  char line [100] = "ls -l";
  char ** argument_array = parse_args( line );
  int i;
  // for (i = 0; i < 4; i++){
  //   printf("%s\n", argument_array[i]);
  // }
  execvp(argument_array[0], argument_array);
  return 0;
}
