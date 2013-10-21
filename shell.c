#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>



//void TypeCommand(char filename[] );// display the content of file 
void CopyCommand(char filename1[] ,char filename2[]);//copying from one file to another
void ExecutableCommand(char command[]);// execute the command
void DeleteCommand(char filename[]);//delete the file
char** splitstring(char str[],int *size );//parse input string and returns command/filenames
//int main()
{
   //char command[100];
   int size,i;
   char** parse_command;
   printf("****************************SHELL****************************\n\n");
   
   for(;;){
       printf("       Shell>>");
       fgets(command,100,stdin);
       command[strlen(command)-1]='\0'; 
       parse_command=splitstring(command,&size);
       // assign null to end of string
       for(i=0;i<size;i++)
          parse_command[i][strlen(parse_command[i])]='\0';
       
       // compare the commands
       if (!strcmp(parse_command[0],"delete")) 
       { 
          if (size==2)
             DeleteCommand(parse_command[1]);
          else
             printf("      ERROR: Invalid format >>delete filename\n");
       }
       else if (!strcmp(parse_command[0],"exit"))
       {
            break;
       } 
       else if(!strcmp(parse_command[0], "type")) 
       { 
         if (size==2)    
            TypeCommand(parse_command[1]);
         else
            printf("      ERROR: Invalid command format >>type filename\n");
       }
       else if (!strcmp(parse_command[0],"copy")) 
       { 
         if (size==3)
           CopyCommand(parse_command[1], parse_command[2]);
         else
           printf("       ERROR: Invalid command format >>copy from-filename to-filename\n");
       } 
       else
       { 
          if (size==1)
            ExecutableCommand(parse_command[0]);
          else
            printf("     ERROR: Invalid command>> type/delete/copy/type/exit//{exec-file-name}\n"); 
       } 
    }
return 0;
}

void DeleteCommand(char filename[50])
{
    if(remove(filename)){
      printf("     ERROR: Can't delete a file\n");
      return;
    }   
}

 

