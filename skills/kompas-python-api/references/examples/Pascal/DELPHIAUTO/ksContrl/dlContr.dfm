object Form1: TForm1
  Left = -2
  Top = 228
  AutoSize = True
  Caption = 'Test Graphic Interface'
  ClientHeight = 377
  ClientWidth = 234
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
  object btLoadGraphic: TButton
    Left = 1
    Top = 0
    Width = 233
    Height = 25
    Caption = 'Load Graphic'
    TabOrder = 0
    OnClick = btLoadGraphicClick
  end
  object btQuitUnload: TButton
    Left = 122
    Top = 286
    Width = 112
    Height = 25
    Caption = 'Quit && Unload '
    TabOrder = 1
    OnClick = btQuitUnloadClick
  end
  object btQuitWoUnload: TButton
    Left = 3
    Top = 285
    Width = 115
    Height = 25
    Caption = 'Quit W\O Unload'
    TabOrder = 2
    OnClick = btQuitWoUnloadClick
  end
  object btUnloadGraphic: TButton
    Left = 2
    Top = 254
    Width = 232
    Height = 25
    Caption = 'Unload Graphic'
    TabOrder = 3
    OnClick = btUnloadGraphicClick
  end
  object btLoadFile: TButton
    Left = 1
    Top = 56
    Width = 112
    Height = 25
    Caption = 'Load File'
    TabOrder = 4
    OnClick = btLoadFileClick
  end
  object btNewFile: TButton
    Left = 122
    Top = 56
    Width = 112
    Height = 25
    Caption = 'New File'
    TabOrder = 5
    OnClick = btNewFileClick
  end
  object btLoadLibrary: TButton
    Left = 2
    Top = 88
    Width = 232
    Height = 25
    Caption = 'Load Library'
    TabOrder = 6
    OnClick = btLoadLibraryClick
  end
  object btRunLibCommand: TButton
    Left = 2
    Top = 120
    Width = 232
    Height = 25
    Caption = 'Run Library Command'
    TabOrder = 7
    OnClick = btRunLibCommandClick
  end
  object btUnloadLibrary: TButton
    Left = 1
    Top = 152
    Width = 233
    Height = 25
    Caption = 'Unload Library'
    TabOrder = 8
    OnClick = btUnloadLibraryClick
  end
  object btSaveFile: TButton
    Left = 0
    Top = 184
    Width = 234
    Height = 25
    Caption = 'Save File'
    TabOrder = 9
    OnClick = btSaveFileClick
  end
  object btCloseFile: TButton
    Left = 0
    Top = 216
    Width = 234
    Height = 25
    Caption = 'Close File'
    TabOrder = 10
    OnClick = btCloseFileClick
  end
  object ExecuteCommand: TButton
    Left = 2
    Top = 320
    Width = 232
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
    TabOrder = 11
    OnClick = ExecuteCommandClick
  end
  object btActive: TButton
    Left = 1
    Top = 27
    Width = 233
    Height = 25
    Caption = 'Get Active'
    TabOrder = 12
    OnClick = btActiveClick
  end
  object btVisible: TButton
    Left = 2
    Top = 352
    Width = 232
    Height = 25
    Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1074#1080#1076#1080#1084#1086#1089#1090#1100#1102
    TabOrder = 13
    OnClick = btVisibleClick
  end
  object OpenDialog1: TOpenDialog
    Left = 200
    Top = 96
  end
end
