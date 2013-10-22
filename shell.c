#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

#define MAXLEN 4
#define MAXCHAR 100

void TypeCommand(char filename[] );// display the content of file 
void CopyCommand(char filename1[] ,char filename2[]);//copying from one file to another
void ExecutableCommand(char command[]);// execute the command
void DeleteCommand(char filename[]);//delete the file
char** splitstring(char str[],int *size );//parse input string and returns command/filenames

int main()
{
   char command[100];
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
 
char** splitstring(char str[], int *size){
  char *pch;
  char** tmp=malloc(sizeof(char*) * MAXLEN) ;
  if(!tmp)
   return NULL; 
  *size=0;
  pch = strtok (str," ");
  while (pch != NULL)
  {
    tmp[*size]=malloc(sizeof(char) * (MAXCHAR+1));
    if (!tmp[*size])
        return NULL;
    strcpy (tmp[*size],pch);
    pch = strtok (NULL, " ");
    (*size)++;
  }
 tmp[*size]="";
 return tmp;
}

void TypeCommand(char filename[50])
{
    FILE *f1;
    char line[200];
    f1 = fopen(filename, "r"); 
    if (f1==NULL){
      printf("     ERROR: Can't open input file to read\n");
      return;
    }
    while(fgets(line, 200, f1)!=NULL)
    {  
      printf("%s\n",line);
    }
 fclose(f1);
}


void DeleteCommand(char filename[50])
{
    if(remove(filename)){
      printf("     ERROR: Can't delete a file\n");
      return;
    }   
}

void CopyCommand(char filename1[50], char filename2[50])
{
    FILE *f1,*f2;
    char line[200];
    f1 = fopen(filename1,"r"); 
    if (f1==NULL){
      printf("can't open input file to read\n"); 
      return;
    }
    f2=fopen(filename2,"w");
    if (f2==NULL){
      printf("      ERROR: Can't open input file to write\n");
      return;
    }
    while(fgets(line,200,f1)!=NULL)
    {
      fputs(line,f2);
    }
   fclose(f2);
   fclose(f1);
}

void ExecutableCommand(char command[50])
{
    pid_t pid;
    int status;

    char **args=malloc(sizeof(char*)*2);
    if (!args)
       return ;
    args[0]=malloc(sizeof(char) * MAXLEN);
    if (!args[0])
       return ;
    strcpy(args[0],command);
    args[1]="";

    command[strlen(command)]='\0';
    
    if((pid = fork())<0){
      printf("      ERROR: Forking child process failed \n");
      return;
    }
    else if (pid==0){
      if(execvp(args[0],args)<0){
          printf("      ERROR: Exec failed\n");
          return;
      }
    }
    else{
        while (wait(&status)!=pid){}
    }    
}


