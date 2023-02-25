#include <iostream>
#include <string>

using namespace std;
/*
    문제
    "*" 문자 연속으로 사용하여 정사각형 사각형 삼각형 만들기
    => 정사각형, 직사각형, 삼각형 선택
*/
int main()
{
    int inputShapeType;

    // 1. 도형 선택.
    for(int keepAsking = 1; keepAsking == 1;)
    {
        cout << "Select the Shape Type." << endl;
        cout << "  (1) - Square " << endl;
        cout << "  (2) - Rectangle " << endl;
        cout << "  (3) - Triangle " << endl;
        cout << "Shape Type (enter 1/2/3): ";
        cin >> inputShapeType;  

        if (inputShapeType == 1 || inputShapeType == 2 || inputShapeType == 3){
            keepAsking = 0;
        }
    }
    const int shapeType = inputShapeType;

    // 2. 도형 높이 정의
    cout << "Enter Shape Height: ";
    int shapeHeight;
    cin >> shapeHeight;

    // 총 행의 개수 설정
    const int numRows = shapeHeight;

    // 3. 모양 너비 정의 또는 계산.
    /*
        모양 정사각형 => 너비는 높이와 동일
        모양 직사각형 => 사용자는 너비수를 명시적으로 제공해야함
        모양 삼각형 => 너비는 (2 * numRows) - 1;
    */

   
   int finalShapeWidth;
   if (shapeType == 1){
        finalShapeWidth = shapeHeight;
   } else if (shapeType == 2){
        int shapeWidth;
        cout << "Enter Shape Width: ";
        cin >> shapeWidth;
        finalShapeWidth = shapeWidth;
   } else {
        finalShapeWidth = (shapeHeight * 2) - 1;
   }
   const string::size_type numCols = finalShapeWidth;

    // 4. 채우기 스타일 선택(중공/단색)
    /* 
        속인 빈 모양이나 단단한 모양을 출력하는 옵션 추가.
    */
    int inputFillStyle;
    for (int keepAsking = 1; keepAsking == 1;){
        cout << "Select Fill Style." << endl;
        cout << "  (1) - Hollow " << endl;
        cout << "  (2) - Solid " << endl;
        cout << "Select Fill Style (enter 1/2): ";
        cin >> inputFillStyle;

        if (inputFillStyle == 1 || inputFillStyle == 2){
            keepAsking = 0;
        }
    }
    const int fillStyle = inputFillStyle;

    // 행의 개수 loop
    for (int r = 0; r != numRows; r++){
        string::size_type c = 0;

        // c 설정
        while(c != numCols){

            // 구현 알고리즘

            
            if (shapeType == 1 or shapeType == 2){
                // 직사각형 또는 정사각형

                // 속이 빈 경우
                if (fillStyle == 1){
                    
                    if(
                            (c == 0)
                        ||  (c == numCols-1)
                        ||  (r == 0)
                        ||  (r == numRows - 1)
                    )
                    { cout << "*"; ++c; }
                    else
                    { cout << ' '; ++c; }
                }
                else if (fillStyle == 2)
                { cout << "*"; ++c; }
            } 

            // 삼각형
            if (shapeType == 3) {

                if (fillStyle == 1){
                    if(
                            (c == ((numCols -1) / 2) - r)
                        ||  (c == ((numCols -1) / 2) + r)
                        ||  (r == numRows - 1)
                    )
                    { cout << "*"; ++c; }
                    else
                    { cout << ' '; ++c; }
                } else if (fillStyle == 2){
                    if(
                            (c >= ((numCols -1) / 2) - r)
                        &&  (c <= ((numCols -1) / 2) + r)
                    )
                    { cout << "*"; ++c; }
                    else
                    { cout << ' '; ++c; }
                }
            }            
        }
        cout << "\n";
    }
    

    return 0;
}