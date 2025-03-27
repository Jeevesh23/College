#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


	struct TASK {
	    int TaskID;
	    char TaskTitle[100];
	    int duration;
	    int status; // 0 for idle, 1 for queued and 2 for completed
	};
	
	void delay(int time);
	void display(struct TASK queue[]);
	void schedule(struct TASK tasks[], struct TASK queue[]);
	void run(struct TASK [], struct TASK []);
	int isFull();
	int isEmpty();
	int front = -1;
	int rear = -1;
	int MAX = 5;
	int main() {
	    struct TASK tasks[10];
	    struct TASK task_arr[MAX];
		int i;
	    FILE *f;
	    f=fopen("tasks.txt.txt", "r+");
	    if ((f=fopen("tasks.txt.txt", "r+")) == NULL) {
	        printf("The file could not be opened\n");
	        exit(1);
	    }
	    for (i = 0; i < 10; i++) {
	    	fscanf(f, "%d %s %d %d", &tasks[i].TaskID, tasks[i].TaskTitle, &tasks[i].duration, &tasks[i].status);
		}
	    fclose(f);
		
		for (i = 0; i < 10; i++) {
	        printf("%d - %s %d %d\n", tasks[i].TaskID, tasks[i].TaskTitle, tasks[i].duration, tasks[i].status);
		}
	    
		while (1) {
	        printf("\n1.Schedule a Task\n");
	        printf("2.Run the tasks\n");
	        printf("3.Display\n");
	        printf("4.Exit\n");
	        printf("Select the task operation - ");
	        int choice;
	        scanf("%d", &choice);
	        
			switch (choice) {
		        case 1:
		        	schedule(tasks, task_arr);
		            break;
		        case 2:
		            run(task_arr, tasks);
		            break;
		        case 3:
		            display(task_arr);
		            break;
		        case 4:
		            printf("Program Terminated");
					exit(0);
		        default:
		            printf("Invalid i/p\n");
		            break;
	        }
	    }
	    return 0;
	}
	
	void delay(int time) {
	    int time_ms = 1000 * time;
	    clock_t start = clock();
	    while (clock() < start + time_ms)
	    {
	        
	    }
	    printf("\n");
	}
	
	void schedule(struct TASK task[], struct TASK queue[]) {
	    int i;
		if (isFull()) {
	        int maxwait = 0;
	        for (i = 0; i < MAX; i++)
	            maxwait += queue[i].duration;
	        printf("Please wait. Min wating time: %d seconds\nMax waiting time: %d seconds\n", task[rear].duration, maxwait);
	        return;
	    }
	
	    printf("Enter the task ID: ");
	    int ID;
	    scanf("%d", &ID);
	    for (i = 0; i < 10; i++) {
	        if (ID == task[i].TaskID) {
	            if (task[i].status != 0) {
	                printf("Task cannot be scheduled\nReason: ");
	                switch (task[i].status) {
		                case 1:
		                    printf("Task already Scheduled\n");
		                    return;
		                case 2:
		                    printf("Task Completed\n");
		                default:
		                    return;
	                }
	                return;
	            }
	            if (front == -1)
	                front = 0;
	            rear += 1;
	            queue[rear].duration = task[i].duration;
				queue[rear].TaskID = task[i].TaskID;
				task[i].status = 1;
	            queue[rear].status = task[i].status;
	            strcpy(queue[rear].TaskTitle, task[i].TaskTitle);
	            printf("Task successfully scheduled\n");
	            return;
	        }
	    }
	    printf("Task not found\n");
	    return;
	}
	
	void run(struct TASK queue[], struct TASK task[]) {
	    int i;
		printf("Running Task: %s\n", queue[front].TaskTitle);
	    delay(queue[front].duration);
	    front = front + 1;
	    MAX += 1;
	    for (i = 0; i < 10; i++) {
	        if (queue[front].TaskID == task[i].TaskID) {
	            task[i].status = 2;
	        }
		}
	 	printf("Task completed!\n");   
	}
	
	void display(struct TASK queue[]) {
	    int i;
		if (isEmpty()) {
	        printf("No tasks scheduled!\n");
	        return;
	    }
	    printf("Sheduled tasks are\n");
	    for (i = front; i <= rear; i++) {
	        printf("ID: %d\nTitle: %s\n", queue[i].TaskID, queue[i].TaskTitle);
	    }
	}
	
	int isFull() {
	    if (rear == MAX - 1)
	        return 1;
	    else 
			return 0;
	}
	
	int isEmpty() {
	    if (front == -1 || front == rear + 1)
	        return 1;
	    else 
			return 0;
	}
