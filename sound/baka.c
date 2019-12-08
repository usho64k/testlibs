#include <conio.h>
#include <stdio.h>
#include <windows.h>

// break付きのキーワード
#define CASE        break;case
#define DEFAULT     break;default

// 記号定数
#define ESC         (0x1B)

// メイン関数
int main( void )
{
    int ch;
    
    printf( TEXT("[1].....音階(C)\n") );
    printf( TEXT("[2].....音階(D)\n") );
    printf( TEXT("[3].....音階(E)\n") );
    printf( TEXT("[4].....音階(F)\n") );
    printf( TEXT("[5].....音階(G)\n") );
    printf( TEXT("[6].....音階(A)\n") );
    printf( TEXT("[7].....音階(B)\n") );
    printf( TEXT("[8].....音階(C)\n") );
    printf( TEXT("[ESC]...終了\n") );
    
    while ( (ch = _getch()) != ESC ){
        switch ( ch ){
            CASE TEXT('q'):     Beep( 440, 200 );       // ド
            CASE TEXT('w'):     Beep( 494, 200 );       // レ
            CASE TEXT('e'):     Beep( 554, 200 );       // ミ
            CASE TEXT('r'):     Beep( 587, 200 );       // ファ
            CASE TEXT('t'):     Beep( 659, 200 );       // ソ
            CASE TEXT('y'):     Beep( 740, 200 );       // ラ
            CASE TEXT('u'):     Beep( 830, 200 );       // シ
            CASE TEXT('i'):     Beep( 880, 200 );       // ド
        	CASE TEXT('o'):     Beep( 
            DEFAULT:            break;
        }
    }
    return 0;
}