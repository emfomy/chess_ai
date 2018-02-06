#include <iostream>
#include <math.h>
#include <time.h> 
using namespace std ;

#define tstep 3
int piecescore[6] = {10000,15,10,9,9,4} ; //{k,q,r,b,n,p}
int addscore[2] = {8,1} ; //{ooo/oo,p2} 
int ep[2][(tstep + 3) / 2] ; 
int ooo[2][(tstep + 3) / 2] ; 
int oo[2][(tstep + 3) / 2] ; 
int cstep[2][(tstep + 3) / 2] ; 
char Chess[tstep + 1][8][8] ; 
int n , t , winner ; 

int PRINT() ; 
int PSTEP() ; 
int CSTEP() ; 
int STEP(int) ; 
int SCORE() ; 
int TSTEP(int,int,int,int,int,int) ; 

int main()//主要函數 
{
    START:
    {
        char C[8][8] = {{'r','p',0,0,0,0,'P','R'},{'n','p',0,0,0,0,'P','N'},{'b','p',0,0,0,0,'P','B'},{'q','p',0,0,0,0,'P','Q'},{'k','p',0,0,0,0,'P','K'},{'b','p',0,0,0,0,'P','B'},{'n','p',0,0,0,0,'P','N'},{'r','p',0,0,0,0,'P','R'}} ; 
        for(int i = 0 ; i <= 7 ; i++)
            for(int j = 0 ; j <= 7 ; j++)
                Chess[0][i][j] = C[i][j] ; 
    } 
    n = 0 ;  
    winner = 9 ; 
    ooo[0][0] = 0 ; 
    ooo[1][0] = 0 ; 
    oo[0][0] = 0 ; 
    oo[1][0] = 0 ; 
     
    cout << endl << "~~~西洋棋比賽開始~~~" << endl << endl ;
    
    while(1)
    { 
        int f ; 
        cout << "0)先手 1)後手 : " ; 
        cin >> f ; 
        if(f == 0)
            break ;
        else if(f == 1)
            goto CFIRST ; 
        cout << "輸入錯誤!!!" << endl << endl ;
    }
     
    while(1)
    {
        PRINT() ; 
        if(winner != 9)
            break ; 
        PSTEP() ; 
        CFIRST : 
        PRINT() ; 
        if(winner != 9)
            break ; 
        cout << "思考中......" << endl << endl ; 
        CSTEP() ; 
    }
    
    switch(winner)
    {
        case 0:
            cout << "你輸了!!!" << endl << endl ; 
            break ; 
        case 1:
            cout << "你贏了!!!" << endl << endl ; 
            break ; 
        case 2:
            cout << "逼和!!!" << endl << endl ; 
            break ; 
    }
    
    END : 
    
    char again ;  
    cout << "重新一局? (Y/N) " ; 
    cin >> again ; 
    switch(again)
    {
        case 'Y': 
        case 'y':
             system("cls") ; 
             goto START ; 
        case 'N':
        case 'n': 
             return 0 ; 
        default:
              cout << endl << "輸入錯誤!!!" << endl << endl ;
              goto END ; 
    } 
}

int PRINT()//棋盤輸出 
{
    cout << endl << "    a   b   c   d   e   f   g   h" << endl ; 
    for(int i = 7 ; i >= 0 ; i--)
    {
        cout << "  + - + - + - + - + - + - + - + - +" << endl ; 
        cout << i + 1 << " | " ;  
        for(int j = 0 ; j <= 7 ; j++)
        {
            char k = Chess[0][j][i] ; 
            cout << k << " | " ;  
        }
        cout << endl ;  
    }
    cout << "  + - + - + - + - + - + - + - + - +" << endl ; 
    cout << endl ; 
}

int PSTEP()//玩家下棋 
{
    char step[7] ;
    int piece , xppiece , yppiece , xfpiece , yfpiece ; 
    t = 0 ; 
    ep[0][0] = 9 ;  
    n++ ; 
    
    PSTEP: 
    cout << "第 " << n << " 步 你走: " ; 
    cin >> step ;  
    if(step[0] == 'e' && step[1] == 'x' && step[2] == 'i' && step[3] == 't')
    {
        winner = 0 ; 
        return 0 ; 
    }
    xppiece = step[0] - 97 ; 
    if(xppiece > 7 && xppiece < 0)
    {
        cout << "輸入錯誤!!!此字串無意義" << endl << endl ;  
        goto PSTEP ; 
    }
    yppiece = step[1] - 49 ;
    if(yppiece > 7 && yppiece < 0)
    {
        cout << "輸入錯誤!!!此字串無意義" << endl << endl ;  
        goto PSTEP ; 
    }
    xfpiece = step[2] - 97 ; 
    if(xfpiece > 7 && xfpiece < 0)
    {
        cout << "輸入錯誤!!!此字串無意義" << endl << endl ;  
        goto PSTEP ; 
    }
    yfpiece = step[3] - 49 ; 
    if(yfpiece > 7 && yfpiece < 0)
    {
        cout << "輸入錯誤!!!此字串無意義" << endl << endl ;  
        goto PSTEP ; 
    }
    if(xfpiece == xppiece && yfpiece == yppiece)
    {
        cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
        goto PSTEP ; 
    }
    
    switch(step[4])
    {
        case '\0':
             piece = 0 ; 
             break ;  
        case 'e':
            if(step[5] == 'p')
                piece = 1 ; 
            else
            { 
                cout << "輸入錯誤!!!此字串無意義" << endl << endl ; 
                goto PSTEP ; 
            }
            break;
        case '=':
            switch(step[5])
            {
                case 'q':
                    piece = 2 ; 
                    break ; 
                case 'r':
                    piece = 3 ; 
                    break ; 
                case 'b':
                    piece = 4 ; 
                    break ; 
                case 'n':
                    piece = 5 ; 
                    break ; 
                default:
                    cout << "輸入錯誤!!!兵卒需生等(=?)" << endl << endl ;  
                    goto PSTEP ;
            } 
            break ;  
        default:
            cout << "此字串無意義" << endl << endl ;  
            goto PSTEP ;
    }
    cstep[0][0] = 10000 * piece + 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece ; 
    
    int dxpiece = xfpiece - xppiece ; 
    int dypiece = yfpiece - yppiece ; 
    switch(Chess[0][xppiece][yppiece])
    {
        case 'k':
            if(dxpiece / 2 == 0 && dypiece / 2 == 0)
            {
                if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                {
                    if(Chess[0][xfpiece][yfpiece] == 'K')
                        winner = 1 ; 
                    Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                    Chess[0][xppiece][yppiece] = 0 ; 
                    ooo[0][0] = 9 ;  
                    oo[0][0] = 9 ; 
                    return 0 ; 
                } 
            } 
            else if(xppiece == 4 && yppiece == 0 && yfpiece == 0)
            {
                if(xfpiece == 2 && ooo[0][0] == 0)
                {
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        ooo[0][0] = 9 ;  
                        oo[0][0] = 9 ; 
                        Chess[0][0][0] = 0 ; 
                        Chess[0][3][0] = 'r' ; 
                        cout << "o-o-o" << endl << endl ;  
                        return 0 ; 
                    } 
                    else
                    {
                        cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                        goto PSTEP ; 
                    }
                } 
                else if(xfpiece == 6 && oo[0][0] == 0)
                { 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        ooo[0][0] = 9 ;  
                        oo[0][0] = 9 ; 
                        Chess[0][7][0] = 0 ; 
                        Chess[0][5][0] = 'r' ; 
                        cout << "o-o" << endl << endl ;  
                        return 0 ; 
                    } 
                    else
                    { 
                        cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                        goto PSTEP ; 
                    }
                } 
                cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                goto PSTEP ;  
            }
            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
            goto PSTEP ;
        case 'q':
            if(dxpiece == dypiece)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dxpiece ; i--)
                        if(Chess[0][xppiece + i][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            } 
            else if(dxpiece == - dypiece)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece - i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dxpiece ; i--)
                        if(Chess[0][xppiece + i][yppiece - i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            } 
            else if(dxpiece == 0)
            {
                if(dypiece > 0)
                { 
                    for(int i = 1 ; i < dypiece ; i++)
                        if(Chess[0][xppiece][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dypiece < 0)
                { 
                    for(int i = - 1 ; i > dypiece ; i--)
                        if(Chess[0][xppiece][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                       {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            } 
            else if(dypiece == 0)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dypiece ; i--)
                        if(Chess[0][xppiece + i][yppiece] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            }
            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
            goto PSTEP ; 
        case 'r':
            if(dxpiece == 0)
            {
                if(dypiece > 0)
                { 
                    for(int i = 1 ; i < dypiece ; i++)
                        if(Chess[0][xppiece][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        } 
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        if(xppiece == 0 && yppiece == 0) 
                            ooo[0][0] = 9 ;  
                        else if (xppiece == 7 && yppiece == 0) 
                            oo[0][0] = 9 ;  
                        return 0 ; 
                    } 
                } 
                else if(dypiece < 0)
                { 
                    for(int i = - 1 ; i > dypiece ; i--)
                        if(Chess[0][xppiece][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        if(xppiece == 0 && yppiece == 0) 
                            ooo[0][0] = 9 ;  
                        else if (xppiece == 7 && yppiece == 0) 
                            oo[0][0] = 9 ;  
                        return 0 ; 
                    } 
                }
            } 
            else if(dypiece == 0)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        if(xppiece == 0 && yppiece == 0) 
                            ooo[0][0] = 9 ;  
                        else if (xppiece == 7 && yppiece == 0) 
                            oo[0][0] = 9 ;  
                        return 0 ; 
                    } 
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dypiece ; i--)
                        if(Chess[0][xppiece + i][yppiece] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        if(xppiece == 0 && yppiece == 0) 
                            ooo[0][0] = 9 ;  
                        else if (xppiece == 7 && yppiece == 0) 
                            oo[0][0] = 9 ;  
                        return 0 ; 
                    } 
                }
            }
            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
            goto PSTEP ;
        case 'b':
            if(dxpiece == dypiece)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dxpiece ; i--)
                        if(Chess[0][xppiece + i][yppiece + i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            } 
            else if(dxpiece == - dypiece)
            {
                if(dxpiece > 0)
                { 
                    for(int i = 1 ; i < dxpiece ; i++)
                        if(Chess[0][xppiece + i][yppiece - i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                } 
                else if(dxpiece < 0)
                { 
                    for(int i = - 1 ; i > dxpiece ; i--)
                        if(Chess[0][xppiece + i][yppiece - i] != 0)
                        {
                            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                            goto PSTEP ; 
                        }  
                    if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            }
            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
            goto PSTEP ;
        case 'n':
            if((abs(dxpiece) == 2 && abs(dypiece) ==1 ) || (abs(dxpiece) == 1 && abs(dypiece) == 2))
                if(Chess[0][xfpiece][yfpiece] / 30 != 3) 
                {
                    if(Chess[0][xfpiece][yfpiece] == 'K')
                        winner = 1 ; 
                    Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                    Chess[0][xppiece][yppiece] = 0 ; 
                    return 0 ; 
                }
            cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
            goto PSTEP ;  
        case 'p':
            if(piece == 1)
            {
                if(abs(dxpiece) == 1 && dypiece  == 1 && yppiece == 4 && abs(xppiece - ep[1][0]) ==1)
                {
                    if(Chess[0][xfpiece][yfpiece] == 0) 
                    { 
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        Chess[0][ep[1][0]][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
            }
            else
            {
                if(dxpiece == 0 && dypiece  == 1)
                {
                    if(Chess[0][xfpiece][yfpiece] == 0) 
                    {
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ;  
                        if(yfpiece == 7)
                        {
                            switch(piece)
                            {
                                case 2:
                                     Chess[0][xfpiece][yfpiece] = 'q' ; 
                                     break ; 
                                case 3:
                                     Chess[0][xfpiece][yfpiece] = 'r' ; 
                                     break ; 
                                case 4:
                                     Chess[0][xfpiece][yfpiece] = 'b' ; 
                                     break ; 
                                case 5:
                                     Chess[0][xfpiece][yfpiece] = 'n' ; 
                                     break ; 
                                default:
                                     cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                                     goto PSTEP ; 
                            }
                        }
                        else
                            Chess[0][xfpiece][yfpiece] = 'p' ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        return 0 ; 
                    }
                }
                else if(abs(dxpiece) == 1 && dypiece  == 1)
                {
                    if(Chess[0][xfpiece][yfpiece] / 30 == 2) 
                    { 
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ;  
                        if(yfpiece == 7)
                        {
                            switch(piece)
                            {
                                case 2:
                                     Chess[0][xfpiece][yfpiece] = 'q' ; 
                                     break ; 
                                case 3:
                                     Chess[0][xfpiece][yfpiece] = 'r' ; 
                                     break ; 
                                case 4:
                                     Chess[0][xfpiece][yfpiece] = 'b' ; 
                                     break ; 
                                case 5:
                                     Chess[0][xfpiece][yfpiece] = 'n' ; 
                                     break ; 
                                default:
                                     cout << "輸入錯誤!!!此移動不合法" << endl << endl ; 
                                     goto PSTEP ; 
                            }
                        }
                        else
                            Chess[0][xfpiece][yfpiece] = 'p' ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        
                        return 0 ; 
                    }
                }
                else if(dxpiece == 0 && dypiece == 2 && yppiece == 1 && Chess[0][xppiece][yppiece + 1] == 0)
                {
                    if(Chess[0][xfpiece][yfpiece] == 0) 
                    { 
                        if(Chess[0][xfpiece][yfpiece] == 'K')
                            winner = 1 ; 
                        Chess[0][xfpiece][yfpiece] = 'p' ; 
                        Chess[0][xppiece][yppiece] = 0 ; 
                        ep[0][0] = xppiece ;  
                        return 0 ; 
                    }
                }
            }
            cout << "輸入錯誤!!!-此移動不合法" << endl << endl ; 
            goto PSTEP ; 
        default:
            cout << "輸入錯誤!!!-此移動不合法" << endl << endl ; 
            goto PSTEP ;
    }
    
    return 0 ; 
} 

int CSTEP()//電腦下棋 
{
    t = 1 ;
    ep[1][0] = 9 ;  
    n++ ; 
    cstep[1][1] = 9999 ; 
        
    STEP(1) ; 
    
    if(cstep[1][1] == 9999)
    { 
        winner = 2 ; 
        return 0 ; 
    }
    if(cstep[1][1] == 0)
    { 
        winner = 1 ; 
        return 0 ; 
    }
    
    int cstep0 = cstep[1][1] ; 
    int piece = cstep0 / 10000 ; 
    int xppiece = cstep0 / 1000 % 10 ; 
    int yppiece = cstep0 / 100 % 10 ; 
    int xfpiece = cstep0 / 10 % 10 ; 
    int yfpiece = cstep0 % 10 ; 
    
    if(Chess[0][xppiece][yppiece] == 'K' || (xppiece == 0 && yppiece == 7) || (xppiece == 7 && yppiece == 7))
    {
        ooo[1][1] = 9 ; 
        oo[1][1] = 9 ; 
    }
    
    if(Chess[0][xfpiece][yfpiece] == 'k')
        winner = 0 ; 
    
    Chess[0][xfpiece][yfpiece] = Chess[0][xppiece][yppiece] ; 
    Chess[0][xppiece][yppiece] = 0 ; 
    
    char p = xppiece + 97 ; 
    char f = xfpiece + 97 ; 
    cout << "第 " << n << " 步 電腦走: " << p << yppiece + 1 << f << yfpiece + 1 ; 
    if(piece == 1)
    { 
        Chess[0][xfpiece][yppiece] = 0 ; 
        cout << "ep" ; 
    } 
    else if(piece == 2)
    {
        Chess[0][xfpiece][yfpiece] = 'Q' ; 
        cout << "=Q" ; 
    }
    else if(piece == 3)
    {
        Chess[0][xfpiece][yfpiece] = 'N' ; 
        cout << "=N" ; 
    }
    else if(piece == 4)
        ep[1][0] = xfpiece ; 
    else if(piece == 5)
    {
        Chess[0][0][7] = 0 ;
        Chess[0][3][7] = 'R' ;
        cout << endl << "o-o-o" ; 
    }
    else if(piece == 6)
    {
        Chess[0][7][7] = 0 ;
        Chess[0][5][7] = 'R' ;
        cout << endl << "o-o" ; 
    }
    
    return 0 ; 
}

int STEP(int step)//電腦推測 
{
    int team = step % 2 , teamstep = (step + 1) / 2 ; 
    
    ep[team][teamstep] = 9 ; 
    cstep[team][teamstep] = 9999 ;  
    ooo[team][teamstep] = ooo[team][teamstep - 1] ; 
    oo[team][teamstep] = oo[team][teamstep - 1] ; 
    int score = -500000 * (team * 2 - 1) ; 
    int xppiece , yppiece , xfpiece , yfpiece ; 
    for(xppiece = 0 ; xppiece <= 7 ; xppiece++)
    {
        for(yppiece = 0 ; yppiece <= 7 ; yppiece++)
        {
            switch(Chess[step - 1][xppiece][yppiece] + 32 * team)
            { 
                case 107 : //K
                    for(xfpiece = xppiece - 1 ; xfpiece <= xppiece + 1 ; xfpiece++)
                        if(xfpiece >= 0 && xfpiece <= 7)
                            for(yfpiece = yppiece - 1 ; yfpiece <= yppiece + 1 ; yfpiece++)
                                if(yfpiece >= 0 && yfpiece <= 7)
                                    if(Chess[step - 1][xfpiece][yfpiece] / 30 != 3 - team)
                                    {
                                        for(int i = 0 ; i <= 7 ; i++)
                                            for(int j = 0 ; j <= 7 ; j++)
                                                Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                        ooo[team][teamstep] = 9 ; 
                                        oo[team][teamstep] = 9 ; 
                                        score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                    }
                    if(ooo[(step - 1) % 2][step / 2] == 0)
                    {
                        xfpiece = xppiece - 2 ; 
                        yfpiece = yppiece ; 
                        if(Chess[step - 1][1][yppiece] == 0 && Chess[step - 1][2][yppiece] == 0 && Chess[step - 1][3][yppiece] == 0)
                        {
                            for(int i = 0 ; i <= 7 ; i++)
                                for(int j = 0 ; j <= 7 ; j++)
                                    Chess[step][i][j] = Chess[step - 1][i][j] ; 
                            ooo[team][teamstep] = 8 ; 
                            oo[team][teamstep] = 8 ; 
                            Chess[step][3][yfpiece] = Chess[step][0][yfpiece] ;
                            Chess[step][0][yfpiece] = 0 ; 
                            score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                cstep[team][teamstep] += 50000 ;  
                        }   
                    }
                    if(ooo[(step - 1) % 2][step / 2] == 0)
                    {
                        xfpiece = xppiece + 2 ; 
                        yfpiece = yppiece ; 
                        if(Chess[step - 1][5][yppiece] == 0 && Chess[step - 1][6][yppiece] == 0)
                        {
                            for(int i = 0 ; i <= 7 ; i++)
                                for(int j = 0 ; j <= 7 ; j++)
                                    Chess[step][i][j] = Chess[step - 1][i][j] ; 
                            ooo[team][teamstep] = 8 ; 
                            oo[team][teamstep] = 8 ; 
                            Chess[step][5][yppiece] = Chess[step - 1][7][yppiece] ;
                            Chess[step][7][yppiece] = 0 ;
                            score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                cstep[team][teamstep] += 60000 ;  
                        }   
                    }
                    break ; 
                
                case 114: //R
                case 113: //Q
                    xfpiece = xppiece ; 
                    if(yppiece < 7)
                    { 
                        for(yfpiece = yppiece + 1 ; yfpiece <= 7 ; yfpiece++)
                        {
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    if(yppiece > 0) 
                    { 
                        for(yfpiece = yppiece - 1 ; yfpiece >= 0 ; yfpiece--)
                        {
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    } 
                    
                    yfpiece = yppiece ; 
                    if(xppiece < 7)
                    { 
                        for(xfpiece = xppiece + 1 ; xfpiece <= 7 ; xfpiece++)
                        {
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    if(xppiece > 0) 
                    { 
                        for(xfpiece = xppiece - 1 ; xfpiece >= 0 ; xfpiece--)
                        {
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                if(xppiece == 0 && yppiece == 7 - team * 7)
                                    ooo[team][teamstep] == 9 ; 
                                if(xppiece == 7 && yppiece == 7 - team * 7)
                                    oo[team][teamstep] == 9 ; 
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    } 
                    if(Chess[step - 1][xppiece][yppiece] == 114 - 32 * team)
                        break ; 
                
                case 98: //B
                    int ppiece , fpiece ; 
                    if(xppiece >= yppiece)
                        ppiece = xppiece ; 
                    else
                        ppiece = yppiece ; 
                    if(ppiece < 7)
                    {
                        for(fpiece = 1 ; fpiece <= 7 - ppiece ; fpiece++)
                        {
                            xfpiece = xppiece + fpiece ; 
                            yfpiece = yppiece + fpiece ; 
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    
                    if(xppiece >= 7 - yppiece)
                        ppiece = xppiece ; 
                    else
                        ppiece = 7 - yppiece ; 
                    if(ppiece < 7)
                    {
                        for(fpiece = 1 ; fpiece <= 7 - ppiece ; fpiece++)
                        {
                            xfpiece = xppiece + fpiece ; 
                            yfpiece = yppiece - fpiece ; 
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    
                    
                    if(7 - xppiece >= yppiece)
                        ppiece = 7 - xppiece ; 
                    else
                        ppiece = yppiece ; 
                    if(ppiece < 7)
                    {
                        for(fpiece = 1 ; fpiece <= 7 - ppiece ; fpiece++)
                        {
                            xfpiece = xppiece - fpiece ; 
                            yfpiece = yppiece + fpiece ; 
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    
                    
                    if(xppiece <= yppiece)
                        ppiece = 7 - xppiece ; 
                    else
                        ppiece = 7 - yppiece ; 
                    if(ppiece > 7)
                    {
                        for(fpiece = 1 ; fpiece <= 7 -ppiece ; fpiece++)
                        {
                            xfpiece = xppiece - fpiece ; 
                            yfpiece = yppiece - fpiece ; 
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                            else if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team) 
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                break ; 
                            }
                            else
                                break ; 
                        } 
                    }
                    
                    break ;  
                    
                case 110: //N
                    for(int x = -2 ; x <= 2 ; x++) 
                    { 
                        if(x)
                        {
                            xfpiece = xppiece + x ; 
                            for(int y = -1 ; y <= 1 ; y += 2) 
                            { 
                                yfpiece = yppiece + (abs(x) % 2 + 1) * y ; 
                                if(xfpiece >= 0 && xfpiece <= 7 && yfpiece >= 0 && yfpiece <= 7)
                                    if(Chess[step - 1][xfpiece][yfpiece] / 30 != 3 - team)
                                    {
                                        for(int i = 0 ; i <= 7 ; i++)
                                            for(int j = 0 ; j <= 7 ; j++)
                                                Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                        score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                    }
                            }
                        }
                    }
                    break ; 
                case 112: //P
                    xfpiece = xppiece ; 
                    yfpiece = yppiece + 1 - team * 2 ; 
                    if(yfpiece >= 0 && yfpiece <= 7) 
                        if(Chess[step - 1][xfpiece][yfpiece] == 0 )
                        {
                            if(yfpiece == 7 - 7 * team)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                Chess[step][xfpiece][yfpiece] = 113 - (32 * team) ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ;
                                if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                    cstep[team][teamstep] += 20000 ; 
                                Chess[step][xfpiece][yfpiece] = 98 - (32 * team) ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ;
                                if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                    cstep[team][teamstep] += 30000 ; 
                            }
                            else
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            }
                        }
                    
                    yfpiece = yppiece + 2 - team * 4 ; 
                    if(yppiece == 1 + team * 5)
                        if(Chess[step - 1][xppiece][(yppiece + yfpiece) / 2] == 0 && Chess[step - 1][xfpiece][yfpiece] == 0)
                        {
                            ep[team][teamstep] = yfpiece ; 
                            for(int i = 0 ; i <= 7 ; i++)
                                for(int j = 0 ; j <= 7 ; j++)
                                    Chess[step][i][j] = Chess[step - 1][i][j] ; 
                            score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                            if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                cstep[team][teamstep] += 40000 ; 
                        }
                    
                    for(int x = -1 ; x <= 1 ; x += 2) 
                    { 
                        xfpiece = xppiece + x ; 
                        yfpiece = yppiece + 1 - team * 2 ; 
                        if(xfpiece >= 0 && xfpiece <= 7 && yfpiece >= 0 && yfpiece  <= 7)
                            if(Chess[step - 1][xfpiece][yfpiece] / 30 == 2 + team)
                            {
                                if(yfpiece == 7 - 7 * team)
                                {
                                    for(int i = 0 ; i <= 7 ; i++)
                                        for(int j = 0 ; j <= 7 ; j++)
                                            Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                    Chess[step][xfpiece][yfpiece] = 113 - (32 * team) ; 
                                    score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                    if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                        cstep[team][teamstep] += 20000 ; 
                                Chess[step][xfpiece][yfpiece] = 98 - (32 * team) ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ;
                                if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                    cstep[team][teamstep] += 20000 ; 
                                }
                                else
                                {
                                    for(int i = 0 ; i <= 7 ; i++)
                                        for(int j = 0 ; j <= 7 ; j++)
                                            Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                    score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                }
                            }
                        if(yppiece == 4 - team && ep[(step - 1) % 2][step / 2] == xfpiece)
                            if(Chess[step - 1][xfpiece][yfpiece] == 0)
                            {
                                for(int i = 0 ; i <= 7 ; i++)
                                    for(int j = 0 ; j <= 7 ; j++)
                                        Chess[step][i][j] = Chess[step - 1][i][j] ; 
                                Chess[step][xfpiece][yppiece] == 0 ; 
                                score = TSTEP(step , xppiece , yppiece , xfpiece , yfpiece , score) ; 
                                if(cstep[team][teamstep] == 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece)
                                    cstep[team][teamstep] += 10000 ; 
                            }
                    }
                    
            }
        }
    }
    
    return score ; 
}
    


int SCORE()//分數計算 
{
    int score = 0 ;  
    
    if(ooo[0][(tstep + 1) / 2] == 9 || oo[0][(tstep + 1) / 2] == 9)
        score += addscore[0] ; 
    if(ooo[1][(tstep + 1) / 2] == 9 || oo[1][(tstep + 1) / 2] == 9)
        score -= addscore[0] ; 
    for(int i = 1 ; i <= tstep ; i++)
        if(ep[i % 2][(i + 1) / 2] != 0)
            score -= addscore[1] * ((i % 2) * 2 - 1) ; 

    for(int x = 0 ; x <= 7 ; x++)
    {
        for(int y = 0 ; y <= 7 ; y++) 
        { 
            switch(Chess[tstep][x][y])
            {
                case 'K':
                    score += piecescore[0]; 
                    break ; 
                case 'k':
                    score -= piecescore[0] ; 
                    break ; 
                case 'Q':
                    score += piecescore[1] ; 
                    break ; 
                case 'q':
                    score -= piecescore[1] ; 
                    break ; 
                case 'R':
                    score += piecescore[2] ; 
                    break ; 
                case 'r':
                    score -= piecescore[2] ; 
                    break ; 
                case 'B':
                    score += piecescore[3] ; 
                    break ; 
                case 'b':
                    score -= piecescore[3] ; 
                    break ; 
                case 'N':
                    score += piecescore[4] ; 
                    break ; 
                case 'n':
                    score -= piecescore[4] ; 
                    break ; 
                case 'P':
                    score += piecescore[5] ; 
                    break ; 
                case 'p':
                    score -= piecescore[5] ; 
            }
        }
    }
    
    return score ; 
} 

int TSTEP(int step , int xppiece , int yppiece , int xfpiece , int yfpiece , int score)
{
    int s , cs ; 
        
    if(Chess[step][xfpiece][yfpiece] == 'k') 
    {
        cs = 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece ; 
        s = 10000000 - step * 100000 ; 
    }
    else if(Chess[step][xfpiece][yfpiece] == 'K') 
    {
        cs = 0 ; 
        s = -1000000 + step * 100000 ; 
    }
    else 
    {
        Chess[step][xfpiece][yfpiece] = Chess[step - 1][xppiece][yppiece] ; 
        Chess[step][xppiece][yppiece] = 0 ;
        if(step == tstep)
            s = SCORE() ; 
        else 
            s = STEP(step + 1) ; 
        cs = 1000 * xppiece + 100 * yppiece + 10 * xfpiece + yfpiece ; 
    }
    
    if((s - score) * ((step % 2) * 2 - 1) > 0) 
    { 
        cstep[step % 2][(step + 1) / 2] = cs ; 
        return s ; 
    } 
    else if(s == score)
    {
        srand(time(NULL)) ; 
        int t = rand() % 2 ; 
        cstep[step % 2][(step + 1) / 2] = cs * t + cstep[step % 2][(step + 1) / 2] * (!t) ; 
    }
    return score ; 
}
