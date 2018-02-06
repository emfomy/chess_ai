Module Module1
    Dim max As Integer = 6
    Dim n, t, f, winner, maxsteps, pn, nox, otest, tests As Integer
    Dim Chess(max, 7, 7), Piece(max, 96), ooo(max, 1), oo(max, 1), ep(max), tsteps(max), steps(999), XChess(1, 7, 7), XPiece(1, 96) As Integer

    Sub Main()
        Dim str As String
        Dim i As Integer
        Do
            LOADING()
START:
            Console.WriteLine(vbLf & "Please Press Enter......") ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            str = Console.ReadLine() ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            If (str Like "none") Then '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                otest = 0 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                tests = 0 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            ElseIf (str Like "test") Then '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                otest = 1 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                tests = 1 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            ElseIf (str Like "score") Then ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                otest = 2 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                tests = 2
            End If
            '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            Console.Clear()
            Console.WriteLine(vbLf & "~~~~西洋棋比賽開始~~~~")

            Do
                Console.Write(vbLf & "0)初級 1)中級 2)高級 : ")
                str = Console.ReadLine
                Select Case str
                    Case "0"
                        max = 2
                        Exit Do
                    Case "1"
                        max = 4
                        Exit Do
                    Case "2"
                        max = 6
                        Exit Do
                    Case "exit"
                        Console.Clear()
                        GoTo START
                    Case Else
                        Console.WriteLine("輸入錯誤!!!")
                End Select
            Loop
            maxsteps = max

            Do
                Console.Write(vbLf & "0)先手 1)後手 : ")
                str = Console.ReadLine
                Select Case str
                    Case "0"
                        f = 0
                        Exit Do
                    Case "1"
                        f = 1
                        GoTo CFIRST
                    Case "exit"
                        Console.Clear()
                        GoTo START
                    Case Else
                        Console.WriteLine("輸入錯誤!!!")
                End Select
            Loop

            Do
                PRINT()
                If (winner <> 9) Then
                    Exit Do
                End If
                If (nox = 50) Then
                    winner = 3
                    Exit Do
                End If
                PSTEP()
CFIRST:
                PRINT()
                If (winner <> 9) Then
                    Exit Do
                End If
                If (nox = 50) Then
                    winner = 3
                    Exit Do
                End If
                Console.WriteLine("思考中......")
                CSTEP()
            Loop
            Select Case winner
                Case 0
                    Console.WriteLine("你輸!!!" & vbLf)
                Case 1
                    Console.WriteLine("你贏!!!" & vbLf)
                Case 2
                    Console.WriteLine("和局!!!" & vbLf)
                Case 3
                    Console.WriteLine("和局!!!(50 no X)" & vbLf)
            End Select

            Do
                Console.Write("列印棋局? (Y/N) ")
                str = Console.ReadLine()
                Select Case str
                    Case "Y"
                    Case "y"
                    Case "N"
                        Exit Do
                    Case "n"
                        Exit Do
                    Case Else
                        Console.WriteLine("輸入錯誤!!!" & vbLf)
                        Continue Do
                End Select
                Console.Clear()
                pn = 0
                If (f = 0) Then
                    Console.WriteLine(vbLf & Chr(9) & "玩家" & Chr(9) & Chr(9) & "電腦")
                Else
                    Console.WriteLine(vbLf & Chr(9) & "電腦" & Chr(9) & Chr(9) & "玩家")
                End If
                For i = 0 To (n - 1) / 2
                    PRINTSTEP()
                    PRINTSTEP()
                    Console.WriteLine()
                Next
                Exit Do
            Loop

            Do
                Console.Write(vbLf & "重新一局? (Y/N) ")
                str = Console.ReadLine()
                Select Case str
                    Case "Y"
                        Exit Do
                    Case "y"
                        Exit Do
                    Case "N"
                        Exit Sub
                    Case "n"
                        Exit Sub
                    Case Else
                        Console.WriteLine("輸入錯誤!!!" & vbLf)
                        Continue Do
                End Select
            Loop
        Loop
    End Sub

    Sub LOADING()
        Dim x, y As Integer
        Dim C(,) As Integer = {{59, 89, 0, 0, 0, 0, 41, 11}, {79, 90, 0, 0, 0, 0, 42, 31}, {69, 91, 0, 0, 0, 0, 43, 21}, {50, 92, 0, 0, 0, 0, 44, 2}, {49, 93, 0, 0, 0, 0, 45, 1}, {70, 94, 0, 0, 0, 0, 46, 22}, {80, 95, 0, 0, 0, 0, 47, 32}, {60, 96, 0, 0, 0, 0, 48, 12}}
        Dim P() As Integer = {99, 47, 37, 99, 99, 99, 99, 99, 99, 99, 99, 7, 77, 99, 99, 99, 99, 99, 99, 99, 99, 27, 57, 99, 99, 99, 99, 99, 99, 99, 99, 17, 67, 99, 99, 99, 99, 99, 99, 99, 99, 6, 16, 26, 36, 46, 56, 66, 76, 40, 30, 99, 99, 99, 99, 99, 99, 99, 99, 0, 70, 99, 99, 99, 99, 99, 99, 99, 99, 20, 50, 99, 99, 99, 99, 99, 99, 99, 99, 10, 60, 99, 99, 99, 99, 99, 99, 99, 99, 1, 11, 21, 31, 41, 51, 61, 71}

        Console.Clear()
        Console.WriteLine(vbLf & "Loading......")

        For x = 0 To 7
            For y = 0 To 7
                Chess(0, x, y) = C(x, y)
            Next
        Next

        For x = 0 To 96
            Piece(0, x) = P(x)
        Next

        For x = 0 To 199
            steps(x) = 0
        Next

        n = 0
        winner = 9
        nox = 0
        ooo(0, 0) = 0
        ooo(0, 1) = 0
        oo(0, 0) = 0
        oo(0, 1) = 0
    End Sub

    Sub CSTEP()
        Dim xpp, ypp, xfp, yfp, pp, fp, p, i, e As Integer
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        tests = otest '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        t = 1
        ep(1) = 9
        n += 1
        ooo(1, 0) = ooo(0, 0)
        ooo(1, 1) = ooo(0, 1)
        oo(1, 0) = oo(0, 0)
        oo(1, 1) = oo(0, 1)

        For i = 1 To maxsteps
            tsteps(i) = 9999
        Next

        TSTEP(1)
        PRINT()

        If (tsteps(1) = 9999) Then
            If (steps(n - 1) \ 2000000) Then
                winner = 1
                steps(n - 1) += 2000000
            Else
                winner = 2
            End If
            Exit Sub
        End If

        steps(n) = tsteps(1)
        p = steps(n) \ 10000
        xpp = steps(n) \ 1000 Mod 10
        ypp = steps(n) \ 100 Mod 10
        xfp = steps(n) \ 10 Mod 10
        yfp = steps(n) Mod 10
        pp = Chess(0, xpp, ypp)
        fp = Chess(0, xfp, yfp)

        If (pp = 1 OrElse (xpp = 0 AndAlso ypp = 7) OrElse (xpp = 7 AndAlso ypp = 7)) Then
            ooo(1, 1) = 9
            oo(1, 1) = 9
        End If

        If (fp = 49) Then
            winner = 0
        End If

        Chess(0, xpp, ypp) = 0
        Chess(0, xfp, yfp) = pp
        Piece(0, pp) = 10 * xfp + yfp
        If (Piece(0, fp) <> 99) Then
            Piece(0, fp) = 99
            steps(n) += 1000000
            nox = 0
        Else
            nox += 1
        End If

        If (fp = 59) Then
            ooo(0, 0) = 9
        ElseIf (fp = 60) Then
            oo(0, 0) = 9
        End If

        If (pp = 1) Then
            ooo(0, 1) = 9
            oo(0, 1) = 9
        ElseIf (pp = 11) Then
            ooo(0, 1) = 9
        ElseIf (pp = 12) Then
            oo(0, 1) = 9
        End If

        Select Case p
            Case 1 'ep
                Chess(0, xfp, ypp) = 0
            Case 2 'P2
                e = xfp
            Case 3 To 40 '=?
                Chess(0, xfp, yfp) = p
                Piece(0, p) = 10 * xfp + yfp
            Case 90 'ooo
                Chess(0, 0, 7) = 0
                Chess(0, 3, 7) = 11
                Piece(0, 11) = 37
                ooo(0, 1) = 8
                oo(0, 1) = 8
            Case 91 'oo
                Chess(0, 7, 7) = 0
                Chess(0, 5, 7) = 12
                Piece(0, 12) = 57
                ooo(0, 1) = 8
                oo(0, 1) = 8
        End Select

        LOADTSTEP(1)
        steps(n) += 1000000 * XSTEP(1)
        ep(1) = e
    End Sub

    Function TSTEP(ByVal tn As Integer)
        Dim score, tt, pp As Integer
        tt = tn Mod 2
        score = -1000000

        If (tt = 1) Then
            LOADTSTEP(tn)
            KTSTEP(score, tn, 1) 'K

            For pp = 2 To 10 'Q
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    RTSTEP(score, tn, pp)
                    LOADTSTEP(tn)
                    BTSTEP(score, tn, pp)
                End If
            Next

            For pp = 11 To 20 'R
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    RTSTEP(score, tn, pp)
                End If
            Next

            For pp = 21 To 30 'B
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    BTSTEP(score, tn, pp)
                End If
            Next

            For pp = 31 To 40 'N
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    NTSTEP(score, tn, pp)
                End If
            Next

            For pp = 41 To 48 'P
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    PTSTEP(score, tn, pp)
                End If
            Next
        Else
            LOADTSTEP(tn)
            KTSTEP(score, tn, 49) 'k

            For pp = 50 To 58 'q
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    RTSTEP(score, tn, pp)
                    LOADTSTEP(tn)
                    BTSTEP(score, tn, pp)
                End If
            Next

            For pp = 59 To 68 'r
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    RTSTEP(score, tn, pp)
                End If
            Next

            For pp = 69 To 78 'b
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    BTSTEP(score, tn, pp)
                End If
            Next

            For pp = 79 To 88 'n
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    NTSTEP(score, tn, pp)
                End If
            Next

            For pp = 89 To 96 'p
                If (Piece(tn, pp) <> 99) Then
                    LOADTSTEP(tn)
                    PTSTEP(score, tn, pp)
                End If
            Next
        End If

        Return (-score)
    End Function

    Sub KTSTEP(ByRef score As Integer, ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, tt, i As Integer

        tt = tn Mod 2
        xpp = Piece(tn, pp) \ 10
        ypp = Piece(tn, pp) Mod 10

        For xfp = xpp - 1 To xpp + 1
            If (xfp >= 0 AndAlso xfp <= 7) Then
                For yfp = ypp - 1 To ypp + 1
                    If (yfp >= 0 AndAlso yfp <= 7) Then
                        LOADTSTEP(tn)
                        fp = Chess(tn, xfp, yfp)
                        If (((fp + 47) \ 48 <> 2 - tt) AndAlso Not (xpp = xfp AndAlso ypp = yfp)) Then
                            DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                        End If
                    End If
                Next
            End If
        Next

        LOADTSTEP(tn)
        If (ooo(tn, tt) = 0 AndAlso Chess(tn, 3, 7 * tt) = 0 AndAlso Chess(tn, 2, 7 * tt) = 0 AndAlso Chess(tn, 1, 7 * tt) = 0) Then
            fp = 0
            xfp = 2
            yfp = ypp

            For i = 2 To 4
                If (XKSTEP(tn, xpp, ypp, i, 7 * tt)) Then
                    GoTo K
                End If
            Next

            Chess(tn, 0, 7 * tt) = 0
            Chess(tn, 3, 7 * tt) = 59 - 48 * tt
            Piece(tn, 59 - 48 * tt) = 30 + 7 * tt
            DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 90)
        End If
K:
        LOADTSTEP(tn)
        If (oo(tn, tt) = 0 AndAlso Chess(tn, 5, 7 * tt) = 0 AndAlso Chess(tn, 6, 7 * tt) = 0) Then
            fp = 0
            xfp = 6
            yfp = ypp

            For i = 4 To 6
                If (XKSTEP(tn, xpp, ypp, i, 7 * tt)) Then
                    Exit Sub
                End If
            Next

            Chess(tn, 0, 7 * tt) = 0
            Chess(tn, 5, 7 * tt) = 59 - 48 * tt
            Piece(tn, 59 - 48 * tt) = 50 + 7 * tt
            DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 91)
        End If
    End Sub

    Sub RTSTEP(ByRef score As Integer, ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, i, j, tt As Integer

        tt = tn Mod 2
        xpp = Piece(tn, pp) \ 10
        ypp = Piece(tn, pp) Mod 10

        For i = -1 To 1 Step 2
            xfp = xpp
            yfp = ypp + i
            j = i
            Do While (yfp <= 7 AndAlso yfp >= 0)
                LOADTSTEP(tn)
                fp = Chess(tn, xfp, yfp)
                If (fp = 0) Then
                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                Else
                    If ((fp + 47) \ 48 = 1 + tt) Then
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                    End If
                    Exit Do
                End If
                j += i
                yfp += i
            Loop

            xfp = xpp + i
            yfp = ypp
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0)
                LOADTSTEP(tn)
                fp = Chess(tn, xfp, yfp)
                If (fp = 0) Then
                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                Else
                    If ((fp + 47) \ 48 = 1 + tt) Then
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
            Loop
        Next
    End Sub

    Sub BTSTEP(ByRef score As Integer, ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, i, j, tt As Integer


        tt = tn Mod 2
        xpp = Piece(tn, pp) \ 10
        ypp = Piece(tn, pp) Mod 10

        For i = -1 To 1 Step 2
            xfp = xpp + i
            yfp = ypp + i
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0 AndAlso yfp <= 7 AndAlso yfp >= 0)
                LOADTSTEP(tn)
                fp = Chess(tn, xfp, yfp)
                If (fp = 0) Then
                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                Else
                    If ((fp + 47) \ 48 = 1 + tt) Then
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
                yfp += i
            Loop

            xfp = xpp + i
            yfp = ypp - i
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0 AndAlso yfp <= 7 AndAlso yfp >= 0)
                LOADTSTEP(tn)
                fp = Chess(tn, xfp, yfp)
                If (fp = 0) Then
                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                Else
                    If ((fp + 47) \ 48 = 1 + tt) Then
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
                yfp -= i
            Loop
        Next
    End Sub

    Sub NTSTEP(ByRef score As Integer, ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, tt, i As Integer


        tt = tn Mod 2
        xpp = Piece(tn, pp) \ 10
        ypp = Piece(tn, pp) Mod 10
        i = -1

        For xfp = xpp - 2 To xpp + 2
            If (xfp >= 0 AndAlso xfp <= 7) Then
                For yfp = ypp - 2 To ypp + 2
                    If (yfp >= 0 AndAlso yfp <= 7) Then
                        If (i = 1) Then
                            If (xpp <> xfp AndAlso ypp <> yfp) Then
                                LOADTSTEP(tn)
                                fp = Chess(tn, xfp, yfp)
                                If ((fp + 47) \ 48 <> 2 - tt) Then
                                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 0)
                                End If
                            End If
                        End If
                    End If
                    i *= -1
                Next
            Else
                i *= -1
            End If
        Next
    End Sub

    Sub PTSTEP(ByRef score As Integer, ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, p, tt As Integer

        tt = tn Mod 2
        xpp = Piece(tn, pp) \ 10
        ypp = Piece(tn, pp) Mod 10

        yfp = ypp + 1 - tt * 2
        If (yfp >= 0 AndAlso yfp <= 7) Then
            For xfp = xpp - 1 To xpp + 1 Step 2
                If (xfp >= 0 AndAlso xfp <= 7) Then
                    LOADTSTEP(tn)
                    fp = Chess(tn, xfp, yfp)
                    If ((fp + 47) \ 48 = 1 + tt) Then
                        p = 0
                        If (yfp = 0 OrElse yfp = 7) Then
                            For p = 3 To 40
                                If (Piece(tn, p) = 99) Then
                                    LOADTSTEP(tn)
                                    Piece(tn, p) = 10 * xfp + yfp
                                    Piece(tn, pp) = 99
                                    Chess(tn, xpp, ypp) = p
                                    If (p >= 33) Then
                                        Exit For
                                    End If
                                    DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, p)
                                    p = 33
                                End If
                            Next
                        End If
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, p)
                    End If

                    LOADTSTEP(tn)
                    If (fp = 0 AndAlso ep(tn - 1) = xfp AndAlso ypp = 4 - tt) Then
                        Chess(tn, xfp, ypp) = 0
                        Piece(tn, Chess(tn, xfp, ypp)) = 99
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 1)
                    End If
                End If
            Next

            xfp = xpp
            LOADTSTEP(tn)
            fp = Chess(tn, xfp, yfp)
            If (fp = 0) Then
                p = 0
                If (yfp = 0 OrElse yfp = 7) Then
                    For p = 3 To 40
                        If (Piece(tn, p) = 99) Then
                            LOADTSTEP(tn)
                            Piece(tn, p) = 10 * xfp + yfp
                            Piece(tn, pp) = 99
                            Chess(tn, xpp, ypp) = p
                            If (p >= 33) Then
                                Exit For
                            End If
                            DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, p)
                            p = 33
                        End If
                    Next
                End If
                DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, p)

                If (ypp = 1 + 5 * tt) Then
                    yfp += 1 - tt * 2
                    LOADTSTEP(tn)
                    fp = Chess(tn, xfp, yfp)
                    If (fp = 0) Then
                        ep(tn) = xfp
                        DOTSTEP(score, tn, xpp, ypp, xfp, yfp, pp, fp, 2)
                    End If
                End If
            End If
        End If
    End Sub

    Sub LOADTSTEP(ByVal tn As Integer)
        Dim x, y As Integer

        ep(tn) = 9
        ooo(tn, 0) = ooo(tn - 1, 0)
        ooo(tn, 1) = ooo(tn - 1, 1)
        oo(tn, 0) = ooo(tn - 1, 0)
        oo(tn, 1) = ooo(tn - 1, 1)

        For x = 0 To 7
            For y = 0 To 7
                Chess(tn, x, y) = Chess(tn - 1, x, y)
            Next
        Next

        For x = 0 To 96
            Piece(tn, x) = Piece(tn - 1, x)
        Next
    End Sub

    Sub DOTSTEP(ByRef score As Integer, ByRef tn As Integer, ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer)
        Dim tt, s As Integer
        tt = tn Mod 2
        Chess(tn, xpp, ypp) = 0
        Chess(tn, xfp, yfp) = pp
        Piece(tn, pp) = 10 * xfp + yfp
        Piece(tn, fp) = 99

        If (p < 90) Then
            If (fp = 11) Then
                ooo(tn, 1) = 9
            ElseIf (fp = 12) Then
                oo(tn, 1) = 9
            ElseIf (fp = 59) Then
                ooo(tn, 0) = 9
            ElseIf (fp = 60) Then
                oo(tn, 0) = 9
            End If

            If (pp = 1 OrElse pp = 49) Then
                ooo(tn, tt) = 9
                oo(tn, tt) = 9
            ElseIf (pp = 11 OrElse pp = 59) Then
                ooo(tn, tt) = 9
            ElseIf (pp = 12 OrElse pp = 60) Then
                oo(tn, tt) = 9
            End If

            If (p > 2) Then
                Chess(tn, xfp, yfp) = p
            End If
        Else
            ooo(tn, tt) = 8
            oo(tn, tt) = 8
        End If

        If (tn = 1 OrElse (tn = 2 AndAlso maxsteps = 3)) Then
            LOADTSTEP(tn + 1)
            If (XSTEP(tn + 1)) Then
                Exit Sub
            End If
        End If


        If (tn = maxsteps OrElse fp = 1 OrElse fp = 49) Then
            s = GETSCORE(tn)
            If (tests = 1) Then '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                TEST(tn, xpp, ypp, xfp, yfp, pp, fp, p, s) ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            End If ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        Else
            If (tests = 1) Then '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                TEST(tn, xpp, ypp, xfp, yfp, pp, fp, p, s) ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            End If ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            s = TSTEP(tn + 1)
        End If

        If (score = s) Then
            Randomize()
            If (Int(Rnd() * 2) = 1) Then
                tsteps(tn) = 10000 * p + 1000 * xpp + 100 * ypp + 10 * xfp + yfp
            End If
        Else
            score = Math.Max(s, score)
            If (score = s) Then
                tsteps(tn) = 10000 * p + 1000 * xpp + 100 * ypp + 10 * xfp + yfp
            End If
        End If
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        If (tests = 2) Then '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            TEST2(tn, xpp, ypp, xfp, yfp, pp, fp, score, s) '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        End If ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    End Sub

    Function GETSCORE(ByVal tn As Integer)
        Dim score, x, y As Integer

        If (ooo(tn, 0) = 9 OrElse oo(tn, 0) = 9) Then
            score += 8
        End If
        If (ooo(tn, 1) = 9 OrElse oo(tn, 1) = 9) Then
            score -= 8
        End If

        For x = 0 To 7
            For y = 0 To 7
                Select Case Chess(tn, x, y)
                    Case 1 'K
                        score += 100000 - tn * 1000
                    Case 2 To 10 'Q
                        score += 15
                    Case 11 To 20 'R
                        score += 10
                    Case 21 To 30 'B
                        score += 9
                    Case 31 To 40 'N
                        score += 9
                    Case 41 To 48 'P
                        score += 4
                    Case 49 'k
                        score -= 100000 - tn * 1000
                    Case 50 To 58 'q
                        score -= 15
                    Case 59 To 68 'r
                        score -= 10
                    Case 69 To 78 'b
                        score -= 9
                    Case 79 To 88 'n
                        score -= 9
                    Case 89 To 96 'p
                        score -= 4
                End Select
            Next
        Next

        If (tn Mod 2 = 0) Then
            Return (-score)
        End If

        Return (score)
    End Function

    Function XKSTEP(ByVal tn As Integer, ByVal xpp As Integer, ByVal ypp As Integer, ByVal xfp As Integer, ByVal yfp As Integer)
        Dim pp, fp As Integer

        tn += 1
        LOADTSTEP(tn)

        pp = Chess(tn, xpp, ypp)
        fp = Chess(tn, xfp, yfp)
        Chess(tn, xpp, ypp) = 0
        Chess(tn, xfp, yfp) = pp
        Piece(tn, pp) = 10 * xfp + yfp
        Piece(tn, fp) = 99

        Return (XSTEP(tn))
    End Function

    Function XSTEP(ByVal tn As Integer)
        Dim x, y, pp As Integer

        For x = 0 To 7
            For y = 0 To 7
                XChess(0, x, y) = Chess(tn, x, y)
            Next
        Next

        tn = tn Mod 2

        For x = 0 To 96
            XPiece(0, x) = Piece(tn, x)
        Next

        If (tn = 1) Then
            LOADXSTEP()
            If (KXSTEP(tn, 1)) Then 'K
                Return (2)
            End If

            For pp = 2 To 10 'Q
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (RXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                    LOADXSTEP()
                    If (BXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 11 To 20 'R
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (RXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 21 To 30 'B
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (BXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 31 To 40 'N
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (NXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 41 To 48 'P
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (PXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next
        Else
            LOADXSTEP()
            If (KXSTEP(tn, 49)) Then 'k
                Return (2)
            End If
            For pp = 50 To 58 'q
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (RXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                    LOADXSTEP()
                    If (BXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 59 To 68 'r
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (RXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 69 To 78 'b
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (BXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 79 To 88 'n
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (NXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next

            For pp = 89 To 96 'p
                If (Piece(tn, pp) <> 99) Then
                    LOADXSTEP()
                    If (PXSTEP(tn, pp)) Then
                        Return (2)
                    End If
                End If
            Next
        End If

        Return (0)
    End Function

    Function KXSTEP(ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp As Integer

        xpp = XPiece(1, pp) \ 10
        ypp = XPiece(1, pp) Mod 10

        For xfp = xpp - 1 To xpp + 1
            If (xfp >= 0 AndAlso xfp <= 7) Then
                For yfp = ypp - 1 To ypp + 1
                    If (yfp >= 0 AndAlso yfp <= 7) Then
                        LOADXSTEP()
                        If ((Chess(1, xfp, yfp) = 1 + tn * 48) AndAlso Not (xpp = xfp AndAlso ypp = yfp)) Then
                            Return (-1)
                        End If
                    End If
                Next
            End If
        Next
        Return (0)
    End Function

    Function RXSTEP(ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, i, j As Integer

        xpp = XPiece(1, pp) \ 10
        ypp = XPiece(1, pp) Mod 10

        For i = -1 To 1 Step 2
            xfp = xpp
            yfp = ypp + i
            j = i
            Do While (yfp <= 7 AndAlso yfp >= 0)
                LOADXSTEP()
                fp = XChess(1, xfp, yfp)
                If (fp <> 0) Then
                    If (fp = 1 + tn * 48) Then
                        Return (-1)
                    End If
                    Exit Do
                End If
                j += i
                yfp += i
            Loop

            xfp = xpp + i
            yfp = ypp
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0)
                LOADXSTEP()
                fp = XChess(1, xfp, yfp)
                If (fp <> 0) Then
                    If (fp = 1 + tn * 48) Then
                        Return (-1)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
            Loop
        Next
        Return (0)
    End Function

    Function BXSTEP(ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, fp, i, j As Integer

        xpp = XPiece(1, pp) \ 10
        ypp = XPiece(1, pp) Mod 10

        For i = -1 To 1 Step 2
            xfp = xpp + i
            yfp = ypp + i
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0 AndAlso yfp <= 7 AndAlso yfp >= 0)
                LOADXSTEP()
                fp = XChess(1, xfp, yfp)
                If (fp <> 0) Then
                    If (fp = 1 + tn * 48) Then
                        Return (-1)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
                yfp += i
            Loop

            xfp = xpp + i
            yfp = ypp - i
            j = i
            Do While (xfp <= 7 AndAlso xfp >= 0 AndAlso yfp <= 7 AndAlso yfp >= 0)
                LOADXSTEP()
                fp = XChess(1, xfp, yfp)
                If (fp <> 0) Then
                    If (fp = 1 + tn * 48) Then
                        Return (-1)
                    End If
                    Exit Do
                End If
                j += i
                xfp += i
                yfp -= i
            Loop
        Next
        Return (0)
    End Function

    Function NXSTEP(ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp, i As Integer

        xpp = XPiece(1, pp) \ 10
        ypp = XPiece(1, pp) Mod 10
        i = -1

        For xfp = xpp - 2 To xpp + 2
            If (xfp >= 0 AndAlso xfp <= 7) Then
                For yfp = ypp - 2 To ypp + 2
                    If (yfp >= 0 AndAlso yfp <= 7) Then
                        If (i = 1) Then
                            If (xpp <> xfp AndAlso ypp <> yfp) Then
                                LOADXSTEP()
                                If (XChess(1, xfp, yfp) = 1 + tn * 48) Then
                                    Return (-1)
                                End If
                            End If
                        End If
                    End If
                    i *= -1
                Next
            Else
                i *= -1
            End If
        Next
        Return (0)
    End Function

    Function PXSTEP(ByRef tn As Integer, ByVal pp As Integer)
        Dim xpp, ypp, xfp, yfp As Integer

        xpp = XPiece(1, pp) \ 10
        ypp = XPiece(1, pp) Mod 10

        yfp = ypp + 1 - tn * 2
        If (yfp >= 0 AndAlso yfp <= 7) Then
            For xfp = xpp - 1 To xpp + 1 Step 2
                If (xfp >= 0 AndAlso xfp <= 7) Then
                    LOADXSTEP()
                    If (XChess(1, xfp, yfp) = 1 + tn * 48) Then
                        Return (-1)
                    End If
                End If
            Next
        End If
        Return (0)
    End Function

    Sub LOADXSTEP()
        Dim x, y As Integer

        For x = 0 To 7
            For y = 0 To 7
                XChess(1, x, y) = XChess(0, x, y)
            Next
        Next

        For x = 0 To 96
            XPiece(1, x) = XPiece(0, x)
        Next
    End Sub

    Sub PSTEP()
        Dim pstep As String
        Dim xpp, ypp, xfp, yfp, pp, fp, dxp, dyp, p, x As Integer
        t = 0
        ep(0) = 9
        n += 1
        x = 0

        LOADTSTEP(1)
        LOADTSTEP(2)
        tsteps(2) = 9999
        maxsteps = 3
        TSTEP(2)
        maxsteps = max

        If (tsteps(2) = 9999) Then
            If (steps(n - 1) \ 2000000) Then
                winner = 0
                steps(n - 1) += 2000000
            Else
                winner = 2
            End If
            Exit Sub
        End If

        Do
            Console.Write("第 " & n & " 步 你走 : ")
            pstep = Console.ReadLine()
            If (pstep = "exit") Then
                winner = 0
                Exit Sub
            End If
            If (pstep Like "????") Then
                If (pstep Like "[!a-h]???") Then
                    Console.WriteLine("輸入錯誤!!!此字串無意義(錯誤代碼:1)" & vbLf)
                    Continue Do
                End If
                If (pstep Like "?[!1-8]??") Then
                    Console.WriteLine("輸入錯誤!!!此字串無意義(錯誤代碼:2)" & vbLf)
                    Continue Do
                End If
                If (pstep Like "??[!a-h]?") Then
                    Console.WriteLine("輸入錯誤!!!此字串無意義(錯誤代碼:3)" & vbLf)
                    Continue Do
                End If
                If (pstep Like "???[!1-8]") Then
                    Console.WriteLine("輸入錯誤!!!此字串無意義(錯誤代碼:4)" & vbLf)
                    Continue Do
                End If
                p = 0
            ElseIf (pstep Like "????ep") Then
                p = 1
            ElseIf (pstep Like "????=q") Then
                p = 2
            ElseIf (pstep Like "????=r") Then
                p = 3
            ElseIf (pstep Like "????=b") Then
                p = 4
            ElseIf (pstep Like "????=n") Then
                p = 5
            Else
                Console.WriteLine("輸入錯誤!!!此字串無意義(錯誤代碼:0)" & vbLf)
                Continue Do
            End If

            xpp = Asc(GetChar(pstep, 1)) - 97
            ypp = Asc(GetChar(pstep, 2)) - 49
            xfp = Asc(GetChar(pstep, 3)) - 97
            yfp = Asc(GetChar(pstep, 4)) - 49
            dxp = xfp - xpp
            dyp = yfp - ypp
            pp = Chess(0, xpp, ypp)
            fp = Chess(0, xfp, yfp)

            If (dxp = 0 AndAlso dyp = 0) Then
                Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:5)" & vbLf)
                Continue Do
            End If

            If (XKSTEP(0, xpp, ypp, xfp, yfp) AndAlso pp <> 0) Then
                Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:++)" & vbLf)
                Continue Do
            End If

            Select Case Chess(0, xpp, ypp)
                Case 49 'k
                    If (KPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:k)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case 50 To 58 'q
                    If (RPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0 AndAlso BPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:q)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case 59 To 68 'r
                    If (RPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:r)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case 69 To 78 'b
                    If (BPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:b)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case 79 To 88 'n
                    If (NPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:n)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case 89 To 96 'p'
                    If (PPSTEP(xpp, ypp, xfp, yfp, dxp, dyp, pp, fp, p, x) <> 0) Then
                        Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:p)" & vbLf)
                        Continue Do
                    End If
                    Exit Do
                Case Else
                    Console.WriteLine("輸入錯誤!!!此移動不合法(錯誤代碼:*)" & vbLf)
                    Continue Do
            End Select
        Loop
        If (x = 1) Then
            nox = 0
        Else
            nox += 1
        End If
        x += XSTEP(0)
        steps(n) = 1000000 * x + 10000 * p + 1000 * xpp + 100 * ypp + 10 * xfp + yfp

    End Sub

    Function KPSTEP(ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef dxp As Integer, ByRef dyp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef x As Integer)
        Dim i As Integer

        If (p <> 0) Then
            Return (9)
        End If

        If (dxp \ 2 = 0 AndAlso dyp \ 2 = 0 AndAlso fp < 49) Then
            If (fp = 1) Then
                winner = 1
            ElseIf (fp = 11) Then
                ooo(0, 1) = 9
            ElseIf (fp = 12) Then
                oo(0, 1) = 9
            End If
            Chess(0, xpp, ypp) = 0
            Chess(0, xfp, yfp) = 49
            Piece(0, 49) = 10 * xfp + yfp
            If (Piece(0, fp) <> 99) Then
                Piece(0, fp) = 99
                x = 1
            End If
            ooo(0, 0) = 9
            oo(0, 0) = 9
            Return (0)
        ElseIf (xpp = 4 AndAlso ypp = 0 AndAlso yfp = 0) Then
            If (xfp = 2 AndAlso ooo(0, 0) = 0 AndAlso Chess(0, 3, 0) = 0 AndAlso fp = 0 AndAlso Chess(0, 1, 0) = 0) Then
                For i = 2 To 4
                    If (XKSTEP(0, xpp, ypp, i, 0)) Then
                        Return (8)
                    End If
                Next

                Chess(0, 4, 0) = 0
                Chess(0, 3, 0) = 59
                Chess(0, 2, 0) = 49
                Chess(0, 0, 0) = 0
                Piece(0, 49) = 20
                Piece(0, 59) = 30
                ooo(0, 0) = 8
                oo(0, 0) = 8
                Console.WriteLine("o-o-o")
                p = 90
                Return (0)
            ElseIf (xfp = 6 AndAlso oo(0, 0) = 0 AndAlso Chess(0, 5, 0) = 0 AndAlso fp = 0) Then
                For i = 4 To 6
                    If (XKSTEP(0, xpp, ypp, i, 0)) Then
                        Return (8)
                    End If
                Next

                Chess(0, 4, 0) = 0
                Chess(0, 5, 0) = 60
                Chess(0, 6, 0) = 49
                Chess(0, 7, 0) = 0
                Piece(0, 49) = 60
                Piece(0, 60) = 50
                ooo(0, 0) = 8
                oo(0, 0) = 8
                Console.WriteLine("o-o")
                p = 91
                Return (0)
            End If
        End If

        Return (9)

    End Function

    Function RPSTEP(ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef dxp As Integer, ByRef dyp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef x As Integer)
        Dim i, j As Integer

        If (p <> 0) Then
            Return (9)
        End If

        If (dxp = 0) Then
            If (dyp > 0) Then
                i = 1
            Else
                i = -1
            End If
            For j = i To dyp - i Step i
                If (Chess(0, xpp, ypp + j) <> 0) Then
                    Return (9)
                End If
            Next
            If (fp < 49) Then
                If (fp = 1) Then
                    winner = 1
                    x = 3
                ElseIf (fp = 11) Then
                    ooo(0, 1) = 9
                ElseIf (fp = 12) Then
                    oo(0, 1) = 9
                End If
                Piece(0, pp) = 10 * xfp + yfp
                If (Piece(0, fp) <> 99) Then
                    Piece(0, fp) = 99
                    x = 1
                End If
                Chess(0, xpp, ypp) = 0
                Chess(0, xfp, yfp) = pp
                If (pp > 59) Then
                    If (xpp = 0 AndAlso ypp = 0) Then
                        ooo(0, 0) = 9
                    ElseIf (xpp = 7 AndAlso ypp = 0) Then
                        oo(0, 0) = 9
                    End If
                End If
                Return (0)
            End If
        ElseIf (dyp = 0) Then
            If (dxp > 0) Then
                i = 1
            Else
                i = -1
            End If
            For j = i To dxp - i Step i
                If (Chess(0, xpp + j, ypp) <> 0) Then
                    Return (9)
                End If
            Next
            If (fp < 49) Then
                If (fp = 1) Then
                    winner = 1
                    x = 3
                ElseIf (fp = 11) Then
                    ooo(0, 1) = 9
                ElseIf (fp = 12) Then
                    oo(0, 1) = 9
                End If
                Piece(0, pp) = 10 * xfp + yfp
                If (Piece(0, fp) <> 99) Then
                    Piece(0, fp) = 99
                    x = 1
                End If
                Chess(0, xpp, ypp) = 0
                Chess(0, xfp, yfp) = pp
                If (pp > 59) Then
                    If (xpp = 0 AndAlso ypp = 0) Then
                        ooo(0, 0) = 9
                    ElseIf (xpp = 7 AndAlso ypp = 0) Then
                        oo(0, 0) = 9
                    End If
                End If
                Return (0)
            End If
        End If

        Return (9)

    End Function

    Function BPSTEP(ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef dxp As Integer, ByRef dyp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef x As Integer)
        Dim i, j As Integer

        If (p <> 0) Then
            Return (9)
        End If


        If (dxp = dyp) Then
            If (dxp > 0) Then
                i = 1
            Else
                i = -1
            End If
            For j = i To dyp - i Step i
                If (Chess(0, xpp + j, ypp + j) <> 0) Then
                    Return (9)
                End If
            Next
            If (fp < 49) Then
                If (fp = 1) Then
                    winner = 1
                    x = 3
                ElseIf (fp = 11) Then
                    ooo(0, 1) = 9
                ElseIf (fp = 12) Then
                    oo(0, 1) = 9
                End If
                Piece(0, pp) = 10 * xfp + yfp
                If (Piece(0, fp) <> 99) Then
                    Piece(0, fp) = 99
                    x = 1
                End If
                Chess(0, xpp, ypp) = 0
                Chess(0, xfp, yfp) = pp
                Return (0)
            End If
        ElseIf (dxp = -dyp) Then
            If (dxp > 0) Then
                i = 1
            Else
                i = -1
            End If
            For j = i To dxp - i Step i
                If (Chess(0, xpp + j, ypp - j) <> 0) Then
                    Return (9)
                End If
            Next
            If (fp < 49) Then
                If (fp = 1) Then
                    winner = 1
                    x = 3
                ElseIf (fp = 11) Then
                    ooo(0, 1) = 9
                ElseIf (fp = 12) Then
                    oo(0, 1) = 9
                End If
                Piece(0, pp) = 10 * xfp + yfp
                If (Piece(0, fp) <> 99) Then
                    Piece(0, fp) = 99
                    x = 1
                End If
                Chess(0, xpp, ypp) = 0
                Chess(0, xfp, yfp) = pp
                Return (0)
            End If
        End If
        Return (9)

    End Function

    Function NPSTEP(ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef dxp As Integer, ByRef dyp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef x As Integer)

        If (p <> 0) Then
            Return (9)
        End If

        If ((Math.Abs(dxp) = 2 AndAlso Math.Abs(dyp) = 1) Or (Math.Abs(dxp) = 1 AndAlso Math.Abs(dyp) = 2)) Then
            If (fp < 49) Then
                If (fp = 1) Then
                    winner = 1
                    x = 3
                ElseIf (fp = 11) Then
                    ooo(0, 1) = 9
                ElseIf (fp = 12) Then
                    oo(0, 1) = 9
                End If
                Piece(0, pp) = 10 * xfp + yfp
                If (Piece(0, fp) <> 99) Then
                    Piece(0, fp) = 99
                    x = 1
                End If
                Chess(0, xpp, ypp) = 0
                Chess(0, xfp, yfp) = pp
                Return (0)
            End If
        End If

        Return (9)

    End Function

    Function PPSTEP(ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef dxp As Integer, ByRef dyp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef x As Integer)
        If (dxp = 0 AndAlso dyp = 1 AndAlso fp = 0) Then
            If (yfp = 7) Then
                Select Case p
                    Case 2 '=q
                        For p = 51 To 58
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 3 '=r
                        For p = 61 To 68
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 4 '=b
                        For p = 71 To 78
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 5 '=n
                        For p = 81 To 88
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case Else
                        Console.WriteLine("輸入錯誤!!!p = ?)" & vbLf)
                        Return (9)
                End Select
                Piece(0, p) = 10 * xfp + yfp
                Piece(0, pp) = 99
                Chess(0, xfp, yfp) = p
            Else
                Piece(0, pp) = 10 * xfp + yfp
                Chess(0, xfp, yfp) = pp
            End If
            Chess(0, xpp, ypp) = 0
            Return (0)
        ElseIf (Math.Abs(dxp) = 1 AndAlso dyp = 1 AndAlso fp < 49 AndAlso fp > 0) Then
            If (fp = 1) Then
                winner = 1
                x = 3
            ElseIf (fp = 11) Then
                ooo(0, 1) = 9
            ElseIf (fp = 12) Then
                oo(0, 1) = 9
            End If
            If (yfp = 7) Then
                Select Case p
                    Case 2 '=q
                        For p = 51 To 58
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 3 '=r
                        For p = 61 To 68
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 4 '=b
                        For p = 71 To 78
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case 5 '=n
                        For p = 81 To 88
                            If (Piece(0, p) = 99) Then
                                Exit Select
                            End If
                        Next
                    Case Else
                        Console.WriteLine("輸入錯誤!!!(p = ?)" & vbLf)
                        Return (9)
                End Select
                Piece(0, p) = 10 * xfp + yfp
                Piece(0, pp) = 99
                Chess(0, xfp, yfp) = p
            Else
                Piece(0, pp) = 10 * xfp + yfp
                Chess(0, xfp, yfp) = pp
            End If
            Piece(0, fp) = 99
            x = 1
            Chess(0, xpp, ypp) = 0
            Return (0)
        ElseIf (dxp = 0 AndAlso dyp = 2 AndAlso ypp = 1 AndAlso Chess(0, xpp, 2) = 0 AndAlso fp = 0) Then
            Piece(0, pp) = 10 * xfp + 3
            Chess(0, xpp, 1) = 0
            Chess(0, xfp, 3) = pp
            ep(0) = xpp
            Return (0)
        ElseIf (p = 1 AndAlso Math.Abs(dxp) = 1 AndAlso dyp = 1 AndAlso ypp = 4 AndAlso ep(1) = xfp AndAlso fp = 0) Then
            Piece(0, pp) = 10 * xfp + 5
            Piece(0, Chess(0, xfp, 4)) = 99
            Chess(0, xpp, 4) = 0
            Chess(0, xfp, 5) = pp
            Chess(0, xfp, 4) = 0
            Return (0)
        End If

        Return (9)

    End Function

    Sub PRINT()
        Dim x, y As Integer
        Console.Clear()
        Console.Write(vbLf & "     a   b   c   d   e   f   g   h ")
        If (f = 0) Then
            Console.Write(Chr(9) & "玩家" & Chr(9) & Chr(9) & "電腦")
        Else
            Console.Write(Chr(9) & "電腦" & Chr(9) & Chr(9) & "玩家")
        End If
        pn = ((n - 1) \ 2 - 16) * 2
        If (pn < 0) Then
            pn = 0
        End If
        For y = 7 To 0 Step -1
            Console.Write(vbLf & "   + - + - + - + - + - + - + - + - + ")
            PRINTSTEP()
            PRINTSTEP()
            Console.Write(vbLf & " " & y + 1 & " | ")
            For x = 0 To 7
                Select Case Chess(0, x, y)
                    Case 1
                        Console.Write("K | ")
                    Case 2 To 10
                        Console.Write("Q | ")
                    Case 11 To 20
                        Console.Write("R | ")
                    Case 21 To 30
                        Console.Write("B | ")
                    Case 31 To 40
                        Console.Write("N | ")
                    Case 41 To 48
                        Console.Write("P | ")
                    Case 49
                        Console.Write("k | ")
                    Case 50 To 58
                        Console.Write("q | ")
                    Case 59 To 68
                        Console.Write("r | ")
                    Case 69 To 78
                        Console.Write("b | ")
                    Case 79 To 88
                        Console.Write("n | ")
                    Case 89 To 96
                        Console.Write("p | ")
                    Case Else
                        Console.Write("  | ")
                End Select
            Next
            PRINTSTEP()
            PRINTSTEP()
        Next
        Console.Write(vbLf & "   + - + - + - + - + - + - + - + - + ")
        PRINTSTEP()
        PRINTSTEP()
        Console.WriteLine(vbLf)
    End Sub

    Sub PRINTSTEP()
        Dim xpp, xfp, ypp, yfp, p, x, c As Integer
        pn += 1
        If (steps(pn) <> 0) Then
            c = steps(pn) \ 2000000
            x = steps(pn) \ 1000000 Mod 2
            p = steps(pn) \ 10000 Mod 100
            xpp = steps(pn) \ 1000 Mod 10
            ypp = steps(pn) \ 100 Mod 10
            xfp = steps(pn) \ 10 Mod 10
            yfp = steps(pn) Mod 10
            Console.Write(Chr(9) & Format(pn, "000") & ".")

            If (p < 90) Then
                Console.Write(Chr(xpp + 97) & ypp + 1)
                If (x <> 0) Then
                    Console.Write("x")
                End If
                Console.Write(Chr(xfp + 97) & yfp + 1)
            End If

            Select Case p
                Case 1
                    Console.Write("ep")
                Case 3 To 10
                    Console.Write("=Q")
                Case 33 To 40
                    Console.Write("=N")
                Case 51 To 58
                    Console.Write("=q")
                Case 61 To 68
                    Console.Write("=r")
                Case 71 To 78
                    Console.Write("=b")
                Case 81 To 88
                    Console.Write("=n")
                Case 90
                    Console.Write("o-o-o")
                Case 91
                    Console.Write("o-o ")
            End Select

            Select Case c
                Case 1
                    Console.Write("+")
                Case 2
                    Console.Write("++")
            End Select
        End If
    End Sub
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Sub TEST(ByRef tn As Integer, ByRef xpp As Integer, ByRef ypp As Integer, ByRef xfp As Integer, ByRef yfp As Integer, ByRef pp As Integer, ByRef fp As Integer, ByRef p As Integer, ByRef s As Integer)
        Dim x, y As Integer
        Console.Clear()
        Console.WriteLine(tn)

        If (p < 90) Then
            Select Case pp
                Case 1
                    Console.Write("K | ")
                Case 2 To 10
                    Console.Write("Q | ")
                Case 11 To 20
                    Console.Write("R | ")
                Case 21 To 30
                    Console.Write("B | ")
                Case 31 To 40
                    Console.Write("N | ")
                Case 41 To 48
                    Console.Write("P | ")
                Case 49
                    Console.Write("k | ")
                Case 50 To 58
                    Console.Write("q | ")
                Case 59 To 68
                    Console.Write("r | ")
                Case 69 To 78
                    Console.Write("b | ")
                Case 79 To 88
                    Console.Write("n | ")
                Case 89 To 96
                    Console.Write("p | ")
            End Select

            Console.Write(Chr(xpp + 97) & ypp + 1 & Chr(xfp + 97) & yfp + 1)
        End If

        Select Case p
            Case 1
                Console.Write("ep")
            Case 3 To 10
                Console.Write("=Q")
            Case 33 To 40
                Console.Write("=N")
            Case 51 To 58
                Console.Write("=q")
            Case 61 To 68
                Console.Write("=r")
            Case 71 To 78
                Console.Write("=b")
            Case 81 To 88
                Console.Write("=n")
            Case 90
                Console.Write("o-o-o")
            Case 91
                Console.Write("o-o")
        End Select

        Select Case fp
            Case 1
                Console.Write(" | K")
            Case 2 To 10
                Console.Write(" | Q")
            Case 11 To 20
                Console.Write(" | R")
            Case 21 To 30
                Console.Write(" | B")
            Case 31 To 40
                Console.Write(" | N")
            Case 41 To 48
                Console.Write(" | P")
            Case 49
                Console.Write(" | k")
            Case 50 To 58
                Console.Write(" | q")
            Case 59 To 68
                Console.Write(" | r")
            Case 69 To 78
                Console.Write(" | b")
            Case 79 To 88
                Console.Write(" | n")
            Case 89 To 96
                Console.Write(" | p")
        End Select

        Console.Write(vbLf & "     a   b   c   d   e   f   g   h ")
        For y = 7 To 0 Step -1
            Console.Write(vbLf & "   + - + - + - + - + - + - + - + - + ")
            Console.Write(vbLf & " " & y + 1 & " | ")
            For x = 0 To 7
                Select Case Chess(tn, x, y)
                    Case 1
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("K | ")
                        Else
                            Console.Write("K*| ")
                        End If
                    Case 2 To 10
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("Q | ")
                        Else
                            Console.Write("Q*| ")
                        End If
                    Case 11 To 20
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("R | ")
                        Else
                            Console.Write("R*| ")
                        End If
                    Case 21 To 30
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("B | ")
                        Else
                            Console.Write("B*| ")
                        End If
                    Case 31 To 40
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("N | ")
                        Else
                            Console.Write("N*| ")
                        End If
                    Case 41 To 48
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("P | ")
                        Else
                            Console.Write("P*| ")
                        End If
                    Case 49
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("k | ")
                        Else
                            Console.Write("k*| ")
                        End If
                    Case 50 To 58
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("q | ")
                        Else
                            Console.Write("q*| ")
                        End If
                    Case 59 To 68
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("r | ")
                        Else
                            Console.Write("r*| ")
                        End If
                    Case 69 To 78
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("b | ")
                        Else
                            Console.Write("b*| ")
                        End If
                    Case 79 To 88
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("n | ")
                        Else
                            Console.Write("n*| ")
                        End If
                    Case 89 To 96
                        If (Piece(tn, Chess(tn, x, y)) = 10 * x + y) Then
                            Console.Write("p | ")
                        Else
                            Console.Write("p*| ")
                        End If
                    Case Else
                        Console.Write("  | ")
                End Select
            Next
        Next
        Console.WriteLine(vbLf & "   + - + - + - + - + - + - + - + - + ")
        If (tn = maxsteps OrElse fp = 1 OrElse fp = 49) Then
            Console.WriteLine("s = " & s)
        End If
        If (Console.ReadLine() = "exit") Then
            tests = 0
            Console.WriteLine("思考中......")
        End If
    End Sub '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Sub TEST2(ByVal tn As Integer, ByVal xpp As Integer, ByVal ypp As Integer, ByVal xfp As Integer, ByVal yfp As Integer, ByVal pp As Integer, ByVal fp As Integer, ByVal score As Integer, ByRef s As Integer)
        Console.Write(tn & Chr(9))
        Select Case pp
            Case 1
                Console.Write("K | ")
            Case 2 To 10
                Console.Write("Q | ")
            Case 11 To 20
                Console.Write("R | ")
            Case 21 To 30
                Console.Write("B | ")
            Case 31 To 40
                Console.Write("N | ")
            Case 41 To 48
                Console.Write("P | ")
            Case 49
                Console.Write("k | ")
            Case 50 To 58
                Console.Write("q | ")
            Case 59 To 68
                Console.Write("r | ")
            Case 69 To 78
                Console.Write("b | ")
            Case 79 To 88
                Console.Write("n | ")
            Case 89 To 96
                Console.Write("p | ")
            Case Else
                Console.Write("  | ")
        End Select
        Console.Write(Chr(xpp + 97) & ypp + 1 & Chr(xfp + 97) & yfp + 1)
        Select Case fp
            Case 1
                Console.Write(" | K")
            Case 2 To 10
                Console.Write(" | Q")
            Case 11 To 20
                Console.Write(" | R")
            Case 21 To 30
                Console.Write(" | B")
            Case 31 To 40
                Console.Write(" | N")
            Case 41 To 48
                Console.Write(" | P")
            Case 49
                Console.Write(" | k")
            Case 50 To 58
                Console.Write(" | q")
            Case 59 To 68
                Console.Write(" | r")
            Case 69 To 78
                Console.Write(" | b")
            Case 79 To 88
                Console.Write(" | n")
            Case 89 To 96
                Console.Write(" | p")
            Case Else
                Console.Write(" |  ")
        End Select
        Console.WriteLine(Chr(9) & "s = " & Format(s, "0000000") & Chr(9) & " || score = " & Format(score, "0000000"))
        If (tn <> maxsteps) Then
            If (Console.ReadLine() = "exit") Then
                tests = 0
                Console.WriteLine("思考中......")
            End If
        End If
    End Sub ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
End Module