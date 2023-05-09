// Section 9
// Challenge
/*
    This challenge is about using a collection(list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.

If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [1 2 3 4 5]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the User enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1], you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint : Use a vector!

*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    bool the_end{false};
    vector<int> data{};
    int data_item{}, min{0}, max{0};
    double sum{0}, avg{0};
    char choice{};

    while (the_end == false)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'P':
        case 'p':
            if (data.size() == 0)
                cout << "[] - the list is empty" << endl;
            else
            {
                cout << "[";
                for (int i{0}; i < data.size(); i++)
                {
                    cout << data.at(i) << " ";
                }
                cout << "]" << endl;
            }
            break;
        case 'A':
        case 'a':
            cout << "Enter the number you want to add: ";
            cin >> data_item;
            data.push_back(data_item);
            cout << data_item << " added" << endl;
            break;
        case 'M':
        case 'm':
            if (data.size() == 0)
                cout << "Unable to calculate the mean - no data" << endl;
            else
            {
                for (int i{0}; i < data.size(); i++)
                    sum += data.at(i);
                avg = sum / data.size();
                cout << "Average of the collection is " << avg << endl;
            }
            break;
        case 'S':
        case 's':
            if (data.size() == 0)
                cout << "Unable to determine the smallest number - list is empty" << endl;
            else
            {
                min = data.at(0);
                for (int i{0}; i < data.size(); i++)
                    if (data.at(i) < min)
                        min = data.at(i);
                cout << "The smallest number is " << min << endl;
            }
            break;
        case 'L':
        case 'l':
            if (data.size() == 0)
                cout << "Unable to determine the largest number - list is empty" << endl;
            else
            {
                max = data.at(0);
                for (int i{0}; i < data.size(); i++)
                    if (data.at(i) > max)
                        max = data.at(i);
                cout << "The largest number is " << max << endl;
            }
            break;
        case 'Q':
        case 'q':
            cout << "Goodbye..." << endl;
            the_end = true;
            break;
        default:
            cout << "You have accessed wrong option, please check the option" << endl;
            break;
        }
    }
    return 0;
}