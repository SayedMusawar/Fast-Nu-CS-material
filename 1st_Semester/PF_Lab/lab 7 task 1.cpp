#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{

    float num1, num2, R, r;
    char op, ter;
    cout << "Enter the two numbers";
    cin >> num1 >> num2;
    cout << "which operation you want to perform ,add,sub,div, mul\n";
    cout << "S for sum,s for subtraction,d for division,m for multiplication\n";
    cin >> op;

    switch (op) {
    case 'S':
        R = num1 + num2;
        //	cout<<"the sum is :"<<R<<endl;
		if (R < 0)
        {
            r =(int) R * -1;
            cout << "the sum is" << r << endl;
        }
        else
        {
            r = (int)R;
            cout << "the sum is is" << r << endl;
        }
        
        cout << "enter n or N chracter to terminate the programm\n";
        cin >> ter;
        if (ter == 'N' || ter == 'n')
            cout << "the programm is ended";
        else
            cout << "invalid termination";
    	break;
    case 's':
        R = num1 - num2;
        //		cout<<"the subtration is"<<R<<endl;
        if (R < 0)
        {

            r =(int) R * -1;
            cout << "subtraction = " << r << endl;
        }
        else
        {

            r = (int)R;
            cout << "subtraction = " << r << endl;
        }
        cout << "enter a chracter to terminate the programm" << endl;
        cin >> ter;
        if (ter == 'N' || ter == 'n')
            cout << "the programm is ended\n";
        else
            cout << "invalid termination\n";
        break;
    case 'd':
        //		cout<<"the division is\n";
        R = num1 / num2;
        //	cout<<R;
        if (R < 0)
        {

            r = (int)R * -1;
            cout << "the division is" << r << endl;
        }
        else
        {

            r = (int)R;
            cout << "Division is" << r << endl;
        }
        cout << "enter a chracter to terminate the programm\n";
        cin >> ter;
        if (ter == 'N' || ter == 'n')
            cout << "the programm is ended";
        else
            cout << "invalid termination";
        break;
    case 'm':
        R = num1 * num2;
        //		cout<<""<<R<<endl;

        if (R < 0)
        {

            r = (int)R * -1;
            cout << "the multiplication is" << r << endl;
        }
        else
        {

            r = (int)R;
            cout << "the multipication is" << r << endl;
        }
        cout << "enter a chracter to terminate the programm\n";
        cin >> ter;
        if (ter == 'N' || ter == 'n')
            cout << "the programm is ended";
        else
            cout << "invalid termination";
        break;
    default:
        cout << "Invalid input." << endl;
    }

    return 0;
}
