// 11.6 Практическая работа. Задание 4. Оценка результатов игры в крестики-нолики
#include <iostream>
using namespace std;

void CrossZero(string text, int *answerVictoryCross,
               int *answerVictoryZero, int *answerCross, int *answerZero,
               int *answerPoint, bool *answerGood) {
  bool good = true;
  int cross = 0, zero = 0, point = 0, RowCross = 0, RoWZero = 0,
      VictoryCross = 0, VictoryZero = 0;

  for (int i = 0; i < text.length(); i++) {
    if (text.length() == 3) {
      if (text[i] == 'X') {
        cross++;
        RowCross++;
      } else if (text[i] == 'O') {
        zero++;
        RoWZero++;
      } else if (text[i] == '.') {
        point++;
      } else {
        good = false;
        break;
      }
    } else {
      good = false;
      break;
    }
  }
  if (RowCross == 3) {
    VictoryCross++;
  } else if (RoWZero == 3) {
    VictoryZero++;
  }

  (*answerVictoryCross) = VictoryCross;
  (*answerVictoryZero) = VictoryZero;
  (*answerCross) = cross;
  (*answerZero) = zero;
  (*answerPoint) = point;
  (*answerGood) = good;
}

int main() {
  string TopRow, MiddleRow, LowerRow, answer;
  cout << "11.6 Practical work.\nTask 4. Evaluation of the results of the "
               "game of tic-tac-toe.\n"
            << endl;
  cout << "Enter field strings\n";
  cin >> TopRow >> MiddleRow >> LowerRow;
  bool TopRowGood = true, MiddleRowGood = true, LowerRowGood = true;
  int cross = 0, zero = 0, point = 0, TopRowCross = 0, TopRowZero = 0,
      MiddleRoWCross = 0, MiddleRowZero = 0, LowerRowCross = 0,
      LowerRowZero = 0, VictoryCross = 0, VictoryZero = 0,
      TopRowVictoryCross = 0, TopRowVictoryZero = 0, MiddleRoWVictoryCross = 0,
      MiddleRowVictoryZero = 0, LowerRowVictoryCross = 0,
      LowerRowVictoryZero = 0, TopRowPoint = 0, MiddleRowPoint = 0,
      LowerRowPoint = 0;

  CrossZero(TopRow, &TopRowVictoryCross, &TopRowVictoryZero, &TopRowCross,
            &TopRowZero, &TopRowPoint, &TopRowGood);
  CrossZero(MiddleRow, &MiddleRoWVictoryCross, &MiddleRowVictoryZero,
            &MiddleRoWCross, &MiddleRowZero, &MiddleRowPoint, &MiddleRowGood);
  CrossZero(LowerRow, &LowerRowVictoryCross, &LowerRowVictoryZero,
            &LowerRowCross, &LowerRowZero, &LowerRowPoint, &LowerRowGood);

  VictoryCross =
      TopRowVictoryCross + MiddleRoWVictoryCross + LowerRowVictoryCross;
  VictoryZero = TopRowVictoryZero + MiddleRowVictoryZero + LowerRowVictoryZero;
  cross = TopRowCross + MiddleRoWCross + LowerRowCross;
  zero = TopRowZero + MiddleRowZero + LowerRowZero;
  point = TopRowPoint + MiddleRowPoint + LowerRowPoint;

  if (TopRowGood && MiddleRowGood && LowerRowGood) {
    if ((TopRow[0] == 'X' && MiddleRow[0] == 'X' && LowerRow[0] == 'X') ||
        (TopRow[1] == 'X' && MiddleRow[1] == 'X' && LowerRow[1] == 'X') ||
        (TopRow[2] == 'X' && MiddleRow[2] == 'X' && LowerRow[2] == 'X') ||
        (TopRow[0] == 'X' && MiddleRow[1] == 'X' && LowerRow[2] == 'X') ||
        (TopRow[2] == 'X' && MiddleRow[1] == 'X' && LowerRow[0] == 'X')) {
      VictoryCross++;
    }
    if ((TopRow[0] == 'O' && MiddleRow[0] == 'O' && LowerRow[0] == 'O') ||
        (TopRow[1] == 'O' && MiddleRow[1] == 'O' && LowerRow[1] == 'O') ||
        (TopRow[2] == 'O' && MiddleRow[2] == 'O' && LowerRow[2] == 'O') ||
        (TopRow[0] == 'O' && MiddleRow[1] == 'O' && LowerRow[2] == 'O') ||
        (TopRow[2] == 'O' && MiddleRow[1] == 'O' && LowerRow[0] == 'O')) {
      VictoryZero++;
    }
    if (VictoryCross > 1 || VictoryZero > 1 ||
        (VictoryCross >= 1 && VictoryZero >= 1) ||
        (VictoryCross == 1 && zero >= cross) ||
        (VictoryZero == 1 && cross >= zero) ||
        (VictoryZero == 1 && cross < zero) ||
        (VictoryCross == 1 && zero != (cross - 1))) {
      answer = "\t>> Incorrect";
    } else if (VictoryCross == 0 && VictoryZero == 0 && point >= 0) {
      answer = "\t>> Nobody";
    } else if (VictoryCross == 1 && VictoryZero == 0) {
      answer = "\t>> Petya won";
    } else if (VictoryCross == 0 && VictoryZero == 1) {
      answer = "\t>> Vanya won";
    }
  } else {
    answer = "Incorrect";
  }
  cout << answer;
}

 