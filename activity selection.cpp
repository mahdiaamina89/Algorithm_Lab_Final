#include <stdio.h>

struct Activity {
  char id[5];
  int start;
  int finish;
};

void activitySelection(Activity activities[], int n);

int main() {

    int n;
      int i, j;

  printf("Enter number of activities: ");
  scanf("%d" , &n);

  Activity activities[100];

  for(int i=0;i<n;i++){
    printf("Activity Name: ");
    scanf("%s", activities[i].id);

    printf("Start Time: ");
    scanf("%d", &activities[i].start);

    printf("Finish Time: ");
    scanf("%d", &activities[i].finish);

    }

    Activity temp;

  for(i = 1; i < n; i++) {
    for(j = 0; j < n - 1; j++){
      if(activities[j].finish > activities[j+1].finish) {
        temp = activities[j];
        activities[j] = activities[j+1];
        activities[j+1] = temp;
      }
    }
  }

  printf("Sorted activities as per finish time (ascending order)\n");
  printf("%10s %10s %10s\n","Activity", "Start", "Finish");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", activities[i].id, activities[i].start, activities[i].finish);
  }


  printf("Selected Activities\n");
  printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  printf("%10s %10i %10i\n", activities[0].id, activities[0].start, activities[0].finish);

  i = 0;
  for(j = 1; j < n; j++) {
    if(activities[j].start >= activities[i].finish) {
      printf("%10s %10i %10i\n", activities[j].id, activities[j].start, activities[j].finish);
      i = j;
    }
  }
  return 0;
}

