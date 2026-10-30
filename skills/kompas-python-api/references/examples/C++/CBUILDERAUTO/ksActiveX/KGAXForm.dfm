object Form1: TForm1
  Left = 281
  Top = 175
  Caption = #1058#1077#1089#1090' '#1050#1086#1084#1087#1072#1089' ActiveX'
  ClientHeight = 436
  ClientWidth = 677
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 673
    Height = 377
    TabOrder = 0
    object KGAX1: TKGAX
      Left = 1
      Top = 1
      Width = 671
      Height = 375
      Align = alClient
      TabOrder = 0
      ControlData = {
        000001005A450000C226000012000000FFFEFF00FFFEFF0005000000FFFEFF00
        0000000000}
    end
  end
  object Button1: TButton
    Left = 8
    Top = 400
    Width = 129
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 400
    Width = 97
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1074#1089#1077
    TabOrder = 2
    OnClick = Button2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 304
    Top = 392
    Width = 369
    Height = 42
    Caption = #1058#1080#1087' '#1086#1090#1086#1073#1088#1072#1078#1077#1085#1080#1103':'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      #1050#1072#1088#1082#1072#1089
      #1041#1077#1079' '#1085#1077#1074#1080#1076#1080#1084#1099#1093' '#1083#1080#1085#1080#1081
      #1053#1077#1074#1080#1076#1080#1084#1099#1077' '#1083#1080#1085#1080#1080' '#1090#1086#1085#1082#1080#1077
      #1055#1086#1083#1091#1090#1086#1085#1086#1074#1086#1077)
    TabOrder = 3
    OnClick = RadioGroup1Click
  end
end
