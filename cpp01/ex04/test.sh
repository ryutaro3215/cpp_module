#!/bin/bash

# コンパイルするソースファイル名
SOURCE_FILE="main.cpp"
# 出力ファイル名
OUTPUT_FILE="sed_replace"

# テストファイル
TEST_FILE="test.txt"
# 期待される出力ファイル
EXPECTED_OUTPUT_FILE="expected_output.txt"
# 実際の出力ファイル
ACTUAL_OUTPUT_FILE="test.txt.replace"

# コンパイル
echo "Compiling $SOURCE_FILE..."
g++ -o $OUTPUT_FILE $SOURCE_FILE

# コンパイルの成否をチェック
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi
echo "Compilation successful."

# テストケースの準備
echo "Preparing test cases..."

# テストファイルを作成
echo "This is a simple test file. This file is for testing." > $TEST_FILE

# 期待される出力ファイルを作成
echo "This is a simple test file. This file is for replaced." > $EXPECTED_OUTPUT_FILE

# テストの実行
echo "Running test cases..."
./$OUTPUT_FILE $TEST_FILE "testing" "replaced"

# 実行の成否をチェック
if [ $? -ne 0 ]; then
    echo "Execution failed!"
    exit 1
fi
echo "Execution successful."

# 結果の比較
diff $ACTUAL_OUTPUT_FILE $EXPECTED_OUTPUT_FILE > /dev/null

# 比較結果のチェック
if [ $? -eq 0 ]; then
    echo "Test passed."
    # クリーンアップ
    rm $TEST_FILE $EXPECTED_OUTPUT_FILE $ACTUAL_OUTPUT_FILE
    exit 0
else
    echo "Test failed."
    echo "Expected:"
    cat $EXPECTED_OUTPUT_FILE
    echo "Actual:"
    cat $ACTUAL_OUTPUT_FILE
    exit 1
fi

