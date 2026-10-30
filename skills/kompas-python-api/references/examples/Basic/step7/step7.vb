Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step7")> _
Public Class Step7
  Dim iKompasObject As Object 'KompasObject
  Dim doc As Object 'ksDocument2D
  Sub WalkFromView(ByRef doc As Object) ' хождение по виду
    ' в текущем документе и виде создадим итератор для хождения по всем элементам
    Dim obj As Integer
    Dim count As Short
    count = 0
    Dim iIter As Object ' ksIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter = iKompasObject.GetIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksCreateIterator(ALL_OBJ, 0)
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If iIter.reference Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = iIter.ksMoveIterator("F")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If doc.ksExistObj(obj) Then
        Do
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(obj, 1)
          count = count + 1
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("номер = " & count)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(obj, 0)
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          obj = iIter.ksMoveIterator("N")
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Loop Until doc.ksExistObj(obj) = 0
      End If
    End If
  End Sub
  Sub UserLightObj(ByRef obj As Integer, ByRef c As Boolean, ByRef count As Short, ByRef doc As Object) ' подсветка элемента
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLightObj(obj, 1)
    If c Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("номер макро= " & count)
    Else
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("номер объекта= " & count)
    End If
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLightObj(obj, 0)
  End Sub
  Sub WalkFromMacro(ByRef doc As Object) ' хождение по макроэлементу
    ' в текущем документе и виде создадим итератор для хождения по макроэлементам
    Dim obj, macro As Integer
    Dim count, count1 As Short
    count = 0
    count1 = 0
    Dim iIter As Object ' ksIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter = iKompasObject.GetIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksCreateIterator(MACRO_OBJ, 0)
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim iIter2 As Object ' ksIterator
    If iIter.reference Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      macro = iIter.ksMoveIterator("F")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If doc.ksExistObj(macro) Then
        Do
          count = count + 1
          UserLightObj(macro, True, count, doc) ' подсветим макроэлемент
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iIter2 = iKompasObject.GetIterator ' создаем итератор для хождения по макроэлементу
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter2.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iIter2.ksCreateIterator(ALL_OBJ, macro)
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter2.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If iIter2.reference Then
            'UPGRADE_WARNING: Couldn't resolve default property of object iIter2.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            obj = iIter2.ksMoveIterator("F")
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If doc.ksExistObj(obj) Then
              Do
                count1 = count1 + 1
                UserLightObj(obj, False, count, doc) ' подсветим объек макроэлемента
                'UPGRADE_WARNING: Couldn't resolve default property of object iIter2.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                obj = iIter2.ksMoveIterator("N")
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              Loop Until doc.ksExistObj(obj) = 0
            End If
          End If
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          macro = iIter.ksMoveIterator("N")
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Loop Until doc.ksExistObj(macro) = 0
      End If
    End If
    If count = 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksError("Макроэлементы в документе отсутствуют")
    End If
  End Sub


  Sub WalkFromDoc(ByRef doc As Object) ' хождение по документам
    Dim pDoc As Integer
    Dim idocPar As Object ' ksDocumentParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    idocPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)

    Dim isheetPar As Object
    Dim istSheet As Object
    Dim count As Short
    Dim iIter As Object
    Dim iviewPar As Object
    Dim number As Integer ' ksViewParam ' ksIterator ' ksStandartSheet ' ksSheetPar
    If Not idocPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.comment = "create document"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.author = "Misha"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.regime. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.regime = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Type = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.GetLayoutParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isheetPar = idocPar.GetLayoutParam
      'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.shtType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isheetPar.shtType = lt_DocSheetStandart

      'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.GetSheetParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istSheet = isheetPar.GetSheetParam
      If Not isheetPar Is Nothing And Not istSheet Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Init()

        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.layoutName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.layoutName = ""
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.shtType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.shtType = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Format. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Format = 3
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.multiply. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.multiply = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.direct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.direct = 0

        'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idocPar.FileName = "a.cdw"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksCreateDocument(idocPar)
        'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idocPar.FileName = "b.cdw"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksCreateDocument(idocPar)
        'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idocPar.FileName = "c.cdw"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksCreateDocument(idocPar)

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter = iKompasObject.GetIterator
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter.ksCreateIterator(DOCUMENT_OBJ, 0) ' создаем итератор для хождения по документам
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If iIter.reference Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pDoc = iIter.ksMoveIterator("F")
          If pDoc Then
            Do
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.reference = pDoc
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              If doc.ksSetObjParam(pDoc, Nothing, DOCUMENT_STATE) Then ' активизируем документ pDoc
                count = count + 1
                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iviewPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewParam)
                If Not iviewPar Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.Init()
                  number = count
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.x = 10
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.y = 20
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.scale_ = 1
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.angle = 0
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.COLOR = RGB(10, 20, 10)
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.state. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.state = stACTIVE
                  'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iviewPar.Name = "user view"

                  'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateSheetView. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  doc.ksCreateSheetView(iviewPar, number) ' создадим вид в документе
                  'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLayer. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  doc.ksLayer(count) ' откроем слой
                  Select Case count
                    Case 1
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksLineSeg(20, 10, 40, 10, 1) ' в первом документе создадим отрезок
                    Case 2
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(50, 50, 20, 1) ' во втором документе создадим окружность
                    Case 3
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksArcByAngle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksArcByAngle(50, 50, 20, 45, 135, 1, 1) ' в третьем документе создадим  дугу
                  End Select
                  'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iKompasObject.ksMessage("документ " & count)
                End If
              End If
              'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pDoc = iIter.ksMoveIterator("N")
            Loop Until pDoc = 0
          End If
        End If
      End If
    End If
  End Sub


  Sub WalkViewDoc(ByRef doc As Object)
    Dim i As Object ' хождение по видам
    Dim idocPar As Object ' ksDocumentParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    idocPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)
    Dim isheetPar As Object
    Dim istSheet As Object
    Dim iviewPar As Object
    Dim number As Integer
    Dim pView As Integer
    Dim count As Short
    Dim iIter As Object
    Dim state As Integer
    Dim ivar As Object ' ksIterator ' ksViewParam ' ksStandartSheet ' ksSheetPar
    If Not idocPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.comment = "create document"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.author = "Misha"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.regime. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.regime = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Type = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.GetLayoutParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isheetPar = idocPar.GetLayoutParam
      'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.GetSheetParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istSheet = isheetPar.GetSheetParam()
      If Not isheetPar Is Nothing And Not istSheet Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Init()

        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.layoutName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.layoutName = ""
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.shtType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.shtType = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Format. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Format = 3
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.multiply. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.multiply = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.direct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.direct = 0

        'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idocPar.FileName = "a.cdw"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksCreateDocument(idocPar)

        ' создадим 5 видов
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iviewPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewParam)
        If Not iviewPar Is Nothing Then
          For i = 0 To 5
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.Init()

            number = 0
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.x = 10
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.y = 20
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.scale_ = 1
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.angle = 0
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.COLOR. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.COLOR = RGB(10, 20, 10)
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.state. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.state = stACTIVE
            'UPGRADE_WARNING: Couldn't resolve default property of object iviewPar.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iviewPar.Name = "user view"

            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateSheetView. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksCreateSheetView(iviewPar, number) ' создадим вид в документе
            ' number = number + 1
          Next
        End If

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter = iKompasObject.GetIterator
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter.ksCreateIterator(VIEW_OBJ, 0) ' создадим итератор для навигации по видам в документе
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If iIter.reference Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pView = iIter.ksMoveIterator("F")
          If pView Then
            Do
              state = stCURRENT
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ivar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
              If Not ivar Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of object ivar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                ivar.Init()

                'UPGRADE_WARNING: Couldn't resolve default property of object ivar.intVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                ivar.intVal = stCURRENT
                'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If doc.ksSetObjParam(pView, ivar, VIEW_LAYER_STATE) Then
                  Select Case count
                    Case 1
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksLineSeg(20, 20, 40, 20, 1)
                    Case 2
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(40, 20, 30, 1)
                    Case 3
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksArcByAngle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksArcByAngle(50, 50, 20, 45, 135, 1, 1)
                    Case 4
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksMtr(40, 0, 0, 1, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksLineSeg(10, 10, 30, 30, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksLineSeg(30, 30, 60, 10, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksLineSeg(60, 10, 10, 10, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksDeleteMtr()
                    Case 5
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(30, 30, 20, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(30, 30, 10, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksHatch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksHatch(0, 45, 2, 0, 0, 0)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(30, 30, 20, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksCircle(30, 30, 10, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      doc.ksEndObj()
                  End Select
                End If
                count = count + 1
              End If
              'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pView = iIter.ksMoveIterator("N")
            Loop Until pView = 0
          End If
        End If
      End If
    End If
  End Sub
  Sub WalkGroup(ByRef doc As Object) ' хождение по именнованным и рабочим группам
    Dim pNameGrp As Integer
    Dim count As Short
    count = 0
    Dim iIter As Object ' ksIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter = iKompasObject.GetIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksCreateIterator(NAME_GROUP_OBJ, 0) ' создадим итератор для движения по именнованным группам в документе
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If iIter.reference Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      pNameGrp = iIter.ksMoveIterator("F")
      If pNameGrp Then
        Do
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(pNameGrp, 1) ' подсветим группу
          count = count + 1
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("номер = " & count)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(pNameGrp, 0) ' снимем подсветку
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pNameGrp = iIter.ksMoveIterator("N")
        Loop Until pNameGrp = 0
      End If
    End If
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksDeleteIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksDeleteIterator()
    ' все именнованные группы ложатся в массив рабочих групп
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksNewGroup(0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 20, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksHatch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksHatch(0, 45, 2, 0, 0, 0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 20, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndObj()
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndGroup()

    ' создать итератор по рабочим группам
    count = 0
    Dim pWorkGrp As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksCreateIterator(WORK_GROUP_OBJ, 0) ' создадим итератор для движения по именнованным группам в документе
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    If iIter.reference Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      pWorkGrp = iIter.ksMoveIterator("F")
      If pWorkGrp Then
        Do
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(pWorkGrp, 1) ' подсветим группу
          count = count + 1
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("номер = " & count)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(pWorkGrp, 0) ' снимем подсветку
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pWorkGrp = iIter.ksMoveIterator("N")
        Loop Until pWorkGrp = 0
      End If
    End If
  End Sub

  Sub WalkLayer(ByRef doc As Object)
    Dim count As Object
    Dim i As Object ' хождение по слоям
    Dim idocPar As Object ' ksDocumentParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    idocPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)

    Dim isheetPar As Object
    Dim istSheet As Object
    Dim pLayer As Integer
    Dim iIter As Object ' ksIterator ' ksStandartSheet ' ksSheetPar
    If Not idocPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.comment. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.comment = "create document"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.author. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.author = "Misha"
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.regime. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.regime = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idocPar.Type = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.GetLayoutParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isheetPar = idocPar.GetLayoutParam
      'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.GetSheetParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istSheet = isheetPar.GetSheetParam()
      If Not isheetPar Is Nothing And Not istSheet Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Init()

        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.layoutName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.layoutName = ""
        'UPGRADE_WARNING: Couldn't resolve default property of object isheetPar.shtType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isheetPar.shtType = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.Format. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.Format = 3
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.multiply. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.multiply = 1
        'UPGRADE_WARNING: Couldn't resolve default property of object istSheet.direct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istSheet.direct = 0

        'UPGRADE_WARNING: Couldn't resolve default property of object idocPar.FileName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idocPar.FileName = "a.cdw"
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksCreateDocument(idocPar)

        ' создадим 5 слоев
        For i = 0 To 5
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLayer. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLayer(i)
          'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksCircle(30, 30, 5 + i * 10, 1)
        Next

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter = iKompasObject.GetIterator
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iIter.ksCreateIterator(LAYER_OBJ, 0) ' создаем итератор по слоям
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If iIter.reference Then
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pLayer = iIter.ksMoveIterator("F")
          'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          count = 0
          If pLayer Then
            Do
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksLightObj(pLayer, 1) ' подсветим группу
              'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessage("номер = " & count)
              'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              doc.ksLightObj(pLayer, 0) ' снимем подсветку
              'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              count = count + 1
              'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pLayer = iIter.ksMoveIterator("N")
            Loop Until pLayer = 0
          End If
        End If
      End If
    End If
  End Sub


  Sub WalkFromGroup(ByRef doc As Object)
    Dim count As Object ' хождение по группе
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksMtr(20, 10, 0, 1, 1)
    Dim pGrp As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    pGrp = doc.ksNewGroup(0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(10, 50, 50, 50, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(10, 10, 50, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(10, 10, 10, 50, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksLineSeg(50, 10, 50, 50, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 20, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksHatch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksHatch(0, 45, 2, 0, 0, 0)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 20, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksCircle(30, 30, 10, 1)
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndObj()
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksEndGroup()
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc.ksDeleteMtr()

    Dim obj As Integer
    Dim iIter As Object ' ksIterator
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter = iKompasObject.GetIterator()
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iIter.ksCreateIterator(ALL_OBJ, pGrp) ' создать итератор для хождения по группе
    'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    '    Dim coutn As Short
    If iIter.reference Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = iIter.ksMoveIterator("F")
      'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      count = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If doc.ksExistObj(obj) Then
        Do
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(obj, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          count = count + 1
          'UPGRADE_WARNING: Couldn't resolve default property of object count. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("номер = " & count)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          doc.ksLightObj(obj, 0)
          'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          obj = iIter.ksMoveIterator("N")
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        Loop Until doc.ksExistObj(obj) = 0
      End If
    End If
  End Sub


  Sub WalkFromDocWithAttr(ByRef doc As Object) ' хождение по элементам документа с определенным атрибутом
    Dim iattr As Object ' ksAttributeObject
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetAttributeObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iattr = iKompasObject.GetAttributeObject()
    Dim pObj, pAttr As Integer
    Dim iIter As Object
    Dim count As Short
    Dim rowsCount, columnsCount As Integer ' ksIterator
    If Not iattr Is Nothing Then

      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iIter = iKompasObject.GetIterator
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iIter.ksCreateAttrIterator(0, 10, 0, 0, 0, 0) ' создадим итератор для поиска объектов по ключу 10
      'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If iIter.reference Then
        'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        pAttr = iIter.ksMoveAttrIterator("F", pObj)
        count = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If doc.ksExistObj(pObj) Then
          Do
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 1)
            count = count + 1
            ' узнаем количество строк и колонок
            'UPGRADE_WARNING: Couldn't resolve default property of object iattr.ksGetAttrTabInfo. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If iattr.ksGetAttrTabInfo(pAttr, rowsCount, columnsCount) Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessage("номер = " & count & "rowsCount = " & rowsCount & "columnsCount = " & columnsCount)
            Else
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessageBoxResult() ' неудачное завершение - выдадим результат работы нашей функции
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 0)
            'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            pAttr = iIter.ksMoveAttrIterator("N", pObj)
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          Loop Until doc.ksExistObj(pObj) = 0
        End If
      End If
    End If
  End Sub
  Sub WalkFromObjWithAttr(ByRef doc As Object) ' хождение по атрибутам объекта
    Dim x, y As Double
    Dim j As Short
    Dim pObj As Integer
    Dim iinfo As Object ' ksRequestInfo
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iinfo = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
    Dim iattr As Object ' ksAttributeObject
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetAttributeObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iattr = iKompasObject.GetAttributeObject()
    Dim count As Short
    Dim rowsCount, columnsCount As Integer
    Dim pAttr As Integer
    Dim iIter As Object
    Dim iterat As Integer
    Dim ref As Integer ' ksIterator
    If Not iinfo Is Nothing And Not iattr Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iinfo.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iinfo.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object iinfo.prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iinfo.prompt = "Укажите объект"
      Do
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCursor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        j = doc.ksCursor(iinfo, x, y, Nothing)
        If j Then
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksFindObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          pObj = doc.ksFindObj(x, y, 1000000.0#)
          'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          If doc.ksExistObj(pObj) Then
            count = 0
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 1)

            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iIter = iKompasObject.GetIterator
            'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksCreateAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iterat = iIter.ksCreateAttrIterator(pObj, 10, 0, 0, 0, 0) ' создадим итератор для поиска объектов по ключу 10
            'UPGRADE_WARNING: Couldn't resolve default property of object iIter.reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If iIter.reference Then
              'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              pAttr = iIter.ksMoveAttrIterator("F", ref)
              If pAttr Then
                Do
                  count = count + 1
                  ' узнаем количество строк и колонок
                  'UPGRADE_WARNING: Couldn't resolve default property of object iattr.ksGetAttrTabInfo. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  If iattr.ksGetAttrTabInfo(pAttr, rowsCount, columnsCount) Then
                    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iKompasObject.ksMessage("номер = " & count & "rowsCount = " & rowsCount & "columnsCount = " & columnsCount)
                  Else
                    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iKompasObject.ksMessageBoxResult() ' неудачное завершение - выдадим результат работы нашей функции
                  End If
                  'UPGRADE_WARNING: Couldn't resolve default property of object iIter.ksMoveAttrIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  pAttr = iIter.ksMoveAttrIterator("N", ref)
                Loop Until pAttr = 0
              End If
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLightObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            doc.ksLightObj(pObj, 0)
          End If
        End If
      Loop Until j = 0
    End If
  End Sub



  ' GetLibraryName

  Public Function GetLibraryName() As String
    GetLibraryName = "Hавигация по модели"
  End Function

  ' ExternalMenuItem

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = "Xождение по виду"
        command_Renamed = 1
      Case 2
        ExternalMenuItem = "Xождение по макроэлементу"
        command_Renamed = 2
      Case 3
        ExternalMenuItem = "Xождение по документам"
        command_Renamed = 3
      Case 4
        ExternalMenuItem = "Xождение по видам"
        command_Renamed = 4
      Case 5
        ExternalMenuItem = "Xождение по группам"
        command_Renamed = 5
      Case 6
        ExternalMenuItem = "Xождение по слоям"
        command_Renamed = 6
      Case 7
        ExternalMenuItem = "Xождение по группе"
        command_Renamed = 7
      Case 8
        ExternalMenuItem = "Xождение по элементам с атрибутом"
        command_Renamed = 8
      Case 9
        ExternalMenuItem = "Xождение по атрибутам объекта"
        command_Renamed = 9
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

    Dim doc As Object 'ksDocument2D
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.Document2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    doc = iKompasObject.Document2D
    If doc Is Nothing Then
      Exit Sub
    End If

    If command_Renamed = 3 Then
      WalkFromDoc(doc) ' Xождение по документам
    End If

    Dim iDocument2D As Object 'ksDocument2D
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iDocument2D = iKompasObject.ActiveDocument2D

    If iDocument2D Is Nothing Then
      Exit Sub
    End If

    Select Case command_Renamed
      Case 1
        WalkFromView(iDocument2D) ' Xождение по виду
      Case 2
        WalkFromMacro(iDocument2D) ' Xождение по макроэлементу
      Case 4
        WalkViewDoc(iDocument2D) ' Xождение по видам
      Case 5
        WalkGroup(iDocument2D) ' Xождение по группам
      Case 6
        WalkLayer(iDocument2D) ' Xождение по слоям
      Case 7
        WalkFromGroup(iDocument2D) ' Xождение по группе
      Case 8
        WalkFromDocWithAttr(iDocument2D) ' Xождение по элементам с атрибутом
      Case 9
        WalkFromObjWithAttr(iDocument2D) ' Xождение по атрибутам объекта
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