unit Step3D11;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}



interface

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LIBRARYNAME : PAnsiChar; pascal;
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

//------------------------------------------------------------------------------
// Удалить все объекты из текущего эскиза
//-
procedure ClearCurrentSketch( value: ksDocument2D );
var
  iIterator: ksIterator;
  obj: Reference;

begin
  // создаим итератор и удалим все существующие объекты в эскизе
  iIterator := ksIterator(iKompasObject.GetIterator);

  if iIterator <> nil then
  begin
    if iIterator.ksCreateIterator(ALL_OBJ, 0) then
    begin
      obj := iIterator.ksMoveIterator( 'F' ); // сместить указатель на первый объект

      while BOOL(value.ksExistObj(obj)) do
      begin
      	value.ksDeleteObj( obj ); // если объект существует удалить его
        obj := iIterator.ksMoveIterator( 'N' ); // в цикле сместить указатель на следующий объект
      end;

      iIterator.ksDeleteIterator; // удалим итератор
    end;
  end;
end;

//------------------------------------------------------------------------------
// Оперция выдавливания
//-
procedure OperationExtrusion();
var
  iPart: ksPart;
  iSketchEntity: ksEntity;
  iSketchDef: ksSketchDefinition;
  iPlaneEntity: ksEntity;
  iSketchDocument2D: ksDocument2D;
  iBaseExtrusionEntity: ksEntity;
  iBaseExtrusionDef: ksBossExtrusionDefinition;
  iSketch2Entity: ksEntity;
  iSketch2Def: ksSketchDefinition;
  iSketch2Document2D: ksDocument2D;
  iBossExtrusion: ksEntity;
  iBossExtrusionDef: ksBossExtrusionDefinition;
  iExtrusionProperty: ksExtrusionParam;
  iThinProperty: ksThinParam;
  iSketch3Entity: ksEntity;
  iSketch3Def: ksSketchDefinition;
  iSketch3Document2D: ksDocument2D;
  iCutExtrusion: ksEntity;
  iCutExtrusionDef: ksCutExtrusionDefinition;

begin
  iKompasObject.ksMessage( 'базовая операция выдавливания' );

  iPart := ksPart(iDocument3D.GetPart( pTop_Part )); // верхний компонент ( модель )

  if iPart <> nil then
  begin

    iSketchEntity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketchEntity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketchDef := ksSketchDefinition(iSketchEntity.GetDefinition);

      if iSketchDef <> nil then
      begin
        // интерфейс плоскости XOY
        iPlaneEntity := ksEntity(iPart.GetDefaultEntity( o3d_planeXOY ));

        if iPlaneEntity <> nil then
        begin
          iSketchDef.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
          iSketchDef.Angle := 45; // угол поворота эскиза
          iSketchEntity.Create; // создадим эскиз
          // интерфейс редактора эскиза
          iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

          if iSketchDocument2D <> nil then
          begin
            // введем новый эскиз - квадрат
            iSketchDocument2D.ksLineSeg(  50,  50, -50,  50, 1 );
            iSketchDocument2D.ksLineSeg(  50, -50, -50, -50, 1 );
            iSketchDocument2D.ksLineSeg(  50, -50,  50,  50, 1 );
            iSketchDocument2D.ksLineSeg( -50, -50, -50,  50, 1 );
            iSketchDef.EndEdit; // завершение редактирования эскиза

            iBaseExtrusionEntity := ksEntity(iPart.NewEntity( o3d_bossExtrusion ));

            if iBaseExtrusionEntity <> nil then
            begin
              // интерфейс свойств базовой операции выдавливания
              iBaseExtrusionDef := ksBossExtrusionDefinition(iBaseExtrusionEntity.GetDefinition);

              if iBaseExtrusionDef <> nil then
              begin
                iBaseExtrusionDef.DirectionType := dtNormal; // направление выдавливания
                iBaseExtrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 200, 0, false );
                iBaseExtrusionDef.SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
                iBaseExtrusionDef.SetSketch( iSketchEntity ); // эскиз операции выдавливания
                iBaseExtrusionEntity.Create; // создать операцию

                iKompasObject.ksMessage( 'изменим параметры операции выдавливания' );

                iBaseExtrusionDef.SetSideParam( false{обратное направление}, etBlind{строго на глубину}, 150, 0, false );
                iBaseExtrusionDef.DirectionType := dtBoth{в оба направления}; // направление выдавливания
                iBaseExtrusionEntity.Update; // обновить параметры

                iKompasObject.ksMessage( 'поменяем эскиз' );

                iSketchDocument2D := nil;
                iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);
                // удалим все существующие объекты в эскизе
                ClearCurrentSketch( iSketchDocument2D );
                // введем в эскиз окружность
                iSketchDocument2D.ksCircle( 0, 0, 100, 1 );
                iSketchDef.EndEdit; // завершение редактирования эскиза
                iSketchEntity.Update; // обновить параметры эскиза
                iBaseExtrusionEntity.Update; // обновить параметры операции выдавливания

                iKompasObject.ksMessage( 'приклеить элемент выдавливания' );

                // создадим новый эскиз
                iSketch2Entity := ksEntity(iPart.NewEntity( o3d_sketch ));

                if iSketch2Entity <> nil then
                begin
                  // интерфейс свойств эскиза
                  iSketch2Def := ksSketchDefinition(iSketch2Entity.GetDefinition);

                  if iSketch2Def <> nil then
                  begin
                    iSketch2Def.SetPlane( iPlaneEntity ); // установим плоскость
		                iSketch2Def.Angle := 45; // повернем эскиз на 45 град.
		                iSketch2Entity.Create; // создадим эскиз

                    // интерфейс редактора эскиза
                    iSketch2Document2D := ksDocument2D(iSketch2Def.BeginEdit);
                    iSketch2Document2D.ksCircle( 0, 0, 150, 1 );
                    iSketch2Def.EndEdit; // завершение редактирования эскиза

                    // приклеим выдавливанием
                    iBossExtrusion := ksEntity(iPart.NewEntity( o3d_bossExtrusion ));

                    if iBossExtrusion <> nil then
                    begin
                      iBossExtrusionDef := ksBossExtrusionDefinition(iBossExtrusion.GetDefinition);

		                  if iBossExtrusionDef <> nil then
                      begin
                        iExtrusionProperty := ksExtrusionParam(iBossExtrusionDef.ExtrusionParam); // интерфейс структуры параметров выдавливания
                        iThinProperty := ksThinParam(iBossExtrusionDef.ThinParam); // интерфейс структуры параметров тонкой стенки

                        if (iExtrusionProperty <> nil) and (iThinProperty <> nil ) then
                        begin
                          iBossExtrusionDef.SetSketch( iSketch2Entity ); // эскиз операции выдавливания
                          iExtrusionProperty.Direction := dtNormal; // направление выдавливания (прямое)
                          iExtrusionProperty.TypeNormal := etBlind; // тип выдавливания ( строго на глубину )
                          iExtrusionProperty.DepthNormal := 100; // глубина выдавливания
                          iThinProperty.Thin := false; // без тонкой стенки

                          iBossExtrusion.Create; // создадим операцию
                        end;
                      end;
                    end;
                  end;
                end;

               iKompasObject.ksMessage( 'вырезать элемент выдавливания' );
                // создадим новый эскиз
                iSketch3Entity := ksEntity(iPart.NewEntity( o3d_sketch ));

                if iSketch3Entity <> nil then
                begin
                  // интерфейс свойств эскиза
                  iSketch3Def := ksSketchDefinition(iSketch3Entity.GetDefinition);

                  if iSketch3Def <> nil then
                  begin
                    iSketch3Def.SetPlane( iPlaneEntity ); // установим плоскость
                    iSketch3Def.Angle := 45; // повернем эскиз на 45 град.
                    iSketch3Entity.Create; // создадим эскиз

                    // интерфейс редактора эскиза
                    iSketch3Document2D := ksDocument2D( iSketch3Def.BeginEdit );
                    // введем новый эскиз - квадрат
                    iSketch3Document2D.ksLineSeg(  50,  50, -50,  50, 1 );
                    iSketch3Document2D.ksLineSeg(  50, -50, -50, -50, 1 );
                    iSketch3Document2D.ksLineSeg(  50, -50,  50,  50, 1 );
                    iSketch3Document2D.ksLineSeg( -50, -50, -50,  50, 1 );
                    iSketch3Def.EndEdit; // завершение редактирования эскиза

                    // вырежим выдавливанием
                    iCutExtrusion := ksEntity(iPart.NewEntity( o3d_cutExtrusion ));

                    if iCutExtrusion <> nil then
                    begin
                      iCutExtrusionDef := ksCutExtrusionDefinition(iCutExtrusion.GetDefinition);

                      if iCutExtrusionDef <> nil then
                      begin
		                    iCutExtrusionDef.SetSketch( iSketch3Entity ); // установим эскиз операции
                        iCutExtrusionDef.DirectionType := dtReverse;
                        iCutExtrusionDef.SetSideParam( false, etBlind, 50, 0, false );
                        iCutExtrusionDef.SetThinParam( false, 0, 0, 0 );
                      end;

                    iCutExtrusion.Create; // создадим операцию вырезание выдавливанием
                    end;
                  end;
                end;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Операции вращения
//-
procedure OperationRotated;
var
  iPart: ksPart;
  iSketchEntity: ksEntity;
  iSketchDef: ksSketchDefinition;
  iPlaneEntity: ksEntity;
  iSketchDocument2D: ksDocument2D;
  iBaseRotatedEntity: ksEntity;
  iBaseRotatedDef: ksBossRotatedDefinition;
  iRotatedProperty: ksRotatedParam;
  iSketch2Entity: ksEntity;
  iSketch2Def: ksSketchDefinition;
  iSketch2Document2D: ksDocument2D;
  iBossRotatedEntity: ksEntity;
  iBossRotatedDef: ksBossRotatedDefinition;
  iSketch3Entity: ksEntity;
  iSketch3Def: ksSketchDefinition;
  iSketch3Document2D: ksDocument2D;
  iCutRotatedEntity: ksEntity;
  iCutRotatedDef: ksCutRotatedDefinition;

begin
  iKompasObject.ksMessage( 'базовая операция вращения' );

  iPart := ksPart(iDocument3D.GetPart( pTop_Part )); // новый компонент

  if iPart <> nil then
  begin
    iSketchEntity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketchEntity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketchDef := ksSketchDefinition(iSketchEntity.GetDefinition);

      if iSketchDef <> nil then
      begin
        // интерфейс плоскости XOY
        iPlaneEntity := ksEntity(iPart.GetDefaultEntity( o3d_planeXOY ));

        if iPlaneEntity <> nil then
        begin
          iSketchDef.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
          iSketchEntity.Create; // создадим эскиз
          // интерфейс редактора эскиза
          iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

          if iSketchDocument2D <> nil then
          begin
            // введем новый эскиз
            iSketchDocument2D.ksArcByAngle( 0, 0, 20, -90, 90, 1, 1 );
	    iSketchDocument2D.ksLineSeg( 0, -20, 0, 20, 3 );
	    iSketchDef.EndEdit; // завершение редактирования эскиза
          end;

          iBaseRotatedEntity := ksEntity(iPart.NewEntity( o3d_bossRotated ));

          if iBaseRotatedEntity <> nil then
          begin
            iBaseRotatedDef := ksBossRotatedDefinition(iBaseRotatedEntity.GetDefinition); // интерфейс базовой операции вращения

	    if iBaseRotatedDef <> nil then
            begin
     	      iRotatedProperty := ksRotatedParam(iBaseRotatedDef.RotatedParam);

	      if iRotatedProperty <> nil then
              begin
	      	iRotatedProperty.Direction := dtBoth;
	      	iRotatedProperty.ToroidShape := false;
	      end;

              //iBaseRotatedDef.SetTorShapeType(false);
              //iBaseRotatedDef.SetDirectionType( dtNormal ); // направление вращения
	      iBaseRotatedDef.SetThinParam( true, dtBoth, 1, 1 ); // тонкая стенка в два направления
	      iBaseRotatedDef.SetSideParam( true, 180 );
	      iBaseRotatedDef.SetSketch( iSketchEntity ); // эскиз операции вращения
	      iBaseRotatedEntity.Create; // создать операцию
            end;
	  end;
        end;
      end;
    end;

    iKompasObject.ksMessage( 'приклеить элемент вращения' );

    iSketch2Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketch2Entity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketch2Def := ksSketchDefinition(iSketch2Entity.GetDefinition);

      if iSketch2Def <> nil then
      begin
        iSketch2Def.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
        iSketch2Entity.Create; // создадим эскиз
        // интерфейс редактора эскиза
        iSketch2Document2D := ksDocument2D(iSketch2Def.BeginEdit);

        if iSketch2Document2D <> nil then
        begin
          // введем новый эскиз
          iSketch2Document2D.ksArcByAngle( 15, 0, 10, -90, 90, 1, 1 );
          iSketch2Document2D.ksLineSeg( 15, -10, 15, 10, 3 );
          iSketch2Def.EndEdit; // завершение редактирования эскиза
        end;

        iBossRotatedEntity := ksEntity(iPart.NewEntity( o3d_bossRotated ));

        if iBossRotatedEntity <> nil then
        begin
          iBossRotatedDef := ksBossRotatedDefinition(iBossRotatedEntity.GetDefinition); // интерфейс базовой операции вращения

 	  if iBossRotatedDef <> nil then
          begin
            iBossRotatedDef.DirectionType := dtNormal;
	    iBossRotatedDef.SetSideParam( true, 360 );
	    iBossRotatedDef.SetSketch( iSketch2Entity ); // эскиз операции вращения
	    iBossRotatedEntity.Create; // создать операцию
	  end;
	end;
      end;
    end;

    iKompasObject.ksMessage( 'вырезать элемент вращения' );

    iSketch3Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketch3Entity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketch3Def := ksSketchDefinition(iSketch3Entity.GetDefinition);

      if iSketch3Def <> nil then
      begin
        iSketch3Def.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
        iSketch3Entity.Create; // создадим эскиз
        // интерфейс редактора эскиза
        iSketch3Document2D := ksDocument2D(iSketch3Def.BeginEdit);

        if iSketch3Document2D <> nil then
        begin
          // введем новый эскиз
	  iSketch3Document2D.ksArcByAngle( 20, 0, 20, 90, 270, 1, 1 );
	  iSketch3Document2D.ksLineSeg( 20, -20, 20, 20, 3 );
          iSketch3Def.EndEdit; // завершение редактирования эскиза
        end;

        iCutRotatedEntity := ksEntity(iPart.NewEntity( o3d_cutRotated ));

        if iCutRotatedEntity <> nil then
        begin
          iCutRotatedDef := ksCutRotatedDefinition(iCutRotatedEntity.GetDefinition); // интерфейс базовой операции вращения

 	  if iCutRotatedDef <> nil then
          begin
            iCutRotatedDef.DirectionType := dtNormal;
            iCutRotatedDef.SetSideParam( true, 90 );
            iCutRotatedDef.SetThinParam( true, dtBoth, 5, 7 ); // тонкая стенка в два направления
            iCutRotatedDef.SetSketch( iSketch3Entity ); // эскиз операции вращения
            iCutRotatedEntity.Create; // создать операцию
	  end;
	end;
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Оперции сечения
//-
procedure OperationLoft;
var
  iPart: ksPart;
  iPlaneEntity: ksEntity;
  iEntityCollection: ksEntityCollection;
  iRectangleParam: ksRectangleParam;
  iOffsetPlaneEntity: ksEntity;
  iOffsetPlaneDef: ksPlaneOffsetDefinition;
  iBaseLoftEntry: ksEntity;
  iBaseLoftDef: ksBaseLoftDefinition;
  iBossLoftEntity: ksEntity;
  iBossLoftDef: ksBossLoftDefinition;
  iCutLoftEntity: ksEntity;
  iCutLoftDef: ksCutLoftDefinition;
  iSketchDef: ksSketchDefinition;
  iSketchDocument2D: ksDocument2D;
  iSketch1Entity: ksEntity;
  iSketch2Entity: ksEntity;
  iSketch3Entity: ksEntity;
  iSketch4Entity: ksEntity;
  iSketch5Entity: ksEntity;
  iSketch6Entity: ksEntity;

begin
  iKompasObject.ksMessage( 'базовая операция вращения' );

  iPart := ksPart(iDocument3D.GetPart( pTop_Part )); // новый компонент

  if iPart <> nil then
  begin
    // интерфейс плоскости XOY
    iPlaneEntity := ksEntity(iPart.GetDefaultEntity( o3d_planeXOY ));

    if iPlaneEntity <> nil then
    begin
      iSketch1Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

      if iSketch1Entity <> nil then
      begin
        // интерфейс свойств эскиза
        iSketchDef := ksSketchDefinition(iSketch1Entity.GetDefinition);

        if iSketchDef <> nil then
        begin
          iSketchDef.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
          iSketch1Entity.Create; // создадим эскиз

          // интерфейс редактора эскиза
          iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

          if iSketchDocument2D <> nil then
          begin
            // введем новый эскиз
            iSketchDocument2D.ksCircle( 0, 0, 4.5, 1 );
 	    iSketchDef.EndEdit; // завершение редактирования эскиза
          end;
        end;
      end;

      // создадим смещенную плоскость, а в ней эскиз
      iOffsetPlaneEntity := ksEntity(iPart.NewEntity( o3d_planeOffset ));

      if iOffsetPlaneEntity <> nil then
      begin
        // интерфейс свойств смещенной плоскости
        iOffsetPlaneDef := ksPlaneOffsetDefinition(iOffsetPlaneEntity.GetDefinition);

        if iOffsetPlaneDef <> nil then
        begin
          iOffsetPlaneDef.Offset := 30; // расстояние от базовой плоскости
          iOffsetPlaneDef.SetPlane( iPlaneEntity ); // базовая плоскость
          iOffsetPlaneEntity.Name := 'Смещенная плоскость 1'; // имя для смещенной плоскости
          iOffsetPlaneEntity.Hidden := true;
          iOffsetPlaneEntity.Create; // создать смещенную плоскость

          iSketch2Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

          if iSketch2Entity <> nil then
          begin
            // интерфейс свойств эскиза
            iSketchDef := ksSketchDefinition(iSketch2Entity.GetDefinition);

            if iSketchDef <> nil then
            begin
              iSketchDef.SetPlane( iOffsetPlaneEntity ); // установим плоскость XOY базовой для эскиза
              iSketch2Entity.Create; // создадим эскиз

              // интерфейс редактора эскиза
              iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

              if iSketchDocument2D <> nil then
              begin
                // введем новый эскиз
                iSketchDocument2D.ksCircle( 0, 0, 8, 1 );
                iSketchDef.EndEdit; // завершение редактирования эскиза
              end;
            end;
          end;
        end;
      end;

      // создадим смещенную плоскость, а в ней эскиз
      iOffsetPlaneEntity := ksEntity(iPart.NewEntity( o3d_planeOffset ));

      if iOffsetPlaneEntity <> nil then
      begin
        // интерфейс свойств смещенной плоскости
        iOffsetPlaneDef := ksPlaneOffsetDefinition(iOffsetPlaneEntity.GetDefinition);

        if iOffsetPlaneDef <> nil then
        begin
          iOffsetPlaneDef.Offset := 60; // расстояние от базовой плоскости
          iOffsetPlaneDef.SetPlane( iPlaneEntity ); // базовая плоскость
          iOffsetPlaneEntity.Name := 'Смещенная плоскость 2'; // имя для смещенной плоскости
          iOffsetPlaneEntity.Hidden := true;
          iOffsetPlaneEntity.Create; // создать смещенную плоскость

          iSketch3Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

          if iSketch3Entity <> nil then
          begin
          // интерфейс свойств эскиза
            iSketchDef := ksSketchDefinition(iSketch3Entity.GetDefinition);

            if iSketchDef <> nil then
            begin
              iSketchDef.SetPlane( iOffsetPlaneEntity ); // установим плоскость XOY базовой для эскиза
              iSketch3Entity.Create; // создадим эскиз

              // интерфейс редактора эскиза
              iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

              if iSketchDocument2D <> nil then
              begin
                // введем новый эскиз
                iSketchDocument2D.ksCircle( 0, 0, 1.8, 1 );
                iSketchDef.EndEdit; // завершение редактирования эскиза
              end;
            end;
          end;
        end;
      end;

      // создадим смещенную плоскость, а в ней эскиз
      iOffsetPlaneEntity := ksEntity(iPart.NewEntity( o3d_planeOffset ));

      if iOffsetPlaneEntity <> nil then
      begin
        // интерфейс свойств смещенной плоскости
        iOffsetPlaneDef := ksPlaneOffsetDefinition(iOffsetPlaneEntity.GetDefinition);

        if iOffsetPlaneDef <> nil then
        begin
          iOffsetPlaneDef.Offset := 120; // расстояние от базовой плоскости
          iOffsetPlaneDef.SetPlane( iPlaneEntity ); // базовая плоскость
          iOffsetPlaneEntity.Name := 'Смещенная плоскость 3'; // имя для смещенной плоскости
          iOffsetPlaneEntity.Hidden := true;
          iOffsetPlaneEntity.Create; // создать смещенную плоскость

          iSketch4Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

          if iSketch4Entity <> nil then
          begin
            // интерфейс свойств эскиза
            iSketchDef := ksSketchDefinition(iSketch4Entity.GetDefinition);

            if iSketchDef <> nil then
            begin
              iSketchDef.SetPlane( iOffsetPlaneEntity ); // установим плоскость XOY базовой для эскиза
              iSketch4Entity.Create; // создадим эскиз

              // интерфейс редактора эскиза
              iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

              if iSketchDocument2D <> nil then
              begin
                // введем новый эскиз
                iSketchDocument2D.ksCircle( 0, 0, 1.8, 1 );
                iSketchDef.EndEdit; // завершение редактирования эскиза
              end;
            end;
          end;

          iSketch5Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

          if iSketch5Entity <> nil then
          begin
            // интерфейс свойств эскиза
            iSketchDef := ksSketchDefinition(iSketch5Entity.GetDefinition);

            if iSketchDef <> nil then
            begin
              iSketchDef.SetPlane( iOffsetPlaneEntity ); // установим плоскость XOY базовой для эскиза
              iSketch5Entity.Create; // создадим эскиз

              // интерфейс редактора эскиза
              iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

              if iSketchDocument2D <> nil then
              begin
                // введем новый эскиз
                iRectangleParam := ksRectangleParam(iKompasObject.GetParamStruct(ko_RectangleParam));
                iRectangleParam.Init;
                iRectangleParam.X := -1.8;
                iRectangleParam.Y := -0.4;
                iRectangleParam.Height := 0.8;
                iRectangleParam.Width := 3.6;
                iRectangleParam.Style := 1;

                iSketchDocument2D.ksRectangle( iRectangleParam, 0 );

                iSketchDef.EndEdit; // завершение редактирования эскиза
              end;  
            end;
          end;
        end;
      end;

      // создадим смещенную плоскость, а в ней эскиз
      iOffsetPlaneEntity := ksEntity(iPart.NewEntity( o3d_planeOffset ));

      if iOffsetPlaneEntity <> nil then
      begin
        // интерфейс свойств смещенной плоскости
        iOffsetPlaneDef := ksPlaneOffsetDefinition(iOffsetPlaneEntity.GetDefinition);

        if iOffsetPlaneDef <> nil then
        begin
          iOffsetPlaneDef.Offset := 110; // расстояние от базовой плоскости
          iOffsetPlaneDef.SetPlane( iPlaneEntity ); // базовая плоскость
          iOffsetPlaneEntity.Name := 'Смещенная плоскость 4'; // имя для смещенной плоскости
          iOffsetPlaneEntity.Hidden := true;
          iOffsetPlaneEntity.Create; // создать смещенную плоскость

          iSketch6Entity := ksEntity( iPart.NewEntity( o3d_sketch ));

          if iSketch6Entity <> nil then
          begin
            // интерфейс свойств эскиза
            iSketchDef := ksSketchDefinition(iSketch6Entity.GetDefinition);

            if iSketchDef <> nil then
            begin
              iSketchDef.SetPlane( iOffsetPlaneEntity ); // установим плоскость XOY базовой для эскиза
              iSketch6Entity.Create; // создадим эскиз

              // интерфейс редактора эскиза
              iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

              if iSketchDocument2D <> nil then
              begin
                // введем новый эскиз
                iRectangleParam := ksRectangleParam(iKompasObject.GetParamStruct(ko_RectangleParam));
                iRectangleParam.Init;
                iRectangleParam.X := -1.8;
                iRectangleParam.Y := -1.8;
                iRectangleParam.Height := 3.6;
                iRectangleParam.Width := 3.6;
                iRectangleParam.Style := 1;

                iSketchDocument2D.ksRectangle( iRectangleParam, 0 );

                iSketchDef.EndEdit; // завершение редактирования эскиза
              end;
            end;
          end;
        end;
      end;

      iKompasObject.ksMessage( 'базовая операция по сечениям' );

      if (iSketch1Entity <> nil) and (iSketch2Entity <> nil) and (iSketch3Entity <> nil) then
      begin
        // создадим базовую операцию по сечениям
        iBaseLoftEntry := ksEntity(iPart.NewEntity( o3d_bossLoft ));

        if iBaseLoftEntry <> nil then
        begin
          iBaseLoftDef := ksBaseLoftDefinition(iBaseLoftEntry.GetDefinition);

          if iBaseLoftDef <> nil then
          begin
            iEntityCollection := ksEntityCollection( iBaseLoftDef.Sketchs );

            if iEntityCollection <> nil then
            begin
              iEntityCollection.Add( iSketch1Entity );
              iEntityCollection.Add( iSketch2Entity );
              iEntityCollection.Add( iSketch3Entity );
            end;

            iBaseLoftEntry.Name := 'Ручка' ;
            iBaseLoftEntry.SetAdvancedColor( 12345678, 0.8, 0.8, 0.8, 0.8, 1, 0.8 );
            iBaseLoftEntry.Create; // создать операцию
          end;
        end;
      end;

      iKompasObject.ksMessage( 'операция приклеивания по сечениям' );

      if (iSketch3Entity <> nil) and (iSketch4Entity <> nil) then
      begin
        // создадим операцию приклеивания по сечениям
        iBossLoftEntity := ksEntity(iPart.NewEntity( o3d_bossLoft ));

        if iBossLoftEntity <> nil then
        begin
          iBossLoftDef := ksBossLoftDefinition( iBossLoftEntity.GetDefinition );

          if iBossLoftDef <> nil then
          begin
            iEntityCollection := ksEntityCollection( iBossLoftDef.Sketchs );

            if iEntityCollection <> nil then
            begin
               iEntityCollection.Add( iSketch3Entity );
               iEntityCollection.Add( iSketch4Entity );
            end;

            iBossLoftEntity.Name := 'Цeвьё';
            iBossLoftEntity.Create; // создать операцию
          end;
        end;
      end;

      iKompasObject.ksMessage( 'операция вырезания по сечениям' );

      if (iSketch5Entity <> nil) and (iSketch6Entity <> nil) then
      begin
        // создадим операцию вырезания по сечениям
        iCutLoftEntity := ksEntity(iPart.NewEntity( o3d_cutLoft ));

        if iCutLoftEntity <> nil then
        begin
          iCutLoftDef := ksCutLoftDefinition( iCutLoftEntity.GetDefinition );

          if iCutLoftDef <> nil then
          begin
            iEntityCollection := ksEntityCollection( iCutLoftDef.Sketchs );

            if iEntityCollection <> nil then
            begin
              iEntityCollection.Add( iSketch5Entity );
              iEntityCollection.Add( iSketch6Entity );
            end;

            iCutLoftDef.SetThinParam( true, dtNormal, 3, 0 );
            iCutLoftEntity.Name := 'Рабочая поверхность';
            iCutLoftEntity.Create; // создать операцию
          end;
        end;
      end;

    end;
  end;
end;

//------------------------------------------------------------------------------
// Создание фаски и скругления
//-
procedure CreateFilletAndChamfer;
var
  iPart: ksPart;
  iSketchEntity: ksEntity;
  iSketchDef: ksSketchDefinition;
  iPlaneEntity: ksEntity;
  iSketchDocument2D: ksDocument2D;
  iBaseExtrusionEntity: ksEntity;
  iBaseExtrusionDef: ksBossExtrusionDefinition;
  iEntityCollection: ksEntityCollection;
  iFilletEntity: ksEntity;
  iFilletDef: ksFilletDefinition;
  iEntityArray: ksEntityCollection;
  iEntityCollection2: ksEntityCollection;
  i, count: Integer;
  iChamferEntity: ksEntity;
  iChamferDef: ksChamferDefinition;

begin
  iPart := ksPart(iDocument3D.GetPart( pTop_Part )); // новый компонент

  if iPart <> nil then
  begin
    iSketchEntity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketchEntity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketchDef := ksSketchDefinition(iSketchEntity.GetDefinition);

      if iSketchDef <> nil then
      begin
        // интерфейс плоскости XOY
        iPlaneEntity := ksEntity(iPart.GetDefaultEntity( o3d_planeXOY ));

        if iPlaneEntity <> nil then
        begin
          iSketchDef.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
          iSketchDef.Angle := 45 ; // угол поворота эскиза
          iSketchEntity.Create; // создадим эскиз
          // интерфейс редактора эскиза
          iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

          if iSketchDocument2D <> nil then
          begin
            // введем новый эскиз
            iSketchDocument2D.ksLineSeg(  50,  50, -50,  50, 1 );
            iSketchDocument2D.ksLineSeg(  50, -50, -50, -50, 1 );

            iSketchDocument2D.ksLineSeg(  50, -50,  50,  50, 1 );
            iSketchDocument2D.ksLineSeg( -50, -50, -50,  50, 1 );
	    iSketchDef.EndEdit; // завершение редактирования эскиза
          end;

          iBaseExtrusionEntity := ksEntity(iPart.NewEntity( o3d_bossExtrusion ));

          if iBaseExtrusionEntity <> nil then
          begin
            iBaseExtrusionDef := ksBossExtrusionDefinition(iBaseExtrusionEntity.GetDefinition); // интерфейс базовой операции вращения

            if iBaseExtrusionDef <> nil then
            begin
              iBaseExtrusionDef.DirectionType := dtNormal; // направление выдавливания
              iBaseExtrusionDef.SetSideParam( true{прямое направление}, etBlind{строго на глубину}, 100, 0, false );
              iBaseExtrusionDef.SetThinParam( false, 0, 0, 0 ); // без тонкой стенки
              iBaseExtrusionDef.SetSketch( iSketchEntity ); // эскиз операции выдавливания
              iBaseExtrusionEntity.Create; // создать операцию

              iEntityCollection := ksEntityCollection(iPart.EntityCollection( o3d_face ));

              if (iEntityCollection <> nil) and
                 (iEntityCollection.SelectByPoint(0, 0, 0)) and
                 (iEntityCollection.GetCount > 0 ) then
              begin
                iKompasObject.ksMessage( 'создание скругления' );

                iFilletEntity := ksEntity(iPart.NewEntity( o3d_fillet ));

                if iFilletEntity <> nil then
                begin
                  iFilletDef := ksFilletDefinition(iFilletEntity.GetDefinition);

                  if iFilletDef <> nil then
                  begin
                    iFilletDef.Radius := 10; // радиус скругления
                    iFilletDef.Tangent := false; // продолжить по касательной

                    iEntityArray := ksEntityCollection( iFilletDef.Array_ ); // динамический массив объектов

                    if iEntityArray <> nil then
                    begin
                      count := iEntityCollection.GetCount;
                      for i := 0 to count - 1 do
                        iEntityArray.Add( iEntityCollection.GetByIndex(i) );

                      iFilletEntity.Create;
                    end;
                  end;
                end;
              end;

              iEntityCollection2 := ksEntityCollection(iPart.EntityCollection( o3d_face ));

              if (iEntityCollection2 <> nil) and
                 (iEntityCollection2.SelectByPoint(0, 0, 100)) and
                 (iEntityCollection2.GetCount > 0 ) then
              begin
                iKompasObject.ksMessage( 'создание фаски' );

                iChamferEntity := ksEntity(iPart.NewEntity( o3d_chamfer ));

                if iChamferEntity <> nil then
                begin
                  iChamferDef := ksChamferDefinition(iChamferEntity.GetDefinition);

                  if iFilletDef <> nil then
                  begin
                    iChamferDef.Tangent := false;
                    iChamferDef.SetChamferParam( true, 10, 10 );

                    iEntityArray.Clear;
                    iEntityArray := ksEntityCollection( iChamferDef.Array_ ); // динамический массив объектов

                    if iEntityArray <> nil then
                    begin
                      count := iEntityCollection2.GetCount;
                      for i := 0 to count - 1 do
                        iEntityArray.Add( iEntityCollection2.GetByIndex(i) );

                      iChamferEntity.Create;
                    end;
                  end;
                end;
              end;

            end;
          end;
        end;
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Базовые операции 3D';
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;
begin
  iKompasObject := KompasObject(CreateKompasObject);

  if iKompasObject <> nil then
  begin
    iDocument3D := ksDocument3D(iKompasObject.ActiveDocument3D);

    if ( ( iDocument3D <> nil ) and ( iDocument3D.IsDetail ) ) then
    begin
      case command of
        1: OperationExtrusion;     // операция выдавливания
        2: OperationRotated;       // операции вращения
        3: OperationLoft;          // oперции сечения
        4: CreateFilletAndChamfer; // создание фаски и скругления
      end;

      iKompasObject.ksMessageBoxResult;

      iDocument3D := nil;
    end;

    iKompasObject := nil;
  end;
end;


end.
