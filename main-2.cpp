#include <iostream>
#include <cmath>
using namespace std;

void task_if26() {   // завдання 1 реалізація
    double x;
    cout << " if 26 " << endl;
    cout << "Enter the value of x: ";

//повідомлення про помилку
    if (!(cin >> x)) {
        cout << "Invalid input! Please enter a valid number." << endl;
        return;
    }


    double result;

    if (x == 0){                 // умова якщо введено 0
        result = 0;

    } else if (x <= 0) {         // умова якщо введено число менше 0
        result = -x;
    }
    else if (x > 0 && x < 2) {   // умова якщо введено від 0 до 2
        result = x * x;
    }
    else {
        result = 4;
    }

    cout << "f(x) value is: " << result << endl;
   
}

// завдання 2 реалізація
void task_geom30() {
    #define PI 3.14159265358979323846
    const double doable = PI;

    cout << "enter radius: ";

    float r;
    float rightSideArea;
    float rightSideperimeter;
    float leftSideArea;
    float leftSideperimeter;
    float answerArea;
    float answerperimeter;

//повідомлення про помилку
    if (!(cin >> r)) {
        cout << "Invalid input! Please enter a valid number." << endl;
        return;
    }

    leftSideArea = (r * r) * sqrt(2);
    leftSideperimeter = (2 * r) + (r * sqrt(2));

    rightSideArea = (r * r) - ((PI * (r * r)) / 4);
    rightSideperimeter = (4 * r) - (0.5 * PI * r);


    answerArea = leftSideArea + rightSideArea;
    answerperimeter = leftSideperimeter + rightSideperimeter;

    cout << "S " << answerArea << "\n" << "P " << answerperimeter;
}

// перемикання між завданнями
int main() { 
 int menu; 
 cout << "Task number:"; 
 cin >> menu; 
 switch (menu)  
{  
  case 26: task_if26(); break;   // Завдання 1 
  case 30: task_geom30(); break;   // Завдання 2
  default: cout << "Wrong task! (Only 26,30)" << endl; //повідомлення про помилку 
 } 
 system ("pause"); 
 return 0; 
}