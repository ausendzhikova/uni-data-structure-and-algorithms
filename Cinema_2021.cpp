#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Student {
    bool visited;
    int x;
    int y;
    bool isSick;

    Student(int x = -1, int y = -1, bool visited = 0, bool isSick = 0) {
        this->x = x;
        this->y = y;
        this->visited = visited;
        this->isSick = isSick;
    }
};

bool isValid(vector<vector<Student>>& students, int rows, int columns, int x, int y) {
    return x >= 0 && y >= 0 && x < rows&& y < columns&& students[x][y].isSick != 1;
}

void findTotalSickStudents(vector<vector<Student>>& students, int rows, int columns, int& count, queue<Student*>& sickStudents, int time) {
    queue<Student*> newSick;
    while (!sickStudents.empty()) {
        auto current = sickStudents.front();
        sickStudents.pop();
        current->visited = 1;


        if (isValid(students, rows, columns, current->x, current->y - 1) && students[current->x][current->y - 1].isSick == 0 && students[current->x][current->y - 1].visited == 0) {
            count++;
            students[current->x][current->y - 1].isSick = 1;
            newSick.push(&students[current->x][current->y - 1]);
        }
        if (isValid(students, rows, columns, current->x, current->y + 1) && students[current->x][current->y + 1].isSick == 0 && students[current->x][current->y + 1].visited == 0) {
            count++;
            students[current->x][current->y + 1].isSick = 1;
            newSick.push(&students[current->x][current->y + 1]);

        }
        if (isValid(students, rows, columns, current->x - 1, current->y) && students[current->x - 1][current->y].isSick == 0 && students[current->x - 1][current->y].visited == 0) {
            count++;
            students[current->x - 1][current->y].isSick = 1;
            newSick.push(&students[current->x - 1][current->y]);

        }
        if (isValid(students, rows, columns, current->x + 1, current->y) && students[current->x + 1][current->y].isSick == 0 && students[current->x + 1][current->y].visited == 0) {
            count++;
            students[current->x + 1][current->y].isSick = 1;
            newSick.push(&students[current->x + 1][current->y]);

        }
    }

    sickStudents = newSick;
    time--;
    if (time > 0 && !sickStudents.empty()) {
        
        findTotalSickStudents(students, rows, columns, count, sickStudents, time);

    }


}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<Student>> students;
    students.assign(rows, vector<Student>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            students[i][j] = Student(i, j, 0, 0);
        }
    }
    int time;
    cin >> time;
    int sickStudentsCount;
    cin >> sickStudentsCount;
    queue<Student*> sickStudents;
    for (int i = 0; i < sickStudentsCount; i++) {
        int rowSick, columnSick;
        cin >> rowSick >> columnSick;
        students[rowSick - 1][columnSick - 1].isSick = 1;
        sickStudents.push(&students[rowSick - 1][columnSick - 1]);
    }

    int allStudents = rows * columns;
    int count = sickStudents.size();
    findTotalSickStudents(students, rows, columns, count, sickStudents, time);
    int healthyStudents = allStudents - count;
    cout << healthyStudents << endl;
    return 0;
}