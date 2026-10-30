object TestSlideDlg: TTestSlideDlg
  Left = 192
  Top = 107
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1054#1090#1088#1080#1089#1086#1074#1082#1072' '#1089#1083#1072#1081#1076#1072' '#1080#1079' Delphi'
  ClientHeight = 259
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pPreviewPanel: TPanel
    Left = 8
    Top = 8
    Width = 257
    Height = 201
    BevelInner = bvLowered
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 0
    object pPreviewBox: TPaintBox
      Left = 1
      Top = 1
      Width = 251
      Height = 195
      Align = alClient
      OnPaint = pPreviewBoxPaint
    end
  end
  object Button1: TButton
    Left = 8
    Top = 216
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 190
    Top = 216
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
  end
end
