object Form1: TForm1
  Left = 0
  Top = 0
  ClientHeight = 669
  ClientWidth = 968
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 705
    Height = 505
  end
  object BitBtn2: TBitBtn
    Left = 779
    Top = 617
    Width = 145
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 0
    OnClick = BitBtn2Click
  end
  object GroupBox1: TGroupBox
    Left = 719
    Top = 3
    Width = 243
    Height = 595
    Caption = #1057#1094#1077#1085#1072
    TabOrder = 1
    object Label28: TLabel
      Left = 11
      Top = 427
      Width = 97
      Height = 13
      Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1099'(x,y,z)'
    end
    object Label29: TLabel
      Left = 3
      Top = 452
      Width = 109
      Height = 13
      Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100'(r,g,b)'
    end
    object Label2: TLabel
      Left = 16
      Top = 16
      Width = 39
      Height = 13
      Caption = #1052#1086#1076#1077#1083#1080
    end
    object Label3: TLabel
      Left = 16
      Top = 302
      Width = 86
      Height = 13
      Caption = #1048#1089#1090#1086#1095#1085#1080#1082#1080' '#1089#1074#1077#1090#1072
    end
    object Label27: TLabel
      Left = 11
      Top = 513
      Width = 168
      Height = 13
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1088#1072#1089#1089#1077#1103#1085#1085#1086#1075#1086' '#1089#1074#1077#1090#1072
    end
    object ListBox1: TListBox
      Left = 10
      Top = 35
      Width = 230
      Height = 94
      ItemHeight = 13
      Items.Strings = (
        '')
      TabOrder = 0
      OnClick = ListBox1Click
    end
    object PageControl1: TPageControl
      Left = 10
      Top = 135
      Width = 230
      Height = 156
      ActivePage = TabSheet1
      TabOrder = 1
      object TabSheet1: TTabSheet
        Caption = #1057#1092#1077#1088#1072
        object Label6: TLabel
          Left = 3
          Top = 5
          Width = 65
          Height = 13
          Caption = #1062#1077#1085#1090#1088'(x,y,z)'
        end
        object Label7: TLabel
          Left = 3
          Top = 60
          Width = 36
          Height = 13
          Caption = #1056#1072#1076#1080#1091#1089
        end
        object Label8: TLabel
          Left = 3
          Top = 33
          Width = 58
          Height = 13
          Caption = #1062#1074#1077#1090'(r,g,b)'
        end
        object Label9: TLabel
          Left = 114
          Top = 60
          Width = 12
          Height = 13
          Caption = 'Kd'
        end
        object Label10: TLabel
          Left = 163
          Top = 60
          Width = 11
          Height = 13
          Caption = 'Ks'
        end
        object BitBtn8: TBitBtn
          Left = 79
          Top = 104
          Width = 66
          Height = 21
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnClick = BitBtn8Click
        end
        object Edit1: TEdit
          Left = 74
          Top = 3
          Width = 23
          Height = 21
          TabOrder = 1
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit2: TEdit
          Left = 103
          Top = 3
          Width = 23
          Height = 21
          TabOrder = 2
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit3: TEdit
          Left = 132
          Top = 3
          Width = 23
          Height = 21
          TabOrder = 3
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit4: TEdit
          Left = 74
          Top = 57
          Width = 23
          Height = 21
          TabOrder = 4
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit5: TEdit
          Left = 74
          Top = 30
          Width = 23
          Height = 21
          TabOrder = 5
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit6: TEdit
          Left = 103
          Top = 30
          Width = 23
          Height = 21
          TabOrder = 6
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit7: TEdit
          Left = 132
          Top = 30
          Width = 23
          Height = 21
          TabOrder = 7
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit8: TEdit
          Left = 132
          Top = 57
          Width = 25
          Height = 21
          TabOrder = 8
          Text = '0,5'
          OnKeyPress = KeyPress
        end
        object Edit9: TEdit
          Left = 177
          Top = 57
          Width = 23
          Height = 21
          TabOrder = 9
          Text = '0,5'
          OnKeyPress = KeyPress
        end
        object BitBtn13: TBitBtn
          Left = 3
          Top = 104
          Width = 70
          Height = 21
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 10
          OnClick = BitBtn13Click
        end
        object BitBtn19: TBitBtn
          Left = 151
          Top = 104
          Width = 68
          Height = 21
          Caption = #1059#1076#1072#1083#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 11
          OnClick = BitBtn7Click
        end
      end
      object TabSheet2: TTabSheet
        Caption = #1069#1083#1083#1080#1087#1089#1086#1080#1076
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label11: TLabel
          Left = 3
          Top = 3
          Width = 65
          Height = 13
          Caption = #1062#1077#1085#1090#1088'(x,y,z)'
        end
        object Label12: TLabel
          Left = 3
          Top = 30
          Width = 42
          Height = 13
          Caption = #1055#1086#1083#1091#1086#1089#1080
        end
        object Label13: TLabel
          Left = 3
          Top = 57
          Width = 58
          Height = 13
          Caption = #1062#1074#1077#1090'(r,g,b)'
        end
        object Label14: TLabel
          Left = 163
          Top = 19
          Width = 12
          Height = 13
          Caption = 'Kd'
        end
        object Label15: TLabel
          Left = 163
          Top = 46
          Width = 11
          Height = 13
          Caption = 'Ks'
        end
        object BitBtn9: TBitBtn
          Left = 75
          Top = 104
          Width = 70
          Height = 21
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnClick = BitBtn9Click
        end
        object Edit10: TEdit
          Left = 74
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 1
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit11: TEdit
          Left = 103
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 2
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit12: TEdit
          Left = 132
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 3
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit13: TEdit
          Left = 74
          Top = 27
          Width = 23
          Height = 21
          TabOrder = 4
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit14: TEdit
          Left = 103
          Top = 27
          Width = 23
          Height = 21
          TabOrder = 5
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit15: TEdit
          Left = 132
          Top = 27
          Width = 23
          Height = 21
          TabOrder = 6
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit16: TEdit
          Left = 74
          Top = 54
          Width = 23
          Height = 21
          TabOrder = 7
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit17: TEdit
          Left = 103
          Top = 54
          Width = 23
          Height = 21
          TabOrder = 8
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit18: TEdit
          Left = 132
          Top = 54
          Width = 23
          Height = 21
          TabOrder = 9
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit19: TEdit
          Left = 179
          Top = 16
          Width = 24
          Height = 21
          TabOrder = 10
          Text = '0,5'
          OnKeyPress = KeyPress
        end
        object Edit20: TEdit
          Left = 178
          Top = 43
          Width = 25
          Height = 21
          TabOrder = 11
          Text = '0,5'
          OnKeyPress = KeyPress2
        end
        object BitBtn12: TBitBtn
          Left = 3
          Top = 104
          Width = 66
          Height = 21
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 12
          OnClick = BitBtn12Click
        end
        object BitBtn18: TBitBtn
          Left = 151
          Top = 104
          Width = 68
          Height = 21
          Caption = #1059#1076#1072#1083#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 13
          OnClick = BitBtn7Click
        end
      end
      object TabSheet3: TTabSheet
        Caption = #1043#1080#1087#1077#1088#1073#1086#1083#1086#1080#1076
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label17: TLabel
          Left = 3
          Top = 3
          Width = 65
          Height = 13
          Caption = #1062#1077#1085#1090#1088'(x,y,z)'
        end
        object Label18: TLabel
          Left = 3
          Top = 28
          Width = 42
          Height = 13
          Caption = #1055#1086#1083#1091#1086#1089#1080
        end
        object Label19: TLabel
          Left = 3
          Top = 53
          Width = 58
          Height = 13
          Caption = #1062#1074#1077#1090'(r,g,b)'
        end
        object Label20: TLabel
          Left = 161
          Top = 3
          Width = 12
          Height = 13
          Caption = 'Kd'
        end
        object Label21: TLabel
          Left = 162
          Top = 28
          Width = 11
          Height = 13
          Caption = 'Ks'
        end
        object Label22: TLabel
          Left = 3
          Top = 78
          Width = 37
          Height = 13
          Caption = #1042#1099#1089#1086#1090#1072
        end
        object Label30: TLabel
          Left = 82
          Top = 78
          Width = 73
          Height = 13
          Caption = #1054#1089#1100' '#1074#1088#1072#1097#1077#1085#1080#1103
        end
        object BitBtn10: TBitBtn
          Left = 79
          Top = 104
          Width = 67
          Height = 21
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 0
          OnClick = BitBtn10Click
        end
        object BitBtn11: TBitBtn
          Left = 3
          Top = 104
          Width = 70
          Height = 21
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 1
          OnClick = BitBtn11Click
        end
        object Edit22: TEdit
          Left = 74
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 2
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit23: TEdit
          Left = 103
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 3
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit24: TEdit
          Left = 132
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 4
          Text = '0'
          OnKeyPress = KeyPress
        end
        object Edit25: TEdit
          Left = 74
          Top = 25
          Width = 23
          Height = 21
          TabOrder = 5
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit26: TEdit
          Left = 103
          Top = 25
          Width = 23
          Height = 21
          TabOrder = 6
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit27: TEdit
          Left = 132
          Top = 25
          Width = 23
          Height = 21
          TabOrder = 7
          Text = '50'
          OnKeyPress = KeyPress
        end
        object Edit28: TEdit
          Left = 74
          Top = 50
          Width = 23
          Height = 21
          TabOrder = 8
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit29: TEdit
          Left = 103
          Top = 51
          Width = 23
          Height = 21
          TabOrder = 9
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit30: TEdit
          Left = 132
          Top = 50
          Width = 23
          Height = 21
          TabOrder = 10
          Text = '0'
          OnKeyPress = KeyPress2
        end
        object Edit31: TEdit
          Left = 179
          Top = 0
          Width = 23
          Height = 21
          TabOrder = 11
          Text = '0,5'
        end
        object Edit32: TEdit
          Left = 179
          Top = 25
          Width = 23
          Height = 21
          TabOrder = 12
          Text = '0,5'
        end
        object ComboBox1: TComboBox
          Left = 161
          Top = 77
          Width = 40
          Height = 21
          ItemIndex = 2
          TabOrder = 13
          Text = 'Z'
          Items.Strings = (
            'X'
            'Y'
            'Z')
        end
        object Edit33: TEdit
          Left = 46
          Top = 75
          Width = 23
          Height = 21
          TabOrder = 14
          Text = '200'
          OnKeyPress = KeyPress
        end
        object BitBtn7: TBitBtn
          Left = 151
          Top = 104
          Width = 68
          Height = 21
          Caption = #1059#1076#1072#1083#1080#1090#1100
          DoubleBuffered = True
          ParentDoubleBuffered = False
          TabOrder = 15
          OnClick = BitBtn7Click
        end
      end
    end
    object BitBtn15: TBitBtn
      Left = 87
      Top = 479
      Width = 66
      Height = 23
      Caption = #1059#1076#1072#1083#1080#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 2
      OnClick = BitBtn15Click
    end
    object Edit40: TEdit
      Left = 114
      Top = 425
      Width = 23
      Height = 21
      TabOrder = 3
      Text = '0'
      OnKeyPress = KeyPress
    end
    object Edit41: TEdit
      Left = 143
      Top = 425
      Width = 23
      Height = 21
      TabOrder = 4
      Text = '0'
      OnKeyPress = KeyPress
    end
    object Edit42: TEdit
      Left = 172
      Top = 425
      Width = 23
      Height = 21
      TabOrder = 5
      Text = '0'
      OnKeyPress = KeyPress
    end
    object Edit43: TEdit
      Left = 172
      Top = 452
      Width = 23
      Height = 21
      TabOrder = 6
      Text = '0'
      OnKeyPress = KeyPress2
    end
    object Edit44: TEdit
      Left = 143
      Top = 452
      Width = 23
      Height = 21
      TabOrder = 7
      Text = '0'
      OnKeyPress = KeyPress2
    end
    object Edit45: TEdit
      Left = 114
      Top = 452
      Width = 23
      Height = 21
      TabOrder = 8
      Text = '0'
      OnKeyPress = KeyPress2
    end
    object BitBtn16: TBitBtn
      Left = 159
      Top = 479
      Width = 75
      Height = 23
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 9
      OnClick = BitBtn16Click
    end
    object BitBtn17: TBitBtn
      Left = 11
      Top = 479
      Width = 70
      Height = 23
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 10
      OnClick = BitBtn17Click
    end
    object ListBox2: TListBox
      Left = 11
      Top = 321
      Width = 229
      Height = 100
      ItemHeight = 13
      TabOrder = 11
      OnClick = ListBox2Click
    end
    object Edit39: TEdit
      Left = 185
      Top = 508
      Width = 23
      Height = 21
      TabOrder = 12
      OnKeyPress = KeyPress
    end
    object Button1: TButton
      Left = 61
      Top = 532
      Width = 118
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
      TabOrder = 13
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 61
      Top = 563
      Width = 118
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1080#1079' '#1092#1072#1081#1083#1072
      TabOrder = 14
      OnClick = Button2Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 519
    Width = 705
    Height = 146
    Caption = #1054#1090#1086#1073#1088#1072#1078#1077#1085#1080#1077
    TabOrder = 2
    object Label1: TLabel
      Left = 170
      Top = 93
      Width = 3
      Height = 13
    end
    object Label16: TLabel
      Left = 212
      Top = 73
      Width = 116
      Height = 13
      Caption = #1059#1075#1086#1083' '#1087#1086#1074#1086#1088#1086#1090#1072' '#1082#1072#1084#1077#1088#1099
    end
    object Label23: TLabel
      Left = 12
      Top = 94
      Width = 131
      Height = 13
      Caption = #1055#1086#1083#1086#1078#1077#1085#1080#1077' '#1082#1072#1084#1077#1088#1099'(x,y,z)'
    end
    object Label24: TLabel
      Left = 12
      Top = 21
      Width = 176
      Height = 13
      Caption = #1059#1075#1083#1099' '#1085#1072#1082#1083#1086#1085#1072' '#1101#1082#1088#1072#1085#1085#1086#1081' '#1087#1083#1086#1089#1082#1086#1089#1090#1080
    end
    object Label25: TLabel
      Left = 12
      Top = 40
      Width = 70
      Height = 13
      Caption = #1055#1086' '#1074#1077#1088#1090#1080#1082#1072#1083#1080
    end
    object Label26: TLabel
      Left = 12
      Top = 67
      Width = 80
      Height = 13
      Caption = #1055#1086' '#1075#1086#1088#1080#1079#1086#1085#1090#1072#1083#1080
    end
    object Label31: TLabel
      Left = 342
      Top = 21
      Width = 92
      Height = 13
      Caption = #1043#1083#1091#1073#1080#1085#1072' '#1088#1077#1082#1091#1088#1089#1080#1080
    end
    object Label4: TLabel
      Left = 530
      Top = 56
      Width = 99
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1100#1085#1072#1103' '#1075#1083#1091#1073#1080#1085#1072
    end
    object Label5: TLabel
      Left = 531
      Top = 83
      Width = 93
      Height = 13
      Caption = #1050#1086#1085#1077#1095#1085#1072#1103' '#1075#1083#1091#1073#1080#1085#1072
    end
    object Label32: TLabel
      Left = 531
      Top = 110
      Width = 21
      Height = 13
      Caption = #1064#1072#1075
    end
    object BitBtn1: TBitBtn
      Left = 249
      Top = 112
      Width = 115
      Height = 27
      Caption = #1056#1077#1085#1076#1077#1088#1080#1085#1075
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn3: TBitBtn
      Left = 285
      Top = 11
      Width = 43
      Height = 25
      Caption = '^'
      DoubleBuffered = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn3Click
    end
    object BitBtn4: TBitBtn
      Left = 285
      Top = 42
      Width = 43
      Height = 25
      Caption = 'v'
      DoubleBuffered = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 2
      OnClick = BitBtn4Click
    end
    object BitBtn5: TBitBtn
      Left = 334
      Top = 41
      Width = 43
      Height = 25
      Caption = '>'
      DoubleBuffered = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 3
      OnClick = BitBtn5Click
    end
    object BitBtn6: TBitBtn
      Left = 236
      Top = 41
      Width = 43
      Height = 25
      Caption = '<'
      DoubleBuffered = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 4
      OnClick = BitBtn6Click
    end
    object Edit21: TEdit
      Left = 342
      Top = 72
      Width = 22
      Height = 21
      TabOrder = 5
      Text = '10'
      OnKeyPress = KeyPress2
    end
    object Edit34: TEdit
      Left = 30
      Top = 113
      Width = 23
      Height = 21
      TabOrder = 6
      OnKeyPress = KeyPress
    end
    object Edit35: TEdit
      Left = 59
      Top = 113
      Width = 23
      Height = 21
      TabOrder = 7
      OnKeyPress = KeyPress
    end
    object Edit36: TEdit
      Left = 98
      Top = 113
      Width = 23
      Height = 21
      TabOrder = 8
      OnKeyPress = KeyPress
    end
    object Edit37: TEdit
      Left = 98
      Top = 67
      Width = 23
      Height = 21
      TabOrder = 9
      OnKeyPress = KeyPress2
    end
    object Edit38: TEdit
      Left = 98
      Top = 40
      Width = 23
      Height = 21
      TabOrder = 10
      OnKeyPress = KeyPress2
    end
    object BitBtn14: TBitBtn
      Left = 149
      Top = 112
      Width = 75
      Height = 25
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 11
      OnClick = BitBtn14Click
    end
    object Edit46: TEdit
      Left = 440
      Top = 13
      Width = 23
      Height = 21
      TabOrder = 12
      OnKeyPress = KeyPress2
    end
    object Edit47: TEdit
      Left = 635
      Top = 56
      Width = 59
      Height = 21
      TabOrder = 13
      Text = '0'
    end
    object Edit48: TEdit
      Left = 636
      Top = 83
      Width = 58
      Height = 21
      TabOrder = 14
      Text = '10'
    end
    object Button3: TButton
      Left = 550
      Top = 14
      Width = 114
      Height = 25
      Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
      TabOrder = 15
      OnClick = Button3Click
    end
    object Edit49: TEdit
      Left = 635
      Top = 110
      Width = 58
      Height = 21
      TabOrder = 16
      Text = '2'
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = #1057#1094#1077#1085#1072'|*.scn'
    Left = 736
    Top = 536
  end
  object OpenDialog1: TOpenDialog
    Filter = #1057#1094#1077#1085#1072'|*.scn'
    Left = 920
    Top = 536
  end
end
