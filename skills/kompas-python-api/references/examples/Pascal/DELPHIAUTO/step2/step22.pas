unit step22;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYNAME : PAnsiChar;        Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;

implementation

uses
  Windows,
  SysUtils,
  LDefin2D,
  ksConstTLB,
  ksAuto,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

var
  iKompasObject: KompasObject;
  iDocument2D: ksDocument2D;
  iMathematic2D: ksMathematic2D;


//------------------------------------------------------------------------------
// DrawPointByArray
//---
procedure DrawPointByArray( iDynamicArray: ksDynamicArray );
var
  iMathPointParam: ksMathPointParam;
  buf: string;
  i: Integer;

begin
  if iDynamicArray <> nil then
  begin
    iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));
    if iMathPointParam <> nil then
      for i := 0 to iDynamicArray.ksGetArrayCount - 1 do
      begin
        iDynamicArray.ksGetArrayItem( i, iMathPointParam );
        iDocument2D.ksPoint( iMathPointParam.x, iMathPointParam.y, 5 );
        buf := Format( 'x = %6.2f  y = %6.2f ', [iMathPointParam.x, iMathPointParam.y] );
        iKompasObject.ksMessage( buf );
      end;
  end
end;


//------------------------------------------------------------------------------
// Пересечь прямые
//---
procedure IntercectLines;
var
  iDynamicArray: ksDynamicArray;

begin
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));

  if iDynamicArray <> nil then
  begin
    iDocument2D.ksLine( 10, 10,  0 );
    iDocument2D.ksLine( 15,  5, 90 );
    iMathematic2D.ksIntersectLinLin( 10, 10, 0, 15, 5, 90, iDynamicArray );
    DrawPointByArray( iDynamicArray );
    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Пересечь кривые
//---
procedure IntercectCurves;
var
  pp1, pp2: Reference;
  iDynamicArray: ksDynamicArray;

begin
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));

  if iDynamicArray <> nil then
  begin
    iDocument2D.ksBezier( 0, 0 );
      iDocument2D.ksPoint( 20,  0, 0 );
      iDocument2D.ksPoint( 10, 20, 0 );
      iDocument2D.ksPoint( 20, 40, 0 );
      iDocument2D.ksPoint( 30, 20, 0 );
      iDocument2D.ksPoint( 20,  0, 0 );
    pp1 := iDocument2D.ksEndObj;

    iDocument2D.ksBezier( 0, 0 );
      iDocument2D.ksPoint(  0, 20, 0 );
      iDocument2D.ksPoint( 20, 10, 0 );
      iDocument2D.ksPoint( 40, 20, 0 );
      iDocument2D.ksPoint( 20, 30, 0 );
      iDocument2D.ksPoint(  0, 20, 0 );
    pp2 := iDocument2D.ksEndObj;

    iMathematic2D.ksIntersectCurvCurv( pp1, pp2, iDynamicArray );
    DrawPointByArray( iDynamicArray );
    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Пересечь отрезок и дугу
//---
procedure IntercectLineSegAndArc;
var
  iDynamicArray: ksDynamicArray;
  a1, a2: double;

begin
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));

  if iDynamicArray <> nil then
  begin
    iDocument2D.ksLineSeg( 0, 40, 100, 40, 1 );
    iDocument2D.ksArcByPoint( 50, 40, 20, 30, 40, 70, 40, 1, 1 );
    a1 := iMathematic2D.ksAngle( 50, 40, 30, 40 );
    a2 := iMathematic2D.ksAngle( 50, 40, 70, 40 );

    iMathematic2D.ksIntersectLinSArc( 0, 40, 100, 40, 50, 40, 20, a1, a2, 1, iDynamicArray );
    DrawPointByArray( iDynamicArray );
    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Касательная из точки
//---
procedure TanFromPoint;
var
  iDynamicArray: ksDynamicArray;
  iMathPointParam: ksMathPointParam;
  i: Integer;

begin
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));
  iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));

  if (iDynamicArray <> nil) and (iMathPointParam <> nil) then
  begin
    iDocument2D.ksPoint( 10, 50, 3);
    iDocument2D.ksCircle( 50, 10, 40, 1 );
    iMathematic2D.ksTanLinePointCircle( 10, 50, 50, 10, 40, iDynamicArray );
    DrawPointByArray( iDynamicArray );

    for i := 0 to iDynamicArray.ksGetArrayCount - 1 do
    begin
      iDynamicArray.ksGetArrayItem( i, iMathPointParam );
      iDocument2D.ksLine( 10, 50, iMathematic2D.ksAngle(10, 50, iMathPointParam.x, iMathPointParam.y) );
    end;

    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Касательная под углом
//---
procedure TanToAngle;
var
  iDynamicArray: ksDynamicArray;
  iMathPointParam: ksMathPointParam;
  i: Integer;

begin
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));
  iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));

  if (iDynamicArray <> nil) and (iMathPointParam <> nil) then
  begin
    iDocument2D.ksCircle( 50, 10, 40, 1 );
    iMathematic2D.ksTanLineAngCircle( 50, 10, 40, -45, iDynamicArray );
    DrawPointByArray( iDynamicArray );

    for i := 0 to iDynamicArray.ksGetArrayCount - 1 do
    begin
      iDynamicArray.ksGetArrayItem( i, iMathPointParam );
      iDocument2D.ksLine( iMathPointParam.x, iMathPointParam.y, -45 );
    end;

    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Поворот точки
//---
procedure RotatePoint;
var
  x, y : Double;
  buf : string;

begin
  iMathematic2D.ksRotate( 60, 50, 50, 50, 180, x, y );
  buf := Format( 'x = %6.2f  y = %6.2f ', [x, y] );
  iKompasObject.ksMessage( buf );
end;

//------------------------------------------------------------------------------
// Симметрия точки
//---
procedure SymmetryPoint;
Var
  x, y : Double;
  buf: string;

begin
  iMathematic2D.ksSymmetry( 55, 60, 60, 50, 50, 50, x, y );
  buf := Format( 'x = %6.2f  y = %6.2f ', [x, y] );
  iKompasObject.ksMessage( buf );
end;

//------------------------------------------------------------------------------
// Сопрягающие окружности к двум прямым
//---
procedure CouplingTwoLines;
var
  iCON: ksCON;
  i: Integer;
  rad: Double;

begin
  iCON := ksCON(iKompasObject.GetParamStruct( ko_CON ));
  if iCON <> nil then
  begin
    rad := 20;
    iMathematic2D.ksCouplingLineLine( 100, 100, 45, 100, 100, -45, rad, iCON );
    iDocument2D.ksLine( 100, 100,  45 );
    iDocument2D.ksLine( 100, 100, -45 );

    for i := 0 to 3 do
    begin
      iDocument2D.ksCircle( iCON.GetXc(i), iCON.GetYc(i), rad, 2 );
      iDocument2D.ksPoint(  iCON.GetX1(i), iCON.GetY1(i), i );
      iDocument2D.ksPoint(  iCON.GetX2(i), iCON.GetY2(i), i );
    end;
  end;
end;

//------------------------------------------------------------------------------
// Перепендикуляр
//---
procedure BuildPerpend;
var
  x, y: Double;
  buf: string;

begin
  iMathematic2D.ksPerpendicular ( 50, 50, 60, 10, 100, 10, x, y );
  buf := Format( 'x = %6.2f  y = %6.2f ', [x, y] );
  iKompasObject.ksMessage( buf );
  iDocument2D.ksLineSeg( 50, 10, 100, 10, 1 );
  iDocument2D.ksLine( 50, 50, iMathematic2D.ksAngle(50, 50, x, y) );
  iDocument2D.ksPoint( x, y, 5 );
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Использованиe математических функций';
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
procedure LIBRARYENTRY(command: WORD); pascal;
begin
  iKompasObject := KompasObject(CreateKompasObject);

  if iKompasObject <> nil then
  begin
    iDocument2D := ksDocument2D(iKompasObject.ActiveDocument2D());
    iMathematic2D := ksMathematic2D(iKompasObject.GetMathematic2D());

    if (iDocument2D <> nil) and (iMathematic2D <> nil) then
    begin
      case command of
        1: IntercectLines;         // пересечь прямые
        2: IntercectCurves;        // пересечь кривые
        3: IntercectLineSegAndArc; // пересечь отрезок и дугу
        4: TanFromPoint;           // касательная из точки
        5: TanToAngle;             // касательная под углом
        6: RotatePoint;            // поворот точки
        7: SymmetryPoint;          // симметрия точки
        8: CouplingTwoLines;       // сопрягающие окружности к двум прямым
        9: BuildPerpend;           // перепендикуляр
      end;

      iKompasObject.ksMessageBoxResult;

      iDocument2D := nil;
      iMathematic2D := nil;
    end;

    iKompasObject := nil;
  end;
end;

end.
