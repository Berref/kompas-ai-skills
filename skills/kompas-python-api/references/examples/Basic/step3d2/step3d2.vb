Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step3D2")> _
Public Class Step3D2
  Public Kompas As Object

  Public Function GetLibraryName() As String
    GetLibraryName = "Работа с компонентой (деталь или сборка)"
  End Function

  Sub GetSetPartName(ByRef doc As Object) ' взять/изменить имя компоненты
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' верхний компонент
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Имя компоненты = " & iPart.Name())
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPart.Name = "Втулка"
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPart.Update()
    End If
  End Sub

  Sub FixAndStandartComponent(ByRef doc As Object) ' фиксирование и установка стандартного объекта
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.IsDetail. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If doc.IsDetail() Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksError("Текущий документ должен быть сборкой")
      Exit Sub
    End If
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(0) ' первая деталь в сборке
    Dim fixed As Short
    Dim stand As Short
    If Not iPart Is Nothing Then
      ' Получить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.fixedComponent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      fixed = iPart.fixedComponent()
      ' Получить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.standardComponent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      stand = iPart.standardComponent()
      If fixed Then
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Компонент зафиксирован")
      Else
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Компонент не зафиксирован")
      End If
      ' Изменить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.fixedComponent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPart.fixedComponent = (Not fixed)
      If stand Then
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Компонент стандартный")
      Else
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Компонент нестандартный")
      End If
      ' Изменить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.standardComponent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPart.standardComponent = (Not stand)
    End If
  End Sub

  Sub GetSetColorProperty(ByRef doc As Object) ' получить и заменить параметры цвета компоненты
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' верхний компонент

    Dim iColorPr As Object ' ksColorProperty
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.ColorParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iColorPr = iPart.ColorParam
      If Not iColorPr Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.emission. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.transparency. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.shininess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.specularity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.diffuse. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.Ambient. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Номер цвета = " & iColorPr.COLOR & " Общий цвет = " & iColorPr.Ambient & " Диффузия = " & iColorPr.diffuse & " Зеркальность = " & iColorPr.specularity & " Блеск = " & iColorPr.shininess & " Прозрачность = " & iColorPr.transparency & " Излучение = " & iColorPr.emission)
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iColorPr.COLOR = 5421504
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.transparency. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iColorPr.transparency = 0.5
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.Ambient. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iColorPr.Ambient = 0.1
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.diffuse. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iColorPr.diffuse = 0.1
        'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPart.Update()
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.emission. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.transparency. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.shininess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.specularity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.diffuse. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.Ambient. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object iColorPr.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("Номер цвета = " & iColorPr.COLOR & " Общий цвет = " & iColorPr.Ambient & " Диффузия = " & iColorPr.diffuse & " Зеркальность = " & iColorPr.specularity & " Блеск = " & iColorPr.shininess & " Прозрачность = " & iColorPr.transparency & " Излучение = " & iColorPr.emission)
      End If
    End If

    ' Взять и поменять параметры цвета компонента
    'If Not iPart Is Nothing Then
    '  Dim ambient As Double, diffuse As Double, specularity As Double, shininess As Double, transparency As Double, emission As Double
    '  Dim color As Long
    '  iPart.GetAdvancedColor color, ambient, diffuse, specularity, shininess, transparency, emission
    '  Kompas.ksMessage "Номер цвета = " & color & " Общий цвет = " & ambient & " Диффузия = " & diffuse & " Зеркальность = " & specularity & " Блеск = " & shininess & " Прозрачность = " & transparency & " Излучение = " & emission
    '  color = 9421504
    '  transparency = 0.5
    '  ambient = 0.1
    '  diffuse = 0.1
    '  iPart.SetAdvancedColor color, ambient, diffuse, specularity, shininess, transparency, emission
    '  iPart.GetAdvancedColor color, ambient, diffuse, specularity, shininess, transparency, emission
    '  iPart.Update
    '  Kompas.ksMessage "Номер цвета = " & color & " Общий цвет = " & ambient & " Диффузия = " & diffuse & " Зеркальность = " & specularity & " Блеск = " & shininess & " Прозрачность = " & transparency & " Излучение = " & emission '
    'End If
  End Sub

  Sub GetSetArrayVariable(ByRef doc As Object)
    Dim j As Object
    Dim i As Object ' взять и поменять внешние переменные компоненты
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.IsDetail. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If doc.IsDetail() Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Текущий документ должен быть сборкой")
      Exit Sub
    End If
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(0) ' первая деталь в сборке
    Dim ivarCol As Object
    Dim ivar As Object
    Dim count As Short
    Dim d As Double
    Dim count2 As Short ' ksVariable ' ksVariableCollection
    If Not iPart Is Nothing Then
      ' работа с массивом внешних переменных
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.VariableCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ivarCol = iPart.VariableCollection()
      If Not ivarCol Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ivar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_VariableParam)
        'UPGRADE_WARNING: Couldn't resolve default property of object ivarCol.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count = ivarCol.GetCount
        For i = 0 To count - 1
          'UPGRADE_WARNING: Couldn't resolve default property of object ivarCol.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ivar = ivarCol.GetByIndex(i)
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.note. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("Номер переменной = " & i & " Имя переменной = " & ivar.Name & " Значение переменной = " & ivar.Value & " Комментарий = " & ivar.note)
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.note. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ivar.note = "qwerty"
          d = 0
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReadDouble. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksReadDouble("Введи переменную", 10, 0, 100, d)
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ivar.Value = d
          'UPGRADE_NOTE: Object ivar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          ivar = Nothing
        Next
        'UPGRADE_WARNING: Couldn't resolve default property of object ivarCol.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count2 = ivarCol.GetCount
        For j = 0 To count2 - 1 ' просмотр изменненных переменных
          'UPGRADE_WARNING: Couldn't resolve default property of object ivarCol.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ivar = ivarCol.GetByIndex(j)
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.note. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("Номер переменной = " & i & " Имя переменной = " & ivar.Name & " Значение переменной = " & ivar.Value & " Комментарий = " & ivar.note)
          'UPGRADE_NOTE: Object ivar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          ivar = Nothing
        Next
        'UPGRADE_WARNING: Couldn't resolve default property of object iPart.RebuildModel. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPart.RebuildModel() ' перестроение модели
      End If
    End If
  End Sub

  Sub GetSetPlacmentComponent(ByRef doc As Object) ' получить и изменить место расположения детали в сборке
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.IsDetail. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If doc.IsDetail Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksError("Текущий документ должен быть сборкой")
      Exit Sub
    End If
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(0) ' первая деталь в сборке
    Dim iplac As Object
    Dim y, x, z As Double ' ksPlacement
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.GetPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iplac = iPart.GetPlacement()
      If Not iplac Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iplac.GetOrigin. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iplac.GetOrigin(x, y, z)
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage("x = " & x & " y = " & y & " z = " & z)
        'UPGRADE_WARNING: Couldn't resolve default property of object iplac.SetOrigin. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iplac.SetOrigin(20, 20, 20)
        'UPGRADE_WARNING: Couldn't resolve default property of object iPart.SetPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPart.SetPlacement(iplac)
        'UPGRADE_WARNING: Couldn't resolve default property of object iPart.UpdatePlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPart.UpdatePlacement()
        'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPart.Update()
      End If
    End If
  End Sub

  Sub GetSetEntity(ByRef doc As Object) ' Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' верхний компонент
    Dim iplaneXOY As Object ' ksEntity
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iplaneXOY = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' 1-интерфейс на плоскость XOY
      If Not iplaneXOY Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iplaneXOY.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Kompas.ksMessage(iplaneXOY.Name())
        'UPGRADE_WARNING: Couldn't resolve default property of object iplaneXOY.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iplaneXOY.Name = "plane"
        'UPGRADE_WARNING: Couldn't resolve default property of object iplaneXOY.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iplaneXOY.Update()
      End If
    End If
  End Sub

  Sub CreateSketch(ByRef doc As Object) ' создание эскиза
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' верхний компонент
    Dim iplaneXOY As Object
    Dim ientity As Object
    Dim isketch As Object
    Dim isketchDoc As Object ' ksDocument2D ' ksSketchDefinition ' ksEntity
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iplaneXOY = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' 1-интерфейс на плоскость XOY
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ientity = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
      If Not iplaneXOY Is Nothing And Not ientity Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object ientity.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isketch = ientity.GetDefinition()
        If Not isketch Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object isketch.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          isketch.SetPlane(iplaneXOY)
          'UPGRADE_WARNING: Couldn't resolve default property of object ientity.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ientity.Create()
          'UPGRADE_WARNING: Couldn't resolve default property of object isketch.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          isketchDoc = isketch.BeginEdit()
          'UPGRADE_WARNING: Couldn't resolve default property of object isketchDoc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          isketchDoc.ksLineSeg(0, 0, 100, 100, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of object isketch.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          isketch.EndEdit()
        End If
      End If
    End If
  End Sub

  Sub GetArraySketch(ByRef doc As Object)
    Dim i As Object ' Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' верхний компонент
    Dim ientityCollection As Object
    Dim icurrentEntity As Object
    Dim count As Short ' ksEntity ' ksEntityCollection
    If Not iPart Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ientityCollection = iPart.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_sketch)
      'UPGRADE_WARNING: Couldn't resolve default property of object iPart.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icurrentEntity = iPart.EntityCollection(0)
      If Not ientityCollection Is Nothing And Not icurrentEntity Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object ientityCollection.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count = ientityCollection.GetCount
        For i = 0 To count - 1
          'UPGRADE_WARNING: Couldn't resolve default property of object ientityCollection.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          icurrentEntity = ientityCollection.GetByIndex(i)
          'UPGRADE_WARNING: Couldn't resolve default property of object icurrentEntity.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage(icurrentEntity.Name)
          'UPGRADE_NOTE: Object icurrentEntity may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          icurrentEntity = Nothing
        Next
      End If
    End If
  End Sub

  Sub GetSetUserParamComponent(ByRef doc As Object) ' Установить и получить параметры пользователя в компоненте
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.IsDetail. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If doc.IsDetail Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksError("Текущий документ должен быть сборкой")
      Exit Sub
    End If
    Dim iPart As Object ' ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = doc.GetPart(0) ' первая деталь в сборке

    Dim iPar As Object ' ksUserParam
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
    Dim iItem As Object ' ksLtVariant
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
    Dim iArr As Object ' ksDynamicArray
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr = Kompas.GetDynamicArray(LTVARIANT_ARR)
    If iPar Is Nothing Or iItem Is Nothing Or iArr Is Nothing Then
      Exit Sub
    End If

    'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iPar.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar.SetUserArray(iArr)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.doubleVal = 12.12
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr.ksAddArrayItem(-1, iItem)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.doubleVal = 21.21
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr.ksAddArrayItem(-1, iItem)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.intVal = 666
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr.ksAddArrayItem(-1, iItem)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem.intVal = 999
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr.ksAddArrayItem(-1, iItem)

    'UPGRADE_WARNING: Couldn't resolve default property of object iPart.SetUserParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart.SetUserParam(iPar) ' установка пользовательской структуры
    'UPGRADE_WARNING: Couldn't resolve default property of object iPart.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart.Update()

    'UPGRADE_WARNING: Couldn't resolve default property of object iPart.GetUserParamSize. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Kompas.ksMessage("Размер пользовательской структуры = " & iPart.GetUserParamSize) ' размер пользовательской структуры

    Dim iPar2 As Object ' ksUserParam
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar2 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
    Dim iItem2 As Object ' ksLtVariant
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2 = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
    Dim iArr2 As Object ' ksDynamicArray
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2 = Kompas.GetDynamicArray(LTVARIANT_ARR)
    If iPar2 Is Nothing Or iItem2 Is Nothing Or iArr2 Is Nothing Then
      Exit Sub
    End If

    'UPGRADE_WARNING: Couldn't resolve default property of object iPar2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar2.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iPar2.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar2.SetUserArray(iArr2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.doubleVal = 3.3
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksAddArrayItem(-1, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.doubleVal = 6.6
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksAddArrayItem(-1, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.intVal = 123
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksAddArrayItem(-1, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.Init()
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItem2.intVal = 321
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksAddArrayItem(-1, iItem2)

    'UPGRADE_WARNING: Couldn't resolve default property of object iPart.GetUserParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart.GetUserParam(iPar2) ' берем пользовательскeую структуру

    Dim a, b As Double
    Dim c, d As Short
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksGetArrayItem(0, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    a = iItem2.doubleVal
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksGetArrayItem(1, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.doubleVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    b = iItem2.doubleVal
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksGetArrayItem(2, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    c = iItem2.intVal
    'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iArr2.ksGetArrayItem(3, iItem2)
    'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    d = iItem2.intVal
    'Kompas.ksMessage "a = " & a
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Kompas.ksMessage("Переменные пользовательского массива a = " & a & " b = " & b & " c = " & c & " d = " & d) ' просмотрим переменные из пользовательского массива
  End Sub

  Sub CreateDocument3D() ' Создание документа 3D
    Dim doc As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Document3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc = Kompas.Document3D
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If Not doc Is Nothing And doc.Create(False, True) Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.author = "Автор" ' Автор документа
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.comment = "Пример документа 3D" ' Комментарии к документу
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.FileName = "c:\example.m3d" ' Имя файла Документа
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.UpdateDocumentParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.UpdateDocumentParam() ' Обновить параметры Документа
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.Save. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.Save() ' Сохранить документ
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Сохраним документ под другим именем")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.SaveAs. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.SaveAs("c:\example_1.m3d") ' сохранить документ под другим именем

      ' Автор документа
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Автор документа: " & doc.author)
      ' Комментарий к документу
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Комментарий к документу: " & doc.comment)
      ' Имя файла
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Имя файла: " & doc.FileName)

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.Close. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.Close() ' закроем документ
    End If
  End Sub

  Sub DocIterator()
    Dim i As Object ' итератор по документам
    Dim arrDoc As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arrDoc = Kompas.GetDynamicArray(CHAR_STR_ARR) ' динамический массив указателей на строки символов
    ' если массив создан запускаем диалог выбора файлов
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksChoiceFiles. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim item As Object
    Dim doc As Object
    If Not arrDoc Is Nothing And Kompas.ksChoiceFiles("*.m3d", "Документы (*.m3d)|*.m3d|Все файлы (*.*)|*.*|", arrDoc, False) Then
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      item = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)
      If Not item Is Nothing Then
        ' откроем все файлы указанные пользователем
        'UPGRADE_WARNING: Couldn't resolve default property of object arrDoc.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        For i = 0 To arrDoc.ksGetArrayCount() - 1
          'UPGRADE_WARNING: Couldn't resolve default property of object arrDoc.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If arrDoc.ksGetArrayItem(i, item) Then
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Document3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc = Kompas.Document3D
            'UPGRADE_WARNING: Couldn't resolve default property of object item.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.Open. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.Open(item.Str, False) ' открываем файл с заданным именем
          End If
        Next i
      End If
    End If

    ' создаем итератор по документам
    Dim iter As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iter = Kompas.GetIterator()
    'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim ref As Integer
    Dim doc2 As Object ' референс документа
    If Not iter Is Nothing And iter.ksCreateIterator(D3_DOCUMENT_OBJ, 0) Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ref = iter.ksMoveIterator("F")
      If ref Then ' смещаем итератор на первый элемент
        Do  ' смещаем итератор на следующую позицию
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksGet3dDocumentFromRef. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc2 = Kompas.ksGet3dDocumentFromRef(ref)
          If Not doc2 Is Nothing Then
            ' автор документа
            'UPGRADE_WARNING: Couldn't resolve default property of object doc2.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("Автор документа: " & doc2.author)
            ' комментарии к документу
            'UPGRADE_WARNING: Couldn't resolve default property of object doc2.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("Комментарий к документу: " & doc2.comment)
            ' имя файла документа
            'UPGRADE_WARNING: Couldn't resolve default property of object doc2.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("Имя файла: " & doc2.FileName)
            ' тип документа
            'UPGRADE_WARNING: Couldn't resolve default property of object doc2.IsDetail. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If doc2.IsDetail Then
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              Kompas.ksMessage("Тип документа: Деталь")
            Else
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              Kompas.ksMessage("Тип документа: Сборка")
            End If
          End If
          'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          ref = iter.ksMoveIterator("N")
        Loop While ref
      End If

      ' сообщаем количество открытых файлов
      'UPGRADE_WARNING: Couldn't resolve default property of object arrDoc.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      Kompas.ksMessage("Открыто " & arrDoc.ksGetArrayCount() & " файлов")

      'UPGRADE_WARNING: Couldn't resolve default property of object iter.ksDeleteIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iter.ksDeleteIterator() ' удалить итератор
    End If

  End Sub

  Sub UseEntityCollection()
    Dim i As Object ' использование массива элементов
    Dim doc As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc = Kompas.ActiveDocument3D ' привязываемся к активному документу
    Dim part As Object
    Dim collect As Object
    Dim count As Short
    Dim count1 As Short
    Dim count2 As Short
    Dim ent As Object
    Dim faceDef As Object
    Dim colorPr As Object
    Dim collect2 As Object
    Dim ent2 As Object
    Dim edgeDef As Object ' ksEdgeDefinition ' ksEntity ' ksEntityCollection ' ksColorProperty - интерфейс свойств цвета ' ksFaceDefinition
    If Not doc Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      part = doc.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент
      If Not part Is Nothing Then
        ' массив поверхностей
        'UPGRADE_WARNING: Couldn't resolve default property of object part.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        collect = part.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_face)

        'UPGRADE_WARNING: Couldn't resolve default property of object collect.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count = collect.GetCount
        count1 = 0 ' количество плоских поверхностей
        count2 = 0 ' количество конических поверхностей

        If Not collect Is Nothing And count Then
          For i = 0 To count - 1
            'UPGRADE_WARNING: Couldn't resolve default property of object collect.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            ent = collect.GetByIndex(i)
            ' интерфейс свойств поверхности
            'UPGRADE_WARNING: Couldn't resolve default property of object ent.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            faceDef = ent.GetDefinition

            'UPGRADE_WARNING: Couldn't resolve default property of object ent.ColorParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            colorPr = ent.ColorParam

            If Not faceDef Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object faceDef.IsCylinder. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object faceDef.IsCone. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If faceDef.IsCone Or faceDef.IsCylinder Then ' коническая по-ть
                'UPGRADE_WARNING: Couldn't resolve default property of object colorPr.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                colorPr.COLOR = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.Blue)
                count2 = count2 + 1 ' считаем количество объектов
              End If

              'UPGRADE_WARNING: Couldn't resolve default property of object faceDef.IsPlanar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If faceDef.IsPlanar Then ' плоская по-ть
                'UPGRADE_WARNING: Couldn't resolve default property of object colorPr.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                colorPr.COLOR = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.Lime)
                count1 = count1 + 1 ' считаем количество объектов
              End If

              'UPGRADE_WARNING: Couldn't resolve default property of object ent.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ent.Update() ' обновить параметры
            End If
          Next i
        End If

        ' сообщяем о результатах работы
        If count = 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("Не найдено ни одной поверхности")
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Kompas.ksMessage("Найдено " & count2 & " коничечких и " & count1 & " плоских объектов")
        End If

        count1 = 0
        count2 = 0
        ' массив ребер
        'UPGRADE_WARNING: Couldn't resolve default property of object part.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        collect2 = part.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_edge)
        'UPGRADE_WARNING: Couldn't resolve default property of object collect2.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count = collect2.GetCount
        If Not collect2 Is Nothing And count Then
          For i = 0 To count - 1
            'UPGRADE_WARNING: Couldn't resolve default property of object collect2.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            ent2 = collect2.GetByIndex(i)
            'UPGRADE_WARNING: Couldn't resolve default property of object ent2.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            edgeDef = ent2.GetDefinition
            If Not edgeDef Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object edgeDef.IsStraight. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If edgeDef.IsStraight Then
                count1 = count1 + 1 ' количество прямых ребер
              Else
                count2 = count2 + 1 ' количество криволинейных ребер
              End If
            End If
          Next i

          ' сообщяем о результатах работы
          If count = 0 Then
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("Не найдено ни одного ребра")
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ksMessage("Найдено " & count1 & " прямых и " & count2 & " криволинейных ребер")
          End If
        End If
      End If
    End If
  End Sub


  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Object)
    Kompas = kompas_

    Dim doc As Object
    Select Case command_Renamed
      Case 1
        CreateDocument3D() ' Создание документа
      Case 2
        DocIterator() ' итератор по документам
      Case 3
        UseEntityCollection() ' использование массива элементов
      Case Else
        'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc = Kompas.ActiveDocument3D
        If Not doc Is Nothing Then
          Select Case command_Renamed
            Case 4 : GetSetPartName(doc) ' взять/изменить имя компоненты
            Case 5 : FixAndStandartComponent(doc) ' фиксирование и установка стандартного объекта
            Case 6 : GetSetColorProperty(doc) ' получить и заменить параметры цвета компоненты
            Case 7 : GetSetArrayVariable(doc) ' взять и поменять внешние переменные компоненты
            Case 8 : GetSetPlacmentComponent(doc) ' получить и изменить место расположения детали в сборке
            Case 9 : GetSetEntity(doc) ' Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
            Case 10 : CreateSketch(doc) ' создать эскиз
            Case 11 : GetArraySketch(doc) ' Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
            Case 12 : GetSetUserParamComponent(doc) ' Установить и получить параметры пользователя в компоненте
          End Select
        End If
    End Select
  End Sub

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String

    Select Case number
      Case 1
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Создание 3D документа"
        command_Renamed = 1
      Case 2
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Итератор по документам"
        command_Renamed = 2
      Case 3
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Массивы элементов"
        command_Renamed = 3
      Case 4
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Взять и поменять имя компоненты"
        command_Renamed = 4
      Case 5
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Фиксирование и установка стандартного объекта"
        command_Renamed = 5
      Case 6
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Получить и заменить параметры цвета компоненты"
        command_Renamed = 6
      Case 7
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Взять и поменять внешние переменные компоненты"
        command_Renamed = 7
      Case 8
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Получить и изменить расположение детали в сборке"
        command_Renamed = 8
      Case 9
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Получить и изменить парметры базовой плоскости"
        command_Renamed = 9
      Case 10
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Создать эскиз"
        command_Renamed = 10
      Case 11
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Вернуть массив эскизов"
        command_Renamed = 11
      Case 12
        itemType = 1 'MENUITEM'
        ExternalMenuItem = "Установить и получить параметры пользователя в компоненте"
        command_Renamed = 12
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