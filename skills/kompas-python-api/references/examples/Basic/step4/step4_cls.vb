Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32


<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step4")> _
Public Class Step4

  Public type_ As Short
  Public flag As Short
  'flag = 1


  Private Declare Function PostThreadMessage Lib "user32" Alias "PostThreadMessageA" (ByVal idThread As Integer, ByVal Msg As Integer, ByVal wParam As Integer, ByVal lParam As String) As Boolean
  Private Declare Function GetCurrentThreadId Lib "Kernel32" () As Integer

  Sub DrawTxtDB()
    Dim bd As Integer
    Dim r1 As Integer
    Dim r2 As Integer
    Dim r3 As Integer
    Dim i As Short
    i = 1
    Dim dr As Double
    Dim l As Double
    Dim f As Short

    Dim data As Object
    Dim par As Object
    Dim item As Object
    Dim arr As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.DataBaseObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    data = kompasOb.DataBaseObject
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    par = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arr = kompasOb.GetDynamicArray(LTVARIANT_ARR)
    If par Is Nothing Or item Is Nothing Or data Is Nothing Then
      Exit Sub
    End If
    'UPGRADE_WARNING: Couldn't resolve default property of object par.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    par.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object par.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    par.SetUserArray(arr)
    'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.doubleVal = 0
    'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arr.ksAddArrayItem(-1, item)
    'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.doubleVal = 0
    'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arr.ksAddArrayItem(-1, item)
    'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object item.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item.intVal = 0
    'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arr.ksAddArrayItem(-1, item)

    Dim libName As String
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    libName = kompasOb.ksChoiceFile("*.loa", "Базы данных(*.loa)|*.loa|Все файлы (*.*)|*.*|", 1)
    Dim a As Double
    If Len(libName) <> 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object data.ksCreateDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      bd = data.ksCreateDB("TXT_DB") ' создать объект, обслуживающий базу данных
      'UPGRADE_WARNING: Couldn't resolve default property of object data.ksConnectDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If data.ksConnectDB(bd, libName) Then ' связать объект базы с определенной базой данных( для текстового файла - имя файла )
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        r1 = data.ksRelation(bd) ' создать отношение - буфер для считывания информации из таблицы
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRDouble("dr") ' имена даются ключевым колонкам,
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRDouble("L") ' по ним в дальнейшем формируются условия выборки
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRInt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRInt("")
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksEndRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksEndRelation()

        ' установить запрос - отношение связывается с базой( указываем какие колонки
        ' базы связать с переменными буфера )
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDoStatement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksDoStatement(bd, r1, "1 2 3") ' колонка dr - 1, L - 2, оставшаяся колонка -3
        Do While (i <> 0)
          'UPGRADE_WARNING: Couldn't resolve default property of object data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          i = data.ksReadRecord(bd, r1, par) ' считать очередную порцию информации и положть в структуру b
          If i <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(0, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            dr = item.doubleVal
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(1, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            l = item.doubleVal
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(2, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            f = item.intVal
            'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            kompasOb.ksMessage("DR = " & dr & " L = " & l & " F = " & f)
          End If
        Loop
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        kompasOb.ksMessage("end")

        i = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksClearArray()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.strVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.strVal = ""
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        r2 = data.ksRelation(bd) ' создать отношение - буфер для считывания информации из таблицы
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRChar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRChar("", 255, 0)
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksEndRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksEndRelation()

        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDoStatement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksDoStatement(bd, r2, "2") ' установить запрос - отношение связывается с базой( указываем какие колонки
        Do While (i <> 0)
          'UPGRADE_WARNING: Couldn't resolve default property of object data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          i = data.ksReadRecord(bd, r2, par) ' считать очередную порцию информации и положть в структуру b
          If Not i = 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(0, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.strVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            kompasOb.ksMessage("L = " & item.strVal)
          End If
        Loop
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        kompasOb.ksMessage("end")

        i = 1

        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksClearArray()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.doubleVal = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object item.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        item.doubleVal = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        arr.ksAddArrayItem(-1, item)
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        r3 = data.ksRelation(bd) ' создать отношение - буфер для считывания информации из таблицы
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRDouble("")
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksRDouble("L")
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksEndRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksEndRelation()

        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDoStatement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksDoStatement(bd, r3, "1 2") ' установить запрос - отношение связывается с базой( указываем какие колонки
        'UPGRADE_WARNING: Couldn't resolve default property of object data.ksCondition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        data.ksCondition(bd, r3, "L=100||L=150")
        Do While (i <> 0)
          'UPGRADE_WARNING: Couldn't resolve default property of object data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          i = data.ksReadRecord(bd, r3, par) ' считать очередную порцию информации и положть в структуру b
          If i <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(0, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            a = item.doubleVal
            'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            arr.ksGetArrayItem(1, item)
            'UPGRADE_WARNING: Couldn't resolve default property of object item.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            l = item.doubleVal
            'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            kompasOb.ksMessage("dr = " & a & " L = " & l)
          End If
        Loop
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        kompasOb.ksMessage("end")
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDeleteDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      data.ksDeleteDB(bd) ' удалить обьект, обслуживающий базу данных
    End If
    'UPGRADE_NOTE: Object data may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    data = Nothing
    'UPGRADE_NOTE: Object par may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    par = Nothing
    'UPGRADE_NOTE: Object item may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    item = Nothing
    'UPGRADE_NOTE: Object arr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    arr = Nothing
  End Sub

  Sub WriteSlideStep()
    ' выберем файл для записи
    Dim name As String
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksSaveFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    name = kompasOb.ksSaveFile("*.rc", "", "", False)
    Dim info As Object
    Dim X As Double
    Dim Y As Double
    Dim slideID As Integer
    If Len(name) <> 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
      If Not info Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info.commandsString = "Укажите точку привязки слайда"
        ' точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If docActive.ksCursor(info, X, Y, Nothing) <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksReadInt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If kompasOb.ksReadInt("Введите идентификатор слайда", 100, 0, 32000, slideID) <> 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksWriteSlide. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If kompasOb.ksWriteSlide(name, slideID, X, Y) = 0 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              kompasOb.ksError("Группа селектирования пуста")
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksClearGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksClearGroup(0, True)
          End If
        End If
        'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        info = Nothing
      End If
    End If
  End Sub

  ' Работа с относительными путями файлов
  Sub WorkRelativePath()
    Dim mainName As String
    Dim fileName As String
    ' имя задающего файла
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    mainName = kompasOb.ksChoiceFile("*.*", "Все файлы (*.*)|*.*|", True)
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    fileName = kompasOb.ksChoiceFile("*.*", "Все файлы (*.*)|*.*|", True)
    Dim relName As String
    Dim mess As String
    Dim fullName As String
    If Len(mainName) <> 0 And Len(fileName) <> 0 Then
      ' относительный путь
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksGetRelativePathFromFullPath. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      relName = kompasOb.ksGetRelativePathFromFullPath(mainName, fileName)

      mess = "Задающий файл : "
      mess = mess & mainName
      mess = mess & " \n"
      mess = mess & "Полный путь : "
      mess = mess & fileName
      mess = mess & " \n"
      mess = mess & "Относительный путь : "
      mess = mess & relName
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      kompasOb.ksMessage(mess)

      ' полный путь
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksGetFullPathFromRelativePath. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      fullName = kompasOb.ksGetFullPathFromRelativePath(mainName, relName)
      mess = "Задающий файл : "
      mess = mess & mainName
      mess = mess & " /n"
      mess = mess & "Относительный путь : "
      mess = mess & relName
      mess = mess & " /n"
      mess = mess & "Полный путь : "
      mess = mess & fullName
      mess = mess & " /n"
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      kompasOb.ksMessage(mess)
    End If
  End Sub

  ' Работа с системными каталогами
  Sub WorkSystemPath()
    Dim catalogName(5) As String
    catalogName(0) = "каталог системных файлов"
    catalogName(1) = "каталог библиотек"
    catalogName(2) = "каталог временных файлов"
    catalogName(3) = "каталог конфигурации"
    catalogName(4) = "INI-файл"
    ' сформировать  полный путь к заданному файлу
    Dim info As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    info = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim j As Short
    Dim fileName As String
    Dim typeCatalog As Short
    Dim mess As String
    Dim relName As String
    If Not info Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object info.Title. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.Title = "Каталоги файлов системы"
      'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.commandsString = "!Системные !Библиотеки !Временные !Конфигурация !INI-файл "
      'UPGRADE_WARNING: Couldn't resolve default property of object info.prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      info.prompt = "Выберите нужный каталог"
      ' static char* buf = "user.ttt";
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCommandWindow. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = docActive.ksCommandWindow(info)
        If j > 0 Then
          Select Case j
            Case 1
              typeCatalog = sptSYSTEM_FILES ' Относительно каталога системных файлов
            Case 2
              typeCatalog = sptLIBS_FILES ' Относительно каталога файлов библиотек
            Case 3
              typeCatalog = sptTEMP_FILES ' Относительно каталога сохранения временных файлов
            Case 4
              typeCatalog = sptCONFIG_FILES ' Относительно каталога сохранения конфигурации системы
            Case 5
              typeCatalog = sptINI_FILE ' Относительно полного имени INI-файла системы
          End Select
          ' полный путь
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksGetFullPathFromSystemPath. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          fileName = kompasOb.ksGetFullPathFromSystemPath("user.ttt", typeCatalog)
          mess = "Полный путь к файлу user.ttt \n"
          mess = mess & catalogName(j - 1)
          mess = mess & " :\n"
          mess = mess & fileName
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage(mess)

          ' относительный путь
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksGetRelativePathFromSystemPath. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          relName = kompasOb.ksGetRelativePathFromSystemPath(fileName, typeCatalog)
          mess = "Относительный путь к файлу \n"
          mess = mess & fileName
          mess = mess & "\n"
          mess = mess & catalogName(j - 1)
          mess = mess & " :\n"
          mess = mess & relName
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage(mess)

        End If
      Loop While (j > 0)
      'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      info = Nothing
    End If
  End Sub

  ' Функция обратной связи, вызываемая из Cursor
  Public Function CALLBACKPROCCURSOR(ByRef comm As Short, ByRef X As Double, ByRef Y As Double, ByRef info As Object, ByRef phan As Object, ByRef dynamic As Short) As Short
    Dim t1 As Object
    If Not info Is Nothing And Not phan Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      t1 = phan.GetPhantomParam
      If Not t1 Is Nothing Then
        Select Case comm
          Case 1
            type_ = comm
          Case 2
            type_ = comm
          Case -1
            ' поставить в модель
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksMoveObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksMoveObj(t1.gr, X, Y)
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If t1.angle > 0.001 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object t1.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksRotateObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              docActive.ksRotateObj(t1.gr, X, Y, t1.angle)
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksStoreTmpGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksStoreTmpGroup(t1.gr)
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksClearGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksClearGroup(t1.gr, True)
        End Select
        ' группа для фантома должна быть временная и обновляться при изменении вида отрисовки
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If t1.gr <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksDeleteObj(t1.gr)
        End If
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.gr = docActive.ksNewGroup(1) ' временная группа

        If (flag = 1 And comm = 1) Or (flag = 2 And comm = 2) Then
          type_ = 3
        End If

        ' обновляется не только изображение но и меню для запроса
        Select Case type_
          Case 1
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksCircle(0, 0, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Квадрат !Треугольник "
            flag = 1
          Case 2
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 0, 10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 0, 0, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(0, 20, -10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Окружность !Квадрат "
            flag = 2
          Case 3
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 0, 10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 0, 10, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 20, -10, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 20, -10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Окружность !Треугольник "
            flag = 0
        End Select

        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        docActive.ksEndGroup()
        'UPGRADE_NOTE: Object t1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        t1 = Nothing
      End If
    End If
    CALLBACKPROCCURSOR = 1
  End Function

  ' Функция обратной связи, вызываемая из Placement
  Public Function CALLBACKPROCPLACEMENT(ByRef comm As Short, ByRef X As Double, ByRef Y As Double, ByRef ang As Double, ByRef info As Object, ByRef phan As Object, ByRef dynamic As Short) As Short

    Dim t1 As Object
    If Not info Is Nothing And Not phan Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      t1 = phan.GetPhantomParam
      If Not t1 Is Nothing Then
        Select Case comm
          Case 1
            type_ = comm
          Case 2
            type_ = comm
          Case -1 ' поставить в модель
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksMoveObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksMoveObj(t1.gr, X, Y)
            ' отлтчте от Cursor угол приходит в виде параметра функции
            If ang > 0.001 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksRotateObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              docActive.ksRotateObj(t1.gr, X, Y, ang)
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksStoreTmpGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksStoreTmpGroup(t1.gr) ' поставить временную группу в вид
            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksClearGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksClearGroup(t1.gr, True)
        End Select

        ' группа для фантома должна быть временная и обновляться при изменении вида отрисовки
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If t1.gr <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksDeleteObj(t1.gr)
        End If
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.gr = docActive.ksNewGroup(1) ' временная группа

        ' обновляется не только изображение но и меню для запроса
        If (flag = 1 And comm = 1) Or (flag = 2 And comm = 2) Then
          type_ = 3
        End If

        Select Case type_
          Case 1
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksCircle(0, 0, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Квадрат !Треугольник "
            flag = 1
          Case 2
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 0, 10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 0, 0, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(0, 20, -10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Окружность !Квадрат "
            flag = 2
          Case 3
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 0, 10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 0, 10, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(10, 20, -10, 20, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksLineSeg(-10, 20, -10, 0, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            info.commandsString = "!Окружность !Треугольник "
            flag = 0
        End Select

        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        docActive.ksEndGroup()
        'UPGRADE_NOTE: Object t1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        t1 = Nothing
      End If
    End If

    CALLBACKPROCPLACEMENT = 1
  End Function

  Sub DrawRectCallBack()
    type_ = 1
    flag = 1
    Dim phan As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    phan = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Phantom)
    Dim t1 As Object
    Dim X As Double
    Dim Y As Double
    Dim ang As Double
    Dim info As Object
    If Not phan Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      phan.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.phantom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      phan.phantom = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      t1 = phan.GetPhantomParam
      If Not t1 Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.scale_ = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.gr = docActive.ksNewGroup(1) ' временная группа
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        docActive.ksCircle(0, 0, 20, 1)
        'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        docActive.ksEndGroup()

        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
        If Not info Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          info.Init()
          'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          info.commandsString = "!Квадрат !Треугольник"
          ' указываем адрес обратной функции для Placement
          'UPGRADE_WARNING: Couldn't resolve default property of object info.SetCallBackP. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          info.SetCallBackP("CALLBACKPROCPLACEMENT", 0, Me)
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksPlacement(info, X, Y, ang, phan)

          'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          t1.gr = docActive.ksNewGroup(1) ' временная группа
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksCircle(0, 0, 20, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksEndGroup()

          ' указываем адрес обратной функции для Cursor
          'UPGRADE_WARNING: Couldn't resolve default property of object info.SetCallBackC. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          info.SetCallBackC("CALLBACKPROCCURSOR", 0, Me)
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksCursor(info, X, Y, phan)
          'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          info = Nothing
        End If
        'UPGRADE_NOTE: Object t1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        t1 = Nothing
      End If
      'UPGRADE_NOTE: Object phan may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      phan = Nothing
    End If
  End Sub

  Sub DrawRectNULL()
    Dim type1 As Short
    Dim flag1 As Short
    Dim j As Short
    type1 = 1
    flag = 1
    j = 1
    Dim phan As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    phan = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Phantom)
    Dim t1 As Object
    Dim X As Double
    Dim Y As Double
    Dim ang As Double
    Dim info As Object
    If Not phan Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      phan.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.phantom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      phan.phantom = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object phan.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      t1 = phan.GetPhantomParam
      If Not t1 Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.scale_ = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        t1.gr = 0 ' временная группа

        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        info = kompasOb.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
        If Not info Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object info.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          info.Init()
          Do While (j <> 0)

            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If t1.gr <> 0 Then
              'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              docActive.ksDeleteObj(t1.gr)
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            t1.gr = docActive.ksNewGroup(1) ' временная группа
            If (flag1 = 1 And j = 1) Or (flag1 = 2 And j = 2) Then
              type1 = 3
            End If

            Select Case type1
              Case 1
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksCircle(0, 0, 20, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                info.commandsString = "!Квадрат !Треугольник "
                flag1 = 1
              Case 2
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(-10, 0, 10, 0, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(10, 0, 0, 20, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(0, 20, -10, 0, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                info.commandsString = "!Окружность !Квадрат "
                flag1 = 2
              Case 3
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(-10, 0, 10, 0, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(10, 0, 10, 20, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(10, 20, -10, 20, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksLineSeg(-10, 20, -10, 0, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                info.commandsString = "!Окружность !Треугольник "
                flag1 = 0
            End Select

            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            docActive.ksEndGroup()

            'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            j = docActive.ksPlacement(info, X, Y, ang, phan)
            '          j = docActive.ksCursor( info, x, y, phan )
            Select Case j
              Case 1
                type1 = j
              Case 2
                type1 = j
              Case -1 ' поставить в модель
                'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksMoveObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksMoveObj(t1.gr, X, Y)
                'UPGRADE_WARNING: Couldn't resolve default property of object t1.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If t1.angle > 0.001 Then
                  'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksRotateObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  docActive.ksRotateObj(t1.gr, X, Y, ang)
                End If
                'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksStoreTmpGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksStoreTmpGroup(t1.gr) ' поставить временную группу в вид
                'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksClearGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                docActive.ksClearGroup(t1.gr, True)
            End Select
          Loop
          'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          info = Nothing
        End If
        'UPGRADE_NOTE: Object t1 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        t1 = Nothing
      End If
      'UPGRADE_NOTE: Object phan may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      phan = Nothing
    End If
  End Sub

  Public Function GetLibraryName() As String
    GetLibraryName = "приемы работы"
  End Function

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Object)
    kompasOb = kompas_

    ' получить интерфейс 2D документа
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    docActive = kompasOb.ActiveDocument2D ' интерфейс активного документа

    Dim h1 As Integer
    Dim name As String
    Dim i As Short
    Dim tr As Integer
    Select Case command_Renamed

      Case 1
        DrawTxtDB() ' работа с БД
      Case 2 ' процессы
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksYesNo. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If kompasOb.ksYesNo("Вызывать функцию CallBack?") Then
          DrawRectCallBack()
        Else
          DrawRectNULL()
        End If
      Case 3 ' ввод длинного целого
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksReadInt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If kompasOb.ksReadInt("Ввести индекс", 10000, -100000, 100000, h1) Then
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage("h = " & h1)
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage("отказ")
        End If
      Case 4 ' выбор имени файла
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        name = kompasOb.ksChoiceFile("*.cdw", "", True)
        If Len(name) <> 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage(name)
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          kompasOb.ksMessage("отказ")
        End If
      Case 5
        WriteSlideStep() ' пример отрисовки слайда
      Case 6
         TestDialog.TestShowDialog() ' отрисовать слайд ( описание в файле step4_3.cpp )
      Case 7
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksEnableTaskAccess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        kompasOb.ksEnableTaskAccess(0) ' запретили доступ к задаче
        For i = 0 To 10000
          'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docActive.ksLineSeg(10, 10 + i, 20, 10 + i, 1)
          If (i Mod 100) = 0 Then
            ' посылаем необрабатываемое сообщение своему приложению
            ' для выполнения процесса в фоновом режиме
            tr = GetCurrentThreadId()
            PostThreadMessage(tr, 0, 0, CStr(0))
            'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksPumpWaitingMessages. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            kompasOb.ksPumpWaitingMessages() ' через каждые 100 отрезков обрабатываем очередь сообщений
            ' при этом Windows получает возможность выполнить свои
            ' действия, например переключиться на другую задачу
          End If
        Next
        'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksEnableTaskAccess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        kompasOb.ksEnableTaskAccess(1) ' разрешили доступ к задаче
      Case 8
        WorkRelativePath() ' Работа с относительными путями файлов
      Case 9
        WorkSystemPath() ' Работа с системными каталогами

        'UPGRADE_NOTE: Object docActive may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        docActive = Nothing
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
        ExternalMenuItem = "работа с БД"
        command_Renamed = 1
      Case 2
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Placement, Cursor"
        command_Renamed = 2
      Case 3
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "ввод длинного целого"
        command_Renamed = 3
      Case 4
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "выбор имени файла"
        command_Renamed = 4
      Case 5
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "записать слайд"
        command_Renamed = 5
      Case 6
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "отрисовать слайд"
        command_Renamed = 6
      Case 7
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "пример с обработкой очереди сообщений"
        command_Renamed = 7
      Case 8
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "относительный путь фала"
        command_Renamed = 8
      Case 9
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "работа с системными каталогами"
        command_Renamed = 9
      Case 10
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