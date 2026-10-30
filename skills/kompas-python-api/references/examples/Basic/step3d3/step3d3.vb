Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32


<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step3D3")> _
Public Class Class1
  Dim iKompasObject As Kompas6API5.KompasObject
  Dim iDocument3D As Kompas6API5.ksDocument3D

  ' GetLibraryName
  Public Function GetLibraryName() As String
    GetLibraryName = "Операции, оси и плоскости"
  End Function

  ' ExternalMenuItem
  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = "Конструктивная ось операции"
        command_Renamed = 1
      Case 2
        ExternalMenuItem = "Конструктивная ось по двум точкам"
        command_Renamed = 2
      Case 3
        ExternalMenuItem = "Конструктивная ось, проходящая через ребро"
        command_Renamed = 3
        '    Case 4
        '      ExternalMenuItem = "Конструктивная ось конической грани"
        '      command = 4
      Case 4
        ExternalMenuItem = "Смещенная плоскость, ось по двум плоскостям, плоскость под углом к другой пло-ти"
        command_Renamed = 4
      Case 5
        ExternalMenuItem = "Плоскость через три вершины"
        command_Renamed = 5
      Case Else
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  ' конструктивная ось операции
  Sub ConstrAxisOperations()
    Dim part As Kompas6API5.ksPart ' интерфейс компонента
    'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент

    Dim entitySketch As Kompas6API5.ksEntity
    Dim sketchDef As Kompas6API5.ksSketchDefinition
    Dim basePlane As Kompas6API5.ksEntity
    Dim sketchEdit As Kompas6API5.ksDocument2D
    Dim entityRotate As Kompas6API5.ksEntity
    Dim rotateDef As Kompas6API5.ksBossRotatedDefinition
    Dim rotproperty As Kompas6API5.ksRotatedParam
    Dim entityAxisOperation As Kompas6API5.ksEntity

    Dim axisOperation As Kompas6API5.ksAxisOperationsDefinition ' интерфейс свойств оси операций ' интерфейс оси операции ' интерфейс парметров вращения ' интерфейс свойств базовой операции вращения ' интерфейс 3D-объекта ' интерфейс редактора эскиза ksDocument2D ' интерфейс свойств эскиза
    If Not part Is Nothing Then ' если компонент создан
      'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch) ' создать новый эскиз

      If Not entitySketch Is Nothing Then ' если 3D-объект создан
        'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        sketchDef = entitySketch.GetDefinition ' берем у объекта его свойства

        If Not sketchDef Is Nothing Then ' если интерфейс свойств есть
          'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' получим интерфейс базовой плоскости XOY

          If Not basePlane Is Nothing Then ' плоскость получили
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.SetPlane(basePlane) ' установим плоскость XOY базовой для эскиза
            'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            basePlane = Nothing ' освобождаем интерфейс
          End If '

          'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entitySketch.Create() ' создадим эскиз
          'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit = sketchDef.BeginEdit ' открыть эскиз на редактирование

          If Not sketchEdit Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksCircle(20, 0, 10, 1) ' рисуем окружность
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(0, 0, 0, 5, 3) ' рисуем отрезок (ось)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.EndEdit() ' завершение редактирования эскиза
            'UPGRADE_NOTE: Object sketchEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            sketchEdit = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_NOTE: Object sketchDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          sketchDef = Nothing ' освобождаем интерфейс
        End If '

        'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entityRotate = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossRotated) ' создаем операцию вращения

        If Not entityRotate Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object entityRotate.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          rotateDef = entityRotate.GetDefinition ' получить свойства базовой операции вращения

          If Not rotateDef Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object rotateDef.RotatedParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            rotproperty = rotateDef.RotatedParam ' получить параметры вращения

            If Not rotproperty Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object rotproperty.direction. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              rotproperty.direction = Kompas6Constants3D.Direction_Type.dtBoth ' выдавливаем в два направления
              'UPGRADE_WARNING: Couldn't resolve default property of object rotproperty.toroidShape. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              rotproperty.toroidShape = False '
              'UPGRADE_NOTE: Object rotproperty may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              rotproperty = Nothing ' освобождаем интерфейс
            End If

            '         rotateDef.TorShapeType false
            '         rotateDef.DirectionType dtNormal        ' направление вращения
            'UPGRADE_WARNING: Couldn't resolve default property of object rotateDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            rotateDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 1, 1) ' тонкая стенка в два направления
            'UPGRADE_WARNING: Couldn't resolve default property of object rotateDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            rotateDef.SetSideParam(True, 180) '
            rotateDef.SetSideParam(False, 180) '
            'UPGRADE_WARNING: Couldn't resolve default property of object rotateDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            rotateDef.SetSketch(entitySketch) ' эскиз операции вращения
            'UPGRADE_WARNING: Couldn't resolve default property of object entityRotate.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityRotate.Create() ' создать операцию
            'UPGRADE_NOTE: Object rotateDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            rotateDef = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entityAxisOperation = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axisOperation) ' создать интерфейс

          If Not entityAxisOperation Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisOperation.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axisOperation = entityAxisOperation.GetDefinition ' получаем интерфейс свойств оси операций

            If Not axisOperation Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object axisOperation.SetOperation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              axisOperation.SetOperation(entityRotate) ' базовая операция
              'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisOperation.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityAxisOperation.Create() ' создать операцию
              'UPGRADE_NOTE: Object axisOperation may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              axisOperation = Nothing ' освобождаем интерфейс
            End If

            'UPGRADE_NOTE: Object entityAxisOperation may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            entityAxisOperation = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("Ось операции") '
          'UPGRADE_NOTE: Object entityRotate may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          entityRotate = Nothing ' освобождаем интерфейс
        End If

        'UPGRADE_NOTE: Object entitySketch may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        entitySketch = Nothing ' освобождаем интерфейс
      End If '

      'UPGRADE_NOTE: Object part may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      part = Nothing ' освобождаем интерфейс
    End If

  End Sub

  ' Конструктивная ось по двум точкам
  ' Конструктивная ось, проходящая через ребро
  Sub ConstrAxis2PointOrEdge(ByRef ax2Point As Boolean)
    Dim part As Kompas6API5.ksPart ' интерфейс компонента
    'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент

    Dim entitySketch As Kompas6API5.ksEntity
    Dim sketchDef As Kompas6API5.ksSketchDefinition
    Dim basePlane As Kompas6API5.ksEntity
    Dim sketchEdit As Kompas6API5.ksDocument2D
    Dim entityExtr As Kompas6API5.ksEntity
    Dim extrusionDef As Kompas6API5.ksBossExtrusionDefinition
    Dim entityColl As Kompas6API5.ksEntityCollection
    Dim collType As Short
    Dim entityAxis2Point As Kompas6API5.ksEntity
    Dim axis2Point As Kompas6API5.ksAxis2PointsDefinition
    Dim entityAxisEdge As Kompas6API5.ksEntity
    Dim axisEdge As Kompas6API5.ksAxisEdgeDefinition
    Dim entityAxisEdge2 As Kompas6API5.ksEntity
    Dim axisEdge2 As Kompas6API5.ksAxisEdgeDefinition
    ' интерфейс 3D-объекта ' интерфейс свойств оси по двум точкам ' интерфейс динамического массива 3D-объектов ' интерфейс свойств базовой операции выдавливания ' интерфейс редактора эскиза ksDocument2D ' интерфейс свойств эскиза
    If Not part Is Nothing Then ' если компонент создан
      'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch) ' создать новый эскиз

      If Not entitySketch Is Nothing Then ' если 3D-объект создан
        'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        sketchDef = entitySketch.GetDefinition ' берем у объекта его свойства

        If Not sketchDef Is Nothing Then ' если интерфейс свойств есть
          'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' получим интерфейс базовой плоскости XOY

          If Not basePlane Is Nothing Then ' плоскость получили
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.SetPlane(basePlane) ' установим плоскость XOY базовой для эскиза
            'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            basePlane = Nothing ' освобождаем интерфейс
          End If '

          'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entitySketch.Create() ' создадим эскиз
          'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit = sketchDef.BeginEdit ' открыть эскиз на редактирование

          If Not sketchEdit Is Nothing Then
            ' введем новый эскиз - квадрат
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, 50, -50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, -50, -50, -50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, -50, 50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(-50, -50, -50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.EndEdit() ' завершение редактирования эскиза
            'UPGRADE_NOTE: Object sketchEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            sketchEdit = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_NOTE: Object sketchDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          sketchDef = Nothing ' освобождаем интерфейс
        End If '

        'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entityExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion) '
        If Not entityExtr Is Nothing Then '
          'UPGRADE_WARNING: Couldn't resolve default property of object entityExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          extrusionDef = entityExtr.GetDefinition ' получаем интерфейс свойств базовой операции выдавливания

          If Not extrusionDef Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 20, 0, False)
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 20, 20) ' тонкая стенка в два направления
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetSketch(entitySketch) ' эскиз операции выдавливания
            'UPGRADE_WARNING: Couldn't resolve default property of object entityExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityExtr.Create() ' создать операцию
            'UPGRADE_NOTE: Object extrusionDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            extrusionDef = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_NOTE: Object entityExtr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          entityExtr = Nothing ' освобождаем интерфейс
        End If

        'UPGRADE_NOTE: Object entitySketch may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        entitySketch = Nothing ' освобождаем интерфейс
      End If '

      If ax2Point Then
        collType = Kompas6Constants3D.Obj3dType.o3d_vertex
      Else
        collType = Kompas6Constants3D.Obj3dType.o3d_edge
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object part.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entityColl = part.EntityCollection(collType) ' получаем массив вершин или ребер
      'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If Not entityColl Is Nothing And entityColl.GetCount > 1 Then
        If ax2Point Then
          ' создадим ось по двум точкам
          'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entityAxis2Point = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axis2Points) ' получить интерфейс оси по двум точкам

          If Not entityAxis2Point Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis2Point.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axis2Point = entityAxis2Point.GetDefinition ' получаем интерфейс свойств оси по двум точкам

            If Not axis2Point Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object axis2Point.SetPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              axis2Point.SetPoint(1, entityColl.GetByIndex(0))
              'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object axis2Point.SetPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              axis2Point.SetPoint(2, entityColl.GetByIndex(entityColl.GetCount - 1))
              'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis2Point.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityAxis2Point.Create()
              'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompasObject.ksMessage("Ось через две точки")
              'UPGRADE_NOTE: Object axis2Point may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              axis2Point = Nothing ' освобождаем интерфейс
            End If

            'UPGRADE_NOTE: Object entityAxis2Point may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            entityAxis2Point = Nothing ' освобождаем интерфейс
          End If
        Else
          ' создадим ось через ребро
          'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entityAxisEdge = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axisEdge) ' получить интерфейс - ось через ребро

          If Not entityAxisEdge Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisEdge.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axisEdge = entityAxisEdge.GetDefinition '

            If Not axisEdge Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object axisEdge.SetEdge. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              axisEdge.SetEdge(entityColl.GetByIndex(0))
              'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisEdge.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityAxisEdge.Create()
              'UPGRADE_NOTE: Object axisEdge may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              axisEdge = Nothing ' освобождаем интерфейс
            End If

            'UPGRADE_NOTE: Object entityAxisEdge may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            entityAxisEdge = Nothing ' освобождаем интерфейс
          End If
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("Ось через грань")

          ' создадим еще ось через грань
          'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entityAxisEdge2 = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axisEdge) ' получить интерфейс - ось через ребро

          If Not entityAxisEdge2 Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisEdge2.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axisEdge2 = entityAxisEdge2.GetDefinition() '

            If Not axisEdge2 Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object axisEdge2.SetEdge. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              axisEdge2.SetEdge(entityColl.GetByIndex(1))
              'UPGRADE_WARNING: Couldn't resolve default property of object entityAxisEdge2.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityAxisEdge2.Create()
              'UPGRADE_NOTE: Object axisEdge may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
              axisEdge = Nothing ' освобождаем интерфейс
            End If

            'UPGRADE_NOTE: Object entityAxisEdge2 may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            entityAxisEdge2 = Nothing ' освобождаем интерфейс
          End If
          'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iKompasObject.ksMessage("Другая ось через грань")
        End If

        'UPGRADE_NOTE: Object entityColl may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        entityColl = Nothing ' освобождаем интерфейс
      End If

      'UPGRADE_NOTE: Object part may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      part = Nothing ' освобождаем интерфейс
    End If

  End Sub

  ' Конструктивная ось конической грани
  Sub ConstrAxisConeface()
    Dim part As Kompas6API5.ksPart                              ' интерфейс компонента
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part)       ' новый компонент

    If Not part Is Nothing Then                     ' если компонент создан
      Dim entitySketch As Kompas6API5.ksEntity      ' интерфейс 3D-объекта
      entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch) ' создать новый эскиз

      If Not entitySketch Is Nothing Then           ' если 3D-объект создан
        Dim sketchDef As Kompas6API5.ksSketchDefinition ' интерфейс свойств эскиза
        sketchDef = entitySketch.GetDefinition  ' берем у объекта его свойства

        If Not sketchDef Is Nothing Then            ' если интерфейс свойств есть
          Dim basePlane As Kompas6API5.ksEntity     ' интерфейс 3D-объекта
          basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' получим интерфейс базовой плоскости XOY

          If Not basePlane Is Nothing Then          ' плоскость получили
            sketchDef.SetPlane(basePlane)         ' установим плоскость XOY базовой для эскиза
            basePlane = Nothing                 ' освобождаем интерфейс
          End If                                    '

          entitySketch.Create                       ' создадим эскиз
          Dim sketchEdit As Kompas6API5.ksDocument2D ' интерфейс редактора эскиза ksDocument2D
          sketchEdit = sketchDef.BeginEdit      ' открыть эскиз на редактирование

          If Not sketchEdit Is Nothing Then
            sketchEdit.ksCircle(0, 0, 50, 1)
            sketchDef.EndEdit                       ' завершение редактирования эскиза
            sketchEdit = Nothing                ' освобождаем интерфейс
          End If

          sketchDef = Nothing                   ' освобождаем интерфейс
        End If                                      '

        Dim entityExtr As Kompas6API5.ksEntity      '
        entityExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion) '
        If Not entityExtr Is Nothing Then           '
          Dim extrusionDef As Kompas6API5.ksSketchDefinition ' интерфейс свойств базовой операции выдавливания
          extrusionDef = entityExtr.GetDefinition ' получаем интерфейс свойств базовой операции выдавливания

          If Not extrusionDef Is Nothing Then
            extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal   ' направление выдавливания
            extrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 20, 30, False)
            extrusionDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 10, 10) ' тонкая стенка в два направления
            extrusionDef.SetSketch(entitySketch)    ' эскиз операции выдавливания
            entityExtr.Create                       ' создать операцию
            extrusionDef = Nothing              ' освобождаем интерфейс
          End If

          entityExtr = Nothing                  ' освобождаем интерфейс
        End If

        entitySketch = Nothing                  ' освобождаем интерфейс
      End If                                        '

      Dim entityColl As Kompas6API5.ksEntityCollection ' интерфейс динамического массива 3D-объектов
      entityColl = part.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_face) ' получаем массив вершин или ребер

      If Not entityColl Is Nothing Then
        Dim entityConFace As Kompas6API5.ksEntity

        Dim i As Integer
        Dim count As Integer
        count = entityColl.GetCount
        For i = 0 To count
          entityConFace = entityColl.GetByIndex(i)
          If Not entityConFace Is Nothing Then
            Dim face As Kompas6API5.ksEntity

            face = entityConFace.GetDefinition
            If Not face Is Nothing Then
              If Not face.IsConic Then              ' если поверхность не коническая, берем следующую из массива
                entityConFace = Nothing
              Else
                Exit For
              End If
            End If
          End If
        Next i

        ' создадим ось через коническую поверхность
        If Not entityConFace Is Nothing Then
          Dim entityAxisConFace As Kompas6API5.ksEntity

          entityAxisConFace = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axisConeFace)
          If Not entityAxisConFace Is Nothing Then

            Dim axisConFace As Kompas6API5.ksAxisConefaceDefinition

            axisConFace = entityAxisConFace.GetDefinition
            If Not axisConFace Is Nothing Then

              axisConFace.SetFace(entityConFace)
              entityAxisConFace.Create
              axisConFace = Nothing
            End If

            entityAxisConFace = Nothing
          End If
          iKompasObject.ksMessage("Ось через коническую поверхность")
          entityConFace = Nothing
        End If

      End If

      part = Nothing                            ' освобождаем интерфейс
    End If

  End Sub

  ' Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
  Sub CreateConstrElem()
    Dim part As Kompas6API5.ksPart ' интерфейс компонента
    'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент

    Dim entity As Kompas6API5.ksEntity
    Dim offsetDef As Kompas6API5.ksPlaneOffsetDefinition
    Dim basePlane As Kompas6API5.ksEntity
    Dim entityAxis As Kompas6API5.ksEntity
    Dim axis2PlanesDef As Kompas6API5.ksAxis2PlanesDefinition
    Dim entityAnglePlane As Kompas6API5.ksEntity
    Dim planeAngleDef As Kompas6API5.ksPlaneAngleDefinition

    If Not part Is Nothing Then ' если компонент создан
      'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entity = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeOffset)
    If Not entity Is Nothing Then
      ' интерфейс свойств смещенной плоскости
      'UPGRADE_WARNING: Couldn't resolve default property of object entity.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      offsetDef = entity.GetDefinition
      If Not offsetDef Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.offset = 150 ' расстояние от базовой плоскости
        'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)
        'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane.Name = "XOY" ' название для плоскости
        'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane.Update() ' обновить параметры

        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.SetPlane(basePlane) ' базовая плоскость
        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.direction. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.direction = False ' направление смещения от базовой плоскости
        'UPGRADE_WARNING: Couldn't resolve default property of object entity.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entity.Name = "Смещенная плоскость" ' имя для смещенной плоскости
        'UPGRADE_WARNING: Couldn't resolve default property of object entity.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entity.Create() ' создать смещенную плоскость

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Изменим параметры смещенной плоскости")

        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.offset = 50 ' изменим расстояние до базовой плоскости
        'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        basePlane = Nothing
        ' возьмем другую базовую плоскость
        'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeYOZ)
        'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane.Name = "YOZ"
        'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane.Update() ' обновить параметры

        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.direction. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.direction = True ' изменим направления смещения относительно базовой плоскости
        'UPGRADE_WARNING: Couldn't resolve default property of object offsetDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        offsetDef.SetPlane(basePlane)
        'UPGRADE_WARNING: Couldn't resolve default property of object entity.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entity.Update() ' обновить параметры

        'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        basePlane = Nothing
        ' возьмем другую базовую плоскость
        'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)
        'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        basePlane.Name = "XOY"

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("На пересечении плоскостей построим ось")

        ' Ось на пересечении двух плоскостей
        'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entityAxis = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_axis2Planes)
        If Not entityAxis Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          axis2PlanesDef = entityAxis.GetDefinition
          If Not axis2PlanesDef Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object axis2PlanesDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axis2PlanesDef.SetPlane(1, entity) ' Базовая плоскость 1
            'UPGRADE_WARNING: Couldn't resolve default property of object axis2PlanesDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axis2PlanesDef.SetPlane(2, basePlane) ' Базовая плоскость 2
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityAxis.Name = "Ось по двум плоскостям" ' имя для оси
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityAxis.Create() ' создаем ось

            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksMessage("Поменяем одну из базовых плоскостей для построения оси")

            'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            basePlane = Nothing
            ' возьмем другую базовую плоскость
            'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOZ)
            'UPGRADE_WARNING: Couldn't resolve default property of object basePlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            basePlane.Name = "XOZ"

            'UPGRADE_WARNING: Couldn't resolve default property of object axis2PlanesDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            axis2PlanesDef.SetPlane(2, basePlane) ' Базовая плоскость 2
            'UPGRADE_WARNING: Couldn't resolve default property of object entityAxis.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityAxis.Update()

            'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompasObject.ksMessage("Через смещенную плоскость и построенную ось \n проведем плоскость под углом 45")

            'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityAnglePlane = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeAngle)
            If Not entityAnglePlane Is Nothing Then
              ' интерфейс свойств плоскости под углом к другой плоскости
              'UPGRADE_WARNING: Couldn't resolve default property of object entityAnglePlane.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              planeAngleDef = entityAnglePlane.GetDefinition
              If Not planeAngleDef Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of object planeAngleDef.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                planeAngleDef.angle = 45 ' угол наклона к базовой плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of object planeAngleDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                planeAngleDef.SetPlane(entity) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of object planeAngleDef.SetAxis. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                planeAngleDef.SetAxis(entityAxis) ' базовая ось
                'UPGRADE_WARNING: Couldn't resolve default property of object entityAnglePlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                entityAnglePlane.Name = "Плоскость под углом к другой плоскости"
                'UPGRADE_WARNING: Couldn't resolve default property of object entityAnglePlane.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                entityAnglePlane.Create() ' создать плоскость под углом

                'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iKompasObject.ksMessage("Изменим одну из базовых плоскостей")

                'UPGRADE_WARNING: Couldn't resolve default property of object planeAngleDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                planeAngleDef.SetPlane(basePlane) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of object entityAnglePlane.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                entityAnglePlane.Update() ' обновить параметры плоскости
              End If
            End If
          End If
        End If

        'UPGRADE_NOTE: Object offsetDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        offsetDef = Nothing ' освобождаем интерфейс
      End If

      'UPGRADE_NOTE: Object entity may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      entity = Nothing ' освобождаем интерфейс
    End If

    'UPGRADE_NOTE: Object part may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    part = Nothing ' освобождаем интерфейс
    End If

  End Sub

  ' Плоскость через три вершины
  Sub constrPlane3Point()
    Dim part As Kompas6API5.ksPart ' интерфейс компонента
    'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of object iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент

    Dim entitySketch As Kompas6API5.ksEntity
    Dim sketchDef As Kompas6API5.ksSketchDefinition
    Dim basePlane As Kompas6API5.ksEntity
    Dim sketchEdit As Kompas6API5.ksDocument2D
    Dim entityExtr As Kompas6API5.ksEntity
    Dim extrusionDef As Kompas6API5.ksBossExtrusionDefinition


    Dim entityColl As Kompas6API5.ksEntityCollection
    Dim entityConstrPlane3Point As Kompas6API5.ksEntity
    Dim constrPlane3Point As Kompas6API5.ksPlane3PointsDefinition ' интерфейс динамического массива 3D-объектов ' интерфейс свойств базовой операции выдавливания ' ' интерфейс редактора эскиза ksDocument2D ' интерфейс 3D-объекта ' интерфейс свойств эскиза
    If Not part Is Nothing Then ' если компонент создан
      'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch) ' создать новый эскиз

      If Not entitySketch Is Nothing Then ' если 3D-объект создан
        'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        sketchDef = entitySketch.GetDefinition ' берем у объекта его свойства

        If Not sketchDef Is Nothing Then ' если интерфейс свойств есть
          'UPGRADE_WARNING: Couldn't resolve default property of object part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY) ' получим интерфейс базовой плоскости XOY

          If Not basePlane Is Nothing Then ' плоскость получили
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.SetPlane(basePlane) ' установим плоскость XOY базовой для эскиза
            'UPGRADE_NOTE: Object basePlane may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            basePlane = Nothing ' освобождаем интерфейс
          End If '

          'UPGRADE_WARNING: Couldn't resolve default property of object entitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entitySketch.Create() ' создадим эскиз
          'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit = sketchDef.BeginEdit ' открыть эскиз на редактирование

          If Not sketchEdit Is Nothing Then
            ' введем новый эскиз - квадрат
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, 50, -50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, -50, -50, -50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(50, -50, 50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchEdit.ksLineSeg(-50, -50, -50, 50, 1)
            'UPGRADE_WARNING: Couldn't resolve default property of object sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            sketchDef.EndEdit() ' завершение редактирования эскиза
            'UPGRADE_NOTE: Object sketchEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            sketchEdit = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_NOTE: Object sketchDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          sketchDef = Nothing ' освобождаем интерфейс
        End If '

        'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entityExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion) '
        If Not entityExtr Is Nothing Then '
          'UPGRADE_WARNING: Couldn't resolve default property of object entityExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          extrusionDef = entityExtr.GetDefinition ' получаем интерфейс свойств базовой операции выдавливания

          If Not extrusionDef Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 20, 30, False)
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 10, 10) ' тонкая стенка в два направления
            'UPGRADE_WARNING: Couldn't resolve default property of object extrusionDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef.SetSketch(entitySketch) ' эскиз операции выдавливания
            'UPGRADE_WARNING: Couldn't resolve default property of object entityExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityExtr.Create() ' создать операцию
            'UPGRADE_NOTE: Object extrusionDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            extrusionDef = Nothing ' освобождаем интерфейс
          End If

          'UPGRADE_NOTE: Object entityExtr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          entityExtr = Nothing ' освобождаем интерфейс
        End If

        'UPGRADE_NOTE: Object entitySketch may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        entitySketch = Nothing ' освобождаем интерфейс
      End If '

      'UPGRADE_WARNING: Couldn't resolve default property of object part.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entityColl = part.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_vertex) ' получаем массив вершин
      'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If Not entityColl Is Nothing And entityColl.GetCount > 2 Then

        ' Плоскость через три вершины
        'UPGRADE_WARNING: Couldn't resolve default property of object part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        entityConstrPlane3Point = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_plane3Points)
        If Not entityConstrPlane3Point Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object entityConstrPlane3Point.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          constrPlane3Point = entityConstrPlane3Point.GetDefinition
          If Not constrPlane3Point Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object constrPlane3Point.SetPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            constrPlane3Point.SetPoint(1, entityColl.GetByIndex(0))
            'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object constrPlane3Point.SetPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            constrPlane3Point.SetPoint(2, entityColl.GetByIndex(1))
            'UPGRADE_WARNING: Couldn't resolve default property of object entityColl.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            'UPGRADE_WARNING: Couldn't resolve default property of object constrPlane3Point.SetPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            constrPlane3Point.SetPoint(3, entityColl.GetByIndex(2))
            'UPGRADE_WARNING: Couldn't resolve default property of object entityConstrPlane3Point.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            entityConstrPlane3Point.Create()
            'UPGRADE_NOTE: Object constrPlane3Point may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
            constrPlane3Point = Nothing
          End If
          'UPGRADE_NOTE: Object constrPlane3Point may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
          constrPlane3Point = Nothing
        End If
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Плоскость через три вершины")

        'UPGRADE_NOTE: Object entityColl may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
        entityColl = Nothing ' освобождаем интерфейс
      End If

      'UPGRADE_NOTE: Object part may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
      part = Nothing ' освобождаем интерфейс
    End If

  End Sub


  ' ExternalRunCommand
  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Object)
    iKompasObject = Kompas

    If iKompasObject Is Nothing Then
      Exit Sub
    End If

    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ActiveDocument3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iDocument3D = iKompasObject.ActiveDocument3D

    If iDocument3D Is Nothing Then
      Exit Sub
    End If

    Select Case command_Renamed
      Case 1
        ConstrAxisOperations() ' Конструктивная ось операции
      Case 2
        ConstrAxis2PointOrEdge((True)) ' Конструктивная ось по двум точкам
      Case 3
        ConstrAxis2PointOrEdge((False)) ' Конструктивная ось, проходящая через ребро
        '    Case 4
        '      ConstrAxisConeface             ' Конструктивная ось конической грани
      Case 4
        CreateConstrElem() ' Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
      Case 5
        constrPlane3Point() ' Плоскость через три вершины
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