#include <iostream>
using namespace std;
int main() {

  // Localization
  string msgWarning[] = {
      "Warning! All values should be in the range 1-30000",
      "Предупреждение! Все значения должны быть  в диапазоне 1-30000"};
  string msgWidth[] = {"Enter width: ", "Введите ширину: "};
  string msgHeight[] = {"Enter height: ", "Введите высоту: "};
  string msgError[] = {"Invalid value.", "Недопустимое значение."};
  string msgChar[] = {"Enter char: ", "Введите символ: "};

  // Choosing language
  int lang;
  do {
    cout << "Choose language (0 - EN, 1 - RU): ";
    if (cin >> lang && (lang == 0 || lang == 1)) {
      if (cin.peek() != '\n' && cin.peek() != EOF) {
        cout << msgError[0] << endl;
        cin.clear();
        cin.ignore(10000, '\n');
      } else {
        cin.ignore(10000, '\n');
        break;
      }
    } else {
      cout << msgError[0] << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  } while (true);

  // Warning
  cout << msgWarning[lang] << endl;

  // Choosing a width
  int x, y;
  do {
    cout << msgWidth[lang];
    if (cin >> x && x > 0 && x < 30000) {
      if (cin.peek() != '\n' && cin.peek() != EOF) {
        cout << msgError[lang] << endl;
        cin.ignore(10000, '\n');
      } else {
        cin.ignore(10000, '\n');
        break;
      }
    } else {
      cout << msgError[lang] << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  } while (true);

  // Choosing a height
  do {
    cout << msgHeight[lang];
    if (cin >> y && y > 0 && y < 30000) {
      if (cin.peek() != '\n' && cin.peek() != EOF) {
        cout << msgError[lang] << endl;
        cin.ignore(10000, '\n');
      } else {
        cin.ignore(10000, '\n');
        break;
      }
    } else {
      cout << msgError[lang] << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  } while (true);

  // Choosing a symbol
  char symbol;
  cout << msgChar[lang];
  cin >> symbol;
  cin.ignore(10000, '\n');
  cout << "" << endl;

  // Drawing a shape
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cout << symbol;
    }
    cout << endl;
  }
  cout << '\n';
  return 0;
}
