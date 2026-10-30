object TestSlideDlg: TTestSlideDlg
  Left = 192
  Top = 107
  ClientHeight = 240
  ClientWidth = 251
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object pPreviewPanel: TPanel
    Left = 8
    Top = 8
    Width = 241
    Height = 193
    BevelInner = bvLowered
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 0
    object pPreviewBox: TPaintBox
      Left = 1
      Top = 1
      Width = 235
      Height = 187
      Align = alClient
      OnPaint = pPreviewBoxPaint
    end
  end
  object OkButton: TButton
    Left = 8
    Top = 216
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 1
  end
  object canselButton: TButton
    Left = 174
    Top = 216
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 2
  end
end
