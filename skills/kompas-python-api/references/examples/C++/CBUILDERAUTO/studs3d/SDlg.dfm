object ShpeelDlg: TShpeelDlg
  Left = 146
  Top = 73
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1064#1087#1080#1083#1100#1082#1080
  ClientHeight = 364
  ClientWidth = 368
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label4: TLabel
    Left = 180
    Top = 220
    Width = 50
    Height = 13
    Caption = #1052#1072#1090#1077#1088#1080#1072#1083
  end
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 160
    Height = 13
    Caption = #1044#1083#1080#1085#1072' '#1074#1074#1080#1085#1095#1080#1074#1072#1077#1084#1086#1075#1086' '#1082#1086#1085#1094#1072' b1'
  end
  object Label5: TLabel
    Left = 8
    Top = 192
    Width = 79
    Height = 13
    Caption = #1050#1083#1072#1089#1089' '#1090#1086#1095#1085#1086#1089#1090#1080
  end
  object Label6: TLabel
    Left = 180
    Top = 192
    Width = 27
    Height = 13
    Caption = #1043#1054#1057#1058
  end
  object Ok: TButton
    Left = 8
    Top = 333
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
  end
  object cboxSpcObj: TCheckBox
    Left = 8
    Top = 244
    Width = 195
    Height = 16
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1073#1098#1077#1082#1090' '#1089#1087#1077#1094#1080#1092#1080#1082#1072#1094#1080#1080
    TabOrder = 1
    OnClick = cboxSpcObjClick
  end
  object Panel1: TPanel
    Left = 180
    Top = 32
    Width = 181
    Height = 145
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 2
    object PaintBox1: TPaintBox
      Left = 1
      Top = 1
      Width = 175
      Height = 139
      Align = alClient
      OnClick = PaintBox1Click
      OnPaint = PaintBox1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 28
    Width = 161
    Height = 81
    TabOrder = 3
    object Label1: TLabel
      Left = 10
      Top = 24
      Width = 44
      Height = 13
      Caption = #1044#1080#1072#1084#1077#1090#1088
    end
    object Label2: TLabel
      Left = 10
      Top = 52
      Width = 32
      Height = 13
      Caption = #1044#1083#1080#1085#1072
    end
  end
  object canselButton: TButton
    Left = 155
    Top = 333
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 4
  end
  object ComboBox: TComboBox
    Left = 81
    Top = 50
    Width = 71
    Height = 21
    TabOrder = 5
    Text = 'ComboBox'
    OnChange = ComboBoxChange
  end
  object helpButton: TButton
    Left = 289
    Top = 333
    Width = 74
    Height = 25
    Caption = #1057#1087#1088#1072#1074#1082#1072
    TabOrder = 6
    OnClick = helpButtonClick
  end
  object ComboBox1: TComboBox
    Left = 248
    Top = 216
    Width = 113
    Height = 21
    TabOrder = 7
    Text = 'ComboBox1'
    OnChange = ComboBox1Change
  end
  object StringGrid1: TStringGrid
    Left = 7
    Top = 267
    Width = 354
    Height = 57
    DefaultColWidth = 39
    DefaultRowHeight = 19
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    TabOrder = 8
    ColWidths = (
      70
      70
      61
      61
      61)
  end
  object ComboBox2: TComboBox
    Left = 81
    Top = 78
    Width = 70
    Height = 21
    TabOrder = 9
    Text = 'ComboBox2'
    OnChange = ComboBox2Change
  end
  object ComboBox3: TComboBox
    Left = 180
    Top = 4
    Width = 73
    Height = 21
    TabOrder = 10
    Text = 'ComboBox3'
    OnChange = ComboBox3Change
  end
  object ComboBox4: TComboBox
    Left = 100
    Top = 188
    Width = 69
    Height = 21
    TabOrder = 11
    Text = 'ComboBox4'
    OnChange = ComboBox4Change
  end
  object ComboBox5: TComboBox
    Left = 248
    Top = 188
    Width = 113
    Height = 21
    TabOrder = 12
    Text = 'ComboBox5'
    OnChange = ComboBox5Change
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 216
    Width = 97
    Height = 17
    Caption = #1052#1077#1083#1082#1080#1081' '#1096#1072#1075
    TabOrder = 13
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 248
    Top = 244
    Width = 97
    Height = 17
    Caption = #1059#1087#1088#1086#1097#1077#1085#1085#1086
    TabOrder = 14
    OnClick = CheckBox2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 112
    Width = 161
    Height = 65
    Items.Strings = (
      #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 1'
      #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 2')
    TabOrder = 15
    OnClick = RadioGroup1Click
  end
end
