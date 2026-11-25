// Contract: for each 5x5 board, find the minimum number of presses (at most 6)
//           that changes every light to 1; output -1 if impossible within 6 presses.
// Interval semantics: rows and columns are [0, 4]; mask represents the complete
//                     press pattern of the first row, with bit j mapped to column j.
// Learner supplies: T test cases and five strings of five '0'/'1' characters per case.
// Return meaning: solve(mask) returns the press count for a valid first-row pattern,
//                or INF when the last row cannot be made all 1.
// Complexity: O(2^5 * 5^2) time and O(5^2) auxiliary space per test case.
// Numeric assumptions: the board width is exactly 5 and the press limit is 6.
// Originating problem: lights-out-5x5 (logic verified; AC not reported).

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int WIDTH = 5;
const int LIMIT = 6;
const int INF = 1e9;

int original[WIDTH][WIDTH];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {1, 0, 0, -1, 0};

void press(int board[WIDTH][WIDTH], int x, int y) {
    for (int k = 0; k < 5; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (0 <= nx && nx < WIDTH && 0 <= ny && ny < WIDTH) {
            board[nx][ny] ^= 1;
        }
    }
}

int solve(int first_row_mask) {
    int board[WIDTH][WIDTH];
    memcpy(board, original, sizeof original);
    int presses = 0;

    // Enumerate one complete press pattern for the first row.
    for (int col = 0; col < WIDTH; ++col) {
        if ((first_row_mask >> col) & 1) {
            press(board, 0, col);
            ++presses;
        }
    }

    // Once row i - 1 is fixed, row i is forced.
    for (int row = 1; row < WIDTH; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            if (board[row - 1][col] == 0) {
                press(board, row, col);
                ++presses;
            }
        }
    }

    // The last row has no next row that can change it.
    for (int col = 0; col < WIDTH; ++col) {
        if (board[WIDTH - 1][col] == 0) {
            return INF;
        }
    }

    return presses;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        for (int row = 0; row < WIDTH; ++row) {
            for (int col = 0; col < WIDTH; ++col) {
                char c;
                cin >> c;
                original[row][col] = c - '0';
            }
        }

        int answer = INF;
        for (int mask = 0; mask < (1 << WIDTH); ++mask) {
            answer = min(answer, solve(mask));
        }

        cout << (answer <= LIMIT ? answer : -1) << '\n';
    }

    return 0;
}
