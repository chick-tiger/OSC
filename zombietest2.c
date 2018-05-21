#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char * argv[]){
pid_t pid;
int i = 0;
puts("\nBefore the While Loop");
while( i++ < 100){
puts("\nBefore the Fork in the Loop:");
printf( "Loop ==> %d \n", i);
pid = fork();
puts("\nFork: This should print twice for every loop:");

if(pid < 0){
puts( "fork failed\n" );
return 1;
}
if(pid == 0) {
puts("\n\nChildren of the world unite");
printf("Am Yisrael Chai! pid =>%d \n", pid);
printf( "Loop in Child ==> %d \n", i);
puts("BYE!!");
exit( EXIT_SUCCESS );
}
if (pid > 0 ){
printf("In the Parent => I'm waiting %d\n", pid );
printf( "Loop in Parent ==> %d \n", i);
//wait(NULL);
puts("Done Waiting for Child");
}
}
return 0;
}
