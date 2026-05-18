
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int getGrade(Student* student, char* predmet) {
    for (int i = 0; i < student->stPO; i++) {
        if (strcmp(student->po[i].predmet, predmet) == 0) {
            return student->po[i].ocena;
        }
    }

    return -1;
}

void swapInArray(VO** array, int indexA, int indexB) {
    VO* temp = NULL;
    temp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = temp;
}

int compareByGradeThenVpisna(VO* a, VO* b) {
    return a->ocena - b->ocena != 0 ? -(a->ocena - b->ocena) : a->vpisna - b->vpisna;
}

void sort(VO** passed, int len, int (*compare)(VO*, VO*)) {
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (compare(passed[i], passed[j]) > 0) {
                swapInArray(passed, i, j);
            }
        }
    }
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    *stVO = 0;
    for (int i = 0; i < stStudentov; i++) {
        *stVO += (getGrade(studentje[i], predmet) >= 6);
    }

    VO** passed = (VO**) calloc(*stVO, sizeof(VO*));
    for (int i = 0; i < *stVO; i++) {
        passed[i] = (VO*) calloc (1, sizeof(VO));
    }
    int i = 0;
    int grade = 0;
    for (int j = 0; j < stStudentov; j++) {
        if ((grade = getGrade(studentje[j], predmet)) >= 6) {
            passed[i]->ocena = grade;
            passed[i]->vpisna = studentje[j]->vpisna;
            i++;
        }
    }

    sort(passed, *stVO, &compareByGradeThenVpisna);

    return passed;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
