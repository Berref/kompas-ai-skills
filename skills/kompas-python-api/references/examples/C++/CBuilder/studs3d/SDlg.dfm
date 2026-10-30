object ShpeelDlg: TShpeelDlg
  Left = 198
  Top = 173
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Шпильки'
  ClientHeight = 448
  ClientWidth = 453
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label4: TLabel
    Left = 222
    Top = 271
    Width = 66
    Height = 16
    Caption = 'Материал'
  end
  object Label3: TLabel
    Left = 10
    Top = 10
    Width = 207
    Height = 16
    Caption = 'Длина ввинчиваемого конца b1'
  end
  object Label5: TLabel
    Left = 10
    Top = 236
    Width = 102
    Height = 16
    Caption = 'Класс точности'
  end
  object Label6: TLabel
    Left = 222
    Top = 236
    Width = 35
    Height = 16
    Caption = 'ГОСТ'
  end
  object Ok: TButton
    Left = 10
    Top = 410
    Width = 92
    Height = 31
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
  end
  object cboxSpcObj: TCheckBox
    Left = 10
    Top = 300
    Width = 240
    Height = 20
    Caption = 'Создать объект спецификации'
    TabOrder = 1
    OnClick = cboxSpcObjClick
  end
  object Panel1: TPanel
    Left = 222
    Top = 39
    Width = 222
    Height = 179
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 2
    object PaintBox1: TPaintBox
      Left = 1
      Top = 1
      Width = 216
      Height = 173
      Align = alClient
      OnClick = PaintBox1Click
      OnPaint = PaintBox1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 10
    Top = 34
    Width = 198
    Height = 100
    TabOrder = 3
    object Label1: TLabel
      Left = 12
      Top = 30
      Width = 57
      Height = 16
      Caption = 'Диаметр'
    end
    object Label2: TLabel
      Left = 12
      Top = 64
      Width = 41
      Height = 16
      Caption = 'Длина'
    end
  end
  object canselButton: TButton
    Left = 191
    Top = 410
    Width = 92
    Height = 31
    Cancel = True
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 4
  end
  object ComboBox: TComboBox
    Left = 100
    Top = 62
    Width = 87
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 5
    OnChange = ComboBoxChange
  end
  object helpButton: TButton
    Left = 356
    Top = 410
    Width = 91
    Height = 31
    Caption = 'Справка'
    TabOrder = 6
    OnClick = helpButtonClick
  end
  object ComboBox1: TComboBox
    Left = 305
    Top = 266
    Width = 139
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 7
    OnChange = ComboBox1Change
  end
  object StringGrid1: TStringGrid
    Left = 9
    Top = 329
    Width = 435
    Height = 70
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
    Left = 100
    Top = 96
    Width = 86
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 9
    OnChange = ComboBox2Change
  end
  object ComboBox3: TComboBox
    Left = 222
    Top = 5
    Width = 89
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 10
    OnChange = ComboBox3Change
  end
  object ComboBox4: TComboBox
    Left = 123
    Top = 231
    Width = 85
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 11
    OnChange = ComboBox4Change
  end
  object ComboBox5: TComboBox
    Left = 305
    Top = 231
    Width = 139
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 12
    OnChange = ComboBox5Change
  end
  object CheckBox1: TCheckBox
    Left = 10
    Top = 266
    Width = 119
    Height = 21
    Caption = 'Мелкий шаг'
    TabOrder = 13
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 305
    Top = 300
    Width = 120
    Height = 21
    Caption = 'Упрощенно'
    TabOrder = 14
    OnClick = CheckBox2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 10
    Top = 138
    Width = 198
    Height = 80
    Items.Strings = (
      'Исполнение 1'
      'Исполнение 2')
    TabOrder = 15
    OnClick = RadioGroup1Click
  end
end
