#include <ios>
#include <iostream>
#include <limits>
using namespace std;

void select(short* pquestion, short choice, short* ptarget){
    cout << "1.Uniquely \n2.Most likely \n3.Probably not \n4.No" << endl;
    while (true){
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 4){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please, try again (1-4)" << endl;
            continue;
        }
        break;
    }
    (*pquestion)++;
    (*ptarget) += choice;
    system("clear");
}

int main(){
    cout << "Welcome to the mbti test. Lets start" << endl;
    short choice = 0, question = 1, first = 0, second = 0, third = 0, fourth = 0;

    // Extraversion/Introversion
    cout << question << ". Do you feel energized after spending time with many people?" << endl;
    select(&question, choice, &first);
    cout << question << ". Do you find it easy to start a conversation with a stranger?" << endl;
    select(&question, choice, &first);
    cout << question << ". Do you prefer to talk about your problems rather than think alone?" << endl;
    select(&question, choice, &first);
    cout << question << ". Do you enjoy being the center of attention?" << endl;
    select(&question, choice, &first);
    cout << question << ". Do you tend to act first and think later?" << endl;
    select(&question, choice, &first);

    // Sensing/Intuition
    cout << question << ". Do you prefer to deal with facts and reality rather than theories?" << endl;
    select(&question, choice, &second);
    cout << question << ". Do you focus more on what is happening right now?" << endl;
    select(&question, choice, &second);
    cout << question << ". Do you like instructions to be clear and detailed?" << endl;
    select(&question, choice, &second);
    cout << question << ". Do you value practical experience more than gut feeling?" << endl;
    select(&question, choice, &second);
    cout << question << ". Do you describe things in a literal, concrete way?" << endl;
    select(&question, choice, &second);

    // thinking/Feeling
    cout << question << ". Do you rely on logic more than emotions when making decisions?" << endl;
    select(&question, choice, &third);
    cout << question << ". Is it more important to be fair than to be kind?" << endl;
    select(&question, choice, &third);
    cout << question << ". Do you stay objective even when others are getting emotional?" << endl;
    select(&question, choice, &third);
    cout << question << ". Do you value efficiency more than harmony in a team?" << endl;
    select(&question, choice, &third);
    cout << question << ". Do you base your arguments on evidence rather than empathy?" << endl;
    select(&question, choice, &third);

    // Judging/Perceiving
    cout << question << ". Do you like to have a detailed plan for your day?" << endl;
    select(&question, choice, &fourth);
    cout << question << ". Do you prefer to finish your work well before the deadline?" << endl;
    select(&question, choice, &fourth);
    cout << question << ". Do you feel better after you have made a final decision?" << endl;
    select(&question, choice, &fourth);
    cout << question << ". Do you keep your living and working space organized?" << endl;
    select(&question, choice, &fourth);
    cout << question << ". Do you prefer to know what to expect rather than going with the flow?" << endl;
    select(&question, choice, &fourth);

    // Result
    string result = "";
    if(first <= 11) result += "E";
    else result += "I";

    if(second <= 11) result += "S";
    else result += "N";

    if(third <= 11) result += "T";
    else result += "F";

    if(fourth <= 11) result += "J";
    else result += "P";

    cout << "\n------------------------------------" << endl;
    cout << "\tYour MBTI is: " << result << endl;
    cout << "------------------------------------" << endl;
    cin.get();
    return 0;
}
