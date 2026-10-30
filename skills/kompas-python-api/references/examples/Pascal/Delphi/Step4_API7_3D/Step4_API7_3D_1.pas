////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения объектов 3D
//
////////////////////////////////////////////////////////////////////////////////
unit Step4_API7_3D_1;

interface
uses
  Sysutils,
  LDefin2D,
  ksAuto,
  Libtool,
  ks3DCOM_TLB,
  LDefin3D,
  LTool3D,
  ksApi7,
  Windows
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  , Variants
{$IFEND}
{$ENDIF CONDITIONALEXPRESSIONS}

  ;

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  procedure  GetNewKompasAPI;
  procedure  CreateAndEditPointDrivenPattern( doc : IKompasDocument );
  procedure  CreateAndEditCircularPattern   ( doc : IKompasDocument );
  procedure  CreateAndEditMirrorPattern     ( doc : IKompasDocument );
  procedure  CreateAndEditExtrusionSurface  ( doc : IKompasDocument );
  procedure  CreateAndEditMeshPointSurface  ( doc : IKompasDocument );
  procedure  CreateAndEditFilletCurve       ( doc : IKompasDocument );

implementation

uses
  LtDefine,
  //ksApi7,
  ksConstTLB,
  forms;

const
  IDS_NODOC = 200;
  IDS_EDIT  = 201;

var
  newKompasAPI  : IApplication;        // Компас Application 7


//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;


//----------------------------------------------------------------------------------------------
// Загрузить строку из ресурсов
//---
function LoadStr( ID : Integer ) : WideString;
var
  buf : array [0..255] of WChar;
begin
  ksConvertLangStrExW( hInstance, ID, buf, 255 );
  Result := buf;
end;


//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;

var
  mes : WideString;
  doc : IKompasDocument;
begin
  Application.Handle := GetHWindow;
  GetNewKompasAPI;
  doc := newKompasAPI.ActiveDocument;

  if ( doc <> nil ) then
  begin
    case command of
       1: CreateAndEditPointDrivenPattern( doc );
       2: CreateAndEditCircularPattern   ( doc );
       3: CreateAndEditMirrorPattern     ( doc );
       4: CreateAndEditExtrusionSurface  ( doc );
       5: CreateAndEditMeshPointSurface  ( doc );
       6: CreateAndEditFilletCurve       ( doc );
    end;
    newKompasAPI := nil;
  end
  else
  begin
    mes := LoadStr( IDS_NODOC );
    ksMessageW( PWideChar(mes) );
  end;
end;


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    newKompasAPI := disp As IApplication;
  end;
end;


//------------------------------------------------------------------------------
// Получить контейнер модельных объектов
// ---
function GetModelContainer( doc : IKompasDocument ) : IModelContainer;
var
  doc3d : IKompasDocument3D;
  part7 : IPart7;
begin
  Result := nil;

  if doc <> nil then
  begin
    // Получаем документ 3D
    doc3d := doc As IKompasDocument3D;

    if doc3d <> nil then
    begin
      // Получаем верхний компонент
      part7 := doc3d.TopPart;

      if part7 <> nil then
        // Получаем контейнер модельных объектов
        Result := part7 As IModelContainer;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Получить интерфейс контейнера поверхностей
// ---
function GetSurfaceContainer( doc : IKompasDocument ) : ISurfaceContainer;
var
  doc3d : IKompasDocument3D;
  part7 : IPart7;
begin
  Result := nil;

  if doc <> nil then
  begin
    // Получаем документ 3D
    doc3d := doc As IKompasDocument3D;

    if doc3d <> nil then
    begin
      // Получаем верхний компонент
      part7 := doc3d.TopPart;

      if part7 <> nil then
        Result := part7 As ISurfaceContainer;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Получить интерфейс контейнера вспомогательной геометрии
// ---
function GetAuxiliaryGeomContainer( doc : IKompasDocument ) : IAuxiliaryGeomContainer;
var
  doc3d : IKompasDocument3D;
  part7 : IPart7;
begin
  Result := nil;

  if doc <> nil then
  begin
    // Получаем документ 3D
    doc3d := doc As IKompasDocument3D;

    if doc3d <> nil then
    begin
      // Получаем верхний компонент
      part7 := doc3d.TopPart;

      if part7 <> nil then
        Result := part7 As IAuxiliaryGeomContainer;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создать эскиз в виде прямоугольника
// ---
function CreateSketch( doc : IKompasDocument; x, y, h, w : double ) : ISketch;
var
  modelCont : IModelContainer;
  sketchs   : ISketchs;
  sketch    : ISketch;
  part      : IPart7;
  planeXY   : IModelObject;
  par       : RectangleParam;
  doc3d     : IKompasDocument3D;
begin
  sketch := nil;
  modelCont := GetModelContainer( doc );

  if modelCont <> nil then
  begin
    // Получаем коллекцию эскзиов
    sketchs := modelCont.Sketchs;

    if sketchs <> nil then
    begin
      // Добавляем новый эскиз
      sketch := sketchs.Add;

      if sketch <> nil then
      begin
        // Получаем документ 3D
        doc3d := doc As IKompasDocument3D;

        if doc3d <> nil then
        begin
          // Получаем верхнюю деталь
          part := doc3d.TopPart;

          if part <> nil then
          begin
            // Получаем плоскость XY
            planeXY := part.DefaultObject[o3d_planeXOY];

            // Задаем базовую плоскость для эскиза
            if planeXY <> nil then
              sketch.Plane := planeXY;

            // Редактируем эскиз
            sketch.BeginEdit;
            // Строим прямоугольник
            FillChar(par, sizeof(par), 0 );
            par.x := x;
            par.y := y;
            par.height := h;
            par.weight := w;
            par.style := ksCSNormal;
            ksRectangle( @par, 0{без осей} );
            sketch.EndEdit;
          end;
        end;
        sketch.Update;
      end;
    end;
  end;
  Result := sketch;
end;


//------------------------------------------------------------------------------
// Создать операцию выдавливания
// ---
function CreateExtrusion( doc : IKompasDocument ) : IExtrusion;
var
  newExtr    : IExtrusion;
  extrusions : IExtrusions;
  modelCont  : IModelContainer;
  sketch     : ISketch;
begin
  newExtr := nil;

  if doc <> nil then
  begin
    // Получаем контейнер модельных объектов
    modelCont := GetModelContainer( doc );

    if modelCont <> nil then
    begin
      // Получаем коллекцию операций выдавливания
      extrusions := modelCont.Extrusions;

      if extrusions <> nil then
      begin
        // Добавляем новую операцию выдавливания
        newExtr := extrusions.Add( o3d_bossExtrusion );

        if newExtr <> nil then
        begin
          // Создаем эскиз для построения операции
          sketch := CreateSketch(doc, 0, 0, 25, 25);

          if sketch <> nil then
            newExtr.Sketch := sketch;

          // Задаем параметры операции
          newExtr.Depth[ true ] := 10;
          newExtr.Direction := dtNormal;
          newExtr.ExtrusionType[ true ] := etBlind;
          newExtr.Update;
        end;
      end;
    end;
  end;
  Result := newExtr;
end;


//------------------------------------------------------------------------------
// Создать точку
// ---
function CreatePoint( doc : IKompasDocument; x, y, z : double ) : IPoint3D;
var
  modelCont  : IModelContainer;
  pointsColl : IPoints3D;
  newPoint   : IPoint3D;
begin
  newPoint := nil;

  if doc <> nil then
  begin
    // Получаем контейнер модельных объектов
    modelCont := GetModelContainer( doc );

    if modelCont <> nil then
    begin
      // Получаем коллекцию точек
      pointsColl := modelCont.Points3D;

      if pointsColl <> nil then
      begin
        // Добавляем новую точку
        newPoint := pointsColl.Add;

        if newPoint <> nil then
        begin
          // Задаем параметры точки
          newPoint.X := x;
          newPoint.Y := y;
          newPoint.Z := z;
          newPoint.Symbol := ksDotPoint;
          newPoint.ParameterType := ksPParamCoord;
          newPoint.Update;
        end;
      end;
    end;
  end;
  Result := newPoint;
end;


//------------------------------------------------------------------------------
// Создать ломаную из одного сегмента
// ---
function CreatePolyLine( doc : IKompasDocument;
                         x1, y1, z1, x2, y2, z2 : double ) : IPolyLine;
var
  polyLine : IPolyLine;
  geomCont : IAuxiliaryGeomContainer;
  coll     : IPolyLines;
  vertex1,
  vertex2  : ICurveVertexParam;
begin
  polyLine := nil;

  if doc <> nil then
  begin
    // Получаем контейнер вспомогательной геометрии
    geomCont := GetAuxiliaryGeomContainer( doc );

    if geomCont <> nil then
    begin
      // Получаем коллекцию ломаных
      coll := geomCont.PolyLines;

      if coll <> nil then
      begin
        // Добавляем ломаную в коллекцию
        polyLine := coll.Add;

        if polyLine <> nil then
        begin
          // Создаем вершины ломаной
          vertex1 := polyLine.AddVertex( -1 );

          if vertex1 <> nil then
            vertex1.SetParamVertex( x1, y1, z1, 1 );

          vertex2 := polyLine.AddVertex( -1 );

          if vertex2 <> nil then
            vertex2.SetParamVertex( x2, y2, z2, 1 );

          polyLine.Update;
        end;
      end;
    end;
  end;
  Result := polyLine;
end;


//------------------------------------------------------------------------------
// Создание и редактирование массива по точкам
// ---
procedure CreateAndEditPointDrivenPattern( doc : IKompasDocument );
var
  modelCont   : IModelContainer;
  patternsCol : IFeaturePatterns;
  newPattern,
  pattern     : IPointDrivenPattern;
  iniObj      : IModelObject;
  point1,
  point2,
  point3      : IPoint3D;
  pointsArr,
  indexArr    : OleVariant;
begin
  if doc <> nil then
  begin
    // Получаем контейнер модельных объектов
    modelCont := GetModelContainer( doc );

    if modelCont <> nil then
    begin
      // Получаем коллекцию массивов
      patternsCol := modelCont.FeaturePatterns;

      if patternsCol <> nil then
      begin
        // Добавляем новую операцию копирования по точкам
        newPattern := patternsCol.Add( o3d_PointDrivenPattern{массив операций} ) As IPointDrivenPattern;

        if newPattern <> nil then
        begin
          // Создаем исходный объект для массива - операцию выдавливания
          iniObj := CreateExtrusion( doc );
          // Создаем точки для построения массива
          point1 := CreatePoint( doc, 27, -39, 13 );
          point2 := CreatePoint( doc, -16, -15, 31 );
          point3 := CreatePoint( doc, -41, 35, 6 );

          if ( iniObj <> nil) And ( point1 <> nil ) And ( point2 <> nil ) And ( point3 <> nil ) then
          begin
            // Устанавливаем исходный объект массива
            newPattern.InitialObjects := iniObj;

            // Проверяем пригодность точек для операции
            if newPattern.IsSuitableDrivenObject( point1 ) And
               newPattern.IsSuitableDrivenObject( point2 ) And
               newPattern.IsSuitableDrivenObject( point3 ) then
            begin
              // Создаем массив точек
              pointsArr := VarArrayCreate( [0, 2], varDispatch );
              pointsArr[0] := point1;
              pointsArr[1] := point2;
              pointsArr[2] := point3;
              // Задаем массив управляющих объектов
              newPattern.DrivenObjects := pointsArr;
            end;
            newPattern.Update;
          end;
        end;
        // Редактирование массива
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем массив из коллекции
          pattern := patternsCol.FeaturePattern[ 0 ] As IPointDrivenPattern;

          if pattern <> nil then
          begin
            // Создаем массив индексов удаляемых элементов
            indexArr := VarArrayCreate( [0, 1], varInteger );
            indexArr[0] := 2;
            indexArr[1] := 0;
            // Удаляем элемент
            pattern.InstanceDeletedIndexes := indexArr;
            pattern.Update;
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создание и редактирование массива по концентрической сетке
// ---
procedure CreateAndEditCircularPattern( doc : IKompasDocument );
var
  modelCont   : IModelContainer;
  patternsCol : IFeaturePatterns;
  newPattern,
  pattern     : ICircularPattern;
  iniObj,
  axisOZ      : IModelObject;
  doc3d       : IKompasDocument3D;
  part7       : IPart7;
begin
  if doc <> nil then
  begin
    // Получаем контейнер модельных объектов
    modelCont := GetModelContainer( doc );

    if modelCont <> nil then
    begin
      // Получаем коллекцию массивов
      // Получаем коллекцию массивов
      patternsCol := modelCont.FeaturePatterns;

      if patternsCol <> nil then
      begin
        // Добавляем новую операцию копирования по концентрической сетке
        newPattern := patternsCol.Add( o3d_circularCopy{массив операций} ) As ICircularPattern;

        if newPattern <> nil then
        begin
          // Создаем исходный объект для массива - операцию выдавливания
          iniObj := CreateExtrusion( doc );

          if iniObj <> nil then
          begin
            newPattern.InitialObjects := iniObj;
            // Шаг копирования в кольцевом направлении
            newPattern.Step2 := 360;
            // Количество экземпляров в кольцевом направлении
            newPattern.Count2 := 6;
            // Шаг между крайними экземплярами
            newPattern.BoundaryInstancesStepFactor2 := TRUE;

            // Ось массива
            doc3d := doc As IKompasDocument3D;

            if doc3d <> nil then
            begin
              part7 := doc3d.TopPart;

              if part7 <> nil then
              begin
                axisOZ := part7.DefaultObject[ o3d_axisOZ ];

                if axisOZ <> nil then
                  newPattern.Axis := axisOZ;
              end;
            end;
            newPattern.Update;
          end;
        end;
        // Редактируем
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем массив из коллекции
          pattern := patternsCol.FeaturePattern[ 0 ] As ICircularPattern;

          if pattern <> nil then
          begin
            // Шаг копирования в радиальном направлении
            pattern.Step1 := 10;
            // Количество экземпляров в радиальном направлении
            pattern.Count1 := 5;
            // Исходная ориентация
            pattern.SaveInitialOrientation := true;
            pattern.Update;
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создание и редактирование зеркального массива
// ---
procedure CreateAndEditMirrorPattern( doc : IKompasDocument );
var
  doc3d       : IKompasDocument3D;
  modelCont   : IModelContainer;
  patternsCol : IFeaturePatterns;
  part7       : IPart7;
  newPattern,
  pattern     : IMirrorPattern;
  iniObj,
  planeXY,
  planeXZ     : IModelObject;
begin
  if doc <> nil then
  begin
    doc3d := doc As IKompasDocument3D;
    // Получаем контейнер модельных объектов
    modelCont := GetModelContainer( doc );

    if ( doc3d <> nil ) And ( modelCont <> nil ) then
    begin
      // Получаем коллекцию массивов
      patternsCol := modelCont.FeaturePatterns;
      part7 := doc3d.TopPart;

      if ( patternsCol <> nil ) And ( part7 <> nil ) then
      begin
        // Добавляем новый зеркальный массив
        newPattern := patternsCol.Add( o3d_mirrorOperation{массив операций} ) As IMirrorPattern;

        if newPattern <> nil then
        begin
          // Создаем исходный объект для массива - операцию выдавливания
          iniObj := CreateExtrusion( doc );

          if iniObj <> nil then
          begin
            // Устанавливаем исходный объект массива
            newPattern.InitialObjects := iniObj;
            // Получаем плоскость симметрии
            planeXY := part7.DefaultObject[ o3d_planeXOY ];

            if planeXY <> nil then
              newPattern.Plane := planeXY;

            // Оставлять исходные объекты
            newPattern.SaveInitialObjects := TRUE;
            newPattern.Update;
          end;
        end;
        // Редактируем
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем массив из коллекции
          pattern := patternsCol.FeaturePattern[ 0 ] As IMirrorPattern;

          if pattern <> nil then
          begin
            // Меняем плоскость симметрии
            planeXZ := part7.DefaultObject[ o3d_planeXOZ ];

            if planeXZ <> nil then
              pattern.Plane := planeXZ;

            pattern.Update;
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создание и редактирование поверхности выдавливания
// ---
procedure CreateAndEditExtrusionSurface( doc : IKompasDocument );
var
  surfCont  : ISurfaceContainer;
  extrCol   : IExtrusions;
  newSurface,
  surface   : IExtrusionSurface;
  surface1  : IExtrusion1;
  sketch    : ISketch;
begin
  if doc <> nil then
  begin
    // Получаем контейнер поверхностей
    surfCont := GetSurfaceContainer( doc );

    if surfCont <> nil then
    begin
      // Получаем коллекцию поверхностей выдавливания
      extrCol := surfCont.ExtrusionSurfaces;

      if extrCol <> nil then
      begin
        // Добавляем новую поверхность выдавливания
        newSurface := extrCol.Add( o3d_ExtrusionSurface ) As IExtrusionSurface;
        surface1 := newSurface As IExtrusion1;
        if surface1 <> nil then
        begin
          // Создаем эскиз
          sketch := CreateSketch( doc, -25, -40, 40, 40 );

          if sketch <> nil then
          begin
            // Сечение
            surface1.Profile := sketch;
            // Направляющий объект
            surface1.DirectionObject := sketch;
            // Глубина
            newSurface.Depth[ true ] := 10;
            // Признак замкнутости поверхности
            newSurface.ClosedShell := true;
            newSurface.Update;
          end;
        end;
        // Редактируем
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем поверхность выдавливания из коллекции
          surface := extrCol.Extrusion[0] As IExtrusionSurface;

          if surface <> nil then
          begin
            // Уклон внутрь
            surface.DraftOutward[true] := true;
            // Угол уклона
            surface.DraftValue[true] := 15;
            // Глубина
            surface.Depth[true] := 30;
            // Признак замкнутости поверхности
            surface.ClosedShell := false;
            surface.Update();
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создание и редактирование поверхности по сети точек
// ---
procedure CreateAndEditMeshPointSurface( doc : IKompasDocument );
var
  surfCont  : ISurfaceContainer;
  meshCol   : IMeshPointsSurfaces;
  newSurface,
  surface   : IMeshPointsSurface;
  points,
  weights   : OleVariant;
begin
  if doc <> nil then
  begin
    // Получаем контейнер поверхностей
    surfCont := GetSurfaceContainer( doc );

    if surfCont <> nil then
    begin
      // Получаем коллекцию поверхностей по сети точек
      meshCol := surfCont.MeshPointsSurfaces;

      if meshCol <> nil then
      begin
        // Добавляем новую поверхность по сети точек
        newSurface := meshCol.Add;

        if newSurface <> nil then
        begin
          with newSurface do
          begin
            // 1-й ряд точек
            BeginPointsSeries( true, -1 );
            AddPoint( 39, -62, 23, 1, ksPParamCoord, nil );
            AddPoint( 18, -40, 22, 1, ksPParamCoord, nil );
            AddPoint( -13, -24, 37, 1, ksPParamCoord, nil );
            EndPointsSeries;
            // 2-й ряд точек
            BeginPointsSeries( true, -1 );
            AddPoint( 56, -52, -4, 1, ksPParamCoord, nil );
            AddPoint( 28, -21, 7, 1, ksPParamCoord, nil );
            AddPoint( 1, -11, 10, 1, ksPParamCoord, nil );
            EndPointsSeries;
            Update;
          end;
        end;
        // Редактируем
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем поверхность по сети точек из коллекции
          surface := meshCol.MeshPointsSurface[0];

          if surface <> nil then
          begin
            points := VarArrayCreate( [0, 8], varDouble );
            points[0] := 73;
            points[1] := -59;
            points[2] := -14;
            points[3] := 56;
            points[4] := -41;
            points[5] := -15;
            points[6] := 30;
            points[7] := -18;
            points[8] := -13;

            weights := VarArrayCreate( [0, 2], varDouble );
            weights[0] := 1;
            weights[1] := 3;
            weights[2] := 3;

            // Добавляем ряд точек
            surface.AddPointsSeries( true, -1, points, weights );
            surface.Update;
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создание и редактирование операции скругления кривых
// ---
procedure CreateAndEditFilletCurve( doc : IKompasDocument );
var
  auxCont   : IAuxiliaryGeomContainer;
  filletCol : IFilletCurves;
  newFillet,
  fillet    : IFilletCurve;
  polyLine1,
  polyLine2 : IPolyLine;
begin
  if doc <> nil then
  begin
    // Получаем контейнер вспомогательной геометрии
    auxCont := GetAuxiliaryGeomContainer( doc );

    if auxCont <> nil then
    begin
      // Получаем коллекцию операций скругления кривых
      filletCol := auxCont.FilletCurves;

      if filletCol <> nil then
      begin
        // Добавляем новую операцию скругления
        newFillet := filletCol.Add;

        if newFillet <> nil then
        begin
          // Создаем кривые
          polyLine1 := CreatePolyLine( doc, 36, -37, 55, 36, -37, 1 );
          polyLine2 := CreatePolyLine( doc, 36, -37, 1, -5, -37, 1 );

          if ( polyLine1 <> nil ) And ( polyLine2 <> nil ) then
          begin
            with newFillet do
            begin
              // Задаем кривые
              Curve1 := polyLine1;
              Curve2 := polyLine2;
              // Радиус дуги скругления
              Radius := 10;
              Update;
            end;
          end;
        end;
        // Редактируем
        if YesNoW( PWideChar(LoadStr(IDS_EDIT)) ) = 1 then
        begin
          // Получаем операцию скругления из коллекции
          fillet := filletCol.FilletCurve[0];

          if fillet <> nil then
          begin
            with fillet do
            begin
              // Направление дуги скругления - обратное
              Direction := FALSE;
              // Радиус дуги скругления
              Radius := 25;
              Update;
            end;
          end;
        end;
      end;
    end;
  end;
end;

end.
