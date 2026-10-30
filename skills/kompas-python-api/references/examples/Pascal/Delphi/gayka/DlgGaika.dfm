inherited fmDlgGaika: TfmDlgGaika
  Left = 289
  Top = 168
  Caption = #1043#1072#1081#1082#1072
  ClientHeight = 338
  ClientWidth = 376
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  inherited Bevel1: TBevel
    Top = 16
    Width = 361
    Height = 281
    ExplicitTop = 16
    ExplicitWidth = 361
    ExplicitHeight = 281
  end
  object Label1: TLabel [1]
    Left = 22
    Top = 29
    Width = 47
    Height = 13
    Caption = #1044#1080#1072#1084#1077#1090#1088' '
  end
  inherited OKBtn: TButton
    Left = 78
    Top = 308
    ExplicitLeft = 78
    ExplicitTop = 308
  end
  inherited CancelBtn: TButton
    Top = 308
    ExplicitTop = 308
  end
  object HelpBtn: TButton
    Left = 238
    Top = 308
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 2
    OnClick = HelpBtnClick
  end
  object cmbDm: TComboBox
    Left = 80
    Top = 24
    Width = 74
    Height = 21
    Style = csDropDownList
    TabOrder = 3
    OnChange = cmbDmChange
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 56
    Width = 137
    Height = 89
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1096#1090#1088#1080#1093#1086#1074#1082#1080
    TabOrder = 4
    object Label2: TLabel
      Left = 16
      Top = 24
      Width = 24
      Height = 13
      Caption = #1059#1075#1086#1083
    end
    object Label3: TLabel
      Left = 16
      Top = 56
      Width = 21
      Height = 13
      Caption = #1064#1072#1075
    end
    object edAngle: TEdit
      Left = 64
      Top = 24
      Width = 57
      Height = 21
      TabOrder = 0
      Text = 'edAngle'
      OnChange = edAngleChange
    end
    object edShag: TEdit
      Left = 63
      Top = 56
      Width = 57
      Height = 21
      TabOrder = 1
      Text = 'edShag'
      OnChange = EShagChange
    end
  end
  object rgVid: TRadioGroup
    Left = 16
    Top = 152
    Width = 137
    Height = 113
    ItemIndex = 0
    Items.Strings = (
      #1042#1080#1076
      #1042#1080#1076' '#1089#1073#1086#1082#1091
      #1042#1080#1076' '#1089#1074#1077#1088#1093#1091
      #1042#1080#1076'/'#1088#1072#1079#1088#1077#1079)
    TabOrder = 5
    OnClick = EVidClick
  end
  object CheckBox1: TCheckBox
    Left = 161
    Top = 200
    Width = 97
    Height = 17
    Caption = #1064#1072#1075' '#1084#1077#1083#1082#1080#1081
    TabOrder = 6
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 160
    Top = 176
    Width = 185
    Height = 17
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1073#1098#1077#1082#1090' '#1089#1087#1077#1094#1080#1092#1080#1082#1072#1094#1080#1080
    TabOrder = 7
    OnClick = CheckBox2Click
  end
  object CheckBox3: TCheckBox
    Left = 160
    Top = 224
    Width = 97
    Height = 17
    Caption = #1059#1087#1088#1086#1097#1077#1085#1086
    TabOrder = 8
    OnClick = CheckBox3Click
  end
  object CheckBox4: TCheckBox
    Left = 160
    Top = 248
    Width = 97
    Height = 17
    Caption = #1054#1089#1100' '#1088#1080#1089#1086#1074#1072#1090#1100
    TabOrder = 9
    OnClick = CheckBox4Click
  end
  object CheckBox5: TCheckBox
    Left = 18
    Top = 273
    Width = 217
    Height = 17
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1081' '#1088#1072#1079#1084#1077#1088' '#1087#1086#1076' '#1082#1083#1102#1095
    TabOrder = 10
    OnClick = CheckBox5Click
  end
  object rgIspoln: TRadioGroup
    Left = 256
    Top = 192
    Width = 105
    Height = 65
    ItemIndex = 0
    Items.Strings = (
      #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 1'
      #1048#1089#1087#1086#1083#1085#1077#1085#1080#1077' 2')
    TabOrder = 11
    OnClick = rgIspolnClick
  end
  object Panel1: TPanel
    Left = 168
    Top = 24
    Width = 193
    Height = 137
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 12
    object PaintBox1: TPaintBox
      Left = 0
      Top = 0
      Width = 189
      Height = 133
      Align = alClient
      OnPaint = PaintBox1Paint
    end
  end
end
