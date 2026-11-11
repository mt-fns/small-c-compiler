// expect: fail
// The function body is never closed, so the end of file is reached
// while still inside the compound statement.

int main() {
    if (1) {
        return 1;
    }
