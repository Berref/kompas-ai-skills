object Form1: TForm1
  Left = 263
  Top = 196
  AutoSize = True
  BorderIcons = [biSystemMenu]
  Caption = 'Test Graphic Interface'
  ClientHeight = 385
  ClientWidth = 245
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
    Width = 243
    Height = 24
    Caption = 'Load Graphic'
    TabOrder = 0
    OnClick = btLoadGraphicClick
  end
  object btUnloadGraphic: TButton
    Left = 0
    Top = 261
    Width = 244
    Height = 25
    Caption = 'Unload Graphic'
    TabOrder = 1
    OnClick = btUnloadGraphicClick
  end
  object btLoadFile: TButton
    Left = 0
    Top = 57
    Width = 118
    Height = 23
    Caption = 'Load File'
    TabOrder = 2
    OnClick = btLoadFileClick
  end
  object btCloseFile: TButton
    Left = 0
    Top = 226
    Width = 244
    Height = 26
    Cancel = True
    Caption = 'CloseFile'
    TabOrder = 3
    OnClick = btCloseFileClick
  end
  object btNewFile: TButton
    Left = 123
    Top = 56
    Width = 121
    Height = 24
    Caption = 'New File'
    TabOrder = 4
    OnClick = btNewFileClick
  end
  object btSaveFile: TButton
    Left = 0
    Top = 192
    Width = 243
    Height = 25
    Caption = 'Save File'
    TabOrder = 5
    OnClick = btSaveFileClick
  end
  object btLoadLibrary: TButton
    Left = 0
    Top = 90
    Width = 244
    Height = 24
    Caption = 'Load Library'
    TabOrder = 6
    OnClick = btLoadLibraryClick
  end
  object btRunLibraryCommand: TButton
    Left = 0
    Top = 122
    Width = 244
    Height = 23
    Caption = 'Run Library Command'
    TabOrder = 7
    OnClick = btRunLibraryCommandClick
  end
  object btUnloadLibrary: TButton
    Left = 0
    Top = 155
    Width = 243
    Height = 26
    Caption = 'Unload Library'
    TabOrder = 8
    OnClick = btUnloadLibraryClick
  end
  object btQuitWOUnload: TButton
    Left = 131
    Top = 293
    Width = 114
    Height = 25
    Caption = 'Quit W\O Unload'
    TabOrder = 9
    OnClick = btQuitWOUnloadClick
  end
  object btQuitUnload: TButton
    Left = 0
    Top = 295
    Width = 121
    Height = 25
    Caption = 'Quit && Unload'
    TabOrder = 10
    OnClick = btQuitUnloadClick
  end
  object ExecuteCommand: TButton
    Left = 0
    Top = 328
    Width = 244
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
    TabOrder = 11
    OnClick = ExecuteCommandClick
  end
  object btActive: TButton
    Left = 1
    Top = 28
    Width = 243
    Height = 24
    Caption = 'Active Graphic'
    TabOrder = 12
    OnClick = btActiveClick
  end
  object btVisible: TButton
    Left = 1
    Top = 360
    Width = 242
    Height = 25
    Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1074#1080#1076#1080#1084#1086#1089#1090#1100#1102
    TabOrder = 13
    OnClick = btVisibleClick
  end
  object OpenDialog1: TOpenDialog
    Left = 2
    Top = 72
  end
end
