object SlideForm: TSlideForm
  Left = 192
  Top = 104
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1058#1077#1089#1090' '#1057#1083#1072#1081#1076#1072
  ClientHeight = 228
  ClientWidth = 187
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
    Top = 6
    Width = 169
    Height = 179
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    BevelInner = bvLowered
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 1
    object pPreviewBox: TPaintBox
      Left = 1
      Top = 1
      Width = 164
      Height = 175
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alClient
      OnPaint = pPreviewBoxPaint
    end
  end
  object closeButton: TButton
    Left = 9
    Top = 194
    Width = 75
    Height = 25
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Cancel = True
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 0
  end
end
