# DrawingObjectTypeEnum - Типы графических объектов

[API интерфейсов. Версия 7](applicate.html) > [Константы API версии 7 ](cj1473974.html) |  Scroll [ [ [ ](documenttypeenum.html "К следующему разделу")](cj1473974.html "На уровень выше")](documentcloseoptions.html "К предыдущему разделу")  
---|---  
  
В API5 соответствует [Типам объектов и интерфейсов...](objtypes.html).

Идентификатор объекта |  | Название объекта | Интерфейс параметров  
---|---|---|---  
ksUnknown | -1 | Неизвестный объект |   
ksAllObj | 0 | Все объекты |   
ksDrLineSeg | 1 | Отрезок | [ILineSegment](ilinesegment.html)  
ksDrCircle | 2 | Окружность | [ICircle](icircle.html)  
ksDrArc | 3 | Дуга | [IArc](iarc.html)  
ksDrDrawText | 4 | Текст на чертеже | [IDrawingText](idrawingtext.html)  
ksDrPoint | 5 | Точка | [IPoint](ipoint.html)  
ksDrHatch | 7 | Штриховка | [IHatch](ihatch.html)  
ksDrBezier | 8 | Bezier сплайн | [IBezier](ibezier.html)  
ksDrLDimension | 9 | Линейный размер | [ILineDimension](ilinedimension.html)  
ksDrADimension | 10 | Угловой размер | [IAngleDimension](iangledimension.html)  
ksDrDDimension | 13 | Диаметральный размер | [IDiametralDimension](idiametraldimension.html)  
ksDrRDimension | 14 | Радиальный размер | [IRadialDimension](iradialdimension.html)  
ksDrRBreakDimension | 15 | Радиальный размер с изломом | [IBreakRadialDimension](ibreakradialdimension.html)  
ksDrRough | 16 | Шероховатость | [IRough](irough.html)  
ksDrBase | 17 | База | [IBase](ibase.html)  
ksDrWPointer | 18 | Стрелка вида | [IViewPointer](iviewpointer.html)  
ksDrCut | 19 | Линия разреза | [ICutLine](icutline.html)  
ksDrLeader | 20 | Простая линия-выноска | [IBaseLeader](ibaseleader.html)  
ksDrPosLeader | 21 | Линия-выноска для обозначения позиции | [IPositionLeader](ipositionleader.html)  
ksDrBrandLeader | 22 | Линия-выноска для обозначения клеймения | [IBrandLeader](ibrandleader.html)  
ksDrMarkerLeader | 23 | Линия-выноска для обозначения маркирования | [IMarkLeader](imarkleader.html)  
ksDrTolerance | 24 | Допуск формы | [ITolerance](itolerance.html)  
ksDrTable | 25 | Таблица | [ITable](itable.html)  
ksDrContour | 26 | Контур | [IContour](icontour.html)  
ksDrMacro | 27 | Нетипизированный макроэлемент | [IMacroObjec](imacroobject.html)  
ksDrLine | 28 | Линия | [ILine](iline.html)  
ksLayer | 29 | Слой | [ILayer](ilayer.html)  
ksDrFragment | 30 | Вставной фрагмент | [ksFragment](ksfragment.html)  
ksDrPolyline | 31 | Полилиния | [IPolyLine](ipolyline.html)  
ksDrEllipse | 32 | Эллипс | [IEllipse](iellipse.html)  
ksDrNurbs | 33 | NURBS сплайн | [INurbs](inurbs.html)  
ksDrEllipseArc | 34 | Дуга эллипса | [IEllipseArc](iellipsearc.html)  
ksDrRectangle | 35 | Прямоугольник | [IRectangle](irectangle.html)  
ksDrRegularPolygon | 36 | Многоугольник | [IRegularPolygon](iregularpolygon.html)  
ksDrEquid | 37 | Эквидистанта | [IEquidistant](iequidistant.html)  
ksDrLBreakDimension | 38 | Линейный размер с обрывом | [IBreakLineDimension](ibreaklinedimension.html)  
ksDrABreakDimension | 39 | Угловой размер с обрывом | [IBreakAngleDimension](ibreakangledimension.html)  
ksDrOrdinateDimension | 40 | Размер высоты | [IHeightDimension](iheightdimension.html)  
ksDrColorFill | 41 | Фоновая заливка цветом | [IColouring](icolouring.html)  
ksDrCentreMarker | 42 | Обозначение центра | [ICentreMarker](icentremarker.html)  
ksDrArcDimension | 43 | Размер длины дуги | [IArcDimension](iarcdimension.html)  
ksDrRaster | 45 | Растровый объект | [IRaster](iraster.html)  
ksDrChangeLeader | 46 | Обозначение изменения | [IChangeLeader](ichangeleader.html)  
ksDrRemoteElement | 47 | Выносной элемент | [IRemoteElement](iremoteelement.html)  
ksDrAxisLine | 48 | Осевая линия | [IAxisLine](iaxisline.html)  
ksDrOLEObject | 49 | Вставка OLE объекта | [IOleDrawingObject](ioledrawingobject.html)  
ksDrUnitNumber | 50 | Номер узла | [IUnitNumber](iunitnumber.html)  
ksDrBrace | 51 | Фигурная скобка | [IBrace](ibrace.html)  
ksDrMarkOnLeader | 52 | Марка/позиционное обозначение с линией-выноской | [IMarkOnLeader](imarkonleader.html)  
ksDrMarkOnLine | 53 | Марка/позиционное обозначение на линии | [IMarkOnLine](imarkonline.html)  
ksDrMarkInsideForm | 54 | Марка/позиционное обозначение без линии-выноски | [IMarkInsideForm](imarkinsideform.html)  
ksDrWaveLine | 55 | Волнистая линия | [IWaveLine](iwaveline.html)  
ksDrStraightAxis | 56 | Прямая ось | [IStraightAxis](istraightaxis.html)  
ksDrBrokenLine | 57 | Линия обрыва с изломами | [IBrokenLine](ibrokenline.html)  
ksDrCircleAxis | 58 | Круговая ось | [ICircleAxis](icircleaxis.html)  
ksDrArcAxis | 59 | Дуговая ось | [IArcAxis](iarcaxis.html)  
ksDrCutUnitMarking | 60 | Обозначение узла в сечении | [ICutUnitMarking](icutunitmarking.html)  
ksDrUnitMarking | 61 | Обозначение узла | [IUnitMarking](iunitmarking.html)  
ksDrMultiTextLeader | 62 | Выносная надпись к многослойным конструкциям | [IMultiTextLeader](imultitextleader.html)  
ksDrExternalView | 63 | Вставка внешнего вида | [IInsertionView](iinsertionview.html)  
ksDrAnnLineSeg | 64 | Аннотационный отрезок | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnCircle | 65 | Аннотационная окружность | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnEllipse | 66 | Аннотационный эллипс | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnArc | 67 | Аннотационная дуга | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnEllipseArc | 68 | Аннотационная дуга эллипса | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnPolyline | 69 | Аннотационная полилиния | [IAnnotativeObject](iannotativeobject.html)  
ksDrAnnPoint | 70 | Аннотационная точка | [IAnnotativeObject](iannotativeobject.html)  
ksDrMultiLine | 72 | Мультилиния | [IMultiline](imultiline.html)  
ksDrBuildingCutLine | 73 | Линия разреза/сечения для СПДС | [ICutLine](icutline.html)  
ksDrAttachedLeader | 74 | Присоединенная линия выноски (не имеет текстов) | [ILeader](ileader.html)  
ksDrConditionCrossing | 75 | Условное пересечение |   
ksReportTable | 76 | Ассоциативная таблица отчета | [IAssociationTable](iassociationtable.html)  
ksEmbodimentsTable | 77 | Таблица иcполнений | [IAssociationTable](iassociationtable.html)  
ksDrSpecialCurve | 78 | Кривая общего вида |   
ksArrayParamTable | 79 | Таблица параметров массива | [IAssociationTable](iassociationtable.html)  
ksDrNurbsByPoints | 80 | NURBS-кривая по точкам |   
ksDrConicCurve | 81 | Коническая кривая |   
ksDrConicCurve4Point | 82 | Коническая кривая по 4 точкам и направлению |   
ksDrConicCurve5Point | 83 | Коническая кривая по 5 точкам |   
ksDrStraightSlot | 87 | Паз |   
ksDrArcSlot | 88 | Паз дуговой |   
ksDrCsPoint | 89 | Точка начала СК |   
ksView | 123 | Вид | [iView](iview.html)  
  
Подразделы:

(отсутствуют)
