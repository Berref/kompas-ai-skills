unit UserSymbol1;

interface

uses  Windows,  Sysutils, LtDefine, LibTool, LDefin2D, forms, controls,
      classes, ManagerEvents, ksApi7, ksConstTLB;

type
//------------------------------------------------------------------------------
// Класс пользовательского обозначения
// ---
PUserSymbol = ^UserSymbol;
UserSymbol = class(PropertyManagerObject)

protected
  m_x          : double;  // Точка привязки
  m_y          : double;  // Точка привязки
  m_endX       : double;  // Точка конца выноски
  m_endY       : double;  // Точка конца выноски
  m_repeat     : Boolean; // Повторять процесс
  m_firstPoint : Boolean;
  m_edit       : Boolean;
  m_editLeader : Boolean;
  m_leader     : IBaseLeader;
public

  constructor Create;
  property EndX : double read m_endX write m_endX;
  property EndY : double read m_endY write m_endY;
  property X : double write m_x;
  property Y : double write m_y;
  property FirstPoint : Boolean read m_firstPoint write m_firstPoint;
  procedure Draw;
  procedure CreateMacro;
  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  function OnButtonClick( buttonID : LongInt ) : Boolean; override;
  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  function OnButtonUpdate( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; override;
end;

  function  CallBack( com : integer; var x, y : double;
                      info : PRequestInfo;
                      ph : PPhantom; _dynamic : integer ) : integer;  stdcall;

const
  MIN_LENGTH = 1.0E-4;

var
  obj : PUserSymbol;

implementation

uses
 entry;

//------------------------------------------------------------------------------
// Конструктор
// ---
constructor UserSymbol.Create;
begin
  m_x := 0;
  m_y := 0;
  m_endX := 0;
  m_endY := 0;
  m_repeat := true;
  m_firstPoint := true;
  m_edit := false;
  m_editLeader := false;
  m_leader := nil;
end;


//------------------------------------------------------------------------------
// Получить контейнер объектов 2D
// ---
function GetDrawingContainer() : IDrawingContainer;
var
  doc      : IKompasDocument;
  doc2d    : IKompasDocument2D;
  viewsMng : IViewsAndLayersManager;
  views    : IViews;
  view     : IView;
begin
  Result := nil;
  // Получаем активный документ
  doc := newKompasAPI.ActiveDocument;
  if doc <> nil then
  begin
    // Получаем документ 2D
    doc2d := doc As IKompasDocument2D;
    if doc2d <> nil then
    begin
      // Получаем менеджер для работы с видами и слоями
      viewsMng := doc2d.ViewsAndLayersManager;
      if viewsMng <> nil then
      begin
        // Получаем коллекцию видов
        views := viewsMng.Views;
        if views <> nil then
        begin
          // Получаем текущий вид
          view := views.ActiveView;
          if view <> nil then
            Result := view As IDrawingContainer;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создать отрезок по начальной точке, длине и углу
// ---
function CreateLineSeg( lineSegCol : ILineSegments;        // коллекция отрезков
                        annCont    : IAnnotativeContainer; // контейнер аннотационных объектов
                        x, y       : double;               // координаты начала отрезка
                        len        : double;               // длина отрезка
                        ang        : double;               // угол наклона отрезка
                        stl        : integer               // стиль линии отрезка
                      ) : double;             // координата Х конца отрезка

var
  lineSeg : ILineSegment;
begin
  Result := 0.0;
  if lineSegCol <> nil then
  begin
    // Добавляем отрезок в коллекцию
    lineSeg := lineSegCol.Add;
    if lineseg <> nil then
    begin
      with lineSeg do
      begin
        X1 := x;
        Y1 := y;
        Length := len;
        Angle := ang;
        Style := stl;
        Update;
        // Для вычисления точки привязки текста
        Result := X2;
        // Преобразуем отрезок в аннотационный и удаляем исходный
        annCont.CreateByGeomObject( lineSeg );
        Delete;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создать отрезок по двум точкам
// ---
function CreateLineSegmentByPoints( lineSegCol : ILineSegments;   // коллекция отрезков
                                    xBeg, yBeg : double;          // координаты начала отрезка
                                    xEnd, yEnd : double           // координаты конца отрезка
                                  ) : ILineSegment;
var                               
  lineSeg : ILineSegment;
begin
  lineSeg := nil;
  if lineSegCol <> nil then
  begin
    lineSeg := lineSegCol.Add;
    if lineSeg <> nil then
      with lineSeg do
      begin
        X1 := xBeg;
        Y1 := yBeg;
        X2 := xEnd;
        Y2 := yEnd;
        Style := ksCSNormal;
        Update;
      end;
  end;
  Result := lineSeg;
end;


//------------------------------------------------------------------------------
// Создать текст
// ---
procedure CreateText( textsCol : IDrawingTexts;         // коллекция текстов
                      annCont  : IAnnotativeContainer;  // контейнер аннотационных объектов
                      x, y     : double;                // координаты точки привязки текста
                      str      : WideString );          // строка текста
var
  drawText : IDrawingText;
  txt      : IText;
begin
  if textsCol <> nil then
  begin
    // Добавляем текст в коллекцию
    drawText := textsCol.Add;
    if drawText <> nil then
    begin
      // Задаем точку привязки
      drawText.X := x;
      drawText.Y := y;

      txt := drawText As IText;
      if txt <> nil then
        txt.Str := str;

      drawText.Update;

      if annCont <> nil then
      begin
        // Преобразуем текст в аннотационный и удаляем исходный
        annCont.CreateByGeomObject( drawText );
        drawText.Delete;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создать выносную линию
// ---
function CreateLeader( macroObj   : IMacroObject; // макроэлемент
                       begX, begY : double;       // координаты начала полки
                       endX, endY : double        // координаты конечной точки ответвления
                     ) : IBaseLeader;
var
  baseLeader : IBaseLeader;
  leadersCol : ILeaders;
  leader     : ILeader;
  branches   : IBranchs;
begin
  if macroObj <> nil then
  begin
    // Получаем коллекцию присоединенных линий-выносок
    leadersCol := macroObj.AttachedLeaders;
    if leadersCol <> nil then
    begin
      // Добавляем линию-выноску
      leader := leadersCol.Add( ksDrLeader ) As ILeader;
      if leader <> nil then
      begin
        // Добавляем ответвление
        branches := leader As IBranchs;
        if branches <> nil then
        begin
          branches.X0 := begX;
          branches.Y0 := begY;
          branches.AddBranchByPoint( -1, endX, endY );
        end;

        baseLeader := leader As IBaseLeader;
        if baseLeader <> nil then
          baseLeader.Update;
      end;
    end;
  end;
  Result := baseLeader;
end;


//------------------------------------------------------------------------------
// Создать заливку
// ---
procedure CreateColouring( drawCont : IDrawingContainer;    // контейнер графических объектов
                           annCont  : IAnnotativeContainer; // контейнер аннотационных объектов
                           x, y     : double );             // координаты базовой точки для отрисовки заливки
var
  colouringsCol : IColourings;
  colouring     : IColouring;
  boundObj      : IBoundariesObject;
  lineSegsCol   : ILineSegments;
  lineSeg1,
  lineSeg2,
  lineSeg3      : ILineSegment;
  annLineSeg1,
  annLineSeg2,
  annLineSeg3   : IAnnotativeObject;
begin
  if drawCont <> nil then
  begin
    // Получаем коллекцию заливок
    colouringsCol := drawCont.Colourings;
    if colouringsCol <> nil then
    begin
      // Добавляем новую заливку
      colouring := colouringsCol.Add;
      if colouring <> nil then
      begin
        // Добавляем границу
        boundObj := colouring As IBoundariesObject;
        if boundObj <> nil then
        begin
          // Создаем отрезки границы
          lineSegsCol := drawCont.LineSegments;
          if lineSegsCol <> nil then
          begin
            lineSeg1 := CreateLineSegmentByPoints( lineSegsCol, x, y + 5, x, y + 10 );
            lineSeg2 := CreateLineSegmentByPoints( lineSegsCol, x, y + 10, x - 10, y + 7 );
            lineSeg3 := CreateLineSegmentByPoints( lineSegsCol, x - 10, y + 7, x, y + 5 );

            if ( lineSeg1 <> nil ) And ( lineSeg2 <> nil ) And ( lineSeg3 <> nil ) then
            begin
              annLineSeg1 := annCont.CreateByGeomObject( lineSeg1 );
              annLineSeg2 := annCont.CreateByGeomObject( lineSeg2 );
              annLineSeg3 := annCont.CreateByGeomObject( lineseg3 );
              lineSeg1.Delete;
              lineSeg2.Delete;
              lineSeg3.Delete;
              boundObj.AddBoundaries( annLineSeg1, true );
              boundObj.AddBoundaries( annLineSeg2, true );
              boundObj.AddBoundaries( annLineSeg3, true );
              colouring.Color1 := RGB( 0, 0, 0 );
              colouring.Update;
            end;
          end;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Создать макроэлеменет - обозначение
// ---
procedure UserSymbol.CreateMacro();
var
  viewPar    : ViewParamW;
  viewRef    : Reference;
  drawCont,
  macroCont  : IDrawingContainer;
  macroCol   : IMacroObjects;
  macroObj   : IMacroObject;
  annCont    : IAnnotativeContainer;
  lineSegCol : ILineSegments;
  lineSeg1   : ILineSegment;
  textsCol   : IDrawingTexts;
  x, y, len1, len2, len3, textX, textDx, textDy : double;
begin
  // Пересчет координат для масштабированных видов
  viewRef := GetReferenceDocumentPart( 3{текущий вид} );
  GetObjParam( viewRef, @viewPar, SizeOf(viewPar), ALLPARAM_W );
  ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
  x := m_x;  y := m_y;
  len1 := 52;  len2 := 2;  len3 := 8;
  ksPointFromMtr( m_x, m_y, x, y );
  ksLengthIntoMtr( len1 );
  ksLengthIntoMtr( len2 );
  ksLengthIntoMtr( len3 );
  DeleteMtr;

  // Получаем контейнер графических объектов
  drawCont := GetDrawingContainer;
  if drawCont <> nil then
  begin
    // Получаем коллекцию макрообъектов
    macroCol := drawCont.MacroObjects;
    if macroCol <> nil then
    begin
      macroObj := macroCol.Add( false{MultyLayer} );
      if macroObj <> nil then
      begin
        ksSetMacroParamW( macroObj.Reference, nil, 0, nil, nil, 1, MP_HOTPOINTS );
        // Получаем контейнер графических объектов макроэлемента
        macroCont := macroObj As IDrawingContainer;
        // Получаем контейнер аннотационных объектов макроэлемента
        annCont := macroObj As IAnnotativeContainer;

        if ( macroCont <> nil ) And ( macroObj <> nil ) then
        begin
          // Строим отрезки
          lineSegCol := macroCont.LineSegments;
          if lineSegCol <> nil then
          begin
            CreateLineSeg( lineSegCol, annCont, x, y, 90, 0, ksCSThin );
            CreateLineSeg( lineSegCol, annCont, x, y, 10, 90, ksCSThin );
            CreateLineSeg( lineSegCol, annCont, x + 2, y - 1, 88, 0, ksCSDashed );
            CreateLineSeg( lineSegCol, annCont, x + 40, y - 10, 5, 0, ksCSNormal );
            CreateLineSeg( lineSegCol, annCont, x + 50, y + 10, 5, 180, ksCSNormal );
            CreateLineSeg( lineSegCol, annCont, x + 90, y, 5, 45, ksCSThin );
            // Вычисляем точку привязки текста
            textX := CreateLineSeg( lineSegCol, annCont, x + 90, y, 5, 315, ksCSThin ) + 2;

            lineSeg1 := CreateLineSegmentByPoints(lineSegCol, x + 40, y - 10, x + 50, y + 10);
            if lineSeg1 <> nil then
            begin
              annCont.CreateByGeomObject( lineSeg1 );
              lineSeg1.Delete;
            end;

            // Пересчет координат для масштабированных видов
            ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
            textDx := textX; textDy := 0;
            ksPointIntoMtr( textX, m_x + 2, textDx, textDy );
            DeleteMtr;

            // Создаем тексты
            textsCol := macroCont.DrawingTexts;
            if textsCol <> nil then
            begin
              CreateText( textsCol, annCont, m_x + len1, m_y + len2, 'Текст1' );
              CreateText( textsCol, annCont, m_x + len1, m_y - len3, 'Текст2' );
              CreateText( textsCol, annCont, textDx, m_y + len2, 'Текст3' );
              CreateText( textsCol, annCont, textDx, m_y - len3, 'Текст4' );
            end;
          end;
          // Создаем заливку
          CreateColouring( macroCont, annCont, x, y );
          // Добавляем к макроэлементу линию-выноску
          m_leader := CreateLeader( macroObj, m_x, m_y, m_endX, m_endY );
          macroObj.Update;
        end;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Функция обратной связи для редактирования элемента
// ---
function CallBack( com      : integer;                // Номер команды
                   var x, y : Double;                 // Координаты курсора
                   info     : PRequestInfo;           // Параметры запроса
                   ph       : PPhantom;               // Фантом
                   _dynamic : Integer                 // Признак динамического процесса
                 ) : Integer; stdcall;
var
  viewPar     : ViewParamW;
  viewRef, gr : Reference;
  beginX, beginY, endX, endY, baseX, baseY : double;
begin
  // Указываем точку конца ответвления
  if ( obj.FirstPoint ) And ( _dynamic = 0 ) then
  begin
    obj.EndX := x;
    obj.EndY := y;
    obj.FirstPoint := false;
  end
  // Указываем базовую точку
  else
  begin
    if not obj.FirstPoint then
    begin
      if _dynamic = 1 then
      begin
        // Запоминаем координаты курсора
        obj.X := x;
        obj.Y := y;

        // Пересчет координат для масштабированных видов
        viewRef := GetReferenceDocumentPart( 3{текущий вид} );
        GetObjParam( viewRef, @viewPar, SizeOf(viewPar), ALLPARAM_W );
        ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
        beginX := x; beginY := y; endX := obj.EndX; endY := obj.EndY;
        ksPointFromMtr( x, y, beginX, beginY );
        ksPointFromMtr( obj.EndX, obj.EndY, endX, endY );
        DeleteMtr;

        if ( ph <> nil )And ( DistancePntPnt(beginX, beginY, endX, endY) > MIN_LENGTH ) then
        begin
          // Перерисовываем фантом
          if ph^.type6.gr <> 0 then
            DeleteObj( ph^.type6.gr );
          gr := NewGroup( 1 );
          Macro( 0 );
            // Отрисовываем стрелку
            AnnLineSeg( beginX, beginY, endX, endY, 0{без значка}, 1{стрелка}, 1 );
            // Отрисовываем габаритный прямоугольник
            baseX := beginX - 10; baseY := beginY - 10;
            AnnLineSeg( beginX, beginY, beginX, beginY + 20, 0{без значка}, 0{без значка}, 1 );
            AnnLineSeg( beginX, beginY + 20, beginX + 125, beginY + 20, 0{без значка}, 0{без значка}, 1 );
            AnnLineSeg( beginX + 125, beginY + 20, beginX + 125, beginY, 0{без значка}, 0{без значка}, 1 );
            AnnLineSeg( beginX + 125, beginY, beginX, beginY, 0{без значка}, 0{без значка}, 1 );
          EndObj;
          EndGroup;
          ph^.type6.gr := gr;
        end;
      end
      // Указали вторую точку
      else
      begin
        if (ph <> nil) And (ph^.type6.gr <> 0) then
        begin
          DeleteObj( ph.type6.gr );
          ph^.type6.gr := 0;
        end;
        obj.CreateMacro;
        // Здесь создать объект в документе
        obj.FirstPoint := true;
      end;
    end;
  end;
  Result := 1;
end;


//------------------------------------------------------------------------------
// Функция обратной связи для редактирования элемента
// ---
procedure UserSymbol.Draw();
var
  info         : RequestInfoW;
  x, y, x1, y1 : double;
  phant        : Phantom;
  macroRef     : Reference;
  macroObj     : IMacroObject;
  leadersCol   : ILeaders;
  leader       : ILeader;
  baseLeader   : IBaseLeader;
begin
  if InitProcessParam then
  begin
    FillChar(info, sizeof(info), 0 );
    info._dynamic := 1;
    x := 0; y := 0; x1 := 0; y1 := 0;
    m_repeat := true;
    FillChar( phant, sizeof(phant), 0 );
    phant.phType := 6;

    info.callBack := Addr( CallBack );
    obj := Addr( self );

    while m_repeat do
    begin
      m_repeat := false;
      macroRef := EditMacroMode;
      m_edit := macroRef <> 0;
      
      if m_edit then
        info.callBack := nil;
        
      // Указываем базовую точку или точку конца ответвления
      ksCursorExW( @info, x, y, @phant, PIUnknown(procParam) );
      // Если редактируем
      if m_editLeader then
      begin
        macroObj := IUnknown(ksTransferReference( macroRef, ksGetCurrentDocument(0) )) As IMacroObject;
        if macroObj <> nil then
        begin
          // Получаем коллекцию присоединенных линий-выносок
          leadersCol := macroObj.AttachedLeaders;
          if leadersCol <> nil then
          begin
            leader := leadersCol.Leader[0] As ILeader;
            if leader <> nil then
            begin
              baseLeader := leader As IBaseLeader;
              // Запускаем процесс редактирования выносной линии
              if baseLeader <> nil then
                ksEditViewObject( baseLeader.Reference );
            end;
          end;
        end;
        m_editLeader := false;
      end;
      info.callBack := nil;
    end;
  end;
end;


//------------------------------------------------------------------------------
//  prButtonClick        - Нажатие кнопки.
//---
function UserSymbol.OnButtonClick( buttonID : LongInt ) : Boolean;
begin
  if buttonID = pbEnter then
  begin
    m_repeat := true;
    m_firstPoint := true;
  end

  else if buttonID = 500 then
  begin
    m_repeat := true;
    m_editLeader := true;
    newKompasAPI.StopCurrentProcess( true, newKompasAPI.ActiveDocument );
  end;
  Result := true;
end;


//------------------------------------------------------------------------------
//  prButtonUpdate        - Установка состояния кнопки спецпанели.
//---
function UserSymbol.OnButtonUpdate ( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean;
begin
  if buttonID = pbEnter then
    _enable := m_edit;
    
  if buttonID = 500 then
    _enable := m_edit;
       
  Result := true;
end;

end.
