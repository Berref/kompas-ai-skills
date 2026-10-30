Option Strict Off
Option Explicit On
Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step5")> _
Public Class Step5
  Dim iKompasObject As Object 'KompasObject
  Sub DrawTransform(ByRef doc As Object) ' трансформация объекта по матрице
    ' трансформация  рабочей группы
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(-30, -30, 0, 1, 1)
    Dim ref As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ref = doc.ksNewGroup(0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(30, 30, 60, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(60, 30, 60, 60, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(60, 60, 30, 60, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(30, 60, 30, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksHatch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksHatch(0, 45, 2, 0, 0, 0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(30, 30, 60, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(60, 30, 60, 60, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(60, 60, 30, 60, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(30, 60, 30, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndObj()
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndGroup()
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()

    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompasObject.ksMessage("создали матрицу 20, 20, 45, 2")

    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(20, 20, 45, 2, 2)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksTransformObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksTransformObj(ref)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()

    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompasObject.ksMessageBoxResult()
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompasObject.ksMessage("вернем обратно")

    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(-20, -20, 0, 1, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksTransformObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksTransformObj(ref)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()

    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(0, 0, 0, 0.5, 0.5)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksTransformObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksTransformObj(ref)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()

    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(0, 0, -45, 1, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksTransformObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksTransformObj(ref)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()
  End Sub

  Sub DrawCopy(ByRef doc As Object) ' копирование объекта
    Dim iPar As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewParam)

    Dim number As Integer
    Dim v As Integer
    If Not iPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.x = 20
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.y = 60
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.scale_ = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.COLOR = RGB(10, 20, 10)
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.state. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.state = stACTIVE
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Name = "user view"

      number = 5
      ' создали вид
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateSheetView. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      v = doc.ksCreateSheetView(iPar, number)
      ' создали слой
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLayer. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksLayer(5)

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksLineSeg(20, 10, 20, 30, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksLineSeg(20, 30, 40, 30, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksLineSeg(40, 30, 40, 10, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksLineSeg(40, 10, 20, 10, 1)

      ' копируем вид ( для вида точки задаются в листовых координатах )
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCopyObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksCopyObj(v, 20, 60, 40, 80, 1, 0)
    End If
  End Sub
  Sub DrawSymmetry(ByRef doc As Object) ' симметрия объекта
    Dim grp As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    grp = doc.ksNewGroup(0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(20, 10, 20, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(20, 30, 40, 30, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(40, 30, 40, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(40, 10, 20, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndGroup()

    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSymmetryObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksSymmetryObj(grp, 40, 10, 40, 20, "1")
  End Sub
  Sub EditTolerance(ByRef doc As Object) ' просмотр допуска формы
    ' редактирование допуска формы
    Dim pObj As Integer

    Dim iInfo As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iInfo = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)

    Dim x As Double
    Dim y As Double
    Dim j As Integer
    Dim typeObj As Short
    Dim numb As Integer
    '    Dim buf As String
    Dim iPar As Object
    Dim iPar2 As Object
    Dim iArrpTextItem As Object
    Dim iItem As Object
    Dim iTextItemFont As Object ' ksTextItemFont ' ksTextItemParam ' ksDynamicArray
    If Not iInfo Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iInfo.prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iInfo.prompt = "Укажите допуск формы"
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      j = doc.ksCursor(iInfo, x, y, Nothing)
      If j Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        pObj = doc.ksFindObj(x, y, 1000000)
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If j And doc.ksExistObj(pObj) Then
          ' узнаем тип объекта
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          typeObj = doc.ksGetObjParam(pObj, Nothing, 0) ' указатель на графический объект
          If typeObj = TOLERANCE_OBJ Then
            ' открыть допуск формы для редактирования
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksOpenTolerance. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksOpenTolerance(pObj)
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ToleranceParam)
            If Not iPar Is Nothing Then
              ' параметры допуска формы
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksGetObjParam(pObj, iPar, ALLPARAM)
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.tBase. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessage("базовая точка = " & iPar.tBase & " стиль = " & iPar.Style & " расположение " & iPar.Type & " x = " & iPar.x & " y = " & iPar.y)
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iPar2 = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
              If Not iPar2 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of object iPar2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iPar2.Init()
                ' в цикле будем брать все существующие ячейки
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetToleranceColumnText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                Do While (doc.ksGetToleranceColumnText(numb, iPar2))
                  'UPGRADE_WARNING: Couldn't resolve default property of object iPar2.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iKompasObject.ksMessage("номер = " & numb & " стиль = " & iPar2.Style)
                  'UPGRADE_WARNING: Couldn't resolve default property of object iPar2.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iArrpTextItem = iPar2.GetTextItemArr
                  'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
                  If Not iArrpTextItem Is Nothing And Not iItem Is Nothing Then
                    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iItem.Init()
                    'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    For j = 0 To iArrpTextItem.ksGetArrayCount - 1
                      'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iArrpTextItem.ksGetArrayItem(j, iItem)
                      'UPGRADE_WARNING: Couldn't resolve default property of object iItem.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iTextItemFont = iItem.GetItemFont
                      'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      If iItem.Type Then
                        'UPGRADE_WARNING: Couldn't resolve default property of object iItem.iSNumb. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        iKompasObject.ksMessage("компонента = " & j & " тип = " & iItem.Type & " номер спецзнака = " & iItem.iSNumb)
                      Else
                        'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.bitVector. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        iKompasObject.ksMessage("компонента = " & j & " h = " & iTextItemFont.HEIGHT & " s = " & iItem.s & " fontName = " & iTextItemFont.FontName & " битвектор = " & iTextItemFont.bitVector)
                      End If
                      'UPGRADE_WARNING: Couldn't resolve default property of object iItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iItem.s = "Допуск формы"
                      'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iArrpTextItem.ksSetArrayItem(j, iItem)
                    Next
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetToleranceColumnText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksSetToleranceColumnText(numb, iPar2)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iArrpTextItem.ksDeleteArray() ' удалим массив компонент
                  End If
                Loop
                ' заменим параметры
                'UPGRADE_WARNING: Couldn't resolve default property of object iPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iPar.x = iPar.x + 10
                'UPGRADE_WARNING: Couldn't resolve default property of object iPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iPar.y = iPar.y + 10
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksSetObjParam(pObj, iPar, ALLPARAM)
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksEndObj() ' закрыли объект "допуск формы"
              End If
            End If
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksError("это не допуск формы")
          End If
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksError("нет объекта")
        End If
      End If
    End If
  End Sub
  Sub EditTolerance1(ByRef doc As Object) ' редактирование допуска формы

  End Sub
  Sub EditTable(ByRef doc As Object)
    Dim i As Object ' просмотр таблицы
    ' редактирование таблицы
    Dim pObj As Integer
    Dim iInfo As Object
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iInfo = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim x As Double
    Dim y As Double
    Dim j As Integer
    Dim typeObj As Short
    Dim numb As Integer
    Dim iPar As Object
    Dim iArrpLineText As Object
    Dim iItemLineText As Object
    Dim iArrpTextItem As Object
    Dim iItem As Object
    Dim iTextItemFont As Object ' ksTextItemFont ' ksTextLineParam ' ksDynamicArray ' ksTextParam
    If Not iInfo Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iInfo.prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iInfo.prompt = "Укажите таблицу"
      ' взять таблицу на чертеже
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      j = doc.ksCursor(iInfo, x, y, Nothing)
      If j Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        pObj = doc.ksFindObj(x, y, 100000)
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If j And doc.ksExistObj(pObj) Then
          ' узнаем тип объекта
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          typeObj = doc.ksGetObjParam(pObj, Nothing, 0) ' указатель на графический объект
          ' проверить полученный объкет  - таблица
          If typeObj = TABLE_OBJ Then
            ' открыть таблицу для редактирования
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksOpenTable. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksOpenTable(pObj)
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextParam)
            If Not iPar Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iPar.Init()
              ' в цикле будем брать все существующие ячейки
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetTableColumnText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              Do While ((doc.ksGetTableColumnText(numb, iPar)))
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksMessage("numb = " & numb)
                'UPGRADE_WARNING: Couldn't resolve default property of object iPar.GetTextLineArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iArrpLineText = iPar.GetTextLineArr
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iItemLineText = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
                If Not iItemLineText Is Nothing And Not iArrpLineText Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iItemLineText.Init()
                  'UPGRADE_WARNING: Couldn't resolve default property of object iArrpLineText.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  For i = 0 To iArrpLineText.ksGetArrayCount - 1
                    'UPGRADE_WARNING: Couldn't resolve default property of object iArrpLineText.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iArrpLineText.ksGetArrayItem(i, iItemLineText)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iKompasObject.ksMessage("i = " & i & " style = " & iItemLineText.Style)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iArrpTextItem = iItemLineText.GetTextItemArr
                    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iItem.Init()
                    If Not iItem Is Nothing And Not iArrpTextItem Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      For j = 0 To iArrpTextItem.ksGetArrayCount - 1
                        'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        iArrpTextItem.ksGetArrayItem(j, iItem)
                        'UPGRADE_WARNING: Couldn't resolve default property of object iItem.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        iTextItemFont = iItem.GetItemFont
                        'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        If iItem.Type Then
                          'UPGRADE_WARNING: Couldn't resolve default property of object iItem.GetISNumb. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iKompasObject.ksMessage("компонента = " & j & " тип = " & iItem.Type & " номер спецзнака = " & iItem.GetISNumb)
                        Else
                          'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.bitVector. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iKompasObject.ksMessage("компонента = " & j & " h = " & iTextItemFont.HEIGHT & " s = " & iItem.s & " fontName = " & iTextItemFont.FontName & " битвектор = " & iTextItemFont.bitVector)
                        End If
                      Next
                      'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iArrpTextItem.ksDeleteArray() ' очистим массив компонент
                    End If
                  Next
                  ' очистим массив текстовых строк
                  'UPGRADE_WARNING: Couldn't resolve default property of object iArrpLineText.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iArrpLineText.ksDeleteArray()
                End If
              Loop
              ' берем ячейку 2
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksColumnNumber. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksColumnNumber(2)
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksText(0, 0, 0, 5, 1, 0, "вторая ячейка")

              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDivideTableItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksDivideTableItem(3, 1, 2)
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksColumnNumber. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksColumnNumber(4)
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksText(0, 0, 0, 5, 1, 0, "4")

              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksEndObj() ' закрыли объект "таблица"
            End If
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksError("это не таблица")
          End If
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksError("нет объекта")
        End If
      End If
    End If
  End Sub
  Sub EditTable1(ByRef doc As Object) ' редактирование таблицы

  End Sub
  Sub EditStamp(ByRef doc As Object)
    Dim j As Object
    Dim i As Object ' взять тексты граф и редактировать штамп
    Dim iStamp As Object ' ksStamp
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetStamp. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iStamp = doc.GetStamp()
    'UPGRADE_WARNING: Couldn't resolve default property of object iStamp.ksOpenStamp. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim numb As Integer
    Dim iArr As Object
    Dim iArrpLineText As Object
    Dim iItemLineText As Object
    Dim count As Short
    Dim iArrpTextItem As Object
    Dim iItem As Object
    Dim iTextItemFont As Object
    Dim iItem2 As Object
    Dim iItemFont As Object ' ksTextItemFont ' ksTextItemParam ' ksDynamicArray ' ksTextLineParam
    If Not iStamp Is Nothing And iStamp.ksOpenStamp Then
      ' в цикле будем брать все существующие графы
      'UPGRADE_WARNING: Couldn't resolve default property of object iStamp.ksGetStampColumnText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr = iStamp.ksGetStampColumnText(numb)
      Do While Not iArr Is Nothing 'numb
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("numb = " & numb)
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArrpLineText = iKompasObject.GetDynamicArray(TEXT_LINE_ARR)
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iItemLineText = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
        'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iItemLineText.Init()
        If Not iItemLineText Is Nothing And Not iArrpLineText Is Nothing And Not iArr Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          count = iArr.ksGetArrayCount
          For i = 0 To count - 1 'iArr.ksGetArrayCount - 1
            'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iArr.ksGetArrayItem(i, iItemLineText)
            'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksMessage("номер ячейки = " & i & " стиль = " & iItemLineText.Style)
            'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iArrpTextItem = iItemLineText.GetTextItemArr
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
            'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iItem.Init()
            If Not iArrpTextItem Is Nothing And Not iItem Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              For j = 0 To iArrpTextItem.ksGetArrayCount - 1
                'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iArrpTextItem.ksGetArrayItem(j, iItem)
                'UPGRADE_WARNING: Couldn't resolve default property of object iItem.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iTextItemFont = iItem.GetItemFont
                'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object j. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksMessage("компонента = " & j & " h = " & iTextItemFont.HEIGHT & " s = " & iItem.s & " fontName = " & iTextItemFont.FontName)
              Next
              'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iArrpTextItem.ksDeleteArray() ' очистим массив компонент
            End If
          Next
          ' очистим массив текстовых строк
          'UPGRADE_WARNING: Couldn't resolve default property of object iArrpLineText.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iArrpLineText.ksDeleteArray()
          'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iArr.ksDeleteArray()
        End If
        'UPGRADE_WARNING: Couldn't resolve default property of object iStamp.ksGetStampColumnText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArr = iStamp.ksGetStampColumnText(numb)
      Loop
      ' заменим  графу 2
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksColumnNumber. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksColumnNumber(2)
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItem2 = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
      'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItem2.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemFont = iItem2.GetItemFont()
      If Not iItem2 Is Nothing And Not iItemFont Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iItemFont.GetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iItemFont.GetBitVectorValue(NEW_LINE) ', True
        'UPGRADE_WARNING: Couldn't resolve default property of object iItem2.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iItem2.s = "графа 2"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksTextLine. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksTextLine(iItem2)
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of object iStamp.ksCloseStamp. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iStamp.ksCloseStamp()
    Else
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksError("Штамп не найден")
    End If
  End Sub
  Sub GetTextTT(ByRef doc As Object)
    Dim j As Object
    Dim i1 As Object
    Dim i As Object ' получить текст ТТ
    ' получим указатель на технические трбования
    Dim pTT As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetReferenceDocumentPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    pTT = doc.ksGetReferenceDocumentPart(1)
    Dim iTechnicalDemandParam As Object ' ksTechnicalDemandParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iTechnicalDemandParam = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TechnicalDemandParam)
    Dim ipGab As Object
    Dim count As Short
    Dim ipTextLine As Object
    Dim iItemLineText As Object
    Dim count1 As Short
    Dim iArrpTextItem As Object
    Dim iItem As Object
    Dim count2 As Short
    Dim iTextItemFont As Object ' ksTextItemFont ' ksDynamicArray
    If pTT And Not iTechnicalDemandParam Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iTechnicalDemandParam.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTechnicalDemandParam.Init()
      ' получим параметры описания ТТ
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(pTT, iTechnicalDemandParam, TECHNICAL_DEMAND_PAR)
      'UPGRADE_WARNING: Couldn't resolve default property of object iTechnicalDemandParam.GetPGab. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipGab = iTechnicalDemandParam.GetPGab
      'UPGRADE_WARNING: Couldn't resolve default property of object ipGab.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      count = ipGab.ksGetArrayCount
      'UPGRADE_WARNING: Couldn't resolve default property of object iTechnicalDemandParam.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("стиль = " & iTechnicalDemandParam.Style & " число страниц  TT = " & count)
      ' создадим массив текстовых строк
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipTextLine = iKompasObject.GetDynamicArray(TEXT_LINE_ARR)
      ' пройдемся по листам ТТ и получим текст
      For i = 0 To count - 1
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(pTT, ipTextLine, i)
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iItemLineText = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
        If Not iItemLineText Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iItemLineText.Init()
          'UPGRADE_WARNING: Couldn't resolve default property of object ipTextLine.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          count1 = ipTextLine.ksGetArrayCount
          For i1 = 0 To count1 - 1
            'UPGRADE_WARNING: Couldn't resolve default property of object ipTextLine.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            ipTextLine.ksGetArrayItem(i1, iItemLineText)
            'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object i1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksMessage("компонента = " & i1 & " style = " & iItemLineText.Style)
            'UPGRADE_WARNING: Couldn't resolve default property of object iItemLineText.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iArrpTextItem = iItemLineText.GetTextItemArr
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
            If Not iItem Is Nothing And Not iArrpTextItem Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iItem.Init()
              'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              count2 = iArrpTextItem.ksGetArrayCount
              For j = 0 To count2 - 1
                'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iArrpTextItem.ksGetArrayItem(j, iItem)
                'UPGRADE_WARNING: Couldn't resolve default property of object iItem.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iTextItemFont = iItem.GetItemFont
                'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object j. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksMessage("компонента = " & j & " h = " & iTextItemFont.HEIGHT & " s = " & iItem.s & " fontName = " & iTextItemFont.FontName)
              Next
              'UPGRADE_WARNING: Couldn't resolve default property of object iArrpTextItem.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iArrpTextItem.ksDeleteArray() ' очистим массив компонент
            End If
          Next
        End If
      Next
      'UPGRADE_WARNING: Couldn't resolve default property of object ipTextLine.ksDeleteArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipTextLine.ksDeleteArray() ' очистим массив текстовых строк
    Else
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksError("Технических требований нет")
    End If
  End Sub
  Sub ChangeTechnicalDemand(ByRef doc As Object)
    Dim j As Object
    Dim i As Object ' редактирование TT
    Dim ref As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetReferenceDocumentPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ref = doc.ksGetReferenceDocumentPart(1)
    Dim iPar As Object ' ksTechnicalDemandParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TechnicalDemandParam)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim iParLine As Object
    Dim count As Short
    Dim iParItem As Object
    Dim iArr As Object
    Dim count1 As Short ' ksDynamicArray ' ksTextItemParam ' ksTextLineParam
    If doc.ksGetObjParam(ref, iPar, TECHNICAL_DEMAND_PAR) Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.strCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("число строк TT = " & iPar.strCount)
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.GetPGab. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksOpenTechnicalDemand. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksOpenTechnicalDemand(iPar.GetPGab, iPar.Style)
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iParLine = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
      If Not iParLine Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iPar.strCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        count = iPar.strCount
        For i = 0 To count - 1
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksGetObjParam(ref, iParLine, TT_FIRST_STR + i)
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iParItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
          'UPGRADE_WARNING: Couldn't resolve default property of object iParLine.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iArr = iParLine.GetTextItemArr
          If Not iParItem Is Nothing And Not iArr Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            count1 = iArr.ksGetArrayCount
            For j = 0 To count1 - 1
              'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iArr.ksGetArrayItem(j, iParItem)
              'UPGRADE_WARNING: Couldn't resolve default property of object iParItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessage(iParItem.s)
              'UPGRADE_WARNING: Couldn't resolve default property of object iParItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iParItem.s = "" & i + 1 & "-я строка"
              'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iArr.ksSetArrayItem(j, iParItem)
            Next
          End If
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksSetObjParam(ref, iParLine, TT_FIRST_STR + i)
        Next
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCloseTechnicalDemand. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksCloseTechnicalDemand()
    End If
  End Sub
  Sub ShowInsertFragment(ByRef doc As Object) ' вставка фрагмента
    ' char libName[250];
    Dim res As Integer
    res = 1
    ' выберем  библиотеку фрагментов
    Dim libName As String
    Dim buf As String
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    libName = iKompasObject.ksChoiceFile("*.lfr", "Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|", 1)
    Dim iFr As Object
    Dim x, y As Double
    Dim iRub As Object
    Dim iType As Object
    Dim iFragment As Object
    Dim pDefFrg As Integer
    Dim iPar As Object
    Dim p As Integer
    Dim j As Short
    Dim ang As Double ' ksPlacementParam ' ksFragment ' ksPhantom
    If Len(libName) Then
      Do While res
        ' выбрать фрагмент в библиотеке фрагментов
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetFragmentLibrary. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iFr = iKompasObject.GetFragmentLibrary
        If Not iFr Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksChoiceFragmentFromLib. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          buf = iFr.ksChoiceFragmentFromLib(libName, res)
          If Len(buf) And res Then
            ' выделим имя вставки
            ' подготовим структуры фанома и запросов для Placement
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iRub = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Phantom)
            If Not iRub Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iRub.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iRub.Init()
              'UPGRADE_WARNING: Couldn't resolve default property of object iRub.phantom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iRub.phantom = 1
              'UPGRADE_WARNING: Couldn't resolve default property of object iRub.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iType = iRub.GetPhantomParam
              If Not iType Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of object iType.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iType.Init()
                'UPGRADE_WARNING: Couldn't resolve default property of object iType.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iType.scale_ = 1
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetFragment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iFragment = doc.GetFragment
                If Not iFragment Is Nothing Then
                  ' создадим описание  всавки фрагментов
                  'UPGRADE_WARNING: Couldn't resolve default property of object iFragment.ksFragmentDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  pDefFrg = iFragment.ksFragmentDefinition(buf, "Вставка фрагмента", 1)
                  If pDefFrg Then
                    ' во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iType.gr = doc.ksNewGroup(1)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PlacementParam)
                    If Not iPar Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iPar.Init()
                      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iPar.scale_ = 1
                      'UPGRADE_WARNING: Couldn't resolve default property of object iFragment.ksInsertFragment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      p = iFragment.ksInsertFragment(pDefFrg, 0, iPar)
                    End If
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksEndGroup()
                    j = 1
                    Do While j
                      'UPGRADE_WARNING: Couldn't resolve default property of object iType.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iType.angle = 0
                      'UPGRADE_WARNING: Couldn't resolve default property of object iType.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      ang = iType.angle
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      j = doc.ksPlacement(Nothing, x, y, ang, iRub)
                      If j Then
                        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCopyObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        doc.ksCopyObj(p, 0, 0, x, y, 1, ang)
                        ' iType.angle
                      End If
                    Loop
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksDeleteObj(iType.gr)
                  End If
                Else
                  'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iKompasObject.ksError("Ошибка создания описания вставки фрагмента")
                End If
              End If
            End If
          End If
        Else
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksError("Имя вставки не определено")
        End If
      Loop
    End If
  End Sub


  Sub EditFragmentLibrary(ByRef doc As Object) ' работа с библиотекой фрагментов
    'char libName[250];
    ' char buf [250];
    ' выберем  библиотеку фрагментов
    ' выберем  библиотеку фрагментов
    Dim libName As String
    Dim buf As String
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    libName = iKompasObject.ksChoiceFile("*.lfr", "Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|", 1)
    Dim iInfo As Object
    Dim iFr As Object
    Dim j, typeEdit As Short
    Dim nameFrg As String = ""
    Dim res As Integer
    Dim res2 As Integer ' ksFragmentLibrary ' ksRequestInfo
    If Len(libName) Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iInfo = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetFragmentLibrary. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFr = iKompasObject.GetFragmentLibrary
      If Not iInfo Is Nothing And Not iFr Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iInfo.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iInfo.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object iInfo.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iInfo.commandsString = "!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент "
        ' CString /*string*/ nameFrg;
        Do While j + 1
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCommandWindow. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          j = doc.ksCommandWindow(iInfo)
          Select Case j
            Case 1 ' Новый_фрагмент
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksReadString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              buf = iKompasObject.ksReadString("Введите имя нового фрагмента", "")
              If Len(buf) Then
                nameFrg = libName
                'if ( buf[0] != '|' )
                '  nameFrg += "|";
                nameFrg = nameFrg & "|" & buf
                typeEdit = 2 ' запустить на редактирование
              Else
                typeEdit = 0
              End If
            Case 2 ' Редактировать_фрагмент
              ' выберем имя файла фрагмента
              'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksChoiceFragmentFromLib. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              buf = iFr.ksChoiceFragmentFromLib(libName, res)
              If res And Len(buf) Then
                nameFrg = buf
                typeEdit = j ' 2- запустить на редактирование, 3-удалить ;
              Else
                typeEdit = 0
              End If
            Case 3 ' Удалить_фрагмент
              ' выберем имя файла фрагмента
              'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksChoiceFragmentFromLib. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              buf = iFr.ksChoiceFragmentFromLib(libName, res2)
              If res2 And Len(buf) Then
                nameFrg = buf
                typeEdit = j ' 2- запустить на редактирование, 3-удалить ;
              Else
                typeEdit = 0
              End If
          End Select
          If j > 0 And typeEdit And Not iFr Is Nothing And Len(nameFrg) Then
            'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksFragmentLibraryOperation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            res = iFr.ksFragmentLibraryOperation(nameFrg, typeEdit)
            If res Then
              If typeEdit = 2 Then
                'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksFragmentLibraryOperation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iFr.ksFragmentLibraryOperation(nameFrg, 4)
                ' редактируем фрагмент из библиотеки
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksText(0, 100, 0, 5, 1, 0, "Редактируем фрагмент из библиотеки")
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                doc.ksLineSeg(0, 100, 110, 100, 1)
                ' редактируем фрагмент в интерактивном режиме
                ' после выбора в меню "Сервис" команды "Закончить редактирование фрагмента",
                ' возвращаемся в библиотеку
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksSystemControlStart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksSystemControlStart("Закончить редактирование фрагмента")
                'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksFragmentLibraryOperation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iFr.ksFragmentLibraryOperation(nameFrg, 0)
              End If
            End If
          Else
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksMessageBoxResult()
          End If
        Loop
      End If
    End If
  End Sub
  Sub ShowInsertFragment1(ByRef doc As Object) ' вставка фрагмента россыпью
    Dim frwName As String
    Dim iFr As Object ' ksFragment
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.GetFragment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iFr = doc.GetFragment
    Dim x, y As Double
    Dim iRub As Object
    Dim iType As Object
    Dim iPar As Object
    Dim j As Short
    Dim ang As Double ' ksPlacementParam ' ksType1 ' ksPhantom
    If Not iFr Is Nothing Then
      ' выберем  фрагмент
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksChoiceFile. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      frwName = iKompasObject.ksChoiceFile("*.frw", "фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|", 1)
      If Len(frwName) Then
        ' подготовим структуры фанома и запросов для Placement
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iRub = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Phantom)
        If Not iRub Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iRub.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iRub.Init()
          'UPGRADE_WARNING: Couldn't resolve default property of object iRub.phantom. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iRub.phantom = 1
          'UPGRADE_WARNING: Couldn't resolve default property of object iRub.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iType = iRub.GetPhantomParam
          If Not iType Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object iType.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iType.Init()
            'UPGRADE_WARNING: Couldn't resolve default property of object iType.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iType.scale_ = 1
            ' во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PlacementParam)
            If Not iPar Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iPar.Init()
              'UPGRADE_WARNING: Couldn't resolve default property of object iPar.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iPar.scale_ = 1
              j = 1
              Do While j
                ' если нужно вставить несколько фрагментов, группу лучше порождать новую,
                ' так как вместе с геометрией могут придти атрибуты, объекты спецификации, стили,
                ' которые связаны с геометрией. При простом копировании группы эта связь будет потеряна.
                'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of object iFr.ksReadFragmentToGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iType.gr = iFr.ksReadFragmentToGroup(frwName, 0, iPar)
                'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If iType.gr Then
                  'UPGRADE_WARNING: Couldn't resolve default property of object iType.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  ang = iType.angle
                  'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksPlacement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  j = doc.ksPlacement(Nothing, x, y, ang, iRub)
                  If j Then
                    ' сдвигаем группу
                    '                  doc.ksCopyObj p, 0, 0, x, y, 1, ang
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMoveObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksMoveObj(iType.gr, x, y)
                    If ang > 0.001 Then
                      'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksRotateObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksRotateObj(iType.gr, x, y, ang)
                    End If
                    ' ставим группу в модель
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksStoreTmpGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksStoreTmpGroup(iType.gr)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksClearGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksClearGroup(iType.gr, True)
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksDeleteObj(iType.gr)
                  End If
                Else
                  'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  If iType.gr Then
                    'UPGRADE_WARNING: Couldn't resolve default property of object iType.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    doc.ksDeleteObj(iType.gr)
                  End If
                  j = 0
                End If
              Loop
            End If
          End If
        End If
      End If
    End If
  End Sub


  Public Sub ExtractFromListBox() 'hControl As Long)

    'Dim sBuf As String * 50
    'Dim cBuf As Long

    'cBuf = "12 34 56"
    'sBuf = String$(cBuf + 1, "t")
    'iKompasObject.ksError sBuf

    'Dim s As String
    's = "helpmeplease"
    'iKompasObject.ksError s
    's = s & "z"
    'For i = 1 To 20
    '  iKompasObject.ksError s(i) 'MidB(s, i)
    'Next
    'Dim arrArgVal As String
    'arrArgVal = "qwert"
    'sBuf = lstrcat(s, arrArgVal)
    'iKompasObject.ksError sBuf
    'For i = 1 To UBound(arrArgVal) - 1 Step 2
    'iKompasObject.ksMessage arrArgVal(i)
    '            strSQL = strSQL & Trim$(Right$(arrArgVal(i), _
    ''                Len(arrArgVal(i)) - 3)) & ","
    'Next

    'Dim z As String
    'z = "qwert"
    'Dim x As String
    'x = "asdfg"
    'Dim res As String
    'res = lstrcat(z, x)
    'iKompasObject.ksMessage z

    'Dim k As Long
    'InStr 1, "qwert", "w", res

  End Sub



  ' GetLibraryName

  Public Function GetLibraryName() As String
    GetLibraryName = "Редактирование"
  End Function

  ' ExternalMenuItem

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = "Tрансформация объекта"
        command_Renamed = 1
      Case 2
        ExternalMenuItem = "Копия  объекта"
        command_Renamed = 2
      Case 3
        ExternalMenuItem = "Симметрия объекта"
        command_Renamed = 3
      Case 4
        ExternalMenuItem = "Просмотр и редактирование допуска формы"
        command_Renamed = 4
      Case 5
        ExternalMenuItem = "Просмотр и редактирование таблицы"
        command_Renamed = 5
      Case 6
        ExternalMenuItem = "Взять тексты граф и редактировать штамп"
        command_Renamed = 6
      Case 7
        ExternalMenuItem = "Получить текст ТТ"
        command_Renamed = 7
      Case 8
        ExternalMenuItem = "Редактировать ТТ"
        command_Renamed = 8
      Case 9
        ExternalMenuItem = "Вставка фрагмента из библиотеки фрагментов"
        command_Renamed = 9
      Case 10
        ExternalMenuItem = "Работа с библиотекой фрагментов"
        command_Renamed = 10
      Case 11
        ExternalMenuItem = "Вставка фрагмента россыпью"
        command_Renamed = 11
      Case Else
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  ' ExternalRunCommand

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Object)
    iKompasObject = Kompas

    If iKompasObject Is Nothing Then
      Exit Sub
    End If

    Dim iDocument2D As Object 'ksDocument2D
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iDocument2D = iKompasObject.ActiveDocument2D

    If iDocument2D Is Nothing Then
      Exit Sub
    End If

    Select Case command_Renamed
      Case 1
        DrawTransform(iDocument2D) ' трансформация объекта по матрице
      Case 2
        DrawCopy(iDocument2D) ' копирование объекта
      Case 3
        DrawSymmetry(iDocument2D) ' симметрия объекта
      Case 4
        EditTolerance(iDocument2D) ' просмотр допуска формы
      Case 5
        EditTable(iDocument2D) ' просмотр таблицы
      Case 6
        EditStamp(iDocument2D) ' взять тексты граф и редактировать штамп
      Case 7
        GetTextTT(iDocument2D) ' получить текст ТТ
      Case 8
        ChangeTechnicalDemand(iDocument2D) ' редактирование TT
      Case 9
        ShowInsertFragment(iDocument2D) ' вставка фрагмента
      Case 10
        EditFragmentLibrary(iDocument2D) ' работа с библиотекой фрагментов
      Case 11
        ShowInsertFragment1(iDocument2D) ' вставка фрагмента россыпью
    End Select

    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompasObject.ksMessageBoxResult()

  End Sub

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