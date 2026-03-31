#include <ios>
#include <iostream>
#include <limits>
#include <vector>
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
    vector <string> description(4);
    if(first <= 11) result += "E", description[0] = "You draw energy from communicating with others and actively interacting with \nthe world. You feel more comfortable discussing ideas out loud than thinking \nabout them alone for a long time.";
    else result += "I", description[0] = "Your energy is directed inward, towards your own thoughts and feelings. \nYou need time alone to regain your strength after social contacts.";

    if(second <= 11) result += "S", description[1] = "You trust facts, specific details, and practical experience. It is \nimportant for you to see the real result and rely on what is happening at the moment.";
    else result += "N", description[2] = "You focus on ideas, symbols, and future possibilities. You like to look \nfor hidden connections and look at the big picture instead of focusing on the details.";

    if(third <= 11) result += "T", description[2] = "When making decisions, you rely on logic, objective analysis, and common \nsense. You value fairness and efficiency more than personal feelings \nand sympathies.";
    else result += "F", description[2] = "Your decisions are based on personal values, people's feelings,\nand a desire for harmony. Empathy is important to you and how your \nactions will affect the atmosphere in the team.";


    if(fourth <= 11) result += "J", description[3] = "You prefer structure, clear planning, and getting things done. \nYou feel more comfortable when everything is organized and decisions are \nmade in advance.";
    else result += "P", description[3] = "You like flexibility, spontaneity, and prefer to keep your options open.\nIt's easier for you to adapt to circumstances on the go than to follow a strict \nschedule.";

    cout << "\n------------------------------------" << endl;
    cout << "\tYour MBTI is: " << result << endl;
    for (int i = 0; i < description.size(); i++) {
        cout << description[i] << endl;
    }
    cout << "------------------------------------" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
