object GaykaDlg: TGaykaDlg
  Left = 192
  Top = 107
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1043#1072#1081#1082#1072
  ClientHeight = 311
  ClientWidth = 386
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 6
    Top = 12
    Width = 44
    Height = 13
    Caption = #1044#1080#1072#1084#1077#1090#1088
  end
  object Ok: TButton
    Left = 8
    Top = 280
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
  end
  object cboxSpcObj: TCheckBox
    Left = 183
    Top = 171
    Width = 196
    Height = 16
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1073#1098#1077#1082#1090' '#1089#1087#1077#1094#1080#1092#1080#1082#1072#1094#1080#1080
    TabOrder = 1
    OnClick = cboxSpcObjClick
  end
  object Panel1: TPanel
    Left = 183
    Top = 8
    Width = 194
    Height = 160
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 2
    object PaintBox1: TPaintBox
      Left = 1
      Top = 1
      Width = 188
      Height = 154
      Align = alClient
      OnClick = PaintBox1Click
      OnPaint = PaintBox1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 38
    Width = 169
    Height = 128
    TabOrder = 3
    object RadioButton1: TRadioButton
      Left = 16
      Top = 24
      Width = 82
      Height = 17
      Caption = #1042#1080#1076
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 48
      Width = 88
      Height = 16
      Caption = #1042#1080#1076' '#1089#1073#1086#1082#1091
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 71
      Width = 84
      Height = 17
      Caption = #1042#1080#1076' '#1089#1074#1077#1088#1093#1091
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 17
      Top = 96
      Width = 87
      Height = 17
      Caption = #1042#1080#1076'\'#1088#1072#1079#1088#1077#1079
      TabOrder = 3
      OnClick = RadioButton4Click
    end
  end
  object canselButton: TButton
    Left = 155
    Top = 280
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 4
  end
  object ComboBox: TComboBox
    Left = 101
    Top = 10
    Width = 75
    Height = 21
    TabOrder = 5
    Text = 'ComboBox'
    OnChange = ComboBoxChange
  end
  object cboxPitch: TCheckBox
    Left = 183
    Top = 192
    Width = 90
    Height = 16
    Caption = #1064#1072#1075' '#1084#1077#1083#1082#1080#1081
    TabOrder = 6
    OnClick = cboxPitchClick
  end
  object cboxSimple: TCheckBox
    Left = 183
    Top = 214
    Width = 90
    Height = 16
    Caption = #1059#1087#1088#1086#1097#1077#1085#1086
    TabOrder = 7
    OnClick = cboxSimpleClick
  end
  object cboxAxis: TCheckBox
    Left = 183
    Top = 235
    Width = 91
    Height = 16
    Caption = #1054#1089#1100' '#1088#1080#1089#1086#1074#1072#1090#1100
    TabOrder = 8
    OnClick = cboxAxisClick
  end
  object cboxKey: TCheckBox
    Left = 8
    Top = 260
    Width = 204
    Height = 14
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1081' '#1088#1072#1079#1084#1077#1088' '#1087#1086#1076' '#1082#1083#1102#1095
    TabOrder = 9
    OnClick = cboxKeyClick
  end
  object GroupBox2: TGroupBox
    Left = 278
    Top = 187
    Width = 99
    Height = 62
    TabOrder = 10
    object rbIspoln1: TRadioButton
      Left = 4
      Top = 14
      Width = 92
      Height = 17
      Caption = #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 1'
      TabOrder = 0
      OnClick = rbIspoln1Click
    end
    object rbIspoln2: TRadioButton
      Left = 4
      Top = 35
      Width = 93
      Height = 17
      Caption = #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 2'
      TabOrder = 1
      OnClick = rbIspoln2Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 168
    Width = 169
    Height = 81
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1096#1090#1088#1080#1093#1086#1074#1082#1080
    TabOrder = 11
    object Label2: TLabel
      Left = 8
      Top = 23
      Width = 24
      Height = 13
      Caption = #1059#1075#1086#1083
    end
    object Label3: TLabel
      Left = 8
      Top = 52
      Width = 21
      Height = 13
      Caption = #1064#1072#1075
    end
    object angleEdit: TEdit
      Left = 64
      Top = 20
      Width = 97
      Height = 21
      TabOrder = 0
      OnChange = angleEditChange
    end
    object stepEdit: TEdit
      Left = 64
      Top = 49
      Width = 97
      Height = 21
      TabOrder = 1
      OnChange = stepEditChange
    end
  end
  object helpButton: TButton
    Left = 302
    Top = 280
    Width = 75
    Height = 25
    Caption = #1057#1087#1088#1072#1074#1082#1072
    TabOrder = 12
    OnClick = helpButtonClick
  end
end
