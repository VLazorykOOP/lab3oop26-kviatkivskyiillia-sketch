#include <iostream>
#include <cmath>
using namespace std;

class Vector3 {
private:
    double arr[3];
    int state;
    static int objectCount;

public:
    Vector3() {
        for (int i = 0; i < 3; i++) arr[i] = 0;
        state = 0;
        objectCount++;
    }

    Vector3(double val) {
        for (int i = 0; i < 3; i++) arr[i] = val;
        state = 0;
        objectCount++;
    }

    Vector3(double* ptr) {
        if (ptr == nullptr) {
            for (int i = 0; i < 3; i++) arr[i] = 0;
            state = 1;
        }
        else {
            for (int i = 0; i < 3; i++) arr[i] = ptr[i];
            state = 0;
        }
        objectCount++;
    }

    ~Vector3() {
        cout << "Destructor: state = " << state << endl;
        objectCount--;
    }

    void setValue(double val = 0.0) {
        for (int i = 0; i < 3; i++) arr[i] = val;
    }

    double getElement(int index) const {
        if (index < 0 || index > 2) {
            cout << "Invalid index!\n";
            return 0;
        }
        return arr[index];
    }

    void print() const {
        cout << "(" << arr[0] << ", " << arr[1] << ", " << arr[2] << ")";
        cout << " state=" << state << endl;
    }

    Vector3 add(const Vector3& other) const {
        Vector3 res;
        for (int i = 0; i < 3; i++) res.arr[i] = arr[i] + other.arr[i];
        return res;
    }

    Vector3 sub(const Vector3& other) const {
        Vector3 res;
        for (int i = 0; i < 3; i++) res.arr[i] = arr[i] - other.arr[i];
        return res;
    }

    Vector3 cross(const Vector3& other) const {
        Vector3 res;
        res.arr[0] = arr[1] * other.arr[2] - arr[2] * other.arr[1];
        res.arr[1] = arr[2] * other.arr[0] - arr[0] * other.arr[2];
        res.arr[2] = arr[0] * other.arr[1] - arr[1] * other.arr[0];
        return res;
    }

    void divide(short val) {
        if (val == 0) { state = 2; return; }
        for (int i = 0; i < 3; i++) arr[i] /= val;
    }

    double length() const {
        return sqrt(arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2]);
    }

    bool isGreater(const Vector3& other) const { return length() > other.length(); }
    bool isLess(const Vector3& other) const { return length() < other.length(); }
    bool isEqual(const Vector3& other) const { return length() == other.length(); }

    static int getObjectCount() { return objectCount; }
};

int Vector3::objectCount = 0;

void runVector3() {
    int choice;
    Vector3 v1, v2;

    do {
        cout << "\n===== Menu Vector3 =====\n";
        cout << "1. Enter vector A\n";
        cout << "2. Enter vector B\n";
        cout << "3. Enter Vectori\n";
        cout << "4. Add A + B\n";
        cout << "5. Vidnyati A - B\n";
        cout << "6. Vektorniy dobutok A x B\n";
        cout << "7. Podilitu vektor A na chislo\n";
        cout << "8. Porivnyati vektori\n";
        cout << "9. Kilkist objectiv\n";
        cout << "0. Back\n";
        cout << "choose: ";
        cin >> choice;

        if (choice == 1) {
            double x, y, z;
            cout << "Enter A (x y z): ";
            cin >> x >> y >> z;
            double data[3] = { x, y, z };
            v1 = Vector3(data);
        }
        else if (choice == 2) {
            double x, y, z;
            cout << "Enter B (x y z): ";
            cin >> x >> y >> z;
            double data[3] = { x, y, z };
            v2 = Vector3(data);
        }
        else if (choice == 3) {
            cout << "A = "; v1.print();
            cout << "B = "; v2.print();
        }
        else if (choice == 4) {
            cout << "A + B = ";
            v1.add(v2).print();
        }
        else if (choice == 5) {
            cout << "A - B = ";
            v1.sub(v2).print();
        }
        else if (choice == 6) {
            cout << "A x B = ";
            v1.cross(v2).print();
        }
        else if (choice == 7) {
            short d;
            cout << "Dilutu A na: ";
            cin >> d;
            v1.divide(d);
            cout << "A = "; v1.print();
        }
        else if (choice == 8) {
            cout << "A > B: " << v1.isGreater(v2) << endl;
            cout << "A < B: " << v1.isLess(v2) << endl;
            cout << "A == B: " << v1.isEqual(v2) << endl;
        }
        else if (choice == 9) {
            cout << "Object sum " << Vector3::getObjectCount() << endl;
        }

    } while (choice != 0);
}

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe() { resetGame(); }

    void resetGame() {
        gameOver = false;
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Error coordinates\n";
            return false;
        }
        if (board[row][col] != ' ') {
            cout << "Klitinka vze busy!\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void printStatus() {
        cout << "Xid gravcha " << currentPlayer << endl;
    }

    void checkGameState() {
        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " Win!\n";
            gameOver = true;
        }
        else if (checkDraw()) {
            printBoard();
            cout << "Nichiya!\n";
            gameOver = true;
        }
    }

    void play() {
        int row, col;
        cout << "Game start!\n";
        while (!gameOver) {
            printBoard();
            printStatus();
            cout << "Vvedit ryadok i stobech (0-2): ";
            cin >> row >> col;
            if (makeMove(row, col)) {
                checkGameState();
                if (!gameOver) switchPlayer();
            }
        }
    }
};

void runTicTacToe() {
    int choice;
    TicTacToe game;

    do {
        cout << "\n===== Chrestiki noliki =====\n";
        cout << "1. New game\n";
        cout << "2. Continu game\n";
        cout << "0. back\n";
        cout << "choose: ";
        cin >> choice;

        if (choice == 1) {
            game.resetGame();
            game.play();
        }
        else if (choice == 2) {
            game.play();
        }

    } while (choice != 0);
}

int main() {
    int choice;

    do {
        cout << "\n=============================\n";
        cout << "   Menu\n";
        cout << "=============================\n";
        cout << "1. Task 1\n";
        cout << "2. Task 2\n";
        cout << "3. Exit \n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            runVector3();
        }
        else if (choice == 2) {
            runTicTacToe();
        }

    } while (choice != 0);

    cout << "Exit\n";
    return 0;
}