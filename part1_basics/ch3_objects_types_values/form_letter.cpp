//Produce a stadard form letter based on user inputs
#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    string message = "Dear " + first_name + ",\n"
        + "   How are you? I am fine. I miss you.\n";

    cout << "Enter the name of a mutual friend:\n";
    string friend_name;
    cin >> friend_name;
    message += "Have you seen " + friend_name + " lately?\n";
    char friend_sex = 0;
    cout << "Enter 'm' if mutual friend is male, or 'f' for female:\n";
    cin >> friend_sex;
    if (friend_sex == 'm')
        message += "If you see " + friend_name + " please ask him to call me.\n";
    if (friend_sex == 'f')
        message += "If you see " + friend_name + " please ask her to call me.\n";

    cout << "Enter the age of the recipient:\n";
    int age;
    cin >> age;
    message += "I hear you just had a birthday and are " + to_string(age) + " years old.\n";
    if (age <= 0 || age >= 110)
        simple_error("You're kidding!\n");
    if (age < 12)
        message += "Next year you will be " + to_string(age + 1) + " years old.\n";
    if (age == 17)
        message += "Next year you will be able to vote!\n";
    if (age > 70)
        message += "I hope you are enjoying retirement.\n";
    message += "Yours truly,\n\n\nSomeone\n";    

    cout << message;
    return 0;
}
