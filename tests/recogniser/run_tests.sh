#!/usr/bin/env bash
# Runs every recogniser test: files in pass/ must be accepted, files in fail/ must be rejected.
# Usage: tests/recogniser/run_tests.sh [path/to/compiler]

testDir="$(cd "$(dirname "$0")" && pwd)"
compiler="${1:-$testDir/../../build/compiler}"

if [ ! -x "$compiler" ]; then
    echo "compiler not found at $compiler (build it first, or pass its path)"
    exit 1
fi

passed=0
failed=0

runTest() {
    local file="$1"
    local expected="$2"
    local expectedCode=0
    if [ "$expected" = "fail" ]; then
        expectedCode=1
    fi

    "$compiler" "$file" > /dev/null
    local code=$?

    if [ "$code" -eq "$expectedCode" ]; then
        echo "PASS  $expected/$(basename "$file")"
        passed=$((passed + 1))
    else
        echo "FAIL  $expected/$(basename "$file") (exit code $code)"
        failed=$((failed + 1))
    fi
}

for file in "$testDir"/pass/*.c; do
    runTest "$file" pass
done

for file in "$testDir"/fail/*.c; do
    runTest "$file" fail
done

echo
echo "$passed passed, $failed failed"
[ "$failed" -eq 0 ]
