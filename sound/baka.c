#include <conio.h>
#include <stdio.h>
#include <windows.h>

// break�t���̃L�[���[�h
#define CASE        break;case
#define DEFAULT     break;default

// �L���萔
#define ESC         (0x1B)

// ���C���֐�
int main( void )
{
    int ch;
    
    printf( TEXT("[1].....���K(C)\n") );
    printf( TEXT("[2].....���K(D)\n") );
    printf( TEXT("[3].....���K(E)\n") );
    printf( TEXT("[4].....���K(F)\n") );
    printf( TEXT("[5].....���K(G)\n") );
    printf( TEXT("[6].....���K(A)\n") );
    printf( TEXT("[7].....���K(B)\n") );
    printf( TEXT("[8].....���K(C)\n") );
    printf( TEXT("[ESC]...�I��\n") );
    
    while ( (ch = _getch()) != ESC ){
        switch ( ch ){
            CASE TEXT('q'):     Beep( 440, 200 );       // �h
            CASE TEXT('w'):     Beep( 494, 200 );       // ��
            CASE TEXT('e'):     Beep( 554, 200 );       // �~
            CASE TEXT('r'):     Beep( 587, 200 );       // �t�@
            CASE TEXT('t'):     Beep( 659, 200 );       // �\
            CASE TEXT('y'):     Beep( 740, 200 );       // ��
            CASE TEXT('u'):     Beep( 830, 200 );       // �V
            CASE TEXT('i'):     Beep( 880, 200 );       // �h
        	CASE TEXT('o'):     Beep( 
            DEFAULT:            break;
        }
    }
    return 0;
}