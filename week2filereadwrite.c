#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_LEN 100
#define TEMP_FILE_NAME "studentRecord.txt"

typedef struct student
{
	char name[MAX_LEN+1];
	int stu_num;
	int score;
}Student;

void writeOperation();
void readOperation();

int main()
{
	writeOperation();
	readOperation();
	
	return 0;
}

void writeOperation()
{
	int fd = 0;

	Student students[3] = {
	
 		{"John",1004,100},   //name, student number,score
		{"Park",1005,75},
		{"Nam",1006,50}
	 };

	fd = open(TEMP_FILE_NAME,O_WRONLY|O_CREAT|O_TRUNC,0777);
 	
	if(fd == -1)
	{
	 	perror("Fail to open the studentRecord file.\n");
		exit(1);
	}
	
	int wd = 0;
	wd = write(fd, students, sizeof(students));

	if(wd == -1)	
	{
		perror("Fail to write the contents.\n");
		exit(1);
	}
	
	printf("Success to write the %d bytes\n",wd);
	
	close(fd);
}

void readOperation()
{
	
	int fd =0;
	Student student;
	fd = open(TEMP_FILE_NAME,O_RDONLY);

	if(fd == -1)
	{

		perror("failed open dummy file");
		exit(1);
	}	
	
	int rd = 0 ;

	while((rd = read(fd, &student, sizeof(Student)))>0)
	{
		printf("Student name	:%s\n",student.name);
	    printf("Student number  :%d\n",student.stu_num);
        printf("Student score   :%d\n",student.score);
	}
   close(fd);

}
