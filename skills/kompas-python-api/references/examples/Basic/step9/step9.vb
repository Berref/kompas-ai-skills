Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

<ClassInterface(ClassInterfaceType.AutoDispatch), ProgId("StepsVB.Step9")> _
Public Class Step9

  Dim iKompasObject As Object 'KompasObject
  Sub DrawLinDim(ByRef doc As Object) ' Линейный размер
    Dim iParam As Object ' ksLDimParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iParam = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LDimParam)
    Dim idPar As Object
    Dim isPar As Object = Nothing

    Dim itPar As Object
    Dim istr As Object
    Dim iarrText As Object
    Dim obj As Integer ' ksDynamicArray ' ksChar255 ' ksDimTextParam ' ksLDimSourceParam ' ksDimDrawingParam
    If Not iParam Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iParam.GetDPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar = iParam.GetDPar()
      If Not idPar Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.textPos. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.textPos = 10
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.textBase. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.textBase = 2
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.pt1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.pt1 = 2
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.pt2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.pt2 = 2
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.ang. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.ang = -30
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.lenght. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.lenght = 20
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object iParam.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar = iParam.GetSPar()
      If Not isPar Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.X1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.X1 = 50
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Y1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.Y1 = 50
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.X2 = 70
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Y2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.Y2 = 60
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.dx. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.dx = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.dy. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.dy = -20
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.basePoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.basePoint = 1
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object iParam.GetTPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar = iParam.GetTPar()
      If Not itPar Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.Init(0)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.SetBitFlagValue(AUTONOMINAL, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.SetBitFlagValue(PREFIX, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.SetBitFlagValue(DEVIATION, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.SetBitFlagValue(UNIT, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.SetBitFlagValue(SUFFIX, True)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.sign. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itPar.sign = 0

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        istr = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)
        'UPGRADE_WARNING: Couldn't resolve default property of object itPar.GetTextArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iarrText = itPar.GetTextArr()
        If Not iarrText Is Nothing Then
          'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          istr.Str = "prefix"
          'UPGRADE_WARNING: Couldn't resolve default property of object iarrText.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iarrText.ksAddArrayItem(-1, istr)

          'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          istr.Str = "+0,5"
          'UPGRADE_WARNING: Couldn't resolve default property of object iarrText.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iarrText.ksAddArrayItem(-1, istr)

          'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          istr.Str = "-0,5"
          'UPGRADE_WARNING: Couldn't resolve default property of object iarrText.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iarrText.ksAddArrayItem(-1, istr)

          'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          istr.Str = "mm"
          'UPGRADE_WARNING: Couldn't resolve default property of object iarrText.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iarrText.ksAddArrayItem(-1, istr)

          'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          istr.Str = "pp&04ww&01oo"
          'UPGRADE_WARNING: Couldn't resolve default property of object iarrText.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          iarrText.ksAddArrayItem(-1, istr)
        End If
      End If
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLinDimension. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksLinDimension(iParam)
    End If

    If obj And Not isPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(obj, iParam, ALLPARAM)
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.X2 = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Y2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.Y2 = 60
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("Поменяем параметры")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksSetObjParam(obj, iParam, ALLPARAM)
    End If
  End Sub

  Sub DrawAngDim(ByRef doc As Object)
    Dim iaDim As Object ' ksADimParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iaDim = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ADimParam)
    Dim itPar As Object
    Dim itextLine As Object
    Dim itextItem As Object
    Dim iFont As Object
    Dim iArr As Object
    Dim iArr1 As Object
    Dim isPar As Object
    Dim idPar As Object
    Dim obj As Integer ' ksDimDrawingParam ' ksADimSourceParam ' ksDynamicArray ' ksTextItemFont ' ksTextItemParam ' ksDimTextParam
    If Not iaDim Is Nothing Then

      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetTPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar = iaDim.GetTPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.Init(True)

      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itextLine = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
      'UPGRADE_WARNING: Couldn't resolve default property of object itextLine.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itextLine.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itextItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
      'UPGRADE_WARNING: Couldn't resolve default property of object itextItem.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itextItem.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itextItem.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itextItem.s = "Угловой размер"

      'UPGRADE_WARNING: Couldn't resolve default property of object itextItem.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont = itextItem.GetItemFont()
      'UPGRADE_WARNING: Couldn't resolve default property of object iFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont.HEIGHT = 5
      'UPGRADE_WARNING: Couldn't resolve default property of object iFont.ksu. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont.ksu = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object iFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont.FontName = "GOST type A"
      'UPGRADE_WARNING: Couldn't resolve default property of object iFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iFont.SetBitVectorValue(NEW_LINE, True)

      'UPGRADE_WARNING: Couldn't resolve default property of object itextLine.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr = itextLine.GetTextItemArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr.ksAddArrayItem(-1, itextItem)

      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.GetTextArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr1 = itPar.GetTextArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object iArr1.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr1.ksAddArrayItem(-1, itextLine)

      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.rad = 50

      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetDPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar = iaDim.GetDPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object idPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksAngDimension. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksAngDimension(iaDim)
    End If

    Dim isPar2 As Object ' ksADimSourceParam
    If obj Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(obj, iaDim, ALLPARAM)
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2 = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar2.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar2.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2.rad = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("Поменяем параметры")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksSetObjParam(obj, iaDim, ALLPARAM)
    End If
  End Sub
  Sub DrawRough(ByRef doc As Object)
    Dim iroughPar As Object ' ksRoughParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iroughPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RoughParam)
    Dim irPar As Object ' ksRoughPar
    'UPGRADE_WARNING: Couldn't resolve default property of object iroughPar.GetrPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    irPar = iroughPar.GetrPar()
    Dim ishPar As Object ' ksShelfPar
    'UPGRADE_WARNING: Couldn't resolve default property of object iroughPar.GetshPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ishPar = iroughPar.GetshPar()
    Dim istr As Object ' ksChar255
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    istr = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)
    Dim iptext As Object
    Dim obj As Integer ' ksDynamicArray
    If Not iroughPar Is Nothing And Not irPar Is Nothing And Not ishPar Is Nothing And Not istr Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object ishPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ishPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Init()

      ' заполним параметры текста шероховатости
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.Style = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.Type = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.around. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.around = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.x = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.y = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.ang. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.ang = 90
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.cText0 = 2
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.cText1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.cText1 = 2
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.cText2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.cText2 = 2
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.cText3. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      irPar.cText3 = 1

      ' режим, когда тексты задаются массивом строк символов
      'UPGRADE_WARNING: Couldn't resolve default property of object irPar.GetpText. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext = irPar.GetpText
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "1"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "2"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "3"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "4"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "5"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "6"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "7"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)

      ' параметры выносной полки
      'UPGRADE_WARNING: Couldn't resolve default property of object ishPar.psh. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ishPar.psh = 0 ' полки нет
      'UPGRADE_WARNING: Couldn't resolve default property of object ishPar.ang. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ishPar.ang = 130 ' угол наклона ножки
      'UPGRADE_WARNING: Couldn't resolve default property of object ishPar.length. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ishPar.length = 20 ' длина ножки

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksRough. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksRough(iroughPar)

      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, iroughPar, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object irPar.ang. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        irPar.ang = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, iroughPar, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawLeader(ByRef doc As Object)
    Dim ilead As Object ' ksLeaderParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ilead = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LeaderParam)
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont
    Dim itMathPoint As Object ' ksMathPointParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itMathPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)
    Dim iptext As Object
    Dim iTextItemArr As Object
    Dim ipPolyLin As Object
    Dim ipMathPoint As Object
    Dim obj As Integer ' ksDynamicArray
    If Not ilead Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing And Not itMathPoint Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.SetBitVectorValue(NEW_LINE, True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Style = 0

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpTextline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext = ilead.GetpTextline

      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr = itLinePar.GetTextItemArr
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.s = "1"
      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksAddArrayItem(-1, iItemPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, itLinePar)

      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksClearArray()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.s = "2"
      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksAddArrayItem(-1, iItemPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, itLinePar)

      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksClearArray()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.s = "3"
      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksAddArrayItem(-1, iItemPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, itLinePar)

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin = ilead.GetpPolyline
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint = iKompasObject.GetDynamicArray(POINT_ARR)
      If Not ipMathPoint Is Nothing And Not ipPolyLin Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 10
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 10

        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksAddArrayItem(-1, itMathPoint)
        'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 30
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 10
        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksClearArray()
        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksAddArrayItem(-1, itMathPoint)
        'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.SetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.SetpPolyline(ipPolyLin)
      End If

      ' заполним параметры
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.x = 50 ' координаты базовой точки ( начало полки )
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.y = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.arrowType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.arrowType = 1 ' тип стрелки
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.dirX. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.dirX = 1 ' направление полки по X (1 -вправо -1-влево)
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.signType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.signType = 0 ' тип знака
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.around. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.around = 0 ' знак обработки по контуру 0-выключен 1- включен
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText0 = 1 ' количество строк текста над полкой 0- текст отсутствует
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText1 = 1 ' количество строк текста под полкой 0- текст отсутствует
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText2 = 0 ' количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText3. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText3 = 1 ' количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksLeader. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksLeader(ilead)
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, ilead, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.x = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, ilead, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawPosLeader(ByRef doc As Object)
    Dim ilead As Object ' ksPosLeaderParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ilead = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_PosLeaderParam)
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    Dim itMathPoint As Object ' ksMathPointParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itMathPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)
    Dim iptext As Object
    Dim iTextItemArr As Object
    Dim ipPolyLin As Object
    Dim ipMathPoint As Object
    Dim obj As Integer ' ksDynamicArray
    If Not ilead Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing And Not itMathPoint Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.Init()

      'ilead.Style = INDICATIN_TEXT_LINE_ARR
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.SetBitVectorValue(NEW_LINE, True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Style = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpTextline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext = ilead.GetpTextline()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr = itLinePar.GetTextItemArr()

      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.s = "1"
      'UPGRADE_WARNING: Couldn't resolve default property of object iTextItemArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iTextItemArr.ksAddArrayItem(-1, iItemPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, itLinePar)

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin = ilead.GetpPolyline
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint = iKompasObject.GetDynamicArray(POINT_ARR)

      If Not ipPolyLin Is Nothing And Not ipMathPoint Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 10
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 10

        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksAddArrayItem(-1, itMathPoint)
        'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 30
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 10
        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksClearArray()
        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksAddArrayItem(-1, itMathPoint)
        'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.SetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.SetpPolyline(ipPolyLin)
      End If

      ' заполним параметры
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.x = 50 ' координаты базовой точки ( начало полки )
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.y = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.arrowType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.arrowType = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.dirX. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.dirX = -1

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksPositionLeader. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksPositionLeader(ilead)
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, ilead, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.x = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, ilead, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawBrandLeader(ByRef doc As Object)
    Dim ilead As Object ' ksBrandLeaderParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ilead = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_BrandLeaderParam)
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    Dim istr As Object ' ksChar255
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    istr = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)
    Dim itMathPoint As Object ' ksMathPointParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itMathPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)
    Dim iptext As Object
    Dim ipPolyLin As Object
    Dim ipMathPoint As Object
    Dim obj As Integer ' ksDynamicArray
    If Not ilead Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing And Not itMathPoint Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText0 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpTextline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext = ilead.GetpTextline()
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "1"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "2"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "3"
      'UPGRADE_WARNING: Couldn't resolve default property of object iptext.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iptext.ksAddArrayItem(-1, istr)

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin = ilead.GetpPolyline()
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint = iKompasObject.GetDynamicArray(POINT_ARR)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 10

      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)
      'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 30
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksClearArray()
      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)
      'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

      ' заполним параметры
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.x = 50 ' координаты базовой точки ( начало полки )
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.y = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.arrowType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.arrowType = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.dirX. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.dirX = -1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText0 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText1 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText2 = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksBrandLeader. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksBrandLeader(ilead)
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, ilead, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.x = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, ilead, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawMarkerLeader(ByRef doc As Object)
    Dim ilead As Object ' ko_MarkerLeaderParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    ilead = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MarkerLeaderParam)
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    Dim istr As Object ' ksChar255
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    istr = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Char255)
    Dim itMathPoint As Object ' ksMathPointParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itMathPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)
    Dim ipCharArr As Object
    Dim ipPolyLin As Object
    Dim ipMathPoint As Object
    Dim obj As Integer ' ksDynamicArray
    If Not ilead Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing And Not itMathPoint Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText0 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.style1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.style1 = 0

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpTextline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipCharArr = ilead.GetpTextline()
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "1"
      'UPGRADE_WARNING: Couldn't resolve default property of object ipCharArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipCharArr.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "2"
      'UPGRADE_WARNING: Couldn't resolve default property of object ipCharArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipCharArr.ksAddArrayItem(-1, istr)
      'UPGRADE_WARNING: Couldn't resolve default property of object istr.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      istr.Str = "3"
      'UPGRADE_WARNING: Couldn't resolve default property of object ipCharArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipCharArr.ksAddArrayItem(-1, istr)

      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.GetpPolyline. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin = ilead.GetpPolyline()
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetDynamicArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint = iKompasObject.GetDynamicArray(POINT_ARR)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 10

      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)
      'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 30
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksClearArray()
      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)
      'UPGRADE_WARNING: Couldn't resolve default property of object ipPolyLin.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipPolyLin.ksAddArrayItem(-1, ipMathPoint)

      ' заполним параметры
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.x = 50 ' координаты базовой точки ( начало полки )
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.y = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.arrowType. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.arrowType = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText0. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText0 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText1 = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object ilead.cText2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ilead.cText2 = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksMarkerLeader. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksMarkerLeader(ilead)
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, ilead, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object ilead.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ilead.x = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, ilead, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawBase(ByRef doc As Object)
    Dim iPar As Object ' ksBaseParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_BaseParam)
    Dim bas As Integer
    If Not iPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Style. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Style = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Type = False ' строка
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.X1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.X1 = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Y1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Y1 = 10
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.X2 = 30
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Y2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Y2 = 40
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Str = "Это база"
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksBase. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      bas = doc.ksBase(iPar)
      'UPGRADE_WARNING: Couldn't resolve default property of object iPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iPar.Init()
      If bas Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(bas, iPar, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object iPar.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iPar.X2 = -30
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(bas, iPar, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawCutLine(ByRef doc As Object)
    Dim icut As Object ' ko_CutLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    icut = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_CutLineParam)
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    Dim itMathPoint As Object ' ksMathPointParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itMathPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_MathPointParam)
    Dim ipMathPoint As Object
    Dim obj As Integer
    Dim ipMathPoint2 As Object ' ksDynamicArray
    If Not icut Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing And Not itMathPoint Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Type = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.X1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.X1 = 30
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Y1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Y1 = 65
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.X2 = 95
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Y2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Y2 = 15
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Right. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Right = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      icut.Str = "A$;1$"
      'UPGRADE_WARNING: Couldn't resolve default property of object icut.GetpMathPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint = icut.GetpMathPoint()

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 50

      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 30

      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)

      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.x = 80
      'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itMathPoint.y = 30

      'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      ipMathPoint.ksAddArrayItem(-1, itMathPoint)

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCutLine. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksCutLine(icut)
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, icut, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object icut.GetpMathPoint. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint2 = icut.GetpMathPoint()
        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint.ksClearArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint.ksClearArray()

        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 30
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 50

        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint2.ksAddArrayItem(-1, itMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 30
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 30

        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint2.ksAddArrayItem(-1, itMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.x. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.x = 80
        'UPGRADE_WARNING: Couldn't resolve default property of object itMathPoint.y. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        itMathPoint.y = 30

        'UPGRADE_WARNING: Couldn't resolve default property of object ipMathPoint2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        ipMathPoint2.ksAddArrayItem(-1, itMathPoint)

        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, icut, ALLPARAM)
      End If
    End If
  End Sub
  Sub DrawDiamDim(ByRef doc As Object)
    Dim cir As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    cir = doc.ksCircle(100, 100, 50, 1)
    Dim iaDim As Object ' ksRDimParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iaDim = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RDimParam)
    Dim itPar As Object ' ksDimTextParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetTPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itPar = iaDim.GetTPar()
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()

    Dim iArr As Object
    Dim iArr2 As Object
    Dim isPar As Object
    Dim idPar As Object
    Dim obj As Integer ' ksDimDrawingParam ' ksRDimSourceParam ' ksDynamicArray
    If Not iaDim Is Nothing And Not itPar Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.Init(True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.SetBitFlagValue(AUTONOMINAL, True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.sign. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.sign = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.HEIGHT = 5
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.ksu. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.ksu = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.FontName = "GOST type A"
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.SetBitVectorValue(NEW_LINE, True)

      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr = itLinePar.GetTextItemArr
      'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr.ksAddArrayItem(-1, iItemPar)

      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.GetTextArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr2 = itPar.GetTextArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr2.ksAddArrayItem(-1, itLinePar)

      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.xc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.xc = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.yc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.yc = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.rad = 50

      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetDPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar = iaDim.GetDPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object idPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDiamDimension. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksDiamDimension(iaDim)
    End If
    Dim isPar2 As Object ' ksRDimSourceParam
    If obj Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(obj, iaDim, ALLPARAM)
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2 = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar2.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2.rad = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("Поменяем параметры")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksDeleteObj(cir)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksCircle(100, 100, 100, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksSetObjParam(obj, iaDim, ALLPARAM)
    End If
  End Sub
  Sub DrawRadDimt(ByRef doc As Object)
    Dim cir As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    cir = doc.ksCircle(100, 100, 50, 1)
    Dim iaDim As Object ' ksRDimParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iaDim = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RDimParam)
    Dim itPar As Object ' ksDimTextParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetTPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itPar = iaDim.GetTPar()
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    Dim iArr As Object
    Dim iArr2 As Object
    Dim isPar As Object = Nothing

    Dim idPar As Object
    Dim obj As Integer ' ksDimDrawingParam ' ksRDimSourceParam ' ksDynamicArray
    If Not iaDim Is Nothing And Not itPar Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.Init(True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.SetBitFlagValue(AUTONOMINAL, True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.sign. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.sign = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.HEIGHT = 5
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.ksu. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.ksu = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.FontName = "GOST type A"
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.SetBitVectorValue(NEW_LINE, True)

      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr = itLinePar.GetTextItemArr
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.GetTextArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr2 = itPar.GetTextArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetDPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar = iaDim.GetDPar()
      If Not iArr Is Nothing And Not iArr2 Is Nothing And Not isPar Is Nothing And Not idPar Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.Init()

        'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArr.ksAddArrayItem(-1, iItemPar)
        'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArr2.ksAddArrayItem(-1, itLinePar)

        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.xc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.xc = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.yc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.yc = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.rad = 50
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksRadDimension. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksRadDimension(iaDim)
    End If
    Dim isPar2 As Object ' ksRDimSourceParam
    If obj And Not isPar Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(obj, iaDim, ALLPARAM)
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2 = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar.rad = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("Поменяем параметры")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksDeleteObj(cir)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksCircle(100, 100, 100, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksSetObjParam(obj, iaDim, ALLPARAM)
    End If
  End Sub
  Sub DrawRadBreakDimt(ByRef doc As Object)
    Dim cir As Integer
    'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    cir = doc.ksCircle(100, 100, 50, 1)
    Dim iaDim As Object ' ksRBreakDimParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iaDim = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RBreakDimParam)
    Dim itPar As Object ' ksDimTextParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetTPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itPar = iaDim.GetTPar
    Dim itLinePar As Object ' ksTextLineParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itLinePar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object ' ksTextItemFont
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont
    Dim iArr As Object
    Dim iArr2 As Object
    Dim isPar As Object
    Dim idPar As Object
    Dim obj As Integer ' ksRBreakDrawingParam ' ksRDimSourceParam ' ksDynamicArray
    If Not iaDim Is Nothing And Not itPar Is Nothing And Not itLinePar Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.Init(True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itLinePar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.SetBitFlagValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.SetBitFlagValue(AUTONOMINAL, True)
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.sign. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itPar.sign = 1

      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.HEIGHT. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.HEIGHT = 5
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.ksu. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.ksu = 1
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.FontName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.FontName = "GOST type A"
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.SetBitVectorValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.SetBitVectorValue(NEW_LINE, True)

      'UPGRADE_WARNING: Couldn't resolve default property of object itLinePar.GetTextItemArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr = itLinePar.GetTextItemArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object itPar.GetTextArr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iArr2 = itPar.GetTextArr()
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetDPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      idPar = iaDim.GetDPar()
      If Not iArr Is Nothing And Not iArr2 Is Nothing And Not isPar Is Nothing And Not idPar Is Nothing Then
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.Init()
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.Init()

        'UPGRADE_WARNING: Couldn't resolve default property of object iArr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArr.ksAddArrayItem(-1, iItemPar)
        'UPGRADE_WARNING: Couldn't resolve default property of object iArr2.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iArr2.ksAddArrayItem(-1, itLinePar)

        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.xc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.xc = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.yc. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.yc = 100
        'UPGRADE_WARNING: Couldn't resolve default property of object isPar.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        isPar.rad = 50

        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.ang. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.ang = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.pb. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.pb = 30
        'UPGRADE_WARNING: Couldn't resolve default property of object idPar.pt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        idPar.pt = 1
      End If

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksRadBreakDimension. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksRadBreakDimension(iaDim)
    End If

    Dim isPar2 As Object ' ksRDimSourceParam
    If obj Then
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksGetObjParam(obj, iaDim, ALLPARAM)
      'UPGRADE_WARNING: Couldn't resolve default property of object iaDim.GetSPar. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2 = iaDim.GetSPar()
      'UPGRADE_WARNING: Couldn't resolve default property of object isPar2.rad. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      isPar2.rad = 100
      'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iKompasObject.ksMessage("Поменяем параметры")
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksDeleteObj(cir)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksCircle(100, 100, 100, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      doc.ksSetObjParam(obj, iaDim, ALLPARAM)
    End If
  End Sub
  Sub DrawViewPointer(ByRef doc As Object)
    Dim obj As Object
    Dim iviewPoint As Object ' ksViewPointerParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iviewPoint = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_ViewPointerParam)
    Dim iItemPar As Object ' ksTextItemParam
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iItemPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
    Dim itFont As Object '
    'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.GetItemFont. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    itFont = iItemPar.GetItemFont()
    '    Dim p As Integer
    If Not iviewPoint Is Nothing And Not iItemPar Is Nothing And Not itFont Is Nothing Then
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object iItemPar.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iItemPar.Init()
      'UPGRADE_WARNING: Couldn't resolve default property of object itFont.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      itFont.Init()

      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.X1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.X1 = 55
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Y1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.Y1 = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.X2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.X2 = 40
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Y2. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.Y2 = 50
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.xt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.xt = 40
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.yt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.yt = 52
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.Type = 0
      'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      iviewPoint.Str = "стрелка"

      'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksViewPointer. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      'UPGRADE_WARNING: Couldn't resolve default property of object obj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      obj = doc.ksViewPointer(iviewPoint)
      'UPGRADE_WARNING: Couldn't resolve default property of object obj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      If obj Then
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksGetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksGetObjParam(obj, iviewPoint, ALLPARAM)
        'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iviewPoint.Type = 0
        'UPGRADE_WARNING: Couldn't resolve default property of object iviewPoint.Str. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iviewPoint.Str = "стрелка вида"
        'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        iKompasObject.ksMessage("Поменяем параметры")
        'UPGRADE_WARNING: Couldn't resolve default property of object doc.ksSetObjParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        doc.ksSetObjParam(obj, iviewPoint, ALLPARAM)
      End If
    End If
  End Sub

  ' GetLibraryName

  Public Function GetLibraryName() As String
    GetLibraryName = "Размеры и другие технологические объекты"
  End Function

  ' ExternalMenuItem

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = "Линейный размер"
        command_Renamed = 1
      Case 2
        ExternalMenuItem = "Угловой  размер"
        command_Renamed = 2
      Case 3
        ExternalMenuItem = "Шероховатость"
        command_Renamed = 3
      Case 4
        ExternalMenuItem = "Линия выноски"
        command_Renamed = 4
      Case 5
        ExternalMenuItem = "Позиционная линия выноски"
        command_Renamed = 5
      Case 6
        ExternalMenuItem = "Клеймение"
        command_Renamed = 6
      Case 7
        ExternalMenuItem = "Маркирование"
        command_Renamed = 7
      Case 8
        ExternalMenuItem = "Обозначение базы"
        command_Renamed = 8
      Case 9
        ExternalMenuItem = "Линия разреза/cечения"
        command_Renamed = 9
      Case 10
        ExternalMenuItem = "Диаметральный размер"
        command_Renamed = 10
      Case 11
        ExternalMenuItem = "Радиальный размер"
        command_Renamed = 11
      Case 12
        ExternalMenuItem = "Радиальный размер с изломом"
        command_Renamed = 12
      Case 13
        ExternalMenuItem = "Стрелка вида"
        command_Renamed = 13
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
        DrawLinDim(iDocument2D) ' Линейный размер
      Case 2
        DrawAngDim(iDocument2D) ' Угловой  размер
      Case 3
        DrawRough(iDocument2D) ' Шероховатость
      Case 4
        DrawLeader(iDocument2D) ' Линия выноски
      Case 5
        DrawPosLeader(iDocument2D) ' Позиционная линия выноски
      Case 6
        DrawBrandLeader(iDocument2D) ' Клеймение
      Case 7
        DrawMarkerLeader(iDocument2D) ' Маркирование
      Case 8
        DrawBase(iDocument2D) ' Обозначение базы
      Case 9
        DrawCutLine(iDocument2D) ' Линия разреза/cечения
      Case 10
        DrawDiamDim(iDocument2D) ' Диаметральный размер
      Case 11
        DrawRadDimt(iDocument2D) ' Радиальный размер
      Case 12
        DrawRadBreakDimt(iDocument2D) ' Радиальный размер с изломом
      Case 13
        DrawViewPointer(iDocument2D) ' Стрелка вида
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