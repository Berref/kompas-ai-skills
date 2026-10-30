# Obj3dType (ksObj3dTypeEnum) - Типы объектов документа-модели; соответствие интерфейсов API 5 и API 7

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Прочие ](bk1944694.html) > [3D ](bk1944689.html) |  Scroll [ [ [ ](errortype3d.html "К следующему разделу")](bk1944689.html "На уровень выше")](kscontour3dbuildingtypetypeenum.html "К предыдущему разделу")  
---|---  
  
В таблице представлены идентификаторы объектов для интерфейсов API 5 и API 7.

Идентификатор объекта | Название объекта | Интерфейс параметров API 5 | Интерфейс параметров API 7  
---|---|---|---  
o3d_unknown | 0 | неизвестный (включает все объекты) |  |   
o3d_planeXOY | 1 | плоскость XOY | ksDefaultObject | [IPlane3D](iplane3d.html)  
o3d_planeXOZ | 2 | плоскость XOZ | ksDefaultObject | [IPlane3D](iplane3d.html)  
o3d_planeYOZ | 3 | плоскость YOZ | ksDefaultObject | [IPlane3D](iplane3d.html)  
o3d_pointCS | 4 | точка начала системы координат | ksDefaultObject | [IModelObject](imodelobject.html)  
Элементы детали |   
o3d_sketch | 5 | эскиз | [ksSketchDefinition](kssketchdefinition.html) | [ISketch](isketch.html)  
o3d_face | 6 | поверхность | [ksFaceDefinition](ksfacedefinition.html) | [IFace](iface.html)  
o3d_edge | 7 | ребро | [ksEdgeDefinition](ksedgedefinition.html) | [IEdge](iedge.html)  
o3d_vertex | 8 | вершина | [ksVertexDefinition](ksvertexdefinition.html) | [IVertex](ivertex.html)  
Конструктивные элементы |   
o3d_axis2Planes | 9 | ось по двум плоскостям | [ksAxis2PlanesDefinition](ksaxis2planesdefinition.html) | [IAxis3DBy2Planes](iaxis3dby2planes.html)  
o3d_axis2Points | 10 | ось по двум точкам | [ksAxis2PointsDefinition](ksaxis2pointsdefinition.html) | [IAxis3DBy2Points](iaxis3dby2points.html)  
o3d_axisConeFace | 11 | ось конической грани | [ksAxisConefaceDefinition](ksaxisconefacedefinition.html) | [IAxis3DByConeface](iaxis3dbyconeface.html)  
o3d_axisEdge | 12 | ось, проходящая через ребро | [ksAxisEdgeDefinition](ksaxisedgedefinition.html) | [IAxis3DByEdge](iaxis3dbyedge.html)  
o3d_axisOperation | 13 | ось операции | [ksAxisOperationsDefinition](ksaxisoperationsdefinition.html) | [IAxis3DByOperation](iaxis3dbyoperation.html)  
o3d_planeOffset | 14 | смещённая плоскость | [ksPlaneOffsetDefinition](ksplaneoffsetdefinition.html) | [IPlane3DByOffset](iplane3dbyoffset.html)  
o3d_planeAngle | 15 | плоскость под углом | [ksPlaneAngleDefinition](ksplaneangledefinition.html) | [IPlane3DByAngle](iplane3dbyangle.html)  
o3d_plane3Points | 16 | плоскость по 3-м точкам | [ksPlane3PointsDefinition](ksplane3pointsdefinition.html) | [IPlane3DBy3Points](iplane3dby3points.html)  
o3d_planeNormal | 17 | нормальная плоскость | [ksPlaneNormalToSurfaceDefinition](ksplanenormaltosurfacedefinition.html) | [IPlane3DNormalToSurface](iplane3dnormaltosurface.html)  
o3d_planeTangent | 18 | касательная плоскость | [ksPlaneTangentToSurfaceDefinition](ksplanetangenttosurfacedefinition.html) | [IPlane3DTangentToFace](iplane3dtangenttoface.html)  
o3d_planeEdgePoint | 19 | плоскость через ребро и вершину | [ksPlaneEdgePointDefinition](ksplaneedgepointdefinition.html) | [IPlane3DByEdgeAndPoint](iplane3dbyedgeandpoint.html)  
o3d_planeParallel | 20 | плоскость через вершину параллельно другой плоскости | [ksPlaneParallelDefinition](ksplaneparalleldefinition.html) | [IPlane3DParallelByPoint](iplane3dparallelbypoint.html)  
o3d_planePerpendicular | 21 | плоскость через вершину перпендикулярно ребру | [ksPlanePerpendicularDefinition](ksplaneperpendiculardefinition.html) | [IPlane3DPerpendicularByEdge](iplane3dperpendicularbyedge.html)  
o3d_planeLineToEdge | 22 | плоскость через ребро параллельно /перпендикулярно другому ребру | [ksPlaneLineToEdgeDefinition](ksplanelinetoedgedefinition.html) | [IPlane3DBy2Edge](iplane3dby2edge.html)  
o3d_planeLineToPlane | 23 | плоскость через ребро параллельно /перпендикулярно грани | [ksPlaneLineToPlaneDefinition](ksplanelinetoplanedefinition.html) | [IPlane3DByEdgeAndPlane](iplane3dbyedgeandplane.html)  
o3d_baseExtrusion | 24 | базовая операция выдавливания | [ksBaseExtrusionDefinition](ksbaseextrusiondefinition.html) | [IExtrusion](iextrusion.html)  
o3d_bossExtrusion | 25 | приклеивание выдавливанием | [ksBossExtrusionDefinition](ksbossextrusiondefinition.html) | [IExtrusion](iextrusion.html)  
o3d_cutExtrusion | 26 | вырезать выдавливанием | [ksCutExtrusionDefinition](kscutextrusiondefinition.html) | [ICutExtrusion](icutextrusion.html)  
o3d_baseRotated | 27 | базовая операция вращения | [ksBaseRotatedDefinition](ksbaserotateddefinition.html) | [IRotated](irotated.html)  
o3d_bossRotated | 28 | приклеивание вращением | [ksBossRotatedDefinition](ksbossrotateddefinition.html) | [IRotated](irotated.html)  
o3d_cutRotated | 29 | вырезать вращением | [ksCutRotatedDefinition](kscutrotateddefinition.html) | [ICutRotated](icutrotated.html)  
o3d_baseLoft | 30 | базовая операция по сечениям | [ksBaseLoftDefinition](ksbaseloftdefinition.html) | [ILoft](iloft.html)  
o3d_bossLoft | 31 | приклеивание по сечениям | [ksBossLoftDefinition](ksbossloftdefinition.html) | [ILoft](iloft.html)  
o3d_cutLoft | 32 | вырезать по сечениям | [ksCutLoftDefinition](kscutloftdefinition.html) | [ILoft](iloft.html)  
o3d_chamfer | 33 | операция "фаска" | [ksChamferDefinition](kschamferdefinition.html) | [IChamfer](ichamfer.html)  
o3d_fillet | 34 | операция "скругление" | [ksFilletDefinition](ksfilletdefinition.html) | [IFillet](ifillet.html)  
o3d_meshCopy | 35 | операция копирования по сетке | [ksMeshCopyDefinition](ksmeshcopydefinition.html) | [ILinearPattern](ilinearpattern.html)  
o3d_circularCopy | 36 | операция копирования по концентрической сетке | [ksCircularCopyDefinition](kscircularcopydefinition.html) | [ICircularPattern](icircularpattern.html)  
o3d_curveCopy | 37 | операция копирования по кривой | [ksCurveCopyDefinition](kscurvecopydefinition.html) | [IPathPattern](ipathpattern.html)  
o3d_circPartArray | 38 | операция массив по концентрической сетке для сборки | [ksCircularPartArrayDefinition](kscircularpartarraydefinition.html) | [ICircularPattern](icircularpattern.html)  
o3d_meshPartArray | 39 | операция массив по сетке для сборки | [ksMeshPartArrayDefinition](ksmeshpartarraydefinition.html) | [ILinearPattern](ilinearpattern.html)  
o3d_curvePartArray | 40 | операция массив по кривой для сборки | [ksCurvePartArrayDefinition](kscurvepartarraydefinition.html) | [IPathPattern](ipathpattern.html)  
o3d_derivPartArray | 41 | операция массив по образцу для сборки | [ksDerivativePartArrayDefinition](ksderivativepartarraydefinition.html) | [IDerivedPattern](iderivedpattern.html)  
o3d_incline | 42 | операция "уклон" | [ksInclineDefinition](ksinclinedefinition.html) | [IIncline](iincline.html)  
o3d_shellOperation | 43 | операция "оболочка" | [ksShellDefinition](ksshelldefinition.html) | [IShell](ishell.html)  
o3d_ribOperation | 44 | операция "ребро жесткости" | [ksRibDefinition](ksribdefinition.html) | [IRib](irib.html)  
o3d_baseEvolution | 45 | кинематическая операция | [ksBaseEvolutionDefinition](ksbaseevolutiondefinition.html) | [IEvolution](ievolution.html)  
o3d_bossEvolution | 46 | приклеить кинематически | [ksBossEvolutionDefinition](ksbossevolutiondefinition.html) | [IEvolution](ievolution.html)  
o3d_cutEvolution | 47 | вырезать кинематически | [ksCutEvolutionDefinition](kscutevolutiondefinition.html) | [IEvolution](ievolution.html)  
o3d_mirrorOperation | 48 | операция "зеркальный массив" | [ksMirrorCopyDefinition](ksmirrorcopydefinition.html) | [IMirrorPattern](imirrorpattern.html)  
o3d_mirrorAllOperation | 49 | операция "зеркально отразить все" | [ksMirrorCopyAllDefinition](ksmirrorcopyalldefinition.html) | [IMirrorPattern](imirrorpattern.html)  
o3d_cutByPlane | 50 | операция "сечение поверхностью" | [ksCutByPlaneDefinition](kscutbyplanedefinition.html) | [ICut](icut.html)  
o3d_cutBySketch | 51 | операция "сечение эскизом" | [ksCutBySketchDefinition](kscutbysketchdefinition.html) | [ICut](icut.html)  
o3d_holeOperation | 52 | отверстие |  |   
Кривые |   
o3d_polyline | 53 | ломаная | [ksPolyLineDefinition](kspolylinedefinition.html) | [IPolyLine](ipolyline.html)  
o3d_conicSpiral | 54 | коническая спираль | [ksConicSpiralDefinition](ksconicspiraldefinition.html) | [IConicSpiral3D](iconicspiral3d.html)  
o3d_spline | 55 | сплайн | [ksSplineDefinition](kssplinedefinition.html) | [ISpline3D](ispline3d.html)  
o3d_cylindricSpiral | 56 | цилиндрическая спираль | [ksCylindricSpiralDefinition](kscylindricspiraldefinition.html) | [ICylindricSpiral3D](icylindricspiral3d.html)  
o3d_importedSurface | 57 | импортирванная поверхность | [ksImportedSurfaceDefinition](ksimportedsurfacedefinition.html) | [IImportedSurface](iimportedsurface.html)  
o3d_thread | 58 | условное изображение резьбы | [ksThreadDefinition](ksthreaddefinition.html) | [IThread](ithread.html)  
o3d_EvolutionSurface | 59 | кинематическая поверхность | [ksEvolutionSurfaceDefinition](ksevolutionsurfacedefinition.html) | [IEvolution](ievolution.html)  
o3d_ExtrusionSurface | 60 | поверхность выдавливания | [ksExtrusionSurfaceDefinition](ksextrusionsurfacedefinition.html) | [IExtrusionSurface](iextrusionsurface.html)  
o3d_RotatedSurface | 61 | поверхность вращения | [ksRotatedSurfaceDefinition](ksrotatedsurfacedefinition.html) | [IRotatedSurface](irotatedsurface.html)  
o3d_LoftSurface | 62 | поверхность по сечениям | [ksLoftSurfaceDefinition](ksloftsurfacedefinition.html) | [ILoft](iloft.html)  
o3d_MacroObject | 63 | макроэлемент 3D | [ksMacro3DDefinition](ksmacro3ddefinition.html) | [IMacroObject3D](imacroobject3d.html)  
o3d_UnionComponents | 64 | операция объединения компонентов | [ksUnionComponentsDefinition](ksunioncomponentsdefinition.html) | [IUnionComponents](iunioncomponents.html)  
o3d_MoldCavity | 65 | операция вычитания компонентов | [ksMoldCavityDefinition](ksmoldcavitydefinition.html) | [IMoldCavity](imoldcavity.html)  
o3d_planeMiddle | 66 | средняя плоскость | [ksPlaneMiddleDefinition](ksplanemiddledefinition.html) | [IPlane3DMiddle](iplane3dmiddle.html)  
o3d_controlPoint | 67 | контрольная точка | [ksControlPointDefinition](kscontrolpointdefinition.html) | [IControlPoint](icontrolpoint.html)  
o3d_conjunctivePoint | 68 | присоединительная точка | [ksConjunctivePointDefinition](ksconjunctivepointdefinition.html) | [IConjunctivePoint](iconjunctivepoint.html)  
o3d_aggregate | 69 | Булева операция | [ksAggregateDefinition](ksaggregatedefinition.html) | [IBoolean](iboolean.html)  
o3d_point3D | 70 | Конструктивная 3D точка |  | [IPoint3D](ipoint3d.html)  
o3d_axisOX | 71 | Ось OX | ksDefaultObject | [IAxis3D](iaxis3d.html)  
o3d_axisOY | 72 | Ось OY | ksDefaultObject | [IAxis3D](iaxis3d.html)  
o3d_axisOZ | 73 | Ось OZ | ksDefaultObject | [IAxis3D](iaxis3d.html)  
o3d_sheetMetalBody | 74 | Листовое тело |  | [ISheetMetalBody](isheetmetalbody.html)  
o3d_sheetMetalBend | 75 | Сгиб |  | [ISheetMetalBend](isheetmetalbend.html)  
o3d_sheetMetalLineBend | 76 | Сгиб по линии |  | [ISheetMetalLineBend](isheetmetallinebend.html)  
o3d_sheetMetalHole | 77 | Элемент листового тела "отверстие" |  | [ISheetMetalHole](isheetmetalhole.html)  
o3d_sheetMetalCut | 78 | Элемент листового тела "вырез" |  | [ISheetMetalCut](isheetmetalcut.html)  
o3d_UnHistoried | 79 | Операция без истории |  |   
o3d_baselineDimension3D | 80 | Линейный размер 3D (от отрезка до точки) |  | [IBaseLineDimension3D](ibaselinedimension3d.html)  
o3d_lineDimension3D | 81 | Линейный размер 3D (на плоскости) |  | [ILineDimension3D](ilinedimension3d.html)  
o3d_radialDimension3D | 82 | Радиальный размер 3D |  | [IRadialDimension3D](iradialdimension3d.html)  
o3d_diametralDimension3D | 83 | Диаметральный размер 3D |  | [IDiametralDimension3D](idiametraldimension3d.html)  
o3d_angleDimension3D | 84 | Угловой размер 3D |  | [IAngleDimension3D](iangledimension3d.html)  
o3d_localCoordinateSystem | 85 | Локальная система координат |  | [ILocalCoordinateSystem](ilocalcoordinatesystem.html)  
o3d_leader3D | 86 | Линия-выноска 3D |  | [ILeader](ileader.html)  
o3d_markLeader3D | 87 | Знак маркировки 3D |  | [IMarkLeader](imarkleader.html)  
o3d_rough3D | 88 | Обозначение 3D шероховатости |  | [IRough3D](irough3d.html)  
o3d_positionLeader3D | 89 | Обозначение позиции 3D |  | [IPositionLeader](ipositionleader.html)  
o3d_brandLeader3D | 90 | Знак клеймения 3D |  | [IBrandLeader](ibrandleader.html)  
o3d_base3D | 91 | Обозначение 3D базы |  | [IBase3D](ibase3d.html)  
o3d_tolerance3D | 92 | Допуск формы 3D |  | [ITolerance3D](itolerance3d.html)  
o3d_SplitLine | 93 | Линия разъема |  | [ISplitLine](isplitline.html)  
o3d_SurfacePatch | 94 | Заплатка |  | [ISurfacePatch](isurfacepatch.html)  
o3d_FaceRemover | 95 | Операция удаления граней |  | [IFaceRemover](ifaceremover.html)  
o3d_SurfaceSewer | 96 | Операция сшивки поверхностей |  | [ISurfaceSewer](isurfacesewer.html)  
o3d_NurbsSurface | 97 | NURBS-поверхность |  | [INurbsSurface](inurbssurface.html)  
o3d_SurfacesIntersectionCurve | 98 | Кривая пересечения поверхностей |  | [ISurfacesIntersectionCurve](isurfacesintersectioncurve.html)  
o3d_lastEntityElement | 99 | Всегда последний из Entity!!! |  |   
Элементы, не являющиеся Entity |   
o3d_variable | 100 | параметрическая переменная | [ksVariable](ksvariable.html) | [IVariable7](ivariable7.html)  
o3d_placement | 101 | местоположение | [ksPlacement](ksplacement.html) | [IPlacement3D](iplacement3d.html)  
o3d_entityCollection | 102 | Массив трехмерных объектов | [ksEntityCollection](ksentitycollection.html) |   
o3d_document | 103 | Документ-модель | [ksDocument3D](ksdocument3d.html) | [IKompasDocument3D](ikompasdocument3d.html)  
o3d_part | 104 | Деталь | [ksPart](kspart.html) | [IPart7](ipart7.html)  
o3d_entity | 105 | Объект | [ksEntity](ksentity.html) | [IModelObject](imodelobject.html)  
o3d_mateConstraint | 106 | сопряжение | [ksMateConstraint](ksmateconstraint.html) | [IMateConstraint3D](imateconstraint3d.html)  
o3d_mateConstraintCollection | 107 | Массив сопряжений | [ksMateConstraintCollection](ksmateconstraintcollection.html) | [IMateConstraints3D](imateconstraints3d.html)  
o3d_partCollection | 108 | Массив элементов сборки | [ksPartCollection](kspartcollection.html) | [IParts7](iparts7.html)  
Объединенные типы объектов для создания EntityCollection |   
o3d_constrElement | 109 | конструктивные элементы-плоскости и оси (конструктивные от o3d_axis2Planes до o3d_plane3Points) |  |   
o3d_operationElement | 110 | Операции (от o3d_baseExtrusion до o3d_cylindricSpiral) |  |   
o3d_curveElement | 111 | Кривые (пространственные и ребра) |  |   
o3d_rasterFormat | 112 | интерфейс параметров для конвертации в растровый формат | [ksRasterFormatParam](ksrasterformatparam.html) |   
o3d_additionFormat | 113 | интерфейс параметров для конвертации в дополнительные форматы: jgs, sat, xt, x_b, step, stl, VRML | [ksAdditionFormatParam](ksadditionformatparam.html) |   
o3d_bodyCollection | 114 | интерфейс массива трехмерных тел | [ksBodyCollection](ksbodycollection.html) |   
o3d_body | 115 | интерфейс трехмерного тела | [ksBody](ksbody.html) | [IBody7](ibody7.html)  
o3d_faceCollection | 116 | интерфейс массива граней | [ksFaceCollection](ksfacecollection.html) |   
o3d_tessellation | 117 | интерфейс триангуляции | [ksTessellation](kstessellation.html) | [ITesselllation7](itessellation7.html)  
o3d_facet | 118 | интерфейс триангуляционной пластины | [ksFacet](ksfacet.html) |   
o3d_featureCollection | 119 | интерфейс массива объектов дерева | [ksFeatureCollection](ksfeaturecollection.html) |   
o3d_feature | 120 | интерфейс объекта дерева | [ksFeature](ksfeature.html) | [IFeature7](ifeature7.html)  
o3d_edgeCollection | 121 | интерфейс массива ребер | [ksEdgeCollection](ksedgecollection.html) |   
o3d_orientedEdge | 122 | интерфейс ориентированного ребра | [ksOrientedEdge](ksorientededge.html) | [IOrientedEdge7](iorientededge7.html)  
o3d_orientedEdgeCollection | 123 | интерфейс массива ориентированных ребер | [ksOrientedEdgeCollection](ksorientededgecollection.html) |   
o3d_loop | 124 | интерфейс цикла | [ksLoop](ksloop.html) | [ILoop7](iloop7.html)  
o3d_loopCollection | 125 | интерфейс массива циклов | [ksLoopCollection](ksloopcollection.html) |   
o3d_curve3D | 126 | интерфейс математической кривой в трехмерном пространстве | [ksCurve3D](kscurve3d.html) | [IMathCurve3D](imathcurve3d.html)  
o3d_surface | 127 | интерфейс математической поверхности в трехмерном пространстве | [ksSurface](kssurface.html) | [IMathSurface3D](imathsurface3d.html)  
o3d_massInertiaParam | 128 | Интерфейс параметров для расчета массово-центровочных характеристик | [ksMassInertiaParam](ksmassinertiaparam.html) | [IMassInertiaParam7](imassinertiaparam7.html)  
o3d_line3dParam | 129 | Интерфейс параметров 3dLine | [ksLineSeg3dParam](kslineseg3dparam.html) |   
o3d_circle3dParam | 130 | Интерфейс параметров 3dCircle | [ksCircle3dParam](kscircle3dparam.html) |   
o3d_ellipse3dParam | 131 | Интерфейс параметров 3dEllipce | [ksEllipse3dParam](ksellipse3dparam.html) |   
o3d_nurbsPoint3dParam | 132 | Интерфейс параметров точки для трехмерной NURBS | [ksNurbsPoint3dParam](ksnurbspoint3dparam.html) |   
o3d_nurbsPoint3dCollection | 133 | Интерфейс массива точек для трехмерной NURBS | [ksNurbsPoint3dCollection](ksnurbspoint3dcollection.html) |   
o3d_nurbsPoint3dCollCollection | 134 | Интерфейс массива массивов точек для трехмерной NURBS поверхности | [ksNurbsPoint3dCollCollection](ksnurbspoint3dcollcollection.html) |   
o3d_nurbsKnotCollection | 135 | Интерфейс массива узлов для трехмерного NURBS | [ksNurbsKnotCollection](ksnurbsknotcollection.html) |   
o3d_nurbs3dParam | 136 | Интерфейс параметров трехмерного NURBS | [ksNurbs3dParam](ksnurbs3dparam.html) |   
o3d_planeParam | 137 | Интерфейс параметров плоскости | [ksPlaneParam](ksplaneparam.html) |   
o3d_coneParam | 138 | Интерфейс параметров конической поверхности | [ksConeParam](ksconeparam.html) |   
o3d_cylinderParam | 139 | Интерфейс параметров цилиндрической поверхности | [ksCylinderParam](kscylinderparam.html) |   
o3d_sphereParam | 140 | Интерфейс параметров сферы | [ksSphereParam](kssphereparam.html) |   
o3d_torusParam | 141 | Интерфейс параметров тора | [ksTorusParam](kstorusparam.html) |   
o3d_nurbsSurfaceParam | 142 | Интерфейс параметров NURBS-поверхности | [ksNurbsSurfaceParam](ksnurbssurfaceparam.html) |   
o3d_mateConstraintGroup | 143 | Объект дерева: группа сопряжений | [IModelObject](imodelobject.html) | [IFeature7](ifeature7.html)  
o3d_measurer | 144 | Интерфейс для измерений расстояния и угла между двумя примитивами (гранями, ребрами, вершинами) | [ksMeasurer](ksmeasurer.html) |   
o3d_selectionMng | 145 | Интерфейс менеджера выделенных объектов | [ksSelectionMng](ksselectionmng.html) | [ISelectionManager](iselectionmanager.html)  
o3d_chooseMng | 146 | Интерфейс менеджера выбора (подсветки) объектов | [ksChooseMng](kschoosemng.html) | [IChooseManager](ichoosemanager.html)  
o3d_arc3dParam | 147 | Интерфейс параметров трехмерной дуги | [ksArc3dParam](ksarc3dparam.html) |   
o3d_deletedCopyCollection | 148 | Интерфейс массива удаленных индексов для операций копирования и массивов компонент | [ksDeletedCopyCollection](ksdeletedcopycollection.html) |   
o3d_viewProjection | 149 | Интерфейс проекции отображения модели в окне | [ksViewProjection](ksviewprojection.html) |   
o3d_viewProjectionCollection | 150 | Интерфейс массива проекций отображения модели в окне | [ksViewProjectionCollection](ksviewprojectioncollection.html) |   
o3d_attribute | 151 | Интерфейс атрибута объекта модели | [ksAttribute3D](ksattribute3d.html) | [IAttribute](iattribute.html)  
o3d_attributeCollection | 152 | Интерфейс массива атрибутов объекта модели | [ksAttribute3DCollection](ksattribute3dcollection.html) |   
o3d_componentPositioner | 153 | Интерфейс управления положением компонентов в сборке | [ksComponentPositioner](kscomponentpositioner.html) |   
o3d_modelLibrary | 154 | Интерфейс библиотеки моделей | [ksModelLibrary](ksmodellibrary.html) | [IInsertsLibrary](iinsertslibrary.html)  
o3d_ObjectsFilter3D | 155 | Не используется |  |   
o3d_coordinate3dCollection | 156 | Интерфейс коллекции координат | [ksCoordinate3dCollection](kscoordinate3dcollection.html) |   
o3d_intersectionResult | 157 | Интерфейс результатов пересечений двух тел | [ksIntersectionResult](ksintersectionresult.html) |   
o3d_PolygonalLineVertexParam | 158 | Параметры вершины полилинии | [ksPolyLineVertexParam](kspolylinevertexparam.html) | [ICurveVertexParam](icurvevertexparam.html)  
o3d_variableCollection | 159 | Массив параметрических переменных | [ksvariableCollection](ksvariablecollection.html) |   
o3d_sTrackingPointsMeasurer | 160 | Интерфейс для расчета координат точек при S- образном соединении прямолинейных рёбер | [IsTrackingPointsMeasurer](istrackingpointsmeasurer.html) |   
o3d_surfaceElement | 161 | Поверхности |  |   
o3d_designationElemen | 162 | Размеры и условные обозначения |  |   
o3d_copyleftObject | 163 | Объекты доступные для копирования |  |   
o3d_Embodiment | 164 | Исполнение |  | [IEmbodiment](iembodiment.html)  
o3d_userMateConstraint | 165 | Пользовательское сопряжение |  | IMateConstraint + IUserObject3D  
o3d_intervalVariable | 166 | Интервальная переменная |  |   
o3d_userFunc | 167 | Функциональная переменная |  |   
o3d_firstEntityElement2 | 500 | Первый из Entity2!!! |  |   
o3d_Equidistant3D | 501 | Эквидистанта 3D |  | [IEquidistant3D](iequidistant3d.html)  
o3d_TrimmedCurve | 502 | Операция усечения кривой |  | [ITrimmedCurve](itrimmedcurve.html)  
o3d_TrimmedCurveObject | 503 | Усеченная кривая |  | [ITrimmedCurve](itrimmedcurve.html)  
o3d_AuxMeshCopy | 504 | Массив вспомогательной геометрии по сетке |  | [ILinearPattern](ilinearpattern.html)  
o3d_AuxCircularCopy | 505 | Массив вспомогательной геометрии по концентрической сетке |  | [ICircularPattern](icircularpattern.html)  
o3d_AuxCurveCopy | 506 | Массив вспомогательной геометрии вдоль кривой |  | [IPathPattern](ipathpattern.html)  
o3d_PointDrivenPattern | 507 | Массив операций по точкам |  | [IPointDrivenPattern](ipointdrivenpattern.html)  
o3d_PartsPointDrivenPattern | 508 | Массив компонентов по точкам |  | [IPointDrivenPattern](ipointdrivenpattern.html)  
o3d_AuxMirrorOperation | 509 | Зеркальный массив вспомогательной геометрии |  | [IMirrorPattern](imirrorpattern.html)  
o3d_ConnectCurve | 510 | Операция соединения кривых |  | [IConnectCurve](iconnectcurve.html)  
o3d_ConnectCurveObject | 511 | Кривая соединения |  | [IModelObject](imodelobject.html)  
o3d_FilletCurve | 512 | Операция скругления кривых |  | [IFilletCurve](ifilletcurve.html)  
o3d_FilletCurveObject | 513 | Скругленная кривая |  | [IModelObject](imodelobject.html)  
o3d_EquidistantSurface | 514 | Операция построения эквидистанты поверхности |  | [IEquidistantSurface](iequidistantsurface.html)  
o3d_RuledSurface | 515 | Линейчатая поверхность |  | [IRuledSurface](iruledsurface.html)  
o3d_TrimmedSurface | 516 | Операция усечения поверхности |  | [ITrimmedSurface](itrimmedsurface.html)  
o3d_ExtensionSurface | 517 | Операция продления поверхности |  | [IExtensionSurface](iextensionsurface.html)  
o3d_SurfaceThickening | 518 | Операция придания толщины поверхности |  | [ISurfaceThickening](isurfacethickening.html)  
o3d_Arc3D | 519 | 3D дуга |  | [IArc3D](iarc3d.html)  
o3d_AuxPointDrivenPattern | 520 | Массив вспомогательной геометрии по точкам |  | [IPointDrivenPattern](ipointdrivenpattern.html)  
o3d_BodiesPointDrivenPattern | 521 | Массив тел по точкам |  | [IPointDrivenPattern](ipointdrivenpattern.html)  
o3d_TablePattern | 522 | Массив операций по таблице из файла |  | [ITablePattern](itablepattern.html)  
o3d_PartsTablePattern | 523 | Массив компонентов по таблице из файла |  | [ITablePattern](itablepattern.html)  
o3d_AuxTablePattern | 524 | Массив вспомогательной геометрии по таблице из файла |  | [ITablePattern](itablepattern.html)  
o3d_BodiesTablePattern | 525 | Массив тел по таблице из файла |  | [ITablePattern](itablepattern.html)  
o3d_MeshPointsSurface | 526 | Поверхность по сети точек |  | [IMeshPointsSurface](imeshpointssurface.html)  
o3d_CloudPointsSurface | 527 | Поверхность по пласту (облаку) точек |  | [ICloudPointsSurface](icloudpointssurface.html)  
o3d_BodiesMeshCopy | 528 | Массив тел по сетке |  | [ILinearPattern](ilinearpattern.html)  
o3d_BodiesCircularCopy | 529 | Массив тел по концентрической сетке |  | [ICircularPattern](icircularpattern.html)  
o3d_BodiesCurveCopy | 530 | Массив тел вдоль кривой |  | [IPathPattern](ipathpattern.html)  
o3d_Scaling3D | 531 | Масштабирование |  | [IScaling3D](iscaling3d.html)  
o3d_MirrorPart | 532 | Зеркальная деталь, с внешней ссылкой на источник (зеркальная вставка детали заготовки) |  | [IBilletObsolete](ibilletobsolete.html)  
o3d_sheetMetalUndercut | 533 | Листовой металл, операция подсечка |  | [ISheetMetalUndercut](isheetmetalundercut.html)  
o3d_sheetMetalPlate | 534 | Листовой металл, операция пластина |  | [ISheetMetalPlate](isheetmetalplate.html)  
o3d_sheetMetalCombinedBend | 535 | Листовой металл, операция комбинированный сгиб, - cгиб по эскизу |  | [ISheetMetalSketchBend](isheetmetalsketchbend.html)  
o3d_sheetMetalBendStraighten | 536 | Листовой металл, операция разогнуть |  | [ISheetMetalBendedStraighten](isheetmetalbendedstraighten.html)  
o3d_sheetMetalBendBended | 537 | Листовой металл, операция согнуть |  | [ISheetMetalBendedStraighten](isheetmetalbendedstraighten.html)  
o3d_sheetMetalBendUnfold | 538 | Листовой металл, операция развертка |  | [ISheetMetalBendUnfoldParameters](isheetmetalbendunfoldparameters.html)  
o3d_sheetMetalClosedCorner | 539 | Листовой металл, операция 'замыкание углов' |  | [ISheetMetalClosedCorner](isheetmetalclosedcorner.html)  
o3d_sheetMetalBendObject | 540 | Листовой металл, сгибы листовых операций |  | [IModelObject](imodelobject.html)  
o3d_sheetMetalDimpleCutout | 541 | Листовой металл, закрытая штамповка |  | [ISheetMetalPressForming](isheetmetalpressforming.html)  
o3d_sheetMetalDrawnCutout | 542 | Листовой металл, открытая штамповка |  | [ISheetMetalPressForming](isheetmetalpressforming.html)  
o3d_sheetMetalBeat | 543 | Листовой металл, буртик |  | [ISheetMetalShoulder](isheetmetalshoulder.html)  
o3d_sheetMetalLouver | 544 | Листовой металл, жалюзи |  | [ISheetMetalJalousie](isheetmetaljalousie.html)  
o3d_sheetMetalCowling | 545 | Обечайка |  | [ISheetMetalRuledShell](isheetmetalruledshell.html)  
o3d_PointsArrOnCurve | 546 | Группа точек по кривой |  | [IPointsArrOnCurve](ipointsarroncurve.html)  
o3d_PointsArrFromFile | 547 | Группа точек из файла |  | [IPointsArrFromFile](ipointsarrfromfile.html)  
o3d_PointsArrOnSurface | 548 | Группа точек на поверхности |  | [IPointsArrOnSurface](ipointsarronsurface.html)  
o3d_ArrayExemplar | 549 | Экземпляр массива |  | [IModelObject](imodelobject.html)  
o3d_AuxGeomArrayExemplar | 550 | Экземпляр массива вспомогательной геометрии |  | [IModelObject](imodelobject.html)  
o3d_BodyArrayExemplar | 551 | Экземпляр массива копирования тел |  | [IModelObject](imodelobject.html)  
o3d_NurbsSurfaceByCurvesMesh | 552 | Сплайновая поверхность по сетке кривых |  | [INurbsSurfacesByCurvesMeshs](inurbssurfacesbycurvesmeshs.html)  
o3d_PlaneByPointAndTangentToFace | 553 | Конструктивная касательная плоскость к грани в точке |  | [IPlane3DTangentToFaceInPoint](iplane3dtangenttofaceinpoint.html)  
o3d_PlaneByPlaneCurve | 554 | Конструктивная касательная плоскость через плоскую кривую |  | [IPlane3DByPlaneCurve](iplane3dbyplanecurve.html)  
o3d_JointSurface | 555 | Поверхность соединения |  | [IJointSurface](ijointsurface.html)  
o3d_DistanceAngleMeasure | 556 | Объект 'Измерение расстояния и угла' |  | [IDistanceAngleMeasurement3D](idistanceanglemeasurement3d.html)  
o3d_EdgeLengthMeasure | 557 | Объект 'Измерение длины ребра' |  | [IEdgeLengthMeasurement3D](iedgelengthmeasurement3d.html)  
o3d_AreaMeasure | 558 | Объект 'Измерение площади' |  | [IAreaMeasurement3D](iareameasurement3d.html)  
o3d_AxisFromPointByDirection | 559 | Ось через вершину по направлению |  | [IAxis3DByPointAndObject](iaxis3dbypointandobject.html)  
o3d_Curve3DWithoutHistory | 560 | Кривая без истории |  | [IUnhistoredCurve3D](iunhistoredcurve3d.html)  
o3d_CurveBy2Projections | 561 | Кривая по двум проекциям |  | [ICurveBy2Projections](icurveby2projections.html)  
o3d_CurveByLaw | 562 | Кривая по закону |  | [ICurveByLaw](icurvebylaw.html)  
o3d_IsoparametricCurve | 563 | Изопараметрическая кривая |  | [IIsoparametricCurve](iisoparametriccurve.html)  
o3d_CurveOutLine | 564 | Линия очерка |  | [ICurveOutLine](icurveoutline.html)  
o3d_SplineOnSurface | 565 | Сплайн на поверхности |  | [ISplineOnSurface](isplineonsurface.html)  
o3d_IsoparametricCurvesSet | 566 | Группа изопараметрических кривых |  | [IIsoparametricCurvesSet](iisoparametriccurvesset.html)  
o3d_ProjectionCurve | 567 | Проекционная кривая |  | [IProjectionCurve](iprojectioncurve.html)  
o3d_Contour3D | 568 | Контур 3D |  | [IContour3D](icontour3d.html)  
o3d_BodyReposition | 569 | Перепозиционирование тела, поверхности |  | [IBodyReposition](ibodyreposition.html)  
o3d_LineSegment3D | 570 | Отрезок 3D |  | [ILineSegment3D](ilinesegment3d.html)  
o3d_Billet | 571 | Операция 'деталь заготовка' |  | [IBilletObsolete](ibilletobsolete.html)  
o3d_PolyLine3DPoint | 572 | Точка ломаной и сплайна |  | [IModelObject](imodelobject.html)  
o3d_OperationLinearDimension | 573 | Управляющий линейный размер операции 3D |  | [IBaseLineDimension3D](ibaselinedimension3d.html)  
o3d_OperationAngularDimension | 574 | Управляющий угловой размер операции 3D |  | [IAngleDimension3D](iangledimension3d.html)  
o3d_OperationRadialDimension | 575 | Управляющий радиальный размер операции 3D |  | [IRadialDimension3D](iradialdimension3d.html)  
o3d_OperationDiametralDimension | 576 | Управляющий диаметральный размер операции 3D |  | [IDiametralDimension3D](idiametraldimension3d.html)  
o3d_SketchLinearDimension | 577 | Управляющий линейный размер эскиза 3D |  | [IBaseLineDimension3D](ibaselinedimension3d.html)  
o3d_SketchAngularDimension | 578 | Управляющий угловой размер эскиза 3D |  | [IAngleDimension3D](iangledimension3d.html)  
o3d_SketchBreakAngularDimension | 579 | Управляющий угловой размер эскиза 3D с обрывом |  | [IAngleDimension3D](iangledimension3d.html)  
o3d_SketchRadialDimension | 580 | Управляющий радиальный размер эскиза 3D |  | [IRadialDimension3D](iradialdimension3d.html)  
o3d_SketchBreakRadialDimension | 581 | Управляющий радиальный размер эскиза 3D с обрывом |  | [IRadialDimension3D](iradialdimension3d.html)  
o3d_SketchDiametralDimension | 582 | Управляющий диаметральный размер эскиза 3D |  | [IDiametralDimension3D](idiametraldimension3d.html)  
o3d_Hole3D | 583 | Отверстие 3D |  | [IHole3D](ihole3d.html)  
o3d_UserObjectOperation | 584 | Пользовательская многотельная операция |  | [IUserObject3D](iuserobject3d.html)  
o3d_Zone3D | 585 | Зона 3D |  | [IZone](izone.html)  
o3d_Zone3DDivision | 586 | Разбиение зон |  | [IZoneDivision](izonedivision.html)  
o3d_Zones3D | 587 | Группа Зоны 3D |  | [IZonesManager](izonesmanager.html)  
o3d_WireFrame3D | 588 | Трехмерный каркас |  |   
o3d_CopyGeometry | 589 | Копия геометрии |  | [ICopyGeometry](icopygeometry.html)  
o3d_CollectionGeometry | 590 | Коллекция геометрии |  | [ICollectionGeometry](icollectiongeometry.html)  
o3d_MeshPatternAnyCopy | 591 | Копирование произвольных объектов по сетке |  | [ILinearPattern](ilinearpattern.html)  
o3d_CircularPatternAnyCopy | 592 | Копирование произвольных объектов по окружности |  | [ICircularPattern](icircularpattern.html)  
o3d_CurvePatternAnyCopy | 593 | Копирование произвольных объектов по кривой |  | [IPathPattern](ipathpattern.html)  
o3d_PointDrivenPatternAnyCopy | 595 | Копирование произвольных объектов по точкам |  | [IPointDrivenPattern](ipointdrivenpattern.html)  
o3d_TablePatternAnyCopy | 596 | Копирование произвольных объектов по таблице |  | [ITablePattern](itablepattern.html)  
o3d_LinearUnhistoriedDimension | 597 | Импортированный линейный размер |  | [IBaseLineDimension3D](ibaselinedimension3d.html)  
o3d_AngularUnhistoriedDimension | 598 | Импортированный угловой размер |  | [IAngleDimension3D](iangledimension3d.html)  
o3d_RadialUnhistoriedDimension | 599 | Импортированный радиальный размер |  | [IRadialDimension3D](iradialdimension3d.html)  
o3d_DiametralUnhistoriedDimension | 600 | Импортированный диаметральный размер |  | [IDiametralDimension3D](idiametraldimension3d.html)  
o3d_FaceLift | 601 | Операция подтягивания граней |  | [IModelObject](imodelobject.html)  
o3d_UserWireFrame3D | 602 | Трехмерный каркас - пользовательский объект |  | [IUserObject3D](iuserobject3d.html)  
o3d_UndefPartObject | 603 | Модельный объект неопределенного типа |  | [IModelObject](imodelobject.html)  
o3d_SpecRough3D | 604 | Неуказанная шероховатость 3D |  | [ISpecRough3D](ispecrough3d.html)  
o3d_SketchBreakLinearDimension | 605 | Управляющий линейный размер эскиза 3D с обрывом |  | [IBaseLineDimension3D](ibaselinedimension3d.html)  
o3d_sheetMetalRuledCowling | 606 | Линейчатая обечайка |  | [ISheetMetalLinearRuledShell](isheetmetallinearruledshell.html), [ISheetMetalRuledShell](isheetmetalruledshell.html)  
o3d_UserDesignationObject3D | 607 | Пользовательский объект обозначение 3D |  | [IUserObject3D](iuserobject3d.html)  
o3d_SplineFormOperation | 608 | Операция прямого редактирования |  |   
o3d_UnhistoriedBase3D | 609 | База без истории |  | [IBase3D](ibase3d.html)  
o3d_UnhistoriedThread | 610 | Резьба без истории |  | [IModelObject](imodelobject.html)  
o3d_UserDesignationCompObj | 611 | Составной объект для пользовательских объектов обозначений 3D |  | [IUserObject3D](iuserobject3d.html)  
o3d_UserFolder | 612 | Пользовательская директория 3D |  | [IUserObject3D](iuserobject3d.html)  
o3d_MeshObject3D | 613 | Полигональный объект 3D |  | [IMeshObject3D](imeshobject3d.html)  
o3d_sheetMetalRib | 614 | Ребро усиления |  | [ISheetMetalRib](isheetmetalrib.html)  
o3d_axis3D | 615 | Ось 3D |  | [IAxis3D](iaxis3d.html)  
o3d_SubFoldLine | 616 | Подобъект Линия сгиба |  | [IModelObject](imodelobject.html)  
o3d_OperationLeaderDimension | 617 | Управляющий размер операции в виде линии выноски |  | [IBaseLeader3D](ibaseleader3d.html)  
o3d_FullFillet | 618 | Полное скругление |  | [IFullFillet](ifullfillet.html)  
o3d_DynamicCrossSection | 619 | Динамическое сечение |  | [IDynamicCrossSection](idynamiccrosssection.html)  
o3d_RestoredSurface | 620 | Восстановленная поверхность |  | [IRestoredSurface](irestoredsurface.html)  
o3d_CurvatureGraph | 621 | График кривизны |  |   
o3d_CollisionObject | 622 | Информация о коллизии |  |   
o3d_CurvatureCheckObject | 623 | Проверка кривизны |  |   
o3d_ContinuityCheck | 624 | Проверка непрерывности |  |   
o3d_SketchFace | 625 | Контур эскиза |  |   
o3d_SectionAnalysis | 626 | Сетка графиков кривизны |  |   
o3d_Text3D | 627 | Надпись 3D |  |   
o3d_SketchArcDimension | 628 | Управляющий размер дуги окружности эскиза 3D |  |   
o3d_ArcDimension3D | 629 | Размер дуги окружности 3D |  |   
o3d_sheetMetalPunch | 630 | Листовой металл, штамповка телом |  |   
o3d_sheetMetalFlanging | 631 | Листовой металл, отбортовка |  |   
o3d_FaceMover | 632 | Операция переместить грани |  |   
o3d_SplitSolid | 633 | Операция Разрезать |  |   
o3d_sheetMetalConvertFromBody | 634 | Операция Преобразования в листовое тело |  |   
o3d_ConicSectionSurface | 635 | Поверхность конического сечения |  |   
o3d_TechnicalDemand3D | 636 | Технические требования 3D |  |  [ITechnicalDemand3D](itechnicaldemand3d.html)  
o3d_ModelText | 637 | Текст в модели |  | [IModelText](imodeltext.html)  
o3d_ModelTable | 638 | Таблица в модели |  | [IModelTable](imodeltable.html)  
o3d_ConicCurve3D | 639 | Коническая 3D кривая |  |   
o3d_ExtensionCurve | 640 | Продление кривой |  |   
o3d_WrapCurve  | 641 | Свернутая кривая |  |   
o3d_UnwrapCurve | 642 | Развернутая кривая. |  |   
o3d_PlaneUnhistoried | 643 | Плоскость без истории |  |   
o3d_DraftFromEdges | 644 | Операция "Уклон от базовой линии" |  |   
o3d_MultiSpline | 645 | Ассоциативный сплайн по объектам |  |   
o3d_BodySurfaceRemover | 646 | Операция удаления тел и поверхностей |  |   
o3d_UserComponentOperation | 647 | Пользовательская операция над вставками |  |   
o3d_FilletChanger | 648 | Изменить размер скругления |  |   
o3d_CurvatureGraphs | 649 | Папка Графиков кривизны |  |   
o3d_Diagnostic | 650 | Диагностика |  |   
o3d_CurvatureCheckObjects | 651 | Папка Проверки кривизны |  |   
o3d_ContinuityCheckGroup | 655 | Папка Проверки непрерывности |  |   
o3d_CollisionCheck | 656 | Папка Проверки коллизий |  |   
o3d_MutualDeviationFolder | 657 | Папка взаимного отклонения |  |   
o3d_MutualDeviation | 658 | Взаимное отклонение |  |   
o3d_FaceReplacer | 659 | Заменить грани |  |   
o3d_FaceResizer | 660 | Изменить размер грани |  |   
o3d_Deviation | 661 | Отклонение |  |   
o3d_Sphere | 662 | Сфера |  |   
o3d_Cylinder | 663 | Цилиндр |  |   
o3d_Block | 664 | Параллелепипед |  |   
o3d_FilletSurface | 665 | Поверхность скругления |  |   
o3d_ExternalReference | 667 | Внешняя ссылка |  |   
o3d_lastEntityElement2 | 1500 | Всегда последний из Entity2!!! |  |   
  
Подразделы:

(отсутствуют)
