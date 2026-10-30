Option Strict Off
Option Explicit On

Imports System.Reflection
Imports System.Runtime.InteropServices
Imports Microsoft.Win32


<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step2")> _
Public Class Step2
  ' step2.cls - Математика
  '
  ' 1. Пересечь прямые                      - Intersect2Line
  ' 2. Пересечь кривые                      - Intersect2Curve
  ' 3. Пересечь отрезок и дугу              - IntersectLineSegArc
  ' 4. Касательная из точки                 - TanLinePointCircle
  ' 5. Касательная под углом                - TanLineAngCircle
  ' 6. Поворот точки                        - RotatePoint
  ' 7. Симметрия точки                      - SymmetryPoint
  ' 8. Сопрягающие окружности к двум прямым - Couplin2Lines
  ' 9. Перепендикуляр                       - Perpendicular

  ' Переменные класса
  Dim iKompasObject As Kompas6API5.Application ' Интерфейс KompasObject
  Dim iDocument2D As Kompas6API5.Document2D ' Интерфейс ksDocument2D
  Dim iMathematic2D As Kompas6API5.Mathematic2D ' Интерфейс ksMathematic2D

  ' Отрисовка точек пересечения в документе iDocument2D по присланному массиву и выдача пользователю их координат

  Sub DrawPointByArray(ByRef iDynamicArray As Object)
    Dim i As Object
    Dim iMathPointParam As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    If Not iDynamicArray Is Nothing Then
      ' Создать интерфейс параметров математической точки
      iMathPointParam = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

      If Not iMathPointParam Is Nothing Then ' Интерфейс создан

        For i = 0 To iDynamicArray.ksGetArrayCount - 1 ' Выдать параметры точек в присланном массиве
          iDynamicArray.ksGetArrayItem(i, iMathPointParam) ' Параметры текущей точки
          ' Нарисовать точку в документе
          iDocument2D.ksPoint(iMathPointParam.x, iMathPointParam.y, 5)
          ' Выдать сообщение с координатами нарисованной точки
          iKompasObject.ksMessage("x = " & iMathPointParam.x & " y = " & iMathPointParam.y)
        Next  ' Следующая точка
      End If
    End If
  End Sub

  ' Пересечь прямые

  Sub Intersect2Line()
    Dim iDynamicArray As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    iDynamicArray = iKompasObject.GetDynamicArray(POINT_ARR)

    If Not iDynamicArray Is Nothing Then ' Интерфейс создан
      iDocument2D.ksLine(10, 10, 0) ' Отрисовка прямых
      iDocument2D.ksLine(15, 5, 90) '
      ' Точка на первой прямой (10, 10), Угол первой прямой = 0,
      ' Точка на второй прямой (15, 5), Угол второй прямой = 90
      ' Получить координаты точки пересечения двух прямых
      iMathematic2D.ksIntersectLinLin(10, 10, 0, 15, 5, 90, iDynamicArray)

      DrawPointByArray(iDynamicArray) ' Отрисовка точек пересечения

      iDynamicArray.ksDeleteArray() ' Удаление массива
    End If
  End Sub

  ' Пересечь кривые

  Sub Intersect2Curve()
    Dim iDynamicArray As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    iDynamicArray = iKompasObject.GetDynamicArray(POINT_ARR)

    Dim pp1 As Integer
    Dim pp2 As Integer ' Указатель на первый объект
    If Not iDynamicArray Is Nothing Then ' Массив создан

      iDocument2D.ksBezier(0, 0) ' Создание кривой Безье
      iDocument2D.ksPoint(20, 0, 0) ' Точки входящие в кривую Безье
      iDocument2D.ksPoint(10, 20, 0)
      iDocument2D.ksPoint(20, 40, 0)
      iDocument2D.ksPoint(30, 20, 0)
      iDocument2D.ksPoint(20, 0, 0)
      ' Функция EndObj возвращает указатель на созданный объект кривой Безье
      pp1 = iDocument2D.ksEndObj

      iDocument2D.ksBezier(0, 0) ' Создание кривой Безье
      iDocument2D.ksPoint(0, 20, 0) ' Точки входящие в кривую Безье
      iDocument2D.ksPoint(20, 10, 0)
      iDocument2D.ksPoint(40, 20, 0)
      iDocument2D.ksPoint(20, 30, 0)
      iDocument2D.ksPoint(0, 20, 0)
      pp2 = iDocument2D.ksEndObj

      ' Пересечение 2-х кривых, могут быть геометрические объекты: отрезки,
      ' окружности, дуги, эллипсы, кривые, контуры, эквидистанты, макробъекты
      iMathematic2D.ksIntersectCurvCurv(pp1, pp2, iDynamicArray)

      DrawPointByArray(iDynamicArray) ' Отрисовка точек пересечения

      iDynamicArray.ksDeleteArray() ' Удаление массива
    End If
  End Sub

  ' пересечь отрезок и дугу

  Sub IntersectLineSegArc()
    Dim iDynamicArray As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    iDynamicArray = iKompasObject.GetDynamicArray(POINT_ARR)

    Dim a1 As Double
    Dim a2 As Double
    If Not iDynamicArray Is Nothing Then ' Массив создан
      iDocument2D.ksLineSeg(0, 40, 100, 40, 1) ' Отрисовка отрезка
      iDocument2D.ksArcByPoint(50, 40, 20, 30, 40, 70, 40, 1, 1) ' Отрисовка дуги по центру и конечным точкам
      a1 = iMathematic2D.ksAngle(50, 40, 30, 40) ' Начальный угол дуги
      a2 = iMathematic2D.ksAngle(50, 40, 70, 40) ' Конечный угол дуги

      ' Получить координаты точек пересечения отрезка и дуги
      ' Первая точка отрезка (0, 40), Вторая точка отрезка (100, 40),
      ' Центр дуги (50, 40), Радиус дуги 20
      iMathematic2D.ksIntersectLinSArc(0, 40, 100, 40, 50, 40, 20, a1, a2, 1, iDynamicArray)
      DrawPointByArray(iDynamicArray) ' Отрисовка точек пересечения

      iDynamicArray.ksDeleteArray() ' Удаление массива
    End If
  End Sub

  ' касательная из точки

  Sub TanLinePointCircle()
    Dim i As Object
    Dim iDynamicArray As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    iDynamicArray = iKompasObject.GetDynamicArray(POINT_ARR)

    Dim iMathPointParam As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Создать интерфейс параметров математической точки
    iMathPointParam = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    ' Интерфейсы созданы
    If (Not iDynamicArray Is Nothing) And (Not iMathPointParam Is Nothing) Then
      iDocument2D.ksPoint(10, 50, 3) ' Отрисовка точки
      iDocument2D.ksCircle(50, 10, 40, 1) ' Отрисовка окружности

      ' Получить точки касания окружности и прямой, проходящей через заданную точку
      ' Координаты внешней точки (10, 50), Координаты центра (50, 10),
      ' радиус окружности 40
      iMathematic2D.ksTanLinePointCircle(10, 50, 50, 10, 40, iDynamicArray)

      DrawPointByArray(iDynamicArray) ' Отрисовка точек пересечения


      ' Отрисовка касательных
      For i = 0 To iDynamicArray.ksGetArrayCount - 1
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iDynamicArray.ksGetArrayItem(i, iMathPointParam) ' Параметры текущей точки
        iDocument2D.ksLine(10, 50, iMathematic2D.ksAngle(10, 50, iMathPointParam.x, iMathPointParam.y))
      Next

      iDynamicArray.ksDeleteArray() ' Удаление массива
    End If
  End Sub

  ' касательная под углом

  Sub TanLineAngCircle()
    Dim i As Object
    Dim iDynamicArray As Kompas6API5.DynamicArray ' Интерфейс ksDynamicArray
    ' Создать интерфейс динамического массива математических точек
    iDynamicArray = iKompasObject.GetDynamicArray(POINT_ARR)

    Dim iMathPointParam As Kompas6API5.MathPointParam ' Интерфейс ksMathPointParam
    ' Создать интерфейс параметров математической точки
    iMathPointParam = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)

    ' Интерфейсы созданы
    If (Not iDynamicArray Is Nothing) And (Not iMathPointParam Is Nothing) Then

      iDocument2D.ksLineSeg(0, 40, 100, 40, 1) ' Отрисовка отрезка
      iDocument2D.ksCircle(50, 10, 40, 1) ' Отрисовка окружности

      ' Получить точки касания окружности и прямой, проходящей под заданным углом
      ' Координаты центра (50, 10), радиус окружности 40, Угол касательной прямой 45
      iMathematic2D.ksTanLineAngCircle(50, 10, 40, 45, iDynamicArray)

      DrawPointByArray(iDynamicArray) ' Отрисовка точек пересечения

      ' Отрисовка касательных
      For i = 0 To iDynamicArray.ksGetArrayCount - 1
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iDynamicArray.ksGetArrayItem(i, iMathPointParam) ' Параметры текущей точки
        iDocument2D.ksLine(iMathPointParam.x, iMathPointParam.y, 45)
      Next

      iDynamicArray.ksDeleteArray() ' Удаление массива
    End If
  End Sub

  ' поворот точки

  Sub RotatePoint()
    Dim x As Double ' Результат поворота точки
    Dim y As Double

    iDocument2D.ksPoint(60, 50, 3) ' Отрисовка точки
    iDocument2D.ksPoint(50, 50, 2) ' Отрисовка точки

    iMathematic2D.ksRotate(60, 50, 50, 50, 180, x, y) ' Поворот точки относительно центра

    iDocument2D.ksPoint(x, y, 5) ' Отрисовка результирующей точки
    iKompasObject.ksMessage("x = " & x & " y = " & y) ' Результат поворота
  End Sub

  ' симметрия точки

  Sub SymmetryPoint()
    Dim x As Double ' Результат симметрии точки
    Dim y As Double

    iDocument2D.ksPoint(30, 60, 3) ' Отрисовка точки
    iDocument2D.ksLineSeg(0, 50, 60, 50, 3) ' Отрисовка отрезка

    ' Получить координаты точки, симметричной относительно заданной оси
    iMathematic2D.ksSymmetry(30, 60, 0, 50, 60, 50, x, y)

    iDocument2D.ksPoint(x, y, 5) ' Отрисовка результирующей точки
    iKompasObject.ksMessage("x = " & x & " y = " & y) ' Результат симметрии
  End Sub

  ' сопрягающие окружности к двум прямым

  Sub Couplin2Lines()
    Dim i As Object
    Dim iCON As Kompas6API5.CON ' Интерфейс ksCON
    ' Создать интерфейс массива координат точек сопряжения
    iCON = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_CON)

    If Not iCON Is Nothing Then ' Интерфейс создан
      iDocument2D.ksLine(100, 100, 45) ' Отрисовка прямых - Первая прямая
      iDocument2D.ksLine(100, 100, -45) ' Вторая прямая

      ' Получить параметры окружностей, касательной к двум прямым
      ' Радиус сопряжения 20
      iMathematic2D.ksCouplingLineLine(100, 100, 45, 100, 100, -45, 20, iCON)

      ' Отрисовка сопрягающихся окружностей и точек касания
      For i = 0 To iCON.GetCount
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iDocument2D.ksCircle(iCON.GetXc(i), iCON.GetYc(i), 20, 2)
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iDocument2D.ksPoint(iCON.GetX1(i), iCON.GetY1(i), i)
        'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iDocument2D.ksPoint(iCON.GetX2(i), iCON.GetY2(i), i)
      Next

      ' Результат сопряжения
      iKompasObject.ksMessage("count = " & iCON.GetCount & "con[0].x1 = " & iCON.GetX1(0) & " con[0].y1 = " & iCON.GetY1(0) & "con[0].x2 = " & iCON.GetX2(0) & " con[0].y2 = " & iCON.GetY2(0) & " ...")
    End If
  End Sub

  ' перепендикуляр

  Sub Perpendicular()
    iDocument2D.ksPoint(50, 50, 2) ' Отрисовка точки
    iDocument2D.ksLineSeg(60, 10, 100, 10, 1) ' Отрисовка отрезка

    Dim x As Double ' Точка пересечения отрезка и перпендикуляра
    Dim y As Double

    ' Координаты точки пересечения отрезка и перпендикуляра
    ' Координаты произвольной внешней точки (50, 50)
    ' Координаты первой точки отрезка (60, 10), Координаты второй точки отрезка (100, 10)
    iMathematic2D.ksPerpendicular(50, 50, 60, 10, 100, 10, x, y) '

    iDocument2D.ksLine(50, 50, iMathematic2D.ksAngle(50, 50, x, y)) ' Отрисовка перпендикуляра
    iDocument2D.ksPoint(x, y, 5) ' Отрисовка точки пересечения отрезка

    iKompasObject.ksMessage("x = " & x & " y = " & y) ' Результат расчета перпендикуляра
  End Sub

  ' Определить имя библиотеки

  Public Function GetLibraryName() As String
    GetLibraryName = "Использованиe математических функций" ' Имя библиотеки
  End Function

  ' Сформировать меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1 ' Команда 1 - пересечь прямые
        ExternalMenuItem = "пересечь прямые"
        command_Renamed = 1
      Case 2 ' Команда 2 - пересечь кривые
        ExternalMenuItem = "пересечь кривые"
        command_Renamed = 2
      Case 3 ' Команда 3 - пересечь отрезок и дугу
        ExternalMenuItem = "пересечь отрезок и дугу"
        command_Renamed = 3
      Case 4 ' Команда 4 - касательная из точки
        ExternalMenuItem = "касательная из точки"
        command_Renamed = 4
      Case 5 ' Команда 5 - касательная под углом
        ExternalMenuItem = "касательная под углом"
        command_Renamed = 5
      Case 6 ' Команда 6 - поворот точки
        ExternalMenuItem = "поворот точки"
        command_Renamed = 6
      Case 7 ' Команда 7 - симметрия точки
        ExternalMenuItem = "симметрия точки"
        command_Renamed = 7
      Case 8 ' Команда 8 - сопрягающие окружности к двум прямым
        ExternalMenuItem = "сопрягающие окружности к двум прямым"
        command_Renamed = 8
      Case 9 ' Команда 9 - перепендикуляр
        ExternalMenuItem = "перепендикуляр"
        command_Renamed = 9
      Case Else
        ' Завершение формирования меню
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  ' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Kompas6API5.Application)
    iKompasObject = Kompas ' Интерфейс приложения КОМПАС

    If iKompasObject Is Nothing Then ' Если интерфейс не задан - выходим
      Exit Sub ' и ничего не делаем
    End If

    iDocument2D = iKompasObject.ActiveDocument2D ' Возьмем интерфейс текущего 2D документа

    If iDocument2D Is Nothing Then ' Если документа нет или текущий не 2D документ
      Exit Sub ' Выйдем из процедуры ничего не делая
    End If

    iMathematic2D = iKompasObject.GetMathematic2D ' Возьмем интерфейс математических функций

    If iMathematic2D Is Nothing Then ' Если интерфейс получить не удалось
      Exit Sub ' Выйдем из процедуры ничего не делая
    End If

    Select Case command_Renamed ' Определим выполняемую команду
      Case 1
        Intersect2Line() ' пересечь прямые
      Case 2
        Intersect2Curve() ' пересечь кривые
      Case 3
        IntersectLineSegArc() ' пересечь отрезок и дугу
      Case 4
        TanLinePointCircle() ' касательная из точки
      Case 5
        TanLineAngCircle() ' касательная под углом
      Case 6
        RotatePoint() ' поворот точки
      Case 7
        SymmetryPoint() ' симметрия точки
      Case 8
        Couplin2Lines() ' сопрягающие окружности к двум прямым
      Case 9
        Perpendicular() ' перепендикуляр
    End Select

    iKompasObject.ksMessageBoxResult() ' Результат выполнения команды

  End Sub

  Public Function ExternalGetResourceModule() As Object

    ExternalGetResourceModule = Assembly.GetExecutingAssembly().Location
  End Function


  Public Function GetImageHeight() As Integer
    GetImageHeight = 100
  End Function

  Public Function GetImageWidth() As Integer
    GetImageWidth = 100
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