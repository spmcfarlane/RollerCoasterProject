PCBNEW-LibModule-V1  11/27/2016 3:44:59 PM
# encoding utf-8
Units mm
$INDEX
TERM_STRIP_4x1
connect-PAD-02
sot23
xbee_r1-XBEE
$EndINDEX
$MODULE TERM_STRIP_4x1
Po 0 0 0 15 580050EB 00000000 ~~
Li TERM_STRIP_4x1
Cd Double rangee de contacts 2 x 5 pins
Kw CONN
Sc 0
AR /54149342
Op 0 0 0
T0 0 -2.54 1.016 1.016 0 0.2032 N V 21 N "P1"
T1 0 2.54 1.016 1.016 0 0.2032 N I 21 N "CONN_4"
DS -5.842 3.302 5.842 3.302 0.15 21
DS 5.842 3.302 5.842 -3.302 0.15 21
DS 5.842 -3.302 -5.842 -3.302 0.15 21
DS -5.842 -3.302 -5.842 3.302 0.15 21
DS 5.08 1.27 -5.08 1.27 0.254 21
DS 5.08 -1.27 -5.08 -1.27 0.254 21
DS -5.08 -1.27 -5.08 1.27 0.254 21
DS 5.08 1.27 5.08 -1.27 0.254 21
$PAD
Sh "1" R 2.032 2.032 0 0 0
Dr 1.524 0 0
At STD N 00E0FFFF
Ne 1 "GND"
Po -3.81 0
$EndPAD
$PAD
Sh "2" C 2.032 2.032 0 0 0
Dr 1.524 0 0
At STD N 00E0FFFF
Ne 3 "SPEED_IN"
Po -1.27 0
$EndPAD
$PAD
Sh "3" C 2.032 2.032 0 0 0
Dr 1.524 0 0
At STD N 00E0FFFF
Ne 1 "GND"
Po 1.27 0
$EndPAD
$PAD
Sh "4" C 2.032 2.032 0 0 0
Dr 1.524 0 0
At STD N 00E0FFFF
Ne 2 "N-0000014"
Po 3.81 0
$EndPAD
$SHAPE3D
Na "pin_array\\pins_array_4x1.wrl"
Sc 1 1 1
Of 0 0 0
Ro 0 0 0
$EndSHAPE3D
$EndMODULE TERM_STRIP_4x1
$MODULE connect-PAD-02
Po 0 0 0 15 5832001E 00000000 ~~
Li connect-PAD-02
Sc 0
AR /5414844F
Op 0 0 0
At VIRTUAL
T0 -5.08 0 1.27 1.27 900 0.0889 N V 20 N "JP4"
T1 2.54 -4.445 1.27 1.27 0 0.0889 N I 20 N "JUMPER"
DC 2.54 0 2.9845 0.4445 0.381 21
DC 0 0 -0.4445 0.4445 0.381 21
$PAD
Sh "1" C 1.524 1.524 0 0 0
Dr 0.889 0 0
At STD N 00A8FFFF
Ne 1 "D_TX"
Po 0 0
$EndPAD
$PAD
Sh "2" C 1.524 1.524 0 0 0
Dr 0.889 0 0
At STD N 00A8FFFF
Ne 2 "OUT"
Po 2.54 0
$EndPAD
$EndMODULE connect-PAD-02
$MODULE sot23
Po 0 0 0 15 54222007 00000000 ~~
Li sot23
Cd SOT23
Sc 0
AR 
Op 0 0 0
At SMD
T0 0 0 0.50038 0.50038 0 0.09906 N V 21 N "SOT23"
T1 0 0.09906 0.50038 0.50038 0 0.09906 N I 21 N "Q***"
DS 0.9525 0.6985 0.9525 1.3589 0.127 21
DS -0.9525 0.6985 -0.9525 1.3589 0.127 21
DS 0 -0.6985 0 -1.3589 0.127 21
DS -1.4986 -0.6985 1.4986 -0.6985 0.127 21
DS 1.4986 -0.6985 1.4986 0.6985 0.127 21
DS 1.4986 0.6985 -1.4986 0.6985 0.127 21
DS -1.4986 0.6985 -1.4986 -0.6985 0.127 21
$PAD
Sh "G" R 0.59944 1.00076 0 0 0
Dr 0 0 0
At SMD N 00888000
Ne 0 ""
Po -0.9525 1.05664
$EndPAD
$PAD
Sh "D" R 0.59944 1.00076 0 0 0
Dr 0 0 0
At SMD N 00888000
Ne 0 ""
Po 0 -1.05664
$EndPAD
$PAD
Sh "S" R 0.59944 1.00076 0 0 0
Dr 0 0 0
At SMD N 00888000
Ne 0 ""
Po 0.9525 1.05664
$EndPAD
$SHAPE3D
Na "smd/smd_transistors/sot23.wrl"
Sc 1 1 1
Of 0 0 0
Ro 0 0 0
$EndSHAPE3D
$EndMODULE sot23
$MODULE xbee_r1-XBEE
Po 0 0 0 15 58004A57 00000000 ~~
Li xbee_r1-XBEE
Sc 0
AR /538038E3
Op 0 0 0
At VIRTUAL
T0 13.335 -14.859 1.778 1.778 0 0.0889 N V 20 N "U2"
T1 0 0 1.524 1.524 0 0.15 N V 21 N "XBEE"
DS -12.192 10.88644 12.192 10.88644 0.1778 21
DS 12.192 10.88644 12.192 -9.398 0.1778 21
DS 12.192 -9.398 4.86664 -16.72082 0.1778 21
DS 4.86664 -16.72082 -4.86664 -16.72082 0.1778 21
DS -4.86664 -16.72082 -12.192 -9.398 0.1778 21
DS -12.192 -9.398 -12.192 10.88644 0.1778 21
DS -12.192 10.88644 12.192 10.88644 0.127 21
DS 12.192 10.88644 12.192 -9.398 0.127 21
DS 12.192 -9.398 4.86664 -16.72082 0.127 21
DS 4.86664 -16.72082 -4.86664 -16.72082 0.127 21
DS -4.86664 -16.72082 -12.192 -9.398 0.127 21
DS -12.192 -9.398 -12.192 10.88644 0.127 21
$PAD
Sh "1" R 1.1684 0 0 0 0
Dr 0.6604 0 0
At STD N 00A8FFFF
Ne 1 "+3.3V"
Po -10.9982 -8.99922
$EndPAD
$PAD
Sh "2" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 4 "DOUT"
Po -10.9982 -6.9977
$EndPAD
$PAD
Sh "3" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 2 "DIN"
Po -10.9982 -4.99872
$EndPAD
$PAD
Sh "4" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po -10.9982 -2.99974
$EndPAD
$PAD
Sh "5" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po -10.9982 -0.99822
$EndPAD
$PAD
Sh "6" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 6 "RSSI"
Po -10.9982 0.99822
$EndPAD
$PAD
Sh "7" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po -10.9982 2.99974
$EndPAD
$PAD
Sh "8" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po -10.9982 4.99872
$EndPAD
$PAD
Sh "9" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po -10.9982 6.9977
$EndPAD
$PAD
Sh "10" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 5 "GND"
Po -10.9982 8.99922
$EndPAD
$PAD
Sh "11" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 8.99922
$EndPAD
$PAD
Sh "12" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 6.9977
$EndPAD
$PAD
Sh "13" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 4.99872
$EndPAD
$PAD
Sh "14" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 2.99974
$EndPAD
$PAD
Sh "15" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 3 "DIO5"
Po 10.9982 0.99822
$EndPAD
$PAD
Sh "16" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 -0.99822
$EndPAD
$PAD
Sh "17" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 -2.99974
$EndPAD
$PAD
Sh "18" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 -4.99872
$EndPAD
$PAD
Sh "19" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 -6.9977
$EndPAD
$PAD
Sh "20" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 0 ""
Po 10.9982 -8.99922
$EndPAD
$PAD
Sh "1" C 1.524 1.524 0 0 0
Dr 1.016 0 0
At STD N 00A8FFFF
Ne 1 "+3.3V"
Po -10.9855 -9.017
$EndPAD
$EndMODULE xbee_r1-XBEE
$EndLIBRARY
