unit step3d31;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;

implementation
uses
  Windows,
  SysUtils,
  LDefin2D,
  LDefin3D,
  ksConstTLB,
  ksAuto,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

var
  iKompasObject: KompasObject;
  iDocument3D: ksDocument3D;

//------------------------------------------------------------------------
// конструктивная ось операции
// ---
procedure ConstrAxisOperations;
var
  part                : ksPart;
  entitySketch        : ksEntity;
  sketchDef           : ksSketchDefinition;
  basePlane           : ksEntity;
  sketchEdit          : ksDocument2D;
  entityRotate        : ksEntity;
  rotateDef           : ksBossRotatedDefinition;
  rotproperty         : ksRotatedParam;
  entityAxisOperation : ksEntity;
  axisOperation       : ksAxisOperationsDefinition;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
    entitySketch := ksEntity( part.NewEntity(o3d_sketch) );
		if ( entitySketch <> nil ) then begin
			// интерфейс свойств эскиза
			sketchDef := ksSketchDefinition( entitySketch.GetDefinition );
			if ( sketchDef <> nil ) then begin
				// получим интерфейс базовой плоскости XOY
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				sketchDef.SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
				entitySketch.Create;             // создадим эскиз

				// интерфейс редактора эскиза
				sketchEdit := ksDocument2D( sketchDef.BeginEdit );
          sketchEdit.ksCircle( 20, 0, 10, 1 );
					sketchEdit.ksLineSeg( 0, 0, 0, 5, 3 );
				sketchDef.EndEdit;                   // завершение редактирования эскиза

				entityRotate := ksEntity( part.NewEntity(o3d_bossRotated) );
				if ( entityRotate <> nil ) then begin
					rotateDef := ksBossRotatedDefinition( entityRotate.GetDefinition ); // интерфейс базовой операции вращения
					if ( rotateDef <> nil ) then begin
     				rotproperty := ksRotatedParam( rotateDef.RotatedParam );
						if ( rotproperty <> nil ) then begin
							rotproperty.Direction := dtBoth;
              rotproperty.ToroidShape  := false;
						end;

						rotateDef.SetThinParam( true, dtBoth, 1, 1 ); // тонкая стенка в два направления
						rotateDef.SetSideParam( true, 180 );
						rotateDef.SetSketch( entitySketch );          // эскиз операции вращения
						entityRotate.Create;                          // создать операцию
					end;
				end;
				// создадим операцию вырезания по сечениям
				entityAxisOperation := ksEntity( part.NewEntity(o3d_axisOperation) );
				if ( entityAxisOperation <> nil ) then begin
					axisOperation := ksAxisOperationsDefinition( entityAxisOperation.GetDefinition );
					if ( axisOperation <> nil ) then begin
						axisOperation.SetOperation( entityRotate );
						entityAxisOperation.Create;                        // создать операцию
					end;
				end;
				iKompasObject.ksMessage( 'Ось операции' );
			end;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Конструктивная ось по двум точкам
// ---
procedure ConstrAxis2Point;
var
  part             : ksPart;
  entitySketch     : ksEntity;
  sketchDef        : ksSketchDefinition;
  basePlane        : ksEntity;
  sketchEdit       : ksDocument2D;
  entityExtr       : ksEntity;
  extrusionDef     : ksBossExtrusionDefinition;
  entityCollection : ksEntityCollection;
  entityAxis2Point : ksEntity;
  axis2Point       : ksAxis2PointsDefinition;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
		entitySketch := ksEntity( part.NewEntity(o3d_sketch) );
		if ( entitySketch <> nil ) then begin
			// интерфейс свойств эскиза
			sketchDef := ksSketchDefinition( entitySketch.GetDefinition );
			if ( sketchDef <> nil ) then begin
				// получим интерфейс базовой плоскости XOY
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				sketchDef.SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
				entitySketch.Create;             // создадим эскиз

				// интерфейс редактора эскиза
				sketchEdit := ksDocument2D( sketchDef.BeginEdit );
					// введем новый эскиз - квадрат
					sketchEdit.ksLineSeg(  50,  50, -50,  50, 1 );
					sketchEdit.ksLineSeg(  50, -50, -50, -50, 1 );
					sketchEdit.ksLineSeg(  50, -50,  50,  50, 1 );
					sketchEdit.ksLineSeg( -50, -50, -50,  50, 1 );
				sketchDef.EndEdit;                   // завершение редактирования эскиза

				entityExtr := ksEntity( part.NewEntity(o3d_bossExtrusion) );
				if ( entityExtr <> nil ) then begin
					// интерфейс свойств базовой операции выдавливания
					extrusionDef := ksBossExtrusionDefinition( entityExtr.GetDefinition ); // интерфейс базовой операции выдавливания
					if ( extrusionDef <> nil ) then begin
						extrusionDef.DirectionType := dtNormal;         // направление выдавливания
						extrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 20, 0, false );
						extrusionDef.SetThinParam( true, dtBoth, 20, 20 ); // тонкая стенка в два направления
						extrusionDef.SetSketch( entitySketch ); // эскиз операции выдавливания
						entityExtr.Create;                      // создать операцию
					end;
				end;
			end;
		end;

		entityCollection := ksEntityCollection( part.EntityCollection(o3d_vertex) );

		if ( (entityCollection <> nil) And (entityCollection.GetCount > 0) ) then begin
			// создадим ось по двум точкам
			entityAxis2Point := ksEntity( part.NewEntity(o3d_axis2Points) );
			if ( entityAxis2Point <> nil ) then begin
				axis2Point := ksAxis2PointsDefinition( entityAxis2Point.GetDefinition );
				if ( axis2Point <> nil ) then begin
					axis2Point.SetPoint( 1, entityCollection.GetByIndex(0) );
					axis2Point.SetPoint( 2, entityCollection.GetByIndex(entityCollection.GetCount - 1) );
					entityAxis2Point.Create;
				end;
			end;
			iKompasObject.ksMessage( 'Ось через две точки' );
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Конструктивная ось, проходящая через ребро
// ---
procedure ConstrAxisEdge;
var
  part             : ksPart;
  entitySketch     : ksEntity;
  sketchDef        : ksSketchDefinition;
  basePlane        : ksEntity;
  sketchEdit       : ksDocument2D;
  entityExtr       : ksEntity;
  extrusionDef     : ksBossExtrusionDefinition;
  entityCollection : ksEntityCollection;
  entityAxisEdge   : ksEntity;
  axisEdge         : ksAxisEdgeDefinition;
  entityAxisEdge2  : ksEntity;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
		entitySketch := ksEntity( part.NewEntity(o3d_sketch) );
		if ( entitySketch <> nil ) then begin
			// интерфейс свойств эскиза
			sketchDef := ksSketchDefinition( entitySketch.GetDefinition );
			if ( sketchDef <> nil ) then begin
				// получим интерфейс базовой плоскости XOY
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				sketchDef.SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
				entitySketch.Create;           // создадим эскиз

				// интерфейс редактора эскиза
				sketchEdit := ksDocument2D( sketchDef.BeginEdit );
					// введем новый эскиз - квадрат
					sketchEdit.ksLineSeg(  50,  50, -50,  50, 1 );
					sketchEdit.ksLineSeg(  50, -50, -50, -50, 1 );
					sketchEdit.ksLineSeg(  50, -50,  50,  50, 1 );
					sketchEdit.ksLineSeg( -50, -50, -50,  50, 1 );
				sketchDef.EndEdit;                   // завершение редактирования эскиза

				entityExtr := ksEntity( part.NewEntity(o3d_bossExtrusion) );
				if ( entityExtr <> nil ) then begin
					// интерфейс свойств базовой операции выдавливания
					extrusionDef := ksBossExtrusionDefinition( entityExtr.GetDefinition ); // интерфейс базовой операции выдавливания
					if ( extrusionDef <> nil ) then begin
						extrusionDef.DirectionType := dtNormal;         // направление выдавливания
						extrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 20, 0, false );
						extrusionDef.SetThinParam( true, dtBoth, 20, 20 ); // тонкая стенка в два направления
						extrusionDef.SetSketch( entitySketch ); // эскиз операции выдавливания
						entityExtr.Create;                    // создать операцию
					end
				end;
		  end;
		end;

		entityCollection := ksEntityCollection( part.EntityCollection(o3d_edge) );

		if ( (entityCollection <> nil) And (entityCollection.GetCount > 1) ) then begin
			// создадим ось через грань
			entityAxisEdge := ksEntity( part.NewEntity(o3d_axisEdge) );
			if ( entityAxisEdge <> nil ) then begin
				axisEdge := ksAxisEdgeDefinition( entityAxisEdge.GetDefinition );
				if ( axisEdge <> nil ) then begin
					axisEdge.SetEdge( entityCollection.GetByIndex(0) );
					entityAxisEdge.Create;
				end;
			end;
			iKompasObject.ksMessage( 'Ось через грань' );

			// создадим еще ось через грань
			entityAxisEdge2 := ksEntity( part.NewEntity(o3d_axisEdge) );
			if ( entityAxisEdge2 <> nil ) then begin
				axisEdge := ksAxisEdgeDefinition( entityAxisEdge2.GetDefinition );
				if ( axisEdge <> nil ) then begin
					axisEdge.SetEdge( entityCollection.GetByIndex(1) );
					entityAxisEdge2.Create;
				end;
			end;
			iKompasObject.ksMessage( 'Другая ось через грань' );
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Конструктивная ось конической грани
// ---
(*
procedure ConstrAxisConeface;
var
  part              : ksPart;
  entitySketch      : ksEntity;
  sketchDef         : ksSketchDefinition;
  basePlane         : ksEntity;
  sketchEdit        : ksDocument2D;
  entityExtr        : ksEntity;
  extrusionDef      : ksBossExtrusionDefinition;
  entityCollection  : ksEntityCollection;
  entityConFace     : ksEntity;
  i, count          : Integer;
  face              : ksFaceDefinition;
  entityAxisConFace : ksEntity;
  axisConFace       : ksAxisConefaceDefinition;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
		entitySketch := ksEntity( part.NewEntity(o3d_sketch) );
		if ( entitySketch <> nil ) then begin
			// интерфейс свойств эскиза
			sketchDef := ksSketchDefinition( entitySketch.GetDefinition );
			if ( sketchDef <> nil ) then begin
				// получим интерфейс базовой плоскости XOY
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				sketchDef.SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
				entitySketch.Create;           // создадим эскиз

				// интерфейс редактора эскиза
				sketchEdit := ksDocument2D( sketchDef.BeginEdit );
				  sketchEdit.ksCircle( 0, 0, 50, 1 );
				sketchDef.EndEdit;                   // завершение редактирования эскиза

				entityExtr := ksEntity( part.NewEntity(o3d_bossExtrusion) );
				if ( entityExtr <> nil ) then begin
					// интерфейс свойств базовой операции выдавливания
					extrusionDef := ksBaseExtrusionDefinition( entityExtr.GetDefinition ); // интерфейс базовой операции выдавливания
					if ( extrusionDef <> nil ) then begin
						extrusionDef.DirectionType := dtNormal;         // направление выдавливания
						extrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 20, 30, false, false );
						extrusionDef.SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
						extrusionDef.SetSketch( entitySketch ); // эскиз операции выдавливания
						entityExtr.Create;                      // создать операцию
					end;
				end;
			end;
		end;

		entityCollection := ksEntityCollection( part.EntityCollection(o3d_face) );

    count := entityCollection.GetCount;
		for i := 0 to count - 1 do begin
			entityConFace := ksEntity( entityCollection.GetByIndex(i) );
			face := ksFaceDefinition( entityConFace.GetDefinition );
			if ( not face.IsConic ) then // если поверхность не коническая, берем следующую из массива
        entityConFace := nil
			else
				Break;
    end;


		// создадим ось через коническую поверхность
		entityAxisConFace := ksEntity( part.NewEntity(o3d_axisConeFace) );
		if ( entityAxisConFace <> nil ) then begin
			axisConFace := ksConstrAxisConefaceDefinition( entityAxisConFace.GetDefinition );
			if ( axisConFace <> nil ) then begin
				axisConFace.SetFace( entityConFace );
				entityAxisConFace.Create;
			end;
		end;
		iKompasObject.ksMessage( 'Ось через коническую поверхность' );
	end;
end;
*)
//-------------------------------------------------------------------------------
// Плоскость через три вершины
// ---
procedure ConstrPlane3Point;
var
  part                    : ksPart;
  entitySketch            : ksEntity;
  sketchDef               : ksSketchDefinition;
  basePlane               : ksEntity;
  sketchEdit              : ksDocument2D;
  entityExtr              : ksEntity;
  extrusionDef            : ksBossExtrusionDefinition;
  entityCollection        : ksEntityCollection;
  entityConstrPlane3Point : ksEntity;
  constrPlane3Point       : ksPlane3PointsDefinition;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
		entitySketch := ksEntity( part.NewEntity(o3d_sketch) );
		if ( entitySketch <> nil ) then begin
			// интерфейс свойств эскиза
			sketchDef := ksSketchDefinition( entitySketch.GetDefinition );
			if ( sketchDef <> nil ) then begin
				// получим интерфейс базовой плоскости XOY
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				sketchDef.SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
				entitySketch.Create;             // создадим эскиз

				// интерфейс редактора эскиза
				sketchEdit := ksDocument2D( sketchDef.BeginEdit );
					// введем новый эскиз - квадрат
					sketchEdit.ksLineSeg(  50,  50, -50,  50, 1 );
					sketchEdit.ksLineSeg(  50, -50, -50, -50, 1 );
					sketchEdit.ksLineSeg(  50, -50,  50,  50, 1 );
					sketchEdit.ksLineSeg( -50, -50, -50,  50, 1 );
				sketchDef.EndEdit;                   // завершение редактирования эскиза

				entityExtr := ksEntity( part.NewEntity(o3d_bossExtrusion) );
				if ( entityExtr <> nil ) then begin
					// интерфейс свойств базовой операции выдавливания
					extrusionDef := ksBossExtrusionDefinition( entityExtr.GetDefinition ); // интерфейс базовой операции выдавливания
					if ( extrusionDef <> nil ) then begin
						extrusionDef.DirectionType := dtNormal;         // направление выдавливания
						extrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 20, 30, false );
						extrusionDef.SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
						extrusionDef.SetSketch( entitySketch ); // эскиз операции выдавливания
						entityExtr.Create;                      // создать операцию
					end;
				end;
			end;
		end;

		entityCollection := ksEntityCollection( part.EntityCollection(o3d_vertex) );

		// Плоскость через три вершины
		entityConstrPlane3Point := ksEntity( part.NewEntity(o3d_plane3Points) );
		if ( entityConstrPlane3Point <> nil ) then begin
			constrPlane3Point := ksPlane3PointsDefinition( entityConstrPlane3Point.GetDefinition );
			if ( constrPlane3Point <> nil ) then begin
				constrPlane3Point.SetPoint( 1, entityCollection.GetByIndex(0) );
				constrPlane3Point.SetPoint( 2, entityCollection.GetByIndex(1) );
				constrPlane3Point.SetPoint( 3, entityCollection.GetByIndex(2) );
				entityConstrPlane3Point.Create;
			end;
		end;
		iKompasObject.ksMessage( 'Плоскость через три вершины' );
	end;
end;

//-------------------------------------------------------------------------------
// Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
// ---
procedure CreateConstrElem;
var
  part             : ksPart;
  entity           : ksEntity;
  offsetDef        : ksPlaneOffsetDefinition;
  basePlane        : ksEntity;
  entityAxis       : ksEntity;
  axis2PlanesDef   : ksAxis2PlanesDefinition;
  entityAnglePlane : ksEntity;
  planeAngleDef    : ksPlaneAngleDefinition;
begin
	part := ksPart( iDocument3D.GetPart(pTop_Part) ); // новый компонент
	if ( part <> nil ) then begin
		entity := ksEntity( part.NewEntity(o3d_planeOffset) );
		if ( entity <> nil ) then begin
			// интерфейс свойств смещенной плоскости
			offsetDef := ksPlaneOffsetDefinition( entity.GetDefinition );
			if ( offsetDef <> nil ) then begin
				offsetDef.offset := 150; // расстояние от базовой плоскости
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				basePlane.name := 'XOY'; // название для плоскости
				basePlane.Update;        // обновить параметры

				offsetDef.SetPlane( basePlane ); // базовая плоскость
				offsetDef.direction := false;          // направление смещения от базовой плоскости
				entity.name := 'Смещенная плоскость'; // имя для смещенной плоскости
				entity.Create;                 // создать смещенную плоскость

				iKompasObject.ksMessage( 'Изменим параметры смещенной плоскости' );

				offsetDef.offset := 50;       // изменим расстояние до базовой плоскости
				basePlane := nil;
				// возьмем другую базовую плоскость
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeYOZ) );
				basePlane.name := 'YOZ';
		  	basePlane.Update;              // обновить параметры

				offsetDef.direction := true;        // изменим направления смещения относительно базовой плоскости
				offsetDef.SetPlane( basePlane );
				entity.Update;                 // обновить параметры

				basePlane := nil;
				// возьмем другую базовую плоскость
				basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOY) );
				basePlane.name := 'XOY';

				iKompasObject.ksMessage( 'На пересечении плоскостей построим ось' );

				// Ось на пересечении двух плоскостей
				entityAxis := ksEntity( part.NewEntity(o3d_axis2Planes) );
				if ( entityAxis <> nil ) then begin
					axis2PlanesDef := ksAxis2PlanesDefinition( entityAxis.GetDefinition );
					if ( axis2PlanesDef <> nil ) then begin
						axis2PlanesDef.SetPlane( 1, entity );    // Базовая плоскость 1
						axis2PlanesDef.SetPlane( 2, basePlane ); // Базовая плоскость 2
						entityAxis.name := 'Ось по двум плоскостям'; // имя для оси
						entityAxis.Create;                     // создаем ось

						iKompasObject.ksMessage( 'Поменяем одну из базовых плоскостей для построения оси' );

						basePlane := nil;
						// возьмем другую базовую плоскость
						basePlane := ksEntity( part.GetDefaultEntity(o3d_planeXOZ) );
						basePlane.name := 'XOZ';

						axis2PlanesDef.SetPlane( 2, basePlane ); // Базовая плоскость 2
						entityAxis.Update;

						iKompasObject.ksMessage( 'Через смещенную плоскость и построенную ось \n проведем плоскость под углом 45' );

						entityAnglePlane := ksEntity( part.NewEntity(o3d_planeAngle) );
						if ( entityAnglePlane <> nil ) then begin
							// интерфейс свойств плоскости под углом к другой плоскости
							planeAngleDef := ksPlaneAngleDefinition( entityAnglePlane.GetDefinition );
							if ( planeAngleDef <> nil ) then begin
								planeAngleDef.Angle := 45;           // угол наклона к базовой плоскости
								planeAngleDef.SetPlane( entity );    // базовая плоскость
								planeAngleDef.SetAxis( entityAxis ); // базовая ось
								entityAnglePlane.name := 'Плоскость под углом к другой плоскости';
								entityAnglePlane.Create;           // создать плоскость под углом

								iKompasObject.ksMessage( 'Изменим одну из базовых плоскостей' );

								planeAngleDef.SetPlane( basePlane ); // базовая плоскость
								entityAnglePlane.Update;           // обновить параметры плоскости
							end;
						end;
					end;
				end;
			end;
		end;
	end;
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LibraryId: UINT; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LibraryEntry( command: WORD ); pascal;
begin
  iKompasObject := KompasObject(CreateKompasObject);

  if iKompasObject <> nil then
  begin
    iDocument3D := ksDocument3D(iKompasObject.ActiveDocument3D);

    if (iDocument3D <> nil) then
    begin
      case command of
        1  : ConstrAxisOperations;  // Конструктивная ось операции
				2  : ConstrAxis2Point;  	  // Конструктивная ось по двум точкам
				3  : ConstrAxisEdge;	      // Конструктивная ось, проходящая через ребро
//				4  : ConstrAxisConeface;    // Конструктивная ось конической грани
				5  : CreateConstrElem;      // Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
				6  : ConstrPlane3Point;     // Плоскость через три вершины
//				8  : ::GetArraySketch;        // Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
//				9  : ::GetSetUserParamComponent; // Установить и получить параметры пользователя в компоненте
//				10 : ::GetSetArrayMate;       // Получить массив зависивых объектов(ksEntityCollection) для повторного редактирования детали.mates
      end;

      iKompasObject.ksMessageBoxResult;

      iDocument3D := nil;
    end;

    iKompasObject := nil;
  end;
end;

end.
