# Типы объектов графического документа; соответствие интерфейсов API5 и API7

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Константы системы ](bk1808863.html) |  Scroll [ [ [ ](ksobjectpropertycontroltypeenum.html "К следующему разделу")](bk1808863.html "На уровень выше")](libpathtypes.html "К предыдущему разделу")  
---|---  
  
В таблице представлены типы графических объектов и соответствующие им интерфейсы API5 и API7.

Название объекта | Идентификатор объекта | DrawingObjectTypeEnum | Старый тип | Тип параметров | Структура | Интерфейс API5 | Интерфейс API7  
---|---|---|---|---|---|---|---  
Неизвестный объект | ksUnknown | -1 |  |  |  |  |   
Все объекты | ksAllObj | 0 | ALL_OBJ |  |  |  |   
Отрезок | ksDrLineSeg | 1 | LINESEG_OBJ | ALLPARAM | [LineSegParam](structlinesegparam.html) | [ksLineSegParam](kslinesegparam.html) | [ILineSegment](ilinesegment.html)  
Окружность | ksDrCircle | 2 | CIRCLE_OBJ | ALLPARAM | [CircleParam](kscircleparam.html) | [ksCircleParam](kscircleparam.html) | [ICircle](icircle.html)  
Дуга | ksDrArc | 3 | ARC_OBJ | ALLPARAM | [ArcParam](structarcparam.html) | [ksArcByAngleParam](ksarcbyangleparam.html) | [IArc](iarc.html)  
|  |  |  | POINT_ARC_PARAM | [ArcParam1](structarcparam1.html) | [ksArcByPointParam](ksarcbypointparam.html) | [IArc](iarc.html)  
|  |  |  | ANGLE_ARC_SHEET_PARAM | [ArcParam](structarcparam.html) | [ksArcByAngleParam](ksarcbyangleparam.html) | [IArc](iarc.html)  
|  |  |  | ANGLE_ARC_VIEW_PARAM | [ArcParam](structarcparam.html) | [ksArcByAngleParam](ksarcbyangleparam.html) | [IArc](iarc.html)  
|  |  |  | POINT_ARC_SHEET_PARAM | [ArcParam1](structarcparam1.html) | [ksArcByPointParam](ksarcbypointparam.html) | [IArc](iarc.html)  
|  |  |  | POINT_ARC_VIEW_PARAM | [ArcParam1](structarcparam1.html) | [ksArcByPointParam](ksarcbypointparam.html) | [IArc](iarc.html)  
Текст на чертеже | ksDrDrawText | 4 | TEXT_OBJ | ALLPARAM | [TextParam](kstextparam.html) | [ksTextParam](kstextparam.html) | [IDrawingText](idrawingtext.html) [IText](itext.html)  
|  |  |  | Индекс строки текста (начиная с 0) | [TextLineParam](structtextlineparam.html) | [ksTextLineParam](kstextlineparam.html) | [ITextLine](itextline.html)  
Точка | ksDrPoint | 5 | POINT_OBJ | ALLPARAM | [PointParam](structpointparam.html) | [ksPointParam](kspointparam.html) | [IPoint](ipoint.html)  
Штриховка | ksDrHatch | 7 | HATCH_OBJ | ALLPARAM | [HatchParam](kshatchparam.html) | [ksHatchParam](kshatchparam.html) | [IHatch](ihatch.html) [IHatchParam](ihatch.html)  
|  |  |  | HATCH_PARAM_EX | [HatchParam](kshatchparam.html) | [ksHatchParam](kshatchparam.html) | [Hatch](ihatch.html) [IHatchParam](ihatch.html)  
Кривая Безье, сплайн | ksDrBezier | 8 | BEZIER_OBJ | ALLPARAM | [BezierParam](structbezierparam.html) | [ksBezierParam](ksbezierparam.html) | [IBezier](ibezier.html)  
Линейны |  |  |  | Индекс узл кривой (начиная с 0) | [BezierPointParam](structbezierpointparam.html) | [ksBezierPointParam](ksbezierpointparam.html) | [IBezier::GetPoint](ibezier_getpoint.html)  
Линейный размер | ksDrLDimension | 9 | LDIMENSION_OBJ | ALLPARAM | [LdimParam](structldimparam.html) | [ksLDimParam](ksldimparam.html) | [ILineDimension](ilinedimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [LDimSource](structldimsource.html) | [ksLDimSourceParam](ksldimsourceparam.html) | [ILineDimension](ilinedimension.html)  
|  |  |  | DIM_DRAW_PARAM | [DimDrawing](structdimdrawing.html) | [ksDimDrawingParam](ksdimdrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
угловой размер | ksDrADimension | 10 | ADIMENSION_OBJ | ALLPARAM | [AdimParam](structadimparam.html) | [ksADimParam](ksadimparam.html) | [IArcDimension](iarcdimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [ADimSource](structadimsource.html) | [ksADimSourceParam](ksadimsourceparam.html) | [IArcDimension](iarcdimension.html)  
|  |  |  | DIM_DRAW_PARAM | [DimDrawing](structdimdrawing.html) | [ksDimDrawingParam](ksdimdrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Диаметральный размер | ksDrDDimension | 13 | DDIMENSION_OBJ | ALLPARAM | [RdimParam](structrdimparam.html) | [ksRDimParam](ksrdimparam.html) | [IDiametralDimension](idiametraldimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [RDimSource](structrdimsource.html) | [ksRDimSourceParam](ksrdimsourceparam.html) | [IDiametralDimension](idiametraldimension.html)  
|  |  |  | DIM_DRAW_PARAM | [RDimDrawing](structrdimdrawing.html) | [ksRDimDrawingParam](ksrdimdrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Радиальный размер | ksDrRDimension | 14 | RDIMENSION_OBJ | ALLPARAM | [RdimParam](structrdimparam.html) | [ksRDimParam](ksrdimparam.html) | [IRadialDimension](iradialdimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [RDimSource](structrdimsource.html) | [ksRDimSourceParam](ksrdimsourceparam.html) | [IRadialDimension](iradialdimension.html)  
|  |  |  | DIM_DRAW_PARAM | [RDimDrawing](structrdimdrawing.html) | [ksRDimDrawingParam](ksrdimdrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Радиальный размер с изломом | ksDrRBreakDimension | 15 | RBREAKDIMENSION_OBJ | ALLPARAM | [RbreakDimParam](structrbreakdimparam.html) | [ksRBreakDimParam](ksrbreakdimparam.html) | [IBreakRadialDimension](ibreakradialdimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [RDimSource](structrdimsource.html) | [ksRDimSourceParam](ksrdimsourceparam.html) | [IBreakRadialDimension](ibreakradialdimension.html)  
|  |  |  | DIM_DRAW_PARAM | [RBreakDrawing](structrbreakdrawing.html) | [ksRBreakDrawingParam](ksrbreakdrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Шероховатость | ksDrRough | 16 | ROUGH_OBJ | ALLPARAM | [RoughParam](structroughparam.html) | [ksRoughParam](ksroughparam.html) | [IRough](irough.html)  
База | ksDrBase | 17 | BASE_OBJ | ALLPARAM | [BaseParam](structbaseparam.html) | [ksBaseParam](ksbaseparam.html) | [IBase](ibase.html)  
Стрелка направления взгляда | ksDrWPointer | 18 | WPOINTER_OBJ | ALLPARAM | [ViewPointerParam](structviewpointerparam.html) | [ksViewPointerParam](ksviewpointerparam.html) | [IViewPointer](iviewpointer.html)  
Линия разреза | ksDrCut | 19 | CUT_OBJ | ALLPARAM | [CutLineParam](structcutlineparam.html) | [ksCutLineParam](kscutlineparam.html) | [ICutLine](icutline.html)  
Простая линия выноска | ksDrLeader | 20 | LEADER_OBJ | ALLPARAM | [LeaderParam](structleaderparam.html) | [ksLeaderParam](ksleaderparam.html) | [ILeader](ileader.html)  
Линия выноска для обозначения позиции | ksDrPosLeader | 21 | POSLEADER_OBJ | ALLPARAMа | [PosLeaderParam](posleaderparam.html) | [ksPosLeaderParam](ksposleaderparam.html) | [IPositionLeader](ipositionleader.html)  
Линия выноска для обозначения клеймения | ksDrBrandLeader | 22 | BRANDLEADER_OBJ | ALLPARAM | [BrandLeaderParam](structbrandleaderparam.html) | [ksBrandLeaderParam](ksbrandleaderparam.html) | [IBrandLeader](ibrandleader.html)  
Линия выноска для обозначения маркирования | ksDrMarkerLeader | 23 | MARKERLEADER_OBJ | ALLPARAM | [MarkerLeaderParam](structmarkerleaderparam.html) | [ksMarkerLeaderParam](ksmarkerleaderparam.html) | [IMarkLeader](imarkleader.html)  
Допуск формы | ksDrTolerance | 24 | TOLERANCE_OBJ | ALLPARAM | [ksTolerancePar](structkstolerancepar.html) | [ksToleranceParam](kstoleranceparam.html) | [ITolerance](itolerance.html)  
Таблица | ksDrTable | 25 | TABLE_OBJ | ALLPARAM | нереализовано | нереализовано | I[DrawingTable](idrawingtable.html) [ITable](idrawingtable.html)  
Контур | ksDrContour | 26 | CONTOUR_OBJ | ALLPARAM | short (стиль) | [ksContourParam](kscontourparam.html) | [IDrawingContour](idrawingcontour.html) [IContour](idrawingcontour.html)  
Нетипизированный макроэлемент | ksDrMacro | 27 | MACRO_OBJ | ALLPARAM | нереализовано | нереализовано | [IMacroObject](imacroobject.html)  
Линия | ksDrLine | 28 | LINE_OBJ | ALLPARAM | [LineParam](structlineparam.html) | [ksLineParam](kslineparam.html) | [ILine](iline.html)  
Слой | ksLayer | 29 | LAYER_OBJ | ALLPARAM | [LayerParam](structlayerparam.html) | [ksLayerParam](kslayerparam.html) | [ILayer](ilayer.html)  
|  |  |  | VIEW_LAYER_STATE | int (состояние слоя) | [ksLtVariant](ksltvariant.html) (состояние слоя) | [ILayer](ilayer.html)  
Вставленный фрагмент | ksDrFragment | 30 | FRAGMENT_OBJ | ALLPARAM | [InsertFragmentParamEx](structinsertfragmentparamex.html) | [ksInsertFragmentParam](ksinsertfragmentparam.html) | [IInsertionFragment](iinsertionfragment.html)  
Полилиния | ksDrPolyline | 31 | POLYLINE_OBJ | ALLPARAM | [PolylineParamEx](structpolylineparamex.html) | [ksPolylineParam](kspolylineparam.html) | [IPolyline](ipolyline.html)  
Эллипс | ksDrEllipse | 32 | ELLIPSE_OBJ | ALLPARAM | [EllipseParam](structellipseparam.html) | [ksEllipseParam](ksellipseparam.html) | [IEllipse](iellipse.html)  
NURBS-кривая по полюсам | ksDrNurbs | 33 | NURBS_OBJ | ALLPARAM | [NurbsParam](structnurbsparam.html) | [ksNurbsParam](ksnurbsparam.html) | [INurbs](inurbs.html)  
|  |  |  | NURBS_CLAMPED_PARAM | [NurbsParam](structnurbsparam.html) | [ksNurbsParam](ksnurbsparam.html) |   
Дуга эллипса | ksDrEllipseArc | 34 | ELLIPSE_ARC_OBJ | ALLPARAM | [EllipseArcParam](structellipsearcparam.html) | [ksEllipseArcParam](ksellipsearcparam.html) | [IEllipseArc](iellipsearc.html)  
|  |  |  | POINT_ARC_PARAM | [EllipseArcParam1](structellipsearcparam1.html) | [ksEllipseArcParam1](ksellipsearcparam1.html) | [IEllipseArc](iellipsearc.html)  
Прямоугольник | ksDrRectangle | 35 | RECTANGLE_OBJ | ALLPARAM | [RectangleParam](structrectangleparam.html) | [ksRectangleParam](ksrectangleparam.html) | [IRectangle](irectangle.html)  
Многоугольник | ksDrRegularPolygon | 36 | REGULARPOLYGON_OBJ | ALLPARAM | [RegularPolygonParam](structregularpolygonparam.html) | [ksRegularPolygonParam](ksregularpolygonparam.html) | [IRegularPolygon](iregularpolygon.html)  
Эквидистанта | ksDrEquid | 37 | EQUID_OBJ | ALLPARAM | [EquidistantParam](structequidistantparam.html) | [ksEquidistantParam](ksequidistantparam.html) | [IEquidistant](iequidistant.html)  
Линейный размер с обрывом | ksDrLBreakDimension | 38 | LBREAKDIMENSION_OBJ | ALLPARAM | [LbreakDimParam](structlbreakdimparam.html) | [ksLBreakDimParam](kslbreakdimparam.html) | [IBreakLineDimension](ibreaklinedimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [LBreakDimSource](structlbreakdimsource.html) | [ksLBreakDimSource](kslbreakdimsource.html) | [IBreakLineDimension](ibreaklinedimension.html)  
|  |  |  | DIM_DRAW_PARAM | [BreakDimDrawing](structbreakdimdrawing.html) | [ksBreakDimDrawing](ksbreakdimdrawing.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Угловой размер с обрывом | ksDrABreakDimension | 39 | ABREAKDIMENSION_OBJ | ALLPARAM | [AbreakDimParam](structabreakdimparam.html) | [ksABreakDimParam](ksabreakdimparam.html) | [IBreakAngleDimension](ibreakangledimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [ADimSource](structadimsource.html) | [ksADimSourceParam](ksadimsourceparam.html) | [IBreakAngleDimension](ibreakangledimension.html)  
|  |  |  | DIM_DRAW_PARAM | [BreakDimDrawing](structbreakdimdrawing.html) | [ksBreakDimDrawing](ksbreakdimdrawing.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Размер высоты | ksDrOrdinateDimension | 40 | ORDINATEDIMENSION_OBJ | ALLPARAM | [OrdinatedDimParam](structordinateddimparam.html) | [ksOrdinatedDimParam](ksordinateddimparam.html) | [IHeightDimension](iheightdimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | [OrdinatedSource](structordinatedsource.html) | [ksOrdinatedSourceParam](ksordinatedsourceparam.html) | [IHeightDimension](iheightdimension.html)  
|  |  |  | DIM_DRAW_PARAM | [OrdinatedDrawing](structordinateddrawing.html) | [ksOrdinatedDrawingParam](ksordinateddrawingparam.html) | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Фоновая заливка цветом | ksDrColorFill | 41 | COLORFILL_OBJ | ALLPARAM | long (цвет) | [ksLtVariant](ksltvariant.html) (цвет) | IColouring  
Обозначение центра | ksDrCentreMarker | 42 | CENTREMARKER_OBJ | ALLPARAM | [CentreParam](structcentreparam.html) | [ksCentreParam](kscentreparam.html) | [ICentreMarker](icentremarker.html) [IAxisLineParam](icentremarker.html)  
Размер длины дуги | ksDrArcDimension | 43 | ARCDIMENSION_OBJ | ALLPARAM | нереализовано | нереализовано | [IArcDimension](iarcdimension.html)  
|  |  |  | DIM_TEXT_PARAM | [DimText](structdimtext.html) | [ksDimTextParam](ksdimtextparam.html) | [IDimensionText](idimensiontext.html)  
|  |  |  | DIM_SOURSE_PARAM | нереализовано | нереализовано | [IArcDimension](iarcdimension.html)  
|  |  |  | DIM_DRAW_PARAM | нереализовано | нереализовано | [IDimensionParams](idimensionparams.html)  
|  |  |  | DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | SHEET_DIM_PARTS | [DimensionPartsParam](structdimensionpartsparam.html) | [ksDimensionPartsParam](ksdimensionpartsparam.html) |   
  
|  |  |  | DIM_VALUE | double | [ksDoubleValue](ksdoublevalue.html) | [IDimensionText::NominalValue](idimensiontext_nominalvalue.html)  
Объект спецификации | не 2D объект | 44 | SPC_OBJ | ALLPARAM | [SpcObjParam](structspcobjparam.html) | [ksSpcObjParam](ksspcobjparam.html) | [ISpecificationObject](ispecificationobject.html) [ISpecificationBaseObject](ispecificationobject.html) [ISpecificationCommentObject](ispecificationobject.html)  
Растровый объект | ksDrRaster | 45 | RASTER_OBJ | ALLPARAM | [RasterParam](structrasterparam.html) | [ksRasterParam](ksrasterparam.html) | [IRaster](iraster.html)  
Обозначение изменения | ksDrChangeLeader | 46 | CHANGE_LEADER_OBJ | ALLPARAM | [ChangeLeaderParam](structchangeleaderparam.html) | [ksChangeLeaderParam](kschangeleaderparam.html) | [IChangeLeader](ichangeleader.html)  
Выносной элемент | ksDrRemoteElement | 47 | REMOTE_ELEMENT_OBJ | ALLPARAM | [RemoteElementParam](remoteelementparam.html) | [ksRemoteElementParam](ksremoteelementparam.html) | [IRemoteElement](iremoteelement.html)  
Осевая линия | ksDrAxisLine | 48 | AXISLINE_OBJ | ALLPARAM | [AxisLineParam](axislineparam.html) | [ksAxisLineParam](ksaxislineparam.html) | [IAxisLine](iaxisline.html) [IAxisLineParam](iaxisline.html)  
Вставка OLE объекта | ksDrOLEObject | 49 | OLEOBJECT_OBJ | ALLPARAM | не реализовано | не реализовано | [IOleDrawingObject](ioledrawingobject.html)  
Номер узла | ksDrUnitNumber | 50 | KNOTNUMBER_OBJ | ALLPARAM | не реализовано | не реализовано | [IUnitMarking](iunitmarking.html)  
Фигурная скобка | ksDrBrace | 51 | BRACE_OBJ | ALLPARAM | не реализовано | не реализовано | [IBrace](ibrace.html)  
Марка/Марка/позиционное обозначение с линией-выноской | ksDrMarkOnLeader | 52 | POSNUM_OBJ | ALLPARAM | не реализовано | не реализовано | [IMarkOnLeader](imarkonleader.html)  
Марка/позиционное обозначение на линии | ksDrMarkOnLine | 53 | MARKONLDR_OBJ | ALLPARAM | не реализовано | не реализовано | [IMarkOnLine](imarkonline.html)  
Марка/позиционное обозначение без линии-выноски | ksDrMarkInsideForm | 54 | MARKWOLDR_OBJ | ALLPARAM | не реализовано | не реализовано | [IMarkInsideForm](imarkinsideform.html)  
Волнистая линияВолнистая | ksDrWaveLine | 55 | WAVELINE_OBJ | ALLPARAM | не реализовано | не реализовано | [IWaveLine](iwaveline.html)  
Прямая ось | ksDrStraightAxis | 56 | DIRAXIS_OBJ | ALLPARAM | не реализовано | не реализовано | [IStraightAxis](istraightaxis.html)  
Линия обрыва с изломами | ksDrBrokenLine | 57 | BROKENLINE_OBJ | ALLPARAM | не реализовано | не реализовано | [IBrokenLine](ibrokenline.html)  
Круговая ось | ksDrCircleAxis | 58 | CIRCLEAXIS_OBJ | ALLPARAM | не реализовано | не реализовано | [ICircleAxis](icircleaxis.html)  
Дуговая ось | ksDrArcAxis | 59 | ARCAXIS_OBJ | ALLPARAM | не реализовано | не реализовано | [IArcAxis](iarcaxis.html)  
Обозначение узла в сечении | ksDrCutUnitMarking | 60 | CUTUNITMARKING | ALLPARAM | не реализовано | не реализовано | [ICutUnitMarking](icutunitmarking.html)  
Обозначение узла | ksDrUnitMarking | 61 | UNITMARKING | ALLPARAM | не реализовано | не реализовано | [IUnitMarking](iunitmarking.html)  
Выносная надпись к многослойным конструкциям | ksDrMultiTextLeade | 62 | MULTITEXTLEADER | ALLPARAM | не реализовано | не реализовано | [IMultiTextLeade](imultitextleader.html)  
Вставка внешнего вида | ksDrExternalView | 63 | EXTERNALVIEW_OBJ | ALLPARAM | не реализовано | не реализовано | [IInsertionView](iinsertionview.html)  
Аннотационный отрезок | ksDrAnnLineSeg | 64 | ANNLINESEG_OBJ | ALLPARAM | [LineSegParam](kslinesegparam.html) | [ksLineSegParam](kslinesegparam.html) | [ILineSegment](ilinesegment.html) [IAnnotativeObject](ilinesegment.html)  
Аннотационная окружность | ksDrAnnCircle | 65 | ANNCIRCLE_OBJ | ALLPARAM | [CircleParam](kscircleparam.html) | [ksCircleParam](kscircleparam.html) | [ICircle](icircle.html) [IAnnotativeObject](icircle.html)  
Аннотационный эллипс | ksDrAnnEllipse | 66 | ANNELLIPSE_OBJ | ALLPARAM | [EllipseParam](ksellipseparam.html) | [ksEllipseParam](ksellipseparam.html) | [IEllipse](iellipse.html) [IAnnotativeObject](iellipse.html)  
Аннотационная дуга | ksDrAnnArc | 67 | ANNARC_OBJ | ALLPARAM | [ArcParam](structarcparam.html) | [ksArcByAngleParam](ksarcbyangleparam.html) | [IArc](iarc.html) [IAnnotativeObject](iarc.html)  
Аннотационная дуга эллипса | ksDrAnnEllipseArc | 68 | ANNELLIPSE_ARC_OBJ | ALLPARAM | [EllipseArcParam](ksellipsearcparam.html) | [ksEllipseArcParam](ksellipsearcparam.html) | [IEllipseArc](iellipsearc.html) [IAnnotativeObject](iellipsearc.html)  
Аннотационная полилиния | ksDrAnnPolyline | 69 | ANNPOLYLINE_OBJ | ALLPARAM | [PolylineParamEx](structpolylineparamex.html) | [ksPolylineParam](kspolylineparam.html) | [IPolyline](ipolyline.html) [IAnnotativeObject](ipolyline.html)  
Аннотационная точка | ksDrAnnPoint | 70 | ANNPOINT_OBJ | ALLPARAM | [PointParam](kspointparam.html) | [ksPointParam](kspointparam.html) | [IPoint](ipoint.html) [IAnnotativeObject](ipoint.html)  
Текст с аннатационной точкой привязки | ksDrAnnText | 71 | ANNTEXT_OBJ | ALLPARAM | [TextParam](kstextparam.html) | [ksTextParam](kstextparam.html) | [IDrawingText](idrawingtext.html) [IText](idrawingtext.html) [IAnnotativeObject](idrawingtext.html)  
Мультилиния | ksDrMultiLine | 72 | MULTILINE_OBJ | ALLPARAM | не реализовано | не реализовано | [IMultiline](imultiline.html)  
Линия разреза/сечения для СПДС | ksDrBuildingCutLine | 73 | BUILDINGCUTLINE_OBJ | ALLPARAM | [CutLineParam](structcutlineparam.html) | [ksCutLineParam](kscutlineparam.html) | [ICutLine](icutline.html)  
Присоединенная линия выноски | ksDrAttachedLeader | 74 | ATTACHED_LEADER_OBJ | ALLPARAM | [LeaderParam](ksleaderparam.html) | [ksLeaderParam](ksleaderparam.html) | [ILeader](ileader.html)  
Условное пересечение | ksDrConditionCrossing | 75 | CONDITIONCROSSING_OBJ | ALLPARAM | не реализовано | не реализовано | IConditionCrossing  
Ассоциативная таблица отчета | ksReportTable | 76 | REPORTTABLE_OBJ | ALLPARAM | не реализовано | не реализовано | [IAssociationTable](iassociationtable.html)  
Таблица исполнений | ksEmbodimentsTable | 77 | EMBODIMENTSTABLE_OBJ | ALLPARAM | не реализовано | не реализовано | [IAssociationTable](iassociationtable.html)  
Кривая общего вида (проекционная кривая) |  | 78 | SPECIALCURVE_OBJ | ALLPARAM | не реализовано | не реализовано | [IDrawingObject](idrawingobject.html) [IDrawingObject1](idrawingobject.html)  
Таблица параметров массива | ksArrayParamTable | 79 | ARRAYPARAMTABLE_OBJ | ALLPARAM | не реализовано | не реализовано | [IAssociationTable](iassociationtable.html)  
NURBS-кривая по точкам | ksDrNurbsByPoints | 80 | NURBS_BY_POINTS_OBJ | ALLPARAM | не реализовано | не реализовано | [INurbsByPoints](inurbsbypoints.html) [INurbs](inurbsbypoints.html)  
Коническая кривая | ksDrConicCurve | 81 | CONIC_CURVE_OBJ | ALLPARAM | не реализовано | не реализовано | I[ConicCurve](iconiccurve.html)  
Круговая сетка центров | ksDrCircularCentres | 84 | CIRCULAR_CENTRES_OBJ | ALLPARAM | не реализовано | не реализовано | [ICircularCentres](icircularcentres.html)  
Линейная сетка центров | ksDrLinearCentres | 85 | LINEAR_CENTRES_OBJ | ALLPARAM | не реализовано | не реализовано | [ILinearCentres](ilinearcentres.html)  
Дуговая осевая линия | ksDrEllipseArcAxis | 86 | ELLIPSE_ARC_AXIS_OBJ | ALLPARAM | не реализовано | не реализовано | не реализовано  
Cпецификация на листе | не объект 2D | 121 | SPECIFICATION_OBJ | ALLPARAM | не реализовано | не реализовано | [ISpecificationDescription::ShowOnSheet](ispecificationdescription_showonsheet.html)  
неуказанная шероховатость | не объект 2D | 122 | SPECROUGH_OBJ | ALLPARAM | не реализовано | не реализовано | [ISpecRough](ispecrough.html)  
Вид | ksView | 123 | VIEW_OBJ | ALLPARAM | [ViewParam](structviewparam.html) | [ksViewParam](ksviewparam.html) | [IView](iview.html)  
Не объекты 2D |  |  |  |  |  |  |   
графический документ (чертеж или фрагмент) |  | 124 | DOCUMENT_OBJ | ALLPARAM | [DocumentParam](structdocumentparam.html) | [ksDocumentParam](ksdocumentparam.html) | [IKompasDocument2D](ikompasdocument2d.html) [IKompasDocument2D1](ikompasdocument2d.html) [IFragmentDocument](ikompasdocument2d.html) [IDrawingDocument](ikompasdocument2d.html)  
технические требования |  | 125 | TECHNICALDEMAND_OBJ | ALLPARAM или TECHNICAL_DEMAND_PAR 0, 1, 2... TT_FIRST_STR reference (массив строк TEXT_LINE_ARR) | [TechnicalDemandParam](structtechnicaldemandparam.html) [ksDynamicArray](structtechnicaldemandparam.html) (массив строк TEXT_LINE_ARR) | [ksTechnicalDemandParam](kstechnicaldemandparam.html) | [ITechnicalDemand](itechnicaldemand.html)  
|  |  |  |  | Примечание: Массив составляют только строки, входящие в страницу (габаритный прямоугольник) технических требований с номером, заданным в TECHNICAL_DEMAND_PAR.  
Штамп |  | 126 | STAMP_OBJ | ALLPARAM | нереализовано | нереализовано? можно использовать [ksStamp](ksstamp.html) | [IStamp](istamp.html)  
Группа селектирования |  | 127 | SELECT_GROUP_OBJ | ALLPARAM | нереализовано | нереализовано | [ISelectionManager](iselectionmanager.html)  
Именованная группа |  | 128 | NAME_GROUP_OBJ | ALLPARAM | нереализовано | нереализовано | [IDrawingGroup](idrawinggroup.html)  
Рабочая группа |  | 129 | WORK_GROUP_OBJ | ALLPARAM | нереализовано | нереализовано | [IDrawingGroup](idrawinggroup.html)  
Документ- спецификация |  | 130 | SPC_DOCUMENT_OBJ | ALLPARAM | [DocumentParam](structdocumentparam.html) | [ksDocumentParam](ksdocumentparam.html) | [ISpecificationDocument](ispecificationdocument.html)  
|  |  |  | DOCUMENT_SIZE | [SheetSize](structsheetsize.html) | [ksSheetSize](kssheetsize.html) | [ILayoutSheet](ilayoutsheet.html) [ISheetFormat](ilayoutsheet.html)  
|  |  |  | DOCUMENT_STATE | int (состояние документа) | [ksLtVariant](ksltvariant.html) (состояние документа) можно использовать [ksSpcDocument](ksspcdocument.html) | [IKompasDocument::Active](ikompasdocument_active.html)  
Документ-модель (деталь или сборка). |  | 131 | D3_DOCUMENT_OBJ | ALLPARAM | [DocumentParam](structdocumentparam.html) | [ksDocumentParam](ksdocumentparam.html) | [IKompasDocument3D](ikompasdocument3d.html) [IKompasDocument3D1](ikompasdocument3d.html) [IPartDocument](ikompasdocument3d.html) [IAssemblyDocument](ikompasdocument3d.html)  
|  |  |  | DOCUMENT_STATE | int (состояние документа) | [ksLtVariant](ksltvariant.html) (состояние документа), можно использовать [IDocument3D](ksdocument3d.html) ksDocument3D | [IKompasDocument::Active](ikompasdocument_active.html)  
Таблица изменений |  | 132 | CHANGE_LIST_OBJ | ALLPARAM | нереализовано | нереализовано | [IDrawingDocument::ChangeListDescriptions](idrawingdocument_changelistdescriptions.html)  
Текстовый документ |  | 133 | TXT_DOCUMENT_OBJ | ALLPARAM | [TextDocumentParam](structtextdocumentparam.html) | [ksTextDocumentParam](kstextdocumentparam.html) | [ITextDocumen](itextdocument.html)t  
Все документы |  | 134 | ALL_DOCUMENTS | константа используется при создании итератора по документам | [IApplication::Documents](iapplication_documents.html)  
Верхняя граница типов поиска |  | 134 | MAX_TIP_SEARCH | не используется |  |  |   
Все объекты, которые могут входить в вид в порядке отрисовки |  | -1000 | ALL_OBJ_SHOW_ORDER | константа используется при создании итератора по объектам вида |   
  
Примечание:

Для SHEET_ALLPARAM используются те же структуры, что и для ALLPARAM.

Подразделы:

(отсутствуют)
