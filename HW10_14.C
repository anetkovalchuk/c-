#include <stdio.h>
#include <string.h>

typedef struct {
    char subject[50];
    char teacher[50];
    int groupNumber;
    char dayOfWeek[15];
    char classHours[20];
    char classroom[20];
} Seminar;

void inputSeminar(Seminar *s) {
    printf("Enter subject: ");
    fgets(s->subject, sizeof(s->subject), stdin);
    s->subject[strcspn(s->subject, "\n")] = '\0';

    printf("Enter teacher: ");
    fgets(s->teacher, sizeof(s->teacher), stdin);
    s->teacher[strcspn(s->teacher, "\n")] = '\0';

    printf("Enter group number: ");
    scanf("%d", &s->groupNumber);

    getchar();

    printf("Enter day of the week: ");
    fgets(s->dayOfWeek, sizeof(s->dayOfWeek), stdin);
    s->dayOfWeek[strcspn(s->dayOfWeek, "\n")] = '\0';

    printf("Enter class hours: ");
    fgets(s->classHours, sizeof(s->classHours), stdin);
    s->classHours[strcspn(s->classHours, "\n")] = '\0';

    printf("Enter classroom: ");
    fgets(s->classroom, sizeof(s->classroom), stdin);
    s->classroom[strcspn(s->classroom, "\n")] = '\0';
}

void outputSeminar(const Seminar *s) {
    printf("\nSeminar details:\n");
    printf("Subject: %s\n", s->subject);
    printf("Teacher: %s\n", s->teacher);
    printf("Group number: %d\n", s->groupNumber);
    printf("Day of the week: %s\n", s->dayOfWeek);
    printf("Class hours: %s\n", s->classHours);
    printf("Classroom: %s\n", s->classroom);
}

int main() {
    Seminar seminar;

    inputSeminar(&seminar);
    outputSeminar(&seminar);

    return 0;
}
