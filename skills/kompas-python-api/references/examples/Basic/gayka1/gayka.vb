Option Strict Off
Option Explicit On
'UPGRADE_WARNING: Class instancing was changed to public. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="ED41034B-3890-49FC-8076-BD6FC2F42A85"'
<System.Runtime.InteropServices.ProgId("GaykaObj_NET.GaykaObj")> Public Class GaykaObj
	
	'--------------------------------------------------------------------------------------
	'
	'
	'-------------------------------------------------------------------------------------
	Private Structure GaykaParam ' параметры гайки ГОСТ 5915-70
		Dim dr As Single
		Dim s As Single
		Dim d As Single
		Dim da As Single
		Dim H As Single
		Dim d2 As Single
		Dim p As Single
		'UPGRADE_NOTE: Class was upgraded to Class_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
		Dim Class_Renamed As Short ' класс точности
		Dim gost As Short ' номер госта
		Dim hatchAng As Single ' угол штриховки
		Dim hatchStep As Single ' шаг штриховки
		Dim massa As Single ' масса
		Dim indexMassa As Short ' 0-металл 1- алюмин сплав 2-латунь
		Dim perform As Byte ' исполнение
		Dim simple As Byte ' упрощенно
		Dim axis_off As Byte ' выкл/вкл ось
		Dim pitch As Byte ' мелкий шаг
		Dim pitch_off As Byte ' мелкий шаг не возможен
		Dim key_s As Byte ' дополнительный размер под ключ
		Dim key_s_on As Byte ' дополнительный размер под ключ вкл
		Dim key_s_gray As Byte ' дополнительный размер под ключ не возможен
		Dim koef_mat_on As Byte ' коэф материала
		Dim ver As Short ' версия макро
	End Structure
	
	Private Structure BaseMakroParam ' базовые параметры
		Dim ang As Single ' угол поворота
		Dim flagAttr As Short ' флаг создания объекта спецификации
		Dim drawType As Short ' тип изображения
		Dim typeSwitch As Byte ' тип запроса положения базовой точки элемента 0 Placement 1 Curso
		' 0 - точка + направление оси 0X ( Placement );
		' 1 - точка, направление совпадает с осью 0X текущей СК ( Cursor ).
	End Structure
	
	
	' указатели на отношения к БД
	Private Structure SimpleBase
		Dim bg As Integer ' указатель базы
		Dim rg As Integer ' указатель отношения
	End Structure
	
	
	
	Const ID_VID As Short = 1
	Const ID_SIDEVID As Short = 2
	Const ID_TOPVID As Short = 3
	Const ID_VIDSEC As Short = 4
	
	' название колонок для спецификации
	Const SPC_FORMAT As Short = 1 ' формат
	Const SPC_ZONA As Short = 2 ' зона
	Const SPC_POSITION As Short = 3 ' позиция
	Const SPC_MARKER As Short = 4 ' обозначение
	Const SPC_NAME As Short = 5 ' наименование
	Const SPC_COUNT As Short = 6 ' количество
	Const SPC_NOTE As Short = 7 ' примечание
	
	Const SPC_CLEAR_GEOM As Short = 0 ' очищать геометрию при редактировании объекта спецификации
	Const STANDART_SECTION As Short = 25
	
	Const COUNT_MASSA As Short = 1000
	Const MAX_COUNT_SPCOBJ As Short = 4 ' максимальное число объектов СП за раз 4
	
	' Контролы панели свойств
	Const DIAM_ID As Short = 10001 ' Комбобокс диаметров резьбы
	Const VIEWSIDE_ID As Short = 10002 ' Кнопки отображения
	Const PERFORMANCE_ID As Short = 10003 ' Кнопки исполнений
	Const SIMPLES_ID As Short = 10004 ' Кнопки упрощений
	Const ADD_PARAM_ID As Short = 10005 ' Кнопки доп. параметров
	Const SPC_CHECK_ID As Short = 10006 ' Чекбокс объекта сп
	Const ANGLE_HATCH_ID As Short = 10007 ' угол штриховки
	Const STEP_HATCH_ID As Short = 10008 ' шаг штриховки
	Const PARAMS_ID As Short = 10009 ' список параметров
	Const VIEW_BOX_ID As Short = 10010 ' окно просмотра
	'Const STR_EDIT_ID = 10011    '
	'Const STR_LIST_ID = 10012    '
	
	' Кнопки панели свойств
	Const BASE_VIEW As Short = 2001 ' Главный вид
	Const LEFT_VIEW As Short = 2002 ' Вид слева
	Const TOP_VIEW As Short = 2003 ' Вид сверху
	Const SEC_VIEW As Short = 2004 ' Вид\разрез
	Const PERF1_VIEW As Short = 2005 ' Исполнение 1
	Const PERF2_VIEW As Short = 2006 ' Исполнение 2
	Const SIMPLE_VIEW As Short = 2007 ' Упрошено
	Const DRAW_AXIS As Short = 2008 ' Рисовать ось
	Const ADDSTEP_BUTT As Short = 2009 ' Мелкий шаг
	Const KEY_BUTT As Short = 2010 ' Доп. размер под ключ
	Const MODSTEP_REAL As Double = 0.5412765877 ' коэффициент для расчета диаметра резьбы по шагу резьбы
	
	
	'-------------------------------------------------------------------------------------
	'
	'
	'-------------------------------------------------------------------------------------
	' базовые параметры
	Private par As BaseMakroParam ' базовые параметры
	Private tmp As GaykaParam ' структура параметров гайки ГОСТ 5915-70
	Private base As SimpleBase ' референсы БД
	
	Private flagMode As Integer ' true - режим редактирования
	Private refMacr As Integer ' референс МАКРО
	Private paramTmp As Object ' ksUserParam параметры для чтения БД
	Private Param As Object ' ksUserParam параметры для Get/SetMacroParam
	Private data As Object ' объект для работы
	Private spcObj(4) As Integer ' массив референсов объектов спецификации
	Public countObj As Short
	Private flagSwitch As Boolean ' false переключения нет true переключение с
	' Placement на Cursor
	Public WithEvents hatchPar As HatchControl1.HatchControl
	Private WithEvents iUserCtrl As KompasAPI7.PropertyUserControl
	Public WithEvents iProcParam As KompasAPI7.ProcessParam
	Private iDiamEdit As KompasAPI7.PropertyList
	Private iViewButt As KompasAPI7.PropertyMultiButton
	Private iPerfButt As KompasAPI7.PropertyMultiButton
	Private iSimpButt As KompasAPI7.PropertyMultiButton
	Private iAddButt As KompasAPI7.PropertyMultiButton
	Private iSpcCheck As KompasAPI7.PropertyCheckBox
	Private iAngleEdit As KompasAPI7.PropertyEdit
	Private iStepEdit As KompasAPI7.PropertyEdit
	Private phantom As Kompas6API5.ksPhantom
	'Private iTestStringEdit As KompasAPI7.PropertyEdit
	'Private iTestStringList As KompasAPI7.PropertyList
	
	
	
	
	' инициализация
	Sub InitUserParam()
		Dim item As Object
		Dim arr As Object ' ksDynamicArray ' ksLtVariant
		If Not Param Is Nothing Then
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			arr = iKompasObject.GetDynamicArray(LTVARIANT_ARR)
			If (Not item Is Nothing) And (Not arr Is Nothing) Then
				'UPGRADE_WARNING: Couldn't resolve default property of object Param.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Param.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object Param.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Param.SetUserArray(arr)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = par.ang ' 0 - ang
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.flagAttr ' 1 - flagAttr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.drawType ' 2 - drawType
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.typeSwitch ' 3 - typeSwitch
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.dr ' 4 - dr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.s ' 5 - s
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d ' 6 - D
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.da ' 7 - da
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.H ' 8 - h
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d2 ' 9 - d2
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.p ' 10 - p
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.Class_Renamed ' 11 - class
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.gost ' 12 - gost
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.hatchAng ' 13 - hatchAng
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.hatchStep ' 14 - hatchShag
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.massa ' 15 - m
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.indexMassa ' 16 - indexMassa
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.perform ' 17 - perform
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.simple ' 18 - simple
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.axis_off ' 19 - axis_off
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.pitch ' 20 - pitch
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.pitch_off ' 21 - pitch_off
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s ' 22 - key_s
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s_on ' 23 - key_s_on
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s_gray ' 24 - key_s_gray
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.koef_mat_on ' 25 - koef_mat_on
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.ver ' 26 - ver
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
			End If
		End If
	End Sub
	
	' сохранить параметры
	Sub SetUserParam()
		Dim item As Object
		Dim arr As Object ' ksDynamicArray ' ksLtVariant
		If Not Param Is Nothing Then
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			'UPGRADE_WARNING: Couldn't resolve default property of object Param.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			arr = Param.GetUserArray
			'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			If (Not item Is Nothing) And (Not arr Is Nothing) And arr.ksGetArrayCount >= 20 Then
				'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = par.ang ' 0 - ang
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(0, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.flagAttr ' 1 - flagAttr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.drawType ' 2 - drawType
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(2, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = par.typeSwitch ' 3 - typeSwitch
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(3, item)
				
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.dr ' 4 - dr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(4, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.s ' 5 - s
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(5, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d ' 6 - D
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(6, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.da ' 7 - da
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(7, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.H ' 8 - h
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(8, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d2 ' 9 - d2
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(9, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.p ' 10 - p
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(10, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.Class_Renamed ' 11 - class
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(11, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.gost ' 12 - gost
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(12, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.hatchAng ' 13 - hatchAng
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(13, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.hatchStep ' 14 - hatchShag
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(14, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.massa ' 15 - m
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(15, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.indexMassa ' 16 - indexMassa
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(16, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.perform ' 17 - perform
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(17, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.simple ' 18 - simple
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(18, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.axis_off ' 19 - axis_off
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(19, item)
				
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.pitch ' 20 - pitch
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(20, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.pitch_off ' 21 - pitch_off
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(21, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s ' 22 - key_s
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(22, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s_on ' 23 - key_s_on
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(23, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.key_s_gray ' 24 - key_s_gray
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(24, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uCharVal = tmp.koef_mat_on ' 25 - koef_mat_on
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(25, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.shortVal = tmp.ver ' 26 - ver
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(26, item)
			End If
		End If
	End Sub
	
	' получить параметры
	Sub GetUserParam()
		Dim item As Object
		Dim arr As Object
		Dim count As Single ' ksDynamicArray ' ksLtVariant
		If Not Param Is Nothing Then
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			'UPGRADE_WARNING: Couldn't resolve default property of object Param.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			arr = Param.GetUserArray
			If (Not item Is Nothing) And (Not arr Is Nothing) Then
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				count = arr.ksGetArrayCount
				
				If count >= 27 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					item.init()
					
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(0, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					par.ang = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(1, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					par.flagAttr = item.shortVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(2, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					par.drawType = item.shortVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(3, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					par.typeSwitch = item.shortVal
					
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(4, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.dr = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(5, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.s = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(6, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.d = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(7, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.da = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(8, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.H = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(9, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.d2 = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(10, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.p = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(11, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.Class_Renamed = item.shortVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(12, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.gost = item.shortVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(13, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.hatchAng = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(14, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.hatchStep = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(15, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.massa = item.floatVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(16, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.indexMassa = item.shortVal
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(17, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.perform = item.uCharVal ' 17 - perform
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(18, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.simple = item.uCharVal ' 18 - simple
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(19, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.axis_off = item.uCharVal ' 19 - axis_off
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(20, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.pitch = item.uCharVal ' 20 - pitch
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(21, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.pitch_off = item.uCharVal ' 21 - pitch_off
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(22, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.key_s = item.uCharVal ' 22 - key_s
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(23, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.key_s_on = item.uCharVal ' 23 - key_s_on
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(24, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.key_s_gray = item.uCharVal ' 24 - key_s_gray
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(25, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uCharVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.koef_mat_on = item.uCharVal ' 25 - koef_mat_on
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(26, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object item.shortVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.ver = item.shortVal ' 26 - ver
				End If
			End If
		End If
	End Sub
	
	' сохранить параметры в модели
	Sub SetParam()
		SetUserParam()
		iDocument2D.ksSetMacroParam(refMacr, Param, False, False, False)
	End Sub
	
	' Функция обратной связи, вызываемая из Placement
	Public Function CALLBACKPROCPLACEMENT(ByRef comm As Short, ByRef X As Double, ByRef Y As Double, ByRef ang As Double, ByRef info As Object, ByRef phan As Object, ByRef dynamic As Short) As Short
    '		Dim ChoiceMenu As Object
		Dim t1 As Object
		'UPGRADE_WARNING: Couldn't resolve default property of object phan.GetPhantomParam. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		t1 = phan.GetPhantomParam
		Dim gr As Integer
		If dynamic = 0 Then ' фиксация
			Select Case comm
				Case -1 ' поставить в модель
					par.ang = ang
					SetParam()
					iDocument2D.ksSetMacroPlacement(refMacr, X, Y, ang, 0)
					'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksStoreTmpGroup(t1.gr)
					'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					If DrawSpcObj(t1.gr) Then
						'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						iDocument2D.ksClearGroup(t1.gr, True)
						CALLBACKPROCPLACEMENT = 0
						Exit Function
					End If
					
					'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksClearGroup(t1.gr, True)
					If flagMode > 0 Then
						CALLBACKPROCPLACEMENT = 0
						Exit Function
					End If
			End Select
			
      info.commandsString = ""
			GetGroup(gr)
			'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			t1.gr = gr
		Else
			par.ang = ang
		End If
		
		CALLBACKPROCPLACEMENT = 1
	End Function
	
	' процесс вставки гайки в модель
	Sub Draw()
		Dim iTestStringList As Object
		Dim iTestStringEdit As Object
		Dim i As Object
		Dim flagCalcPaket As Object
		par.typeSwitch = False
		
		phantom = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_Phantom)
		Dim t1 As Object
		Dim j As Short
		Dim X As Double
		Dim Y As Double
		Dim ang As Double
		Dim gr As Integer
		Dim info As Object
		Dim iSpc As Object
		Dim count As Short ' ksSpecification ' ksRequestInfo ' ksType1
		If Not phantom Is Nothing Then
			phantom.init()
			phantom.phantom = 1
			t1 = phantom.GetPhantomParam
			If Not t1 Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object t1.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				t1.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object t1.scale_. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				t1.scale_ = 1
				'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				t1.gr = 0 ' временная группа
				j = 1 :  : If iKompasObject.ksReturnResult = 0 Then
					flagMode = iDocument2D.ksEditMacroMode
					
					If MacroElementParam() Then
						Do 
							flagSwitch = False
							'UPGRADE_WARNING: Couldn't resolve default property of object flagCalcPaket. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
							flagCalcPaket = False
							GetGroup(gr)
							'UPGRADE_WARNING: Couldn't resolve default property of object t1.gr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
							t1.gr = gr
							'UPGRADE_WARNING: Couldn't resolve default property of object t1.angle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
							t1.angle = par.ang
							
							info = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
							If Not info Is Nothing Then
								'UPGRADE_WARNING: Couldn't resolve default property of object info.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
								info.init()
								'UPGRADE_WARNING: Couldn't resolve default property of object info.dynamic. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
								info.dynamic = 1
								
								' указываем адрес обратной функции для Placement
								'UPGRADE_WARNING: Couldn't resolve default property of object info.SetCallBackP. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
								info.SetCallBackP("CALLBACKPROCPLACEMENT", 0, Me)
								j = iDocument2D.ksPlacementEx(info, X, Y, ang, phantom, iProcParam)
								
								If spcObj(0) > 0 Then
									iSpc = iDocument2D.GetSpecification()
									count = countObj
									For i = 0 To count - 1
										' Олегово окно - редактируем параметры
										'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
										'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksEditWindowSpcObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
										If Not iSpc Is Nothing And iSpc.ksEditWindowSpcObject(spcObj(i)) Then
											'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
											DrawPosLeader(spcObj(i), iSpc)
										End If
									Next i
									
									spcObj(0) = 0
									
									If flagMode = 0 Then
										flagSwitch = True
										If par.typeSwitch Then
											par.typeSwitch = 0
										Else
											par.typeSwitch = 1
										End If
									End If
									
								End If
								
								If flagSwitch = True Then
									j = 1
									If par.typeSwitch > 0 Then
										par.typeSwitch = 0
									Else
										par.typeSwitch = 1
									End If
								End If
							End If
						Loop While j
						
						CloseGaykaBase() ' закрытие базы
						
						'UPGRADE_NOTE: Object iDiamEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iDiamEdit = Nothing
						'UPGRADE_NOTE: Object iViewButt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iViewButt = Nothing
						'UPGRADE_NOTE: Object iPerfButt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iPerfButt = Nothing
						'UPGRADE_NOTE: Object iSimpButt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iSimpButt = Nothing
						'UPGRADE_NOTE: Object iAddButt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iAddButt = Nothing
						'UPGRADE_NOTE: Object iSpcCheck may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iSpcCheck = Nothing
						'UPGRADE_NOTE: Object iAngleEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iAngleEdit = Nothing
						'UPGRADE_NOTE: Object iStepEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iStepEdit = Nothing
						'UPGRADE_NOTE: Object iUserCtrl may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iUserCtrl = Nothing
						'UPGRADE_NOTE: Object iProcParam may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iProcParam = Nothing
						'UPGRADE_NOTE: Object iTestStringEdit may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iTestStringEdit = Nothing
						'UPGRADE_NOTE: Object iTestStringList may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						iTestStringList = Nothing
					End If
				End If
			End If
		End If
	End Sub
	
	' создание МАКРО гайки
	Public Sub GetGroup(ByRef gr As Integer)
		Dim k2 As Short
		If tmp.perform = 1 Then
			k2 = 2
		Else
			k2 = 1
		End If
		
		If CBool(iDocument2D.ksExistObj(gr)) Then
			iDocument2D.ksDeleteObj(gr)
		End If
		
		gr = iDocument2D.ksNewGroup(1)
		iDocument2D.ksMacro(0)
		Select Case par.drawType
			Case ID_VID ' вид
				If tmp.simple = 0 Then
					gayka_k(0, 0, 0, tmp.s, tmp.d, 0, tmp.H, 1, 0, tmp.d2, k2)
					gayka_k(0, 0, 0, tmp.s, tmp.d, 0, tmp.H, -1, 0, tmp.d2, k2)
				Else
					gayka_k_y(0, 1)
					gayka_k_y(0, -1)
				End If
				
				If tmp.axis_off = 0 Then
					iDocument2D.ksLineSeg(-3, 0, tmp.H + 3, 0, 3)
				End If
			Case ID_SIDEVID 'вид сбоку
				If tmp.axis_off = 0 Then
					iDocument2D.ksLineSeg(-3, 0, tmp.H + 3, 0, 3)
				End If
				
				If tmp.simple = 1 Then
					k2 = 3
				End If
				
				gayka_k_side(0, tmp.s, tmp.d, tmp.d2, tmp.H, 1, k2)
				gayka_k_side(0, tmp.s, tmp.d, tmp.d2, tmp.H, -1, k2)
			Case ID_TOPVID : gayka_sverhu() ' вид ссверху
			Case ID_VIDSEC ' пол-вида/пол-разреза
				If tmp.simple = 0 Then
					gayka_k(0, 0, 0, tmp.s, tmp.d, 0, tmp.H, 1, 0, tmp.d2, k2)
				Else
					gayka_k_y(0, 1)
				End If
				
				gayka_p_k(-1)
				
				If tmp.axis_off = 0 Then
					iDocument2D.ksLineSeg(-3, 0, tmp.H + 3, 0, 3)
				End If
		End Select
		refMacr = iDocument2D.ksEndObj
		iDocument2D.ksEndGroup()
	End Sub
	
	' Создание и инициализация параметров гайки на панели свойств
	Function MacroElementParam() As Boolean
		MacroElementParam = False
		
		Dim iTabs As KompasAPI7.PropertyTabs
		Dim iTab As KompasAPI7.PropertyTab
		Dim iCtrls As KompasAPI7.PropertyControls
		Dim item As Kompas6API5.ksLtVariant
		Dim arr As Kompas6API5.ksDynamicArray
		Dim i As Short
		Dim sep As KompasAPI7.PropertySeparator
		Dim fullPath As String = ""
		If Not iKomApp Is Nothing Then
			OpenGaykaBase()
			
			iProcParam = iKomApp.CreateProcessParam
			iProcParam.Caption = "Гайка ГОСТ 5915-70"
			iProcParam.SpecToolbar = Kompas6Constants.SpecPropertyToolBarEnum.pnEnterEscCreateHelp
			
			iTabs = iProcParam.PropertyTabs
			
			iTab = iTabs.Add("Параметры гайки")
			
			iCtrls = iTab.PropertyControls
			
			'    Set iTestStringEdit = iCtrls.Add(ksControlEditStr)
			'    iTestStringEdit.name = "Тест строкового редактора"
			'    iTestStringEdit.Id = STR_EDIT_ID
			'    iTestStringEdit.Width = 17
			'    iTestStringEdit.Value = "Пробная строка"
			'    Set iTestStringList = iCtrls.Add(ksControlListStr)
			'    iTestStringList.name = "Тест строкового списка"
			'    iTestStringList.Id = STR_LIST_ID
			'    iTestStringList.Sort = False
			'    iTestStringList.Width = 7
			'    iTestStringList.Add ("Строка 1")
			'    iTestStringList.Add ("Строка 2")
			'    iTestStringList.Add ("Строка 3")
			'    iTestStringList.Add ("Строка 4")
			'    iTestStringList.Value = "Строка 2"
			
			' Диаметр резьбы
			iDiamEdit = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlListReal)
			iDiamEdit.name = "&Диаметр"
			iDiamEdit.Id = DIAM_ID
			iDiamEdit.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameAlwaysVisible
			iDiamEdit.Sort = False
			iDiamEdit.Width = 7
			iDiamEdit.ReadOnly = True
			iDiamEdit.Hint = "Диаметр резьбы"
			iDiamEdit.Tips = "Диаметр резьбы"
			
			' заполним список диаметров
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			'UPGRADE_WARNING: Couldn't resolve default property of object paramTmp.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			arr = paramTmp.GetUserArray()
			If (Not item Is Nothing) And (Not arr Is Nothing) Then
				i = 1
				Do While i
					'UPGRADE_WARNING: Couldn't resolve default property of object data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					i = data.ksReadRecord(base.bg, base.rg, paramTmp)
					
					If i > 0 Then
						arr.ksGetArrayItem(0, item)
						iDiamEdit.Add((item.floatVal))
					End If
				Loop 
			End If
			
			iDiamEdit.Value = tmp.dr ' выделим текущий диаметр гайки
			
			' Разделитель
			sep = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlSeparator)
			sep.name = "Отображение"
			sep.SeparatorType = Kompas6Constants.SeparatorTypeEnum.ksSeparatorDownName
			'UPGRADE_NOTE: Object sep may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			sep = Nothing
			
			iViewButt = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlMultiButton)
			iViewButt.Id = VIEWSIDE_ID ' Кнопки отображения
			iViewButt.name = "&Вид отображения"
			iViewButt.Tips = "Вид отображения"
			iViewButt.Hint = "Вид отображения гайки"
			iViewButt.ButtonsType = Kompas6Constants.ButtonTypeEnum.ksRadioButton
			iViewButt.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameVerticalVisible
			' при отладке App.hInstance указывает на VB а не на библиотеку, поэтому
			' битмапы достаем из файлов, для этого их нужно положить тудаже где лежит
			' собранный dll, в конечном приложении можно оставить идентификаторы чтобы
			' битмапы брались из ресурсов библиотеки
      iViewButt.ResModule = System.Reflection.Assembly.GetExecutingAssembly().Location()
			
			If GetFullName("G_view.bmp", fullPath) Then
				iViewButt.AddButton(BASE_VIEW, fullPath) ' Главный вид
			Else
				iViewButt.AddButton(BASE_VIEW, BASE_VIEW) ' Главный вид
			End If
			
			If GetFullName("G_left.bmp", fullPath) Then
				iViewButt.AddButton(LEFT_VIEW, fullPath) ' Вид слева
			Else
				iViewButt.AddButton(LEFT_VIEW, LEFT_VIEW) ' Вид слева
			End If
			
			If GetFullName("G_top.bmp", fullPath) Then
				iViewButt.AddButton(TOP_VIEW, fullPath) ' Вид сверху
			Else
				iViewButt.AddButton(TOP_VIEW, TOP_VIEW) ' Вид сверху
			End If
			
			If GetFullName("G_sec.bmp", fullPath) Then
				iViewButt.AddButton(SEC_VIEW, fullPath) ' Вид\разрез
			Else
				iViewButt.AddButton(SEC_VIEW, SEC_VIEW) ' Вид\разрез
			End If
			
			Select Case par.drawType ' выделим текущий вид
				Case ID_VID : iViewButt.ButtonChecked(BASE_VIEW) = True ' главный вид
				Case ID_SIDEVID : iViewButt.ButtonChecked(LEFT_VIEW) = True ' вид сбоку
				Case ID_TOPVID : iViewButt.ButtonChecked(TOP_VIEW) = True ' вид сверху
				Case ID_VIDSEC : iViewButt.ButtonChecked(SEC_VIEW) = True ' главный вид \ разрез
			End Select
			
			iViewButt.ButtonTips(BASE_VIEW) = "Главный вид"
			iViewButt.ButtonHint(BASE_VIEW) = "Главный вид отображения Гайки"
			iViewButt.ButtonTips(LEFT_VIEW) = "Вид сбоку"
			iViewButt.ButtonTips(TOP_VIEW) = "Вид сверху"
			iViewButt.ButtonTips(SEC_VIEW) = "Вид\разрез"
			
			' Кнопки исполнений
			iPerfButt = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlMultiButton)
			iPerfButt.Id = PERFORMANCE_ID
			iPerfButt.name = "&Исполнение"
			iPerfButt.ButtonsType = Kompas6Constants.ButtonTypeEnum.ksRadioButton
			iPerfButt.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameVerticalVisible
      iPerfButt.ResModule = System.Reflection.Assembly.GetExecutingAssembly().Location()
			iPerfButt.Hint = "Выбор исполнения"
			iPerfButt.Tips = "Исполнение"
			
			If GetFullName("G_i1.bmp", fullPath) Then
				iPerfButt.AddButton(PERF1_VIEW, fullPath) ' Исполнение 1
			Else
				iPerfButt.AddButton(PERF1_VIEW, PERF1_VIEW) ' Исполнение 1
			End If
			
			If GetFullName("G_i2.bmp", fullPath) Then
				iPerfButt.AddButton(PERF2_VIEW, fullPath) ' Исполнение 2
			Else
				iPerfButt.AddButton(PERF2_VIEW, PERF2_VIEW) ' Исполнение 2
			End If
			
			If tmp.perform Then ' выделим исполнение
				iPerfButt.ButtonChecked(PERF2_VIEW) = True ' исполнение 2
			Else
				iPerfButt.ButtonChecked(PERF1_VIEW) = True ' исполнение 1
			End If
			
			iPerfButt.ButtonTips(PERF1_VIEW) = "Исполнение 1"
			iPerfButt.ButtonTips(PERF2_VIEW) = "Исполнение 2"
			
			' Кнопки упрощений
			iSimpButt = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlMultiButton)
			iSimpButt.Id = SIMPLES_ID
			iSimpButt.name = "&Упрощения"
			iSimpButt.ButtonsType = Kompas6Constants.ButtonTypeEnum.ksCheckButton
			iSimpButt.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameVerticalVisible
      iSimpButt.ResModule = System.Reflection.Assembly.GetExecutingAssembly().Location()
			iSimpButt.Hint = "Упрощения отображения гайки"
			iSimpButt.Tips = "Упрощения отображения"
			
			If GetFullName("G_simple.bmp", fullPath) Then
				iSimpButt.AddButton(SIMPLE_VIEW, fullPath) ' Упрошено
			Else
				iSimpButt.AddButton(SIMPLE_VIEW, SIMPLE_VIEW) ' Упрошено
			End If
			
			If GetFullName("G_osx_on.bmp", fullPath) Then
				iSimpButt.AddButton(DRAW_AXIS, fullPath) ' Рисовать ось
			Else
				iSimpButt.AddButton(DRAW_AXIS, DRAW_AXIS) ' Рисовать ось
			End If
			
			If tmp.simple Then
				iSimpButt.ButtonChecked(SIMPLE_VIEW) = True ' Упрошено
			End If
			
			If tmp.axis_off = 0 Then
				iSimpButt.ButtonChecked(DRAW_AXIS) = True ' Рисовать ось
			End If
			
			iSimpButt.ButtonTips(SIMPLE_VIEW) = "Упрошено"
			iSimpButt.ButtonTips(DRAW_AXIS) = "Рисовать ось"
			
			' Разделитель
			sep = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlSeparator)
			sep.SeparatorType = Kompas6Constants.SeparatorTypeEnum.ksSeparatorDownName
			'UPGRADE_NOTE: Object sep may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			sep = Nothing
			
			' Кнопки доп. параметров
			iAddButt = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlMultiButton)
			iAddButt.Id = ADD_PARAM_ID
			iAddButt.name = "Дополнительные па&раметры"
			iAddButt.ButtonsType = Kompas6Constants.ButtonTypeEnum.ksCheckButton
			iAddButt.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameVerticalVisible
      iAddButt.ResModule = System.Reflection.Assembly.GetExecutingAssembly().Location()
			iAddButt.Hint = "Дополнительные параметры"
			iAddButt.Tips = "Дополнительные параметры"
			
			If GetFullName("G_step.bmp", fullPath) Then
				iAddButt.AddButton(ADDSTEP_BUTT, fullPath) ' Мелкий шаг
			Else
				iAddButt.AddButton(ADDSTEP_BUTT, ADDSTEP_BUTT) ' Мелкий шаг
			End If
			
			If GetFullName("G_key.bmp", fullPath) Then
				iAddButt.AddButton(KEY_BUTT, fullPath) ' Доп. размер под ключ
			Else
				iAddButt.AddButton(KEY_BUTT, KEY_BUTT) ' Доп. размер под ключ
			End If
			
			If tmp.pitch Then
				iAddButt.ButtonChecked(ADDSTEP_BUTT) = True
			End If
			
			If tmp.key_s Then
				iAddButt.ButtonChecked(KEY_BUTT) = True
			End If
			
			iAddButt.ButtonTips(ADDSTEP_BUTT) = "Мелкий шаг"
			iAddButt.ButtonTips(KEY_BUTT) = "Дополнительный размер под ключ"
			
			' Чекбокс объекта сп
			iSpcCheck = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlCheckBox)
			iSpcCheck.Id = SPC_CHECK_ID
			iSpcCheck.name = "&Создать объект спецификации"
			iSpcCheck.Value = par.flagAttr
			iSpcCheck.Hint = "Создать объект спецификации"
			iSpcCheck.Tips = "Создать объект спецификации"
			
			iUserCtrl = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlUser)
			iUserCtrl.SetOCXControl("HatchControl1.HatchControl")
			iUserCtrl.Id = 10011
			iUserCtrl.name = "&Тест OCX"
			iUserCtrl.Width = 200
			iUserCtrl.HEIGHT = 200
			
			' Разделитель
			sep = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlSeparator)
			sep.name = "Параметры штриховки"
			sep.SeparatorType = Kompas6Constants.SeparatorTypeEnum.ksSeparatorDownName
			'UPGRADE_NOTE: Object sep may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			sep = Nothing
			
			' угол штриховки
			iAngleEdit = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlEditReal)
			iAngleEdit.Id = ANGLE_HATCH_ID
			iAngleEdit.name = "У&гол, гр"
			iAngleEdit.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameAlwaysVisible
			iAngleEdit.Width = 7
			iAngleEdit.Value = tmp.hatchAng
			iAngleEdit.Enable = par.drawType = ID_VIDSEC
			iAngleEdit.Hint = "Угол штриховки"
			iAngleEdit.Tips = "Угол"
			
			' шаг штриховки
			iStepEdit = iCtrls.Add(Kompas6Constants.ControlTypeEnum.ksControlEditReal)
			iStepEdit.Id = STEP_HATCH_ID
			iStepEdit.name = "&Шаг, мм"
			iStepEdit.NameVisibility = Kompas6Constants.PropertyControlNameVisibility.ksNameAlwaysVisible
			iStepEdit.Width = 7
			iStepEdit.Value = tmp.hatchStep
			iStepEdit.Enable = par.drawType = ID_VIDSEC
			iStepEdit.Hint = "Шаг штриховки"
			iStepEdit.Tips = "Шаг"
			
			'Const PARAMS_ID = 10009      ' список параметров
			'Const VIEW_BOX_ID = 10010    ' окно просмотра
			
			'    Set hatchPar = CreateObject("HatchControl1.HatchControl")
			'    hatchPar.AngleEditValue = "10"
			
			MacroElementParam = True
			
			'UPGRADE_NOTE: Object iCtrls may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iCtrls = Nothing
			'UPGRADE_NOTE: Object iTab may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iTab = Nothing
			'UPGRADE_NOTE: Object iTabs may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iTabs = Nothing
		End If
		
	End Function
	
	' отрисовка гайки
	Sub gayka_k(ByVal ls As Double, ByVal l As Double, ByVal d1 As Double, ByVal s As Double, ByVal d As Double, ByVal l1 As Double, ByVal H As Double, ByVal j As Short, ByVal j1 As Short, ByVal d2 As Double, ByVal j2 As Short)
		Dim math As Object ' ksMathematic2D
		math = iKompasObject.GetMathematic2D
		Dim X(9) As Double
		Dim Y(9) As Double
		Dim c As Double
		Dim h1 As Double
		Dim rb As Double
		Dim xc2 As Double
		Dim yc2 As Double
		Dim xcbl As Double
		Dim ycbl As Double
		Dim xcbp As Double
		Dim ycbp As Double
		Dim ycml As Double
		If Not math Is Nothing Then :  :  :  :  :  : ' Координаты контура рез_части
			
			'j1=1 -   контровочное отверстие  j1=0 - контров. отв. нет
			'j2=1 исполнение 1   j2=2    исполнение 2
			
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksCosD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			d = s / math.ksCosD(30)
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksTanD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			c = (d - d2) / 2 * math.ksTanD(30)
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksSinD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			h1 = d * 0.5 * math.ksSinD(30)
			rb = (h1 * h1 + c * c) / 2 / c
			
			X(1) = ls
			Y(1) = 0
			If j2 = 1 Then
				X(2) = ls : Y(2) = j * (d2 * 0.5)
				X(3) = ls + c : Y(3) = j * (d * 0.5)
				X(7) = ls + c : Y(7) = j * h1
			Else
				X(2) = ls : Y(2) = j * (d * 0.5)
				X(7) = ls : Y(7) = j * h1
			End If
			
			X(4) = ls + H - c : Y(4) = j * (d * 0.5)
			X(5) = ls + H : Y(5) = j * (d2 * 0.5)
			X(6) = ls + H : Y(6) = 0
			
			X(8) = ls + H - c : Y(8) = j * h1
			xc2 = ls + l : yc2 = j * (d * 0.5 - l1)
			
			xcbl = ls + rb : ycbl = 0
			xcbp = ls + H - rb : ycbp = 0
			ycml = j * ((d * 0.5 - h1) / 2 + h1)
			
			If j2 = 1 Then
				iDocument2D.ksLineSeg(X(1), Y(1), X(2), Y(2), 1)
				iDocument2D.ksLineSeg(X(2), Y(2), X(3), Y(3), 1)
				iDocument2D.ksLineSeg(X(3), Y(3), X(4), Y(4), 1)
				iDocument2D.ksLineSeg(X(4), Y(4), X(5), Y(5), 1)
				iDocument2D.ksLineSeg(X(5), Y(5), X(6), Y(6), 1)
				iDocument2D.ksLineSeg(X(7), Y(7), X(8), Y(8), 1)
				iDocument2D.ksArcByPoint(xcbl, ycbl, rb, X(1), Y(1), X(7), Y(7), -j, 1)
				iDocument2D.ksArcByPoint(xcbp, ycbp, rb, X(6), Y(6), X(8), Y(8), j, 1)
				iDocument2D.ksArcBy3Points(ls + c * 0.5, (d * 0.5 - (d - d2) / 4) * j, ls, ycml, X(7), Y(7), 1)
				iDocument2D.ksArcBy3Points(ls + H - c * 0.5, (d * 0.5 - (d - d2) / 4) * j, ls + H, ycml, X(8), Y(8), 1)
			Else
				iDocument2D.ksLineSeg(X(1), Y(1), X(2), Y(2), 1)
				iDocument2D.ksLineSeg(X(2), Y(2), X(4), Y(4), 1)
				iDocument2D.ksLineSeg(X(4), Y(4), X(5), Y(5), 1)
				iDocument2D.ksLineSeg(X(5), Y(5), X(6), Y(6), 1)
				iDocument2D.ksLineSeg(X(7), Y(7), X(8), Y(8), 1)
				iDocument2D.ksArcByPoint(xcbp, ycbp, rb, X(6), Y(6), X(8), Y(8), j, 1)
				iDocument2D.ksArcBy3Points(ls + H - c * 0.5, (d * 0.5 - (d - d2) / 4) * j, ls + H, ycml, X(8), Y(8), 1)
				
			End If
			
			If j1 = 1 Then
				iDocument2D.ksCircle(xc2, yc2, d1 * 0.5, 1)
				iDocument2D.ksLineSeg(xc2 - 2, yc2, xc2 + 2, yc2, 2)
				iDocument2D.ksLineSeg(xc2, yc2 - 2, xc2, yc2 + 2, 2)
			End If
		End If
		
	End Sub
	
	' отрисовка гайки
	Sub gayka_k_side(ByVal ls As Double, ByVal s As Double, ByVal d As Double, ByVal d2 As Double, ByVal H As Double, ByVal j As Short, ByVal j2 As Short)
		Dim math As Object ' ksMathematic2D
		math = iKompasObject.GetMathematic2D
		Dim X As Double
		Dim Y As Double
		Dim x2 As Double
		Dim y2 As Double
		Dim c As Short
		If Not math Is Nothing Then :  : ' j2 = 1 исполнение 1   j2 = 2    упрощенное
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksTanD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			c = (d - d2) / 2 * math.ksTanD(30)
			Y = j * s * 0.5
			If j2 = 1 Then
				X = ls + c
				iDocument2D.ksLineSeg(ls, 0, ls, j * d2 * 0.5, 1)
				iDocument2D.ksLineSeg(ls, j * d2 * 0.5, X, Y, 1)
				iDocument2D.ksArcBy3Points(ls + c, j * (s * 0.5), ls, s * 0.25 * j, ls + c, 0, 1)
			Else
				X = ls
				iDocument2D.ksLineSeg(X, 0, X, Y, 1)
			End If
			
			If j2 = 3 Then
				x2 = ls + H
				y2 = Y
			Else
				x2 = ls + H - c
				y2 = j * d2 * 0.5
			End If
			
			iDocument2D.ksLineSeg(X, Y, x2, Y, 1)
			If j2 <> 3 Then
				iDocument2D.ksLineSeg(x2, Y, ls + H, y2, 1)
				iDocument2D.ksArcBy3Points(ls + H - c, j * (s * 0.5), ls + H, s * 0.25 * j, ls + H - c, 0, 1)
			End If
			iDocument2D.ksLineSeg(ls + H, y2, ls + H, 0, 1)
			If j > 0 Then
				iDocument2D.ksLineSeg(X, 0, x2, 0, 1)
			End If
		End If
	End Sub
	
	' отрисовка гайки
	Sub gayka_k_y(ByRef ls As Double, ByRef j As Short)
    'Dim s As Object
		Dim math As Object ' ksMathematic2D
		math = iKompasObject.GetMathematic2D
		Dim h1 As Double
		Dim p1 As Double
		Dim p2 As Double
		If Not math Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksCosD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			tmp.d = tmp.s / math.ksCosD(30)
			
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksSinD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			h1 = tmp.d * 0.5 * math.ksSinD(30) : p1 = j * tmp.d * 0.5
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      p2 = ls + tmp.H
			iDocument2D.ksLineSeg(ls, 0, ls, p1, 1)
			iDocument2D.ksLineSeg(ls, p1, p2, p1, 1)
			iDocument2D.ksLineSeg(p2, p1, p2, 0, 1)
			iDocument2D.ksLineSeg(ls, j * h1, p2, j * h1, 1)
		End If
	End Sub
	
	' отрисовка гайки
	Sub gayka_p_k(ByRef j As Short)
		Dim math As Object ' ksMathematic2D
		math = iKompasObject.GetMathematic2D
		Dim c1 As Double
		Dim c2 As Double
		Dim X As Double
		Dim x1 As Double
		Dim x2 As Double
		Dim x3 As Double
		Dim y2 As Double
		Dim y3 As Double
		Dim c As Double
		Dim Y As Double
		Dim dd As Double
		If Not math Is Nothing Then : c1 = 0
			c2 = 0 :  :  :  : X = 0 : 'UPGRADE_WARNING: Couldn't resolve default property of object math.ksTanD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			c = (tmp.d - tmp.d2) / 2 * math.ksTanD(30)
			If tmp.perform = 0 And tmp.simple = 0 Then
				Y = tmp.d2 * 0.5 * j
			Else
				Y = tmp.d * 0.5 * j
			End If
			
			iDocument2D.ksLineSeg(0, 0, 0, Y, 1)
			
			If tmp.perform = 0 And tmp.simple = 0 Then
				X = c
				iDocument2D.ksLineSeg(0, Y, X, j * (tmp.d * 0.5), 1)
			End If
			
			dd = tmp.dr - 2 * MODSTEP_REAL * tmp.p
			
			If tmp.simple = 0 Then
				x3 = tmp.H - c
				y3 = j * tmp.d2 * 0.5
				y2 = j * tmp.da * 0.5
			Else
				x3 = tmp.H
				y3 = j * tmp.d * 0.5
				y2 = j * dd * 0.5
			End If
			
			iDocument2D.ksLineSeg(X, j * tmp.d * 0.5, x3, j * tmp.d * 0.5, 1)
			If tmp.simple = 0 Then
				iDocument2D.ksLineSeg(x3, j * tmp.d * 0.5, tmp.H, y3, 1)
			End If
			
			iDocument2D.ksLineSeg(tmp.H, y3, tmp.H, 0, 1)
			
			x1 = tmp.H
			x2 = x1
			If tmp.simple = 0 Then
				c1 = (tmp.da - dd) * 0.5
				c2 = (tmp.da - tmp.dr) * 0.5
				If tmp.perform = 0 Then
					x2 = x2 - c2
				End If
			End If
			
			If tmp.perform = 0 And tmp.simple = 0 Then
				x1 = x1 - c1
				iDocument2D.ksLineSeg(tmp.H, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1)
				iDocument2D.ksLineSeg(x1, j * dd * 0.5, x1, 0, 1)
			End If
			
			iDocument2D.ksLineSeg(x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1)
			
			If tmp.simple = 0 Then
				iDocument2D.ksLineSeg(c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1)
				iDocument2D.ksLineSeg(c1, j * dd * 0.5, c1, 0, 1)
			End If
			
			iDocument2D.ksHatch(0, tmp.hatchAng, tmp.hatchStep, 0, 0, 0)
			iDocument2D.ksLineSeg(0, y2, 0, Y, 1)
			If tmp.perform = 0 And tmp.simple = 0 Then
				iDocument2D.ksLineSeg(0, Y, X, j * (tmp.d * 0.5), 1)
				iDocument2D.ksLineSeg(tmp.H, y3, tmp.H, j * tmp.da * 0.5, 1)
				iDocument2D.ksLineSeg(tmp.H, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1)
			Else
				iDocument2D.ksLineSeg(tmp.H, y3, tmp.H, j * dd * 0.5, 1)
			End If
			
			iDocument2D.ksLineSeg(X, j * (tmp.d * 0.5), x3, j * tmp.d * 0.5, 1)
			If tmp.simple = 0 Then
				iDocument2D.ksLineSeg(x3, j * tmp.d * 0.5, tmp.H, y3, 1)
				iDocument2D.ksLineSeg(c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1)
			End If
			
			iDocument2D.ksLineSeg(x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1)
			
			iDocument2D.ksEndObj()
			
			iDocument2D.ksLineSeg(c2, j * 0.5 * tmp.dr, x2, j * 0.5 * tmp.dr, 2)
		End If
	End Sub
	
	' отрисовка гайки
	Sub gayka_sverhu()
		Dim h1 As Object
		Dim dd As Object
		Dim d As Object
		Dim s As Object
		Dim math As Object ' ksMathematic2D
		math = iKompasObject.GetMathematic2D
		Dim rad As Double
		Dim x1 As Double
		Dim y1 As Double
		If Not math Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			s = tmp.s * 0.5
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksCosD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			d = s / math.ksCosD(30)
			'UPGRADE_WARNING: Couldn't resolve default property of object dd. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			dd = tmp.dr - 2 * MODSTEP_REAL * tmp.p
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksSinD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			h1 = d * math.ksSinD(30)
			
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(-s, h1, 0, d, 1)
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(0, d, s, h1, 1)
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(s, h1, s, -h1, 1)
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(s, -h1, 0, -d, 1)
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(0, -d, -s, -h1, 1)
			'UPGRADE_WARNING: Couldn't resolve default property of object h1. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksLineSeg(-s, -h1, -s, h1, 1)
			
			If tmp.simple = 0 Then
				iDocument2D.ksCircle(0, 0, tmp.d2 * 0.5, 1)
			End If
			
			'UPGRADE_WARNING: Couldn't resolve default property of object dd. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			iDocument2D.ksCircle(0, 0, dd * 0.5, 1) :  : rad = tmp.dr * 0.5
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksSinD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			x1 = rad * math.ksSinD(15)
			'UPGRADE_WARNING: Couldn't resolve default property of object math.ksCosD. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			y1 = rad * math.ksCosD(15)
			iDocument2D.ksArcByPoint(0, 0, rad, x1, y1, y1, -x1, 1, 2)
			
			If tmp.axis_off = 0 Then
				'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				If d >= 6 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksLineSeg(-3 - s, 0, s + 3, 0, 3)
					'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksLineSeg(0, -3 - d, 0, 3 + d, 3)
				Else
					'UPGRADE_WARNING: Couldn't resolve default property of object s. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksLineSeg(-1 - s, 0, s + 1, 0, 3)
					'UPGRADE_WARNING: Couldn't resolve default property of object d. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iDocument2D.ksLineSeg(0, -1 - d, 0, 1 + d, 3)
				End If
			End If
			
		End If
	End Sub
	
	'----------------------------------------------------------------------------------------------
	' отрисовать позиционную линию выноски
	' уже проверено , что объект спецификации есть
	' Функцию нужно запускать вне Cursor и Placement
	'----------------------------------------------------------------------------------------------
	Sub DrawPosLeader(ByRef spcObj As Integer, ByVal iSpc As Object)
		Dim posLeater As Object
		Dim info As Object ' ksRequestInfo
		info = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
		Dim posLeader As Integer
		
		Dim flag As Boolean
		Dim x1 As Double
		Dim y1 As Double
    'Dim prompt As String
		Dim j1 As Short
    'Dim menu As String ' Создать новую линию выноски
		If Not info Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object info.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			info.init()
			flag = False
			posLeader = 0
			Do 
				'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				info.commandsString = "!Подключить_существующую !Создать_новую_линию_выноски"
				'UPGRADE_WARNING: Couldn't resolve default property of object info.prompt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				info.prompt = "Укажите линию выноски"
				j1 = iDocument2D.ksCursor(info, x1, y1, Nothing)
				
				Select Case j1
					Case 2
						posLeader = iDocument2D.ksCreateViewObject(POSLEADER_OBJ)
						flag = False
					Case 1 ' Подключить существующую
						'UPGRADE_WARNING: Couldn't resolve default property of object info.commandsString. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						info.commandsString = ""
						If iDocument2D.ksCursor(info, x1, y1, Nothing) Then
							posLeader = iDocument2D.ksFindObj(x1, y1, 100) ' величина стороны окошка-ловушки с центром x,y
							If posLeader = 0 And iDocument2D.ksGetObjParam(posLeader, Nothing, 0) = POSLEADER_OBJ Then
                iKompasObject.ksError("Ошибка! Объект не позиционная линия выноски!")
								posLeader = 0
								flag = True
							Else
								flag = False
							End If
						Else
							flag = False
						End If
					Case -1
						'UPGRADE_WARNING: Couldn't resolve default property of object posLeater. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						posLeater = iDocument2D.ksFindObj(x1, y1, 100) ' величина стороны окошка-ловушки с центром x,y
						'UPGRADE_WARNING: Couldn't resolve default property of object posLeater. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						If Not posLeader And Not iDocument2D.ksGetObjParam(posLeater, Nothing, 0) = POSLEADER_OBJ Then
							iKompasObject.ksError("Ошибка! Объект не позиционная линия выноски!")
							posLeader = 0
							flag = True
						Else
							flag = False
						End If
				End Select
			Loop While flag
			
			' линия выноски есть, подключим ее к объекту спецификации
			If posLeader > 0 Then
				' ввойдем в режим редактирования объекта спецификации
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				If iSpc.ksSpcObjectEdit(spcObj) Then
					' подключим линию выноски
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcIncludeReference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcIncludeReference(posLeader, True)
					' закроем объект спецификации
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEnd. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcObjectEnd()
				End If
			End If
		End If
	End Sub
	
	Function IsSpcObjCreate() As Boolean
		IsSpcObjCreate = True
	End Function
	
	' объект спецификации
	Function DrawSpcObj(ByRef geom As Integer) As Boolean
		Dim i As Object
		Dim iSpc As Object ' ksSpecification
		iSpc = iDocument2D.GetSpecification
		
    '		Dim count As Short
		If Not iSpc Is Nothing And IsSpcObjCreate Then
			If iKompasObject.ksReturnResult = Kompas6Constants.ErrorType.etError10 Then '  10  "Ошибка! Вырожденный объект"
				iKompasObject.ksResultNULL()
				DrawSpcObj = False
				Exit Function
			End If
			
			spcObj(0) = EditSpcObj(spcObj(0), geom)
			If par.flagAttr = 0 And spcObj(0) > 0 Then
				For i = 0 To countObj - 1
					'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					If spcObj(i) Then
						' ввойдем в режим редактирования объекта спецификации
						'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						If iSpc.ksSpcObjectEdit(spcObj(i)) Then
							' очистим геометрию, чтобы не удалялась в месте с объектом
							'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcIncludeReference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
							iSpc.ksSpcIncludeReference(0, 0)
							' закроем объект спецификации
							'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEnd. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
							iSpc.ksSpcObjectEnd()
						End If
						'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						iDocument2D.ksDeleteObj(spcObj(i))
						'UPGRADE_WARNING: Couldn't resolve default property of object i. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
						spcObj(i) = 0
					End If
				Next i
			End If
		End If
		
		If spcObj(0) > 0 Then
			DrawSpcObj = True
		Else
			DrawSpcObj = False
		End If
	End Function
	
	' создание или редактирование объекта спецификации
	Function EditSpcObj(ByRef spcObj As Integer, ByVal geom As Integer) As Integer
		Dim iSpc As Object ' ksSpecification
		iSpc = iDocument2D.GetSpecification()
		
		Dim bufPar As Object ' ksUserParam
		bufPar = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
		
		Dim item As Object ' ksLtVariant
		item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
		
		Dim arr As Object ' ksDynamicArray
		arr = iKompasObject.GetDynamicArray(LTVARIANT_ARR)
		
		Dim flMode As Integer
		Dim create As Boolean
		Dim massa As Single
		If Not iSpc Is Nothing And Not bufPar Is Nothing And Not item Is Nothing And Not arr Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object bufPar.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			bufPar.init()
			'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			item.init()
			'UPGRADE_WARNING: Couldn't resolve default property of object bufPar.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			bufPar.SetUserArray(arr)
			If flagMode = 0 And par.flagAttr = 0 Then
				EditSpcObj = 0
				Exit Function
			End If
			
			If flagMode > 0 Then
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksGetSpcObjForGeomWithLimit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				spcObj = iSpc.ksGetSpcObjForGeomWithLimit("", 0, geom, 0, 1, STANDART_SECTION, 297327484710#)
				If par.flagAttr = 0 Then
					EditSpcObj = spcObj
					Exit Function
				End If
				
				If spcObj > 0 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEdit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					If iSpc.ksSpcObjectEdit(spcObj) = 0 Then
						spcObj = 0
					End If
				End If
			End If
			
			flMode = spcObj
			If flMode = 0 Then
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectCreate. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				create = CBool(iSpc.ksSpcObjectCreate("", 0, STANDART_SECTION, 0, 297327484710#, 0))
			End If
			
			' создаем объект спецификации для умолчательногостиля СП
			If flMode > 0 Or create Then
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				' исполнение
				If tmp.perform = 1 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 2, 0)
				Else
					'UPGRADE_WARNING: Couldn't resolve default property of object item.uIntVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					item.uIntVal = 2
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksSetArrayItem(0, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 2, 1)
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcChangeValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcChangeValue(SPC_NAME, 2, bufPar, UINT_ATTR_TYPE)
				End If
				
				' изменим диаметр
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.dr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(0, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcChangeValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				iSpc.ksSpcChangeValue(SPC_NAME, 4, bufPar, FLOAT_ATTR_TYPE)
				
				' отследим мелкий шаг
				If tmp.pitch = 0 Then ' выключить шаг и его разделитель
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 5, 0)
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 6, 0) ' щаг
				Else
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 5, 1)
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 6, 1) ' щаг
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					item.floatVal = tmp.p
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksSetArrayItem(0, item)
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcChangeValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcChangeValue(SPC_NAME, 6, bufPar, FLOAT_ATTR_TYPE)
				End If
				
				' выключим поле допуска
				If flMode = 0 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 7, 0)
					' выключим класс прочности
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 8, 0)
					' выключим материал
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 9, 0)
					' выключим покрытие
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcVisible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcVisible(SPC_NAME, 10, 0)
				End If
				
				' изменим ГОСТ
				'UPGRADE_WARNING: Couldn't resolve default property of object item.uIntVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.uIntVal = tmp.gost
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksSetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksSetArrayItem(0, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcChangeValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				iSpc.ksSpcChangeValue(SPC_NAME, 12, bufPar, UINT_ATTR_TYPE)
				Select Case tmp.indexMassa
					Case 0 : massa = tmp.massa
					Case 1 : massa = 0.356 * tmp.massa
					Case 2 : massa = 1.08 * tmp.massa
				End Select
				
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcMassa. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				iSpc.ksSpcMassa(CStr(massa)) ' масса детали
				
				' подключим геометрию
				If geom > 0 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcIncludeReference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					iSpc.ksSpcIncludeReference(geom, SPC_CLEAR_GEOM)
				End If
				
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpc.ksSpcObjectEnd. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				EditSpcObj = iSpc.ksSpcObjectEnd
				Exit Function
			End If
		End If
		
		EditSpcObj = 0
	End Function
	
	' инициализация параметров пользователя
	Sub InitUserParamTmp()
		Dim item As Object
		Dim arr As Object ' ksDynamicArray ' ksLtVariant
		If Not paramTmp Is Nothing Then
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			arr = iKompasObject.GetDynamicArray(LTVARIANT_ARR)
			If (Not item Is Nothing) And (Not arr Is Nothing) Then
				'UPGRADE_WARNING: Couldn't resolve default property of object paramTmp.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				paramTmp.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object paramTmp.SetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				paramTmp.SetUserArray(arr)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.dr ' 0 - dr
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.p ' 1 - p1
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.p ' 2 - p2
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.s ' 3 - s
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d ' 4 - D
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.da ' 5 - da
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.H ' 6 - h
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d2 ' 7 - d2
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.massa ' 8 - m
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.s ' 9 - s1
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.d ' 10 - D1
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.floatVal = tmp.massa ' 11 - m1
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksAddArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksAddArrayItem(-1, item)
			End If
		End If
	End Sub
	
	Sub GetUserParamTmp()
		Dim item As Object
		Dim item1 As Object
		Dim arr As Object ' ksDynamicArray ' ksLtVariant
		If Not paramTmp Is Nothing Then
			item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			item1 = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
			'UPGRADE_WARNING: Couldn't resolve default property of object paramTmp.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			arr = paramTmp.GetUserArray()
			'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayCount. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			If (Not item Is Nothing) And (Not item1 Is Nothing) And (Not arr Is Nothing) And arr.ksGetArrayCount() >= 12 Then
				'UPGRADE_WARNING: Couldn't resolve default property of object item.init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				item.init()
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(0, item) ' dr
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.dr = item.floatVal
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(5, item) ' da
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.da = item.floatVal
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(6, item) ' h
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.H = item.floatVal
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(7, item) ' d2
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.d2 = item.floatVal
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(1, item) ' p1
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(2, item1) ' p2
				If tmp.pitch = 1 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.p = item1.floatVal
				Else
					'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.p = item.floatVal
				End If
				
				'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				If System.Math.Abs(item1.floatVal - item.floatVal) < 0.001 Then
					tmp.pitch_off = 1
				Else
					tmp.pitch_off = 0
				End If
				
				'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				arr.ksGetArrayItem(9, item1) ' s1
				'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				If tmp.key_s_on = 1 And System.Math.Abs(item1.floatVal) > 0.001 Then
					tmp.key_s_gray = 1
				Else
					tmp.key_s_gray = 0
					tmp.key_s = 0
				End If
				
				If tmp.key_s_on = 1 And tmp.key_s = 1 Then
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.s = item1.floatVal ' размер под ключ
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(10, item1) ' D1
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.d = item1.floatVal ' диаметр описанной окружности
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(11, item1) ' m1
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.massa = item1.floatVal
				Else
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(3, item1) ' s
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.s = item1.floatVal ' размер под ключ
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(4, item1) ' D
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.d = item1.floatVal ' диаметр описанной окружности
					'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					arr.ksGetArrayItem(8, item1) ' m
					'UPGRADE_WARNING: Couldn't resolve default property of object item1.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					tmp.massa = item1.floatVal
				End If
			End If
		End If
	End Sub
	
	' подключиться к базе данных
	Function ConnectDB_(ByVal bd As Integer, ByVal name As String) As Boolean
		Dim buf As String = ""
		If GetFullName(name, buf) Then
			'UPGRADE_WARNING: Couldn't resolve default property of object data.ksConnectDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ConnectDB_ = data.ksConnectDB(base.bg, buf)
		Else
			'UPGRADE_WARNING: Couldn't resolve default property of object data.ksConnectDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ConnectDB_ = data.ksConnectDB(base.bg, name)
		End If
	End Function
	
	' получить полное имя файла
	Function GetFullName(ByRef name As String, ByRef buf As String) As Boolean
		Dim path As String
		path = iKompasObject.ksSystemPath(sptLIBS_FILES)
		path = path & "\Load\" & name
		Dim fso As New Scripting.FileSystemObject
		If fso.FileExists(path) Then
			GetFullName = True
			buf = path
		Else
			path = My.Application.Info.DirectoryPath
			path = Left(path, InStrRev(path, "\"))
			path = path & "\Load\" & name
			If fso.FileExists(path) Then
				GetFullName = True
				buf = path
			Else
				path = My.Application.Info.DirectoryPath
				path = path & "\" & name
				If fso.FileExists(path) Then
					GetFullName = True
					buf = path
				Else
					GetFullName = False
				End If
			End If
		End If
	End Function
	
	' открыть базу данных
	Function OpenGaykaBase() As Boolean
		InitUserParamTmp()
		OpenGaykaBase = False
		If Not data Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object data.ksCreateDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			base.bg = data.ksCreateDB("TXT_DB") ' TXT_DB
			
			If ConnectDB_(base.bg, "5915.loa") Then ' 5915.loa
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				base.rg = data.ksRelation(base.bg)
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("dr")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksRFloat. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksRFloat("")
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksEndRelation. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				data.ksEndRelation()
				'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDoStatement. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				If data.ksDoStatement(base.bg, base.rg, "") Then ' TXT_ALL
					OpenGaykaBase = True
				End If
			End If
		End If
	End Function
	
	Sub CloseGaykaBase() ' закрыть базу данных
		If base.bg <> 0 Then
			'UPGRADE_WARNING: Couldn't resolve default property of object data.ksDeleteDB. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			data.ksDeleteDB(base.bg)
		End If
	End Sub
	
	'-------------------------------------------------------------------------------
	'  Читать параметры гайки по диаметру
	'  возвращает 1 - успех 0 - не найдено записи , ошибка связи с БД
	' ---
	Function ReadGaykaBase(ByRef d As Single) As Boolean
		Dim s As String
		If d > 0 Then
			s = "dr=" & Str(d) ' dr=%.0f
		Else
			s = "dr=" & Str(tmp.d) ' dr=%.0f
		End If
		
		'UPGRADE_WARNING: Couldn't resolve default property of object data.ksCondition. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		Dim i As Short
		If data.ksCondition(base.bg, base.rg, s) = 1 Then
			'UPGRADE_WARNING: Couldn't resolve default property of object data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			i = data.ksReadRecord(base.bg, base.rg, paramTmp)
			If i > 0 Then
				GetUserParamTmp()
				ReadGaykaBase = True
			End If
		Else
			ReadGaykaBase = False
		End If
	End Function
	
	Public Sub init() ' инициализация параметров структуры гайки
		tmp.gost = 5915
		tmp.hatchAng = 45
		tmp.hatchStep = 2
		tmp.dr = 20
		tmp.p = 2.5
		tmp.ver = 1
		tmp.indexMassa = 0
		tmp.s = 30
		tmp.d = 33
		tmp.da = 21.6
		tmp.H = 16
		tmp.d2 = 27.7
		tmp.Class_Renamed = 2 'класс точности
		tmp.perform = 0
		tmp.axis_off = 0
		tmp.simple = 0
		tmp.massa = 71.44
	End Sub
	
	' инициализация объекта класса
	'UPGRADE_NOTE: Class_Initialize was upgraded to Class_Initialize_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Private Sub Class_Initialize_Renamed()
		Param = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
		paramTmp = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_UserParam)
		data = iKompasObject.DataBaseObject()
		
		refMacr = 0
		flagMode = 0
		countObj = 1
		
		InitUserParam()
		
		If iDocument2D.ksEditMacroMode > 0 And iDocument2D.ksGetMacroParam(0, Param) > 0 Then
			GetUserParam() ' инициализация из макропараметров
			tmp.ver = 1
			tmp.key_s_on = 1
			tmp.koef_mat_on = 1
		Else ' инициализация по умолчанию
			par.drawType = ID_VID
			par.ang = 0
			par.flagAttr = 0
			init() ' инициализация параметров структуры гайки
		End If
	End Sub
	Public Sub New()
		MyBase.New()
		Class_Initialize_Renamed()
	End Sub
	
	
	Private Sub hatchPar_AngleChange() Handles hatchPar.AngleChange
		MsgBox("Изменили угол")
	End Sub
	
	Private Sub hatchPar_StepChange() Handles hatchPar.StepChange
		MsgBox("Изменили шаг")
	End Sub
	
	Private Function iProcParam_ChangeControlValue(ByVal control As KompasAPI7.IPropertyControl) As Boolean
		Dim redrawPhantom As Boolean
		redrawPhantom = False
		
		'UPGRADE_NOTE: val was upgraded to val_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
		Dim val_Renamed As Single
		Select Case control.Id
			Case DIAM_ID ' Комбобокс диаметров резьбы
				'UPGRADE_WARNING: Couldn't resolve default property of object control.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				val_Renamed = control.Value
				tmp.dr = val_Renamed ' Установим диаметр гайке
				ReadGaykaBase(val_Renamed) ' Прочитаем новые параметры из базы
				redrawPhantom = True ' перерисовать фантом
				
			Case SPC_CHECK_ID ' Чекбокс объекта сп
				'UPGRADE_WARNING: Couldn't resolve default property of object iSpcCheck.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				par.flagAttr = iSpcCheck.Value
				
			Case ANGLE_HATCH_ID ' угол штриховки
				'UPGRADE_WARNING: Couldn't resolve default property of object iAngleEdit.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.hatchAng = iAngleEdit.Value
				redrawPhantom = True ' перерисовать фантом
				
			Case STEP_HATCH_ID ' шаг штриховки
				'UPGRADE_WARNING: Couldn't resolve default property of object iStepEdit.Value. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				tmp.hatchStep = iStepEdit.Value
				redrawPhantom = True ' перерисовать фантом
				
				'    Case STR_EDIT_ID
				'      iKompasObject.ksMessage iTestStringEdit.Value
				'
				'    Case STR_LIST_ID
				'      iKompasObject.ksMessage iTestStringList.Value
		End Select
		
		If redrawPhantom Then
			RedrawPhantomProc()
		End If
	End Function
	
	Private Function iProcParam_ControlCommand(ByVal control As KompasAPI7.IPropertyControl, ByVal buttonID As Integer) As Boolean
		Dim redrawPhantom As Boolean
		redrawPhantom = False
		
		Select Case control.Id
			Case VIEWSIDE_ID ' Кнопки отображения
				If buttonID = BASE_VIEW Then ' главный вид
					par.drawType = ID_VID
					iAngleEdit.Enable = False
					iStepEdit.Enable = False
				End If
				
				If buttonID = LEFT_VIEW Then ' вид сбоку
					par.drawType = ID_SIDEVID
					iAngleEdit.Enable = False
					iStepEdit.Enable = False
				End If
				
				If buttonID = TOP_VIEW Then ' вид сверху
					par.drawType = ID_TOPVID
					iAngleEdit.Enable = False
					iStepEdit.Enable = False
				End If
				
				If buttonID = SEC_VIEW Then ' вид \ разрез
					par.drawType = ID_VIDSEC
					iAngleEdit.Enable = True
					iStepEdit.Enable = True
				End If
				redrawPhantom = True ' перерисовать фантом
				
			Case PERFORMANCE_ID ' Кнопки исполнений
				If buttonID = PERF2_VIEW Then ' исполнение 2
					tmp.perform = 1
				Else
					tmp.perform = 0 ' исполнение 1
				End If
				
				redrawPhantom = True ' перерисовать фантом
				
			Case SIMPLES_ID ' Кнопки упрощений
				If buttonID = SIMPLE_VIEW Then ' Упрошено
					tmp.simple = iSimpButt.ButtonChecked(SIMPLE_VIEW)
					redrawPhantom = True ' перерисовать фантом
				End If
				
				If buttonID = DRAW_AXIS Then ' Рисовать ось
					If iSimpButt.ButtonChecked(DRAW_AXIS) Then
						tmp.axis_off = 0
					Else
						tmp.axis_off = 1
					End If
					redrawPhantom = True ' перерисовать фантом
				End If
				
			Case ADD_PARAM_ID ' Кнопки доп. параметров
				If buttonID = ADDSTEP_BUTT Then ' Мелкий шаг
					tmp.pitch = iAddButt.ButtonChecked(ADDSTEP_BUTT)
				End If
				
				If buttonID = KEY_BUTT Then ' Доп. размер под ключ
					tmp.key_s = iAddButt.ButtonChecked(KEY_BUTT)
				End If
				
		End Select
		
		If redrawPhantom Then
			RedrawPhantomProc()
		End If
		
	End Function
	
	Private Sub RedrawPhantomProc()
		Dim pt1 As Kompas6API5.ksType1
		pt1 = phantom.GetPhantomParam
		Dim gr As Integer
		GetGroup(gr) ' новая геометрия
		pt1.gr = gr
		
		iDocument2D.ksChangeObjectInLibRequest(Nothing, phantom)
	End Sub
	
	Private Function iUserCtrl_CreateOCX(ByVal iOcx As Object) As Boolean
		hatchPar = iOcx
	End Function
	
	Private Function iUserCtrl_DestroyOCX() As Boolean
		'UPGRADE_NOTE: Object hatchPar may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		hatchPar = Nothing
	End Function
End Class