// preethi rajagopalan
void ifTypeCommand(char* Command, char* filename );//function declarations-passing the command(type/delete/copy/execute/exit)
void ifCopyCommand(char *Command,char* filename1 , char* filename2);//copying from one file to another
void ifExecutableCommand(char* Command, int args);
void ifError(char* Command);//any other command other than type/copy/execute/delete/exit shows error message
void ifExitCommand();
void ifDeleteCommand(char* Command, char* filename);
#include <stdio.h>
int main(int argc, char* argv[])
{
char **Command;
char str[52][52];
int i,n;
char **args;//pointer to pointer,2 dimensional character array
printf("\n Hello There! \n");
printf("\n Enter the number of arguments:");
scanf("%d",&n);
printf("\n Enter the command: \n");
for(i=0;i<n;i++)
scanf("%s",Command[i]);
if ( strcmp(Command[0], "delete") == 0) 
   { 
ifDeleteCommand(Command);
   } 
return 0;}
if ( (strcmp(Command, "exit") == 0 &&argc== 1 ) 
      ifExitCommand();
   } 
   else if ( strcmp(Command, "type") == 0 &&argc== 2 ) 
   { 
   ifTypeCommand(Command);
   } 
   else if ( strcmp(Command, "copy") == 0 &&argc== 3 ) 
   { 
scanf("%s",str[0]);
scanf("%s",str[1]);
scanf("%s",str[2]);      
ifCopyCommand(str[1], str[2]);
   } 
   else if ( strcmp(Command, "delete") == 0 &&argc== 2) 
   { 
ifDeleteCommand(Command);
   } 
   else if (argc== 5 ) 
 { 
scanf("%s",str);
scanf("%s",*args);
ifExecutableCommand(str,args);
   } 
   else 
{ 
ifError(Command);
}
return 0;
}
void ifTypeCommand(char Command[50], char filename[50])//type command reads the contents of a file and displays that on the screen.
{
FILE *f1;
char c;
f1 = fopen  ("a.c", "r"); 
while(f1)
{
c= fgetc(f1);
putc(c,f1);
}
void ifDeleteCommand(char** Command)//the given filename will be deleted if Command is "Delete"
{
remove(Command[1]);   
}
void ifCopyCommand(char* str[1], char* str[2])
{
FILE *f1,*f2;
char c;
f1 = fopen  (str[1], "r"); 
f2 = fopen  (str[2], "w"); 
while(f1)
{
c= fgetc(f1);
fputc(c,f2);
}
void ifExecutableCommand(char Command[50] , char **args )
{
execvp(Command,args);   
}
void ifExitCommand()
{
exit(0);
}
void ifError(char* Command)
{
printf("\n Invalid Command ");
}

