Option Strict Off
Option Explicit On
Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step8")> _
Public Class Step8

  Public Kompas As Object
  Public attr As Object
  Public doc As Object

  Sub ShowCol(ByRef par As Object, ByRef iCol As Short, ByRef fl As Boolean)
    Dim s As String
    If fl Then
      s = "структура"
    Else
      s = ""
    End If

    ' выдадим поля колонки не указатели
    'UPGRADE_WARNING: Couldn't resolve default property of object par.FlagEnum. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object par.Def. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object par.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object par.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Kompas.ksMessage(s & " i = " & iCol & " header=" & par.Header & " type=" & par.Type & " def=" & par.Def & " flagEnum=" & par.FlagEnum)
    'UPGRADE_WARNING: Couldn't resolve default property of object par.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim pCol As Object
    If par.Type = RECORD_ATTR_TYPE Then ' структура
      'UPGRADE_WARNING: Couldn't resolve default property of object par.GetColumns. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      pCol = par.GetColumns
      If Not pCol Is Nothing Then
        ShowColumns(pCol, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object pCol.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        pCol.ksDeleteArray()
        'UPGRADE_NOTE: Object pCol may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        pCol = Nothing
      End If
    End If
  End Sub

  Sub ShowColumns(ByRef pCol As Object, ByRef fl As Boolean)
    Dim par As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    par = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)
    Dim n As Short
    Dim i As Short
    If Not par Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object par.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      par.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object pCol.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      n = pCol.ksGetArrayCount

      For i = 0 To n - 1
        'UPGRADE_WARNING: Couldn't resolve default property of object pCol.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If pCol.ksGetArrayItem(i, par) = 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessageBoxResult() ' проверяем результат работы нашей функции
        Else
          ShowCol(par, i, fl)
        End If
      Next i
      'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      par = Nothing
    End If
  End Sub

  ' создание типа аттрибута
  Sub FuncAttrType()
    Dim type_ As Object
    Dim col As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    type_ = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_AttributeType)
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    col = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)
    Dim arr As Object
    Dim nameFile As String
    Dim numbType As Double
    If Not type_ Is Nothing And Not col Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object col.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      col.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Header = "double_str_long" ' заголовoк-комментарий типа
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.RowsCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.RowsCount = 1 ' кол-во строк в таблице
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.FlagVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.FlagVisible = True ' видимый, невидимый   в таблице
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.password. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.password = "" ' пароль, если не пустая строка  - защищает от несанкционированного изменения типа
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Key1 = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Key2 = 20
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key3. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Key3 = 30
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key4. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Key4 = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.GetColumns. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      arr = type_.GetColumns
      If Not arr Is Nothing Then
        ' первая колонка  структуры
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Header = "double" ' заголовoк-комментарий столбца
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Type = DOUBLE_ATTR_TYPE ' тип данных в столбце - см.ниже
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Key. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Key = 0 ' дополнительный признак, который позволит отличить две переменные с одинаковым типом
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Def. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Def = "123456789" ' значение по умолчанию
        'UPGRADE_WARNING: Couldn't resolve default property of object col.FlagEnum. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.FlagEnum = False ' флаг включающий режим, когда значение поля атрибута
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, col)

        ' вторая колонка структуры
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Header = "str" ' заголовoк-комментарий столбца
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Type = STRING_ATTR_TYPE ' тип данных в столбце - см.ниже
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Key. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Key = 0 ' дополнительный признак, который позволит отличить две переменные с одинаковым типом
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Def. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Def = "string" ' значение по умолчанию
        'UPGRADE_WARNING: Couldn't resolve default property of object col.FlagEnum. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.FlagEnum = False ' флаг включающий режим, когда значение поля атрибута
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, col)

        ' третья колонка структуры
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Header = "long" ' заголовoк-комментарий столбца
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Type = LINT_ATTR_TYPE ' тип данных в столбце - см.ниже
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Key. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Key = 0 ' дополнительный признак, который позволит отличить две переменные с одинаковым типом
        'UPGRADE_WARNING: Couldn't resolve default property of object col.Def. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.Def = "1000000" ' значение по умолчанию
        'UPGRADE_WARNING: Couldn't resolve default property of object col.FlagEnum. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        col.FlagEnum = False ' флаг включающий режим, когда значение поля атрибута
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, col)
        'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr = Nothing
      End If
      nameFile = ""
      ' запросить имя библиотеки
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      nameFile = Kompas.ksChoiceFile("*.lat", "", False)
      ' создать тип атрибута
      'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksCreateAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      numbType = attr.ksCreateAttrType(type_, nameFile)
      If numbType > 1 Then
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("numbType = " & numbType)
      Else
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessageBoxResult() ' проверяем результат работы нашей функции
      End If

      ' удалим  массив колонок
      '    arr.ksDeleteArray
      'UPGRADE_NOTE: Object type_ may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      type_ = Nothing
      'UPGRADE_NOTE: Object col may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      col = Nothing
    End If
  End Sub

  Sub DelTypeAttr()
    Dim numb As Double
    Dim j As Short
    Dim password As String
    password = ""
    ' запросить имя библиотеки
    Dim nameFile As String
    nameFile = ""
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    nameFile = Kompas.ksChoiceFile("*.lat", "", False)
    Do
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      j = Kompas.ksReadDouble("Ввести номер типа атрибута", 1000.0#, 0, 1000000000000.0#, numb)
      If j <> 0 Then
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        password = Kompas.ksReadString("Ввести пароль типа атрибута", "")
        'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksDeleteAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If attr.ksDeleteAttrType(numb, nameFile, password) = 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessageBoxResult() ' проверяем результат работы нашей функции
        End If
      End If
    Loop While (j <> 0)
  End Sub

  ' получить тип атрибута
  Sub ShowTypeAttr()
    Dim numb As Double
    ' запросить имя библиотеки
    Dim nameFile As String
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    nameFile = Kompas.ksChoiceFile("*.lat", "", False)

    Dim type_ As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    type_ = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_AttributeType)
    Dim pCol As Object
    If Not type_ Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Init()

      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksChoiceAttrTypes. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        numb = attr.ksChoiceAttrTypes(nameFile)
        If numb <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksGetAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If attr.ksGetAttrType(numb, nameFile, type_) = 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessageBoxResult() ' проверяем результат работы нашей функции
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key4. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key3. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.Key1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("key1 = " & type_.Key1 & " key2 = " & type_.Key2 & " key3 = " & type_.Key3 & " key4 = " & type_.Key4)
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.password. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.FlagVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.RowsCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.Header. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("header = " & type_.Header & " rowsCount = " & type_.RowsCount & " flagVisible = " & type_.FlagVisible & " password = " & type_.password)
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.GetColumns. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            pCol = type_.GetColumns
            If Not pCol Is Nothing Then
              ShowColumns(pCol, False)
              'UPGRADE_WARNING: Couldn't resolve default property of object pCol.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pCol.ksDeleteArray()
              'UPGRADE_NOTE: Object pCol may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              pCol = Nothing
            End If
            '          ShowColumns attrType.columns, FALSE  ' пользовательская функция
          End If
        End If
      Loop While (numb)
      ' удалим  массив колонок
      '    DeleteArray attrType.columns
      'UPGRADE_NOTE: Object type_ may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      type_ = Nothing
    End If
  End Sub

  ' заменить тип атрибута
  Sub ChangeType()
    Dim numb As Double
    Dim password As String
    password = ""
    ' запросить имя библиотеки
    Dim nameFile As String
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    nameFile = Kompas.ksChoiceFile("*.lat", "", False)
    Dim j As Short

    Dim type_ As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    type_ = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_AttributeType)
    Dim arr As Object
    Dim par1 As Object
    Dim parN As Object
    Dim n As Short
    Dim numbType As Double
    If Not type_ Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object type_.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      type_.Init()
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = Kompas.ksReadDouble("Ввести номер типа атрибута", 1000.0#, 0, 1000000000000.0#, numb)
        If j <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          password = Kompas.ksReadString("Ввести пароль типа атрибута", "")
          ' считаем тип атрибута
          'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksGetAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If attr.ksGetAttrType(numb, nameFile, type_) = 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessageBoxResult() ' проверяем результат работы нашей функции
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.password. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            type_.password = password
            'UPGRADE_WARNING: Couldn't resolve default property of object type_.GetColumns. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr = type_.GetColumns()
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            par1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            parN = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ColumnInfoParam)
            If Not arr Is Nothing And Not par1 Is Nothing And Not parN Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object par1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              par1.Init()
              'UPGRADE_WARNING: Couldn't resolve default property of object parN.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              parN.Init()
              ' число колонок
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              n = arr.ksGetArrayCount()
              ' считаем первую колонку
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              arr.ksGetArrayItem(0, par1)
              ' считаем последнюю колонку
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              arr.ksGetArrayItem(n - 1, parN)
              ' заменим первую колонку
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              arr.ksSetArrayItem(0, parN)
              ' заменим последнюю колонку
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              arr.ksSetArrayItem(n - 1, par1)

              ' заменим  тип атрибута  на новый
              'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksSetAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              numbType = attr.ksSetAttrType(numb, nameFile, type_, password)
              If numbType > 1 Then
                'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                Kompas.ksMessage("numbType = " & numbType)
              Else
                'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                Kompas.ksMessageBoxResult() ' неудачное завершение - выдадим результат работы нашей функции
              End If
              'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              arr.ksDeleteArray()
              'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              arr = Nothing
              'UPGRADE_NOTE: Object par1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              par1 = Nothing
              'UPGRADE_NOTE: Object parN may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              parN = Nothing
            End If
          End If
        End If
      Loop While (j <> 0)
      'UPGRADE_NOTE: Object type_ may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      type_ = Nothing
    End If
  End Sub

  ' создадим атрибут типа,полученного из функции FuncTypeAttr
  Sub NewAttr()
    Dim attrPar As Object
    Dim usPar As Object
    Dim fVisibl As Object
    Dim colKeys As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    attrPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Attribute)
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    usPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    fVisibl = Kompas.GetDynamicArray(LTVARIANT_ARR)
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    colKeys = Kompas.GetDynamicArray(LTVARIANT_ARR)
    Dim item As Object
    Dim arr As Object
    Dim info As Object
    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim pObj As Integer
    Dim nameFile As String
    Dim numb As Double
    Dim pAttr As Integer
    If Not attrPar Is Nothing And Not usPar Is Nothing And Not fVisibl Is Nothing And Not colKeys Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object usPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      usPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.setValues. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.setValues(usPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.setColumnKeys. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.setColumnKeys(colKeys)
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.setFlagVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.setFlagVisible(fVisibl)
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.Key1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.Key1 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.Key2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.Key2 = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.Key3. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.Key3 = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object attrPar.password. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attrPar.password = "111"

      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      item = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      arr = Kompas.GetDynamicArray(LTVARIANT_ARR)
      If Not item Is Nothing And Not arr Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object usPar.setUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        usPar.setUserArray(arr)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.DoubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.DoubleVal = 987654321.0#
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.StrVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.StrVal = "qwerty"
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.LongVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.LongVal = 999991
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)

        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.UCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.UCharVal = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object fVisibl.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        fVisibl.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object fVisibl.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        fVisibl.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object fVisibl.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        fVisibl.ksAddArrayItem(-1, item)
        'UPGRADE_NOTE: Object item may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        item = Nothing
        'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr = Nothing
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
      If Not info Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object info.Prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.Prompt = "Укажите объект"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = doc.ksCursor(info, x, y, Nothing)
        If j <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pObj = doc.ksFindObj(x, y, 1000000.0#)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If doc.ksExistObj(pObj) <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 1)
            ' запросить имя библиотеки
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            nameFile = Kompas.ksChoiceFile("*.lat", "", False)
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            j = Kompas.ksReadDouble("Ввести номер типа атрибута", 1000.0#, 0, 1000000000000.0#, numb)
            If j <> 0 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksCreateAttr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pAttr = attr.ksCreateAttr(pObj, attrPar, numb, nameFile)
              If pAttr = 0 Then
                'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                Kompas.ksMessageBoxResult() ' неудачное завершение - выдадим результат работы нашей функции
              End If
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 0)
          End If
        End If
        'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        info = Nothing
      End If
      'UPGRADE_NOTE: Object attrPar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      attrPar = Nothing
      'UPGRADE_NOTE: Object usPar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      usPar = Nothing
      'UPGRADE_NOTE: Object fVisibl may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      fVisibl = Nothing
      'UPGRADE_NOTE: Object colKeys may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      colKeys = Nothing
    End If
  End Sub

  ' удалить первый атрибут  у данного объекта
  Sub DelObjAttr()
    Dim info As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim pObj As Integer
    Dim iter As Object
    Dim pAttr As Integer
    Dim n As Integer
    Dim password As String
    If Not info Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Prompt = "Укажите объект"
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = doc.ksCursor(info, x, y, Nothing)
        If j <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pObj = doc.ksFindObj(x, y, 1000000.0#)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If doc.ksExistObj(pObj) <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 1)
            ' создадим итератор для хождения по атрибутам объекта
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iter = Kompas.GetIterator
            If Not iter Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksCreateAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If iter.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) <> 0 Then
                ' встали на первый атрибут
                'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                pAttr = iter.ksMoveAttrIterator("F", n)
                If pAttr <> 0 Then
                  'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  password = Kompas.ksReadString("Ввести пароль типа атрибута", "")
                  'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksDeleteAttr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  If attr.ksDeleteAttr(pObj, pAttr, password) = 0 Then
                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessageBoxResult()
                  End If
                Else
                  'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  Kompas.ksMessage("атрибут не найден")
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksLightObj(pObj, 0)
              End If
            End If
          End If
        End If
      Loop While (j <> 0)
      'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      info = Nothing
    End If
  End Sub

  ' считать  атрибут  типа double_str_long
  Sub ReadObjAttr()
    Dim res As Boolean
    res = False
    Dim usPar As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    usPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
    Dim item As Object
    Dim arr As Object
    If Not usPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object usPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      usPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      item = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      arr = Kompas.GetDynamicArray(LTVARIANT_ARR)
      If Not item Is Nothing And Not arr Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object usPar.setUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        usPar.setUserArray(arr)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.DoubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.DoubleVal = 987654321.0#
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.StrVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.StrVal = "qwerty"
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.LongVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.LongVal = 999991
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        res = True
        'UPGRADE_NOTE: Object item may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        item = Nothing
        'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        arr = Nothing
      End If
    End If
    Dim info As Object
    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim pObj As Integer
    Dim iter1 As Object
    Dim pAttr As Integer
    Dim n As Integer
    Dim k1 As Integer
    Dim k2 As Integer
    Dim k3 As Integer
    Dim k4 As Integer
    Dim numb As Double
    Dim item1 As Object
    Dim arr1 As Object
    If res Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
      If Not info Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object info.Prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.Prompt = "Укажите объект"
        Do
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          j = doc.ksCursor(info, x, y, Nothing)
          If j <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            pObj = doc.ksFindObj(x, y, 1000000.0#)
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If doc.ksExistObj(pObj) <> 0 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksLightObj(pObj, 1)
              ' создадим итератор для хождения по атрибутам объекта
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iter1 = Kompas.GetIterator
              If Not iter1 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of object iter1.ksCreateAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If iter1.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) <> 0 Then
                  ' встали на первый атрибут
                  'UPGRADE_WARNING: Couldn't resolve default property of object iter1.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  pAttr = iter1.ksMoveAttrIterator("F", n)
                  If pAttr <> 0 Then
                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessage("тип и ключи атрибута")
                    'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksGetAttrKeysInfo. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    attr.ksGetAttrKeysInfo(pAttr, k1, k2, k3, k4, numb)
                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessage("k1 = " & k1 & " k2 = " & k2 & " k3 = " & k3 & " k4 = " & k4 & " numb = " & numb)

                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessage("строка атрибута")
                    'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksGetAttrRow. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    attr.ksGetAttrRow(pAttr, 0, Nothing, Nothing, usPar)

                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessage("заменим строку атрибута")
                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    item1 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
                    'UPGRADE_WARNING: Couldn't resolve default property of object usPar.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    arr1 = usPar.GetUserArray
                    If Not item1 Is Nothing And Not arr1 Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.Init()
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.DoubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.DoubleVal = numb
                      'UPGRADE_WARNING: Couldn't resolve default property of object arr1.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      arr1.ksSetArrayItem(0, item1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.Init()
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.StrVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.StrVal = "1234567\nasdfgh\nzxcvb"
                      'UPGRADE_WARNING: Couldn't resolve default property of object arr1.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      arr1.ksSetArrayItem(1, item1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.Init()
                      'UPGRADE_WARNING: Couldn't resolve default property of object item1.LongVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      item1.LongVal = 888881
                      'UPGRADE_WARNING: Couldn't resolve default property of object arr1.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      arr1.ksSetArrayItem(2, item1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksSetAttrRow. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      attr.ksSetAttrRow(pAttr, 0, Nothing, Nothing, usPar, "111")
                      'UPGRADE_NOTE: Object item1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
                      item1 = Nothing
                      'UPGRADE_NOTE: Object arr1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
                      arr1 = Nothing
                    End If
                  Else
                    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    Kompas.ksMessage("атрибут не найден")
                  End If
                End If
              End If
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksLightObj(pObj, 0)
            End If
          End If
        Loop While (j <> 0)
        'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        info = Nothing
      End If
      'UPGRADE_NOTE: Object usPar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      usPar = Nothing
    End If
  End Sub

  ' просмотреть  атрибут
  Sub ShowObjAttr()
    Dim info As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim pObj As Integer
    If Not info Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Prompt = "Укажите объект"
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = doc.ksCursor(info, x, y, Nothing)
        If j <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pObj = doc.ksFindObj(x, y, 1000000.0#)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If doc.ksExistObj(pObj) <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksChoiceAttr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            attr.ksChoiceAttr(pObj)
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 0)
          End If
        End If
      Loop While (j <> 0)
      'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      info = Nothing
    End If
  End Sub

  Sub ShowLib()
    ' запросить имя библиотеки
    Dim nameFile As String
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    nameFile = Kompas.ksChoiceFile("*.lat", "", False)

    Dim numb As Double
    'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksChoiceAttrTypes. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    numb = attr.ksChoiceAttrTypes(nameFile)
    If numb > 1 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("numbType = " & numb)
    End If
  End Sub

  Sub ShowType()
    ' запросить имя библиотеки
    Dim nameFile As String
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    nameFile = Kompas.ksChoiceFile("*.lat", "", False)
    Dim password As String
    Dim numb As Double
    Dim j As Short
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    j = Kompas.ksReadDouble("Ввести номер типа атрибута", 1000.0#, 0, 1000000000000.0#, numb)
    If j <> 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      password = Kompas.ksReadString("Ввести пароль типа атрибута", "")
      'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksViewEditAttrType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      attr.ksViewEditAttrType(nameFile, 2, numb, password)
    End If
  End Sub

  ' пройтись у объекта, по атрибутам  с ключом
  ' key1=10 и выдать количество  колонок и строк для данного атрибута
  Sub WalkFromObjWithAttr()
    Dim info As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    info = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim x As Double
    Dim y As Double
    Dim j As Short
    Dim pObj As Integer
    Dim iter As Object
    Dim pAttr As Integer
    Dim n As Integer
    If Not info Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Prompt = "Укажите объект"
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = doc.ksCursor(info, x, y, Nothing)
        If j <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pObj = doc.ksFindObj(x, y, 1000000.0#)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If doc.ksExistObj(pObj) <> 0 Then
            ' создадим итератор для движения по атрибутам с ключом 10
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iter = Kompas.GetIterator
            If Not iter Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksCreateAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If iter.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) <> 0 Then
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksLightObj(pObj, 1)
                ' встали на первый атрибут
                'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                pAttr = iter.ksMoveAttrIterator("F", n)
                If pAttr <> 0 Then
                  Do
                    'UPGRADE_WARNING: Couldn't resolve default property of object attr.ksViewEditAttr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    attr.ksViewEditAttr(pAttr, 1, "")
                    'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    pAttr = iter.ksMoveAttrIterator("N", n)
                  Loop While (pAttr <> 0)
                End If
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksLightObj(pObj, 0)
              End If
              'UPGRADE_NOTE: Object iter may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              iter = Nothing
            End If
          End If
        End If
      Loop While (j <> 0)
      'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      info = Nothing
    End If
  End Sub

  Public Function GetLibraryName() As String
    GetLibraryName = "Работа с аттрибутами"
  End Function

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Object)
    Kompas = kompas_

    ' получить интерфейс 2D документа
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc = Kompas.ActiveDocument2D ' интерфейс активного документа
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetAttributeObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    attr = Kompas.GetAttributeObject ' интерфейс работы с атрибутами

    Select Case command_Renamed

      Case 1
        FuncAttrType() ' создать тип атрибута
      Case 2
        DelTypeAttr() ' удалить  тип атрибута
      Case 3
        ShowTypeAttr() ' получить  тип атрибута
      Case 4
        ChangeType() ' заменить  тип атрибута
      Case 5
        NewAttr() ' создать атрибут определенного типа
      Case 6
        DelObjAttr() ' удалить атрибут
      Case 7
        ReadObjAttr() ' считать атрибут
      Case 8
        ShowObjAttr() ' просмотреть атрибут
      Case 9
        ShowLib() ' просмотреть библиотеку
      Case 10
        ShowType() ' просмотреть тип
      Case 11
        WalkFromObjWithAttr() ' просмотреть атрибут

    End Select
  End Sub

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 3 '"ENDMENU"'
    ExternalMenuItem = ""
    command_Renamed = -1

    Select Case number
      Case 1
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Создать тип атрибута"
        command_Renamed = 1
      Case 2
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Удалить тип атрибута"
        command_Renamed = 2
      Case 3
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Получить тип атрибута"
        command_Renamed = 3
      Case 4
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Заменить тип атрибута"
        command_Renamed = 4

      Case 5
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Создать атрибут определенного типа"
        command_Renamed = 5
      Case 6
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Удалить атрибут"
        command_Renamed = 6
      Case 7
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Считать атрибут"
        command_Renamed = 7
      Case 8
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "просмотреть атрибуты объекта"
        command_Renamed = 8
      Case 9
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Просмотреть библиотеку"
        command_Renamed = 9
      Case 10
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Просмотреть тип"
        command_Renamed = 10
      Case 11
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Просмотреть атрибут"
        command_Renamed = 11
      Case Else
        itemType = 3 '"ENDMENU"'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  <ComRegisterFunctionAttribute()> _
  Friend Shared Sub RegisterKompasLib(ByVal typeToRegister As Type)
    Try
      Dim regKey As RegistryKey
      regKey = Registry.LocalMachine
      Dim keyName As String
      keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
      regKey = regKey.OpenSubKey(keyName, True)
      regKey.CreateSubKey("Kompas_Library")
      regKey = regKey.OpenSubKey("InprocServer32", True)
      regKey.SetValue(Nothing, System.Environment.GetFolderPath(Environment.SpecialFolder.System) + "\mscoree.dll")
      regKey.Close()

    Catch e As Exception
      MsgBox(e.Message, MsgBoxStyle.OkOnly)
    End Try

  End Sub

  <ComUnregisterFunctionAttribute()> _
  Friend Shared Sub UnregisterKompasLib(ByVal typeToRegister As Type)
    Dim regKey As RegistryKey
    regKey = Registry.LocalMachine
    Dim keyName As String
    keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
    regKey = regKey.OpenSubKey(keyName, True)
    regKey.DeleteSubKey("Kompas_Library")
    regKey.Close()
  End Sub
End Class