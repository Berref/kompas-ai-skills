Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32


<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step3D1")> _
Public Class Step3D1
  Dim iKompas As Kompas6API5.Application
  Dim iDocument2D As Kompas6API5.ksDocument2D
  Dim iMathematic2D As Kompas6API5.ksMathematic2D
  Dim iDocument3D As Kompas6API5.ksDocument3D

  ' удалить все объекты из текущего эскиза
  Sub ClearCurrentSketch(ByRef sketchEdit As Kompas6API5.ksDocument2D)
    ' создаим итератор и удалим все существующие объекты в эскизе
    Dim iter As Kompas6API5.ksIterator
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.GetIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iter = iKompas.GetIterator
    Dim ref As Integer
    If Not iter Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iter.ksCreateIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If iter.ksCreateIterator(ALL_OBJ, 0) Then
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ref = iter.ksMoveIterator("F") ' сместить указатель на первый элемент в списке
        If ref Then
          Do
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksExistObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            If sketchEdit.ksExistObj(ref) Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              sketchEdit.ksDeleteObj(ref) ' если объект существует удалить его
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iter.ksMoveIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            ref = iter.ksMoveIterator("N")
          Loop While ref
        End If

        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iter.ksDeleteIterator. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iter.ksDeleteIterator() ' удалим итератор
      End If
    End If
  End Sub

  ' Операции выдавливания
  Sub CreateExtrusion()
    Dim thinProp As Kompas6API5.ksThinParam
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompas.sMessage("Операции выдавливания")
    Dim part As Kompas6API5.ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pNew_Part) ' новый компонент
    Dim entitySketch As Kompas6API5.ksEntity
    Dim sketchDef As Kompas6API5.ksSketchDefinition
    Dim basePlane As Kompas6API5.ksEntity
    Dim sketchEdit As Kompas6API5.ksDocument2D
    Dim entityExtr As Kompas6API5.ksEntity
    Dim extrusionDef As Kompas6API5.ksBossExtrusionDefinition
    Dim sketchEdit2 As Kompas6API5.ksDocument2D
    Dim entitySketch3 As Kompas6API5.ksEntity
    Dim sketchDef3 As Kompas6API5.ksSketchDefinition
    Dim sketchEdit3 As Kompas6API5.ksDocument2D
    Dim entityBossExtr As Kompas6API5.ksEntity
    Dim bossExtrDef As Kompas6API5.ksBossExtrusionDefinition
    Dim extrProp As Kompas6API5.ksExtrusionParam
    Dim tninProp As Kompas6API5.ksThinParam
    Dim entitySketch4 As Kompas6API5.ksEntity
    Dim sketchDef4 As Kompas6API5.ksSketchDefinition
    Dim sketchEdit4 As Kompas6API5.ksDocument2D
    Dim entityCutExtr As Kompas6API5.ksEntity
    Dim cutExtrDef As Kompas6API5.ksCutExtrusionDefinition ' ksEntity ' ksDocument2D ' ksSketchDefinition ' ksExtrusionProperty ' ksBossExtrusionDefinition ' ksBaseExtrusionDefinition
    If Not part Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
      If Not entitySketch Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        sketchDef = entitySketch.GetDefinition()
        If Not sketchDef Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchDef.SetPlane(basePlane) ' установим плоскость XOY базовой для эскиза
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchDef.angle = 45 ' угол поворота эскиза
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entitySketch.Create() ' создадим эскиз

          ' интерфейс редактора эскиза
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit = sketchDef.BeginEdit()
          ' введем новый эскиз - квадрат
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit.ksLineSeg(50, 50, -50, 50, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit.ksLineSeg(50, -50, -50, -50, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit.ksLineSeg(50, -50, 50, 50, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchEdit.ksLineSeg(-50, -50, -50, 50, 1)
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          sketchDef.EndEdit() ' завершение редактирования эскиза

          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          entityExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion)
          If Not entityExtr Is Nothing Then
            ' интерфейс свойств базовой операции выдавливания
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            extrusionDef = entityExtr.GetDefinition ' интерфейс базовой операции выдавливания
            If Not extrusionDef Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 200, 0, False)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 10, 10) ' тонкая стенка в два направления
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.SetSketch(entitySketch) ' эскиз операции выдавливания
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityExtr.Create() ' создать операцию

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompas.ksMessage("Изменим параметры операции выдавливания")

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.SetSideParam(False, Kompas6Constants3D.End_Type.etBlind, 150, 0, False)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrusionDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtBoth ' направление выдавливания
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityExtr.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityExtr.Update() ' обновить параметры

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompas.ksMessage("Поменяем эскиз")

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              sketchEdit2 = sketchDef.BeginEdit

              ' создадим итератор и удалим все существующие объекты в эскизе
              ClearCurrentSketch(sketchEdit2)
              ' введем в эскиз окружность
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit2.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              sketchEdit2.ksCircle(0, 0, 100, 1)

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              sketchDef.EndEdit() ' завершение редактирования эскиза
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entitySketch.Update() ' обновить параметры эскиза
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityExtr.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entityExtr.Update() ' обновить параметры операции выдавливания

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iKompas.ksMessage("Приклеем выдавливанием")

              ' создадим новый эскиз
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              entitySketch3 = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
              If Not entitySketch3 Is Nothing Then
                ' интерфейс свойств эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch3.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                sketchDef3 = entitySketch3.GetDefinition
                If Not sketchDef3 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef3.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  sketchDef3.SetPlane(basePlane) ' установим плоскость
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef3.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  sketchDef3.angle = 45 ' повернем эскиз на 45 град.
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch3.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  entitySketch3.Create() ' создадим эскиз

                  ' интерфейс редактора эскиза
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef3.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  sketchEdit3 = sketchDef3.BeginEdit
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit3.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  sketchEdit3.ksCircle(0, 0, 150, 1)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef3.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  sketchDef3.EndEdit() ' завершение редактирования эскиза

                  ' приклеим выдавливанием
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  entityBossExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion)
                  If Not entityBossExtr Is Nothing Then
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityBossExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    bossExtrDef = entityBossExtr.GetDefinition
                    If Not bossExtrDef Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. bossExtrDef.ExtrusionParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      extrProp = bossExtrDef.ExtrusionParam ' интерфейс структуры параметров выдавливания

                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. bossExtrDef.ThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      thinProp = bossExtrDef.ThinParam ' интерфейс структуры параметров тонкой стенки
                      If (Not extrProp Is Nothing) And (Not thinProp Is Nothing) Then
                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. bossExtrDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        bossExtrDef.SetSketch(entitySketch3) ' эскиз операции выдавливания

                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrProp.direction. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        extrProp.direction = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания (прямое)
                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrProp.typeNormal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        extrProp.typeNormal = Kompas6Constants3D.End_Type.etBlind ' тип выдавливания ( строго на глубину )
                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. extrProp.depthNormal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        extrProp.depthNormal = 100 ' глубина выдавливания

                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. thinProp.thin. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        thinProp.thin = False ' без тонкой стенки

                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityBossExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        entityBossExtr.Create() ' создадим операцию
                      End If
                    End If
                  End If

                  ' создадим новый эскиз
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  entitySketch4 = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
                  If Not entitySketch4 Is Nothing Then
                    ' интерфейс свойств эскиза
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch4.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    sketchDef4 = entitySketch4.GetDefinition
                    If Not sketchDef4 Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef4.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchDef4.SetPlane(basePlane) ' установим плоскость
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef4.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchDef4.angle = 45 ' повернем эскиз на 45 град.
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entitySketch4.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      entitySketch4.Create() ' создадим эскиз

                      ' интерфейс редактора эскиза
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef4.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchEdit4 = sketchDef4.BeginEdit
                      ' введем новый эскиз - квадрат
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit4.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchEdit4.ksLineSeg(50, 50, -50, 50, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit4.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchEdit4.ksLineSeg(50, -50, -50, -50, 1)

                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit4.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchEdit4.ksLineSeg(50, -50, 50, 50, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit4.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchEdit4.ksLineSeg(-50, -50, -50, 50, 1)
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef4.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      sketchDef4.EndEdit() ' завершение редактирования эскиза
                    End If
                  End If

                  ' вырежим выдавливанием
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. part.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  entityCutExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_cutExtrusion)
                  If entityCutExtr Is Nothing Then
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityCutExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    cutExtrDef = entityCutExtr.GetDefinition
                    If Not cutExtrDef Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. cutExtrDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      cutExtrDef.SetSketch(entitySketch4) ' установим эскиз операции
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. cutExtrDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      cutExtrDef.directionType = Kompas6Constants3D.Direction_Type.dtReverse
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. cutExtrDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      cutExtrDef.SetSideParam(False, Kompas6Constants3D.End_Type.etBlind, 50, 0, False)
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. cutExtrDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      cutExtrDef.SetThinParam(False, 0, 0, 0)
                    End If
                  End If

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. entityCutExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  entityCutExtr.Create() ' создадим операцию вырезание выдавливанием

                End If
              End If
            End If
          End If
        End If
      End If
    End If
  End Sub

  ' Операции вращения
  Sub OperationRotated()
    Dim iPart As Kompas6API5.ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part)

    Dim iEntitySketch As Kompas6API5.ksEntity
    Dim isketchDef As Kompas6API5.ksSketchDefinition
    Dim iBasePlane As Kompas6API5.ksEntity
    Dim isketchEdit As Kompas6API5.ksDocument2D
    Dim iEntityRotate As Kompas6API5.ksEntity
    Dim iRotateDef As Kompas6API5.ksBossRotatedDefinition
    Dim iRotproperty As Kompas6API5.ksRotatedParam
    Dim iEntitySketch2 As Kompas6API5.ksEntity
    Dim iSketchDef2 As Kompas6API5.ksSketchDefinition
    Dim iBasePlane2 As Kompas6API5.ksEntity
    Dim iSketchEdit2 As Kompas6API5.ksDocument2D
    Dim iEntityBossRotate As Kompas6API5.ksEntity
    Dim iBossRotateDef As Kompas6API5.ksBossRotatedDefinition
    Dim iEntitySketch3 As Kompas6API5.ksEntity
    Dim iSketchDef3 As Kompas6API5.ksSketchDefinition
    Dim iBasePlane3 As Kompas6API5.ksEntity
    Dim iSketchEdit3 As Kompas6API5.ksDocument2D
    Dim iEntityCutRotate As Kompas6API5.ksEntity
    Dim iCutRotateDef As Kompas6API5.ksCutRotatedDefinition 'ksEntity 'ksDocument2D 'ksSketchDefinition 'ksBossRotatedDefinition 'ksRotatedProperty 'ksBaseRotatedDefinition
    If Not iPart Is Nothing Then

      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iEntitySketch = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

      If Not iEntitySketch Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isketchDef = iEntitySketch.GetDefinition()

        If Not isketchDef Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iBasePlane = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

          If Not iBasePlane Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchDef.SetPlane(iBasePlane) 'установим плоскость XOY базовой для эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch.Create() 'создадим эскиз

            'интерфейс редактора эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchEdit = isketchDef.BeginEdit

            If Not isketchEdit Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksArcByAngle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksArcByAngle(0, 0, 20, -90, 90, 1, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksLineSeg(0, -20, 0, 20, 3)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchDef.EndEdit() 'завершение редактирования эскиза
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityRotate = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossRotated)

            If Not iEntityRotate Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityRotate.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iRotateDef = iEntityRotate.GetDefinition

              If Not iRotateDef Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotateDef.RotatedParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iRotproperty = iRotateDef.RotatedParam

                If Not iRotproperty Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotproperty.direction. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRotproperty.direction = Kompas6Constants3D.Direction_Type.dtBoth
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotproperty.toroidShape. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRotproperty.toroidShape = False
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotateDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iRotateDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 1, 1) 'тонкая стенка в два направления
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotateDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iRotateDef.SetSideParam(True, 180)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRotateDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iRotateDef.SetSketch(iEntitySketch) ' эскиз операции вращения

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch.Update()
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityRotate.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityRotate.Update() ' обновить параметры операции вращения

              End If
            End If
          End If
        End If
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompas.ksMessage("Базовая операция вращения")

      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iEntitySketch2 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

      If Not iEntitySketch2 Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch2.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iSketchDef2 = iEntitySketch2.GetDefinition()

        If Not iSketchDef2 Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iBasePlane2 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

          If Not iBasePlane2 Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iSketchDef2.SetPlane(iBasePlane2) 'установим плоскость XOY базовой для эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch2.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch2.Create() 'создадим эскиз

            'интерфейс редактора эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iSketchEdit2 = iSketchDef2.BeginEdit

            If Not iSketchEdit2 Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit2.ksArcByAngle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchEdit2.ksArcByAngle(15, 0, 10, -90, 90, 1, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit2.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchEdit2.ksLineSeg(15, -10, 15, 10, 3)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchDef2.EndEdit() 'завершение редактирования эскиза
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityBossRotate = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossRotated)

            If Not iEntityBossRotate Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossRotate.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iBossRotateDef = iEntityBossRotate.GetDefinition

              If Not iBossRotateDef Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBossRotateDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBossRotateDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBossRotateDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBossRotateDef.SetSideParam(True, 360)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBossRotateDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBossRotateDef.SetSketch(iEntitySketch2) ' эскиз операции приклеивания вращением
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossRotate.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossRotate.Create() ' создать операцию

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef2.EndEdit() ' создать операцию
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch2.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch2.Update() ' обновить параметры эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossRotate.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossRotate.Update() ' обновить параметры операции вращения
              End If
            End If
          End If
        End If
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompas.ksMessage("Операция приклеивания вращением")

      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iEntitySketch3 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

      If Not iEntitySketch3 Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch3.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iSketchDef3 = iEntitySketch3.GetDefinition()

        If Not iSketchDef3 Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iBasePlane3 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

          If Not iBasePlane3 Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iSketchDef3.SetPlane(iBasePlane3) 'установим плоскость XOY базовой для эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch3.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch3.Create() 'создадим эскиз

            'интерфейс редактора эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iSketchEdit3 = iSketchDef3.BeginEdit

            If Not iSketchEdit3 Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit3.ksArcByAngle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchEdit3.ksArcByAngle(20, 0, 20, 90, 270, 1, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit3.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchEdit3.ksLineSeg(20, -20, 20, 20, 3)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchDef3.EndEdit() 'завершение редактирования эскиза
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityCutRotate = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_cutRotated)

            If Not iEntityCutRotate Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutRotate.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iCutRotateDef = iEntityCutRotate.GetDefinition

              If Not iCutRotateDef Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutRotateDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCutRotateDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutRotateDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCutRotateDef.SetSideParam(True, 90)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutRotateDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCutRotateDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 5, 7) ' тонкая стенка в два направления
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutRotateDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCutRotateDef.SetSketch(iEntitySketch3) ' эскиз операции вырезания вращением
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutRotate.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityCutRotate.Create() ' создать операцию

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch3.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch3.Update() ' обновить параметры эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutRotate.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityCutRotate.Update() ' обновить параметры операции вращения
              End If
            End If
          End If
        End If
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompas.ksMessage("Операция вырезания вращением")
    End If
  End Sub

  ' Операции по сечениям
  Sub OperationLoft()
    Dim iPart As Kompas6API5.ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part)

    Dim iEntitySketch As Kompas6API5.ksEntity
    Dim isketchDef As Kompas6API5.ksSketchDefinition
    Dim iBasePlane As Kompas6API5.ksEntity
    Dim isketchEdit As Kompas6API5.ksDocument2D
    Dim iEntityOffsetPlane As Kompas6API5.ksEntity
    Dim iEntitySketch2 As Kompas6API5.ksEntity
    Dim iOffsetDef As Kompas6API5.ksPlaneOffsetDefinition
    Dim iBasePlane2 As Kompas6API5.ksEntity
    Dim iSketchDef2 As Kompas6API5.ksSketchDefinition
    Dim iSketchEdit2 As Kompas6API5.ksDocument2D
    Dim iEntityOffsetPlane2 As Kompas6API5.ksEntity
    Dim iEntitySketch3 As Kompas6API5.ksEntity
    Dim iOffsetDef2 As Kompas6API5.ksSketchDefinition
    Dim iBasePlane3 As Kompas6API5.ksEntity
    Dim iSketchDef3 As Kompas6API5.ksSketchDefinition
    Dim iSketchEdit3 As Kompas6API5.ksDocument2D
    Dim iEntityBossLoft1 As Kompas6API5.ksEntity
    Dim iBossLoft1 As Kompas6API5.ksBossLoftDefinition
    Dim iEntCol As Kompas6API5.ksEntityCollection
    Dim ientitySketch7 As Kompas6API5.ksEntity
    Dim sketchDef As Kompas6API5.ksSketchDefinition
    Dim sketchEdit As Kompas6API5.ksDocument2D
    Dim iEntityOffsetPlane3 As Kompas6API5.ksEntity
    Dim iEntitySketch4 As Kompas6API5.ksEntity
    Dim iOffsetDef3 As Kompas6API5.ksPlaneOffsetDefinition
    Dim iBasePlane4 As Kompas6API5.ksEntity
    Dim iSketchDef4 As Kompas6API5.ksSketchDefinition
    Dim iSketchEdit4 As Kompas6API5.ksDocument2D
    Dim iEntityBossLoft2 As Kompas6API5.ksEntity
    Dim iBossLoft2 As Kompas6API5.ksBossLoftDefinition
    Dim iEntCol2 As Kompas6API5.ksEntityCollection
    Dim iEntitySketch5 As Kompas6API5.ksEntity
    Dim iSketchDef5 As Kompas6API5.ksSketchDefinition
    Dim iSketchEdit5 As Kompas6API5.ksDocument2D
    Dim iRecPar As Kompas6API5.ksEntityCollection
    Dim iEntityOffsetPlane4 As Kompas6API5.ksEntity
    Dim iEntitySketch6 As Kompas6API5.ksEntity
    Dim iOffsetDef4 As Kompas6API5.ksPlaneOffsetDefinition
    Dim iBasePlane5 As Kompas6API5.ksEntity
    Dim iSketchDef6 As Kompas6API5.ksSketchDefinition
    Dim iSketchEdit6 As Kompas6API5.ksDocument2D
    Dim iRecPar2 As Kompas6API5.ksRectParam
    Dim iEntityCutLoft As Kompas6API5.ksEntity
    Dim iCutLoft As Kompas6API5.ksCutLoftDefinition

    Dim iEntCol3 As Kompas6API5.ksCutLoftDefinition ' ksEntity ' ksRectangleParam ' ksDocument2D ' ksSketchDefinition ' ksConstrPlaneOffsetDefinition 'ksEntity ' ksBossLoftDefinition ' ksEntityCollection ' ksBossLoftDefinition 'ksDocument2D 'ksSketchDefinition
    If Not iPart Is Nothing Then

      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iEntitySketch = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

      If Not iEntitySketch Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isketchDef = iEntitySketch.GetDefinition()

        If Not isketchDef Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iBasePlane = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

          If Not iBasePlane Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchDef.SetPlane(iBasePlane) 'установим плоскость XOY базовой для эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch.Create() 'создадим эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.Hidden. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch.hidden = True

            'интерфейс редактора эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchEdit = isketchDef.BeginEdit

            If Not isketchEdit Is Nothing Then
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksCircle(0, 0, 4.5, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchDef.EndEdit() 'завершение редактирования эскиза
            End If

            ' создадим смещенную плоскость, а в ней эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityOffsetPlane = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeOffset)
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch2 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

            If Not iEntityOffsetPlane Is Nothing And Not iEntitySketch2 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iOffsetDef = iEntityOffsetPlane.GetDefinition()

              If Not iOffsetDef Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef.offset = 30 ' расстояние от базовой плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBasePlane2 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

                If Not iBasePlane2 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane2.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane2.name = "Смещенная плоскость"
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane2.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane2.Update() ' обновить параметры
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef.SetPlane(iBasePlane2) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane.name = "Смещенная плоскость" ' имя для смещенной плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane.Hidden. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane.hidden = True
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane.Create() ' создать смещенную плоскость

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch2.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef2 = iEntitySketch2.GetDefinition()

                If Not iSketchDef2 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchDef2.SetPlane(iEntityOffsetPlane) ' установим плоскость XOY базовой для эскиза
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch2.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch2.Create() ' создадим эскиз

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchEdit2 = iSketchDef2.BeginEdit()

                If Not iSketchEdit2 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit2.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchEdit2.ksCircle(0, 0, 8, 1)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef2.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef2.EndEdit() ' завершение редактирования эскиза
              End If
            End If

            ' создадим смещенную плоскость, а в ней эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityOffsetPlane2 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeOffset)
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch3 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

            If Not iEntityOffsetPlane2 Is Nothing And Not iEntitySketch3 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane2.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iOffsetDef2 = iEntityOffsetPlane2.GetDefinition()

              If Not iOffsetDef2 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef2.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef2.offset = 60 ' расстояние от базовой плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBasePlane3 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

                If Not iBasePlane3 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane3.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane3.name = "Смещенная плоскость"
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane3.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane3.Update() ' обновить параметры
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef2.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef2.SetPlane(iBasePlane3) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane2.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane2.name = "Смещенная плоскость" ' имя для смещенной плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane2.Hidden. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane2.hidden = True
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane2.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane2.Create() ' создать смещенную плоскость

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch3.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef3 = iEntitySketch3.GetDefinition()

                If Not iSketchDef3 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchDef3.SetPlane(iEntityOffsetPlane2) ' установим плоскость XOY базовой для эскиза
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch3.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch3.Create() ' создадим эскиз

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchEdit3 = iSketchDef3.BeginEdit()

                If Not iSketchEdit3 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit3.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchEdit3.ksCircle(0, 0, 1.5, 1)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef3.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef3.EndEdit() ' завершение редактирования эскиза
              End If
            End If

            ' создадим базовую операцию по сечениям
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityBossLoft1 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossLoft)

            If Not iEntityBossLoft1 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iBossLoft1 = iEntityBossLoft1.GetDefinition()

              If Not iBossLoft1 Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBossLoft.Sketchs. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntCol = iBossLoft1.Sketchs()

                If Not iEntCol Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol.Add(iEntitySketch)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol.Add(iEntitySketch2)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol.Add(iEntitySketch3)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft1.name = "Ручка"
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.SetAdvancedColor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft1.SetAdvancedColor(12345678, 0.8, 0.8, 0.8, 0.8, 1, 0.8)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft1.Create() ' создать операцию
              End If
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompas.ksMessage("Базовая операция по сечениям")

            ' создадим смещенную плоскость, а в ней эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            ientitySketch7 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
            If Not ientitySketch7 Is Nothing Then
              ' интерфейс свойств смещенной плоскости
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. ientitySketch7.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              sketchDef = ientitySketch7.GetDefinition()
              If Not sketchDef Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                sketchDef.SetPlane(iEntityOffsetPlane2) ' установим плоскость XOY базовой для эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. ientitySketch7.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                ientitySketch7.Create() ' создадим эскиз

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                sketchEdit = sketchDef.BeginEdit()
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchEdit.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                sketchEdit.ksCircle(0, 0, 1.5, 1)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. sketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                sketchDef.EndEdit() ' завершение редактирования эскиза
              End If
            End If

            ' создадим смещенную плоскость, а в ней эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityOffsetPlane3 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeOffset)
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch4 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

            If Not iEntityOffsetPlane3 Is Nothing And Not iEntitySketch4 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane3.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iOffsetDef3 = iEntityOffsetPlane3.GetDefinition()

              If Not iOffsetDef3 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef3.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef3.offset = 120 ' расстояние от базовой плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBasePlane4 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

                If Not iBasePlane4 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane4.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane4.name = "Смещенная плоскость"
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane4.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane4.Update() ' обновить параметры
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef3.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef3.SetPlane(iBasePlane4) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane3.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane3.name = "Смещенная плоскость" ' имя для смещенной плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane3.Hidden. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane3.hidden = True
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane3.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane3.Create() ' создать смещенную плоскость

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch4.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef4 = iEntitySketch4.GetDefinition()

                If Not iSketchDef4 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef4.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchDef4.SetPlane(iEntityOffsetPlane3) ' установим плоскость XOY базовой для эскиза
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch4.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch4.Create() ' создадим эскиз

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef4.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchEdit4 = iSketchDef4.BeginEdit()

                If Not iSketchEdit4 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit4.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchEdit4.ksCircle(0, 0, 1.8, 1)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef4.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef4.EndEdit() ' завершение редактирования эскиза
              End If
            End If

            ' создадим операцию приклеивания по сечениям
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityBossLoft2 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossLoft)

            If Not iEntityBossLoft2 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iBossLoft2 = iEntityBossLoft2.GetDefinition()

              If Not iBossLoft2 Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBossLoft.Sketchs. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntCol2 = iBossLoft2.Sketchs()

                If Not iEntCol2 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol2.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol2.Add(ientitySketch7)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol2.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol2.Add(iEntitySketch4)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft2.name = "Цивьё"
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.SetAdvancedColor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft2.SetAdvancedColor(1234567890, 0.8, 0.8, 0.8, 0.8, 1, 0.8)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityBossLoft.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityBossLoft2.Create() ' создать операцию
              End If
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompas.ksMessage("Операция приклеивание по сечениям")

            ' создадим эскиз в уже созданной смещенной плоскости
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch5 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

            If Not iEntitySketch5 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch5.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iSketchDef5 = iEntitySketch5.GetDefinition()

              If Not iSketchDef5 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef5.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef5.SetPlane(iEntityOffsetPlane3) ' установим плоскость XOY базовой для эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch5.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch5.Create()

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef5.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchEdit5 = iSketchDef5.BeginEdit()

                If Not iSketchEdit5 Is Nothing Then

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRecPar = iKompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RectangleParam)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRecPar.Init()

                  If Not iRecPar Is Nothing Then
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar.x = -1.8
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar.y = -0.4
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar.HEIGHT = 0.8
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.Width. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar.Width = 3.6
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar.Style = 1
                  End If

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit5.ksRectangle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchEdit5.ksRectangle(iRecPar, 0)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef5.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchDef5.EndEdit() ' завершение редактирования эскиза
                End If
              End If
            End If

            ' создадим смещенную плоскость, а в ней эскиз
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityOffsetPlane4 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_planeOffset)
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch6 = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

            If Not iEntityOffsetPlane4 Is Nothing And Not iEntitySketch6 Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane4.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iOffsetDef4 = iEntityOffsetPlane4.GetDefinition()

              If Not iOffsetDef4 Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef4.offset. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef4.offset = 110 ' расстояние от базовой плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iBasePlane5 = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

                If Not iBasePlane5 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane5.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane5.name = "Смещенная плоскость"
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iBasePlane5.Update. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iBasePlane5.Update() ' обновить параметры
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iOffsetDef4.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iOffsetDef4.SetPlane(iBasePlane5) ' базовая плоскость
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane4.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane4.name = "Смещенная плоскость" ' имя для смещенной плоскости
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane4.Hidden. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane4.hidden = True
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityOffsetPlane4.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityOffsetPlane4.Create() ' создать смещенную плоскость

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch6.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef6 = iEntitySketch6.GetDefinition()

                If Not iSketchDef6 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef6.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchDef6.SetPlane(iEntityOffsetPlane4) ' установим плоскость XOY базовой для эскиза
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch6.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntitySketch6.Create() ' создадим эскиз

                ' интерфейс редактора эскиза
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef6.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchEdit6 = iSketchDef6.BeginEdit()

                If Not iSketchEdit6 Is Nothing Then

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRecPar2 = iKompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RectangleParam)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iRecPar2.Init()

                  If Not iRecPar2 Is Nothing Then
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar2.x = -1.8
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar2.y = -1.8
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar2.HEIGHT = 3.6
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.Width. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar2.Width = 3.6
                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iRecPar2.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iRecPar2.Style = 1
                  End If

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchEdit6.ksRectangle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iSketchEdit6.ksRectangle(iRecPar2, 0)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iSketchDef6.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iSketchDef6.EndEdit() ' завершение редактирования эскиза
              End If
            End If

            ' создадим операцию вырезания по сечениям
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityCutLoft = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_cutLoft)

            If Not iEntityCutLoft Is Nothing Then

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutLoft.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iCutLoft = iEntityCutLoft.GetDefinition()

              If Not iCutLoft Is Nothing Then

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutLoft.Sketchs. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntCol3 = iCutLoft.Sketchs()

                If Not iEntCol3 Is Nothing Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol3.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol3.Add(iEntitySketch5)
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntCol3.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntCol3.Add(iEntitySketch6)
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCutLoft.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCutLoft.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtNormal, 3, 0)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutLoft.Name. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityCutLoft.name = "Рабочая поверхность"
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutLoft.SetAdvancedColor. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityCutLoft.SetAdvancedColor(1234, 0.8, 0.8, 0.8, 0.8, 1, 0.8)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityCutLoft.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityCutLoft.Create()
              End If
            End If
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iKompas.ksMessage("Операция вырезания по сечениям")
          End If
        End If
      End If
    End If
  End Sub

  ' Создание фаски и скругления
  Sub CreateFilletAndChamfer()
    Dim i As Integer

    Dim iPart As Kompas6API5.ksPart
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iDocument3D.GetPart. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPart = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part)

    Dim iEntitySketch As Kompas6API5.ksEntity
    Dim isketchDef As Kompas6API5.ksSketchDefinition
    Dim iBasePlane As Kompas6API5.ksEntity
    Dim isketchEdit As Kompas6API5.ksDocument2D
    Dim iEntityExtr As Kompas6API5.ksEntity
    Dim iExtrusionDef As Kompas6API5.ksBossExtrusionDefinition
    Dim iCollect As Kompas6API5.ksEntityCollection
    Dim iEntityFillet As Kompas6API5.ksEntity
    Dim iFilletDef As Kompas6API5.ksFilletDefinition
    Dim iArr As Kompas6API5.ksDynamicArray
    Dim iCollect2 As Kompas6API5.ksEntityCollection
    Dim iEntityChamfer As Kompas6API5.ksEntity
    Dim iChamferDef As Kompas6API5.ksChamferDefinition
    Dim iArr2 As Kompas6API5.ksEntityCollection ' ksChamferDefinition ' ksEntity ' ksFilletDefinition ' ksBaseExtrusionDefinition 'ksDocument2D 'ksEntity 'ksSketchDefinition
    If Not iPart Is Nothing Then

      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iEntitySketch = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)

      If Not iEntitySketch Is Nothing Then
        ' интерфейс свойств эскиза
        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isketchDef = iEntitySketch.GetDefinition()

        If Not isketchDef Is Nothing Then
          ' получим интерфейс базовой плоскости XOY
          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.GetDefaultEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iBasePlane = iPart.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)

          If Not iBasePlane Is Nothing Then
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.SetPlane. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchDef.SetPlane(iBasePlane) 'установим плоскость XOY базовой для эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntitySketch.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntitySketch.Create() 'создадим эскиз

            'интерфейс редактора эскиза
            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.BeginEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            isketchEdit = isketchDef.BeginEdit

            If Not isketchEdit Is Nothing Then
              ' введем новый эскиз - квадрат
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksLineSeg(50, 50, -50, 50, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksLineSeg(50, -50, -50, -50, 1)

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksLineSeg(50, -50, 50, 50, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchEdit.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchEdit.ksLineSeg(-50, -50, -50, 50, 1)
              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. isketchDef.EndEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              isketchDef.EndEdit() 'завершение редактирования эскиза
            End If

            'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            iEntityExtr = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion)

            If Not iEntityExtr Is Nothing Then
              'If Not iEntityExtr Is Nothing Then ' интерфейс свойств базовой операции выдавливания

              'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityExtr.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              iExtrusionDef = iEntityExtr.GetDefinition() ' интерфейс базовой операции выдавливания

              If Not iExtrusionDef Is Nothing Then
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iExtrusionDef.directionType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iExtrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iExtrusionDef.SetSideParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iExtrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 100, 0, False)
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iExtrusionDef.SetThinParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iExtrusionDef.SetThinParam(False, 0, 0, 0) ' без тонкой стенки
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iExtrusionDef.SetSketch. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iExtrusionDef.SetSketch(iEntitySketch) ' эскиз операции выдавливания

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityExtr.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iEntityExtr.Create() ' создать операцию

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCollect = iPart.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_face)

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect.SelectByPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If Not iCollect Is Nothing And iCollect.SelectByPoint(0, 0, 0) And iCollect.GetCount() Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iKompas.ksMessage("Создание скругления")

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntityFillet = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_fillet)

                  If Not iEntityFillet Is Nothing Then

                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityFillet.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iFilletDef = iEntityFillet.GetDefinition()

                    If Not iFilletDef Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iFilletDef.radius. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iFilletDef.radius = 10 ' радиус скругления
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iFilletDef.tangent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iFilletDef.tangent = False ' продолжить по касательной

                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iFilletDef.Array. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iArr = iFilletDef.array() ' динамический массив объектов

                      If Not iArr Is Nothing Then
                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iArr.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        For i = 0 To iArr.GetCount
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iArr.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iArr.Add(iCollect.GetByIndex(i))
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityFillet.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iEntityFillet.Create()
                        Next
                      End If
                    End If
                  End If
                End If

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.EntityCollection. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                iCollect2 = iPart.EntityCollection(Kompas6Constants3D.Obj3dType.o3d_face)

                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect2.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect2.SelectByPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                If Not iCollect2 Is Nothing And iCollect2.SelectByPoint(0, 0, 100) And iCollect2.GetCount Then
                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iKompas.ksMessage("Создание фаски")

                  'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iPart.NewEntity. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                  iEntityChamfer = iPart.NewEntity(Kompas6Constants3D.Obj3dType.o3d_chamfer)

                  If Not iEntityChamfer Is Nothing Then

                    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityChamfer.GetDefinition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                    iChamferDef = iEntityChamfer.GetDefinition()

                    If Not iChamferDef Is Nothing Then
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iChamferDef.SetChamferParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iChamferDef.SetChamferParam(True, 10, 10)
                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iChamferDef.tangent. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iChamferDef.tangent = False ' продолжить по касательной

                      'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iChamferDef.Array. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                      iArr2 = iChamferDef.array() ' динамический массив объектов

                      If Not iArr2 Is Nothing Then
                        'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iArr2.GetCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                        For i = 0 To iArr2.GetCount
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iCollect2.GetByIndex. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iArr2.Add. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iArr2.Add(iCollect2.GetByIndex(i))
                          'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iEntityChamfer.Create. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                          iEntityChamfer.Create()
                        Next
                      End If
                    End If
                  End If
                End If
              End If
            End If
          End If
        End If
      End If
    End If
  End Sub

  ' GetLibraryName

  Public Function GetLibraryName() As String
    GetLibraryName = "Объекты 3D"
  End Function

  ' ExternalMenuItem

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = "Операции выдавливания"
        command_Renamed = 1
      Case 2
        ExternalMenuItem = "Операции вращения"
        command_Renamed = 2
      Case 3
        ExternalMenuItem = "Оперции по сечениям"
        command_Renamed = 3
      Case 4
        ExternalMenuItem = "Создание фаски и скругления"
        command_Renamed = 4
      Case Else
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command_Renamed = -1
    End Select
  End Function

  ' ExternalRunCommand

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Object)
    iKompas = Kompas

    If iKompas Is Nothing Then
      Exit Sub
    End If

    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ActiveDocument3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iDocument3D = iKompas.ActiveDocument3D

    If iDocument3D Is Nothing Then
      Exit Sub
    End If

    'Set iMathematic2D = iKompas.GetMathematic2D

    'If iMathematic2D Is Nothing Then
    '  Exit Sub
    'End If

    Select Case command_Renamed
      Case 1
        CreateExtrusion() ' Операции выдавливания
      Case 2
        OperationRotated() ' Операции вращения
      Case 3
        OperationLoft() ' Оперции по сечениям
      Case 4
        CreateFilletAndChamfer() ' Создание фаски и скругления
    End Select

    'UPGRADE_WARNING: Couldn't resolve default property of Kompas6API5. iKompas.ksMessageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iKompas.ksMessageBoxResult()

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